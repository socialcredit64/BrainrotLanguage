#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>


int main() {
   std::cout << "Printing Contents";
   // Open the file for reading
   std::string line;
   std::ifstream ReadFile("example.txt");
   
   while (std::getline (ReadFile, line)){
      std::cout << line << "\n";
   }
   
   return 0;
}