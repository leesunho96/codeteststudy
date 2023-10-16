/*
 *https://school.programmers.co.kr/learn/courses/30/lessons/42860
 *
문제 설명
조이스틱으로 알파벳 이름을 완성하세요. 맨 처음엔 A로만 이루어져 있습니다.
ex) 완성해야 하는 이름이 세 글자면 AAA, 네 글자면 AAAA

조이스틱을 각 방향으로 움직이면 아래와 같습니다.

▲ - 다음 알파벳
▼ - 이전 알파벳 (A에서 아래쪽으로 이동하면 Z로)
◀ - 커서를 왼쪽으로 이동 (첫 번째 위치에서 왼쪽으로 이동하면 마지막 문자에 커서)
▶ - 커서를 오른쪽으로 이동 (마지막 위치에서 오른쪽으로 이동하면 첫 번째 문자에 커서)
예를 들어 아래의 방법으로 "JAZ"를 만들 수 있습니다.

- 첫 번째 위치에서 조이스틱을 위로 9번 조작하여 J를 완성합니다.
- 조이스틱을 왼쪽으로 1번 조작하여 커서를 마지막 문자 위치로 이동시킵니다.
- 마지막 위치에서 조이스틱을 아래로 1번 조작하여 Z를 완성합니다.
따라서 11번 이동시켜 "JAZ"를 만들 수 있고, 이때가 최소 이동입니다.
만들고자 하는 이름 name이 매개변수로 주어질 때, 이름에 대해 조이스틱 조작 횟수의 최솟값을 return 하도록 solution 함수를 만드세요.

제한 사항
name은 알파벳 대문자로만 이루어져 있습니다.
name의 길이는 1 이상 20 이하입니다.
입출력 예
name	return
"JEROEN"	56
"JAN"	23
 */




#include "stdafx.h"
#define DEBUG_MODE 1



// 레버를 좌/우로 이동시 a로 돌아가는 것을 모르고, 유지하는 것을 가정으로 문제 해결. 문제를 잘못 읽음.
namespace MissUnderstanding
{
/*
 * get<0>(result) : targetIdx
 * get<1>(result) : moveNumber
 */
CheckDesc GetMinDesc(const int presentIndex, const string presentString, const string compareString, const vector<bool>& sameIDX)
{
	CheckDesc result(0, numeric_limits<int>::max());
	vector<int> validIdx;
	const char& presentChar = presentString.at(presentIndex);

	auto GetMinNum = [&](const char& c)
	{
		const int&& up = c - presentChar;
		const int&& down = abs(26 + presentChar - c);

		return up > down ? down : up;
	};

	auto GetMinIndex = [&](const string& pStr, const int& presentIdx, const int& targetIndex )
	{
		const int&& strSize = pStr.length();

		const int&& direct = abs(presentIndex - targetIndex);
		const int&& round = abs(presentIndex - targetIndex + strSize);

		return min(direct, round);
	};

	for (int i = 0; i < sameIDX.size(); i++)
	{
		if(!sameIDX.at(i))
			validIdx.push_back(i);
	}

	int minComp = numeric_limits<int>::max();

#ifdef DEBUG_MODE
	int mvIDX, mvCh;
#endif


	for (const auto idx : validIdx)
	{
		const auto [moveIDX, moveChar] = make_tuple(GetMinIndex(presentString, presentIndex, idx ),  GetMinNum(compareString.at(idx)));
		const auto moveTime = moveIDX + moveChar;

		if(get<1>(result) > moveTime)
		{
			get<1>(result) = moveTime;
			get<0>(result) = idx;

#ifdef DEBUG_MODE
			mvIDX = moveIDX;
			mvCh = moveChar;
#endif
		}
	}
#ifdef DEBUG_MODE
	cout <<"moveIDX : " << mvIDX << ", moveChar : " << mvCh <<  endl;
#endif
	return result;
}

using CheckDesc = tuple<int, int>;
int solution(string name)
{
	int answer = 0;
	int length = name.size();
	string present(length, 'A');
	vector<bool> sameIDX(name.length(), false);
	int presentIndex = 0;
	




	while(!AllSameInContainer<vector<bool>, bool>(sameIDX, true))
	{
#ifdef DEBUG_MODE
		cout << "present IDX : " << presentIndex << ", Alphabet : " << present.at(presentIndex) << endl;
#endif

		auto [targetIDX, moveTime] = GetMinDesc(presentIndex, present, name, sameIDX);


		answer += moveTime;
		present.at(targetIDX) = name.at(targetIDX);
		sameIDX.at(targetIDX) = true;
		presentIndex = targetIDX;
#ifdef DEBUG_MODE
		cout << 	"change IDX : " << presentIndex << ", Alphabet : " << present.at(presentIndex) << ", moveTime : " << moveTime << endl<<endl;
#endif
	}


	return answer;
}
}

struct node
{
	string substr = string();	
	node* next = nullptr;
};
int solution(string name)
{
	vector<int> AIDX;

	for (int i = 0; i < name.length(); i++)
	{
		if(name.at(i) == 'A')
		{
			AIDX.push_back(i);
		}
	}



	

	return 0;
}
int main()
{
	string sinput = "JEROEN";
	cout << solution(sinput);

};