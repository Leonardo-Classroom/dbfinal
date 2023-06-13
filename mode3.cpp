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

        //關鍵字搜尋
        //加pause
        //第幾位學生，有幾位學生
        vector<vector<string>> couid_std;
        // cout<<couid_std.size()<<endl;
        // couid_std[i][0]=="";
        // couid_std[i].push

        // if (str.find(str2) != string::npos) {
        //         //.. found.
        // } 
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
                // for(int i=0;i<tokens.size();i++)
                // {
                //     cout<<tokens[i]<<" & ";
                // }
                // cout<<endl;
                //cout<<tokens[0]<<"\t"<<tokens[1]<<"\t"<<tokens[2]<<endl;
                if(tokens[2] == result[0]){
                    // cout<<tokens[1]<<endl;
                    // cout<<"in - Same course name"<<endl;
                    bool exist = false;
                    for(int i=0;i<couid_std.size();i++)
                    {
                        // cout<<"in - vector"<<endl;
                        if(tokens[1]==couid_std[i][0])
                        {
                            // cout<<"add in std_id"<<endl;
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
                        // cout<<"add in course_id"<<endl;
                    }
                    // cout<<tokens[0]<<"\t"<<tokens[1]<<"\t"<<"block["<<result[i]<<"]"<<endl;
                    // if(!isStart){
                    //     cout<<"course_ID\tcourse_Name\n ["<<tokens[1]<<"] \t"<<tokens[2]<<endl;
                    //     isStart=true;
                    //     cout<<"\nstudent_ID\tblock_Num\n"<<endl;
                    // }

                    // isDataExist = 1;
                    // cout<<tokens[0]<<"\t[block "+result[i]+"]"<<endl;
                    // courseId = token[1];
                    //
                }
            }
        }

        for(int i=0;i<couid_std.size();i++)
        {
            cout<<couid_std[i][1]<<" - "<<couid_std[i][0]<<endl;
            // cout<<endl<<"所有修課學生:"<<endl;
            cout<<endl;
            for(int j=2;j<couid_std[i].size();j++)
            {
                cout<<couid_std[i][j]<<"\t"<<couid_std[i][0]<<"\t"<<couid_std[i][1]<<endl;
            }
            cout<<endl;
            // system("pause");
            // system("cls");
        }
    }
    
}