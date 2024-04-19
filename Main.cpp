#include <iostream>
#include <fstream>
  using std::ifstream;
#include <cstdlib>


int main() {
   std::cout << "Hello World!";
   // Open the file for reading
   std::ifstream file("example.txt");

   if (!file.is_open()) {
      std::cerr << "Failed to open the file." << std::endl;
      return 1;
   }

   std::string line;
   while (std::getline(file, line)) {
      std::cout << line << std::endl; // Print each line
   }

   file.close(); // Close the file

   return 0;
}