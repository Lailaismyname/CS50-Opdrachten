//This program checks wether a creditcard number is valid and to which creditcardcompany it belongs.
#include <cs50.h>
#include <stdio.h>

int fsum;

int main(void)
//step 1 ask cc nr.
{
    //cc = creditcard number. ccc= copycreditcard nr. (voor reset cc)
    long long cc = get_long_long("Please submit your credit card number: \n");
    long long ccc = cc;
    //stap 2. int dc = Digit Counter. stap 2 reken het aantal getallen van cc uit.
    int dc = 0;
    while (cc != 0)
    {
        cc = cc / 10;
        dc += 1;
    }

    cc = ccc;
    // stap 3 luhn's algorithm. int l = Laatste; int el = Éen a Laatste;
    int l;
    int el;
    int sum1 = 0;
    int sum2 = 0;
    int dcdc = 0;
    do
    {
        l = ccc % 10;
        ccc = ccc / 10;
        el = ccc % 10;
        el = el * 2;
        ccc = ccc / 10;
        if (el > 9)
        {
            el = (el % 10) + (el / 10);
        }
        sum1 = sum1 + l;
        sum2 = sum2 + el;
        fsum = sum1 + sum2;
        dcdc++;
    }
    while (dcdc <= dc);
    ccc = cc;
    fsum = fsum % 10;

    //check if card is amex
    if (dc == 15 && fsum == 0)
    {
        int amex;
        for (amex = 0; amex <= 12; amex++)
        {
            cc = cc / 10;
            if (cc == 34 || cc == 37)
            {
                printf("AMEX\n");
            }
        }
    }
    // Check if card is mastercard or visa
    else if (dc == 16 && fsum == 0)
    {
        int mc;
        for (mc = 0; mc <= 13; mc++)
        {
            cc = cc / 10;
            if (cc == 51 || cc == 52 || cc == 53 || cc == 54 || cc == 55)
            {
                printf("MASTERCARD\n");
            }
            //check if visa
            if (cc / 10 == 4)
            {
                printf("VISA\n");
            }

        }
    }
    //check if visa
    else  if (dc == 13 && fsum == 0)
    {
        int v;
        for (v = 0; v <= 11; v++)
        {
            cc = cc / 10;
            if (cc == 4)
            {
                printf("VISA\n");
            }
        }
    }
    else
    {
        printf("INVALID\n");
    }

}

