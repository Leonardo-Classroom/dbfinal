#include <iostream>
#include <fstream>  
#include <sstream>  
#include <string>  
#include <vector> 
#include "RedBlackTree.cpp"

using namespace std;

void mode1(vector<string> result){

    cout<<"mode 1:"<<endl;

    if(result.size()){
        cout<<"result:"<<endl;
        cout<<result[0]<<"> ";
        for(int i=1;i<result.size();i++){
            cout<<result[i]<<" ";
        }
        cout<<endl;
        cout<<"==============="<<endl;

        //寫這邊，result[0]是學號，result[1]...是block，代表在result[0]哪些block中有資料
        //去這些block中找資料，把該學號修的課號跟課名都印出來
    }
}