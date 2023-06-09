#ifndef BALANCED_TREE_H  
#define BALANCED_TREE_H  
  
#include <iostream>  
#include <vector>  
#include <map>  
  
class BalancedTreeIndex {  
private:  
    std::map<std::string, std::vector<std::string>> index;  
  
public:  
    // 插入索引  
    void insert(const std::string& key, const std::string& value) {  
        index[key].push_back(value);  
    }  
  
    // 搜尋索引  
    std::vector<std::string> search(const std::string& key) {  
        if (index.find(key) != index.end()) {  
            return index[key];  
        } else {  
            return std::vector<std::string>();  
        }  
    }  
};  
  
#endif  
