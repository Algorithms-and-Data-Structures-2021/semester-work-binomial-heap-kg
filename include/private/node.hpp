#pragma once

namespace itis {

  struct Node final {
   public:
    int key;
    int degree{0};
    Node *p {nullptr};
    Node *child {nullptr};
    Node *sibling {nullptr};

    Node(int key_) : key{k} {}
  };

}
