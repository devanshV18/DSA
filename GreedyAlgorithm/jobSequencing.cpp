#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Job structure
struct Jobs {
    int id;
    int deadline;
    int profit;
};

// Custom comparator for sorting
bool compare(Jobs j1, Jobs j2) {
    if (j1.profit == j2.profit) {
        return j1.deadline < j2.deadline;
    }
    return j1.profit > j2.profit;
}

// Function to find maximum profit and number of jobs done
pair<int, int> maxProfitScheduling(vector<int>& jobIds, vector<int>& deadlines, vector<int>& profits) {
    int n = jobIds.size();
    vector<Jobs> schedule;

    // Building the schedule vector with job details
    for (int i = 0; i < n; i++) {
        schedule.push_back({jobIds[i], deadlines[i], profits[i]});
    }

    // Sorting jobs by profit in decreasing order
    sort(schedule.begin(), schedule.end(), compare);

    // Find the maximum deadline to define the range of slots
    int maxDeadline = 0;
    for (auto job : schedule) {
        maxDeadline = max(maxDeadline, job.deadline);
    }

    // Array to track available time slots (initialized to -1 for free slots)
    vector<int> timeSlots(maxDeadline + 1, -1);

    int jobCount = 0;
    int maxProfit = 0;

    // Try to schedule each job
    for (auto job : schedule) {
        // Start from the latest slot before or on the job's deadline
        for (int slot = job.deadline; slot > 0; slot--) {
            if (timeSlots[slot] == -1) { // If the slot is free
                timeSlots[slot] = job.id; // Assign the job to this slot
                jobCount++;               // Increment the count of scheduled jobs
                maxProfit += job.profit;  // Add the job's profit to the total profit
                break;                    // Move to the next job after scheduling
            }
        }
    }

    return {jobCount, maxProfit};
}

int main() {
    // Example input
    vector<int> jobIds = {6, 3, 4, 2, 5, 8, 1, 7};
    vector<int> deadlines = {2,6,6,5,4,2,4,2};
    vector<int> profits = {80,70,65,60,25,22,20,10};

    // Function call
    pair<int, int> result = maxProfitScheduling(jobIds, deadlines, profits);

    // Output the result
    cout << "Number of jobs done: " << result.first << endl;
    cout << "Maximum profit: " << result.second << endl;

    return 0;
}
