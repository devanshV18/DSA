#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};

    // Step 1: Sort intervals by start time
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> merged; // To store merged intervals
    merged.push_back(intervals[0]); // Start with the first interval

    // Step 2: Iterate through intervals and merge overlapping ones
    for (int i = 1; i < intervals.size(); i++) {
        // Get the last interval in the merged list
        vector<int>& last = merged.back();

        if (intervals[i][0] <= last[1]) {
            // Overlapping: merge intervals by updating the end of the last interval
            last[1] = max(last[1], intervals[i][1]);
        } else {
            // Non-overlapping: add the current interval to the result
            merged.push_back(intervals[i]);
        }
    }

    return merged;
}

int main() {
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> result = merge(intervals);

    cout << "Merged intervals: ";
    for (const auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
