#include <iostream>
using namespace std;

bool setContains(const int set[], const int size, int searchNum);
bool setAddItem(int set[], int& size, int maxSize, int newNum);
bool setDeleteItem(int set[], int& size, int deleteNum);
bool setsEqual(const int set1[], const int size1, 
               const int set2[], const int size2);


int main() {

    return 0;
}

bool setContains(const int set[], const int size, int searchNum){
    for (int i = 0; i < size; i++){
        if (set[i] == searchNum)
            return true;
    }
    return false;
}

bool setAddItem(int set[], int& size, int maxSize, int newNum){
  // do a initial check for if there room for a new number and if the number hasn't already been added
    if (size >= maxSize || setContains(set, size, newNum)) {
        return false;
    }

    // place newNum and increase size by one
    set[size] = newNum;
    size++;
    return true;
}


bool setDeleteItem(int set[], int& size, int deleteNum){
    for (int i = 0; i < size; i++){
        if (set[i] == deleteNum){
            for (int j = i; j < size - 1; j++) {
                set[j] = set[j + 1];
            }

            size--;
            return true;
        }
    }
    return false;
}

bool setsEqual(const int set1[], const int size1,
               const int set2[], const int size2){
    if (size1 != size2) {
        return false;
    }

    for (int i = 0; i < size1; i++){
        if (!setContains(set2, size2, set1[i])) {
            return false;
        }
    }

    return true;
}
