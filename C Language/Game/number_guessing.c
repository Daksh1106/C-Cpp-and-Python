#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num, secret, attempts = 0, max_attempts = 5;
    printf("~~~~~~    Welcome to the NUMBER GUESSING GAME!!!    ~~~~~~\n");
    srand(time(NULL));
    secret = (rand() % 20) + 1;
    while (attempts < max_attempts)
    {
        printf("Enter your guess (Attempt %d of %d): ", attempts + 1, max_attempts);
        scanf("%d", &num);
        attempts++;
        if (num == secret)
        {
            printf("Congratulations! Number: %d in %d attempt(s).\n", secret, attempts);
            break;
        }
        else
            printf(num < secret ? "Higher please.\n" : "Lower please.\n");
    }

    if (num != secret)
        printf("Out of attempts! Number was %d.\n", secret);
    return 0;
}