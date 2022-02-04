/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Genadii Nikolovv
* @idnumber 62519
* @task 3
* @compiler GCC
*
*/


#include<iostream>
#include<cmath>

using namespace std ;
 int main(){
    int N = 0 , counter = 0;
    double num = 0.0 ;
    cin >> N ;
    // checking whether entered numbers is in this diapason
    if(N >= 2 && N <= pow(10,9))
      {
        //constants for diving N on 2 and 5
        int p = 0 , k = 0;
        p = N;
        // dividing '1' on our number
        num = 1.0 / N ;
        //difference of divided number and its integer
        num = num - int(num);
        // we divide our number on 2 while it has no remainder
        while(p % 2 == 0)
            {
                p = N / 2;
                N = p;
            }
        // we divide remaindeè on five while it has no reaminder
        while (p % 5 == 0)
            {
                k = p / 5;
                p = k;
            }
        int result = 0;
        // our result afte dividing on 2 and 5
        result = p ;
        // checking whether our last remainder is 1
        // if it is one our number is not endless liver
        if (result == 1)
        {
            while(num != 0)
            {
                // multiplication divided number
                num = num * 10;
                // increase counter
                counter++ ;
                //difference of divided number and its integer
                num = num - int(num);
           }
            cout << counter << endl;
        }else
            {
                cout << "NO" << endl;
            }
     }else
        {
            cout << "0" << endl;
        }
    return 0;
    }
