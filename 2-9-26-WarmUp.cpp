#include <iostream>
#include <fstream>

using namespace std;

const int DATACAP = 32;
const int MAXCHAR = 128;

int main() {
   char items[DATACAP][MAXCHAR];
   double prices[DATACAP];
   int amounts[DATACAP];



    ifstream inFS;

    // Try to open file
   cout << "Opening file groceryList.txt." << endl;

   inFS.open("groceryList.txt");
   if (!inFS.is_open()) {
      cout << "Could not open file groceryList.txt." << endl;
      return 1; // 1 indicates error
   }

   for (int i = 0; i < 5; i++) {
    


   }
    
    

}
