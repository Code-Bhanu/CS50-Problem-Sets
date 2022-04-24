#include<stdio.h>
int main()
{
    //int length = 7;
    int array[7] = {9,8,5,7,0,4,1};
    //int temp = 0, swap ;
    int big_index = 0 ;


       for (int j=1 ; j < 7 ; j++)
       {
        if (array[0] > array[j])
        {
            big_index = 0;
        }
       // else
    //    {
      //      big_index = j;
    //    }
       }


       printf("%i\n",big_index);


    //printf("The big number is : %i at position %i", array[pos], pos);
    return 0;
}

