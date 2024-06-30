#include "FileSystem.h"
#include <iostream>

void printMenu() {
    std::cout << "\n=============================" << std::endl;
    std::cout << "   File System   " << std::endl;
    std::cout << "=============================" << std::endl;
    std::cout << "1. Create a New File" << std::endl;
    std::cout << "2. Delete an Existing File" << std::endl;
    std::cout << "3. Display File Content" << std::endl;
    std::cout << "4. Write Content to File" << std::endl;
    std::cout << "5. Create a New Directory" << std::endl;
    std::cout << "6. Remove an Existing Directory" << std::endl;
    std::cout << "7. Exit the System" << std::endl;
    std::cout << "=============================" << std::endl;
    std::cout << "Please enter your choice (1-7): ";
}

int main() {
    FileSystem fs;

    while (true) {
        printMenu();

        std::string command;
        getline(std::cin, command);

        if (command.empty()) {
            std::cout << "Invalid input. Please enter a number between 1 and 7." << std::endl;
            continue;
        }

        try {
            int choice = stoi(command);

            switch (choice) {
                case 1: {
                    std::string fileName;
                    std::cout << "Enter the name of the new file: ";
                    getline(std::cin, fileName);
                    fs.handleCommand("create_file " + fileName);
                    break;
                }
                case 2: {
                    std::string fileName;
                    std::cout << "Enter the name of the file to delete: ";
                    getline(std::cin, fileName);
                    fs.handleCommand("delete_file " + fileName);
                    break;
                }
                case 3: {
                    std::string fileName;
                    std::cout << "Enter the name of the file to read: ";
                    getline(std::cin, fileName);
                    fs.handleCommand("read_file " + fileName);
                    break;
                }
                case 4: {
                    std::string fileName, content;
                    std::cout << "Enter the name of the file to write to: ";
                    getline(std::cin, fileName);
                    std::cout << "Enter the content to write: ";
                    getline(std::cin, content);
                    fs.handleCommand("write_file " + fileName + " " + content);
                    break;
                }
                case 5: {
                    std::string dirName;
                    std::cout << "Enter the name of the new directory: ";
                    getline(std::cin, dirName);
                    fs.handleCommand("create_directory " + dirName);
                    break;
                }
                case 6: {
                    std::string dirName;
                    std::cout << "Enter the name of the directory to delete: ";
                    getline(std::cin, dirName);
                    fs.handleCommand("delete_directory " + dirName);
                    break;
                }
                case 7:
                    std::cout << "Thank you for using the File System. Goodbye!" << std::endl;
                    return 0;
                default:
                    std::cout << "Invalid choice. Please enter a number between 1 and 7." << std::endl;
                    break;
            }
        } catch (const std::invalid_argument&) {
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}
