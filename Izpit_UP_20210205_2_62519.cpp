#include<iostream>

using namespace std;
/// Task 1

int myStrlen( char str[]){
    int counter = 0;
    while(str[counter++] != '\0'){}
    return counter;
}

bool isCorrectStr(char str[]){
    int length = myStrlen( str);
    bool flag = false;
    for(int i = 0 ; i < length - 1 ; i++){
        if( (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') ){
            flag = true;
        }else {
            return false;
        }
    }
    return flag;
}

bool checkStr( char str[]){
    int length = myStrlen(str);
    bool flag = true;
    if(isCorrectStr(str)){
        for(int i = 0 ; i < length ; i++){
            flag = true;
            if ( i == 0){
                if (str[i] >= 'a' && str[i] <= 'z'){
                    if ( str[i + 1] < 'A' && str[i + 1] > 'Z'){
                        flag = false;
                    }
                }
                if(str[i] >= 'A' && str[i] <= 'Z'){
                    if( str[i + 1] < 'a' && str[i + 1] > 'z'){
                        flag = false;
                    }
                }

            }
            else if ( i > 0 && i < length - 1){
                 if ( str[i] >= 'a' && str[i] <= 'z'){
                    if( (str[i - 1] < 'A' || str[i - 1] > 'Z')
                        ||( str[i + 1] < 'A' || str[i + 1] > 'Z') ){
                        flag = false;
                    }
                }
                if (str[i] >= 'A' &&  str[i] <= 'Z'){
                    if ( (str[i - 1] < 'a' || str[i - 1] > 'z') || (str[i + 1] < 'a' || str[i + 1] > 'z')){
                        flag = false;

                    }
                }
            }

            else if( i == length - 1 ){
                 if ( str[i] >= 'a' && str[i] <= 'z'){
                    if (str[i - 1] < 'A' || str[i - 1] > 'Z'){
                       flag = false;

                    }
                }
                if(str[i] >= 'A' && str[i] <= 'Z'){
                    if(str[i - 1] < 'a' || str[i - 1] > 'z'){
                        flag = false;

                    }
                }
            }

        }
       return flag;
    }else{
        return false;
    }
}

/// Task 2

int* F(char str[]){
    int length = myStrlen(str) , counter = 0 ;
    int* result = new int[3];
    bool flag = true;
    for( int i = 0 ; i < length ; i++){
        if ( (str[i] == 'a') && (str[i - 1] == ' ' || str[i - 1] == '\t')){
            counter++;
        }else if (i == 0 && str[i] == 'a' ){
            counter++;
        }
    }

    result[0] = counter;
    counter = 0;
    for ( int i = 0 ; i < length ; i++){
        if ( (str[i] == ' ' || str[i] == '\t' || str[i] == '\0') && flag == false){
            counter++;
            flag = true;
        }
        if ( str[i] != ' ' && str[i] != '\t' && str[i] != '\0'){
            flag = false;
        }
    }
    result[1] = counter;
    return result;
}

/// Task 3

int countDigits( long n){
    int counter = 0;
    while( n > 0){
        counter++;
        n /= 10;
    }
    return counter;
}

void mySwap( int& a , int& b){
    int c = a;
    a = b;
    b = c;
}

void Sort( int array[] , int size){
    for ( int i = 0 ; i < size ; i++){
        for ( int j = i + 1 ; j < size ; j++){
            if (array[i] > array[j] ){
                mySwap( array[i] , array[j]);
            }
        }
    }
}

int AnalyzeNumber( long n){
    int lengthOfNumber = countDigits( n );
    int counter = 0 , array[lengthOfNumber] ;
    while( n > 0){
        array[counter++] = n % 10;
        n /= 10;
    }

    for ( int i = 0 ; i < counter / 2 ; i++){
        mySwap(array[i] , array[counter - i - 1]);
    }

    Sort( array , counter);
    int smallThanN = 0 , biggerThanN = 0 , middleDigit = array[counter / 2];
    for ( int i = 0 ; i < counter ; i++){
        if ( array[i] != middleDigit && array[i] < middleDigit){
            smallThanN++;
        }
        if( array[i] != middleDigit && array[i] > middleDigit){
            biggerThanN++;
        }
    }
    if ( smallThanN == biggerThanN){
        return 1;
    }
    return -1;

}


int main(){

    /// Task 1
    char str1[100];
    cout << "Input string Task1 "<< endl;
    cin.getline( str1 , 100 , '\n');
    cout << "main function : " << checkStr(str1) << endl;

 /*   /// Task 2
    char str2[100];
    cout << "Input cause for Task2 " << endl;
    cin.getline(str2 , 100 , '\n');
    int *array = F(str2);
    for ( int i = 0 ; i < 2 ; i++){
        cout << array[i] << " ";
    }
    delete[] array;


    /// Task 3
    int array1[10];
    cout << " Input array with 5 digits " << endl;
    for ( int i = 0 ; i < 10 ; i++){
        cin >> array1[i];
    }

    for ( int i = 0 ; i < 5 ; i++){
        cout << AnalyzeNumber( array1[i] )<< endl;
    }

*/

    return 0;
}
