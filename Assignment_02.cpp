// Implement a problem of move all zeroes to end of array. 
#include <iostream>
using namespace std;
int main()
{
    // Declare Variable
    int a[10], ans[10], T, n, j, i, c;
    // Read Count of Test Cases
    cout << "Enter No of Test Cases: ";
    cin >> T;
    while (T--)
    {
        // Read Array Size
        cout << "Enter Size:";
        cin >> n;
        // Read Array Element
        cout << "Enter " << n << " Element: ";
        i = 0;
        while (i < n)
        {
            cin >> a[i];
            i++;
        }
        // Store Non Zero Elements in answer Array 
        i = 0;
        c = 0;
        j = 0;
        while (i < n)
        {
            // Get the count of zero present in given array
            if (a[i] == 0)
                c++;
            else
            {
                // Store non zero
                ans[j] = a[i];
                j++;
            }
            i++; 
        }
        // Store zero at the end of final array
        i = 0;
        while (i < c)
        {
            ans[j] = 0;
            j++;
        }
        // Display Answer
        i = 0;
        while (i < n)
        {
            cout << ans[i] << " ";
            i++;
        }
        cout<<endl;
    }
    return 0;
}
