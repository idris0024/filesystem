#include "File.h"
#include <cstdio>
#include <cstdio>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

File::File(const std::string& fileName) : name(fileName) {}

std::string File::getName() const {
    return name;
}

bool File::create() {
    FILE *file = fopen(name.c_str(), "w");
    if (file) {
        fclose(file);
        return true;
    } else {
        perror("Error creating file");
        return false;
    }
}

bool File::removeFile() {
    if (remove(name.c_str()) == 0) {
        return true;
    } else {
        perror("Error deleting file");
        return false;
    }
}

std::string File::read() const {
    std::string content;
    FILE *file = fopen(name.c_str(), "r");
    if (file) {
        char buffer[1024];
        while (fgets(buffer, sizeof(buffer), file)) {
            content += buffer;
        }
        fclose(file);
    } else {
        perror("Error reading file");
    }
    return content;
}

bool File::write(const std::string& content) {
    FILE *file = fopen(name.c_str(), "w");
    if (file) {
        fputs(content.c_str(), file);
        fclose(file);
        return true;
    } else {
        perror("Error writing file");
        return false;
    }
}
