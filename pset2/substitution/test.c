#include<stdio.h>
#include<string.h>
#include<ctype.h>

int repeat_check(string str);
int main(void)
{
    char s[] = "YFDTSMPBVIEERGHWONUAKLQXCZ";
    printf("%i\n",repeat_check(s));


}


int repeat_check(string str)
{
   for(int i=0; i<26 ; i++)
    {
        for (int j=0; j<26 ; j++)
        {
            if(toupper(str[i]) == toupper(str[j]))
            {
            //    printf("0");
                return 0;
            }
        }
    }

   // printf("1");
    return 1;
}