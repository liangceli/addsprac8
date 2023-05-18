#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <cmath>
#include <utility>

template <typename T>
class Heap {
 private:
  std::vector<T> values;
  void heapify(int);

 public:
  Heap();
  Heap(std::vector<T>);

  void insert(T);
  void remove(T);
  T getMin();
};

template <typename T>
Heap<T>::Heap() {}

template <typename T>
Heap<T>::Heap(std::vector<T> start_values) {
  for (int i = 0; i < start_values.size(); i++) {
    values.push_back(start_values.at(i));
  }

  int initial_parent_index = floor(values.size() / 2) - 1;
  for (int parent_index = initial_parent_index; parent_index >= 0; parent_index--) {
    heapify(parent_index);
  }
}

template <typename T>
void Heap<T>::insert(T value) {
  values.push_back(value);
  int new_index = values.size() - 1;
  int parent_index = floor((new_index - 1) / 2);
  while (parent_index >= 0 && values.at(new_index) < values.at(parent_index)) {
    std::swap(values.at(new_index), values.at(parent_index));
    int temp = new_index;
    new_index = parent_index;
    parent_index = floor((temp - 1) / 2);
  }
}

template <typename T>
void Heap<T>::remove(T value) {
  int idx = -1;
  for (int i = 0; i < values.size(); i++) {
    if (values.at(i) == value) {
      idx = i;
      break;
    }
  }
  if (idx == -1) {
    return;
  }

  int left_child_idx = idx * 2 + 1;
  int right_child_idx = idx * 2 + 2;

  if (left_child_idx >= values.size() || right_child_idx >= values.size()) {
    values.at(idx) = values.at(values.size() - 1);
    values.pop_back();
    heapify(idx);
    return;
  }

  T& left_child = values.at(left_child_idx);
  T& right_child = values.at(right_child_idx);
  T& target = values.at(idx);

  if (left_child <= right_child) {
    target = left_child;
    remove(left_child);
  } else {
    target = right_child;
    remove(right_child);
  }
}

template <typename T>
T Heap<T>::getMin() {
  if (values.empty()) {
    throw std::logic_error("Heap is empty.");
  }
  return values.at(0);
}

template <typename T>
void Heap<T>::heapify(int parent_index) {
  if (parent_index < 0 || parent_index >= values.size()) {
    return;
  }

  int left_child_index = parent_index * 2 + 1;
  int right_child_index = parent_index * 2 + 2;

  int index_of_smallest = parent_index;

  if (left_child_index < values.size() && values.at(left_child_index) < values.at(index_of_smallest)) {
    index_of_smallest = left_child_index;
  }

  if (right_child_index < values.size() && values.at(right_child_index) < values.at(index_of_smallest)) {
    index_of_smallest = right_child_index;
  }

  if (index_of_smallest != parent_index) {
    std::swap(values.at(parent_index), values.at(index_of_smallest));
    heapify(index_of_smallest);
  }
}

#endif
