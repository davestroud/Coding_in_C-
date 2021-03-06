// John David Stroud
// CS2255 Computer Science II
// david@davidstroud.me
// https://github.com/davestroud

// Homework #2 - Password Verifier

/* Password must have at least 6 characters
** Password must have at least one uppercase character
** Password must have at lease one lowercase character
** Password must have at least one numeric digit
*/

#include <iostream>
#include <cctype>
#include <cstdio> // For the get the C getchar()function
#include <cstring>

using namespace std;

// function prototypes
bool verifyPassWord(char[]);
int countLetters(char*);
int countDigits(char*);

int main()
{
  char passWord[20];

  // Enter a password
  cout << "The password must have:\n"
        << "\tat least 6 characters,\n"
        << "\tat least one uppercase character,\n"
        << "\tat least one lowercase character,\n"
        << "\tat least one numeric digit\n"
        << "Enter a password: " << endl;
  cin.getline(passWord, 20);

  if (verifyPassWord(passWord))
    cout << "The password is valid" << endl;
  else
  {
    cout << "The password is not valid.\n";
    cout << "The password must be 6 or more characters long.\n";
    cout << "The password must have:\n";
    cout << "\tat least one uppercase character" << endl;
  }

  cout << endl << "Press any key to continue ..." <<endl;
  getchar();

  return 0;
}


bool verifyPassWord(char custPass[])
{
  int numLetters, numDigits, length;

  length = strlen(custPass);
  numLetters = countLetters(custPass);
  numDigits = countDigits(custPass);
  if (numLetters > 5 && numDigits > 1)
    return true;
  else
    return false;
}

// counts the number of letters, both capital and lowercase in the string
int countLetters(char *strPtr)
{
  int occurs = 0;

  while(*strPtr != '\0')
  {
    if (isalpha(*strPtr))
      occurs++;
    strPtr++;
  }
  return occurs;
}

// counts the number of digits in the string
int countDigits(char *strPtr)
{
  int occurs = 0;

  while(*strPtr != '\0')
  {
    if (isdigit(*strPtr))
      occurs++;
    strPtr++;
  }
  return occurs;
}
