// Searching on a B+ tree in C++
#include "Node.h"

using namespace std;

Node::Node() {
  key = new int[MAX];
  ptr = new Node *[MAX + 1];
}



