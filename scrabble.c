#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int numbers[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                  'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int compute_score(string word);

int main(void)
{
    string p1 = get_string("Player 1: ");
    string p2 = get_string("Player 2: ");

    int s1 = compute_score(p1);
    int s2 = compute_score(p2);

    if (s1 > s2)
    {
        printf("Player 1 wins!\n");
    }
    else if (s1 < s2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{

    for (int k = 0, len = strlen(word); k < len; k++)
    {
        word[k] = tolower(word[k]);
    }

    int total = 0;
    int j = 0;
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        bool found = false;
        for (j = 0; j < 26; j++)
        {
            if (word[i] == letters[j])
            {
                found = true;
                break;
            }
        }

        if (found == true)
        {
            total += numbers[j];
        }
    }

    return total;
}
