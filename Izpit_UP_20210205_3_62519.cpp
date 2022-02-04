#include<iostream>

using namespace std;

void mySwap( long &a , long &b){
    long c = a;
    a = b;
    b = c;
}

void ConvertArr( long arr[] , long S , long E){
    if ( S >= 0 && S < E && E >= 0){
        for ( int i = S ; i < (S + E) / 2 ; i++){
            mySwap(arr[i] , arr[S+E - i]);
        }
    }
}

int findElement( long arr[] , int l){
    int k = -2;
    for ( int i = l ; i > 0 ; i--){
        if ( arr[i] > (arr[i - 1] + arr[ i + 1]) / 2 ){
           k = i ;
        }
    }
    if ( k != -2 ){
        return k;
    }
    return -1;
}

int ** mergearrays( int* A, int* B, int m ){
    int ** pArr = new int* [2];
    for ( int i = 0 ; i < m ; i++){
        pArr[i] = new int[m];
    }

    for ( int i = 0 ; i < 2 ; i++){
        for ( int j = 0 ; j < m ; j++){
            if ( i == 0){
                pArr[i][j] = A[j];
            }else {
                pArr[i][j] = B[j];
            }

        }
    }
    return pArr;
}

int main(){
/*
Task 1
    long arr[8] = {4, 5, 6, 7, 8, 9, 0, 1} , S = 2 , E = 5;
    ConvertArr( arr , S , E);
*/

//Task 2
    int l = 7 ;
    long arr[l] = {2, 3, 17, 8, 1, 9};
    cout << findElement( arr , l) << endl;

/*   int** pMatric = new int*[2];
    int n = 5 , A[n] = {3, 5, 11, 2, 9} , B[n] = {1, 4, 32, 71, 5};
    for (int i = 0 ; i < 5 ; i++){
        pMatric[i] = new int [n];
    }
    pMatric = mergearrays( A , B , n);
    for ( int i = 0 ; i < 2 ; i++){
        for ( int j = 0 ; j < n ; j++){
            cout << pMatric[i][j] << " ";
        }
        cout << endl;
    }

    for( int i = 0 ; i < n ; i++){
        delete[] pMatric[i];
    }
    delete[] pMatric;
*/
return 0;
}
