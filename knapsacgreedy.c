#include <stdio.h>

int value[20];
int weight[20];
float ratio[20];

int name[20];

int main()
{
    int num, max, i, j, temp;
    printf("ENTER NUMBER OF FRUITS:");
    scanf("%d", &num);
    printf("ENTER MAX CAPACITY:");
    scanf("%d", &max);

    for (i = 0; i < num; i++)
    {
        printf("ENTER THE NUTRIENT VALUE FOR FRUIT %d: ", i+1);
        scanf("%d", &value[i]);
        name[i]=i+1;
    }
    for (i = 0; i < num; i++)
    {
        printf("ENTER THE WEIGHT FOR FRUIT %d: ", i+1);
        scanf("%d", &weight[i]);
    }
    for (i = 0; i < num; i++)
    {
        ratio[i] = (float)value[i] / weight[i];
    }

    // Sorting fruits based on the ratio in descending order
    for (i = 0; i < num - 1; i++)
    {
        for (j = 0; j < num - i - 1; j++)
        {
            if (ratio[j] < ratio[j + 1])
            {
                float tempRatio = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = tempRatio;

                int tempValue = value[j];
                value[j] = value[j + 1];
                value[j + 1] = tempValue;

                int tempWeight = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = tempWeight;

                int tempname = name[j];
                name[j] = name[j + 1];
                name[j + 1] = tempname;

            }
        }
    }

    printf("\nFRUIT VALUE   WEIGHT   RATIO\n");
    for (i = 0; i < num; i++)
    {
        printf("F%d     %d      %d      %.2f\n", name[i], value[i], weight[i], ratio[i]);
    }

    int currentWeight = 0;
    float totalValue = 0;

    for (i = 0; i < num; i++)
    {
        if (currentWeight + weight[i] <= max)
        {
            printf("Selected Fruit: F%d\n", name[i]);
            currentWeight += weight[i];
            totalValue += value[i];
        }
        else
        {
            float remainingWeight = max - currentWeight;
            float fraction = remainingWeight / weight[i];
            printf("Selected Fraction of Fruit: F%d (Fraction: %.2f)\n", name[i], fraction);
            totalValue += fraction * value[i];
            currentWeight = max; 
            break;
        }
    }

    printf("Total Value: %.2f\n", totalValue);
    printf("Total Weight: %d\n", currentWeight);

    return 0;
}
