#include "Lexer.cpp"
#include <string>
#include <unordered_map>

class Compiler {
public:
    Compiler(const std::vector<Token>& tokens)
        : tokens(tokens), position(0) {}

    void execute() {
        while (position < tokens.size()) {
            Token token = tokens[position++];
            if (token.customKeyword) {
                switch (*token.customKeyword) {
                    case CustomKeyword::NUM:
                        executeNumDeclaration();
                        break;
                    case CustomKeyword::PRINT:
                        executePrintStatement();
                        break;
                }
            }
        }
    }

private:
    std::vector<Token> tokens;
    size_t position;
    std::unordered_map<std::string, int> variables;

    void executeNumDeclaration() {
        // Expecting format: num IDENTIFIER = NUMBER ;
        std::string identifier = tokens[position++].lexeme;  
        position++;  
        int value = std::stoi(tokens[position++].lexeme);  
        position++;  
        variables[identifier] = value;  
    }

    void executePrintStatement() {
        // Expecting format: print ( IDENTIFIER ) ;
        position++;  
        std::string identifier = tokens[position++].lexeme;  
        position++;  
        position++;  
        std::cout << variables[identifier] << "\n";  
    }
};

