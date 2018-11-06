#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_COST 2000

using namespace std;

int main(void) {
	int N, M;
	cin >> N >> M;
	
	int min_six = MAX_COST , min_one = MAX_COST;

	for(int m=0; m<M; m++) {
		int six_cost, one_cost;
		cin >> six_cost >> one_cost;
		
		if(min_six > six_cost) min_six = six_cost;
		if(min_one > one_cost) min_one = one_cost;
	}

	int result = 0;
	if(min_six < min_one * 6) {
		if(N >= 6) {
			int remain_N = N % 6;
			result = (N/6)*min_six;
			result += min(remain_N * min_one, min_six);
		}
		else {
			result = min(N * min_one, min_six);
		}
	}
	else {
		result = min_one * N;
	}

	cout << result << endl;
	system("pause");

	return 0;
}
