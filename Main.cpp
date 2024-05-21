#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cctype>



#include "Compiler.cpp"

int main() {
   //std::cout << "Printing Contents";

   // Open file
   std::string line;
   std::ifstream ReadFile("example.txt");

   while (std::getline (ReadFile, line)){
      std::cout << line << "\n";
   }
   
   //token debug string/file toggle
   std::string source = "num a=10; cout<<a;";
   //std::string source;
   //for (int i=0; i<15; i++){
   //   source += line + "\n";
   //}
   Lexer lexer(source);
   std::vector<Token> tokens = lexer.tokenize();

   Compiler compiler(tokens);
   compiler.execute();


   return 0;
}