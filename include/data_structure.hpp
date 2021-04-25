#pragma once
#include <list>
#include <algorithm>
#include <iostream>
#include <vector>
// Заголовочный файл с объявлением структуры данных

namespace itis {

  // Tip 1: объявите здесь необходимые структуры, функции, константы и прочее

  // Пример: объявление константы времени компиляции в заголовочном файле
//  inline constexpr auto kStringConstant = "Hello, stranger!";

  struct Node {
    int data, degree;
    Node *child, *sibling, *parent;

    static Node *newNode(int key);
  };

  // Пример: объявление структуры с полями и методами
  struct BinomialHeap {
   public:
    int size_{0};
//    int capacity_{0};
    int* data_{nullptr};
    std::list<Node*> root_list;

//    static std::list<Node*> make(){
//      std::list<Node*> root_list{nullptr};
//    }

    Node* mergeBinomialTrees(Node *b1, Node *b2);

    BinomialHeap *unionBinomialHeap(BinomialHeap *l1, BinomialHeap *l2);

    BinomialHeap *adjust(BinomialHeap *_heap);

    BinomialHeap *insertATreeInHeap(BinomialHeap *_heap, Node *tree);

    BinomialHeap *insert(BinomialHeap *_heap, int key);

    Node* getMin(BinomialHeap *_heap);

    BinomialHeap *extractMin(BinomialHeap *_heap);

    BinomialHeap *removeMinFromTreeReturnBHeap(Node *tree);

    BinomialHeap *removeHeap(BinomialHeap *heap);

    BinomialHeap *makeHeap(std::vector<int> input_data);

    void printTree(Node *h);

    void printHeap(BinomialHeap *_heap);
    // Tip 2: На начальном этапе разработки структуры данных можете определения методов задавать в
    // заголовочном файле, как только работа будет завершена, можно будет оставить здесь только объявления.

    int size() const {
      return size_;
    }
  };

}  // namespace itis