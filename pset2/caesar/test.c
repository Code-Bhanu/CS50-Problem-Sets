#include<stdio.h>

char intToAscii(int number) {
   return (char)number;
}

int main() {
   printf("The ASCII of 5 is %c\n", intToAscii(65));
   printf("The ASCII of 8 is %c\n", intToAscii(90));
}