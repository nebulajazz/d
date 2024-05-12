#include <stdio.h>
#define MAX_ELEMENTS 100

int numElements, targetSum;
int elements[MAX_ELEMENTS];
int subset[MAX_ELEMENTS];

void findSubsets(int currentIndex, int currentSum, int remainingSum) {
    int i;
    subset[currentIndex] = 1;

    if (currentSum + elements[currentIndex] == targetSum) {
        for (i = 0; i < numElements; i++) {
            printf("%d ", subset[i]);
        }
        printf("\n");
    } else if (currentSum + elements[currentIndex] + elements[currentIndex + 1] <= targetSum) {
        findSubsets(currentIndex + 1, currentSum + elements[currentIndex], remainingSum - elements[currentIndex]);
    }

    if (currentSum + elements[currentIndex + 1] <= targetSum && currentSum + remainingSum - elements[currentIndex] >= targetSum) {
        subset[currentIndex] = 0;
        findSubsets(currentIndex + 1, currentSum, remainingSum - elements[currentIndex]);
    }
}

int main() {
    int i, totalSum;
    totalSum = 0;

    printf("Number of elements: ");
    scanf("%d", &numElements);

    printf("Enter the elements: ");
    for (i = 0; i < numElements; i++) {
        scanf("%d", &elements[i]);
        totalSum += elements[i];
        subset[i] = 0;
    }

    printf("Target sum: ");
    scanf("%d", &targetSum);

    findSubsets(0, 0, totalSum);
    
    return 0;
}
