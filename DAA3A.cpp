#include <iostream>
#include <vector>
using namespace std;

int countWaysToMakeSum(const vector<int>& coins, int sum) {
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;
    
    for (int coin : coins) {
        for (int j = coin; j <= sum; ++j) {
            dp[j] += dp[j - coin];
        }
    }
    
    return dp[sum];
}

int main() {
    int N, sum;
    cout << "Enter the number of types of coins: ";
    cin >> N;
    
    vector<int> coins(N);
    cout << "Enter the coin denominations: ";
    for (int i = 0; i < N; ++i) {
        cin >> coins[i];
    }
    
    cout << "Enter the target sum: ";
    cin >> sum;
    
    cout << "Number of ways to make the sum: " << countWaysToMakeSum(coins, sum) << endl;
    
    return 0;
}