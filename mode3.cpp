#include <iostream>
#include <fstream>  
#include <sstream>  
#include <string>  
#include <vector>
#include <algorithm> 
#include "RedBlackTree.cpp"

using namespace std;

vector<string> split3(const string& s, char delimiter) {  
    vector<string> tokens;  
    string token;  
    istringstream tokenStream(s);  
    while (getline(tokenStream, token, delimiter)) {  
        tokens.push_back(token);  
    }
    return tokens;  
}

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

        vector<vector<string>> couid_std;
        for(int i=1;i<result.size();i++)
        {
            // cout<<"check block["<<i<<"]"<<endl;
            string f_name = "blocks/block"+result[i]+".csv"; //第一個block/為路徑//之後為檔名
            ifstream file(f_name);
            string line;
            getline (file,line);
            while(getline (file,line))
            {
                vector<string> tokens=split3(line, ',');
                if(tokens[2] == result[0]){
                    bool exist = false;
                    for(int i=0;i<couid_std.size();i++)
                    {
                        if(tokens[1]==couid_std[i][0])
                        {
                            exist = true;
                            couid_std[i].push_back(tokens[0]);
                        }
                    }
                    if(exist == false)
                    {
                        vector<string> tmp;
                        tmp.push_back(tokens[1]);
                        tmp.push_back(tokens[2]);
                        tmp.push_back(tokens[0]);
                        couid_std.push_back(tmp);
                    }
                }
            }
        }
        int sort_num[couid_std.size()];
        for(int i=0;i<couid_std.size();i++)
        {
            sort_num[i]=stoi(couid_std[i][0]);
        }

        for(int i=0;i<couid_std.size()-1;i++)//Sort the sequence
        {
            for(int j=0;j<couid_std.size()-i-1;j++)
            {
                if(sort_num[j]>sort_num[j+1])
                {
                    int temp;
                    temp = sort_num[j];
                    sort_num[j] = sort_num[j+1];
                    sort_num[j+1]=temp;
                }
            }
        }

        // for(int k=0;k<couid_std.size();k++)//test
        // {
        //     cout<<sort_num[k]<<endl;
        // }

        for(int k=0;k<couid_std.size();k++)//print the srudents page by page
        {
            for(int i=0;i<couid_std.size();i++)
            {
                if(sort_num[k]==stoi(couid_std[i][0]))
                {
                    cout<<couid_std[i][1]<<" - "<<couid_std[i][0]<<endl;
                    cout<<endl;
                    cout<<"Student Id"<<"\t"<<"Course Id"<<"\t"<<"Course Name"<<endl;
                    for(int j=2;j<couid_std[i].size();j++)
                    {
                        cout<<couid_std[i][j]<<"\t"<<couid_std[i][0]<<"\t\t"<<couid_std[i][1]<<endl;
                    }
                    cout<<"Total number: "<<couid_std[i].size()-2<<endl;
                    cout<<endl;
                    cout<<"Page: "<<k+1<<"/"<<couid_std.size()<<endl;
                    system("pause");
                    system("cls");
                    break;
                }
            }
        }
    }
}