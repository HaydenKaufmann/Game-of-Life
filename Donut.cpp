/*
Donut.cpp
implements Donut functions
*/

#include <iostream>
#include <fstream>
#include "Donut.h"
using namespace std;

/*
Donut.cpp
default constructor
*/
Donut::Donut(){
  m_curr = nullptr;
  m_last = nullptr;
  fheight = 0;
  fwidth = 0;
  iHeight = 0;
  iWidth = 0;
}

/*
Classic.cpp
default destructor
*/
Donut::~Donut(){
}

/*
Donut.cpp
oneGeneration
@param item: 2D array to move one generation
@return: 2D array after generation

makes arr go one generation into the future
*/
char** Donut::oneGeneration(char** arr){
  Donut c;
  m_last = arr;

  char** m_curr = new char*[fwidth]; //creates new array to return
  for(int i = 0; i < fwidth; i++){
    m_curr[i] = new char[fheight];
  }

  for(int i = 0; i < fheight; i++){ //fills new array
    for(int j = 0; j < fwidth; j++){
      m_curr[i][j] = '-';
    }
  }

  int numNeighbors = 0; //initilizes num numNeighbors;

  for(int i = 1; i < fheight - 1; i++){
    for(int j = 1; j < fwidth - 1; j++){
      numNeighbors = c.numNeighbors(m_last, i, j); //searches through last to count neighbors

      if(numNeighbors <= 1){ //implements Conway's Game of Life rules
        m_curr[i][j] = '-';
      }
      else if(m_last[i][j] == 'X' && numNeighbors == 2){
        m_curr[i][j] = 'X';
      }
      else if(m_last[i][j] == '-' && numNeighbors == 2){
        m_curr[i][j] = '-';
      }
      else if(m_last[i][j] == 'X' && numNeighbors == 3){
        m_curr[i][j] = 'X';
      }
      else if(m_last[i][j] == '-' && numNeighbors == 3){
        m_curr[i][j] = 'X';
      }
      else if(numNeighbors >= 4){
        m_curr[i][j] = '-';
      }
    }
  }

  m_curr[0][0] = m_curr[iHeight][iWidth]; //corner cases for Mirror
  m_curr[0][fwidth - 1] = m_curr[iHeight][1];
  m_curr[fheight - 1][0] = m_curr[1][iWidth];
  m_curr[fheight - 1][fwidth - 1] = m_curr[1][1];

  for(int x = 1; x <= iWidth; x++){ //side cases for Mirror
    m_curr[0][x] = m_curr[iHeight][x];
    m_curr[fheight - 1][x] = m_curr[1][x];
  }

  for(int x = 1; x <= iHeight; x++){
    m_curr[x][0] = m_curr[x][iWidth];
    m_curr[x][fwidth - 1] = m_curr[x][1];
  }


  return m_curr;
}

/*
Donut.cpp
makeClassicArr
@param item: 2D array to give mirrored boarder
@return: 2D array after given mirrored boarder

creates classic array of input
*/
char** Donut::makeDonutArr(char** curr, int w, int h){
  iHeight = h; //input array's height and width
  iWidth = w;

  fwidth = w + 2; //array to be made (with boarder) height and width
  fheight = h + 2;

  char** ret = new char*[fwidth]; //creates new (larger) array
  for(int i = 0; i < fwidth; i++){
    ret[i] = new char[fheight];
  }

  for(int i = 0; i < fheight; i++){ //fills new array
    for(int j = 0; j < fwidth; j++){
      ret[i][j] = '-';
    }
  }

  for(int i = 0; i < iHeight; i++){ //fills larger array with input array
    for(int j = 0; j < iWidth; j++){
      if(curr[i][j] == 'X'){
        ret[i+1][j+1] = 'X';
      }
    }
  }

  ret[0][0] = ret[iHeight][iWidth]; //corner cases for Mirror
  ret[0][fwidth - 1] = ret[iHeight][1];
  ret[fheight - 1][0] = ret[1][iWidth];
  ret[fheight - 1][fwidth - 1] = ret[1][1];

  for(int x = 1; x <= iWidth; x++){ //side cases for Mirror
    ret[0][x] = ret[iHeight][x];
    ret[fheight - 1][x] = ret[1][x];
  }

  for(int x = 1; x <= iHeight; x++){
    ret[x][0] = ret[x][iWidth];
    ret[x][fwidth - 1] = ret[x][1];
  }

  m_curr = ret;
  return ret;
}

