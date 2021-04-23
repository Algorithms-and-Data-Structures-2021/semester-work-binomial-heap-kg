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

    Node* mergeBinomialTrees(Node *b1, Node *b2) {
      if (b1->data > b2->data)
        std::swap(b1, b2);

      b2->parent = b1;
      b2->sibling = b1->child;
      b1->child = b2;
      b1->degree++;

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

    std::list<Node*> removeMinFromTreeReturnBHeap(Node *tree) {
      std::list<Node*> heap;
      Node *temp = tree->child;
      Node *lo;

      while (temp) {
        lo = temp;
        temp = temp->sibling;
        lo->sibling = nullptr;
        heap.push_front(lo);
      }
      return heap;
    }

    Node* detMin(std::list<Node*> _heap) {
      std::list<Node*>::iterator it = _heap.begin();
      Node *temp = *it;
      while (it != _heap.end()) {
        if ((*it)->data < temp->data)
          temp = *it;
        it++;
      }
      return temp;
    }

    void printTree(Node *h) {
      while (h) {
        std::cout << h->data << " ";
        printTree(h->child);
        h = h->sibling;
      }
    }

    void printHeap(std::list<Node*> _heap) {
      std::list<Node*>::iterator  it;
      it = _heap.begin();
      while (it != _heap.begin()) {
        printTree(*it);
        it++;
      }
    }
    // Tip 2: На начальном этапе разработки структуры данных можете определения методов задавать в
    // заголовочном файле, как только работа будет завершена, можно будет оставить здесь только объявления.

    int size() const {
      return size_;
    }
  };

}  // namespace itis