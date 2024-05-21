#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cctype>

#include "Lexer.h"


int main() {
   std::cout << "Printing Contents";

   // Open the file for reading
   std::string line;
   std::ifstream ReadFile("example.txt");

   while (std::getline (ReadFile, line)){
      std::cout << line << "\n";
   }
   
   //executing
   std::string source = "if (a + 1) { b = 2; }";
   Lexer lexer(source);
   std::vector<Token> tokens = lexer.tokenize();

   for (const Token& token : tokens) {
      std::cout << "Token: " << token.lexeme << " (Type: " << static_cast<int>(token.type) << ")\n";
   }


   return 0;
}