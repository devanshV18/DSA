#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string reverseWords(string s) {

        int cnt=0,cntb=0;
        string res="";
        string w=" ";
        reverse(s.begin(),s.end());
         s+=w;
          reverse(s.begin(),s.end());
         w="";
        for(int i=s.size()-1;i>=0;i--){
            if(cnt==0 && s[i]==' '){

            }
            else if(cnt==0 && s[i]!=' '){
                cnt=1;
                w+=s[i];
                cntb=0;
            }
            else if(cnt==1 && s[i]!=' '){
                if(cntb==1){
                    w=" ";
                    res+=w;
                    w="";
                }
                w+=s[i];
                cntb=0;
            }
            else if(cnt==1 && s[i]==' '){
             reverse(w.begin(),w.end());
             res+=w;
             w=""; 
             cntb=1;
            }
           /* else{
                reverse(w.begin(),w.end());
                res+=w;
            }
           /* else if(cnt==1 && cntb==1 && s[i]!=' '){
                w=" ";
                res+=w;
            }*/
        }
        return res;
    }
};