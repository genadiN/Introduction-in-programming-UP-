
/// Genadi Nikolov Nikolov 62519


int myStrlen( char* str ){
    int counter = 0;
    while(str[counter++] != '\0'){}

    return counter;
}

bool checkStr ( char* str ){
    int length = myStrlen ( str );
    bool flag = false;
    for ( int i = 0 ; i < length - 1 ; i++){
        if ( str[i] >= '0' && str[i] <= '9'){
            flag = true;
        }else {
            return false;
        }
    }
    return flag;
}

long charToInt( char* num ){
    long length = myStrlen( num ) , sum = 0;
    for ( int i = 0 ; i < length - 1; i++){
        sum += num[i] - '0';
    }
    return sum;
}

long convertNumber( char* num){
    if ( checkStr( num ) == false ){
        return -1 ;
    }
    long sumChar = charToInt( num );
    return sumChar;
}

long nFactoriel( long n ){
    long sum = 1;
    while ( n > 0){
        sum = sum * n ;
        n--;
    }
    return sum;
}

double powNumber( double n , long stepen ){
    int sum = 1;
    for(int i = 0 ; i < stepen ; i++){
        sum *= n ;
    }
    return sum ;
}

double mySin( double x , long n){
    double sum = 0;
    for( int i = 0 ; i < n ; i++){
        sum += ( powNumber( -1 , n ) * powNumber(x , 2 * n + 1) )
                / ( nFactoriel( 2 * n + 1) );
    }
    return sum ;
}

int charToInt(char str){
    return (int)str;
}
char fromDigitToChar( int num ){
    if ( num == 0){ return '0' ; }
    else if ( num == 1 ) { return '1' ;}
    else if ( num == 2 ) { return '2' ;}
    else if ( num == 3 ) { return '3' ;}
    else if ( num == 4 ) { return '4' ;}
    else if ( num == 5 ) { return '5' ;}
    else if ( num == 6 ) { return '6' ;}
    else if ( num == 7 ) { return '7' ;}
    else if ( num == 8 ) { return '8' ;}
    else if ( num == 9 ) { return '9' ;}
}


char* Encode( char* str ){
    int length = myStrlen( str ) , index = 0;
    char* result = new char[length * 4 + 1];
    for(int i = 0 ; i < length ; i++){
        if ( (int)str[i] > 0 && (int)str[i] < 100 ){
            int number = str[i];
            int second_digit = number % 10 ;
            int first_digit = number / 10 ;
            result[index++] = fromDigitToChar( first_digit );
            result[index++] = fromDigitToChar( second_digit );
        }else if ( (int)str[i] < 10 ){
            result[index++] = str[i];
        }else{
            int number = str[i];
            int second_digit = number % 10 ;
            int first_digit = (number / 10 ) % 10  ;
            int third_digit = ( number / 100 ) ;
            result[index++] = fromDigitToChar( third_digit);
            result[index++] = fromDigitToChar( first_digit );
            result[index++] = fromDigitToChar ( second_digit );
        }
        if (i != length - 1){
            result[index++] = '_';
        }
    }
    result[index] = '\0';
    return result;
}

