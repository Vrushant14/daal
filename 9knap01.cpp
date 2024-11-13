#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int profit;
    int weight;
}; 
int knapsack(int n, int W, Item items[])
{
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
            else if (items[i - 1].weight <= w)
            {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - items[i - 1].weight] +
                                                 items[i - 1].profit);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}

int main()
{
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> W;
    Item items[n];
    cout << "Enter the profit and weight of each item:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> items[i].profit >> items[i].weight;
    }
    int maxProfit = knapsack(n, W, items);
    cout << "Maximum profit that can be obtained: " << maxProfit << endl;
    return 0;
}
