#include <MyFilesystem.hpp>

int main() {
  const path examplePath{"../misc"};
  MyFilesystem Tested(examplePath);
  Tested.PrintAllFiles();
}