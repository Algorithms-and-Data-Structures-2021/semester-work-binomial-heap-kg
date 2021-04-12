#pragma once

#include "private/node.hpp"

// Заголовочный файл с объявлением структуры данных

namespace itis {

  // Tip 1: объявите здесь необходимые структуры, функции, константы и прочее

  // Пример: объявление константы времени компиляции в заголовочном файле
  inline constexpr auto kStringConstant = "Hello, stranger!";

  // Пример: объявление структуры с полями и методами
  struct BinomialHeap {
   public:
    int size_{0};
    int capacity_;
    int* data_{nullptr};
    Node *head_{nullptr};

    // Tip 2: На начальном этапе разработки структуры данных можете определения методов задавать в
    // заголовочном файле, как только работа будет завершена, можно будет оставить здесь только объявления.

    explicit BinomialHeap(int capacity) : capacity_{capacity} {};

    Node *BinomialHeapMinimum(){     // Compare to 0(lg n)
      Node *y = nullptr;
      Node *x = head_;
      int min = 0;
      min = std::numeric_limits<int>::max();
      while (x != nullptr){
        if (x->key < min) {
          min = x->key;
          y = x;
        }
        x = x->sibling;
      }
      return y;
    }

    int size() const {
      return size_;
    }
  };

}  // namespace itis