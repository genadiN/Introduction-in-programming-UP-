#include<iostream>

using namespace std;

int largestSeq( int arr[] , int N){
    int sumEvenNumbers = 0 , maxSum = 0;
    for ( int i = 0 ; i < N ; i++){
        if ( arr[i] % 2 == 0){
            sumEvenNumbers = 0;
            for ( int j = i ; j < N ; j++){
                if ( arr[j] % 2 == 0){
                    sumEvenNumbers += arr[j];
                }else {
                    break;
                }
            }
        }
        if ( maxSum < sumEvenNumbers){
            maxSum = sumEvenNumbers;
        }
    }

    return maxSum;
}

int myStrlen( char str[]){
    int counter = 0;
    while( str[counter++] != '\0'){}

    return counter;
}

int* numOfWords( char str[]){
    int length = myStrlen ( str ) , counter = 0 , evenWords = 0 ,oddWords = 0;
    int *result = new int[2];
    bool flag = false;
    for ( int i = 0 ; i < length ; i++){
        if ( str[i] != ' ' && str[i] != '\t' && str[i] != '\0'){
            counter++;
        }
        if ( str[i] == ' ' || str[i] == '\t' || str[i] == '\0'){
            if ( (counter ) % 2 == 0){
            evenWords++;
            }else {
                oddWords++;
            }
            counter = 0;
        }
    }
    result[0] = evenWords;
    result[1] = oddWords;
    return result;
}

int* mergeArrays( int A[] , int B[] , int m){
    int *answer = new int[m];
    int j = m - 1;
    for ( int i = 0 ; i < m ; i++ ){
        answer[i] = A[i] + B[j];
        j--;
    }
    return answer;
}

int main(){
/*
    int arr[12] = { 2, 4, 3, 11, 12, 168, 144, 5, 9, 62, 98, 1};
    cout << largestSeq( arr , 12 ) << endl;
*/
 /*   char str[100];
    cin.getline(str , 100 , '\n');
    int *pArr = numOfWords(str );
    for( int i = 0 ; i < 2 ; i++){
        cout << pArr[i] << " " ;
    }
    delete[] pArr;
  */
  int m = 4 , A[m] = {1, 2, 3, 4} , B[m] = {2, 5, 7, 11};
  int *pointerArr = mergeArrays( A , B , m);
  for ( int i = 0 ; i < m ; i++){
    cout << pointerArr[i] << " ";
  }
  delete[] pointerArr;
}
