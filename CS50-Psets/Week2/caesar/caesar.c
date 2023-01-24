#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

//function prototypes
char rotate(char c, int k);
int main(int argc, string argv[])
{
    //checks if there are two arguments, if not prints the correct usage and exits the program returning 1.
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //checks if argument is digit letter by letter, if not does the same as above if statement
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    //converts argument from string to integer
    int k = atoi(argv[1]);

    //gets string for plaintext
    string p = get_string("plaintext: ");
    printf("ciphertext: ");

    //prints output for ciphertext letter by letter
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        p[i] = rotate(p[i], k);
    }
    printf("\n");
}

//checks if the string includes uppercase letters or lowercase letters and converts it to ciphertext
char rotate(char p, int k)
{
    if (isupper(p))
    {
        printf("%c", (p - 65 + k) % 26 + 65);
    }
    else if (islower(p))
    {
        printf("%c", (p - 97 + k) % 26 + 97);
    }
    else
    {
        printf("%c", p);
    }
    return p;
}