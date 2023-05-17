#include <iostream>
#include <queue>
using namespace std;

int main() {
    // 定义一个priority_queue，存放整数类型，从小到大排序
    priority_queue<int, vector<int>, greater<int> > pq;

    // 插入元素
    pq.push(1);
    pq.push(1);
    pq.push(1);
    pq.push(3);
    pq.push(4);
    pq.push(2);
    pq.push(1);

    // 输出队列中的元素
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}
