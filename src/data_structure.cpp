#include "data_structure.hpp"
#include <iostream>

// файл с определениями

namespace itis {

  // здесь должны быть определения методов вашей структуры
  Node *Node::newNode(int key) {
    Node *temp = new Node;
    temp->data = key;
    temp->degree = 0;
    temp->child = temp->parent = temp->sibling = nullptr;
    return temp;
  }

  Node *BinomialHeap::mergeBinomialTrees(Node *b1, Node *b2) {
    if (b1->data > b2->data) {
      std::swap(b1, b2);

      b2->parent = b1;
      b2->sibling = b1->child;
      b1->child = b2;
      b1->degree++;
    }
    return b1;
  }
  std::list<Node *> BinomialHeap::unionBinomialHeap(std::list<Node *> l1, std::list<Node *> l2) {
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
  std::list<Node *> BinomialHeap::adjust(std::list<Node *> _heap) {
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
//          Node *temp;  // can it be deleted?
        *it1 = mergeBinomialTrees(*it1, *it2);
        it2 = _heap.erase(it2);
        if (it3 != _heap.end())
          it3++;
      }
    }
    return _heap;
  }
  std::list<Node *> BinomialHeap::insertATreeInHeap(std::list<Node *> _heap, Node *tree) {
    std::list<Node*> temp;
    temp.push_back(tree);
    temp = unionBinomialHeap(_heap, temp);
    return adjust(temp);
  }
  std::list<Node *> BinomialHeap::insert(std::list<Node *> _heap, int key) {
    Node *temp = Node::newNode(key);
    return insertATreeInHeap(_heap, temp);
  }
  Node *BinomialHeap::getMin(std::list<Node *> _heap) {
    std::list<Node*>::iterator it = _heap.begin();
    Node *temp = *it;
    while (it != _heap.end()) {
      if ((*it)->data < temp->data)
        temp = *it;
      it++;
    }
    return temp;
  }
  std::list<Node *> BinomialHeap::extractMin(std::list<Node *> _heap) {
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
    new_heap = unionBinomialHeap(new_heap, lo);
    new_heap = adjust(new_heap);
    return new_heap;
  }
  std::list<Node *> BinomialHeap::removeMinFromTreeReturnBHeap(Node *tree) {
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
  void BinomialHeap::printTree(Node *h) {
    while (h) {
      std::cout << h->data << " ";
      printTree(h->child);
      h = h->sibling;
    }
  }
  void BinomialHeap::printHeap(std::list<Node *> _heap) {
    std::list<Node*>::iterator  it;
    it = _heap.begin();
    while (it != _heap.begin()) {
      printTree(*it);
      it++;
    }
  }
}  // namespace itis

//int main(){
////  int ch, key;
////  std::list<itis::Node*> _heap;
//  auto _heap = itis::BinomialHeap();
//  _heap.root_list = _heap.insert(_heap.root_list, 1);
//  _heap.root_list = _heap.insert(_heap.root_list, 2);
//  _heap.root_list = _heap.insert(_heap.root_list, 3);
////  std::cout << "heap" << std::endl;
//  _heap.printHeap(_heap.root_list);
//
//  itis::Node *temp = _heap.getMin(_heap.root_list);
//  std::cout << temp->data << std::endl;
//}