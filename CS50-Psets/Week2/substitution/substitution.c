#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    // if there are not two arguments given when run the code, it returns the correct usage and exits the code returning 1
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        // if the given argument is not equal to 26 asks the user to enter 26 characters and exits the program returning 1
        if (n != 26)
        {
            printf("Key must contain 26 characters\n");
            return 1;
        }
        // if argument contains non-alphabetical character, asks the user to enter alphabetical character
        if (!isalpha(argv[1][i]))
        {
            printf("Key must only contain alphabetic characters\n");
            return 1;
        }
        // compares every character to each character if there is a same character asks the to enter non-repeated characters
        for (int j = i + 1; j < n; j++)
        {
            if (tolower(argv[1][i]) == tolower(argv[1][j]))
            {
                printf("Key must not contain repeated characters\n");
                return 1;
            }
        }
    }

    // prompts the user for plain text
    string plain_text = get_string("plaintext: ");

    // converts the argument to standardize input
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        argv[1][i] = tolower(argv[1][i]);
    }

    printf("ciphertext: ");

    for (int i = 0, n = strlen(plain_text); i < n; i++)
    {
        int key = plain_text[i];
        // checks user input for plain text letter by letter, if contains lowercase letters converts it to the cipher letter
        if (islower(plain_text[i]))
        {
            key -= 97;
            printf("%c", argv[1][key]);
        }
        // checks if contains uppercase letter and converts it to the cipher letter
        else if (isupper(plain_text[i]))
        {
            key -= 65;
            printf("%c", toupper(argv[1][key]));
        }
        // if non-alphabetical character just prints the character
        else
        {
            printf("%c", plain_text[i]);
        }
    }
    // prints a new line after ciphertext
    printf("\n");
}