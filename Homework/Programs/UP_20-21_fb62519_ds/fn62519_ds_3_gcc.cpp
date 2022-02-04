/**
*
* Solution to homework assignment S
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Genadi Nikolov
* @idnumber 62519
* @task 3
* @compiler GCC
*
*/


#include<iostream>
using namespace std;

// Function for length of the char array;
int myStrlen(char str[] ){
    int counter = 0;
// Loop for counting the elements;
    while ( str[counter++] != '\0');
    return counter;
}

//Function for checking and returning the maximum word from string;
char* maximumWord( char str[]){
// Initialize needed variables ;
    int len = myStrlen( str ) , index , maxSum = 0 , sum = 0 , lenMaxWord = 0;
// Two char* array ;
// Contain temporary maximum word;
    char* temporaryChar = new char[len];
// Contain the maximum word;
    char* maxWord = new char[len];
// Loop for scanning the char array;
    for ( int i = 0 ; i < len ; i++){
// checking if the temporary sum big then all time sum;
        if ( maxSum < sum){
// Loop for input elements in all time maximum word array;
            for ( int k = 0 ; k < lenMaxWord ; k++){
                maxWord[k] = temporaryChar[k];
            }
// All time maximum sum is equal to sum;
            maxSum = sum;
        }
// Checking for spaces and tabulates;
        if ( str[i] != ' ' && str[i] != '\t'){

            int j = i , index = 0 ;
            sum = 0;
// Input elements while we see space or tabulate;
            while ( str[j] != ' ' && str[j] != '\t' && str[j] != '\0'){
// Input elements in temporary maximum word array;
                temporaryChar[index] = str[j];
                sum += (int)str[j];
                j++;
                index++;
            }
// Checking if the length of the temporary array is big than the old max word length;
            if ( index > lenMaxWord){
                lenMaxWord = index;
            }
        }
// if we see space fulling the temporary array with '\0';
        else {
            temporaryChar[index] = '\0';
            sum = 0;
        }
    }
// Return the maximum word;
    return maxWord;
}

int main()
{
// Initialize char array with size 1000;
    char str[1000];
// Input the char array;
    cin.getline ( str , 1000 , '\n' );
// Initialize pointer with char array size;
    char *pStr = new char [ myStrlen ( str ) ];
// copy information to the pointer;
    pStr = str;
// Out the maximum word;
    cout << maximumWord( pStr) << endl;
// Delete dynamic memory;
    delete pStr;
    return 0;
}
