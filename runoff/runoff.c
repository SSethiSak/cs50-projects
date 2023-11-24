#include <cs50.h>
#include <stdio.h>
#include <string.h>
// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    for (int i=0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name)== 0)
        {
            preferences[voter][rank] = i;// this record preference as interger representing the interger that represent a particular member of a candidate
            return true;
        }
    }

    // TODO
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)// j is for voter and k is for candidates rank for j
{
    for (int j=0; j < voter_count; j++)// go through every voter 1 by 1
{
    for (int k=0; k < candidate_count; k++)// go through every candidate 1 by 1
    {
        if (candidates[preferences[j][k]].eliminated == false)//this ask if the candidate the voter j voted as kth preference rank is eliminated or not
        {
            candidates[preferences[j][k]].votes++;// if candidate ranked k on the voter is eliminated then give 1 vote to the k + 1 preference instead
            break;
        }


}
        }// TODO
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
   for (int w=0; w < candidate_count; w++)
   {
    if (candidates[w].votes > voter_count / 2)
    {
        printf("%s\n", candidates[w].name);
        return true;

    }
   }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int min = voter_count;
    for (int note=0; note < candidate_count; note++)
    {
        if (candidates[note].eliminated == false)
        {
            if (candidates[note].votes < min)
            {
                min = candidates[note].votes;
            }
        }
    }
    // TODO
    return min;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    int notEli = 0;
    int equal = 0;
   for (int left=0; left < candidate_count; left++)
   {
    if (candidates[left].eliminated == false)
    {
       notEli++;               //keep track of candidate not eliminated yet
    }
   }


   for (int mini=0; mini < candidate_count; mini++)
   {
    if (candidates[mini].votes == min)
    {
        equal++;                //keep track of how many candidate have vote count equal to minimum vote count
    }
    }

    if (notEli == equal)
    {
        return true;
    }
    else return false;
    // TODO

}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for (int gone=0; gone < candidate_count; gone++)
    {
        if (candidates[gone].votes == min)
        {
            candidates[gone].eliminated = true;
        }
    }
    // TODO
    return;
}