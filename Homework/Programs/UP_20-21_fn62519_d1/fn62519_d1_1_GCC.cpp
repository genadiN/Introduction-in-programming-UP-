/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Genadii Nikolovv
* @idnumber 62519
* @task 1
* @compiler GCC
*
*/



#include<iostream>
#include<math.h>

using namespace std ;

int main(){
    int N = 0 , X = 0 , M = 0;
    int sum = 0 , sumeven = 0 , oddbr = 0 , evenbr= 0;
    int k = 0 , br = 0;
    cin >> N;
    cin >> X;
    cin >> M;
    if(N > 0 && M > 0 && X > 0){
    for(int i = 1 ; i <= N ; i++){
        if(i % 2 == 1){
            oddbr++ ; // we count odd birthdays
        }
        if(i % 2 == 0){
            br++;
            evenbr += br; // counter for even birthdays
        }
    }
      k = -5*br; // calculate spending money for treats
      sumeven = evenbr * 30; //  calculate money in cash from even birthdays
      M *= oddbr; // calculate money from odd birthdays
      sumeven = k + sumeven; // calculate money from even birthdays
      sum  = M + sumeven; // calculate all saved money
      cout << endl;
      // checking whether we have money for a laptop
      if(sum > X){
        cout << "yes" << endl << sum - X << endl;
      } else if(sum < X){
           cout << "no" << endl << abs(sum - X) <<endl;
        }
    }else cout << "wrong input " <<endl;

 return 0;
}
