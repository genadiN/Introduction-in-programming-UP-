/// Genadi Nikolov Nikolov

#include<iostream>

using namespace std ;

const int MAX = 25 ;
void input(int arr[] , int n  ){

  for(int i = 0 ; i < n ; i++){
   cin >> arr[i];
  }
}

double recursive(int arr[] , int i , int n){
if (i == n-1)
      return arr[i];
   if (i == 0)
      return ((arr[i] + recursive(arr, i+1, n))/n);
      return (arr[i] + recursive(arr, i+1, n));
}

double average(int arr[], int n){
   return recursive(arr, 0 , n);

}
int main(){
    int n = 0, arr[MAX] = {0} , average1 = 0 ;
    do{
    cin >> n;
  }while(n < 0 || n > 20);
    input(arr , n );
    average1 = average(arr , n);
    bool flag = false;
    int index = 0;
    for(int i = n ; i >= 0 ; i--){
        if(arr[i] > average1){
            index = i;
            flag = true ;
            return flag ;
        }else{
           flag = false ;
         }
    }
    if(flag == true){
        cout << index << endl;
    }else{
      cout << " -1 " << endl;
    }
return 0 ;
}
