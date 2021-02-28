#include<bits/stdc++.h>
using namespace std;

int main()
{
    int total_slices,pizzas,random;
    cin>>total_slices>>pizzas;
    vector<int> slices;
    for(int i=0;i<pizzas;i++){
        cin>>random;
        slices.push_back(random);
    }
    vector<int> ans;
    for(int i=slices.size()-1;i>=0;i--){
        if(total_slices >= slices[i]){
            total_slices = total_slices-slices[i];
            ans.push_back(i);
        }
    }
    cout<<ans.size()<<endl;
    vector<int> scores;
    for(int i=ans.size()-1;i>=0;i--){
        scores.push_back(slices[ans[i]]);
        cout<<ans[i]<<" ";
    }
    cout<<endl<<"scores ="<<accumulate(scores.begin(),scores.end(),0);
    
    return 0;
}
