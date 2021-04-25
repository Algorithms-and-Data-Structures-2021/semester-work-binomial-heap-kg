#include "data_structure.hpp"
#include <iostream>

// файл с определениями

namespace itis {

  // здесь должны быть определения методов вашей структуры
  Node *Node::newNode(int key) {
    Node *temp = new Node;
    temp->data = key;
    temp->degree = 0;
    temp->child = nullptr;
    temp->parent = nullptr;
    temp->sibling = nullptr;
    return temp;
  }

  Node *BinomialHeap::mergeBinomialTrees(Node *b1, Node *b2) {
    if (b1->data > b2->data) {
      std::swap(b1, b2);
    }

    b2->parent = b1;
    b2->sibling = b1->child;
    b1->child = b2;
    b1->degree++;
    return b1;
  }

  BinomialHeap *BinomialHeap::unionBinomialHeap(BinomialHeap* l1, BinomialHeap *l2) {
    BinomialHeap *_new = new BinomialHeap();
    std::list<Node*>::iterator i1 = l1->root_list.begin();
    std::list<Node*>::iterator i2 = l2->root_list.begin();
    while(i1 != l1->root_list.end() && i2 != l2->root_list.end()){
      if((*i1)->degree <= (*i2)->degree){
        _new->root_list.push_back(*i1);
        i1++;
      }
      else{
        _new->root_list.push_back(*i2);
        i2++;
      }
    }
    while(i1 != l1->root_list.end()){
      _new->root_list.push_back(*i1);
      i1++;
    }
    while(i2 != l2->root_list.end()){
      _new->root_list.push_back(*i2);
      i2++;
    }
    return _new;
  }

  BinomialHeap *BinomialHeap::adjust(BinomialHeap *_heap) {
    if (_heap->root_list.size() <= 1)
      return _heap;
    // std::list<Node*> new_heap;
    std::list<Node*>::iterator it1, it2, it3;
    it1 = it2 = it3 = _heap->root_list.begin();

    if (_heap->root_list.size() == 2) {
      it2 = it1;
      it2++;
      it3 = _heap->root_list.end();
    } else {
      it2++;
      it3 = it2;
      it3++;
    }
    while (it1 != _heap->root_list.end()) {
      if (it2 == _heap->root_list.end())
        it1++;
      else if ((*it1)->degree < (*it2)->degree) {
        it1++;
        it2++;
        if (it3 != _heap->root_list.end())
          it3++;
      }
      else if (it3 != _heap->root_list.end() &&
               (*it1)->degree == (*it2)->degree &&
               (*it1)->degree == (*it3)->degree) {
        it1++;
        it2++;
        it3++;
      }
      else if ((*it1)->degree == (*it2)->degree) {
        *it1 = mergeBinomialTrees(*it1, *it2);
        it2 = _heap->root_list.erase(it2);
        if (it3 != _heap->root_list.end())
          it3++;
      }
    }
    return _heap;
  }

  BinomialHeap *BinomialHeap::insertATreeInHeap(BinomialHeap* _heap, Node *tree) {
    BinomialHeap *temp = new BinomialHeap();
    temp->root_list.push_back(tree);
    BinomialHeap *united_heap = unionBinomialHeap(_heap, temp);
    return adjust(united_heap);
  }

  BinomialHeap *BinomialHeap::insert(BinomialHeap* _heap, int key) {
    Node *temp = Node::newNode(key);
    return insertATreeInHeap(_heap, temp);
  }

  Node *BinomialHeap::getMin(BinomialHeap *_heap) {
    std::list<Node*>::iterator it = _heap->root_list.begin();
    Node *temp = *it;
    while (it != _heap->root_list.end()) {
      if ((*it)->data < temp->data)
        temp = *it;
      it++;
    }
    return temp;
  }

  BinomialHeap *BinomialHeap::extractMin(BinomialHeap *_heap) {
    BinomialHeap *new_heap = new BinomialHeap();
    BinomialHeap *lo = new BinomialHeap();
    Node *temp;

    temp = getMin(_heap);
    std::list<Node*>::iterator i;
    i = _heap->root_list.begin();
    while (i != _heap->root_list.end()){
      if(*i != temp){
        new_heap->root_list.push_back(*i);
      }
      i++;
    }
    lo = removeMinFromTreeReturnBHeap(temp);
    new_heap = unionBinomialHeap(new_heap, lo);
    new_heap = adjust(new_heap);
    delete temp;
    return new_heap;
  }

  BinomialHeap *BinomialHeap::removeMinFromTreeReturnBHeap(Node *tree) {
    BinomialHeap *heap = new BinomialHeap();
    Node *temp = tree->child;
    Node *lo;

    while (temp) {
      lo = temp;
      temp = temp->sibling;
      lo->sibling = nullptr;
      heap->root_list.push_front(lo);
    }
    return heap;
  }

  BinomialHeap *BinomialHeap::removeHeap(BinomialHeap *heap) {
    while (!heap->root_list.empty()) {
      heap = heap->extractMin(heap);
    }
    return heap;
  }

  BinomialHeap *BinomialHeap::makeHeap(BinomialHeap *former_heap, std::vector<int> &input_data) {
    // BinomialHeap *heap = new BinomialHeap();
    for (int &number: input_data) {
      former_heap = former_heap->insert(former_heap, number);
    }
    return former_heap;
  }

  void BinomialHeap::printTree(Node *h) {
    while (h) {
      std::cout << "| " << h->data << " " << "degree: " << h->degree << " |    ";
      printTree(h->child);
      h = h->sibling;
    }
  }

  void BinomialHeap::printHeap(BinomialHeap *_heap) {
    std::list<Node*>::iterator  it;
    it = _heap->root_list.begin();
    while (it != _heap->root_list.end()) {
      printTree(*it);
      it++;
    }
    std::cout << std::endl;
  }
}  // namespace itis
