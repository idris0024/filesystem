#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "Directory.h"
#include "File.h"
#include <string>

class FileSystem {
public:
  std::string handleCommand(const std::string &command);

private:
  Directory currentDirectory;

  std::string createFile(const std::string &fileName);
  std::string deleteFile(const std::string &fileName);
  std::string readFile(const std::string &fileName);
  std::string writeFile(const std::string &fileName,
                        const std::string &content);
  std::string createDirectory(const std::string &dirName);
  std::string deleteDirectory(const std::string &dirName);
  std::string changeDirectory(const std::string &dirName);
  std::string listDirectory() const;
};

#endif // FILESYSTEM_H
