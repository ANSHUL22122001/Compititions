#include<bits/stdc++.h>
using namespace std;
class developers
{
public:
    long long int id,bonus,skills;
    string company;
    vector<string> skillsofdevelopers;
    void read(long long int _id)
    {
        string random;
        id=_id;
        cin>>company>>bonus>>skills;
        for(long long int i=0;i<skills;i++){
            cin>>random;
            skillsofdevelopers.push_back(random);
        }
    }
};

class projectmanagers
{
public:
    long long int id,bonus,skills;
    string company;
    vector<string> skillsofprojectmanagers;
    void read(long long int _id)
    {
        string random;
        id=_id;
        cin>>company>>bonus;
    }
};

int main()
{
    long long int columns,rows,number_of_developers,number_of_projectmanagers;
    cin>>columns>>rows;
    char floor[rows][columns];
    string useless;
    for(long long int i=0;i<rows;i++){
        cin>>useless;
        for(long long int j=0;j<columns;j++){
            floor[i][j] = useless[j];
        }
    }
    cin>>number_of_developers;
    developers dv[number_of_developers];
    for(long long int i=0;i<number_of_developers;i++){
        dv[i].read(i);
    }
    for(long long int i=0;i<number_of_developers;i++){
        for(long long int j=i+1;j<number_of_developers;j++){
            if(dv[i].company > dv[j].company){
                swap(dv[i], dv[j]);
            }
        }
    }
    cin>>number_of_projectmanagers;
    projectmanagers pm[number_of_projectmanagers];

    for(long long int i=0;i<number_of_projectmanagers;i++){
        pm[i].read(i);
    }
    for(long long int i=0;i<number_of_projectmanagers;i++){
        for(long long int j=i+1;j<number_of_projectmanagers;j++){
            if(pm[i].company > pm[j].company){
                swap(pm[i], pm[j]);
            }
        }
    }
    long long int ans[number_of_developers+number_of_projectmanagers][2];

    for(long long int k=0;k<number_of_developers;k++){
        for(long long int i=0;i<rows;i++){
            for(long long int j=0;j<columns;j++){
                if(floor[i][j] == '_'){
                    ans[dv[k].id][0]=j;
                    ans[dv[k].id][1]=i;
                    floor[i][j] = 'X';
                    goto x;
                }
            }
        }
        ans[dv[k].id][0]=-1;
        ans[dv[k].id][1]=-1;
        x:cout<<"";
    }

    for(long long int k=0;k<number_of_projectmanagers;k++){
        for(long long int i=0;i<rows;i++){
            for(long long int j=0;j<columns;j++){
                if(floor[i][j] == 'M'){
                    ans[number_of_developers+pm[k].id][0]=j;
                    ans[number_of_developers+pm[k].id][1]=i;
                    floor[i][j] = 'X';
                    goto y;
                }
            }
        }
        ans[number_of_developers+pm[k].id][0]=-1;
        ans[number_of_developers+pm[k].id][1]=-1;
        y:cout<<"";
    }

    for(long long int i=0;i<number_of_developers+number_of_projectmanagers;i++){
        if(ans[i][0] == -1){
            cout<<"X";
        }
        else{
            cout<<ans[i][0]<<" "<<ans[i][1];
        }
        cout<<endl;
    }
    return 0;
}
