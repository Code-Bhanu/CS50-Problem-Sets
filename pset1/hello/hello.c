#include<cs50.h>
#include<stdio.h>
int main(void)
{
//Get the name of the user and print it
    string name = get_string("What is your name?");
    printf("hello %s\n", name);
}
