#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Item{
   int value;
   int weight;
};

bool compare(Item a, Item b){
   double r1 = (double) a.value / (double) a.weight; //calculating val/wt for item a
   double r2 = (double) b.value / (double) b.weight; //calculating val/wt for item b
   return r1 > r2;
}

int fractionalKnapSack(vector<Item> items, int capacity){
   int n = items.size();

   sort(items.begin(), items.end(), compare);

   int value = 0;
   for(int i = 0; i<n; i++){

      if(capacity >= items[i].weight){
         value = value + items[i].value;
         capacity = capacity - items[i].weight;
      }
      else{
         double fraction = ((double) items[i].value / items[i].weight) * capacity;
         value = value + fraction;
         break; //in case of fractional addition, the bag is full so just break.
      }
   }

   return value;
}

int main() {
    vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};
    int capacity = 50;

    cout << "Maximum value in knapsack = " << fractionalKnapSack(items, capacity) << endl;

    return 0;
}