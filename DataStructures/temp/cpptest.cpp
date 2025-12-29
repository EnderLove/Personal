#include <iostream>

using namespace std;

void changePP(int **ppint){
    int *n = new int;
    *n = 9;
    *ppint = n;
    //delete n;
}

int main(){
    int **ppint = nullptr;
    int *p = new int;
    *p = 4;
    ppint = &p;

    cout << **ppint << endl;
    changePP(ppint);
    cout << **ppint << endl;
}




