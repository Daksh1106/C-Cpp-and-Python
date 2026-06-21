// Write a program in C language where the program is capable of playing the 'Snake, water, gun' game with me. The program should be able to print the result after i choose snake/water/gun.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char getComputerChoice()
{
    char choices[] = {'s', 'w', 'g'};
    return choices[rand() % 3];
}

int determineWinner(char you, char comp)
{
    if (you == comp)
        return 0;
    if ((you == 's' && comp == 'w') || (you == 'w' && comp == 'g') || (you == 'g' && comp == 's'))
        return 1;
    return -1;
}

void printChoice(char choice)
{
    char *choices[] = {"Snake", "Water", "Gun"};
    int idx = (choice == 's') ? 0 : (choice == 'w') ? 1
                                : (choice == 'g')   ? 2
                                                    : -1;
    printf("%s", idx >= 0 ? choices[idx] : "Invalid");
}

int main()
{
    char you, comp;
    int result;
    srand(time(0)); // Seed the random number generator with current time
    // Display welcome message and instructions
    printf("====== Welcome to the Snake, Water, Gun Game ======\nInstructions:\nType 's' for Snake, 'w' for Water, 'g' for Gun\n--------------------------------------------------\n");
    printf("Enter your choice (s/w/g): ");
    scanf(" %c", &you);
    if (you != 's' && you != 'w' && you != 'g')
    {
        printf("Invalid choice!\n");
        return 0;
    }
    comp = getComputerChoice();
    result = determineWinner(you, comp);
    printf("\nYou chose: ");
    printChoice(you);
    printf("\nComputer chose: ");
    printChoice(comp);
    printf("\n");

    if (result == 0)
        printf("Result: It's a draw!\n");
    else if (result == 1)
    {
        printf("Result: You win! ");
        if (you == 's')
            printf("Snake drinks Water.\n");
        else if (you == 'w')
            printf("Water douses Gun.\n");
        else
            printf("Gun kills Snake.\n");
    }
    else
    {
        printf("Result: You lose! ");
        if (comp == 's')
            printf("Snake drinks Water.\n");
        else if (comp == 'w')
            printf("Water douses Gun.\n");
        else
            printf("Gun kills Snake.\n");
    }
    return 0;
}