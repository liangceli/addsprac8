#include <vector>
#include <iostream>
using namespace std;

int main() {
    std::vector<int> vec;
     vec.push_back(0);
     vec.push_back(2);
     vec.push_back(3);
     vec.push_back(4);
     vec.push_back(5);

    auto it = vec.begin() + 2; // 获取第三个元素的位置
    vec.erase(it); // 删除第三个元素

    std::cout << "Vector after deletion: ";
    for (int val : vec) {
        if(vec.at(0)==0){
            throw logic_error("Heap is empty.");
        }
        std::cout << val << " ";
    }
    
    return 0;
}
