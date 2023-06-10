// Searching on a B+ tree in C++
#include <iostream>
#include "BPtree.cpp"

using namespace std;

// 定義學生結構體  
struct Student{  
  string studentID;  
  string courseID;  
  string courseName;   
};  

int main() {

  Student s1 = {"1", "11", "Computer Science"};
  Student s2 = {"2", "22", "Math"};
  Student s3 = {"3", "33", "English"};
  Student s4 = {"4", "44", "History"};
  Student s5 = {"5", "55", "Geography"};
  Student s6 = {"6", "66", "Physics"};
  Student s7 = {"7", "77", "Chemistry"};
  Student s8 = {"8", "88", "Biology"};
  

  BPTree node;
  node.insert(1);
  node.insert(2);
  node.insert(3);
  node.insert(4);
  node.insert(5);
  node.insert(6);
  node.insert(7);
  node.insert(8);

  // cout<<node.getRoot()->key[0]<<endl;
  
  node.display(node.getRoot());

  node.search(15);
}