#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;

        // Loop through each bar to calculate the area for each one
        for (int i = 0; i < n; ++i) {
            // Find the previous smaller element (left)
            int left = i;
            while (left >= 0 && heights[left] >= heights[i]) {
                left--;
            }

            // Find the next smaller element (right)
            int right = i;
            while (right < n && heights[right] >= heights[i]) {
                right++;
            }

            // Calculate the width of the rectangle
            int width = right - left - 1;

            // Calculate the area for the current bar
            int area = heights[i] * width;

            // Update maxArea if the current area is larger
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};

int main() {
    Solution sol;
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "Largest Rectangle Area: " << sol.largestRectangleArea(heights) << endl;
    return 0;
}
