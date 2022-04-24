 #include<stdio.h>
 int main()
 {
    int pair_count = 3, swap = -1, temp = 0;
  int strength1[] ={3,1,2};
 for(int s = 0 ; s < pair_count ; s++)
    {
        printf("%i ",strength1[s] );

    }
    printf("\n");

    do
    {
        swap = 0;
        for(int b = 0 ; b < pair_count ; b++)
        {
            if (strength1[b] < strength1[b+1])
            {
                temp = strength1[b];
                strength1[b] = strength1[b+1] ;
                strength1[b+1] = temp;
                swap++;

            }
        }
    }
    while(swap !=0 );

 for( int s = 0 ; s < pair_count ; s++)
    {
        printf("%i ",strength1[s] );

    }


}