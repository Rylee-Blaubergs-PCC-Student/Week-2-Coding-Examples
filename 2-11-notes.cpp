/* warmup: Copy a file!
 * Make a program that reads the contents of a text file (regardless
 * of formatting) and writes a carbon-copy of that file. 
 * eg:
 *
 * file.txt:
 * hello world! I love
 * dogs!
 *
 * COPY_file.txt:
 * hello world! I love
 * dogs!
 */

#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;




  // file formats - 
  // txt is a text file, with no formatting
  // csv files - standard data file, top line is a header info, then following, 
  //             a format of values separated by commas
  // tsv files - standard data file, top line is a header info, then following, 
  //             a format of values separated by tabs 
  //














  // Passing files to functions
  // A file object is known as a "file handler"
//  ifstream myInputFile("file.txt"); 
  // file handles MUST be passed by reference to functions

const int MAXCHAR = 256;

struct SalaryDataFile {
  char names[16][MAXCHAR] = {0};
  int salaries[16] = {0};
  double raises[16] = {0};
  int size = 0;
};

void loadData(ifstream& inFile, SalaryDataFile& sdf){
  
  while(inFile >> sdf.names[sdf.size] >> sdf.salaries[sdf.size] >> sdf.raises[sdf.size]){
    sdf.size++;
  }
  inFile.close();
}

/* 8 File functions worth knowing
 * ifstream.get() - reads 1 character 
 * ofstream.put() - writes 1 character
 * ifstream.clear() - resets the error flag 
 * ifstream.tellg() - finds and returns the current cursor position
 * ifstream.seekg() - set the position of the cursor to some position in the file
 * ofstream.tellp() - finds and returns the current cursor position
 * ofstream.seekp() - set the position of the cursor to some position in the file
 * ifstream.rdbuf() - returns the entire contents of the file
 */


int main() {

  SalaryDataFile sdf;

  ifstream inFile("salaries.txt");
  loadData(inFile, sdf);

  for(int i=0; i<sdf.size; i++){
    cout << sdf.names[i] << sdf.salaries[i] << sdf.raises[i] << endl;
  }






//  ifstream inFile("salaries.txt");
//  ofstream outFile;
//  outFile.open("salaries_COPY.txt", ios::app);
//
//  if(!inFile.is_open() || !outFile.is_open()){
//    cout << "ERROR files did not open" << endl;
//    exit(1);
//  }
//
//
//  char line[1024];
//  while(!inFile.eof()){
//    inFile.getline(line, 1024);
//    outFile << line << endl;
//  }
//
//  // or just this:
//  // outFile << inFile.rdbuf(); // cheeky 1-line solution
//
//  inFile.close();
//  outFile.close();
  























  return 0;
}
