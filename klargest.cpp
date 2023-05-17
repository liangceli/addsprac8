#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class klargest{
    private:
    vector<int> values;

    public:
    klargest();
    //klargest(vector<int> curr_values);
    int kth_largest(vector<int> values, int k);
};

klargest :: klargest(){}
/*klargest :: klargest(vector<int> curr_values){
    for(int i=0; i<curr_values.size(); i++){
        values.push_back(curr_values.at(i));     
    }
}*/

int klargest :: kth_largest(vector<int> values, int k){ //k indicates the k'th larges.  For example, if k is 2, then we return the second largest, if k is 5, we return the 5th largest.

//两种情况：1.minheap 2.maxheap
//判断进来的values是minheap还是maxheap
//为避免特殊情况 判断是minheap还是maxheap的方法：看此heap的parent和child之间有没有大小关系 只要有一处大小关系，就可以判断出这个heap是什么heap
bool isminheap=false;
bool ismaxheap=false;
int parent=values.at(0);
int child=values.at(1);
for(int i=0; i<values.size(); i++){
    if(values.at(i)<values.at(2*i+1) || values.at(i)<values.at(2*i+2)){
        isminheap=true;
        break;
    }else if(values.at(i)>values.at(2*i+1) || values.at(i)>values.at(2*i+2)){
        ismaxheap=true;
        break;
    }else{
        isminheap=true;
        ismaxheap=true;
    }
}

int target;
//当是minheap的时候
if(isminheap==true){ //当是minheap的时候 优先级是小
    priority_queue<int, vector<int>, greater<int> > minpq;
    for(int i=0; i<values.size(); i++){
         minpq.push(values.at(i));
    }
     for(int l=0; l<k; l++){
        minpq.pop();
    }
    target=minpq.top();
    return target;
}else if(ismaxheap==true){ //当是maxheap的时候 优先级是大
    priority_queue<int> maxpq;
    for(int i=0; i<values.size(); i++){
        maxpq.push(values.at(i));
    }
    for(int j=0; j<k; j++){
        maxpq.pop();
    }
    target=maxpq.top();
    return target;
}else{ //当既是maxheap也是minheap的时候(heap里面的数都相等)
return -1;
}

}

/*int main(){
    vector<int> min;
    min.push_back(1);
    min.push_back(1);
    min.push_back(1);
    min.push_back(3);
    min.push_back(4);
    min.push_back(2);
    min.push_back(1);

    vector<int> max;
    max.push_back(5);
    max.push_back(5);
    max.push_back(5);
    max.push_back(3);
    max.push_back(4);
    max.push_back(2);
    max.push_back(5);

    vector<int> non;
    non.push_back(1);
    non.push_back(1);
    non.push_back(1);
    non.push_back(1);
    non.push_back(1);
    non.push_back(1);
    non.push_back(1);

    klargest k;
    cout<<k.kth_largest(min,2);
    cout<<k.kth_largest(max,2);
    cout<<k.kth_largest(non,2);
    return 0;
}*/