#include <cs50.h>
#include <stdio.h>
#include <string.h>

//** NOTE: COME BACK TO THIS PROBLEM LATER. IT NEEDS MORE TIME. PICK UP ON THE SORT PAIRS FUNCTION

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
    // checks candidacy, increments ranks[j] (j is voter's rank for each candidate)
    for (int i = 0; i < candidate_count; i++)
    {
        // strcmp returns 0 when strings are equal
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[i] = rank;
            // printf("%d\n", ranks[i]); // print for debugging
            return true;
        }
    }
    return false;
}

// Update preferences[i][j] given one voter's ranks
void record_preferences(int ranks[])
{
    // icrements number of voters who prefer i over j
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (ranks[i] < ranks[j])
            {
                preferences[i][j] ++;
            }
            printf("%i\n", preferences[i][j]); // print for debugging
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{

    // compare preferences[i][j], increment total in pairs[]. Each element in pairs is composed of int winner and int loser.
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > 0)
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
            }
            else if (preferences[j][i] > 0)
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
            }
            printf("winner = %d loser = %d\n", pairs[pair_count].winner, pairs[pair_count].loser);  // print for debugging
            pair_count ++;
        }
    }
    // printf("%i\n", pair_count);  // print for debugging
    return;
}


// NOTE: STILL NEED TO SOLVE THIS
// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    //for each winner in pairs, get value from preference matrix.

    int temp;
    for (int i = 0; i < pair_count - 1; i++)
    {
        for (int j = 0; j < pair_count - i - 1; j++)
        {
            // Bubble sort: compare two elements, swap positions if i is larger than i + 1
            if (preferences[pairs[j].winner] > preferences[pairs[j + 1].winner])
            {
                temp = preferences[pairs[j].winner];
                preferences[pairs[j].winner] = preferences[pairs[j + 1].winner];
                preferences[pairs[j + 1].winner] = temp;
            }
        }

    }
    printf("%i\n", preferences);
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
}