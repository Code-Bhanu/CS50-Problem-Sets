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
string s;

int main(int argc, string argv[])
{

    //local variable declaration
    int alpha_check = 0, key_length = 0, repeat_check = 0;
    string plaintext;
    s = argv[1] ;

    //check whether number of arguments are 2
    if (argc == 2)
    {
        key_length = strlen(s);
        if (key_length == 26)
        {
            //check whether argument is alphabet
            for (int i = 0 ; i < key_length ; i++)
            {
                if (!(isalpha(s[i])))
                {
                    alpha_check = 1 ;
                    break;
                }
            }

            //argument is alphabet
            if (alpha_check != 1)
            {
                for (int m = 0; m < 26 ; m++)
                {
                    repeat_check = 0;
                    for (int n = 0; n < 26 ; n++)
                    {
                        if (toupper(s[m]) == toupper(s[n]))
                        {
                            //check for character repetition
                            repeat_check ++ ;
                        }
                    }
                    if (repeat_check > 1)
                    {
                        printf("Key must not contain repeated characters.\n");
                        return 1;
                    }
                }

                //prompt user for input
                plaintext = get_string("plaintext: ");

                //call cipher function
                cipher(plaintext);

            }
            else
            {
                printf("Key must contain only alphabhetic characters.\n");
                return 1;
            }
        }
        else
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}



//Function  cipher definition
void cipher(string ptext)
{
    int len = strlen(ptext);
    char ciphertext[len];
    for (int j = 0 ; j < len ; j++)
    {
        if (isalpha(ptext[j]))
        {
            ciphertext[j] = formula(ptext[j]);
        }
        else
        {
            ciphertext[j] = ptext[j];
        }
    }
    printf("ciphertext: %s\n", ciphertext);
}


//Function substitution formula definition
char formula(char pi)
{
    int pindex = 0, cindex = 0;
    pindex = (int)pi;
    if (isupper(pi))
    {
        cindex = pindex - 65;
        return (toupper(s[cindex]));
    }
    else
    {
        cindex = pindex - 97;
        return (tolower(s[cindex]));
    }
}