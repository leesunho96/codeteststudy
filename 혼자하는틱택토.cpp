/*https://school.programmers.co.kr/learn/courses/30/lessons/160585
 *
 *문제 설명
틱택토는 두 사람이 하는 게임으로 처음에 3x3의 빈칸으로 이루어진 게임판에 선공이 "O", 후공이 "X"를 번갈아가면서 빈칸에 표시하는 게임입니다. 가로, 세로, 대각선으로 3개가 같은 표시가 만들어지면 같은 표시를 만든 사람이 승리하고 게임이 종료되며 9칸이 모두 차서 더 이상 표시를 할 수 없는 경우에는 무승부로 게임이 종료됩니다.

할 일이 없어 한가한 머쓱이는 두 사람이 하는 게임인 틱택토를 다음과 같이 혼자서 하려고 합니다.

혼자서 선공과 후공을 둘 다 맡는다.
틱택토 게임을 시작한 후 "O"와 "X"를 혼자서 번갈아 가면서 표시를 하면서 진행한다.
틱택토는 단순한 규칙으로 게임이 금방 끝나기에 머쓱이는 한 게임이 종료되면 다시 3x3 빈칸을 그린 뒤 다시 게임을 반복했습니다. 그렇게 틱택토 수 십 판을 했더니 머쓱이는 게임 도중에 다음과 같이 규칙을 어기는 실수를 했을 수도 있습니다.

"O"를 표시할 차례인데 "X"를 표시하거나 반대로 "X"를 표시할 차례인데 "O"를 표시한다.
선공이나 후공이 승리해서 게임이 종료되었음에도 그 게임을 진행한다.
게임 도중 게임판을 본 어느 순간 머쓱이는 본인이 실수를 했는지 의문이 생겼습니다. 혼자서 틱택토를 했기에 게임하는 과정을 지켜본 사람이 없어 이를 알 수는 없습니다. 그러나 게임판만 봤을 때 실제로 틱택토 규칙을 지켜서 진행했을 때 나올 수 있는 상황인지는 판단할 수 있을 것 같고 문제가 없다면 게임을 이어서 하려고 합니다.

머쓱이가 혼자서 게임을 진행하다 의문이 생긴 틱택토 게임판의 정보를 담고 있는 문자열 배열 board가 매개변수로 주어질 때, 이 게임판이 규칙을 지켜서 틱택토를 진행했을 때 나올 수 있는 게임 상황이면 1을 아니라면 0을 return 하는 solution 함수를 작성해 주세요.

제한사항
board의 길이 = board[i]의 길이 = 3
board의 원소는 모두 "O", "X", "."으로만 이루어져 있습니다.
board[i][j]는 i + 1행 j + 1열에 해당하는 칸의 상태를 나타냅니다.
"."은 빈칸을, "O"와 "X"는 해당 문자로 칸이 표시되어 있다는 의미입니다.
입출력 예
board	result
["O.X", ".O.", "..X"]	1
["OOO", "...", "XXX"]	0
["...", ".X.", "..."]	0
["...", "...", "..."]	1
입출력 예 설명
입출력 예 #1

예제 1번의 게임판은 다음과 같습니다.

O.X
.O.
..X
선공 후공이 번갈아가면서 다음과 같이 놓았을 때 이러한 게임판이 나올 수 있습니다.

1행 1열 → 1행 3열 → 2행 2열 → 3행 3열
1행 1열 → 3행 3열 → 2행 2열 → 1행 3열
2행 2열 → 1행 3열 → 1행 1열 → 3행 3열
2행 2열 → 3행 3열 → 1행 1열 → 1행 3열
물론 위와 다르게 머쓱이가 2행 2열에 O, 3행 3열에 X, 1행 3열에 X, 1행 1열에 O 순서로 표시를 해서 실수를 했을 가능성도 있지만 "실수를 했을 가능성이 있는가"를 묻는 게 아닌 "이 게임판이 규칙을 지켜서 진행한 틱택토에서 나올 수 있는 상황인가"를 묻는 문제라는 것에 유의해주세요. 따라서 1을 return 합니다.

입출력 예 #2

예제 2번의 게임판은 다음과 같습니다.

OOO
...
XXX
규칙을 지켜서 진행한 틱택토라면 선공과 후공이 번갈아가면서 각각 1행, 3행 중 두 칸씩에 표시를 한 뒤 5번째 차례에 선공이 1행에 가로로 3개의 O를 완성했을 때 종료되므로 적어도 머쓱이가 게임이 종료된 후에도 계속 진행하는 실수를 했다는 것을 추론해 볼 수 있고, 정상적인 틱택토에서는 이러한 상황이 나올 수 없습니다. 따라서 0을 return 합니다.

입출력 예 #3

예제 3번은 2행 2열에만 X가 표시가 되어있습니다. 선공 O 표시가 없이 X만 있으므로 머쓱이가 O를 표시해야 할 때 X를 표시하는 실수를 했다는 것을 추론해 볼 수 있고, 규칙을 지켜서 진행했을 때는 이러한 상황이 나올 수 없습니다. 따라서 0을 return 합니다.
입출력 예 #4

예제 4번은 빈 3x3 게임판입니다. 선공이 아직 빈칸에 표시하기 전에 이러한 상황이 나올 수 있습니다. 따라서 1을 return 합니다.
 */

#include "stdafx.h"

