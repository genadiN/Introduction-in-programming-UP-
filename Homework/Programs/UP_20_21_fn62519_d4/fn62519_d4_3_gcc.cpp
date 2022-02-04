
/**
*
* Solution to homework assignment 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Genadi Nikolov
* @idnumber 62519
* @task 3
* @compiler GCC
*
*/

#include<iostream>

using namespace std ;

// Function to check the right operation.
bool Check ( char operation ){

// Checking for four operation and return.
    if(operation == '/' || operation == '*' || operation == '-' || operation == '+'){
      return true;
    }
    return false;
}

// Function that check the minimum divider of two numbers.
double gcd(double a , double b){
// Converting numbers into long int.
  long int num = (long int)(a);
  long int den = (long int)(b);

// Check is one number equal to null or not.
   if(num == 0){
        return den;
   }

// Return greatest common divider of two numbers.
   return gcd( den % num , num);
}

// Function to decrease the final number.
double Fraction(double &a , double &b){

// Finding the greatest common divider.
     long int fractor = gcd( a , b);
     a = a / fractor;
     b = b / fractor;

// Exit the final fraction numbers.
     cout << a << " " << b <<endl;
}

// Function for collecting numbers.
double Sum(double x1 , double x2 , double y1 , double y2 ){

// Valuables for numerator and denominator.
    double num , den ;
    den = gcd(x2 , y2);

// Finding the denominator
    den = ( x2 * y2 ) / den;

// Finding the number.
    num = x1 * ( den / x2 ) + y1 * den / y2;

// Decrease the fraction.
    Fraction(num , den);
}

// Function for difference.
double Difference( double num1 , double den1 , double num2 , double den2){

// Valuables for numerator and denominator.
  double num , den ;
  den = gcd( den1 , den2);

// Finding the denominator.
  den = ( den1 * den2) / den;

// Finding the numerator.
  num = num1 * den / den1 - num2 * den / den2;

//Decrease the fraction.
  Fraction(num , den);
}

//Function for multiplication.
double Multiplication(double num1 , double den1 , double num2 , double den2){

//Valuables for numerator and denominator.
  double num , den ;

// Finding the numerator.
  num = num1 * num2;

// finding the denominator.
  den = den1 * den2;

// Decrease the fraction.
  Fraction(num , den);
}

// Function for dividing.
double Divide( double num1 , double den1 , double num2 , double den2){

// Valuables for numerator and denominator.
   double num , den;

// Finding the numerator.
   num = num1 * den2;

// Finding the denominator.
   den = den1 * num2;

// Decrease the fraction.
   Fraction(num , den);
}

int main(){

// Declaration of numbers;
   double a , b , c ,d ;

// Check for right input of first numerator.
    do{
        cin >> a;
    }while( a < -100000000 || a > 100000000);

// Check for right input of first denominator.
    do{
        cin >> b ;
    }while( b < -100000000 || b > 100000000);

//Declaration of operation.
   char operation = '\0';
   cin >> operation;

// Check for right input of the operation.
   if( Check(operation) == false){
    cout << " -1 " << endl;
    return 0;
   }

// Check for right input of second numerator.
    do{
        cin >> c;
    }while( c < -100000000 || c > 100000000);

// Check for right input of second denominator.
    do{
        cin >> d;
    }while( d < -100000000 || d > 100000000);

// Make a switch for operations.
    switch(operation){

// Input '+' for sum .
        case '+' :
            Sum(a , b , c , d);
            break;

// Input '-' for difference.
        case '-' :
            Difference(a , b , c , d);
            break;

// Input '/' for dividing.
        case '/' :
            Divide(a, b , c , d);
            break;

// Input '*' for multiplication.
        case '*' :
            Multiplication( a , b , c , d);
            break;
    }
return 0;
}