/*
Donut.cpp
getfHeight
@return: fheight

accessor
*/
int Donut::getfHeight(){
  return fheight;
}

/*
Donut.cpp
getfWidth
@return: fwidth

accessor
*/
int Donut::getfWidth(){
  return fwidth;
}

/*
Donut.cpp
getiHeight
@return: iHeight

accessor
*/
int Donut::getiHeight(){
  return iHeight;
}

/*
Donut.cpp
getiWidth
@return: iWidth

accessor
*/
int Donut::getiWidth(){
  return iWidth;
}

/*
Donut.cpp
numNeighbors
@param item: 2D array to count neighbors of, the row of space in array, the column of the space in the array
@return: the number of neighbors the space has

counts neighbors
*/
int Donut::numNeighbors(char** last, int i, int j){
  int num = 0;
  if(last[i - 1][j - 1] == 'X'){ //top left's status
    num++;
  }
  if(last[i - 1][j] == 'X'){ //top status
    num++;
  }
  if(last[i - 1][j + 1] == 'X'){ //top right status
    num++;
  }
  if(last[i][j - 1] == 'X'){ //left status
    num++;
  }
  if(last[i][j + 1] == 'X'){ //right status
    num++;
  }
  if(last[i + 1][j - 1] == 'X'){ //bottom left status
    num++;
  }
  if(last[i + 1][j] == 'X'){ //bottom status
    num++;
  }
  if(last[i + 1][j + 1] == 'X'){ //bottom right status
    num++;
  }
  return num;
}

/*
Donut.cpp
printArr
@param item: 2D array to print, the array's width, the array's height, the amount of generations to be printed

prints amount of generations of toPrint
*/
void Donut::printArr(char** toPrint, int width, int height, int amount){
  Donut c;
  char** arrC = c.makeDonutArr(toPrint, width, height); //turns input array into Mirror array

  char** last = new char*[c.getfWidth()]; //creates array of same size to act as comparison to last generation
  for(int i = 0; i < c.getfWidth(); i++){
    last[i] = new char[c.getfHeight()];
  }

  cout << "0" << endl; //0 case

  for(int i = 1; i < c.getfHeight() - 1; i++){
    for(int j = 1; j < c.getfWidth() - 1; j++){
      cout << arrC[i][j];
      last[i][j] = arrC[i][j];
    }
    cout << "" << endl;
  }
  cout << "" << endl;

  bool checkDup = true; //initilizes variables
  int total = 0;
  int generation = 1;

  while(amount > 0 && checkDup){ //checks while its less than amount and not stabilized
    total = 0;

    for(int i = 0; i < c.getfHeight(); i++){ //makes last == arrC
      for(int j = 0; j < c.getfWidth(); j++){
        last[i][j] = arrC[i][j];
      }
    }

    arrC = c.oneGeneration(arrC); //arrc = next generation of arrC

    cout << generation << endl; //prints what generation it is
    for(int i = 1; i < c.getfHeight() - 1; i++){ //prints out next generation
      for(int j = 1; j < c.getfWidth() - 1; j++){
        cout << arrC[i][j];
      }
      cout << "" << endl;
    }
    cout << "" << endl;

    for(int i = 0; i < c.getfHeight(); i++){ //counts to see if last == arrC
      for(int j = 0; j < c.getfWidth(); j++){
        if(last[i][j] == arrC[i][j]){
          total++;
        }
      }
    }

      if(total == c.getfHeight() * c.getfWidth()){ //if all of last == all of arrC cancel while loop
        checkDup = false;
      }

      amount--;
      generation++;
    }
}
