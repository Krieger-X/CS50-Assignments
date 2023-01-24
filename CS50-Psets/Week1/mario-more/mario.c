#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    //getting user input for height
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    //for loop for printing column
    for (int i = 0; i < n; i++)
    {

        //prints right aligned pyramid
        for (int j = 0; j < n; j++)
        {
            if (i + j < n - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }

        //prints blank space in the middle
        printf("  ");

        //prints left aligned pyramid
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}