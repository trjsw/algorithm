#include <iostream>
#include <vector>

using namespace std;

long long steps(int n){
    if(n==1)
        return 1;
    else if(n==2)
        return 2;
    else if(n==3)
        return 4;
    else
    {
        return (0ll + steps(n-1) + steps(n-2) + steps(n-3)) % ((long long)1e9+7);
    }
}

int main(){
    int n;
    cout << "Input stairs number: ";
    cin >> n;
    getchar();
    int x = steps(n);
    cout << "Way to target: " << steps(n) << endl;
    getchar();
    return 0;
}