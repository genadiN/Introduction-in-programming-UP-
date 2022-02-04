/**
*
* Solution to homework assignment S
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Genadi Nikolov
* @idnumber 62519
* @task 1
* @compiler GCC
*
*/


#include <iostream>

using namespace std;

// Boolean function, checks if the year is leap or not;
bool isLeapYear ( int year ){
    if ( year % 4 == 0){
        if ( year % 100 == 0){
            if ( year % 400 == 0){
                return true;
            }
            else {
                return false;
            }
        }else {
            return true;
        }
    }else {
        return false;
    }

}

// Main function for out leap years ;
void leapYearInterval( int Y , int M){
        int counter = 0;

// Loop for countering and showing leap years;
        while (counter <= M){
//Check if the function isLeapYear is true;
            if ( isLeapYear(Y) == true ){
// If it is true increase counter and out the year;
                counter++;
                cout << Y << endl;
            }
// Increase the year;
            Y++;
        }
}

// Main function;
int main()
{
// Initialize variables;
    int Y = 0 , M = 0;
// Input variables;
    cin >> Y >> M ;
// Checks after entering whether they are in correct interval;
    if ( Y < 0 || Y > 2100 || M < 0 || M > 1000){
        cout << "-1" << endl;
        return 0;
    }else {
// Doing the isLeapInterval functon;
        leapYearInterval( Y , M);
    }

    return 0;
}
