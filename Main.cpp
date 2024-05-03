#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>


int main() {
   std::cout << "Hello World!";
   // Open the file for reading
   std::fstream fio;
 
   std::string line;


   fio.open("sample.txt", ios::trunc | ios::out | ios::in);

   // Execute a loop If file successfully Opened
   while (fio) {
 
      // Read a Line from standard input
      std::getline(cin, line);

      // Press -1 to exit
      if (line == "-1")
         break;

      // Write line in file
      fio << line << std::endl;
   }


   fio.seekg(0, std::ios::beg);

   while (fio) {
      std::getline(fio, line);
      std::cout << line << std::endl;
   }

   fio.close();
 
   return 0;
}