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

  return 0;
}