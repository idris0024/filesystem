#include "FileSystem.h"
#include <iostream>
#include <sstream>

std::string FileSystem::handleCommand(const std::string &command) {
  std::stringstream ss(command);
  std::string cmd;
  ss >> cmd;

  if (cmd == "create_file") {
    std::string fileName;
    ss >> fileName;
    return createFile(fileName);
  } else if (cmd == "delete_file") {
    std::string fileName;
    ss >> fileName;
    return deleteFile(fileName);
  } else if (cmd == "read_file") {
    std::string fileName;
    ss >> fileName;
    return readFile(fileName);
  } else if (cmd == "write_file") {
    std::string fileName;
    ss >> fileName;
    std::string content;
    getline(ss, content);
    content = content.substr(1); // Remove leading space
    return writeFile(fileName, content);
  } else if (cmd == "create_directory") {
    std::string dirName;
    ss >> dirName;
    return createDirectory(dirName);
  } else if (cmd == "delete_directory") {
    std::string dirName;
    ss >> dirName;
    return deleteDirectory(dirName);
  } else if (cmd == "change_directory") {
    std::string dirName;
    ss >> dirName;
    return changeDirectory(dirName);
  } else if (cmd == "list_directory") {
    return listDirectory();
  } else if (cmd == "exit") {
    exit(0); // Normally handle exit command in a different way in real
             // applications
  } else {
    return "Invalid command.";
  }
}

std::string FileSystem::createFile(const std::string &fileName) {
  File file(fileName);
  if (file.create()) {
    return "File '" + fileName + "' created.";
  } else {
    return "Failed to create file '" + fileName + "'.";
  }
}

std::string FileSystem::deleteFile(const std::string &fileName) {
  File file(fileName);
  if (file.removeFile()) {
    return "File '" + fileName + "' deleted.";
  } else {
    return "Failed to delete file '" + fileName + "'.";
  }
}

std::string FileSystem::readFile(const std::string &fileName) {
  File file(fileName);
  std::string content = file.read();
  if (!content.empty()) {
    return "Content of file '" + fileName + "':\n" + content;
  } else {
    return "Failed to read file '" + fileName + "'.";
  }
}

std::string FileSystem::writeFile(const std::string &fileName,
                                  const std::string &content) {
  File file(fileName);
  if (file.write(content)) {
    return "Content of file '" + fileName + "' updated.";
  } else {
    return "Failed to write to file '" + fileName + "'.";
  }
}

std::string FileSystem::createDirectory(const std::string &dirName) {
  Directory dir(dirName);
  if (dir.create()) {
    return "Directory '" + dirName + "' created.";
  } else {
    return "Failed to create directory '" + dirName + "'.";
  }
}

std::string FileSystem::deleteDirectory(const std::string &dirName) {
  Directory dir(dirName);
  if (dir.remove()) {
    return "Directory '" + dirName + "' deleted.";
  } else {
    return "Failed to delete directory '" + dirName + "'.";
  }
}

std::string FileSystem::changeDirectory(const std::string &dirName) {
  if (Directory::change(dirName)) {
    currentDirectory = Directory(dirName);
    return "Changed directory to '" + dirName + "'.";
  } else {
    return "Failed to change directory to '" + dirName + "'.";
  }
}

std::string FileSystem::listDirectory() const {
  std::vector<std::string> contents = currentDirectory.list();
  std::stringstream ss;
  ss << "Contents of directory '" << currentDirectory.getName() << "':\n";
  for (const auto &item : contents) {
    ss << item << "\n";
  }
  return ss.str();
}
