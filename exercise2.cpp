//
// main.cpp
// Cpp
// 
// Created by jy_Dong
//

#include<iostream>

using namespace std;

// calculate x^n
double power(double x, int n){
    double val = 1;
    while (n--) // n \neq 0 : ture; n = 0 : false
        val = x * val;
    return val;
}

int main(){
    /*
    cout << "5 to the power 2 is " << power(5,2) << endl;
    return 0;
    */
    char array[9];
    cin.get(array,9);
    // cout << int(array[1]) << endl;
    int ans = 0;
    for (int i = 0; i < 8; i++){
        if (array[i] == '1'){
            ans = ans + power(2,7-i);
        }
    }
    cout << ans << endl;
    return 0;
}