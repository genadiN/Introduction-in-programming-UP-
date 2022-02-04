/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Genadii Nikolovv
* @idnumber 62519
* @task 2
* @compiler GCC
*
*/



#include<iostream>

using namespace std;

int main(){
    int n = 1 , max2 = 0 , max1 = 0 , counter = 0;
    while(n != 0 && n > 0){
        cin >> n;
        counter = counter + 1;
        if(n > max1 ){ // searching the maximum number
            max2 = max1;
            max1 = n;
        }else if(n > max2){ // searching second maximum number
            max2 = n ;
            }
    }
    cout << endl;
    counter -= 1;
    if(counter <= 2){  // checking whether we have more than two numbers entered
        cout << "-1 " << endl;
    }else if(max1 == max2){ // checking whether we less than 2 numbers entered
            cout << "-1" << endl;
     }else if(max1 != max2){
        cout << max2 << endl;
    }

return 0;
}