using INDEX = pair<int, int>;
int solution(vector<string> board)
{
    // Values
	constexpr int width = 3;
    constexpr int height = 3;

    int ONUM = 0;
    int XNUM = 0;
	
	int OWinNum = 0;
	int XWinNum = 0;

	int stoneNum = ONUM + XNUM;

    vector<pair<char, int>> results;

    // SetValues.
	{
	    auto GetWinnerWinNum = [&](const INDEX& base, const vector<INDEX>& directions )
	    {
		    const auto [height, width] = base;
	        const auto idxVal = board[height][width];
	        int winCase = 0;
	        for (auto direction : directions)
	        {
		        const auto& [directionHeight, directionWidth] = direction;
	            const char val1 = board[height + directionHeight][width + directionWidth];
	            const char val2 = board[height + directionHeight * 2][width + directionWidth * 2];

	            if(val1 == val2 && idxVal == val1)
					winCase ++;
	        }

	        if(winCase == 0)
				return pair<char, int>('.', 0);

	        else
				return pair<char, int>(idxVal, winCase);
	    };

	    for (auto str : board)
	    {
	        for (auto c : str)
	        {
	            if (c == 'O')
	                ONUM++;
	            else if (c == 'X')
	                XNUM++;
	        }
	    }

		// INDEX(1, 0) INDEX(1, 1), INDEX(0, 1)  0, 0
		{
			vector<INDEX> directions { INDEX(1, 0), INDEX(1, 1), INDEX(0, 1) };
			results.push_back(GetWinnerWinNum(INDEX(0, 0), directions));
		}

	    // INDEX(1, 0) 0, 1
		{
	        vector<INDEX> directions{ INDEX(1, 0)};
	        results.push_back(GetWinnerWinNum(INDEX(0, 1), directions));
		}

	    // INDEX(1, 0) 0, 2
		{
	        vector<INDEX> directions{ INDEX(1, 0)};
	        results.push_back(GetWinnerWinNum(INDEX(0, 2), directions));
		}    

		// INDEX(0, 1) 1, 0
		{
	        vector<INDEX> directions{ INDEX(0, 1) };
	        results.push_back(GetWinnerWinNum(INDEX(1, 0), directions));
		}

	    // INDEX(0, 1), INDEX(-1, 1) 2, 0
	    {
			vector<INDEX> directions{ INDEX(0, 1), INDEX(-1, 1) };
			results.push_back(GetWinnerWinNum(INDEX(2, 0), directions));
	    }


		for (const auto& result : results)
		{
			const auto [winChar, winNum] = result;

			if(winChar == '.')
				continue;

			if(winChar == 'O')
			{
				OWinNum += winNum;				
			}
			else if(winChar == 'X')
			{
				XWinNum += winNum;
			}
		}

    }




	/*
	 *O의 갯수보다 X의 갯수가 더 많다 or O의 갯수 - X의 갯수 가 1보다 크다
	 *	1-1. 게임이 끝났는데(9개 모두 표시) O의 갯수 - X의 갯수 = 1이 아니다

	 *O, X 모두가 3개 줄이 만들어져 있다(즉, 3개 줄이 각각 하나씩 있다 - 한꺼번에 줄 2개가 동시에 생기는 경우 - 가운데로 끝내는 경우 - 가 있으므로 카운트 2로는 부족)
	 
	 *O로 게임이 끝났는데 O의 갯수와 X의 갯수가 같다 or X로 게임이 끝났는데 O의 갯수가 더 많다
	 
	 */
	// Return
	{
		// 선공은 무조건 후공보다 하나 많거나 동일해야함
		int differ = ONUM - XNUM;
		if(ONUM < XNUM || !IsInRange<int>(differ, 1))
			return 0;

		// 돌이 꽉찼는데 선공이 하나 더 많지 않은 경우.
		if(stoneNum == 9 && differ != 1)
			return 0;
		// 선공도 이기고, 후공도 이긴 경우
		if(OWinNum > 0 && XWinNum > 0)
			return 0;
		// 선공이 이겼는데 선공의 개수가 하나 더 많지 않은 경우
		if(OWinNum > 0 && differ != 1)
			return 0;
		// 후공이 이겼는데 선후공 개수가 동일하지 않은경우
		if(XWinNum > 0 && differ != 0)
			return 0;
	}

    return 1; 
}

int main()
{
	vector<pair<vector<string>, bool>> data_set = 
	{
       {{"OXO", "XOX", "OXO"}, true}, // 0
       {{"OOX", "XXO", "OOX"}, true}, // 1
       {{"XXX", ".OO", "O.."}, true}, // 2
       {{"OX.", ".O.", ".XO"}, true}, // 3
       {{"...", "...", ".O."}, true}, // 4
       {{"X.X", "X.O", "O.O"}, true}, // 5
       {{"XO.", "OXO", "XOX"}, true}, // 6
       {{"OOO", "XOX", "XXO"}, true}, // 7
       {{"OOO", "XOX", "X.X"}, false}, // 8
       {{"XXX", "OO.", "OO."}, false}, // 9
       {{".X.", "...", "..."}, false}, // 10
       {{".X.", "X..", ".O."}, false}, // 11
       {{"XOX", "OXO", "XOX"}, false}, // 12
       {{"XXX", "XOO", "OOO"}, false}, // 13
       {{"OOX", "OXO", "XOO"}, false}, // 14
       {{"OOX", "OXO", "XOX"}, false}, // 15
       {{".OX", "OXO", "XO."}, false}, // 16
       {{"OOO", "XX.", "X.."}, false}, // 17
    };
    for (int i = 0; i < data_set.size(); i++) 
    {
        cout <<"case" << i << " : "<< (solution(data_set[i].first) == data_set[i].second) << endl;
    }
    
}