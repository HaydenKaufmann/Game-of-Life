/*
FileProcessor.cpp
implements FileProcessor functions
*/

#include <iostream>
#include <fstream>
#include "FileProcessor.h"
using namespace std;

/*
FileProcessor
default constructor
*/
FileProcessor::FileProcessor(){
  m_inputFile = "";
  height = 0;
  width = 0;
}

/*
FileProcessor
default destructor
*/
FileProcessor::~FileProcessor(){
}

/*
FileProcessor
processFile
opens file and prints the translated information from input file into it
@param item: string inputFile is the file that is copied from
             string outputFile is the file that the translation is copied to
*/
  char** FileProcessor::processFile(string inputFile){
  m_inputFile = inputFile;

  ifstream in_file(m_inputFile);

/*
  int temp;

  if(in_file >> temp){
    height = temp;
  }
  if(in_file >> temp){
    width = temp;
  }
  */
  string line;
  getline(in_file,line);
  height = stoi (line);

  getline(in_file,line);
  width = stoi (line);

  char** ret = new char*[width];
  for(int i = 0; i < width; i++){
    ret[i] = new char[height];
  }

  int l = 0;
  //string line;

  while(getline(in_file,line)){
      for(int i = 0; i < width; i++){
        ret[l][i] = toupper(line[i]);
        //cout << ret[l][i];
      }
      //cout << "" << endl;
      l++;
  }

  in_file.close();

  return ret;
}


char** FileProcessor::processFile(int h, int w, double chance){
  width = w;
  height = h;

  char** ret = new char*[width];
  for(int i = 0; i < width; i++){
    ret[i] = new char[height];
  }

   srand(time(0));

    for(int i = 0; i < width; i++){
      for(int j = 0; j < height; j++){
        if(rand() % 100 + 1 <= chance * 100.0){
          ret[i][j] = 'X';
        }
        else{
          ret[i][j] = '-';
        }
        //cout << ret[i][j];
      }
      //cout << "" << endl;
    }

  width = w;
  height = h;

  return ret;
}

int FileProcessor::getWidth(){
  return width;
}

int FileProcessor::getHeight(){
  return height;
}
