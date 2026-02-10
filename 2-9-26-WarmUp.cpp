#include <iostream>
#include <fstream>

using namespace std;

const int DATACAP = 32;
const int MAXCHAR = 128;

int main() {
   char items[DATACAP][MAXCHAR];
   double prices[DATACAP];
   int amounts[DATACAP];

   int count = 0;

    ifstream inFS;

    // Try to open file
   cout << "Opening file groceryList.txt." << endl;

   inFS.open("groceryList.txt");
   if (!inFS.is_open()) {
      cout << "Could not open file groceryList.txt." << endl;
      return 1; // 1 indicates error
   }

// get all data from txt file
//    for (int i = 0; i < 5; i++) {
//     inFS >> items[i], prices[i], amounts[i];
//    }
while (!inFS.eof()) {
    count++;
    inFS >> items[count], prices[count], amounts[count];
}

   
// echo data from txt file
   for (int i = 0; i < 5; i++) {
   cout << "item: " << items[i] << ", ";
   cout << "price: " << prices[i] << ", ";
   cout << "amount: " << amounts[i];
   cout << endl;
   }
    
   inFS.close();


}
