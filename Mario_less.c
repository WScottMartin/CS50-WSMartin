#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n; // Establishes variable n

    do
    {
        n = get_int("Height: ");    // Prompt user for Height value
    }
    while (n < 1);                  // Loop to account for sub-one numbers

    int brick = 1;                  // All pyramids start with one brick, this variable is later incremented upon
    for (int i = 0; i < n; i++)     // Establishes the loop to run an equal number of times to the value >
                                    // > 'n' (pyramid height)
    {
        int space = n - i - 1;              // Initializes 'space' to create a dynamic number of spaces based on the >
                                            // > final height and current row. This variable is later decremented upon.
        for (int j = 0; j < space; j++)     // Nested loop to print as many spaces as the variable 'space' denotes
        {
            printf(" ");                    // Prints a single space per loop
        }
        for (int k = 0; k < brick; k++)     // Nested loop to print as many '#'s as the variable "brick" denotes
        {
            printf("#");                    // Prints a single # per loop
        }
        printf("\n");       // Prints a new line
        brick += 1;         // Increments 'brick' to add another '#' to the following layer
        space -= 1;         // Decrements 'space' to remove one ' ' from the following layer to make room for new '#'
    }
}
