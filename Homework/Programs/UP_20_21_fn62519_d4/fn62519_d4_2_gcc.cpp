
/**
*
* Solution to homework assignment 4
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
#include<iomanip>

using namespace std;

// function for checking is the coordinates are in the chess board.
bool CorrectMoving(int N , int M , int row , int cow ){

// Check is they are in the limit - [N , M].
    if(row >= 0 & row <= N && cow >= 0 && cow <= M ){

// And returning the answer.
        return true;
    }
    return false;
}


// Function for searching the position.
bool SearchingPosition(int N , int M , int p , int q , int p1 , int q1 , int k , int movings){

// Check if we are reach the position.
    if( p == p1 && q == q1 ){
        return true;
    }

// Check if we reach the numbers of allowed movings.
    if( movings >= k){
        return false;
    }

// Start checking all possible coordinates.
    if( CorrectMoving(N , M , p - 2  , q - 1 ) == true){
        if( SearchingPosition( N , M , p - 2 , q - 1 , p1 , q1 , k , movings + 1) == true ){
            return true;
        }
    }
    if( CorrectMoving (N , M , p - 1 , q - 2) == true){
        if( SearchingPosition ( N , M , p - 1 , q - 2 , p1 , q1 , k , movings + 1) == true ){
            return true;
        }
    }
    if(CorrectMoving (N , M , p - 2 , q + 1 ) == true){
        if( SearchingPosition ( N , M , p - 2 , q + 1 , p1 , q1 , k , movings + 1) == true ){
            return true;
        }
    }
    if(CorrectMoving (N , M , p - 1  , q + 2 ) == true){
        if( SearchingPosition ( N , M , p - 1 , q + 2 , p1 , q1 , k , movings + 1) == true ){
            return true;
        }
    }
    if(CorrectMoving ( N , M , p + 1  , q - 2  ) == true){
        if( SearchingPosition ( N , M , p + 1 , q - 2 , p1 , q1 , k , movings + 1) == true ){
            return true;
        }
    }
    if(CorrectMoving ( N , M , p + 2  , q - 1 ) == true){
        if( SearchingPosition ( N , M , p + 2 , q - 1 , p1 , q1 , k , movings + 1) == true){
            return true;
        }
    }
    if(CorrectMoving ( N , M , p + 1  , q + 2 ) == true){
        if( SearchingPosition ( N , M , p + 1 , q + 2 , p1 , q1 , k , movings + 1) == true ){
            return true;
        }
    }
    if(CorrectMoving ( N , M , p + 2  , q + 1 ) == true){
        if( SearchingPosition ( N , M , p + 2 , q + 1 , p1 , q1 , k , movings + 1) == true){
            return true;
        }
    }
    return false;
}

int main(){

// Variables used for range of chess board , start and search position and allowed moves.
    int N , M , p , q , p1 , q1 , k;

// Correct input of chess board.
    do{
        cin >> N ;
    }while( N < 3 || N > 200);
    do{
        cin >> M;
    }while( M < 3 || M > 200);

// Input other variables.
        cin >> p >> q >> p1 >> q1 >> k;

// Exit the answer.
    if( SearchingPosition( N , M , p ,q , p1 , q1 , k , 0) == true){
        cout << " true " <<  endl;
    }else {
        cout << " false " << endl;
    }

return 0;
}
