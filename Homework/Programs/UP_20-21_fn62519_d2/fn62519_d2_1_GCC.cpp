
/**
*
* Solution to homework assignment 2
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
#include<cmath>

using namespace std ;

const int MAX_SIZE = 200;
int arr[MAX_SIZE] = {0};

void InputArray (int a){
  for( int i = 0 ; i < a ; i++){
    cin >> arr[i] ;
  }
 }

int main(){
  int N = 0 , HalfN = 0;
  bool flag = false;
  // Checking whether our N is from 3 to 100
  do{
    cin >> N;
  }while(N < 3 || N > 100);
  // Checking is ' N ' even or odd to make our intervals for a difference
  if(N % 2 == 0 ){
    HalfN = N / 2 -1; // input 10 ;
  }else{
   HalfN = N / 2 ;
   }
    // Checking is ' N ' even or odd to make our intervals for a difference
   if(N % 2 == 0 ){
    HalfN = N / 2 -1; // input 10 ;
  }else{
   HalfN = N / 2 ;
   }
    // Input our Array !
  InputArray(N);
  flag = true ;
  for(int i = 0 ; i < HalfN ; i++){
         // Sum of differences and hecking i they are equal.
        if((abs(arr[i] - arr[i+1]) ) != (abs(arr[N - i -1] - arr[N - i - 2])) ){
           flag = false;
           break;
           }
   }
   // Exit 0 if it is not a triangle several and 1 if it is a triangle several.
   cout << flag << endl;
}
