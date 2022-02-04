
/**
*
* Solution to homework assignment 2
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

using namespace std ;

// My constant for maximum elements in the array.
const int MAX_SIZE = 2000;

int main(){
 int N = 0 , counter = 0 , counter1 = 0 , counter2 = 0;
 int arr[MAX_SIZE] = {0};
 bool flag = false;
 //Entering N from 3 to 100 included.
 do{
    cin >> N ;
    }while(N < 3 || N > 1000 );
 // Input my array.
 for( int i = 0 ; i < N ; i++){
    cin >> arr[i];
 }
 // Main loop for searching from zero to N element
 for(int i = 0 ; i < N ; i++){
        flag = false ;
    // Checking for N > 5 for biggest palindromes
      if(N > 5){
        if(arr[i] == arr[N - i - 1]  || arr[i] == arr[N - i - 2] || arr[i] == arr[N - i - 3] ){
        flag = true;
        }
      }
    // Loop for searching subsets which are palindromes under six elements.
     for(int j = i + 1 ; j < N ; j++){
        // Palindrome with three elements.
      if(j == i + 2 && arr[i] == arr[j]){
          //cout << arr[i] << " " << arr[j - 1] <<" " <<  arr[j] << endl;
                counter1++;
            }
     // Palindrome with four elements.
      if(j == i + 3 && arr[i] == arr[j] && arr[i + 1] == arr[j - 1]){
        //cout << arr[i] << " " << arr[i + 1] <<" "<< arr[j - 1] << " "<< arr[j] << endl;
        counter1++;
      }
      // Palindrome with five elements.
      if(j == i + 4){
        if(arr[i] == arr[j] && arr[i + 1] == arr[j - 1]){
           // cout << arr[i] << " " << arr[i + 1] << " " << arr[j-2]<<" "<< arr[j - 1] << " " << arr[j] << endl;
            counter2++;
        }
      }
    }
 }
    if(flag )counter = 1 ;
    cout << counter + counter1 + counter2 << endl;
 return 0 ;
}
