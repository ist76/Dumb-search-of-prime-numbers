/*Tutorial to find all prime numbers in the range from 0 to user specified*/
# include <stdio.h>
# include <stdlib.h>

# define COLUMN 25 /*displays the specified number of numbers in a row*/

int prime(int p, const int primes_ex[]); /*prime number test function prototype*/

int main(void)
{
    int n = 0;
    int q = 0;
    int correct = 0; /*upper limit, found counter, correctness flag*/
    int* primes = malloc(COLUMN * sizeof(int)); /*array with found primes*/
    if (primes == NULL) return 0;

    puts("Enter an upper limit for finding prime numbers:");
    correct = scanf_s("%i", &n); /*checking the correctness of the upper bound entered by the user*/
    if ((correct != 1) || (n < 3))
    {
        puts("Input error!");
        return(0);
    }

    printf_s("\n%6i \t", 2); /*the number 2 is always displayed*/
    primes[q++] = 2;

    for (int i = 3; i <= n; i += 2) /*We don’t check even candidate numbers*/
    {
        if (prime(i, primes) != 0) /*display a candidate number if the check function does not return "0"*/
        {
            printf_s("%6i \t", i);
            primes[q] = i;
            q++;
            if (q % COLUMN == 0)
            {
                primes = realloc(primes, ((q + COLUMN) * sizeof(int))); /*allocate more space for the array*/
                if (primes == NULL) return 0;
                puts("");
            }
        }
    }
    free(primes);
    return 0;
}

/* Accepts a candidate number and matches the found primes, gives the number itself if it is prime or 0 */
int prime(int p, const int primes_ex[])
{
    int countr = 0;
    for (int j = 0; primes_ex[j]*primes_ex[j] < p;)
    {
        if (p % primes_ex[j++] == 0) return 0;
    }
    return p;
}
