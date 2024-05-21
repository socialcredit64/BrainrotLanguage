#include <iostream>
#include <vector>
#include <cctype>
#include <string>

    enum class TokenType {
    IDENTIFIER,
    KEYWORD,
    NUMBER,
    STRING,
    OPERATOR,
    PUNCTUATION,
    END_OF_FILE,
    UNKNOWN
};


struct Token {
    TokenType type;
    std::string lexeme;
};


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
        return { TokenType::END_OF_FILE, "" };
    }

    // Skip over whitespace characters
    void skipWhitespace() {
        while (position < source.size() && std::isspace(source[position])) {
            position++;
        }
    }

    // Tokenize an identifier or keyword
    Token tokenizeIdentifierOrKeyword() {
        size_t start = position;
        while (position < source.size() && std::isalnum(source[position])) {
            position++;
        }
        std::string lexeme = source.substr(start, position - start);
        if (lexeme == "if" || lexeme == "else") {
            return { TokenType::KEYWORD, lexeme };
        }
        return { TokenType::IDENTIFIER, lexeme };
    }

    // Tokenize a number
    Token tokenizeNumber() {
        size_t start = position;
        while (position < source.size() && std::isdigit(source[position])) {
            position++;
        }
        std::string lexeme = source.substr(start, position - start);
        return { TokenType::NUMBER, lexeme };
    }

    // Tokenize an operator
    Token tokenizeOperator() {
        char current = source[position++];
        return { TokenType::OPERATOR, std::string(1, current) };
    }

    // Tokenize punctuation
    Token tokenizePunctuation() {
        char current = source[position++];
        return { TokenType::PUNCTUATION, std::string(1, current) };
    }

    // Tokenize an unknown character
    Token tokenizeUnknown() {
        char current = source[position++];
        return { TokenType::UNKNOWN, std::string(1, current) };
    }
};