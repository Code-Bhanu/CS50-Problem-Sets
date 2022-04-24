#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;



//bhanu

bool cycle(int cycle_start, int loser);
//bhanu

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];


int pair_count;
int candidate_count;



// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);



int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];

    }


    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }



    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }





    add_pairs();

    sort_pairs();

    lock_pairs();

    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for (int i = 0 ; i < candidate_count ; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    int x, y;

    for (int j = 0 ; j < candidate_count ; j++)
    {
        x = ranks[j];
        for (int k = j + 1 ; k < candidate_count ; k++)
        {
            y = ranks[k];
            preferences[x][y] += 1 ;

        }
    }



    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    int t = 0 ;
    for (int r = 0 ; r < candidate_count ; r++)
    {
        for (int s = r + 1 ; s < candidate_count ; s++)
        {
            if (preferences[r][s] > preferences[s][r])
            {
                pairs[t].winner = r ;
                pairs[t].loser = s ;
                t++;
            }
            else if (preferences[s][r] > preferences[r][s])
            {
                pairs[t].winner = s ;
                pairs[t].loser = r ;
                t++;
            }

        }
    }

    pair_count = t;

    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int strength[pair_count], t = 0, swap = -1, temp = 0, temp1 = 0, temp2 = 0;
    // TODO

    for (int r = 0 ; r < candidate_count ; r++)
    {
        for (int s = r + 1 ; s < candidate_count ; s++)
        {
            if (preferences[r][s] > preferences[s][r])
            {
                strength[t] = preferences[r][s] - preferences[s][r];
                t++;
            }
            else if (preferences[s][r] > preferences[r][s])
            {
                strength[t] = preferences[s][r] - preferences[r][s] ;
                t++;

            }

        }
    }

    {

        while (swap != 0)
        {
            swap = 0;
            for (int b = 0 ; b < pair_count - 1 ; b++)
            {
                if (strength[b] < strength[b + 1])
                {


                    temp = strength[b];
                    strength[b] = strength[b + 1] ;
                    strength[b + 1] = temp;



                    temp1 = pairs[b].winner ;
                    pairs[b].winner = pairs[b + 1].winner;
                    pairs[b + 1].winner = temp1;

                    temp2 = pairs[b].loser ;
                    pairs[b].loser = pairs[b + 1].loser;
                    pairs[b + 1].loser = temp2;

                    swap++;

                }
            }
        }




    }

    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO

    for (int i = 0; i < pair_count; i++)
    {
        if (!cycle(pairs[i].winner, pairs[i].loser))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }

    return;
}



// checks if a cycle is made
bool cycle(int strt, int los)
{
    if (los == strt)
    {
        return true;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[los][i])
        {
            if (cycle(strt, i))
            {
                return true;
            }
        }
    }
    return false;
}




// Print the winner of the election
void print_winner(void)
{
    // TODO
    int win = 0, flse = 0;


    for (int g = 0 ; g < pair_count ; g++)
    {
        flse = 0;
        for (int h = 0 ; h < pair_count ; h++)
        {
            if (locked[h][g] == false)
            {
                flse++;
            }

        }

        if (flse == pair_count)
        {
            win = g;
            break;
        }



    }



    printf("%s\n", candidates[win]);

    return;
}

