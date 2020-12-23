// Copyright 2020 Your Name <your_email>

#ifndef INCLUDE_MYFILESYSTEM_HPP_
#define INCLUDE_MYFILESYSTEM_HPP_

#include <boost/filesystem.hpp>
#include <boost/filesystem/path.hpp>
#include <utility>
using path = boost::filesystem::path;

using iterator = boost::filesystem::directory_iterator;
using entry = boost::filesystem::directory_entry;
using string = std::string;
struct File {
  string Broker;
  string Id;
  string Date;
};

struct Account{
 public:
  Account(string broker, string id, int files, string year,
          string month, string day);
  Account(File& f);
  bool operator == (File &Another);
  void AddFile(File &Another);
  string GetBroker();
  string GetId();
  int GetFiles();
  string GetData();

 private:
  string Broker;
  string Id;
  int Files;
  string Year;
  string Month;
  string Day;
};
class MyFilesystem{
 public:
  explicit MyFilesystem(boost::filesystem::path  myPath) : MyPath(std::move(myPath)) {}

  void PrintAllFiles();

  int IsAccExist(File &f);

  void PrintTotalInformation();
 private:
  void PrintAllFiles(const path &p);
  static bool IsFileNameTrue(const path& p);
 private:
  path MyPath;
  std::vector<Account> AccsList;
};

#endif // INCLUDE_MYFILESYSTEM_HPP_
