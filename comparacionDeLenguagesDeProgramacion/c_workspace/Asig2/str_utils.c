/*
 * Ricardo J Mojica Rivera
 * 841-07-5094
 * September 24, 2014
 * str_utils.c
 * This program take string and change it to uppercase
 * check if is a digit and return the digit or 0 if no digit
 */

#include <stdio.h>  //for printf
#include <ctype.h> //for toupper, isdigit

#define LINE_SIZE 51


void strtoupper(const char *str);
int strtoint(const char *str);


int main(void){
    char string1[LINE_SIZE] = "hello world!", string2[LINE_SIZE] = "-45", string3[LINE_SIZE];

    printf("This is string1: %s\n", string1);
    printf("This is string2: %s\n", string2);
    printf("This is toupper string1 result: ");
    strtoupper(string1);
    printf("\n");
    printf("string1 digit is: %d\n", strtoint(string1));
    printf("string2 digit is: %d\n", strtoint(string2));

    printf("\nEnter a sentence or a number: ");
    gets(string3);
    printf("This is your string toupper result: ");
    strtoupper(string3);
    printf("\n");
    printf("string1 digit is: %d\n", strtoint(string3));


}

// print every character in uppercase
void strtoupper(const char *str){
    while(*str){
        printf("%c", toupper(*str));
        str++;
    }
}

// Check if the string is a number
// if not a number return 0
// else return the integer of the string
int strtoint(const char *str){
    int tempnum = 0, sign = 1;
    if (*str == '-'){
        sign = -1;
        str++;
    }
    while(*str && (isdigit(*str))){
         tempnum = *str -'0' + tempnum * 10;
         str++;
    }
    if (*str)
        return 0;
    else
        return tempnum*sign;
}
