//This program calculates how many coins need to be returned when user inputs an amount of change. It calculates the total amount of coins not the individual amount of counts.

#include <cs50.h>
#include <stdio.h>
#include <math.h>


int main(void)
{
    //i = input
    float i;
    do
    {
        i = get_float("Please submit the amount of change: \n");
    }
    while (i < 0);

    // doe de input x 100 w= wissgeld
    int w = round(i * 100);

    // declare variable. c = coins, q = quarters, d = dimes, n = nickles, p = pennies.
    int c = 0;
    int q = 25;
    int d = 10;
    int n = 5;
    int p = 1;

    //loop 1 int q = quarter int rq= result quarter
    for (q = 25 ; q <= w; c++)
    {
        w = w - 25;
    }


    //loop 2 int d = dime int rd = result dime
    for (d = 10 ; d <= w; c++)
    {
        w = w - 10;
    }


    //loop 3 int n = nickle int rn = result nickle
    for (n = 5; n <=  w; c++)
    {
        w = w - 5;
    }


    //loop 4 int p = penny int rp = result penny
    for (p = 1; p <= w; c++)
    {
        w = w - 1;
    }

    //print the amount of coins. output should be integer not float.  printf("%i\n" , q + d + n + p);
    do
    {
        printf("%i\n", c);
    }
    while (w < 0);
}
