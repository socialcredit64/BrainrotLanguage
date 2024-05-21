#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>

// Enum to define different token types
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

// Structure to represent a token without line and column
struct Token {
    TokenType type;
    std::string lexeme;
};

// Lexer class to tokenize the source code
class Lexer {
public:
    Lexer(const std::string& source);

    // Tokenize the entire source code
    std::vector<Token> tokenize();

private:
    std::string source;
    size_t position;

    // Get the next token from the source code
    Token nextToken();

    // Skip over whitespace characters
    void skipWhitespace();

    // Tokenize an identifier or keyword
    Token tokenizeIdentifierOrKeyword();

    // Tokenize a number
    Token tokenizeNumber();

    // Tokenize an operator
    Token tokenizeOperator();

    // Tokenize punctuation
    Token tokenizePunctuation();

    // Tokenize an unknown character
    Token tokenizeUnknown();
};

#endif // LEXER_H
