/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Genadi Nikolov
* @idnumber 62519
* @task 2
* @compiler GCC
*
*/


#include<iostream>

using namespace std ;

// Constant for maximum elements int strings.
const int MAX_SIZE = 151;

// Function for input the first two strings.
void Input( char str[] ){
   cin.getline(str , MAX_SIZE , '\x20');
}

// Function for input the last string.
void Input2(char str[]){
 cin.getline(str , MAX_SIZE , '\n');
}

// Function for length of string.
int strlen(char str[]){
   int counter = 0;
   while(str[counter++] != '\0');
   return counter ;
}

// Function that checks for upper cases and convert them to lower.
bool LowerCase(char str[]){
   int N = strlen(str);
   for(int i = 0 ; i < N ; i++){

// Check and return  true if in the string have upper cases.
       if(str[i] < 'a' || str[i] > 'z'){
            return true;
       }
   }
// Otherwise return false.
   return false;
}

// Function for sort a string.
void Sort(char str[]){
   int N = strlen(str);
   for(int i = 0 ; i < N ; i++){
    for(int k = i ; k < N ; k++){
        if(str[i] > str[k]){
        char Swap = str[i];
        str[i] = str[k];
        str[k] = Swap;
        }
    }
  }
}

// Function compare if two sorted strings are equals.
bool strncmp(char str1[] , char str2[]){
  int N = strlen(str1) ;
  Sort(str1);
  Sort(str2);
 for( int i = 0 ;i < N ; i++){
    if( str1[i] != str2[i]){
        return false;
    }
 }
 return true;
}

// Final function that checks whether
// third string is a concatenation of first two strings.
int Function(char str1[] , char str2[] , char str3[]){

//Input two more strings where i will put the third string.
    char usestr1[MAX_SIZE] =" \0 " ;
    char usestr2[MAX_SIZE] = " \0 ";

// Variables for length of strings.
    int M = strlen(str1);
    int N = strlen(str2);
    int T = strlen(str3);

// Checks if char arrays have upper cases and return -1 if it is true.
    if(LowerCase(str2) == true ){
        return -1;
    }else if(LowerCase(str1) == true){
        return -1;
     }else if(LowerCase(str3) == true){
         return -1 ;
      }

// Checks whether sum of lengths of first two strings is equal to third string.
    if(M + N -2 != strlen(str3) - 1){
        return false;
    }else{

// Input elements from 0 to M.
      for(int i = 0 ; i < M - 1; i++){
        usestr1[i] = str3[i];
      }

// Input elements from M -1 to the last element.
      for(int i = M - 1 ; i <= M + N  - 1; i++){
        usestr2[i] = str3[i];
      }

// Comparing the new string with the first and second strings.
     if( strncmp ( str1 , usestr1 ) ) return true;
     else if( strncmp ( str2 , usestr2 ) )return true;
     else{

// Make new strings for second case.
        char teststr1[MAX_SIZE] = "\0";
        char teststr2[MAX_SIZE] = "\0";

//Input elements in the new string form 0 to N.
        for(int i = 0 ; i < N ; i++){
           teststr1[i] = usestr2[i];
        }

// Input elements in the new string from N to  M + N which is the last element.
        for(int i = N ; i < M + N ; i++){
            teststr2[i] = usestr1[i];
        }

// Comparing this new strings with second and first strings;
        if ( strncmp ( teststr1 , str2 ) ) return true;
        if ( strncmp ( teststr2 , str1 ) ) return true;
     }
    }

// If we reach here it means that third string is nor a concatenation of the previous two.
    return false;
}

int main(){

// Initialization of three strings.
    char str1[MAX_SIZE] = "\0";
    char str2[MAX_SIZE] = "\0";
    char str3[MAX_SIZE] = "\0";

// Input three strings.
    Input(str1);
    Input(str2);
    Input2(str3);

// Exit the result of the function.
    cout << Function(str1 , str2 , str3);
}
