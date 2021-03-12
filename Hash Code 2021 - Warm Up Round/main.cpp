#include<bits/stdc++.h>
using namespace std;
class pizzas
{
public:
    vector<string> ing;
    int id,any;
    void read(int eid)
    {
        id = eid;
        string should;
        cin>>any;
        for(int j=0;j<any;j++){
            cin>>should;
            ing.push_back(should);
        }
    }
};

int main()
{
    int m,t2,t3,t4;
    cin>>m>>t2>>t3>>t4;
    pizzas pz[m];
    vector<vector<int>> output;
    for(int j=0;j<m;j++){
        pz[j].read(j);
    }
    for(int i=0;i<m;i++){
        for(int j=i+1;j<m;j++){
            if(pz[i].any > pz[j].any){
                swap(pz[i],pz[j]);
            }
        }
    }
    int last = m-1,plus=0;
    if(last >= 3){
        for(int j=0;j<t4;j++){
            if(last < 3)
                break;
            vector<int> making;
            making.push_back(4);
            for(int i=4;i>0;i--){
                making.push_back(pz[last].id);
                last--;
            }
        plus++;
            output.push_back(making);
        }
    }
    if(last >= 2){
        for(int j=0;j<t3;j++){
            if(last < 2)
                break;
            vector<int> making;
            making.push_back(3);
            for(int i=3;i>0;i--){
                making.push_back(pz[last].id);
                last--;
            }

        plus++;
            output.push_back(making);
        }
    }
    if(last >= 1){
        for(int j=0;j<t2;j++){
            if(last < 1)
                break;
            vector<int> making;
            making.push_back(2);
            for(int i=2;i>0;i--){
                making.push_back(pz[last].id);
                last--;
            }
            output.push_back(making);

        plus++;
        }
    }
    else{

    }
    cout<<plus<<endl;
    for(int i=0;i<output.size();i++){
        for(int j=0;j<output[i].size();j++){
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}






