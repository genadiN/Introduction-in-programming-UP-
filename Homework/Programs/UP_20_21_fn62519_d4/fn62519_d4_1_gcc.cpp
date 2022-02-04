
/**
*
* Solution to homework assignment 4
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

// Constant for maximum elements.
const int MAX_SIZE = 200;

// Function for input an array.
void Input(int arr[] , int M ){
    for(int i = 0 ; i < M ; i++){
        cin >> arr[i];
    }
}

// Function for exit the result.
bool Function(int arr[] , int m , int n){

// Variables.
   int counter = 0 , maxe = 0 , indexi = 0;

// Loop for finding the maximum element of the array.
   for(int i = 0 ; i < n ; i++){

// Finding the maximum element and its index.
    if(arr[i] > maxe){
        maxe = arr[i];
        indexi = i;
    }
   }

// Main loop for finding the result.
   for(int i = 1 ; i < n ; i++){

// Increasing the counter if one of the statements are true.
     if(arr[i] - arr[i - 1 ] < 0 || ( arr[i] - maxe < 0 && i >= indexi) || arr[i] - arr[0] < 0){

// Increase our counter if the numbers are not in correct order.
        counter++;
     }
   }

//  Checking if the counter is smaller than the 'm' and exit true or false.
// where 'm' is our variables for shifting.
   if( counter > m ){

// Exit true == 1 when it is correct.
    return false;
   }

// Otherwise exit false == 0.
   return true ;

}

int main(){

// Variables for input.
// N = shifting , M = size of the array .
    int N = 0 , M = 0 , arr[MAX_SIZE] = {0};

// Loop for correct input.
    do{
         cin >> N >> M;
    }while( N < 0 || M < 0);

// Function for input the array.
    Input( arr , M);

// Exit the result of the main function.
    cout << Function(arr ,  N , M);
return 0;
}
