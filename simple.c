/*Tutorial to find all prime numbers in the range from 0 to user specified*/
# include <stdio.h>
# define COLUMN 25 /*displays the specified number of numbers in a row*/

int prime(int p);

int main(void)
{
    int n, q = 1, correct;   
    puts("Enter an upper limit for finding prime numbers:");
    correct = scanf_s("%i", &n); /*checking the correctness of the upper bound entered by the user*/
    if ((correct != 1) || (n < 3))
    {
        puts("Input error!");
        return(0);
    }

    printf_s("\n%6i \t", 3); /*the number 3 is always displayed*/
    for (int i = 5; i <= n; i += 2) /*We don’t check even candidate numbers*/
    {
        if (prime(i) != 0) /*display a candidate number if the check function does not return "0"*/
        {
            printf_s("%6i \t", i);
            q++;
            if (q == COLUMN)
            {
                puts("");
                q = 0;
            }
        }     
    }
    return 0;    
}

int prime(int p) /*The most primitive check is whether the resulting number is prime. Returns either 0 or the number itself*/
{
    for (int j = 3; j < (p / 3 + 1); j += 2) /*Minimal optimization: substitute only odd divisors and up to 1/3 of the upper search limit*/
    {
        if (p % j == 0) return 0;           
    }
    return p;
}
