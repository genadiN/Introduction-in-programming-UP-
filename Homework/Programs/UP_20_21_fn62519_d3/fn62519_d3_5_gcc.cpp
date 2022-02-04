/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Genadi Nikolov
* @idnumber 62519
* @task 5
* @compiler GCC
*
*/


#include<iostream>
#include<fstream>


using namespace std ;

// Constant for maximum elements in char array.
const int MAX_SIZE = 151;

// Function for length of the char array.
int Size(char str[]){
  int counter = 0 ;
  while(str[counter++] != '\0');
  return --counter;
}

//Function fro printing.
void print(char str[]){

// Getting the length of char.
    int N = Size(str);
    for(int i = 0 ; i < N ;i++){
        cout << str[i];
    }
    cout << endl;
}

// Function for sort a char array.
void Sort(char str[]){

// Getting the length of the array.
   int N = Size(str);
// Make a simple sort.
   for(int i = 0 ; i < N ; i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            for(int k = i ; k < N ; k++){
                if(str[i] > str[k]){
                    char Swap = str[i];
                    str[i] = str[k];
                    str[k] = Swap;
                }
            }
        }
   }
}

// Main function.
int main(){
// Initialization of char array with maximum elements 151.
    char line[MAX_SIZE] = "\0" ;

// Open a text file.
    ifstream file("message.txt");

// Check whether it is open.
    if(file.is_open()){

// An array where we put the exit symbols.
        char exit[MAX_SIZE] = "\0";
        int index = 0;

// Functions in the file while it is open.
        while(file >> line){

// Finding the length of each line of the char array.
            int N = Size(line);

// Make a sort of each line.
            Sort(line);

// Check which symbol we have to put into an 'exit' array.
            for(int i = 1 ; i < N ; i++){

// comparing the difference between each two elements.

                if(line[i] - line[i - 1] != 1  && i < N){

// if it is more than one we put an alphabet in the 'exit' array.
                    line[i] = line[i - 1] + 1;
                    exit[index++] = line[i];
                    break;
                }

// Else we put '.'.
                else {
                    exit[index] = '.';
                }
            }
        }
// Exit the answer;
        print(exit);

// Close the working file.
        file.close();
        }

// If file is not opening.
    else{
        cout << "-2" << endl;
    }

return 0;
}
