#define CATCH_CONFIG_MAIN
#include "FileSystem.h"
#include "catch.hpp"

TEST_CASE("File System Operations", "[FileSystem]") {
  FileSystem fs;

  SECTION("Create File") {
    std::string result = fs.handleCommand("create_file testfile.txt");
    REQUIRE(result == "File 'testfile.txt' created.");
  }

  SECTION("Delete File") {
    fs.handleCommand("create_file testfile.txt");
    std::string result = fs.handleCommand("delete_file testfile.txt");
    REQUIRE(result == "File 'testfile.txt' deleted.");
  }

  SECTION("Read File") {
    fs.handleCommand("create_file testfile.txt");
    fs.handleCommand("write_file testfile.txt Hello, world!");
    std::string result = fs.handleCommand("read_file testfile.txt");
    REQUIRE(result == "Content of file 'testfile.txt':\nHello, world!");
  }

  SECTION("Write to File") {
    fs.handleCommand("create_file testfile.txt");
    std::string result =
        fs.handleCommand("write_file testfile.txt Hello, world!");
    REQUIRE(result == "Content of file 'testfile.txt' updated.");
  }

  SECTION("Create Directory") {
    std::string result = fs.handleCommand("create_directory testdir");
    REQUIRE(result == "Directory 'testdir' created.");
  }

  SECTION("Delete Directory") {
    fs.handleCommand("create_directory testdir");
    std::string result = fs.handleCommand("delete_directory testdir");
    REQUIRE(result == "Directory 'testdir' deleted.");
  }

  SECTION("Invalid Command") {
    std::string result = fs.handleCommand("invalid_command");
    REQUIRE(result == "Invalid command.");
  }
}
