#pragma once
#include <list>

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
    int capacity_{0};
    int* data_{nullptr};

    // Tip 2: На начальном этапе разработки структуры данных можете определения методов задавать в
    // заголовочном файле, как только работа будет завершена, можно будет оставить здесь только объявления.

    int size() const {
      return size_;
    }
  };

}  // namespace itis