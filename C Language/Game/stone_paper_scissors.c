#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandomNumber(int n)
{
    return rand() % n;
}

int greater(char char1, char char2)
{
    if (char1 == char2)
        return -1;
    if ((char1 == 'R' && char2 == 'S') || (char1 == 'P' && char2 == 'R') || (char1 == 'S' && char2 == 'P'))
        return 1;
    return 0;
}

int main()
{
    srand(time(NULL));
    int playerScore = 0, compScore = 0, temp, result;
    char playerChar, compChar;
    char dict[] = {'R', 'P', 'S'};
    printf("Rock, Paper, Scissors! (Best of 3)\n");

    for (int i = 0; i < 3; i++)
    {
        printf("Round %d: Choose 1-Rock, 2-Paper, 3-Scissors: ", i + 1);
        scanf("%d", &temp);
        if (temp < 1 || temp > 3)
        {
            printf("Invalid!\n");
            i--;
            continue;
        }
        playerChar = dict[temp - 1];
        compChar = dict[generateRandomNumber(3)];
        printf("You: %c | Computer: %c -> ", playerChar, compChar);
        result = greater(playerChar, compChar);
        if (result == 1)
        {
            playerScore++;
            printf("You win!\n");
        }
        else if (result == -1)
        {
            printf("Tie!\n");
        }
        else
        {
            compScore++;
            printf("Computer wins!\n");
        }
        printf("Score: %d-%d\n\n", playerScore, compScore);
    }

    printf("\nFinal: ");
    if (playerScore > compScore)
        printf("Player wins!\n");
    else if (playerScore < compScore)
        printf("Computer wins!\n");
    else
        printf("Draw!\n");

    return 0;
}