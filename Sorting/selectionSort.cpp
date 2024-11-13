#include<iostream>
#include<vector>
using namespace std;

//in selection sort, we iterate through the entire array towards the righ in the inner loop (j) for each value of i until i < n-1, i can go upto second last elemnt. The inner loop compares each element starting from element at ith index till the end, and if any elemnt is lesser than current ith, minIndex is updated to that index.
// once inner loop ends, we swap v[minIndex, v[i]], swapping the minimum elememt to the start of the array.
void selectionSort(vector<int> &v){
    int n = v.size();
    for(int i = 0; i<n-1; i++){ //i goes till second last elemnt
        int minIndex = i; //for each new i we call minIndex to be the first element or i.
        for(int j = i; j<n; j++){ //j goes till last
            if(v[j] < v[minIndex]){
                minIndex = j;
            }
        }//inner loop

        swap(v[i], v[minIndex]);
    }
}

int main(){
    vector<int> v = {13,46,24,52,20,9};
    selectionSort(v);

    for(int i = 0; i<v.size(); i++){
        cout << v[i] << " ";
    }
}