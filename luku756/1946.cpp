#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>

//https://www.acmicpc.net/problem/1946
/*
서류점수와 면접점수 중 하나가 다른이보다 커야 한다.
서류점수를 기준으로 정렬하여 번호를 매기면, 나보다 상위에 있는 사람중에 나의 면접점수보다 점수가 높은 이가 있어서는 안된다.
그러므로 위에서부터 내려오면서 그중에 가장 높은 점수(가장 높은 등수) 를 기록해 두고, 그보다 나의 등수가 높으면 합격이다.

만약 면접점수가 1인 사람이 나타날 경우 그 아래는 반드시 그보다 서류점수와 면접점수가 낮으므로 계산을 끝내면 된다.

사람 수는 최대 100000으로, n^2 타임으로 정렬을 해서는 안된다.
들어오는 입력은 빈칸이 없는 int 이므로, counting sort를 이용하여 입력만 받는 중에 정렬 가능하다.

counting sort -> 서류점수를 인덱스로, 면접점수를 값으로 하는 배열을 사용한다.

*/

using namespace std;

int score[1000001];//인덱스 - 서류점수, 값 - 면접점수. 정렬된 값으로 들어온다. n 타임 정렬
int main() {

	int T;
	int N, L;

	cin >> T;
	while(T--) {

		cin >> N;	//입력 받기
		int a,b;
		for(int i=0; i<N; i++) {
			cin >> a >> b;
			score[a-1] = b;
		}


		int cnt = 1;
		int log=score[0];	//나보다 서류점수가 높은이 중 면접 최대 점수. 초기값은 서류점수 1등의 점수

		for(int i=1; i<N; i++) {

			if(score[i] < log) {
				log = score[i];
				cnt++;

				if(log == 1)//1등이 나왔으면 하위는 무조건 서류와 면접 점수가 낮다.
					break;
			}
		}


		cout << cnt << endl;
	}

	return 0;
}
