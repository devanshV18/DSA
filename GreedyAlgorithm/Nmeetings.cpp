#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

struct Meeting{
    int start;
    int end;
    int pos;
};

// VVVII
//this function will sort our vector of items where each item will be of the type Meeting

bool compare(Meeting m1, Meeting m2){
    //if two meetings have same end time, we need to sort them by position
    if(m1.end == m2.end){
        return m1.pos < m2.pos;
    }
    //sort ascendingly in terms of end time
    return m1.end < m2.end;
}

void maxMeetings(vector<int> &s, vector<int> &e, int n){
    vector<Meeting> meets;

    for(int i = 0; i<n; i++){
        meets.push_back({ s[i], e[i], i+1 });
    }

    //now lets sort our DS on the basis of end time and on the basis of posn in case end times coincide
    //sorting the meets vector containing a custom Data type item using our custom comparator

    sort(meets.begin(), meets.end(), compare);
    
    //initial settings
    vector<int> selectedMeetings;
    int freeTime = meets[0].end;
    int cnt = 1;
    selectedMeetings.push_back(meets[0].pos);

    for(int i = 1; i< meets.size(); i++){
        if( meets[i].start > freeTime ){
            selectedMeetings.push_back(meets[i].pos);
            cnt++;
            freeTime = meets[i].end;
        }
    }

    cout << "Maximum number of meetings Possible: " << cnt << endl;

    cout << "Order of Meetings based on 1 based indexing" << endl;

    for(int i = 0 ; i< selectedMeetings.size(); i++){
        cout << selectedMeetings[i] << " ";
    }

    cout << endl;
}

int main() {
    // Example input
    vector<int> startTimes = {0,3,1,5,5,8};
    vector<int> endTimes = {5,4,2,9,7,9};
    int n = startTimes.size();

    maxMeetings(startTimes, endTimes, n);

    return 0;
}