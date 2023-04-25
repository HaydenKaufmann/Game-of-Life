/*
FileProcessor header
Defines / Prototypes FileProcessor.cpp
*/

#include <iostream>
#include <fstream>
#include <array>
using namespace std;
//std::array

class FileProcessor{
  int height;
  int width;
  string m_inputFile;
  char* arr;

  public:
    FileProcessor(); //constructor
    ~FileProcessor(); //destructor

    char** processFile(string inputFile);
    char** processFile(int h, int w, double chance);
    int getWidth();
    int getHeight();
};
