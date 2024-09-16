#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>

int secondLargestuo(vector<int> v){
    sort(v.begin(), v.end());
    for(int i=v.size()-2; i>=0 ; i--){
        if(v[i]==v[i+1]){
            continue;
        }
        else{
            return v[i];
        }
    }
}

//without sorting
int secondLargest(vector<int> v){
    int n = v.size();

    int largestElement = v[0];
    int secondLargestElement = -1;

    for(int i = 0; i<n; i++){
        if(v[i] > largestElement){
            secondLargestElement = largestElement;
            largestElement = v[i];
        }
        //safely placing any element that is greater than secondlargest element but not equal to the largest element in the second largest element variable
        else if (v[i] > secondLargestElement && v[i] != largestElement){
            secondLargestElement = v[i];
        }
    }
    return secondLargestElement;
}

int main(){
    vector<int> vc = {2,4,3,8,7,6};
    int ans = secondLargest(vc);
    cout<<ans<<endl;
}