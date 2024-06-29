#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <dirent.h>
#include <iostream>
#include <unistd.h>
#include <vector>

class Directory {
private:
  std::string name;

public:
  Directory(const std::string &dirName);
Directory(){};
  std::string getName() const;
  bool create();
  bool remove();
  static bool change(const std::string &dirName);
  std::vector<std::string> list() const;
};

#endif // DIRECTORY_H