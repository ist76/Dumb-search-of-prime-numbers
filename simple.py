# Tutorial to find all prime numbers in the range from 0 to user specified

# The most primitive check is whether the resulting number is prime. Returns either 0 or the number itself
def prime(num):
    for j in range(3, num // 3 + 1, 2):     #Minimal optimization: substitute only odd
                                            # divisors and up to 1/3 of the upper search limit
        if num % j == 0:
            return False
    return num


column = 25  # displays the specified number of numbers in a row
q = 1
try:
    n = int(input("Enter an upper limit for finding prime numbers: \n"))
except ValueError:
    n = 0
if n <= 3:  # checking the correctness of the upper bound entered by the user
    print('Input error!')
    exit()

print('%6d' % 3, end='\t')  # the number 3 is always displayed
for i in range(5, n + 1, 2):  # We don't check even numbers
    if prime(i):  # display a candidate number if the check function does not return "0"
        print('%6d' % i, end='\t')
        q += 1
        if q == column:
            print()
            q = 0
