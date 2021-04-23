#pragma once
#include <list>
#include <algorithm>
#include <iostream>
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

    std::list<Node*> unionBinomialHeap(std::list<Node*> l1, std::list<Node*> l2);

    std::list<Node*> adjust(std::list<Node*> _heap);

    std::list<Node*> insertATreeInHeap(std::list<Node*> _heap, Node *tree);

    std::list<Node*> insert(std::list<Node*> _heap, int key);

    Node* getMin(std::list<Node*> _heap);

    std::list<Node*> extractMin(std::list<Node*> _heap);

    std::list<Node*> removeMinFromTreeReturnBHeap(Node *tree);

    void printTree(Node *h);

    void printHeap(std::list<Node*> _heap);
    // Tip 2: На начальном этапе разработки структуры данных можете определения методов задавать в
    // заголовочном файле, как только работа будет завершена, можно будет оставить здесь только объявления.

    int size() const {
      return size_;
    }
  };

}  // namespace itis