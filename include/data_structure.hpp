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

    std::list<Node*> unionBionomialHaap(std::list<Node*> l1, std::list<Node*> l2){
      std::list<Node*> _new;
      std::list<Node*>::iterator i1 = l1.begin();
      std::list<Node*>::iterator i2 = l2.begin();
      while(i1 != l1.end() && i2 != l2.end()){
        if((*i1)->degree <= (*i2)->degree){
          _new.push_back(*i1);
          i1++;
        }
        else{
          _new.push_back(*i2);
          i2++;
        }
      }
      while(i1 != l1.end()){
        _new.push_back(*i1);
        i1++;
      }
      while(i2 != l2.end()){
        _new.push_back(*i2);
        i2++;
      }
      return _new;
    }

    std::list<Node*> insertATreeInHeap(std::list<Node*> _heap, Node *tree){
      std::list<Node*> temp;
      temp.push_back(tree);
      temp = unionBionomialHaap(_heap, temp);
      return adjust(temp);
    }

    std::list<Node*> insert(std::list<Node*> _heap, int key){
      Node *temp = newNode(key);
      return insertATreeInHeap(_heap, temp);
    }

    std::list<Node*> extractMin(std::list<Node*> _heap){
      std::list<Node*> new_heap, lo;
      Node *temp;

      temp = getMin(_heap);
      std::list<Node*>::iterator i;
      i = _heap.begin();
      while (i != _heap.end()){
        if(*i != temp){
          new_heap.push_back(*i);
        }
        i++;
      }
      lo = removeMinFromTreeReturnBHeap(temp);
      new_heap = unionBionomialHaap(new_heap, lo);
      new_heap = adjust(new_heap);
      return new_heap;
    }

    // Tip 2: На начальном этапе разработки структуры данных можете определения методов задавать в
    // заголовочном файле, как только работа будет завершена, можно будет оставить здесь только объявления.

    int size() const {
      return size_;
    }
  };

}  // namespace itis