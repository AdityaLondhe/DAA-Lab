#include <iostream>
using namespace std;

// Function to count trailing zeroes in factorial of a given number
int countTrailingZeroes(int num) {
    int count = 0;
    // We only count the number of 5s in the factors of the numbers
    for (int i = 5; num / i >= 1; i *= 5) 
    {
        count += num / i;
    }
    return count;
}

// Function to find the smallest number with at least n trailing zeroes in its factorial
int findSmallestNumber(int n) 
{
    // Binary search to find the smallest number with at least n trailing zeroes
    int low = 0;
    int high = 5 * n; // Upper bound based on the number of trailing zeroes needed
    int result = -1;

    while (low <= high) 
    {
        int mid = (low + high) / 2;
        int zeroes = countTrailingZeroes(mid);

        if (zeroes >= n) 
        {
            result = mid;
            high = mid - 1;
        } else 
        {
            low = mid + 1;
        }
    }

    return result;
}

int main() 
{
    int n;
    cout << "Enter the number of trailing zeroes needed: ";
    cin >> n;
    int result = findSmallestNumber(n);
    cout << "The smallest number whose factorial contains at least " << n << " trailing zeroes is: " << result << endl;
    return 0;
}