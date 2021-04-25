#include <iostream>

#include "data_structure.hpp"

using namespace std;

int main(int argc, char *argv[]) {
  for (int index = 0; index < argc; index++) {
    cout << index << ": " << argv[index] << endl;
  }

  itis::BinomialHeap *main_heap = new itis::BinomialHeap();

  main_heap = main_heap->insert(main_heap, 6);
  main_heap = main_heap->insert(main_heap, 1);
  main_heap = main_heap->insert(main_heap, 4);
  main_heap = main_heap->insert(main_heap, 5);
  main_heap = main_heap->insert(main_heap, 8);
  main_heap = main_heap->insert(main_heap, 2);
  main_heap = main_heap->insert(main_heap, 4);
  main_heap = main_heap->insert(main_heap, 3);
  main_heap = main_heap->insert(main_heap, 9);

  main_heap->printHeap(main_heap);
  cout<<"that's all" << endl;
  main_heap = main_heap->removeHeap(main_heap);
  main_heap->printHeap(main_heap);

  vector<int>data_for_heap{6, 1, 4, 5, 8, 2, 4, 3, 9};
  itis::BinomialHeap *main_heap2 = new itis::BinomialHeap();
  main_heap2 = main_heap2->makeHeap(data_for_heap);
  std::cout << "new heap: " << endl;
  main_heap2->printHeap(main_heap2);

  return 0;
}