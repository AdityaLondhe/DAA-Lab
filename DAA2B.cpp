#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the maximum profit
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;

    int maxProfit = 0;
    int minPrice = prices[0];

    // Iterate over each day's price
    for (int i = 1; i < n; i++) {
        // Update the minimum price seen so far
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        }
        // Calculate potential profit by selling on the current day
        int potentialProfit = prices[i] - minPrice;
        // Update the maximum profit if the current potential profit is greater
        if (potentialProfit > maxProfit) {
            maxProfit = potentialProfit;
        }
    }

    return maxProfit;
}

int main() {
    int n;

    // Input number of days
    cout << "Enter the number of days: ";
    cin >> n;

    vector<int> prices(n);

    // Input the stock prices for each day
    cout << "Enter the stock prices for each day: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    // Calculate the maximum profit
    int result = maxProfit(prices);

    // Output the result
    cout << "Maximum profit that can be earned: " << result << endl;

    return 0;
}