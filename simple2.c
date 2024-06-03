/*Tutorial to find all prime numbers in the range from 0 to user specified*/
# include <stdio.h>
# include <stdlib.h>

# define COLUMN 25 /*displays the specified number of numbers in a row*/

int prime(int p, int qex, int primes_ex[]); /*prime number test function prototype*/

int main(void)
{
    int n, q, correct; /*upper limit, found counter, correctness flag*/
    int *primes = malloc(COLUMN * sizeof(int)); /*array with found primes*/

    puts("Enter an upper limit for finding prime numbers:");
    correct = scanf_s("%i", &n); /*checking the correctness of the upper bound entered by the user*/
    if ((correct != 1) || (n < 3))
    {
        puts("Input error!");
        return(0);
    }

    printf_s("\n%6i \t", 3); /*the number 3 is always displayed*/
    primes[q++] = 3;

    for (int i = 5; i <= n; i += 2) /*We don’t check even candidate numbers*/
    {
        if (prime(i, q, primes) != 0) /*display a candidate number if the check function does not return "0"*/
        {
            printf_s("%6i \t", i);
            primes[q] = i;
            q++;
            if (q % COLUMN == 0)
            {
                primes = realloc(primes, ((q + COLUMN) * sizeof(int))); /*allocate more space for the array*/
                puts("");               
            }
        }     
    }
    free(primes);
    return 0;    
}

/*A little optimization: only prime divisors
the function is passed a candidate, the number of prime numbers found and an array with them*/
int prime(int p, int qex, int primes_ex[])
{
    for (int j = 0; j < qex; j++) /*FIXME! the divisor must be taken <= the root of p */
    {
        if (p % primes_ex[j] == 0) return 0;           
    }
    return p;
}
