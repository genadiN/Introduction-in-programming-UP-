#include "header.h"

#include<iostream>

using namespace std;

int main(){
    char str[10];
    cin.getline(str , 10 , '\n');
   /* char* pStr = Encode( str );
    for ( int i = 0 ; i < myStrlen ( pStr); i++){
        cout << pStr[i];
    }

    delete[] pStr;*/
    cout << charToInt( str ) << endl;
    cout << mySin( 30 , 180) << endl;

}
