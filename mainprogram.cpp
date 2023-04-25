/*
mainprogram.cpp
implements mainprogram functions
*/

#include <iostream>
#include <fstream>
#include <array>
#include <unistd.h>

#include "FileProcessor.h" //processes input / file into array
#include "Classic.h" //processes array into classic format
#include  "Donut.h" //processes array into donut format
#include "Mirror.h" //processes array into donut format

using namespace std;

/*
  mainprogram
  main
  Plays Conway's Game of Life
*/
int main() {
  FileProcessor p = FileProcessor();
  char** arr = nullptr;
  int choice;
  int w;
  int h;
  double prob;
  string choiceS;

  cout << "Would you like to provide a map file (1) or a random assignment (2)" << endl;
  cin >> choice;

  if(choice == 1){
    cout << "Whats the name of the map file?" << endl;
    cin >> choiceS;
    arr = p.processFile(choiceS);
  }
  else{
    cout << "Whats the height of the simulation?" << endl;
    cin >> h;

    cout << "Whats the width of the simulation?" << endl;
    cin >> w;

    cout << "Whats the probability in the simulation? (0.0 - 1.0)" << endl;
    cin >> prob;

    arr = p.processFile(w, h, prob);

  }

  cout << "Would you like to run it in classic (1), doughnut (2), or mirror (3) mode?" << endl;
  cin >> choice;
  cout << endl;

  if(choice == 1){
    Classic c = Classic();
    c.printArr(arr, p.getWidth(), p.getHeight(), 100);
  }

  if(choice == 2){
    Donut d = Donut();
    d.printArr(arr, p.getWidth(), p.getHeight(), 100);
  }

  if(choice == 3){
    Mirror m = Mirror();
    m.printArr(arr, p.getWidth(), p.getHeight(), 100);
  }

  cout << "Thank you!" << endl;

  return 0;
}
