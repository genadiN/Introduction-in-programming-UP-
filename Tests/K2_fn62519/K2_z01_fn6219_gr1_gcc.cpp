/// Genadi Nikolov Nikolov


#include<iostream>

using namespace std ;

const int MAX = 200 ;

int Func(int n , int m){
   int digit[MAX] = {0} , index = 0;
     while(n > 0){
        int k = n % 10;
        digit[index++] = k;
        n /= 10;
    }
    int arr[MAX] = {0} , counter = 0 ;
    for(int i = index ; i >= 0 ; i--){
       arr[counter] = digit[i];
       counter++;
    }
   int sum = 0 ;
   if(counter - 1 >= m){
    sum = digit[0] - digit[m - 1];
    return sum;
   }else{
        return -10;
    }
    return 0 ;
}

int main(){
    int N = 0 , M = 0;
    do{
         cin >> N >> M;
    }while(N < 0 || M < 0);
    cout<< Func(N , M);




}
