#include<vector>
#include<iostream>
using namespace std;

int partition(vector<int> &v, int low, int high){
    int pivot = v[low];
    int i = low;
    int j = high;

    while( i < j ){
        while( v[i] <= pivot && i <= high - 1 ){
            i++;
        }

        while ( v[j] > pivot && j >= low + 1 ){
            j--;
        }

        if( i < j ){
            swap(v[i], v[j]);
        }
    }

    swap(v[low], v[j]);

    return j;
}

void qs(vector<int> &v, int low, int high){
    if( low < high ){
        int pIndex = partition(v,low,high);
        qs(v, low, pIndex-1);
        qs(v, pIndex+1, high);
    }
}

vector<int> quickSort(vector<int> v){
    qs(v, 0, v.size()-1);
    return v;
}

int main(){
    vector<int> test = {7,2,5,8,3,6,1,11};
    vector<int> sortedArray = quickSort(test);

    for( int i = 0; i<sortedArray.size(); i++){
        cout << sortedArray[i] << " ";
    }
}