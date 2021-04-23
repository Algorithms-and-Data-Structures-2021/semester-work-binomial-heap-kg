#pragma once
#include <list>
#include <algorithm>

// Заголовочный файл с объявлением структуры данных

namespace itis {

  // Tip 1: объявите здесь необходимые структуры, функции, константы и прочее

  // Пример: объявление константы времени компиляции в заголовочном файле
//  inline constexpr auto kStringConstant = "Hello, stranger!";

  struct Node {
    int data, degree;
    Node *child, *sibling, *parent;

    Node *newNode(int key) {
      Node *temp = new Node;
      temp->data = key;
      temp->degree = 0;
      temp->child = temp->parent = temp->sibling = nullptr;
      return temp;
    }
  };

  // Пример: объявление структуры с полями и методами
  struct MyStructure {
   public:
    int size_{0};
//    int capacity_{0};
    int* data_{nullptr};
    std::list<Node*> root_list;

    Node* mergeBinomialTrees(Node *n1, Node *n2){
      if (n1->data > n2->data){
        std::swap(n1, n2);
      }
      n2->parent = n1;
      n2->sibling = n1->child;
      n1->child = n2;
      n1->degree++;

      return n1;
    }



    // Tip 2: На начальном этапе разработки структуры данных можете определения методов задавать в
    // заголовочном файле, как только работа будет завершена, можно будет оставить здесь только объявления.

    int size() const {
      return size_;
    }
  };

}  // namespace itis