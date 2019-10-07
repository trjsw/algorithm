#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

vector<int> Dist = {0,2,5,8,10,14,17,20};
vector<int> choose;

bool CheckDis(int m, int dist){
    if(Dist.size() == 2){
        return (Dist.at(1) - Dist.at(0)) >= dist ? true : false;
    }
    int move_times = 0;
    int before = 0;
    for(auto j=1; j<Dist.size()-1; j++){
        if(move_times>=m)
            return false;
        if (Dist.at(j) - Dist.at(before) >= dist){
            before = j;
        }
        else
        {
            ++move_times;
            choose.at(j) = 0;
        }
    }
    return true;
}


int main(){
    int max_move = 4;
    for( auto iter : Dist)
        cout << iter << " ";
    cout << endl;

    for(auto i=0; i<Dist.size(); i++){
        choose.push_back(1);
    }

    auto x = Dist.at(0);
    for(auto i=0; i<Dist.size(); i++){
        cout << Dist.at(i) - x << " ";
        x = Dist.at(i);
    }
    cout << endl;
    
    // cout<< "The result of CheckDis is:" << (CheckDis(2, 4)==true? "true" : "false") << endl;
    auto start = 0;
    auto end = Dist.at(Dist.size()-1);
    auto max_dist= 0;

    while (start < end)
    {
        for(auto i=0; i<choose.size(); i++)
            choose.at(i) = 1;
        int mid = (end+start)/2;
        if(CheckDis(max_move, mid))
        {
            max_dist = mid;
            start = mid+1;
        }
        else
        {
            end = mid;
        }
    }
    cout << "The max distance is: " << max_dist << endl;
    for(auto it:choose)
        cout << it << " ";
    cout << endl;
}