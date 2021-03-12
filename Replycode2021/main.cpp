#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pairs;
class buildings
{
public:
    int x_coordinates,y_coordinates,latency,connection_speed;
    void read()
    {
        cin>>x_coordinates>>y_coordinates>>latency>>connection_speed;
    }
};

class antinas
{
public:
    int range,connection_speed,id;
    void read(int _id)
    {
        id=_id;
        cin>>range>>connection_speed;
    }
};


int main()
{
    vector< pair <int,int> > vect;
    set<pairs> s;
    int rows,columns,number_of_buildings,number_of_antinas,points;
    cin>>rows>>columns;
    cin>>number_of_buildings>>number_of_antinas>>points;

    buildings bu[number_of_buildings];
    for(int i=0;i<number_of_buildings;i++){
        bu[i].read();
        vect.push_back( make_pair(bu[i].connection_speed, i));
    }
    sort(vect.rbegin(), vect.rend());
    antinas an[number_of_antinas];
    for(int i=0;i<number_of_antinas;i++){
        an[i].read(i);
    }
    for(int i=0;i<number_of_antinas;i++){
        for(int j=i+1;j<number_of_antinas;j++){
            if(an[i].connection_speed> an[j].connection_speed){
                swap(an[i],an[j]);
            }
        }
    }
     

    cout<<number_of_antinas<<endl;
    for(int i=0;i<number_of_antinas;i++){
        cout<<an[i].id<<" "<<bu[vect[i].second].x_coordinates<<" "<<bu[vect[i].second].y_coordinates<<endl;
    }
   
    
    return 0;
}
