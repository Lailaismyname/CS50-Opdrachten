// This program calculates the time span of a lama population's growth. The user can input a starting en end size of the population.

#include<cs50.h>
#include<stdio.h>

int main(void)
{
    //ask input. int cp = current population
    int cp;
    int gp;
    do
    {
        cp = get_int("How many lovely lama's do we have currently?\n");
    }
    while (cp < 0 || cp < 9);
    //ask input int gp = growth population
    do
    {
        gp = get_int("How many lovely lama's will there be eventually?\n");
    }
    while (gp < cp);

    //if cp and gp equal print.
    int y = 0;
    if (gp == cp)
    {
        printf("Years: %i\n", y);
    }
    //else calculate amount of years
    else
    {
        do
        {
            cp = cp + (cp / 3) - (cp / 4);
            y++;
        }
        while (gp > cp);

        printf("Years: %i\n", y);
    }

}
