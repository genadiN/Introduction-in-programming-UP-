
/**
*
* Solution to homework assignment 2
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

using namespace std ;

const int MAX_SIZE = 1000;

int main(){
//Declaration of my components.
int N = 0 , arr[MAX_SIZE] = {0} , counter = 0 , ArrIndex= 0 , Number = 0 ;
    //If N is not int the interval from 3 to 100 input again,
    do{
    cin >> N;
    }while(N < 3 || N > 100);
    // This loop is if we reach our MAX_SIZE of elements.
    for( int MaximumElements = 0 ; MaximumElements < MAX_SIZE ; MaximumElements++){
        bool flag = true;
        cin >> Number ;
        //Interval for numbers.
        if(Number <-2147483648 || Number > 2147483647){
            break;
        }
        for(int i = 0 ; i < ArrIndex ; i++){
            if(arr[i] == Number){
                flag = false ;
                break;
            }
        }
    //Include different number in my array.
        if(flag){
            arr[ArrIndex]  = Number ;
            ArrIndex++;
        }
    //checking whether my new array is with ' N ' elements.
    if(ArrIndex == N )break;
    }
    //sum of elements which is equal to zero.
    for(int g = 0 ; g < ArrIndex ; g++ ){
        for(int h = g + 1 ; h < ArrIndex ; h++){
            for( int f = h + 1 ; f < ArrIndex ; f++){
    //Check the difference is correct and count equations.
                if(arr[g] + arr[h] + arr[f] == 0){
                    counter++;
                }
            }
        }
    }
    //Exit our final differences.
    cout << counter << endl;
return 0;
}
