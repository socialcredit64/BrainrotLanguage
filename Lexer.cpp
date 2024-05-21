#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <queue>
#include <optional>

// Enum for token types
enum class TokenType {
    IDENTIFIER,
    NUMBER,
    STRING,
    OPERATOR,
    PUNCTUATION,
    END_OF_FILE,
    UNKNOWN
};

// Enum for custom keywords
enum class CustomKeyword {
    NUM,
    PRINT
};

// Token struct
struct Token {
    TokenType type;
    std::string lexeme;
    std::optional<CustomKeyword> customKeyword; // Optional field for custom keywords
};

// Lexer class
class Lexer {
public:
    Lexer(const std::string& source)
        : source(source), position(0) {}

    // Tokenize the entire source code
    std::vector<Token> tokenize() {
        std::vector<Token> tokens;
        while (position < source.size()) {
            Token token = nextToken();
            tokens.push_back(token);
            if (token.type == TokenType::END_OF_FILE) {
                break;
            }
        }
        return tokens;
    }

private:
    std::string source;
    size_t position;

    // Get the next token from the source code
    Token nextToken() {
        while (position < source.size()) {
            char current = source[position];
            if (std::isspace(current)) {
                skipWhitespace();
                continue;
            }
            if (std::isalpha(current)) {
                return tokenizeIdentifierOrKeyword();
            }
            if (std::isdigit(current)) {
                return tokenizeNumber();
            }
            if (current == '+' || current == '-' || current == '*' || current == '/') {
                return tokenizeOperator();
            }
            if (current == '(' || current == ')' || current == '{' || current == '}') {
                return tokenizePunctuation();
            }
            return tokenizeUnknown();
        }
        return { TokenType::END_OF_FILE, "", std::nullopt };
    }

    // Skip over whitespace characters
    void skipWhitespace() {
        while (position < source.size() && std::isspace(source[position])) {
            position++;
        }
    }

    // Tokenize an identifier or custom keyword
    Token tokenizeIdentifierOrKeyword() {
        size_t start = position;
        while (position < source.size() && std::isalnum(source[position])) {
            position++;
        }
        std::string lexeme = source.substr(start, position - start);
        if (lexeme == "num") {
            return { TokenType::IDENTIFIER, lexeme, CustomKeyword::NUM };
        }
        if (lexeme == "print") {
            return { TokenType::IDENTIFIER, lexeme, CustomKeyword::PRINT };
        }
        return { TokenType::IDENTIFIER, lexeme, std::nullopt }; // Default to IDENTIFIER
    }

    // Tokenize a number
    Token tokenizeNumber() {
        size_t start = position;
        while (position < source.size() && std::isdigit(source[position])) {
            position++;
        }
        std::string lexeme = source.substr(start, position - start);
        return { TokenType::NUMBER, lexeme, std::nullopt }; // Default to NUMBER
    }

    // Tokenize an operator
    Token tokenizeOperator() {
        char current = source[position++];
        return { TokenType::OPERATOR, std::string(1, current), std::nullopt }; // Default to OPERATOR
    }

    // Tokenize punctuation
    Token tokenizePunctuation() {
        char current = source[position++];
        return { TokenType::PUNCTUATION, std::string(1, current), std::nullopt }; // Default to PUNCTUATION
    }

    // Tokenize an unknown character
    Token tokenizeUnknown() {
        char current = source[position++];
        return { TokenType::UNKNOWN, std::string(1, current), std::nullopt }; // Default to UNKNOWN
    }
};