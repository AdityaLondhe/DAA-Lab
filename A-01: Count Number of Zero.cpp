// Find count of Zero By using Divide and Conquer(binary search)
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[10], T, n, i, low, high, mid, flag, count_zero;
    cin >> T;
    while (T--)
    {
        flag = 0;
        count_zero = 0;
        cout << "Enter Array Size: ";
        cin >> n;
        cout << "Enter " << n << " Element: ";
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        low = 0;
        high = n - 1;
        mid = (low + high) / 2;

        while (low <= high)
        {
            if (a[mid] == 0 && a[mid - 1] == 1)
            {
                flag = 1;
                count_zero = n - mid;
                break;
            }
            if (a[mid] == 0 && mid == 0)
            {
                flag = 1;
                count_zero = n - mid;
                break;
            }
            else if (a[mid] == 1 && a[mid + 1] == 0)
            {
                flag = 1;
                count_zero = n - 1 - mid ;
                break;
            }
            else if (a[mid] == 1 && a[mid + 1] != 0)
                low = mid + 1;
            else if (a[mid] == 0 && a[mid - 1] != 1)
                high = mid - 1;

            mid = (low + high) / 2;
        }
        if (flag == 1 && low <= high)
            cout << "Count of Zero: " << count_zero << endl;
    }
    return 0;
}
