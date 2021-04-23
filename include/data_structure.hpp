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
//    int* data_{nullptr};
    std::list<Node *> root_list;

    Node* mergeBinomialTrees(Node *b1, Node *b2) {
      if (b1->data > b2->data)
        std::swap(b1, b2);

      b2->parent = b1;
      b2->sibling = b1->child;
      b1->child = b2;
      b1->degree++;

      return b1;
    }

    std::list<Node*> adjust(std::list<Node*> _heap) {
      if (_heap.size() <= 1)
        return _heap;
      std::list<Node*> new_heap;
      std::list<Node*>::iterator it1, it2, it3;
      it1 = it2 = it3 = _heap.begin();

      if (_heap.size() == 2) {
        it2 = it2;
        it2++;
        it3 = _heap.end();
      } else {
        it2++;
        it3 = it2;
        it3++;
      }
      while (it1 != _heap.end()) {
        if (it2 == _heap.end())
          it1++;
        else if ((*it1)->degree < (*it2)->degree) {
          it1++;
          it2++;
          if (it3 != _heap.end())
            it3++;
        }
        else if (it3 != _heap.end() &&
            (*it1)->degree == (*it2)->degree &&
            (*it1)->degree == (*it3)->degree) {
          it1++;
          it2++;
          it3++;
        }
        else if ((*it1)->degree == (*it2)->degree) {
          Node *temp;  // can it be deleted?
          *it1 = mergeBinomialTrees(*it1, *it2);
          it2 = _heap.erase(it2);
          if (it3 != _heap.end())
            it3++;
        }
      }
      return _heap;
    }

    // Tip 2: На начальном этапе разработки структуры данных можете определения методов задавать в
    // заголовочном файле, как только работа будет завершена, можно будет оставить здесь только объявления.

    int size() const {
      return size_;
    }
  };

}  // namespace itis