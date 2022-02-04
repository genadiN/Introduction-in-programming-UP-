/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Genadii Nikolovv
* @idnumber 62519
* @task 4
* @compiler GCC
*
*/


#include<iostream>
#include<cmath>

using namespace std ;

int main(){
   unsigned int N = 1 , m = 1 , p = 1 , q  = 1  , summin = 0;
    cin >> N;
    q = N;
    if(N >= 1 && N <= pow(10 , 9)){
        summin = N + 2; // the maximum sum
                for(int im = 1 ; im <= N ; im++){
                        if(N % im == 0){ // checking for a dividing without a remainder
                    for(int ip = 1 ; ip <= N / im ; ip++){ // decrease diapason of the loop
                        if(N % ip == 0){ // checking for a dividing without a remainder
                           for(int iq = 1 ; iq  <= N  / ip / im; iq++){
                               if(im * ip * iq == N){ // multiplication of searching three numbers
                                 int sum = 0;
                                 sum = im + ip + iq;
                                 if(sum < summin){ // finding minimum sum
                                    summin = sum;
                                    m = im;
                                    p = ip;
                                    q = iq;
                                 }
                               }
                            }
                        }
                    }


                        }

                }
        cout << m << " " << p << " " << q << endl;
    }else cout << " 0 " <<endl;

return 0 ;
}
