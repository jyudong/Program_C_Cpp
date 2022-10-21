//
// main.cpp
// Cpp
// 
// Created by jy_Dong
//
// 数组Z字形排列

#include<iostream>
#include<cstring>

using namespace std;

int main(){
    char array[40]; // = "3 abc.sjtu.edu.cn";
    cin.get(array, 35);

    int row;
    int space;
    int a, b;
    if (array[1] == ' '){
        row = array[0] - '0'; // number of row;
        cout << row << endl;
        space = 2;
    }
    else{
        a = array[0] - '0'; // 十位数
        b = array[1] - '0'; // 个位数
        row = 10*a+b;
        space = 3;
    }

    int length = 20;
    char c[length][length]; // initialize row * col char matrix;
    for (int l=0; l<length; l++){
        for (int s=0; s<length; s++){
            c[l][s] = '\0';
        }
    }

    int i = 0; // vertical or not index; 区分竖直向下放置还是斜着放置
    int j = 0; // group index; 确定列坐标
    int total = 0; // number of character used; 总共放置了多少个元素

    // reset
    while (total < strlen(array)){
        if (i == 0)
        {
            for (int num_row=0; num_row<row; num_row++){
                c[num_row][j*(row-1)] = array[total + space];
                total += 1;
                if (total >= strlen(array) - space){
                break; // 如果放置元素超过总元素数目，跳出循环
                }
            }
            if (total >= strlen(array) - space){
                break; // 同上
            }
            i = 1;
        }
        if (i != 0)
        {
            for (int num_row=0; num_row<row-2; num_row++){
                c[row-2-num_row][j*(row-1) + num_row+1] = array[total+space];
                total += 1;
                if (total >= strlen(array) - space){
                break;
                }
            }
            if (total >= strlen(array) - space){
                break;
            }
            i = 0;
            j = j+1;
        }
    }

    // output
    for (int l=0; l<15; l++){
        for (int s=0; s<15; s++){
            if (c[l][s] != '\0'){
                printf("%c", c[l][s]);
            }
        }
    }

    return 0;
}