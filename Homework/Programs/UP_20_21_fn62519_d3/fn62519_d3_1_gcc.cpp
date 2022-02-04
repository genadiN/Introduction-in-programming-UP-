/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Genadi Nikolov
* @idnumber 62519
* @task 1
* @compiler GCC
*
*/


#include<iostream>


using namespace std ;

// Constant for maximum elements in the char array.
const int MAX = 151;

// Function for input the array.
void Input(char str[]){
   cin.getline(str , MAX , '\n');
}

// Function for length of the char array.
int Strlen(char str[]){
  int counter = 0 ;
  while(str[counter++] != '\0');
  return counter;
}

// Function converting char to integer.
int CharToInt(char str){
  return(str - 'a');
}

// Function for check the frequency of elements.
bool AllSame(int frequency[] , int N){
   int same ;
   for(int i = 0 ; i < N ; i++){
      if(frequency[i] > 0){
         same = frequency[i];
         break;
      }
   }

// Check is for false or true.
   for(int j = 1 ; j < N ; j++){
     if(frequency[j] > 0 && frequency[j] != same){
        return false;
     }
   }
   return true;
}

// Function for a correct char array.
bool Function(char str[]){

// Finding the length of the string.
  int length = Strlen(str);

// Initialization of integer array.
  int frequency[MAX] = {0};

//Converting out char in integer.
  for(int i = 0 ; i < length ; i++){
    frequency[ CharToInt ( str [ i ] ) ]++;
  }

// Check is all numbers are with same frequencies;
  if(AllSame(frequency , MAX))return true;

// Loop for decrease the frequency.
  for(char c = 'a' ; c <= 'z' ; c++){

// Converting symbols in integer.
    int i = CharToInt(c);
    if(frequency[i] > 0){

// Decrease the frequency.
        frequency[i]--;

// Again check is it has same frequencies of the symbols.
        if(AllSame(frequency , MAX))return true ;
        frequency[i]++;
    }
  }

// If we reach here it mean the char array is not correct.
  return false;
}

int main()
{

// Initialization of char array.
    char str[MAX] = "\0" ;

// Input the char array.
    Input(str);

// Exit the result.
    cout << Function(str);
    return 0;
}
