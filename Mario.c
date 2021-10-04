//This is a program that prints an ascii art pyramide, user can request height of pyramid with a max height of 8.
#include <cs50.h>
#include <stdio.h>


int main(void)
{
// Vraag hoogte gebruiker.
    int getal;
    do
    {
        getal = get_int("Desired height of pyramide: ");
    }
    while (getal < 1 || getal > 8);

    //loop 1 , n = nieuwe regel!
    int n;
    for (n = 0 ; n < getal; n++)
    {
        //loop 2
        int punt;
        for (punt = 1 + n ; punt < getal ; punt++)
        {
            printf(" ");
        }

        //loop3
        int hash;
        for (hash = 0; hash <= n ; hash++)
        {
            printf("#");
        }
        //print een space. (is het kleiner dan 1? ja print space)
        int space;
        for (space = 0; space < 2; space++)
        {
            printf(" ");
        }
        //print rechtse pyramide
        int rechts;
        for (rechts = 0; rechts <= n; rechts++)
        {
            printf("#");
        }

        printf("\n");

    }

}

