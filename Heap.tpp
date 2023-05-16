#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <cmath> // for floor()
#include <utility>

//min heap
template <typename T>
class Heap {
 private:
  std::vector<T> values;
  void heapify(int);

 public:
  Heap();  // constructs an empty heap

  // constructs a heap with the values from the given vector
  // the type T MUST provide comparison operators <, >, ==
  Heap(std::vector<T>);

  void insert(T);
  void remove(T);
  T getMin();
};

/*******************************/
// default constructor
/*******************************/

template <typename T>
Heap<T>::Heap() {}

/*******************************/
// constructs a heap with the values in the given vector
// the type T MUST provide comparison operators <, >, ==
/*******************************/

template <typename T>
Heap<T>::Heap(std::vector<T> start_values) {
  // copy the values into our heap vector
  for (int i = 0; i < start_values.size(); i++) {
    values.push_back(start_values.at(i));
  }

  // starting from last non-leaf node (last parent), heapify each
  // of the parents
  int initial_parent_index = floor(values.size() / 2) - 1;
  for (int parent_index = initial_parent_index; parent_index >= 0; parent_index--) {
    heapify(parent_index);
  }
}

/*******************************/
// add values to the heap
/*******************************/

template <typename T>
void Heap<T>::insert(T value) {
   // TO BE IMPLEMENTED
   //插到vector的最后一个元素 用pushback
   //建立whileloop
   //找出这个元素的index，从而找到它的parent
   //和它的parent进行比较，
   //如果它比parent小，swap它和它的parent
   //如果swap的话，和parent的parent比较，如果还小，继续swap，直到root，
   //considering worst case 不断减小index直到index小于零
   values.push_back(value);
   int new_index=values.size()-1;
   int parent_index=floor((new_index-1)/2);
   while(parent_index>=0){
    if(values.at(new_index)<values.at(parent_index)){
        T temp=values.at(new_index);
        values.at(new_index)=values.at(parent_index);
        values.at(parent_index)=temp;
        //swap(values.at(new_index),values.at(parent_index));
        int temp=new_index;
        new_index=parent_index;
        parent_index=floor((temp-1)/2);
    }
   }
}

/*******************************/
/* delete values from the heap */
/*******************************/

template <typename T>
void Heap<T>::remove(T value) {
  // TO BE IMPLEMENTED
  //如何在vector中找到value（从左边数的第一个）得到index
  int idx;
  for(int i=0; i<values.size(); i++){
    idx++;
    if(values.at(i)==value){
        break;
    }
  }
  //要被删除的如果没有children 直接删除就好了
  int leftchild_idx=idx*2+1;
  int rightchild_idx=idx*2+2;
  if(leftchild_idx>=values.size()|| rightchild_idx>=values.size()){
    auto it=values.begin()+idx;
    values.erase(it);
  }
  //被删除的时候这个value被最下层的最右边的value（也就是最后一个元素）所替代
  T original_last_value=values.at(values.size()-1);
  value=original_last_value;
  //删除最后一个元素用popback（）
  values.pop_back(values.at(values.size()-1));
  //替换之后，将被替换之后的元素和左子元素进行调换
  swap(values.at(leftchild_idx),values.at(idx));
}

/*******************************/
// find the smallest value in the heap
/*******************************/

template <typename T>
T Heap<T>::getMin() { 
  // TO BE IMPLEMENTED
  /*if (values.empty()) {
    throw std::logic_error("Heap is empty.");
    cout<<"Heap is empty.";
  }*/
  return values.at(0);
}

/*******************************/
// private function to heapify a given 'node'
/*******************************/

template <typename T>
void Heap<T>::heapify(int parent_index) {
  // if we're outside the index range, return
  if (parent_index < 0 || parent_index >= values.size()) return;

  // find children indexes
  int left_child_index = parent_index * 2 + 1;
  int right_child_index = parent_index * 2 + 2;

  // if parent is larger than child, swap with smallest child
  int index_of_smallest = parent_index;

  // check if left child exists and if exists, is smallest value there
  if (left_child_index < values.size() &&
      values.at(left_child_index) < values.at(index_of_smallest)) {
    // make this index the current smallest
    index_of_smallest = left_child_index;
  }

  // check if left child exists and if exists, is smallest value there
  if (right_child_index < values.size() &&
      values.at(right_child_index) < values.at(index_of_smallest)) {
    // make this index the current smallest
    index_of_smallest = right_child_index;
  }

  // if parent is not smallest, swap with smallest child
  if (index_of_smallest != parent_index) {
    T temp = values.at(parent_index);
    values.at(parent_index) = values.at(index_of_smallest);
    values.at(index_of_smallest) = temp;
  }

  // move up the 'tree' to grandparent
  int grandparent = floor(parent_index/2) - 1;
  heapify(grandparent);
}

#endif