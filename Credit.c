#include <cs50.h>
#include <stdio.h>
string cardcheck(long democardnumber);

int main(void)
{
    long cardnumber;

    do
    {
        cardnumber = get_long("Number: ");  // Gets card number
    }
    while (cardnumber <= 0);                // Ensures it is greater than 0

    printf("%s\n", cardcheck(cardnumber));  // Activates Cardcheck with the acquired number as the argument
}

string cardcheck(long democardnumber)
{
    long firstloopnumber = democardnumber / 10, secondloopnumber = democardnumber, democardnumber_last_two_digits = democardnumber, typecheck = 0,
                                            digitchecker = democardnumber;
    int digitsumtotal = 0, digitsumone = 0, digitsumtwo = 0, modulo = 0, multipliedmodulo = 0,
        mmdigitone = 0, mmdigittwo = 0;

    // First set of numbers
    while (firstloopnumber > 0) // Loops until all numbers have been processed - Starts on second digit of cardnumber (0 from 34001 e.g.)
    {
        modulo = firstloopnumber % 10;                          // Acquires next digit
        multipliedmodulo = modulo * 2;                          // Multiplies that value by 2
        mmdigitone = multipliedmodulo % 10;                     // Breaks off first digit of new product
        mmdigittwo = (multipliedmodulo / 10) % 10;              // Breaks of second digit of new product
        digitsumone = mmdigitone + mmdigittwo + digitsumone;    // Adds them together and updates 'digitsumone'
        firstloopnumber = firstloopnumber / 100;                // Removes irrelevant/completed digits
    }

    // Second set of numbers
    while (secondloopnumber > 0) // Loops until all numbers have been processed - Starts on first digit of cardnumber (1 from 34001 e.g.)
    {
        modulo = secondloopnumber % 10;             // Acquires next digit
        digitsumtwo = modulo + digitsumtwo;         // Adds them to 'digitsumone'
        secondloopnumber = secondloopnumber / 100;  // Removes irrelevant/completed digits
    }
    digitsumtotal = digitsumone + digitsumtwo;

    // Begins verifying validity
    if (digitsumtotal % 10 == 0)    // Checks if the last digit of the sum of calculations = 0
    {
        while (democardnumber_last_two_digits >= 100)   // Loops until there are only two digits remaining (taking 34 from 34000 e.g.)
        {
            democardnumber_last_two_digits /= 10;       // Repeatedly divides by 10 until two digits remain
        }

        typecheck = democardnumber_last_two_digits;     // Assigns new variable for ease of typing
        if (typecheck == 34 || typecheck == 37)         // Checks if the last two digits are congruent with AMEX practices
        {
            int aloops;
            for (aloops = 0; digitchecker != 0; aloops++) // Loops until digitchecker = 0
            {
                digitchecker /= 10;     // Repeatedly divides by 10 until no digits remain
            }
            if (aloops == 15)           // Checks if it took 15 loops to bring the number down to 0
            {
                return "AMEX";          // Returns AMEX to be printed if # of digits matches requirements
            }
            else
            {
                return "INVALID";       // Returns INVALID if not matching
            }
        }
        else if (typecheck >= 51 && typecheck <= 55) // Checks if the last two digits are congruent with M.CARD practices
        {
            int mloops;
            for (mloops = 0; digitchecker != 0; mloops++)
            {
                digitchecker /= 10;     // Repeatedly divides by 10 until no digits remain
            }
            if (mloops == 16)           // Checks if it took 16 loops to bring the number down to 0
            {
                return "MASTERCARD";    // Returns MASTERCARD to be printed if of digits matches requirements
            }
            else
            {
                return "INVALID";        // Returns INVALID if not matching
            }
        }
        else if (typecheck / 10 == 4)    // Checks if the last two digits are congruent with VISA practices
        {
            int vloops;
            for (vloops = 0; digitchecker != 0; vloops++)
            {
                digitchecker /= 10;             // Repeatedly divides by 10 until no digits remain
            }
            if (vloops == 16 || vloops == 13)   // Checks if it took 16 or 13 loops to bring the number down to 0
            {
                return "VISA";                  // Returns VISA to be printed if # of digits matches requirements
            }
            else
            {
                return "INVALID";               // Returns INVALID if not matching
            }
        }
        else
        {
            return "INVALID";   // Returns INVALID if none of the last digits match valid card options
        }
    }
    else
    {
        return "INVALID";       // Returns INVALID if the last digit of the sum of calculation is not 0
    }
}
