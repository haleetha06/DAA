#include <stdio.h>
#define LIMIT 50

struct Task
{
    char name[5];
    int due;
    int gain;
};

void arrangeByProfit(struct Task list[], int count)
{
    int a, b;
    struct Task swapTemp;

    for (a = 0; a < count - 1; a++)
    {
        for (b = a + 1; b < count; b++)
        {
            if (list[a].gain < list[b].gain)
            {
                swapTemp = list[a];
                list[a] = list[b];
                list[b] = swapTemp;
            }
        }
    }
}

int main()
{
    struct Task list[LIMIT];
    int totalTasks, x, y, highestDeadline = 0;
    int schedule[LIMIT];
    int overallProfit = 0;

    printf("Enter total number of tasks: ");
    scanf("%d", &totalTasks);

    for (x = 0; x < totalTasks; x++)
    {
        printf("Enter Task name, Profit value and Deadline: ");
        scanf("%s %d %d", list[x].name,
                              &list[x].gain,
                              &list[x].due);

        if (list[x].due > highestDeadline)
            highestDeadline = list[x].due;
    }

    arrangeByProfit(list, totalTasks);

    for (x = 0; x <= highestDeadline; x++)
        schedule[x] = -1;

    for (x = 0; x < totalTasks; x++)
    {
        for (y = list[x].due; y > 0; y--)
        {
            if (schedule[y] == -1)
            {
                schedule[y] = x;
                overallProfit += list[x].gain;
                break;
            }
        }
    }

    printf("\nSelected Task Order:\n");
    for (x = 1; x <= highestDeadline; x++)
    {
        if (schedule[x] != -1)
            printf("%s ", list[schedule[x]].name);
    }

    printf("\nMaximum Profit Earned: %d\n", overallProfit);

    return 0;
}
