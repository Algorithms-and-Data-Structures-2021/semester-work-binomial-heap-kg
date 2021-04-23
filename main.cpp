#include <iostream>

#include "data_structure.hpp"

using namespace std;

int main(int argc, char *argv[]) {
  for (int index = 0; index < argc; index++) {
    cout << index << ": " << argv[index] << endl;
  }
//  int ch, key;
//  std::list<itis::Node*> _heap;

  itis::BinomialHeap main_heap = itis::BinomialHeap();

  // auto _heap = itis::BinomialHeap();
  main_heap.insert(&main_heap, 1);
  main_heap.insert(&main_heap, 2);
  main_heap.insert(&main_heap, 3);

//  _heap.root_list = _heap.insert(_heap.root_list, 1);
//  _heap.root_list = _heap.insert(_heap.root_list, 2);
//  _heap.root_list = _heap.insert(_heap.root_list, 3);
//  std::cout << "heap" << std::endl;
//  _heap.printHeap(_heap.root_list);

  main_heap.printHeap(&main_heap);

//  itis::Node *temp = _heap.getMin(_heap.root_list);
//  std::cout << temp->data << std::endl;
  return 0;
}