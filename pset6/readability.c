#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int main(void)
{
    //Declaration of variables
    float L, S;
    int index = 0;
    int cnt_letter = 0, cnt_sent = 0, cnt_word = 0;

    //Text input from the user
    string s = get_string("Text: ");
    int length = strlen(s);

    //Count number of letters, words, sentences in the text
    for (int i = 0; i < length ; i++)
    {
        if (isalpha(s[i]))
        {
            cnt_letter += 1;
        }
        else if ((s[i] == '.') || (s[i] == '?') || (s[i] == '!'))
        {
            cnt_sent += 1 ;
        }
        else if (s[i] == ' ')
        {
            cnt_word += 1 ;
        }

    }
    if (cnt_word != 0)
    {
        cnt_word++;
    }

    //Average letters and sentences per 100 words
    L = ((float)cnt_letter / cnt_word) * 100;
    S = ((float)cnt_sent / cnt_word) * 100;

    // Coleman-Liau formula
    index = round((0.0588 * L) - (0.296 * S) - 15.8);


    // print grades
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}