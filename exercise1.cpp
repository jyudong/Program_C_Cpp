//
// main.cpp
// Cpp
// 
// Created by jy_Dong
//

#include<iostream>
#include<cstring>

using namespace std;

int main(){
	char array[100];
	cin.get(array, 80);
	char test;
	cin >> test;
	int ans = -1;
	for (int i = 0; i < strlen(array); i++)
	{
		if (test == array[i])
		{
			ans = i;
		}
	}
	if (ans == -1)
	{
		cout << "Not Found" ;
	}
	else 
	{
		cout << ans;
	}
}
