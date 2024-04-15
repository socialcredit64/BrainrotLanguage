#include <iostream>
  using namespace std;
#include <fstream>
  using std::ifstream;
#include <cstdlib>


int main() {
  cout << "Hello World!";
  ifstream indata; // indata is like cin
   int num; // variable for input value
indata.open("example.txt"); // opens the file
   if(!indata) { // file couldn't be opened
      cerr << "Error: file could not be opened" << endl;
      exit(1);
   }
indata >> num;
   while ( !indata.eof() ) { // keep reading until end-of-file
      cout << "The next number is " << num << endl;
      indata >> num; // sets EOF flag if no value found
   }
   indata.close();
   cout << "End of file" << endl;
   return 0;
  return 0;
}