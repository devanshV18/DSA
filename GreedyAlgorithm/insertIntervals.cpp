#include<vector>
#include<iostream>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int n = intervals.size();
    int i = 0;
    vector<vector<int>> ans;

    // all intervals coming before the new interval
    while( i < n && intervals[i][1] < newInterval[0] ){
        ans.push_back(intervals[i]);
        i++;
    }  
    //VVVVIII ------> //at this point all intervals strictly to the left i.e. which ends before the new interval (to be inserted starts) are in ans array and i points to the first overlapping interval. The overlap case only means if the start of the interval is less than or equal to the end of new Interval.
    // ex :-     6      7   (current interval)
    //         5          8 (new interval)  


    //i resumes after pushing all intervals that end before the start of new Interval
    //handling the overlappings -> it will handle all overlaps and assign start and end point with extreme values to newInterval
    while( i < n && intervals[i][0] <= newInterval[1] ){
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    //at this point all overlappings are resolved and a new interval that handles all overlappings is ready to be inserted

    ans.push_back(newInterval);


    //after inserting the resolved interval,  we just simply push the remaining intervals.
    while(i < n){
        ans.push_back(intervals[i]);
        i++;
    }

    return ans;
}

vector<vector<int>> insertIntervals(vector<vector<int>> intervals, vector<int> newInterval){
    int n = intervals.size();
    int i = 0;
    vector<vector<int>> ans;

    while(i < n && intervals[i][1] < newInterval[0]){
        ans.push_back(intervals[i]);
        i++;
    }


    while(i < n && intervals[i][0] <= newInterval[1]){
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }

    ans.push_back(newInterval);

    while(i < n){
        ans.push_back(intervals[i]);
        i++;
    }

    return ans;
}

int main() {
    vector<vector<int>> intervals = {{1, 3}, {6, 9}};
    vector<int> newInterval = {2, 5};

    vector<vector<int>> result = insert(intervals, newInterval);

    cout << "Merged intervals: ";
    for (const auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}