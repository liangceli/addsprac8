#include <vector>
#include <queue>
#include <iostream>
using namespace std;


int kth_largest(vector<int> values, int k){ //k indicates the k'th larges.  For example, if k is 2, then we return the second largest, if k is 5, we return the 5th largest.
    int target;

    priority_queue<int> maxpq;
        for(int i=0; i<values.size(); i++){
            maxpq.push(values.at(i));
        }
        for(int j=1; j<=(k-1); j++){
            maxpq.pop();
        }
        target=maxpq.top();
        return target;
}


