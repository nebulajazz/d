#include <stdio.h> 

void minCoins(int coins[], int n, int amount) { 
    int i, minCoins = 0,count; 
    for (i = n - 1; i >= 0; i--) { 
        count = 0;
        while (amount >= coins[i]) {
            count++;
            minCoins++; 
            amount -= coins[i]; 
        } 
        printf("%d x $%d used\n", count, coins[i]);
    } 
   printf("Minimum number of coins required: %d\n", minCoins); 
} 

int main() { 
    int coins[10]; 
    int n, i, amount; 
    printf("Enter the number of coin denominations: "); 
    scanf("%d", &n); 
    printf("Enter the coin denominations:\n"); 
    for (i = 0; i < n; i++) { 
        scanf("%d", &coins[i]); 
    } 
    printf("Enter the amount: "); 
    scanf("%d", &amount);
    
    minCoins(coins, n, amount); 
    
    return 0; 
}
