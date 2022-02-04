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
#include<math.h>

using namespace std ;

int main(){
  int a = 0 , b = 0 , c = 0;
  cin >> a >> b >> c;
         // checking whether entered numbers are digits
     if(a >= 0 && a <= 9 && b >= 0 && b <=9 && c >= 0 && c <= 9 ){
        if (a == 0 && b == 0 && c == 0){ cout << "0" << endl; }
           else{
                // checking all situations with when numbers are zero
            if(a == b && a == c ){ cout << a << a << a << endl; }
            if(a == 0 && b == 0 ){ cout << c << a << b << c << endl; }
            if(a == 0 && c == 0 ){ cout << b << a << c << b << endl; }
            if(b == 0 && c == 0 ){ cout << a << b << c << a << endl; }
        else{
            // checking all situations when 'a' when is different from zero
        if(a != 0){
          if(a == b && a < c){ cout << a << c << a << endl; }
          if(a == b && a > c){ cout << a << c << b << endl; }
          if(a == c && a < b){ cout << a << b << a << endl; }
          if(a == c && a > b){ cout << a << b << a << endl; }
          if(a < b && b < c  ){ cout << a << b << c << b << a << endl; }
          if(a < c && c < b  ){ cout << a << c << b << c << a << endl; }
        }
       // checking all situations when 'a' when is zero
        else if(a == 0 && b != 0 && c != 0){
           if (b < c){ cout << b << a << c << a << b << endl; }
           if (b > c){ cout << c << a << b << a << c << endl; }
        }
        // checking all situations when 'b' when is different from zero
        if(b != 0){
           if(b == c && b < a){ cout << b << a << b << endl; }
           if(b == c && b > a){ cout << b << a << c << endl; }
           if(b < a && a < c  ){ cout << b << a << c << a << b << endl; }
           if(b < c && c < a ){ cout << b << c << a << c << b << endl;  }
        }
        // checking all situations when 'b' is zero
        else if(b == 0 && a != 0 && c != 0) {
         if(a < c){ cout << a << b << c << b << a << endl; }
         if(a > c){ cout << c << b << a << b << c << endl; }
         }
         // checking all situations when 'c' when is different from zero
         if (c != 0){
            if(c < a && a < b ){ cout << c << a << b << a << c << endl; }
            if(c < b && b < a ){ cout << c << b << a << b << c << endl; }
         }
         // checking all situations when 'c' when is zero
         else if(c == 0 && a != 0 && b != 0) {
            if(a > b ){ cout << b << c << a << c << b << endl; }
            if(a < b ){ cout << a << c << b << c << a << endl; }
            }
          }
        }
     }else cout << " -1 " << endl;

 return 0;
}
