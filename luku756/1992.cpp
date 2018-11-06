#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<string>

//https://www.acmicpc.net/problem/1992
/*
재귀 방식으로 구현, 전부가 0 혹은 1이면 그대로 기록하고, 아닐 경우 4분할한다.
압축 문자열은 전역변수 string에 기록한다.

*/

using namespace std;

char map[100][100];

string compTextstr;
void compress(int startX, int startY, int len) {



	int cnt[2] ={ 0,0 };

	for(int i = startY; i < startY + len; i++) {

		for(int j = startX; j < startX + len; j++) {
			cnt[map[i][j]-'0']++;

		}
	}

	if(cnt[0] == len*len) {//전부 0
		compTextstr += "0";
	}
	else if(cnt[1] == len*len) {//전부 1
		compTextstr += "1";
	}
	else {
		int half = len/2;
		compTextstr += "(";
		compress(startX, startY, half);
		compress(startX+half, startY, half);
		compress(startX, startY+half, half);
		compress(startX+half, startY+half, half);

		compTextstr += ")";
	}
}

int main() {

	int T;
	int N;


		cin >> N;	//입력 받기
		
		for(int i=0; i<N; i++) {
			getchar();
			for(int j=0; j<N; j++) {

				cin >> map[i][j];
			}
		}
		compTextstr = "";\

		compress(0,0,N);



		cout << compTextstr << endl;
	

	return 0;
}
