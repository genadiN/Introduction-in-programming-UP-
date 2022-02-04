/**
*
* Solution to homework assignment S
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Genadi Nikolov
* @idnumber 62519
* @task 2
* @compiler GCC
*
*/

#include<iostream>
using namespace std;

// Function for swap numbers;
void swapNumbers ( int &a , int &b){
        int c = a;
        a = b;
        b = c;
}

// Sort array function
void sortArray(int size_Array , int arr[]){
// Two loops for sorting;
    for ( int i = 0 ; i < size_Array ; i++){
        for ( int j = i + 1 ; j < size_Array ; j++){
// Checking if the element on 'j' postion is less than element on 'i' position ;
            if( arr[j] < arr[i] ){
// If it is true swap numbers;
                swapNumbers( arr[i] , arr[j]);
            }
        }
    }
}
// Function for printing an array
void printArray ( int size_Array , int arr[]){
    for ( int i = 0 ; i < size_Array; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
// Boolean function for check if the number is from Fubonacci set;
bool isFibonacci( int number ){
// Initialize start variables;
    int i = 1 , j = 1 , k = 2;
// First check
    if ( number == 1 || number == 0){
        return true;
    }
// Loop for searching a fibonacci number;
    while ( k <= number ){
         k = i + j;
         i = j ;
         j = k ;
// Check if the number is from fibonacci or not and return ;
         if ( k == number ){
             return true;
         }
    }
    return false;
}
// Function for checking are there same numbers in output array;
bool isSame( int size_Array, int arr[] , int number){
    for ( int i = 0 ; i < size_Array ; i++){
// If there are same numbers return false ;
        if ( arr[i] == number ){
            return false;
        }
    }
    return true;
}
//Function F()
void F(int size_Array , int arr[]){
// Initialize output array with start index;
    int fibonacciArray[size_Array] , index = 0;
// Loop scanning main array ;
    for ( int i = 0 ; i < size_Array ; i++){
// Check if the number is from Fibonacci set;
        if ( isFibonacci( arr[i] ) == true ){
// Check if the number has its same in the output array;
            if ( isSame( index , fibonacciArray , arr[i] ) == true){
// Input number in output array if everything is true;
                    fibonacciArray[index++] = arr[i] ;
            }
        }
    }
// Lastly sort output array and print the elements;
    sortArray(index , fibonacciArray);
    printArray(index , fibonacciArray);
}

// Main function;
int main()
{
// Initialize the first array with size 6;
    int size_Array = 5, arr0[size_Array] = {3 , 11 , 5 , 1 , 7 , 12};
// Initialize the second array with size 6;
    int arr1[size_Array] = { 3, 0, 0, 1, 12, 8 };
// Initialize the third array with size 10;
    int size_Array2 = 10 , arr2[size_Array2] = {8 , 31 , 61 , 120 , 29 , 149 , 13 , 773 , 1016 , 5};
//Calling the F() function for three arrays and print the result;
    F(size_Array , arr0);
    F(size_Array , arr1);
    F(size_Array2 , arr2);

   return 0;
}


