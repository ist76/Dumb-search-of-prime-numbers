/* Tutorial to find all prime numbers in the range from 0 to user specified */
# include <stdio.h>
# include <stdlib.h>

# define COLUMN 25 /* displays the specified number of numbers in a row */

int prime(int p, const int primes_ex[]); /*prime number test function prototype*/
int n_get(void);

int main(int argc, char *argv[])
{
    int n = 0;
    int columns = COLUMN;

    if ((argc >= 2) && (atoi(argv[1]) > 1)) columns = atoi(argv[1]); /* set columns from comandline */
    if ((argc >= 3) && (atoi(argv[2]) > 3)) { n = atoi(argv[2]); }
    else { n = n_get(); };

    if (n == 0) return(0);
    printf_s("\n%6i \t", 2); /* the number 2 is always displayed */
    int *primes = malloc(columns * sizeof(int)); /* array with found primes */
    if (primes == NULL) return 0;
    int q = 0;
    primes[q++] = 2;

    for (int i = 3; i <= n; i += 2) /*We don’t check even candidate numbers*/
    {
        if (prime(i, primes) != 0) /*display a candidate number if the check function does not return "0"*/
        {
            printf_s("%6i \t", i);
            primes[q] = i;
            q++;
            if (q % columns == 0)
            {
                /*allocate more space for the array*/
                if ((primes = realloc(primes, ((q + columns) * sizeof(int)))) == NULL) return 0;
                puts("");
            }
        }
    }

    if ((argc >= 4) && (*argv[3] == 'f')) /* Outputting found numbers to a file */
    {
        puts("\nWriting a file......");
        FILE* fPtr = NULL;
        fopen_s(&fPtr, "primes.txt", "w");
        if (fPtr == NULL) puts("File could not be opened");
        else
        {
            for (int c = 0; c < q;)
            {
                fprintf(fPtr, "%6i \t", primes[c]);
                if (++c % columns == 0) fprintf(fPtr, "\n");
            }
            puts("primes.txt writed");
            fclose(fPtr);
        }
    }
    free(primes);
    return 0;
}

/* Accepts a candidate number and matches the found primes, gives the number itself if it is prime or 0 */
int prime(int p, const int primes_ex[])
{
    for (int j = 1; primes_ex[j] * primes_ex[j] <= p;)
    {
        if (p % primes_ex[j++] == 0) return 0;
    }
    return p;
}

int n_get(void) /* getting search ceiling from user */
{
    int correct = 0; /* correctness flag */
    int n_int = 0; /* upper limit */
    puts("Enter an upper limit for finding prime numbers:");
    correct = scanf_s("%i", &n_int); /*checking the correctness of the upper bound entered by the user*/
    if ((correct != 1) || (n_int < 3))
    {
        puts("Input error!");
        return(0);
    }
    return(n_int);
}
