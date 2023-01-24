#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        //prompts the user to enter the height
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    //for loop for column
    for (int i = 0; i < height; i++)
    {
        //for loop for row
        for (int j = 0; j < height; j++)
        {
            if (i + j < height - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}