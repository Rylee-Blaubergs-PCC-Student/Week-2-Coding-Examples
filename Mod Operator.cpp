// Example program
#include <iostream>
#include <string>
using namespace std;

int main()
{
  int number = 0;
  cout << "Enter a whole number: ";
  cin >> number;
  // number = 234, when you do 234 / 10 = 23 and the 4 drops off 
  cout << "The last digit in your number is: " << number % 10 << endl;
  // When I divide by 10000, I drop the last 4 digits
  number /= 10000;   // number = number / 10000;
  cout << number << endl;
  cout << "The middle three digits in your number are: " << number % 1000 << endl;
  number /= 1000;   // number = number / 1000;
  cout << number << endl;
  
  return 0;
}
