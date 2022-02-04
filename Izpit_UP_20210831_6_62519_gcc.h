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
/*
void reverseNumber( int number ){
    int newnumber = 0 , stepen = 1 , counter = 0;
    while ( number > 0){
        counter*=10;
        number /= 10 ;

    }
    stepen = counter;
    while ( number > 0) {
        newnumber += number % 10 * stepen;
        stepen /= 10 ;
        number /= 10;
    }
    number = newnumber;
}
*/
/*
char* Encode( char* str ){
    int length = myStrlen( str ) , index = 0;
    char* result = new char[length * 2 + 1];
    for(int i = 0 ; i < length ; i++){
            int symbol = charToInt( str[i]);
            reverseNumber( symbol );
            while( symbol > 0){
                result[index] = char((symbol % 10) - '0');
                symbol /= 10;
                index++;
            }
            result[index++] = '_';
    }
    return result;
}

