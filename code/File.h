#ifndef FILE_H
#define FILE_H

#include <iostream>

class File {
private:
  std::string name;

public:
  File(const std::string &fileName);
  std::string getName() const;
  bool create();
  bool removeFile();
  std::string read() const;
  bool write(const std::string &content);
};

#endif // FILE_H
