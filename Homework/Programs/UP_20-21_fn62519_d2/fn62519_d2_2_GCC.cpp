
/**
*
* Solution to homework assignment 2
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

using namespace std ;

//Function for input an array.
void InputArray(double arr[] , int n ){
    for(int i = 0 ; i < n ; i++){
        do{
            cin >> arr[i] ;
        }while(arr[i] < 0.1 || arr[i] > 100);
    }
}
//Function for sum of the profit.
double Profit(double arr[] , int n){
   double profit = 0.0 ;
   int bottom = 0 ;
   for(int i = 0 ; i < n ; i++){
        //If the first element of the array is biggest
        if(arr[i - 1] > arr[i]){
            bottom = i;
        }
        // Checking for biggest elements in the array.
        if(arr[i - 1] <= arr[i] && (i + 1 == n || arr[i] > arr[i + 1])){
            profit += arr[i] - arr[bottom];
        }
   }
   // Sum of the profit.
   cout << profit << endl ;
}
const int MAX_SIZE = 200;

int main(){
 int N = 0 ;
 double arr[MAX_SIZE] = { 0.0 };
 // Checking if N element from 3 to 365
 do{
    cin >> N;
 }while(N < 3 || N > 365);
 InputArray(arr , N );
 Profit(arr , N );

return 0 ;
}
