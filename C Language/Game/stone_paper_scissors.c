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
    else if ((char1 == 'R') && (char2 == 'S'))
        return 1;
    else if ((char2 == 'R') && (char1 == 'S'))
        return 0;
    else if ((char1 == 'P') && (char2 == 'R'))
        return 1;
    else if ((char2 == 'P') && (char1 == 'S'))
        return 0;
    else if ((char1 == 'S') && (char2 == 'P'))
        return 1;
    else if ((char2 == 'S') && (char1 == 'P'))
        return 0;
    return -1;
}

int main()
{
    srand(time(NULL));
    int playerScore = 0, compScore = 0, temp;
    char playerChar, compChar;
    char dict[] = {'R', 'P', 'S'};

    printf("Welcome to Rock, Paper, Scissors!\n");

    for (int i = 0; i < 3; i++)
    {
        // Player input
        printf("Your turn:\nChoose 1 for Rock, 2 for Paper, 3 for Scissors.\n");
        scanf("%d", &temp);

        if (temp < 1 || temp > 3)
        {
            printf("Invalid choice! Try again.\n");
            i--; // repeat this round
            continue;
        }

        playerChar = dict[temp - 1];
        printf("You chose: %c\n\n", playerChar);

        // Computer input
        temp = generateRandomNumber(3) + 1;
        compChar = dict[temp - 1];
        printf("Computer chose: %c\n", compChar);

        // Compare
        int result = greater(playerChar, compChar);
        if (result == 1)
        {
            playerScore++;
            printf("You Got it!\n");
        }
        else if (result == -1)
        {
            printf("It's a tie!\n");
        }
        else
        {
            compScore++;
            printf("Computer Got it!\n");
        }

        printf("You: %d | Computer: %d\n\n", playerScore, compScore);
    }

    // Final result
    if (playerScore > compScore)
        printf("Player wins the game!\n");
    else if (playerScore < compScore)
        printf("Computer wins the game!\n");
    else
        printf("It's a draw!\n");

    return 0;
}