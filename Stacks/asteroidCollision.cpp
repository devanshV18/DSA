#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<vector>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
         stack<int> s;
    
    for (int ast : asteroids) {
        bool exploded = false;
        
        // Process collisions only if the stack is non-empty and a collision is possible (i.e., stack top is positive and current asteroid is negative)
        while (!s.empty() && s.top() > 0 && ast < 0) {
            if (s.top() < -ast) {
                s.pop(); // The positive asteroid is smaller, it explodes
            } else if (s.top() == -ast) {
                s.pop(); // Both asteroids are the same size, both explode
                exploded = true;
                break;
            } else {
                exploded = true; // The positive asteroid is larger, the current one explodes
                break;
            }
        }

        if (!exploded) {
            s.push(ast); // If it didn't explode, push it onto the stack
        }
    }

    // Retrieve the remaining asteroids from the stack
    vector<int> result(s.size());
    for(int i = s.size() - 1; i >= 0; --i) {
        result[i] = s.top();
        s.pop();
    }

    return result; 
}

int main(){
    vector<int> asteroids = {5, 10, -5};
    vector<int> result = asteroidCollision(asteroids);
    
    // Print the result
    for (int ast : result) {
        cout << ast << " ";
    }
    
    return 0;
}