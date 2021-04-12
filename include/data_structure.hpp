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
    int* data_{nullptr};
    Node *head_{nullptr};

    // Tip 2: На начальном этапе разработки структуры данных можете определения методов задавать в
    // заголовочном файле, как только работа будет завершена, можно будет оставить здесь только объявления.

    explicit BinomialHeap() = default;

    /** The running time is O(lg n).
     *
     * @param H is a binomial heap that consists nodes y and z
     * @return a pointer to the node with the minimum key in a binomial heap H
     */
    Node *BinomialHeapMinimum(BinomialHeap H){
      Node *y = nullptr;
      Node *x = H.head_;
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

    /**
     * Makes z the parent of y.
     * Thus, the kye of z must be lower than the key of y.
     * The running time is O(1).
     *
     * @param y is a node with greater key
     * @param z is a node with lower key
     */
    void BinomialLink(Node *y, Node *z) {
      y->p = z;
      y->sibling = z->child;
      z->child = y;
      z->degree++;
    }

    /** The subroutine. It is used within Union method and some other methods.
     * If the root lists of H1 and H2 have m roots altogether, Merge runs in O(m) time.
     *
     * @param H1 is first binomial heap to be merged
     * @param H2 is second binomial heap to be merged
     * @return the pointer to a root list (of a new binomial heap)
     * that is sorted by monotonically increasing degree
     */
    Node *BinomialHeapMerge(BinomialHeap H1, BinomialHeap H2) {
      auto H = BinomialHeap();
      Node *cur_root_H1 = H1.head_;
      Node *cur_root_H2 = H2.head_;
      Node *cur_root_H = head_;

      if ((cur_root_H1 != nullptr) && (cur_root_H2 != nullptr)) {
        if (cur_root_H1->degree < cur_root_H2->degree) {
          H.head_ = cur_root_H1;
          cur_root_H1 = cur_root_H1->sibling;
        } else {
          H.head_ = cur_root_H2;
          cur_root_H2 = cur_root_H2->sibling;
        }
        cur_root_H = head_->sibling;
      }

      while (cur_root_H1 != nullptr || cur_root_H2 != nullptr) {
        if (cur_root_H1->degree < cur_root_H2->degree) {
          cur_root_H = cur_root_H1;
          cur_root_H1 = cur_root_H1->sibling;
        }
        else {
          cur_root_H = cur_root_H2;
          cur_root_H2 = cur_root_H2->sibling;
        }
        cur_root_H = cur_root_H->sibling;
      }

      while (cur_root_H1 != nullptr) {
        cur_root_H = cur_root_H1;
        cur_root_H1 = cur_root_H1->sibling;
        cur_root_H = cur_root_H->sibling;
      }

      while (cur_root_H2 != nullptr) {
        cur_root_H = cur_root_H2;
        cur_root_H2 = cur_root_H2->sibling;
        cur_root_H = cur_root_H->sibling;
      }

      BinomialHeapClear(H1);
      BinomialHeapClear(H2);

      return H.head_;
    }

    BinomialHeap BinomialHeapUnion(BinomialHeap H1, BinomialHeap H2) {
      // TODO: to implement the method using BinomialHeapMerge and some other subroutines
    }

    void BinomialHeapClear(BinomialHeap H) {
      // TODO: to implement a clear of space
    }

    int size() const {
      return size_;
    }
  };

}  // namespace itis