#include<bits/stdc++.h>
using namespace std;

vector<int> scores_of_books;
int days;
set<int> s;
class library
{
public:
    vector<int> books_library_have;
    int books,id,sign_up,shipping_days;
    void read(int itsid)
    {
        int random;
        id = itsid;
        cin>>books>>sign_up>>shipping_days;
        for(int i=0;i<books;i++){
            cin>>random;
            books_library_have.push_back(random);
        }
        for(int i=0;i<books;i++){
            for(int j=i+1;j<books;j++){
                if(scores_of_books[books_library_have[i]] < scores_of_books[books_library_have[j]]){
                    swap(books_library_have[i],books_library_have[j]);
                }
            }
        }
    }
};

class output
{
public:
    int id;
    vector<int> books_signed;  
    void ans()
    {
        cout<<id<<" "<<books_signed.size()<<endl;
        for(int i=0;i<books_signed.size();i++){
            cout<<books_signed[i]<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    int books,libraries,random;
    cin>>books>>libraries>>days;
    for(int i=0;i<books;i++){
        cin>>random;
        scores_of_books.push_back(random);
    }
    library lb[libraries];
    for(int i=0;i<libraries;i++){
        lb[i].read(i);
    }
    for(int i=0;i<libraries;i++){
        for(int j=i+1;j<libraries;j++){
            if(lb[i].sign_up > lb[j].sign_up){
                swap(lb[i],lb[j]);
            }
        }
    }
    int i,library_signed=0;
    output ot[libraries];
    vector<vector<int>> answer;
    for(i=0;i<libraries;i++){
        if(days > lb[i].sign_up){
            library_signed++;
            days = days - lb[i].sign_up;
            ot[i].id = lb[i].id;
            for(int j=0;i<lb[i].sign_up*days;j++){
                if(j < lb[i].books){
                    if (s.find(lb[i].books_library_have[j]) == s.end()){
                        ot[i].books_signed.push_back(lb[i].books_library_have[j]);
                        s.insert(lb[i].books_library_have[j]);
                    }
                }
                else {
                    break;
                }
            }
        }
        else{
            break;
        }
    }
    cout<<library_signed<<endl;
    for(i=0;i<library_signed;i++){
        ot[i].ans();
    }
    set<int>::iterator setIt = s.begin();
    vector<int> ans;
    for(int i=0;i<s.size();i++){
        ans.push_back(scores_of_books[*setIt]);
        setIt++;
    }
    cout<<endl<<"scores ="<<accumulate(ans.begin(),ans.end(),0);
    return 0;
}
