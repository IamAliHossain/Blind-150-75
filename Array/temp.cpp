#include "bits/stdc++.h"
using namespace std;

int main(){
        
    int a = 2, b = 1, c = 2 , d = 3;
    if(a < 1 || b == a){
        a += c;
    }
    else{
        a += b;
    }
    if(a > b || a == b){
        a += b ;
    }
    else{
        a += c ;
    }
    cout << a << " " << b << endl;

    switch(a){
        a++;
        case(2):
            a ++;
        case(3):
            a++;
        case(4):
            a++;
        default:
            a++;
            break;
        a++;

    }
    cout << a << " " << b << endl;

    return 0 ;
}






