#include<iostream>
using namespace std;
#include<stack>
#include<vector>

int celeb(vector<vector<int>> v){
    int n = v.size();

    //since we have a n*n matrix the size of rows and column is ame as n
    vector<int> knowME(n,0);
    vector<int> iKnow(n,0);

    //Generating know me and i know array
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(v[i][j] == 1){
                //j is known by someone
                knowME[j]++;

                //i knows someone
                iKnow[i]++;
            }
        }
    }

    //checking both conditions atisfied for ith candidate.
    for(int i = 0; i<n; i++){
        if( knowME[i] == n-1 && iKnow[i] == 0 ){
            return i;
        }
    }
    return -1;
}

int celebOpt(vector<vector<int>> v){
    int n = v.size();
    int top = 0;
    int bottom = n-1;

    while(top < bottom){
        //if top knows bottom, top cant be a celeb
        if(v[top][bottom] == 1){
            top++;
        }
        //if bottom knows top bottom cant be a celeb
        else if(v[bottom][top] == 1){
            bottom--;
        }
        //case where both dont know each other -> both cant be a celeb as someone should be known by everyone to be a celeb
        else{
            top++;
            bottom--;
        }
    } 

    int candidate = top;

    // Validate the candidate
    for (int i = 0; i < n; i++) {
        if (i != candidate) {
            if (v[candidate][i] == 1 || v[i][candidate] == 0) {
                return -1;  // If candidate knows someone or someone doesn't know the candidate, not a celebrity
            }
        }
    }

    return candidate;  // If valid, return the celebrity's index
}

int main() {
    vector<vector<int>> v = {
        {0, 1, 1},
        {0, 0, 0},
        {1, 1, 0}
    };

    int result = celebOpt(v);
    if (result == -1) {
        cout << "No celebrity found." << endl;
    } else {
        cout << "Celebrity is person " << result << "." << endl;
    }
    return 0;
}