#include <iostream>
#include <vector>
using namespace std;

long long MaxNum;
int countNum = 0;

bool valid_num(long long Number){
    return Number<=MaxNum?true:false;
}

void create_vec(long long Num, vector<long long> &V)
{
    long long roll_Num = Num;
    V.push_back(1);
    while(roll_Num < MaxNum)
    {
        V.push_back(roll_Num);
        roll_Num*=Num;
    }
}

int main()
{
    cout<< "Input the MaxNum(1 -- 1000000000000): ";
    cin >> MaxNum;
    getchar();
    vector <long long> Vec_3, Vec_5, Vec_7;

    create_vec(3, Vec_3);
    create_vec(5, Vec_5);
    create_vec(7, Vec_7);
    
    for(int i=0; i<Vec_3.size(); i++)
    {
        for(int j=0; j<Vec_5.size(); j++){
            int k=0;
            while(k<Vec_7.size() && valid_num(Vec_3.at(i) * Vec_5.at(j) * Vec_7.at(k))){
                cout << countNum <<": " << Vec_3.at(i) * Vec_5.at(j) * Vec_7.at(k) << endl;
                ++countNum;
                ++k;
            }
        }
    }
    countNum--;
    cout << "Luchy Number count: " << countNum;
    getchar();
    return 0;
}
