#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                   'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

bool alphabetical(string key);
bool duplicate(string key);
int compare(char plaintext);
bool alphabetical_char(char plaintext);

int main(int argc, char *argv[])
{
    // check if user entered a prompt
    if (argc < 2)
    {
        printf("Please provide a command-line argument.\n");
        return 1;
    }

    // check if user entered a prompt
    if (argc > 2)
    {
        printf("Please provide one command-line argument (key).\n");
        return 1;
    }

    // check if key is 26 characters
    else if (strlen(argv[1]) != 26)
    {
        printf("Please provide a key that is 26 characters.\n");
        return 1;
    }

    string key = argv[1];

    // in a for loop, check if each character is in the alphabet
    if (alphabetical(key) == false)
    {
        printf("Please provide a key that only contains alphabetical characters.\n");
        return 1;
    }

    // in a for loop, check if there are any repeats
    if (duplicate(key) == true)
    {
        printf("Please provide a key with no duplicate characters.\n");
        return 1;
    }

    // ask user to enter plaintext
    string plaintext = get_string("plaintext: ");

    // ciphertext structure
    string ciphertext = plaintext;

    // for each plaintext char, check if alphabetical.
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        if (alphabetical_char(plaintext[i]) == true)
        {
            if (islower(plaintext[i]))
            {
                ciphertext[i] = tolower(key[compare(plaintext[i])]);
            }
            else
            {
                ciphertext[i] = toupper(key[compare(plaintext[i])]);
            }
        }

        else
        {
            continue;
        }
    }

    // print final ciphertext
    printf("ciphertext: %s\n", ciphertext);
}

bool alphabetical(string key)
{
    bool br = false;
    bool found = false;
    for (int i = 0; i < 26; i++)
    {
        br = false;
        found = false;

        for (int j = 0; j < 26; j++)
        {
            if (tolower(key[i]) == alphabet[j])
            {
                found = true;
                break;
            }
        }

        if (found == false)
        {
            br = true;
            return found;
            break;
        }
    }
    return found;
}

bool alphabetical_char(char plaintext)
{

    bool found = false;

    for (int j = 0; j < 26; j++)
    {
        if (tolower(plaintext) == alphabet[j])
        {
            found = true;
            break;
        }
    }
    return found;
}

bool duplicate(string key)
{
    bool duplicate = false;

    for (int i = 0; i < 26; i++)
    {
        if (duplicate == true)
        {
            break;
        }

        for (int j = (i + 1); j < 26; j++)
        {
            if (tolower(key[i]) == tolower(key[j]))
            {
                duplicate = true;
                break;
            }
        }
    }
    return duplicate;
}

int compare(char plaintext)
{
    int i = 0;
    for (i = 0; i < 26; i++)
    {
        if (tolower(plaintext) == tolower(alphabet[i]))
        {
            break;
        }
    }
    return i;
}
