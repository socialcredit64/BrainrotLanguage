#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>




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
    Lexer(const std::string& source);
    std::vector<Token> tokenize();

private:
    std::string source;
    size_t position;

    Token nextToken();
    void skipWhitespace();
    Token tokenizeIdentifierOrKeyword();
    Token tokenizeNumber();
    Token tokenizeOperator();
    Token tokenizePunctuation()
    Token tokenizeUnknown();
};

#endif // LEXER_H
