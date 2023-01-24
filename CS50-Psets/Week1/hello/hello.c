#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // asks what your name is and stores it in a variable called name
    string name = get_string("what is your name?\n");
    // prints hello following with name
    printf("hello, %s\n", name);

}