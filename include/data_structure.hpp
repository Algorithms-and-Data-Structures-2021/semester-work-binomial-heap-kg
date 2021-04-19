#pragma once
#include <algorithm>

// Заголовочный файл с объявлением структуры данных

namespace itis {

  // Tip 1: объявите здесь необходимые структуры, функции, константы и прочее

  // Пример: объявление константы времени компиляции в заголовочном файле
  // inline constexpr auto kStringConstant = "Hello, stranger!";

  struct Node {
    int data;
    int degree;
    Node *child;
    Node *sibling;
    Node *parent;
  };

  Node* newNode(int key) {
    Node *temp = new Node;
    temp->data = key;
    temp->degree = 0;
    temp->child = nullptr;
    temp->parent = nullptr;
    temp->sibling = nullptr;
    return temp;
  }

  // Пример: объявление структуры с полями и методами
  struct MyStructure {
   public:
    int size_{0};
    int capacity_{0};
    Node *root_list{nullptr};
    // int* data_{nullptr};

    // Tip 2: На начальном этапе разработки структуры данных можете определения методов задавать в
    // заголовочном файле, как только работа будет завершена, можно будет оставить здесь только объявления.
    Node *mergeBinomialTrees(Node *b1, Node *b2) {
      if (b1->data > b2->data){
        Node *temp = b1;
        b1 = b2;
        b2 = temp;
      }
      b2->parent = b1;
      b2->sibling = b1->child;
      b1->child = b2;
      b1->degree++;

      return b1;
    }

    MyStructure* unionBinomialHeap(MyStructure *l1, MyStructure *l2) {}

    int size() const {
      return size_;
    }
  };

}  // namespace itis