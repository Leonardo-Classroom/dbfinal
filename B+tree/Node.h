// Searching on a B+ tree in C++
#include <climits>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;
int MAX = 3;

// BP node
class Node {

    public:
        bool IS_LEAF;
        int *key;
        int size;
        Node **ptr;

        Node();
};

