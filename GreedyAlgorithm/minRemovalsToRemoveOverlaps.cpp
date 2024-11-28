#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int minRemovals(vector<vector<int>> intervals){
    if(intervals.empty()) return 0;

    int n =intervals.size();

    sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){
        return a[1] < b[1]; //sorting the array in ascending order by end points
    });

    vector<vector<int>> nonOverlappings;
    nonOverlappings.push_back(intervals[0]);

    for(int i = 1; i<n; i++){
        vector<int> last = nonOverlappings.back();
        if(intervals[i][0] >= last[1]){
            nonOverlappings.push_back(intervals[i]);
        }
    }

    int newSize = nonOverlappings.size();

    return n - newSize;

}

int main(){
    vector<vector<int>> intervals2 = {{1, 2}, {2, 3}, {3, 4},{1,3}};
    int removals = minRemovals(intervals2);
    cout << removals << endl;
}