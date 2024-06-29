#include "Directory.h"
#include <sys/stat.h>

Directory::Directory(const std::string &dirName) : name(dirName) {}

std::string Directory::getName() const { return name; }

bool Directory::create() {
  if (mkdir(name.c_str(), 0777) == 0) {
    return true;
  } else {
    perror("Error creating directory");
    return false;
  }
}

bool Directory::remove() {
  if (rmdir(name.c_str()) == 0) {
    return true;
  } else {
    perror("Error deleting directory");
    return false;
  }
}

bool Directory::change(const std::string &dirName) {
  if (chdir(dirName.c_str()) == 0) {
    return true;
  } else {
    perror("Error changing directory");
    return false;
  }
}

std::vector<std::string> Directory::list() const {
  std::vector<std::string> contents;
  DIR *dir;
  struct dirent *ent;
  if ((dir = opendir(name.c_str())) != NULL) {
    while ((ent = readdir(dir)) != NULL) {
      contents.push_back(ent->d_name);
    }
    closedir(dir);
  } else {
    perror("Error opening directory");
  }
  return contents;
}
