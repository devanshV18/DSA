#include<iostream>
#include<vector>
using namespace std;


//brute force approach, we use an extra array to store merged array and then calculate the median and return it.

double median( vector<int> a, vector<int> b ){
    int n1 = a.size();
    int n2 = b.size();
    int n = n1+n2;

    int i = 0;
    int j = 0;
    vector<int> v;

    while(i < n1 && j < n2){
        if( a[i] < b[j] ){
            v.push_back(a[i]);
            i++;
        }

        else{
            v.push_back(b[j]);
            j++;
        }
    }
        while( i < n1 ){
            v.push_back(a[i]);
            i++;
        }

        
        while( j < n2 ){
            v.push_back(b[j]);
            j++;
        }

        if( n % 2 == 1 ){//odd
            return (double)(v[n/2]);
        }

        return (double)( (double)(v[n/2] + v[n/2-1]) )/ 2.0;
    
}


//better approach -> eliminate the usage of extra space / extra array

int medianBetter(vector<int> a, vector<int> b){
    int n1 = a.size();
    int n2 = b.size();
    int n = n1+n2;

    int i = 0;
    int j = 0;
    int cnt = 0;

    int el1 = -1;
    int el2 = -1;
    int ind1 = n/2;
    int ind2 = ind1-1;    


    while( i < n1 && j < n2 ){
        if( a[i] < b[j] ){
            if(cnt == ind1){
                el1 = a[i];
            }        
            if(cnt == ind2){
                el2 = a[i];
            }
            cnt++;
            i++;        
        }
        else{
            if(cnt == ind1){
                el2 = b[j];
            }
            if(cnt == ind2){
                el2 = b[j];
            }
            cnt++;
            j++;
        }
    }

    while( i < n1 ){
        if(cnt == ind1){
            el1 = a[i];
        }        
        if(cnt == ind2){
            el2 = a[i];
        }
        cnt++;
        i++;
    }

    while( j < n2 ){
        if(cnt == ind1){
            el1 = b[j];
        }         
        if(cnt == ind2){
            el2 = b[j];
        }
        cnt++;
        j++;
    }

    if(n%2 == 1){
        return (double)el2;
    }

   return (double)((double)(el1 + el2)) / 2.0;
}

int main(){
    vector<int> a = {1,2};
    vector<int> b = {3,4};
    double res = medianBetter(a,b);
    cout << res << endl;
}