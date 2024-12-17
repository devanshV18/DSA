#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//brute force approach -> to pick each train using outer loop and corresponding to each picked i/train we compare with all other trains for the intersection and store it in an intermediate variable platformsNeeded which is initialised to 1 for each traina s for each train a minimum of 1 platform is surely required. Also outide the inner loop after each iteration we store the max of the platformsNeeded as maximum number of platformsNeeded = maximum numbers of intersection at a given timeline for any train = minimum number of platforms required

int minPlatforms(vector<int> &arrivals, vector<int> &departures){
    int n = arrivals.size();

    int minPlatformsCount = 0;

    for(int i = 0; i<n; i++){
        int platformsNeeded = 1;
        for(int j = 0; j<n; j++){
            if(i != j ){
                if( arrivals[j] <= departures[i] && departures[j] >= arrivals[i] ){
                    platformsNeeded += 1;
                }
            }
        }
        minPlatformsCount = max(minPlatformsCount, platformsNeeded);
    }

    return minPlatformsCount;
}


//optimal approach -> analysing the entire timeline instead of analysing arrivals and departure times

int minPlatformsOptimised(vector<int> &arrivals, vector<int> &departures){
    int n = arrivals.size();

    sort(arrivals.begin(), arrivals.end());
    sort(departures.begin(), departures.end());
    int i = 0, j = 0;
    int minPlatformsCount = 0;
    int cnt = 0;

    while( i < n ){
        if( arrivals[i] <= departures[j] ){
            cnt++;
            i++;
        }
        else{
            cnt--;
            j++;
        }
        minPlatformsCount = max(minPlatformsCount, cnt);
    }

    return minPlatformsCount;
}

int minPlatformsRequired(vector<int> arrivals, vector<int> departures){
    int n = arrivals.size(); //common size

    // i want max platforms required == max intersections for each train
    int minPlatforms = 0;

    for(int i = 0; i<n; i++){
        int platformsNeeded = 1;
        for(int j = 0; j<n; j++){
            if( i != j ){
                if(arrivals[j] <= departures[i] && departures[j] >= arrivals[i]){
                    platformsNeeded += 1;
                }
            }
        }
        minPlatforms = max(minPlatforms, platformsNeeded);
    }

    return minPlatforms;
}


int minPlatformsRequiredOptimised(vector<int> departs, vector<int> arrivs){
    int n = departs.size();

    sort(departs.begin(), departs.end());
    sort(arrivs.begin(), arrivs.end());

    int i = 0, j = 0;
    int cnt = 0;
    int minPlatforms = 0;
    while( i < n ){
        if( arrivs[i] <= departs[j] ){
            cnt++;
            i++;
        }
        else{
            cnt--;
            j++;
        }
        minPlatforms = max(minPlatforms, cnt);
    }

    return cnt;
}

int main() {
    // Example input
    vector<int> arrival = {900, 940, 950, 1100, 1500, 1800};
    vector<int> departure = {910, 1200, 1120, 1130, 1900, 2000};

    int result = minPlatformsRequiredOptimised(arrival, departure);

    cout << "Minimum number of platforms required: " << result << endl;

    return 0;
}