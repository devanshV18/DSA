#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<stack>
using namespace std;


//Brute force method
// Approach -> find all the indices of NSE and PSE of each element of the array ,
// then compute the area for each element as v[i] * (nse-pse-1)


//next smaller element indices -> if found OK and if not found assign n (the size of array)
vector<int> nextSmallerElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> nse(n, n); // Initialize with -1 (no smaller element)
    stack<int> s;
    
    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] > arr[i]) {
            nse[s.top()] = i; // Update the index of the next smaller element
            s.pop();
        }
        s.push(i);
    }

    return nse;
}



//finding prev smaller element indices -> if found OK , if not found assign -1 
vector<int> previousSmallerElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> pse(n, -1); // Initialize with -1 (no smaller element)
    stack<int> s;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop(); // Pop elements until we find the smaller one
        }
        if (!s.empty()) {
            pse[i] = s.top(); // Update the index of the previous smaller element
        }
        s.push(i);
    }

    return pse;
}


int maxAreaHistogram(vector<int> v){
    vector<int> nse = nextSmallerElement(v);
    vector<int> pse = previousSmallerElement(v);
    int maxArea = 0;

    for(int i = 0; i<v.size(); i++){
        int area = ( v[i] * (nse[i] - pse[i] - 1) );
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int main() {
    vector<int> histogram = {2, 4};
    cout << "Maximum Rectangle Area in Histogram: " << maxAreaHistogram(histogram) << endl;
    return 0;
}
