#include <iostream>
#include <fstream>  
#include <sstream>  
#include <string>  
#include <vector> 
#include "RedBlackTree.cpp"

using namespace std;

void mode3(vector<string> result){

    cout<<"mode 3:"<<endl;

    if(result.size()){
        cout<<"result:"<<endl;
        cout<<result[0]<<"> ";
        for(int i=1;i<result.size();i++){
            cout<<result[i]<<" ";
        }
        cout<<endl;
        cout<<"==============="<<endl;

        //寫這邊，result[0]是課名，result[1]...是block，代表在result[0]哪些block中有資料
        //去這些block中找資料，把該課名的課號跟學生都印出來，
        //注意，不同課號可能有相同課名，要分開印出
    }
    
}