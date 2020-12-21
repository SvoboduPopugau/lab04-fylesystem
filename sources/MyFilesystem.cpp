// Copyright 2020 Your Name <your_email>

#include <MyFilesystem.hpp>
#include <iostream>
void MyFilesystem::PrintAllFiles() {
  if (!boost::filesystem::exists(MyPath)){
    std::cout << "doesn't exist" << std::endl;
  } else{
    if(boost::filesystem::is_regular_file(MyPath)){
      std::cout<< MyPath.filename() << std::endl;
    }else if(boost::filesystem::is_directory(MyPath)){
      for(entry &x : iterator(MyPath)){
        if (boost::filesystem::is_directory(x.path())){
          PrintAllFiles(x.path(),2);       //TODO:Реализовать перегрузку
        }
        if (boost::filesystem::is_regular_file(x.path())){
          if(TruFilename(x.path()))
          std::cout << MyPath.filename().string() << " " << x.path().filename().string() << std::endl;
        }
        if (boost::filesystem::is_symlink(x.path())){
          std::cout << "\t" << "Symlink: " << x.path() << std::endl;
        }
      }
    } else if(boost::filesystem::is_symlink(MyPath)){
      std::cout << "Symlink: " << MyPath << std::endl;
    }
  }
}
void MyFilesystem::PrintAllFiles(const path p, unsigned tabs) {
  if (!boost::filesystem::exists(p)){
    std::cout << "doesn't exist" << std::endl;
  } else{
    if(boost::filesystem::is_regular_file(p)){
      std::cout<< p.filename() << std::endl;
    }else if(boost::filesystem::is_directory(p)){
      for(entry &x : iterator(p)){
        if (boost::filesystem::is_directory(x.path())){
          PrintAllFiles(x.path(), tabs+1);                                  //
        }
        if (boost::filesystem::is_regular_file(x.path())){                       //Если файл
          if(TruFilename(x.path()))
          std::cout << p.filename().string() << " " << x.path().filename().string() << std::endl;
        }
        if (boost::filesystem::is_symlink(x.path())){
          std::cout << "Symlink: " << x.path() << std::endl;
        }
      }
    } else if(boost::filesystem::is_symlink(p)){
      std::cout << "Symlink: " << p << std::endl;
    }
  }
}
bool MyFilesystem::TruFilename(const path p) {
  std::string name(p.stem().string());
  if((name.find("balance_") != std::string::npos)&&!(name.find(".old") != std::string::npos))
    return true;
  else
    return false;
}
