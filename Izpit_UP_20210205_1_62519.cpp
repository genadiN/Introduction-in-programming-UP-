#include<iostream>

using namespace std;
///Task 1
int myStrlen( char *str){
    int counter = 0;
    while(str[counter++] != '\0'){}

    return counter;
}

void mySwap( char& a , char& b){
    char c = a;
    a = b ;
    b = c;
}

char* reverseString( char* str){
    int length = myStrlen( str );
    char* pStr = new char[length + 1];
    for ( int i = 0 ; i < length / 2 ; i++){
        mySwap( str[i] , str[ length - i - 1]);
    }
    return str;
}

char* revandreplace(char* str ){
    int length = myStrlen( str );
    for ( int i = 0 ; i < length ; i++){
        if ( str[i] == 'e'){
            str[i] = '!';
        }else if( str[i] == 'y'){
            str[i] = '*';
        }
    }

   char* pStr = reverseString(str);;
   for ( int i = 0 ; i < length ; i++){
    cout << pStr[i];
   }
    return pStr;
}

///Task 2
int* charToInt( char str[]){
    int length = myStrlen( str);
    int* integerArray = new int[length];
    for ( int i = 0 ; i < length ; i++){
        integerArray[i] = str[i] - '0';
    }
    return integerArray;
}

int arrayToNumber( int *arr , int N){
    int number = 0 , degree = 1;
    for ( int i = 0 ; i < N - 1; i++){
        degree *= 10;
    }

    for( int i = 0 ; i < N  ; i++){
        number = number + arr[i] * degree;
        degree /= 10;
    }
    return number;
}
bool CheckDate(char* str){
   int* array = charToInt ( str) ;
   int number = arrayToNumber( array , myStrlen( str ) - 1);
   if ( number % 4 == 0){
       if ( number % 100 == 0){
            if ( number % 400 == 0){
                return true;
            }
            else {
                return false;
            }
       }
       else {
        return true;
       }
   }
   else {
    return false;
   }
}

///Task 3

int* countletters(int A[] , int B[] , int N){
    int* arr = new int[3];
    int sumArray[N] ;
    for ( int i = 0 ; i < N ; i++){
        sumArray[i] = A[i] + B[i];
    }

    for ( int i = 0 ; i < N ; i++){
        if ( sumArray[i] >= 65 && sumArray[i] <= 90){
            arr[0]++;
        }
        if ( sumArray[i] >= 97 && sumArray[i] <= 122){
            arr[1]++;
        }
    }
    return arr;
}

int main(){

/// Task 1
/*    char str[100] ;
    cin.getline(str , 100 , '\n');
    char *pointer = revandreplace(str );
    cout << *pointer << endl;
    delete[] pointer;*/

/// Task 2
    char str1[100];
    cin.getline(str1 , 100 , '\n');
    cout << CheckDate( str1) << endl;

/// Task 3
   /* int n = 5 , arr1[5] = {3, 5 , 11 , 2 , 9} , arr2[n] = {1, 4 , 32 , 71 , 5};
    int* array = countletters(arr1 , arr2 , n);
    for ( int i = 0 ; i < 2 ; i++){
        cout << array[i] << " ";
    }*/
}
