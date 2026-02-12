/******************************************************************************
# Author:           Neelam Asher, Jaden Youngblood, Rylee Blaubergs, Joe Roaden
# Lab:              Discussion #5
# Date:             02-10-25
# Description:      This program prompts the user for input file name
#                   it then finds the percentage of men and women for each major
#                   then it shows the average salary for all majors
# Input:            stem.txt
#                  
#          
# Output:           stemout.txt
# Sources:          None

#******************************************************************************/

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// constants
const int MAX_CHAR = 256;
const int MAX_DATA = 32;


// function prototypes
bool openFile(ifstream &inFile, string fileName);
void ratioCalc(ifstream &inFile, ofstream &outFile, int totalStudents[], int totalWomen[], int totalMen[], char majorNames[MAX_DATA][MAX_CHAR], int count);
void getAverage(ifstream &inFile, ofstream &outFile, int salaries[], int count);


// main
int main()
{
  //Declare input File 
  ifstream inFile;
  string fileName;
  cout << "Welcome to the file input calculator! Choose a file to create calculations!" << endl;
  cout << "Enter name of input file: ";
  cin >> fileName;

  if (!openFile(inFile, fileName))
  {
    cout << "file did not open. Program terminating!!!";
    return 0;
  }
  

  //Declare Variables
  int courseCodes[MAX_DATA];
  char majorNames[MAX_DATA][MAX_CHAR];
  char majorCategories[MAX_DATA][MAX_CHAR];
  int totalStudents[MAX_DATA];
  int totalMen[MAX_DATA];
  int totalWomen[MAX_DATA];
  int salaries[MAX_DATA];

  //Logic to ignore header - declare c string to hold header data
  char tempVar[MAX_CHAR];

  // Clear the header with a getline
  inFile.getline(tempVar, MAX_CHAR);

  int count = 0;
  while (inFile >> courseCodes[count] >> majorNames[count] >> majorCategories[count] >> totalStudents[count] >> totalMen[count] >> totalWomen[count] >> salaries[count])
  {
    count++;
  }
  
  inFile.close();
  
  //declare output file
  ofstream outFile("stemout.txt");
  ratioCalc(inFile, outFile, totalStudents, totalWomen, totalMen, majorNames, count);
  getAverage(inFile, outFile, salaries, count);
  outFile.close();
  cout << "Thank you for using this program. Goodbye!" << endl;
}

// function to open file
// returns true if file opens
// returns false if file does not open for any reason
// parameters: file stream variable by reference and fileName

bool openFile(ifstream &inFile, string fileName)
{
  inFile.open(fileName);
  if (!inFile)  
  {
    return false;
  }
  return true;
}


void ratioCalc(ifstream &inFile, ofstream &outFile, int totalStudents[], int totalWomen[], int totalMen[], char majorNames[MAX_DATA][MAX_CHAR], int count) {
  double ratioOfWomen;
  double ratioOfMen;
  outFile << "Here are the percentage breakdowns for Men and Women for each Major" << endl;
  outFile << fixed << setprecision(2) << endl; 
  
  for (int i = 0; i < count; i++) {
    ratioOfWomen = (static_cast<double>(totalWomen[i])/totalStudents[i]) * 100;
    outFile << "For " << majorNames[i] << " the percentage of women is " << ratioOfWomen << "%" << endl;
    
    ratioOfMen = (static_cast<double>(totalMen[i])/totalStudents[i]) * 100;
    outFile << "For " << majorNames[i] << " the percentage of men is " << ratioOfMen << "%" << endl;

    outFile << endl;
  }
   
}

void getAverage(ifstream &inFile, ofstream &outFile, int salaries[], int count) {
  double sumTotal = 0;
  double average;

  outFile << "Here is the average salary for all majors $";
  outFile << fixed << setprecision(2); 

  for (int i = 0; i < count; i++) {
    sumTotal = salaries[i] + sumTotal; 
  }

  average = sumTotal/count;
  
  outFile << average << endl;
}
