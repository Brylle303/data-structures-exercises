#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "recursion.h"
#include "powerSolver.c"
#include "iterPower.c"
#include "fibonacci.c"
#include "iterFibo.c"



void menu();

int main()
{
    bool isExit;
    int numBase;
    int numPower;
    int choice1, choice2;
    int result;
    int seqNum;

    while(!isExit)
    {
        system("cls");
        menu();
        printf("CHOICE: ");
        scanf("%d", &choice1);

        if(choice1 > 0 && choice1 < 4)
        {
            switch(choice1)
            {
            case 1:
                system("cls");
                printf("\n=POWER=\n");
                printf("Input base: ");
                scanf("%d", &numBase);
                printf("Input power: ");
                scanf("%d", &numPower);

                printf("[1] Iterative Power\n[2] Recursive Power\nChoice: ");
                scanf("%d", &choice2);

                switch(choice2)
                {
                case 1:
                    printf("\n-Iterative Power-\n");
                    printf("Result: ");
                    iterPower(numBase, numPower);

                    getche();

                    break;
                case 2:
                    printf("\n-Recursive Power-\n");
                    result = powerSolver(numBase, numPower);

                    printf("Result: %d\n", result);

                    getche();

                    break;
                }

                break;
            case 2:
                system("cls");
                printf("\n=FIBONACCI SEQUENCE=\n");
                printf("Input sequence where (n) is: ");
                scanf("%d", &seqNum);

                printf("Iterative Fibo(5): ");
                iterFibo(seqNum);
                printf("Recursive Fibo(5): ");

                for(int i = 0; i < seqNum; i++)
                {
                    printf("%d ", fibonacci(i));
                }
                printf("\n\n");

                printf("Press any key to continue...");
                getche();

                break;
            case 3:
                system("cls");
                printf("\n[Exiting Program]\n");

                return 0;
            }
        }
        else
        {
            printf("Invalid choice");
            getche();
        }


    }


    return 0;
}


void menu()
{
    printf("===MENU===\n");
    printf("[1] POWER\n");
    printf("[2] FIBONACCI\n");
    printf("[3] EXIT\n");

}
