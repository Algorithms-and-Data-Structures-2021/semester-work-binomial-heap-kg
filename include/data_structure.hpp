#pragma once
#include <list>
#include <algorithm>
#include <iostream>
#include <vector>


namespace itis {

  struct Node {
    int data, degree;
    Node *child, *sibling, *parent;

    static Node *newNode(int key);
  };

  struct BinomialHeap {
   public:
    int size_{0};
    int* data_{nullptr};
    std::list<Node*> root_list;

    Node* mergeBinomialTrees(Node *b1, Node *b2);

    BinomialHeap *unionBinomialHeap(BinomialHeap *l1, BinomialHeap *l2);

    BinomialHeap *adjust(BinomialHeap *_heap);

    BinomialHeap *insertATreeInHeap(BinomialHeap *_heap, Node *tree);

    BinomialHeap *insert(BinomialHeap *_heap, int key);

    Node* getMin(BinomialHeap *_heap);

    BinomialHeap *extractMin(BinomialHeap *_heap);

    BinomialHeap *removeMinFromTreeReturnBHeap(Node *tree);

    BinomialHeap *removeHeap(BinomialHeap *heap);

    BinomialHeap *makeHeap(std::vector<int> &input_data);

    void printTree(Node *h);

    void printHeap(BinomialHeap *_heap);

    int size() const {
      return size_;
    }
  };
}
