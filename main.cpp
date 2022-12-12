#include <iostream>
#include <string.h>
#include <fstream> 

#define cppStdTags "#include <iostream> \n\n int main() {\n\n}"
#define hppStdTags "#pragma once \n\n"

static int retNum;

struct { //The structure used for grouping file details in one spot
public:
    std::string fileType;
    std::string filePath;
    std::string fileName;

} fileDetails;


void genFile() {

    if (fileDetails.fileType == ".cpp") {
        std::ofstream userFile(fileDetails.filePath + fileDetails.fileName + ".cpp");
        userFile << cppStdTags;
        userFile.close();
        retNum = 1;
    } else if (fileDetails.fileType == ".hpp") {
        std::ofstream userHeader(fileDetails.filePath + fileDetails.fileName + ".hpp");
        userHeader << hppStdTags;
        userHeader.close();
        retNum = 1;
    } 
} 



int main() {

    std::cout << "Welcome to quickCode File creation Wizard V1.0.0\n";
    std::cout << "Please select from one of the following file types:\n";

    std::cout << ".cpp\n" << std::endl;
    std::cout << ".hpp" << std::endl;

        std::cin >> fileDetails.fileType;

    std::cout << "Next, please select where you would like this file to be placed: ";
    

        std::cin >> fileDetails.filePath;

    std::cout << "Finally, please select the name of this file: ";

        std::cin >> fileDetails.fileName;

    std::cout << "Please wait while we generate your file for you..." << std::endl;

    genFile();

while (true) {
if (retNum == 1) {
    std::cout << "Your file has been successfully created\n";

    std::cout << "Thank you for using quickCode!" << std::endl;
    break;

} else {
    std::cout << "Sorry, there appears to be an issue with your file, please try again..." << std::endl;
    break;
}
}
}