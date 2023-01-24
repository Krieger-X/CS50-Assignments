#include <cs50.h>
#include <stdio.h>

//function prototypes
int checksum1(long int n);
int checksum2(long int n);
int calculate_digits(long int n);
int starting_num(long int n, int digits);
int main(void)
{
    long int n = get_long("Number: ");

    //calculates chechsum
    int checksum3 = checksum1(n) + checksum2(n);
    checksum3 %= 10;
    //printf("checksum: %i\n", checksum3);

    //card number length
    int digits = calculate_digits(n);

    //checks starting number
    int sn = starting_num(n, digits);

    //checks checksum, digits, starting number with below values, if all of them matches prints AMEX
    if ((checksum3 == 0 && (digits == 15 && sn == 34)) || sn == 37)
    {
        printf("AMEX\n");
    }
    //checks checksum, digits, starting number with below values, if all of them matches prints MASTERCARD
    else if ((checksum3 == 0 && (digits == 16 && sn == 51)) || sn == 52 || sn == 53 || sn == 54 || sn == 55)
    {
        printf("MASTERCARD\n");
    }
    //checks checksum, digits, starting number with below values, if all of them matches prints VISA
    else if ((checksum3 == 0 && (digits == 13 || digits == 16)) && sn == 4)
    {
        printf("VISA\n");
    }
    //if doesn't match prints INVALID
    else
    {
        printf("INVALID\n");
    }
}

//picks every other digit starting from second to last digit, multiplies it by 2 and returns the sum.
int checksum1(long int n)
{
    int sum = 0;
    do
    {
        long int temp = 0;
        temp = n / 100;
        n %= 100;
        n /= 10;
        n *= 2;
        if (n >= 10)
        {
            int temp2 = 0;
            temp2 = n / 10;
            n %= 10;
            sum += n;
            sum += temp2;
        }
        else
        {
            sum += n;
        }
        n = temp;
    }
    while (n != 0);

    return sum;
}

//picks every other digit starting from the last digit and returns the sum.
int checksum2(long int n)
{
    int sum2 = 0;
    long int temp = 0;
    temp = n / 10;
    n %= 10;
    sum2 += n;
    n = temp;
    do
    {
        temp = n / 100;
        n %= 100;
        n /= 10;
        sum2 += n;
        n = temp;
    }
    while (n != 0);

    return sum2;
}

//calculates and returns card number length
int calculate_digits(long int n)
{
    int count = 0;
    do
    {
        n /= 10;
        count++;
    }
    while (n != 0);

    return count;
}

//checks and returns starting number
int starting_num(long int n, int digits)
{
    // if card digits is 15, takes out last 13 digits and returns the starting two digits
    if (digits == 15)
    {
        n /= 10000000000000;
    }
    else if (digits == 13)
    {
        int temp = 0;
        n /= 1000000000000;
    }
    //if digits is 16, takes out last 13 digits and returns the starting two digits, if the first starting digit is 4, returns one digit.
    else if (digits == 16)
    {
        int temp = 0;
        n /= 100000000000000;
        temp = n / 10;
        if (temp == 4)
        {
            n /= 10;
        }
    }
    else
    {
        return 0;
    }

    return n;
}