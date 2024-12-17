#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Meetings{
    int start;
    int end;
    int posn;
};

bool compare(Meetings a, Meetings b){
    if(a.end == b.end){
        return a.posn < b.posn;
    }
    
    return a.end < b.end;
}

int maxMeetingsPossible(vector<int> s, vector<int> e){
    vector<Meetings> meets;

    //populating the meets vector with our meetings

    for(int i = 0; i <s.size(); i++){
        meets.push_back({s[i], e[i], i+1});
    }

    sort(meets.begin(), meets.end(), compare); //sorting the meetings based on their ending times in ascending order

    vector<int> ans; //contains the posn of meeting in order to maximise the number of meetings;
    
    //the first meeting will definately take place
    int freeTime = meets[0].end;
    ans.push_back(meets[0].posn);

    for(int i = 1; i<meets.size(); i++){
        if(meets[i].start > freeTime){
            freeTime = meets[i].end;
            ans.push_back(meets[i].posn);
        }
    }

    return ans.size();
}

int main(){
    vector<int> startTimes = {0,3,1,5,5,8};
    vector<int> endTimes = {5,4,2,9,7,9};
    int n = startTimes.size();

    int ans = maxMeetingsPossible(startTimes, endTimes);
    cout<<ans<<endl;
    return 0;
}