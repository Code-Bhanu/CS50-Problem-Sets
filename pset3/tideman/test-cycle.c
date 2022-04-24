#include<cs50.h>
#include<stdio.h>
#include<string.h>

void lock_pairs(void);
bool cycle(int q);

#define MAX 9


typedef struct
{
    int w;
    int l;
}
loops;

typedef struct
{
    int winner;
    int loser;
}
pair;

pair pairs[MAX * (MAX - 1) / 2];


loops loop[MAX * (MAX - 1) / 2];

bool locked[MAX][MAX];

int pair_count = 3;

void print_winner(void);


int main(void)
{

    //bhanu
    pairs[0].winner = 0;
    pairs[0].loser = 1;
    pairs[1].winner = 2;
    pairs[1].loser = 0;
    pairs[2].winner = 1;
    pairs[2].loser = 2;
    //bhanu

    lock_pairs();

    for(int a =0; a< pair_count ; a++)
    {
        printf("loop[%d].w : %d loop[%d].l : %d\n", a,loop[a].w,a, loop[a].l );
    }

     for(int i =0; i< pair_count ; i++)
    {
        for(int j=0 ; j< pair_count ; j++)
        {
        printf("%d ", locked[i][j]);
        }
        printf("\n");
    }


print_winner();

    return 0;
}

void lock_pairs(void)
{
    // TODO

    for (int f = 0 ; f < pair_count ; f++)
    {

         if (!cycle(f))
        {
        locked[pairs[f].winner][pairs[f].loser] = true;
        }
    }


    return;
}



bool cycle(int q)
{

   int win = 0 , los = 0;

      win = pairs[q].winner;
    los = pairs[q].loser;

    loop[win].w = 1;
    loop[los].l = 1;

    int cyc = 0;
    for(int p = 0; p < pair_count ; p++)
    {
        if (( loop[p].w == 1 ) && (loop[p].l == 1))
        {
            cyc ++ ;
        }
    }


    if ( cyc == pair_count)
    {
       printf("\ncycle full\n");
        return true;

    }
    else
    {

        return false;
    }

}


void print_winner(void)
{
    // TODO
    int win = 0 , flse = 0;


    for(int g = 0 ; g < pair_count ; g++)
    {
        flse = 0;
       for (int h=0 ; h< pair_count ; h++)
        {
            if (locked[h][g] == false)
            {
                flse++;
            }

        }

        if(flse == pair_count)
        {
            win = g;
            break;
        }



    }



   printf("%d\n", win);

    return;
}