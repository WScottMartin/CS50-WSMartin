#include <cs50.h>
#include <stdio.h>

int calculate_quarters(int remaining_cents);
int calculate_dimes(int remaining_cents);
int calculate_nickels(int remaining_cents);
int calculate_pennies(int remaining_cents);

int main(void)
{

    int cents; // Declare the variable 'cents'
    do
    {
        cents = get_int("Change owed: "); // Request input amount of change owed
    }
    while (cents <= 0);

    int quarters = calculate_quarters(cents); // calculates how many quarters fit in 'cents'
    cents = cents - (quarters * 25);

    int dimes = calculate_dimes(cents);
    cents = cents - (dimes * 10);

    int nickels = calculate_nickels(cents);
    cents = cents - (nickels * 5);

    int pennies = calculate_pennies(cents);

    int total = pennies + nickels + dimes + quarters;
    printf("%i\n", total);
}

// ============calculate quarters function============
int calculate_quarters(int remaining_cents)
{

    int quarters;
    for (quarters = 0; remaining_cents >= 25; quarters++)
    {
        remaining_cents = remaining_cents - 25;
    }
    return quarters;
}

// ============calculate dimes function============
int calculate_dimes(int remaining_cents)
{

    int dimes;
    for (dimes = 0; remaining_cents >= 10; dimes++)
    {
        remaining_cents = remaining_cents - 10;
    }
    return dimes;
}

// ============calculate nickels function============
int calculate_nickels(int remaining_cents)
{

    int nickels;
    for (nickels = 0; remaining_cents >= 5; nickels++)
    {
        remaining_cents = remaining_cents - 5;
    }
    return nickels;
}

// ============calculate pennies function============
int calculate_pennies(int remaining_cents)
{

    int pennies;
    for (pennies = 0; remaining_cents >= 1; pennies++)
    {
        remaining_cents = remaining_cents - 1;
    }
    return pennies;
}
