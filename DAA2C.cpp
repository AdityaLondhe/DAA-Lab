#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to check if a given workload per day is feasible within D days
bool isFeasible(vector<int>& tasks, int D, int maxWorkPerDay) {
    int daysNeeded = 1; // Start with one day
    int currentWork = 0; // Work done on the current day

    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i] > maxWorkPerDay) {
            return false; // If a single task exceeds maxWorkPerDay, it's not feasible
        }

        if (currentWork + tasks[i] > maxWorkPerDay) {
            // Start a new day
            daysNeeded++;
            currentWork = tasks[i];

            if (daysNeeded > D) {
                return false; // If days needed exceeds D, it's not feasible
            }
        } else {
            currentWork += tasks[i];
        }
    }

    return true;
}

// Function to find the minimum work to be done per day
int minWorkPerDay(vector<int>& tasks, int D) {
    int low = *max_element(tasks.begin(), tasks.end()); // Minimum possible work is the max task
    int high = accumulate(tasks.begin(), tasks.end(), 0); // Maximum possible work is the sum of all tasks

    int result = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isFeasible(tasks, D, mid)) {
            result = mid;
            high = mid - 1; // Try for a smaller workload
        } else {
            low = mid + 1; // Increase the workload per day
        }
    }

    return result;
}

int main() {
    int n, D;

    // Input number of tasks
    cout << "Enter the number of tasks: ";
    cin >> n;

    vector<int> tasks(n);

    // Input the work required for each task
    cout << "Enter the amount of work for each task: ";
    for (int i = 0; i < n; i++) {
        cin >> tasks[i];
    }

    // Input the number of days
    cout << "Enter the number of days: ";
    cin >> D;

    // Calculate the minimum work per day to complete all tasks in D days
    int result = minWorkPerDay(tasks, D);

    // Output the result
    cout << "Minimum amount of work to be done per day: " << result << endl;

    return 0;
}