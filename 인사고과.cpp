#include "stdafx.h"
#define TUPLE tuple<int, int>




int solution(vector<vector<int>> scores) {
	int answer = 0;


	TUPLE wanho = make_tuple(scores[0][0], scores[0][1]);
	int wanhoSum = get<0>(wanho) + get<1>(wanho);

	auto compare = [&](vector<int>& v1, vector<int>& v2)
	{
		auto [v1x, v1y] = v1;
		auto [v2x, v2y] = v2;


		if(v1x > v2x)
			return true;
		if(v1x == v2x)
			return v1y > v2y;
		return false;
	};


	return answer;
}


int main()
{
	vector<vector<int>> input = {{2,2},{1,4},{3,2},{3,2},{2,1}};
	cout << solution(input);
}


//int desc_asc(const void* lhs, const void* rhs) {
//	int * const *l = lhs, *const *r = rhs;
//	int * const l_arr = *l, *const r_arr = *r;
//	if (l_arr[0] > r_arr[0])
//		return -1;
//	if (l_arr[0] == r_arr[0]) {
//		if (l_arr[1] < r_arr[1]) {
//			return -1;
//		}
//		else if (l_arr[1] == r_arr[1]) {
//			return 0;
//		}
//	}
//	return 1;
//}
//
//// scores_rows는 2차원 배열 scores의 행 길이, scores_cols는 2차원 배열 scores의 열 길이입니다.
//int solution(int** scores, size_t scores_rows, size_t scores_cols) {
//	int wanho_a = scores[0][0], wanho_b = scores[0][1];
//	qsort(scores, scores_rows, sizeof scores[0], desc_asc);
//	int wanho_sum = wanho_a + wanho_b, max_comp = 0, answer = 1;
//	for (int i = 0; i < scores_rows; i++) {
//		int* s = scores[i];
//		if (wanho_a < s[0] && wanho_b < s[1])
//			return -1;
//		if (max_comp <= s[1]) {
//			if (s[0] + s[1] > wanho_sum)
//				answer++;
//			max_comp = s[1];
//		}
//	}
//	return answer;
//}