/*
 *https://school.programmers.co.kr/learn/courses/30/lessons/1844
 *
 *ROR ������ �� ������ ����� �����ϸ�, ��� �� ������ ���� �ı��ϸ� �̱�� �����Դϴ�. ����, �� ���� ��� �� ������ �ִ��� ���� �����ϴ� ���� �����մϴ�.

���ݺ��� ����� �� ���� ������ �Ǿ� ������ �����Ϸ��� �մϴ�. ������ 5 x 5 ũ���� �ʿ�, ����� ĳ���Ͱ� (��: 1, ��: 1) ��ġ�� �ְ�, ��� �� ������ (��: 5, ��: 5) ��ġ�� �ִ� ����� �����Դϴ�.

�ִܰŸ�1_sxuruo.png

�� �׸����� ������ �κ��� ������ �����־� �� �� ���� ���̸�, ��� �κ��� �� �� �ִ� ���Դϴ�. ĳ���Ͱ� ������ ���� ��, ��, ��, �� �������� �� ĭ�� �̵��ϸ�, ���� ���� ��� ���� �� �� �����ϴ�.
�Ʒ� ���ô� ĳ���Ͱ� ��� �� �������� ���� �� ���� ����� ��Ÿ���� �ֽ��ϴ�.

ù ��° ����� 11���� ĭ�� ������ ��� �� ������ �����߽��ϴ�.
�ִܰŸ�2_hnjd3b.png

�� ��° ����� 15���� ĭ�� ������ ����� ������ �����߽��ϴ�.
�ִܰŸ�3_ntxygd.png

�� ���ÿ����� ù ��° ������� �� ������ ����� ������ �����ϴ� ����� �����Ƿ�, �� ����� ��� �� �������� ���� ���� ���� ����Դϴ�.

����, ��� ���� �ڽ��� �� ���� ������ ���� �����ξ��ٸ� ��� �� ������ �������� ���� ���� �ֽ��ϴ�. ���� ���, ������ ���� ��쿡 ����� ĳ���ʹ� ��� �� ������ ������ �� �����ϴ�.

�ִܰŸ�4_of9xfg.png

���� ���� ���� maps�� �Ű������� �־��� ��, ĳ���Ͱ� ��� �� ������ �����ϱ� ���ؼ� �������� �ϴ� ĭ�� ������ �ּڰ��� return �ϵ��� solution �Լ��� �ϼ����ּ���. ��, ��� �� ������ ������ �� ���� ���� -1�� return ���ּ���.

���ѻ���
maps�� n x m ũ���� ���� ���� ���°� ����ִ� 2���� �迭��, n�� m�� ���� 1 �̻� 100 ������ �ڿ����Դϴ�.
n�� m�� ���� ���� ����, �ٸ� ���� ������, n�� m�� ��� 1�� ���� �Է����� �־����� �ʽ��ϴ�.
maps�� 0�� 1�θ� �̷���� ������, 0�� ���� �ִ� �ڸ�, 1�� ���� ���� �ڸ��� ��Ÿ���ϴ�.
ó���� ĳ���ʹ� ���� ���� ���� ����� (1, 1) ��ġ�� ������, ���� ������ ���� ���� ���� �ϴ��� (n, m) ��ġ�� �ֽ��ϴ�
 *
 */




/*
 * ���ͽ�Ʈ�� �켱���� ť�� ����� ȿ���� ���� X -> �Ƹ��� 
 */

#include "stdafx.h"

#define VISITED -1
#define UNVISITED 1
#define WALL 0


namespace DYJKSTRA
{
	int solution(vector<vector<int>> maps)
	{   
	    typedef tuple<int, int, int> Path;
		typedef tuple<int, int> Point;

	    const int width = static_cast<int>(maps[0].size() - 1);
	    const int height = static_cast<int>(maps.size() - 1);
	    const Point target = make_tuple(height, width);
	    

	    struct compare
	    {
	        bool operator()(const Path& p1, const Path& p2) const
	        {
	            return get<2>(p1) > get<2>(p2);
	        }
	    };

	    priority_queue<Path, deque<Path>, compare> path;    

	    path.push(make_tuple(0, 0, 1));

	    while(!path.empty())
	    {
		    auto top = path.top();
	        auto[topHeight, topWidth, weight] = top;
	        maps[topHeight][topWidth] = VISITED;
	        path.pop();
	        
	        auto&& ways = GetPathes(make_tuple(topHeight, topWidth));
	        for (auto& way : ways)
	        {
				const auto[wayHeight, wayWidth] = way;

	            if(IsInRange(wayHeight, 0, height) && IsInRange(wayWidth, 0, width))
	            {	                
	                if(way == target)
			    		return weight + 1;           

	                if(maps[wayHeight][wayWidth] == UNVISITED)
						path.push(make_tuple(wayHeight, wayWidth, weight + 1));
	            }
	        }	    
	    }
	    return -1;
	}

}


namespace BFS
{
	int solution(vector<vector<int>> maps)
	{
	    const int height = static_cast<int>(maps.size());
	    const int width = static_cast<int>(maps[0].size());
	    const tuple<int, int> target = { height - 1, width - 1 };

	    vector<vector<int>> visited(height, vector<int>(width, UNVISITED));
	    queue<tuple<int, int>> q;

	    q.push({ 0, 0 });
	    visited[0][0] = VISITED;

	    int steps = 1;

	    while (!q.empty())
	    {
	        int size = q.size();

	        for (int i = 0; i < size; ++i)
	        {
	            tuple<int, int> current = q.front();
	            q.pop();

	            vector<tuple<int, int>> ways = GetPathes(current);

	            for (const auto& way : ways)
	            {
					auto [nx, ny] = way;

	                if (nx >= 0 && nx < height && ny >= 0 && ny < width && visited[nx][ny] == UNVISITED && maps[nx][ny] == 1)
	                {
	                    if (way == target)
	                        return steps + 1;

	                    q.push(way);
	                    visited[nx][ny] = VISITED;
	                }
	            }
	        }

	        steps++;
	    }

	    return -1;
	}
}
int main()
{
	vector<vector<int>> maps = { {1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1} };

    cout << BFS::solution(maps);
}