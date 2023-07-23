#include <stdio.h>
#include <stdbool.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int weights[], int values[], int n) {
    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // Backtrack to find the selected items
    int selected[n];
    int i = n, w = W, count = 0;

    while (i > 0 && w > 0) {
        if (dp[i][w] != dp[i - 1][w]) {
            selected[count++] = i;
            w -= weights[i - 1];
            i--;
        } else {
            i--;
        }
    }

    printf("Selected objects: ");
    for (int j = count - 1; j >= 0; j--)
        printf("%d ", selected[j]);
    printf("\n");

    return dp[n][W];
}

int main() {
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int weights[n], values[n];
    printf("Enter the weights: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &weights[i]);

    printf("Enter the values: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &values[i]);

    printf("Enter the maximum weight capacity of the knapsack: ");
    scanf("%d", &W);

    int result = knapsack(W, weights, values, n);
    printf("The maximum value that can be obtained from the knapsack is: %d\n", result);

    return 0;
}
