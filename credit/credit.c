#include <cs50.h>
#include <stdio.h>

int count_digits(long number);
long get_input(void);
int luhn_check(long number, int digits);
int get_first_digits(long number);
void print_result(int isValid, int firstDigits, int digits);

int main(void)
{
    long number = get_input();

    int digits = count_digits(number);

    int isValid = luhn_check(number, digits);

    int firstDigits = get_first_digits(number);

    print_result(isValid, firstDigits, digits);
}

long get_input(void)
{
    long number;

    do
    {
        number = get_long("Number: ");
    }
    while (number <= 1000000000);

    return number;
}

int count_digits(long number)
{
    int digits = 0;
    long n = number;

    while (n >= 1)
    {
        digits++;
        n /= 10;
    }

    return digits;
}

int luhn_check(long number, int digits)
{
    long n = number;
    int sum = 0;

    for (int i = 1; i <= digits; i++)
    {
        if (i % 2 == 0)
        {
            int x = n % 10 * 2;

            if (x > 9)
            {
                while (x > 0)
                {
                    sum += x % 10;
                    x /= 10;
                }
            }
            else
            {
                sum += x;
            }
        }
        else
        {
            sum += n % 10;
        }

        n /= 10;
    }

    return sum % 10 == 0;
}

int get_first_digits(long number)
{
    long n = number;

    while (n >= 100)
    {
        n /= 10;
    }

    return (int) n;
}

void print_result(int isValid, int firstDigits, int digits)
{
    if (isValid && digits == 15 && (firstDigits == 34 || firstDigits == 37))
    {
        printf("AMEX\n");
    }
    else if (isValid && digits == 16 && firstDigits >= 51 && firstDigits <= 55)
    {
        printf("MASTERCARD\n");
    }
    else if (isValid && (digits == 13 || digits == 16) && firstDigits >= 40 && firstDigits < 50)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}