#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


void swap(std::string &str, const std::string &from, const std::string &to) {
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
}

int main() {
    // Open the input file
    std::ifstream inputFile("example.txt");
    

    // Read the content of the input file
    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    std::string content = buffer.str();

    // Replace "num" with "int" and "print" with "std::cout"
    swap(content, "num", "int");
    swap(content, "print", "std::cout");

    // Open the output file
    std::ofstream outputFile("result.cpp");
    

    // Write the modified content into the output file
    outputFile << "#include <iostream>\n\n";
    outputFile << "int main() {\n";
    outputFile << content << "\n";
    outputFile << "return 0;\n";
    outputFile << "}\n";

    // Close the files
    inputFile.close();
    outputFile.close();

    // Compile and run the generated C++ program
    system("g++ -o program output.cpp");
    system("./program");

    return 0;
}