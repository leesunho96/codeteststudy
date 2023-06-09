/*https://school.programmers.co.kr/learn/courses/30/lessons/160585
 *
 *���� ����
ƽ����� �� ����� �ϴ� �������� ó���� 3x3�� ��ĭ���� �̷���� �����ǿ� ������ "O", �İ��� "X"�� �����ư��鼭 ��ĭ�� ǥ���ϴ� �����Դϴ�. ����, ����, �밢������ 3���� ���� ǥ�ð� ��������� ���� ǥ�ø� ���� ����� �¸��ϰ� ������ ����Ǹ� 9ĭ�� ��� ���� �� �̻� ǥ�ø� �� �� ���� ��쿡�� ���ºη� ������ ����˴ϴ�.

�� ���� ���� �Ѱ��� �Ӿ��̴� �� ����� �ϴ� ������ ƽ���並 ������ ���� ȥ�ڼ� �Ϸ��� �մϴ�.

ȥ�ڼ� ������ �İ��� �� �� �ô´�.
ƽ���� ������ ������ �� "O"�� "X"�� ȥ�ڼ� ������ ���鼭 ǥ�ø� �ϸ鼭 �����Ѵ�.
ƽ����� �ܼ��� ��Ģ���� ������ �ݹ� �����⿡ �Ӿ��̴� �� ������ ����Ǹ� �ٽ� 3x3 ��ĭ�� �׸� �� �ٽ� ������ �ݺ��߽��ϴ�. �׷��� ƽ���� �� �� ���� �ߴ��� �Ӿ��̴� ���� ���߿� ������ ���� ��Ģ�� ���� �Ǽ��� ���� ���� �ֽ��ϴ�.

"O"�� ǥ���� �����ε� "X"�� ǥ���ϰų� �ݴ�� "X"�� ǥ���� �����ε� "O"�� ǥ���Ѵ�.
�����̳� �İ��� �¸��ؼ� ������ ����Ǿ������� �� ������ �����Ѵ�.
���� ���� �������� �� ��� ���� �Ӿ��̴� ������ �Ǽ��� �ߴ��� �ǹ��� ������ϴ�. ȥ�ڼ� ƽ���並 �߱⿡ �����ϴ� ������ ���Ѻ� ����� ���� �̸� �� ���� �����ϴ�. �׷��� �����Ǹ� ���� �� ������ ƽ���� ��Ģ�� ���Ѽ� �������� �� ���� �� �ִ� ��Ȳ������ �Ǵ��� �� ���� �� ���� ������ ���ٸ� ������ �̾ �Ϸ��� �մϴ�.

�Ӿ��̰� ȥ�ڼ� ������ �����ϴ� �ǹ��� ���� ƽ���� �������� ������ ��� �ִ� ���ڿ� �迭 board�� �Ű������� �־��� ��, �� �������� ��Ģ�� ���Ѽ� ƽ���並 �������� �� ���� �� �ִ� ���� ��Ȳ�̸� 1�� �ƴ϶�� 0�� return �ϴ� solution �Լ��� �ۼ��� �ּ���.

���ѻ���
board�� ���� = board[i]�� ���� = 3
board�� ���Ҵ� ��� "O", "X", "."���θ� �̷���� �ֽ��ϴ�.
board[i][j]�� i + 1�� j + 1���� �ش��ϴ� ĭ�� ���¸� ��Ÿ���ϴ�.
"."�� ��ĭ��, "O"�� "X"�� �ش� ���ڷ� ĭ�� ǥ�õǾ� �ִٴ� �ǹ��Դϴ�.
����� ��
board	result
["O.X", ".O.", "..X"]	1
["OOO", "...", "XXX"]	0
["...", ".X.", "..."]	0
["...", "...", "..."]	1
����� �� ����
����� �� #1

���� 1���� �������� ������ �����ϴ�.

O.X
.O.
..X
���� �İ��� �����ư��鼭 ������ ���� ������ �� �̷��� �������� ���� �� �ֽ��ϴ�.

1�� 1�� �� 1�� 3�� �� 2�� 2�� �� 3�� 3��
1�� 1�� �� 3�� 3�� �� 2�� 2�� �� 1�� 3��
2�� 2�� �� 1�� 3�� �� 1�� 1�� �� 3�� 3��
2�� 2�� �� 3�� 3�� �� 1�� 1�� �� 1�� 3��
���� ���� �ٸ��� �Ӿ��̰� 2�� 2���� O, 3�� 3���� X, 1�� 3���� X, 1�� 1���� O ������ ǥ�ø� �ؼ� �Ǽ��� ���� ���ɼ��� ������ "�Ǽ��� ���� ���ɼ��� �ִ°�"�� ���� �� �ƴ� "�� �������� ��Ģ�� ���Ѽ� ������ ƽ���信�� ���� �� �ִ� ��Ȳ�ΰ�"�� ���� ������� �Ϳ� �������ּ���. ���� 1�� return �մϴ�.

����� �� #2

���� 2���� �������� ������ �����ϴ�.

OOO
...
XXX
��Ģ�� ���Ѽ� ������ ƽ������ ������ �İ��� �����ư��鼭 ���� 1��, 3�� �� �� ĭ���� ǥ�ø� �� �� 5��° ���ʿ� ������ 1�࿡ ���η� 3���� O�� �ϼ����� �� ����ǹǷ� ��� �Ӿ��̰� ������ ����� �Ŀ��� ��� �����ϴ� �Ǽ��� �ߴٴ� ���� �߷��� �� �� �ְ�, �������� ƽ���信���� �̷��� ��Ȳ�� ���� �� �����ϴ�. ���� 0�� return �մϴ�.

����� �� #3

���� 3���� 2�� 2������ X�� ǥ�ð� �Ǿ��ֽ��ϴ�. ���� O ǥ�ð� ���� X�� �����Ƿ� �Ӿ��̰� O�� ǥ���ؾ� �� �� X�� ǥ���ϴ� �Ǽ��� �ߴٴ� ���� �߷��� �� �� �ְ�, ��Ģ�� ���Ѽ� �������� ���� �̷��� ��Ȳ�� ���� �� �����ϴ�. ���� 0�� return �մϴ�.
����� �� #4

���� 4���� �� 3x3 �������Դϴ�. ������ ���� ��ĭ�� ǥ���ϱ� ���� �̷��� ��Ȳ�� ���� �� �ֽ��ϴ�. ���� 1�� return �մϴ�.
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
	 *O�� �������� X�� ������ �� ���� or O�� ���� - X�� ���� �� 1���� ũ��
	 *	1-1. ������ �����µ�(9�� ��� ǥ��) O�� ���� - X�� ���� = 1�� �ƴϴ�

	 *O, X ��ΰ� 3�� ���� ������� �ִ�(��, 3�� ���� ���� �ϳ��� �ִ� - �Ѳ����� �� 2���� ���ÿ� ����� ��� - ����� ������ ��� - �� �����Ƿ� ī��Ʈ 2�δ� ����)
	 
	 *O�� ������ �����µ� O�� ������ X�� ������ ���� or X�� ������ �����µ� O�� ������ �� ����
	 
	 */
	// Return
	{
		// ������ ������ �İ����� �ϳ� ���ų� �����ؾ���
		int differ = ONUM - XNUM;
		if(ONUM < XNUM || !IsInRange<int>(differ, 1))
			return 0;

		// ���� ��á�µ� ������ �ϳ� �� ���� ���� ���.
		if(stoneNum == 9 && differ != 1)
			return 0;
		// ������ �̱��, �İ��� �̱� ���
		if(OWinNum > 0 && XWinNum > 0)
			return 0;
		// ������ �̰�µ� ������ ������ �ϳ� �� ���� ���� ���
		if(OWinNum > 0 && differ != 1)
			return 0;
		// �İ��� �̰�µ� ���İ� ������ �������� �������
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