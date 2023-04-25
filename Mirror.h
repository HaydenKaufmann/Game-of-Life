#include <iostream>
#include <fstream>
using namespace std;

//further documentation / information in Mirror.cpp

class Mirror{
  char** m_curr; //current array
  char** m_last; //last generation's array
  int fheight; //height of outer array
  int fwidth; //width of outer array
  int iHeight; //height of inner array
  int iWidth; //width of inner array
  int generation; //how many generations have been passed

public:
  Mirror(); //default constructor
  ~Mirror(); //default destructor
  char** makeMirrorArr(char** curr, int w, int h); //turns curr into mirrored array
  char** oneGeneration(char** curr); //makes curr into one generation in the future
  int getfHeight(); //returns fheight
  int getfWidth(); //return fwidth
  int getiHeight(); //returns iHeight
  int getiWidth(); //retursn iWidth
  int numNeighbors(char** last, int i, int j); //returns number of neighbors to last[i][j]
  void printArr(char** toPrint, int width, int height, int amount); //prints out amount generations of toPrint
};
