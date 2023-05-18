

/*int kth_largest(vector<int> values, int k){ //k indicates the k'th larges.  For example, if k is 2, then we return the second largest, if k is 5, we return the 5th largest.
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
}*/

#include <queue>
#include <vector>

int kth_largest(std::vector<int> values, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    // add elements to the priority queue
    for (int val : values) {
        pq.push(val);
        // if the priority queue has more than k elements, remove the smallest element
        if (pq.size() > k) {
            pq.pop();
        }
    }

    // the kth largest element is at the top of the priority queue
    return pq.top();
}

