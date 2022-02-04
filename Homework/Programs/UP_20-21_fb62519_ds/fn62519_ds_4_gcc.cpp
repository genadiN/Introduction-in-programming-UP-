/**
*
* Solution to homework assignment S
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Genadi Nikolov
* @idnumber 62519
* @task 4
* @compiler GCC
*
*/

#include<iostream>
using namespace std;

// Function for length of char array
int myStrlen( char str[]){
    int counter = 0;
// Increase counter while we see '\0'
    while ( str[counter] != '\0'){
        counter++;
    }
    return counter;
}

// F() function
char* F(char str1[] , char str2[] , int N){
    int index = 0;
// Two variables for the lengths of two char array;
    int lengthStr1 = myStrlen ( str1 );
    int lengthStr2 = myStrlen ( str2 );
// Checking if position to copy is valid number;
    if ( N < 0 || N > lengthStr1){
        return "-1";
    }
// Dynamic char array for sorting final char array;
    char* finalString = new char [lengthStr2 + lengthStr1 + 2];
// Loop for scanning the first char array;
    for ( int i = 0 ; i <= lengthStr1 ; i++){
        if( i < N){
// Fulling the final array if index is less than position to copy;
            finalString[index] = str1[i];
            index++;
        }
// Checking if we reach the position to paste
        else if ( i == N ){
// Loop for fulling the output char array with elements
//  from second char array;
            for ( int j = 0 ; j < lengthStr2; j++){
                finalString[index] = str2[j];
                index++;
            }
            index--;
        }
// Checking if we pass the position to paste and full
// final char array with elements from first char array;
        else if ( i > N){
            index = lengthStr2 + i - 1;
            finalString[index] = str1[i - 1];
        }
    }
// Returning the final char array;
    return finalString;
}

// Main function;
int main()
{
// initialize needed variables ;
// N = position to paste;
// str1 , str2 = char array;
    int N = 0;
    char str1[100] ;
    char str2[100] ;
// Input two char array
    cin.getline(str1 , 100 , '\n');
    cin.getline(str2 , 100 , '\n');
// input position for paste;
    cin >> N;
// variables for length of two char array;
    int len1 = myStrlen( str1 ) , len2 = myStrlen( str2 );
// Pointers for two char array;
    char* pStr1 = new char [len1 + len2 +1 ];
    char* pStr2 = new char [len2 + len2 + 1];
    pStr1 = str1;
    pStr2 = str2;
// Calling F() function with pointers and position 'N';
    cout << F(pStr1 , pStr2 , N) << endl;
// Delete dynamic memory;
    delete pStr1;
    delete pStr2;

    return 0;
}
