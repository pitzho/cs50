#include <cs50.h>
#include <stdio.h>

int checksum(long number);
void check_vendor(long number);

int main(void)
{
    int check_number;
    long number;

    number = get_long("Number: ");
    check_number = checksum(number);
    if (check_number == 1)
    {
        check_vendor(number);
    }
    else
    {
        printf("INVALID\n");
    }
}

void check_vendor(long number)
{
    string vendor;

    if (number >= 4000000000000 && number < 5000000000000)
    {
        vendor = "VISA\n";
    }
    else if (number >= 340000000000000 && number < 350000000000000)
    {
        vendor = "AMEX\n";
    }
    else if (number >= 370000000000000 && number < 380000000000000)
    {
        vendor = "AMEX\n";
    }
    else if (number >= 4000000000000000 && number < 5000000000000000)
    {
        vendor = "VISA\n";
    }
    else if (number >= 5100000000000000 && number < 5600000000000000)
    {
        vendor = "MASTERCARD\n";
    }
    else
    {
        vendor = "INVALID\n";
    }

    printf("%s", vendor);
}

int checksum(long number)
{
    int sum_even = 0;
    int tracker = 1;

    for (long i = number; i > 0; i /= 10)
    {
        if (tracker % 2 == 0)
        {
            int digit = (i % 10) * 2;
            int j = digit / 10;
            int k = digit % 10;
            sum_even = sum_even + j + k;
            tracker++;
        }
        else
        {
            tracker++;
        }
    }

    int sum_odd = 0;
    tracker = 1;

    for (long i = number; i > 0; i /= 10)
    {
        if (tracker % 2 != 0)
        {
            sum_odd = sum_odd + i % 10;
            tracker++;
        }
        else
        {
            tracker++;
        }
    }

    int sum = sum_odd + sum_even;

    if (sum % 10 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}