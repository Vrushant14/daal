#include <bits/stdc++.h>
using namespace std;

struct Items
{
    int profit;
    int weight;
};
void bubbleSort(int n, double ratio[], Items item[])
{

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (ratio[j] < ratio[j + 1])
            {
                double tempRatio = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = tempRatio;
                Items tempItem = item[j];
                item[j] = item[j + 1];
                item[j + 1] = tempItem;
            }
        }
    }
}

double calcMax(int n, int W, Items item[])
{
    double ratio[n];
    for (int i = 0; i < n; i++)
    {
        ratio[i] = (double)item[i].profit / item[i].weight;
    }
    bubbleSort(n, ratio, item);
    cout << "Sorted items based on profit/weight ratio:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Profit: " << item[i].profit << ", Weight: " << item[i].weight
             << ", P/W Ratio: " << ratio[i] << endl;
    }
    int tempW = 0;
    double maxProfit = 0;
    for (int i = 0; i < n; i++)
    {
        if (tempW + item[i].weight <= W)
        {
            tempW += item[i].weight;
            maxProfit += item[i].profit;
            cout << "Item" << i + 1 << " Profit: " << item[i].profit << endl;
        }
        else
        {
            int remW = W - tempW;
            double fractionalProfit = item[i].profit * ((double)remW / item[i].weight);
            maxProfit += fractionalProfit;
            cout << (double)remW / item[i].weight * 100 << "\% of item " << i + 1
                 << ", Profit: " << fractionalProfit << endl;
            break;
        }
    }
    return maxProfit;
}

int main()
{
    int n;
    cout << "Enter the number of items: ";
    cin >> n;
    int W;
    cout << "Enter the total possible weight: ";
    cin >> W;
    Items item[n];
    cout << "Enter the profit of each item:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> item[i].profit;
    }
    cout << "Enter the weight of each item:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> item[i].weight;
    }
    double maxProfit = calcMax(n, W, item);
    cout << "Maximum profit that can be obtained: " << maxProfit << endl;
    return 0;
}