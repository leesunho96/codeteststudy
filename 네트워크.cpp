/*
 *https://school.programmers.co.kr/learn/courses/30/lessons/43162
 *
 *���� ����
��Ʈ��ũ�� ��ǻ�� ��ȣ ���� ������ ��ȯ�� �� �ֵ��� ����� ���¸� �ǹ��մϴ�. ���� ���, ��ǻ�� A�� ��ǻ�� B�� ���������� ����Ǿ��ְ�, ��ǻ�� B�� ��ǻ�� C�� ���������� ����Ǿ� ���� �� ��ǻ�� A�� ��ǻ�� C�� ���������� ����Ǿ� ������ ��ȯ�� �� �ֽ��ϴ�. ���� ��ǻ�� A, B, C�� ��� ���� ��Ʈ��ũ �� �ִٰ� �� �� �ֽ��ϴ�.

��ǻ���� ���� n, ���ῡ ���� ������ ��� 2���� �迭 computers�� �Ű������� �־��� ��, ��Ʈ��ũ�� ������ return �ϵ��� solution �Լ��� �ۼ��Ͻÿ�.

���ѻ���
��ǻ���� ���� n�� 1 �̻� 200 ������ �ڿ����Դϴ�.
�� ��ǻ�ʹ� 0���� n-1�� ������ ǥ���մϴ�.
i�� ��ǻ�Ϳ� j�� ��ǻ�Ͱ� ����Ǿ� ������ computers{i}{j}�� 1�� ǥ���մϴ�.
computer{i}{i}�� �׻� 1�Դϴ�.
����� ��
n	computers	return
3	{{1, 1, 0}, {1, 1, 0}, {0, 0, 1}}	2
3	{{1, 1, 0}, {1, 1, 1}, {0, 1, 1}}	1
 */

#include "stdafx.h"

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    vector<set<int>> Network(computers.size());

    for (int i = 0; i < computers.size(); i++)
    {
	    Network[i].insert(i);
    }    

    for (int networkIdx = 0; networkIdx < computers.size(); networkIdx++)
    {
		set<set<int>> localNetwork;


        for (int computer = 0; computer < computers[networkIdx].size(); computer++)
        {
	        if(computers[networkIdx][computer] == 1)
				localNetwork.insert(Network[computer]);
        }


        auto baseNetwork = *localNetwork.begin();

        for (auto a : localNetwork)
			baseNetwork.merge(a);

        for (auto a : baseNetwork)
			Network[a] = baseNetwork;

    }



    set<set<int>> link;
    for (auto a : Network)
		link.insert(a);

    answer = link.size();
    return answer;
}


int main()
{
	vector<vector<int>> input = { {{1, 1, 0},{1, 1, 0},{0, 0, 1}} };

    //vector<vector<int>> input = { {1, 1, 0},{1, 1, 1},{0, 1, 1} };
    cout << solution(input.size(), input);

}
