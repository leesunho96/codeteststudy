﻿/*
 *
 https://school.programmers.co.kr/learn/courses/30/lessons/133500

 등대
문제 설명
인천 앞바다에는 1부터 n까지 서로 다른 번호가 매겨진 등대 n개가 존재합니다. 등대와 등대 사이를 오가는 뱃길이 n-1개 존재하여, 어느 등대에서 출발해도 다른 모든 등대까지 이동할 수 있습니다. 등대 관리자 윤성이는 전력을 아끼기 위하여, 이 중 몇 개의 등대만 켜 두려고 합니다. 하지만 등대를 아무렇게나 꺼버리면, 뱃길을 오가는 배들이 위험할 수 있습니다. 한 뱃길의 양쪽 끝 등대 중 적어도 하나는 켜져 있도록 등대를 켜 두어야 합니다.

예를 들어, 아래 그림과 같이 등대 8개와 7개의 뱃길들이 있다고 합시다. 이 경우 1번 등대와 5번 등대 두 개만 켜 두어도 모든 뱃길은 양쪽 끝 등대 중 하나가 켜져 있으므로, 배들은 안전하게 운항할 수 있습니다.

image7_1.PNG

등대의 개수 n과 각 뱃길이 연결된 등대의 번호를 담은 이차원 배열 lighthouse가 매개변수로 주어집니다. 윤성이가 켜 두어야 하는 등대 개수의 최솟값을 return 하도록 solution 함수를 작성해주세요.

제한사항
2 ≤ n ≤ 100,000
lighthouse의 길이 = n – 1
lighthouse 배열의 각 행 [a, b]는 a번 등대와 b번 등대가 뱃길로 연결되어 있다는 의미입니다.
1 ≤ a ≠ b ≤ n
모든 등대는 서로 다른 등대로 이동할 수 있는 뱃길이 존재하도록 입력이 주어집니다.
입출력 예
n	lighthouse	result
8	[[1, 2], [1, 3], [1, 4], [1, 5], [5, 6], [5, 7], [5, 8]]	2
10	[[4, 1], [5, 1], [5, 6], [7, 6], [1, 2], [1, 3], [6, 8], [2, 9], [9, 10]]	3
입출력 예 설명
입출력 예 #1

본문에서 설명한 예시입니다.
입출력 예 #2

뱃길은 아래 그림과 같이 연결되어 있습니다. 윤성이가 이중 1, 6, 9번 등대 3개만 켜 두어도 모든 뱃길은 양쪽 끝 등대 중 하나가 켜져 있게 되고, 이때의 등대 개수 3개가 최소가 됩니다.
image7_2.PNG
 */

#include "stdafx.h"

#define MAX 100001

using namespace std;

int solution(int n, vector<vector<int>> lighthouse) {
    vector<vector<int>> info(n + 1);

    int answer = 0;
    bool isLightOn[MAX] = { 0 }; // 불이 켜진 등대인지 체크


    for (int i = 0; i < lighthouse.size(); i++) {
        info[lighthouse[i][0]].push_back(lighthouse[i][1]);
        info[lighthouse[i][1]].push_back(lighthouse[i][0]);
    }

    function<void(int, int)> dfs = [&](int node, int parent) mutable
    {
        for (int i = 0; i < info[node].size(); i++) 
        {
            if (info[node][i] != parent) 
            {
                dfs(info[node][i], node);

                // 자식과 부모 등대 모두 불이 꺼져 있다면 부모 등대 불 켜주기
                if (!isLightOn[info[node][i]] && !isLightOn[node]) 
                {
                    isLightOn[node] = true;
                    answer++;
                }
            }
        }
    };

    // 트리이기 때문에 1부터 시작
    dfs(1, 1);

    return answer;
}
int main()
{
    vector < tuple<int, vector<vector<int>>, int>> testCases
    {
        {8 ,{{1, 2},{1, 3},{1, 4},{1, 5},{5, 6},{5, 7},{5, 8}}, 2},
        {10,{{4, 1},{5, 1},{5, 6},{7, 6},{1, 2},{1, 3},{6, 8},{2, 9},{9, 10}}, 3}
    };


    for (const auto& testCase : testCases)
    {
        const auto& [node, link, expectedResult] = testCase;

        TestFunction(solution, tuple<int, vector<vector<int>>>(node, link), expectedResult);
    }
}