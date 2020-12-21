// Copyright 2020 Your Name <your_email>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#endif // INCLUDE_HEADER_HPP_
#include <boost/filesystem.hpp>
#include <boost/filesystem/path.hpp>

using path = boost::filesystem::path;
using iterator = boost::filesystem::directory_iterator;
using entry = boost::filesystem::directory_entry;

class MyFilesystem{
 public:
  MyFilesystem(const boost::filesystem::path& myPath) : MyPath(myPath) {}

  void PrintAllFiles();

 private:
  void PrintAllFiles(const path p, unsigned tabs);
  bool TruFilename(const path p);
 private:
  path MyPath;
};