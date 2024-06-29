#include "FileSystem.h"
#include <iostream>

void printMenu() {
    std::cout << "===== File System Menu =====" << std::endl;
    std::cout << "1. Create File" << std::endl;
    std::cout << "2. Delete File" << std::endl;
    std::cout << "3. Read File" << std::endl;
    std::cout << "4. Write to File" << std::endl;
    std::cout << "5. Create Directory" << std::endl;
    std::cout << "6. Delete Directory" << std::endl;
    std::cout << "9. Exit" << std::endl;
    std::cout << "===========================" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    FileSystem fs;

    while (true) {
        printMenu();

        std::string command;
        getline(std::cin, command);

        switch (stoi(command)) {
            case 1: {
                std::string fileName;
                std::cout << "Enter file name: ";
                getline(std::cin, fileName);
                fs.handleCommand("create_file " + fileName);
                break;
            }
            case 2: {
                std::string fileName;
                std::cout << "Enter file name: ";
                getline(std::cin, fileName);
                fs.handleCommand("delete_file " + fileName);
                break;
            }
            case 3: {
                std::string fileName;
                std::cout << "Enter file name: ";
                getline(std::cin, fileName);
                fs.handleCommand("read_file " + fileName);
                break;
            }
            case 4: {
                std::string fileName, content;
                std::cout << "Enter file name: ";
                getline(std::cin, fileName);
                std::cout << "Enter content to write: ";
                getline(std::cin, content);
                fs.handleCommand("write_file " + fileName + " " + content);
                break;
            }
            case 5: {
                std::string dirName;
                std::cout << "Enter directory name: ";
                getline(std::cin, dirName);
                fs.handleCommand("create_directory " + dirName);
                break;
            }
            case 6: {
                std::string dirName;
                std::cout << "Enter directory name: ";
                getline(std::cin, dirName);
                fs.handleCommand("delete_directory " + dirName);
                break;
            }
            case 9:
                std::cout << "Exiting..." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 9." << std::endl;
                break;
        }

        std::cout << std::endl;
    }

    return 0;
}
