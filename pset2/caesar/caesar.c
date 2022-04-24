#include<cs50.h>
#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

//functions declaration
void cipher(string s);
char formula(char pi);

//global variable declaration
int key = 0;

int main(int argc, string argv[])
{

    //local variable declaration
    int digi_check = 0;
    string plaintext;
    //check whether number of arguments are 2
    if (argc == 2)
    {
        //check whether argument is non-digit
        for (int i = 0 ; i < strlen(argv[1]); i++)
        {
            if (!(isdigit(argv[1][i])))
            {
                digi_check = 1 ;
                break;
            }
        }
        if (digi_check != 1)
        {
            //convert argument from string to integer
            key = atoi(argv[1]);
            //prompt user for input
            plaintext = get_string("plaintext: ");
            //call cipher function
            cipher(plaintext);
        }
        else
        {
            printf("Usage: ./caesar key");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./caesar key");
        return 1;
    }
}

//Function cipher definition
void cipher(string ptext)
{
    int len = strlen(ptext);
    char ciphertext[len];
    for (int j = 0 ; j < strlen(ptext) ; j++)
    {
        if (isalpha(ptext[j]))
        {
            //call caesar formula function
            ciphertext[j] = formula(ptext[j]);
        }
        else
        {
            ciphertext[j] = ptext[j];
        }
    }
    printf("ciphertext: %s\n", ciphertext);
}

//Function caesar formula definition
char formula(char pi)
{
    int pindex = 0, cindex = 0;
    char ci;
    pindex = (int)pi;
    if (isupper(pi))
    {
        cindex = ((pindex - 65 + key) % 26);
        cindex = cindex + 65;
    }
    else
    {
        cindex = ((pindex - 97 + key) % 26);
        cindex = cindex + 97;
    }
    ci = (char)cindex;
    return ci;
}