/**
*
* Solution to homework assignment 3
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
#include<iomanip>

using namespace std ;

/// Constant for maximum size of the matrix.
const int MAX_SIZE = 500;

/// Function for input numbers in matrix.
int Input(double arr[][MAX_SIZE] , int N ){
    double input = 0.0 ;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){

        //Input elements from [ 1 , 100 ] ,
            do{
                cin >> input ;
             }while( input < 0 || input > 100);
            arr[i][j] = input;
        }
    }
}

/// Function for summation of values in the diagonals.
int Sumdiagonals( double arr[][MAX_SIZE] , int N){
    long double sumd2 = 0.0 , sumd = 0.0 ;
    for(int i = 0 ; i < N ; i++){

/// Sum of the second diagonal.
        sumd2 += arr[i][N - i - 1];
        for(int j = 0 ; j < N ; j++){
            if(i == j ){

/// Sum of the main diagonal.
                sumd += arr[i][j];
            }
        }
    }
/// Checking if two sums are equal.
    if(sumd == sumd2){
        return sumd;
    }
    else{
        return -1;
    }
}

/// Function for summation of values of rows.
int sumRows(double arr[][MAX_SIZE] , int N ){
    double sumi , indexi = 0.0 , oldsumi = 0.0 ;
    double sum = 0.0;
    bool flag = false;
    for(int i = 0 ; i < N ; i++){
        flag = false;
        sumi = 0;
        for(int j = 0 ; j < N ; j++){

/// Sum of the rows.
            sumi += arr[i][j];

/// Checking if new sum is equal to old sum.
            if( oldsumi == sumi ){
                flag = true ;
            }
            else{
             flag = false;
            }
        }
            oldsumi = sumi ;
   }
/// Exit the sum of the rows if they are equal otherwise exit -1.
    if( flag ){
       return sumi;
    }
    else {
      return -1;
     }
}

/// function for summation of values in cows.
int sumCows(double arr[][MAX_SIZE] , int N ){
    double sum = 0.0 , sumj = 0.0 , indexj = 0.0 , k = 0;
    bool flag = false;
    for(int j = 0 ; j < N ; j++){
            flag = false;

/// Making sum of the rows each time equal to null.
            sumj = 0.0;
        for(int i = 0 ; i < N ; i++){

/// Sum of the cows.
                sumj += arr[i][j];
        }

/// checking if new sum is equal to old sum .
        if( k == sumj ){
            flag = true ;

        }else{
         flag = false;
        }
        k = sumj;
      }

/// Exit sum of cols if they are equal on exit -3 if they are not equal.
    if( flag ){
        return sumj ;
    }else {
      return -3;
      }
}

/// Function checking if the quadrat is magic.
bool F(double arr[][MAX_SIZE] , int N){
   double  indexi , indexj , indexd;
   bool flag = false;

/// Variables which gain values of the function above.
   indexd = Sumdiagonals(arr, N) ;
   indexi = sumRows(arr , N) ;
   indexj =sumCows(arr , N) ;

/// Checking for the magic quadat .
 if( indexi == indexd && indexi == indexj){
        flag = true ;
        return flag;
    }
    else{
        flag = false;
    }
    return flag ;
}

int main(){
    int N = 0 ;
    double arr[MAX_SIZE][MAX_SIZE] = {0.0};

/// Input " N " from ( 1 , 1000);
     do{
        cin >> N ;
     }while(N <= 1 || N >= 1000);

/// Input an array.
    Input(arr , N);

/// Exit the result.
    cout << F(arr , N) << endl << endl;

return 0 ;
}

