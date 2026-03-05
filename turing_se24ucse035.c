#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void turingTest()
{
    char response[200];
    int score = 0;

    char *questions[] = {
        "What is your favorite food?",
        "Do you like watching movies?",
        "What do you do in your free time?",
        "Which music do you like?"
    };

    printf("\n--- Turing Test Simulation ---\n");

    for(int i=0;i<3;i++)
    {
        int q = rand()%4;

        printf("Judge: %s\n",questions[q]);
        printf("Entity Response: ");

        fgets(response,200,stdin);

        int words = 0;
        for(int j=0;response[j]!='\0';j++)
            if(response[j]==' ')
                words++;

        if(words>=1)
            score++;
    }

    if(score>=2)
        printf("Result: Looks like a HUMAN\n");
    else
        printf("Result: Looks like a MACHINE\n");
}

int main()
{
    srand(time(NULL));

    turingTest();

    return 0;
}
