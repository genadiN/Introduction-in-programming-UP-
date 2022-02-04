/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Genadi Nikolov
* @idnumber 62519
* @task 4
* @compiler GCC
*
*/

#include <iostream>

using namespace std;

// Constant for maximum size of the char array.
const int MAX_SIZE = 100;

// Function for length of the char array.
int Strlen(char str[])
{
    int counter = 0;
    while (str[counter++] != '\0');
    return --counter;
}

// Function for correct input.
int CheckInput(char str[])
{
    int N = Strlen(str);
    for (int i = 0; i < N; i++)
    {
// Check if the input is alphabet symbols.
        if ( ! ( ( str[i] >= 'A' && str[i] <= 'Z' ) || ( str[i] >= 'a' && str[i] <= 'z' ) ) ){
            return -1;
        }
    }
    return 1;
}

// Main function .
int Combinations(char str[])
{
    int counter = 0;
    int N = Strlen(str);

// Loop from 0 to the end of the array.
    for (int i = 0; i < N; i++)
    {
// Loop for sifting out.
        for (int j = 0; j < N - i; j++)
        {
            counter++;
        }
    }
    return counter;
}

int main()
{

// Declaration of char array.
    char str[MAX_SIZE] = "\0";

//Initialization of char array.
    cin.getline( str , MAX_SIZE , '\n');

// Check for correct input.
    if (CheckInput(str) == -1)
    {
        cout << -1;
        return 0;
    }

//Output - prints the result
    cout << Combinations(str);

    return 0;
}
