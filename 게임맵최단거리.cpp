/*
 *https://school.programmers.co.kr/learn/courses/30/lessons/1844
 *
 *ROR 게임은 두 팀으로 나누어서 진행하며, 상대 팀 진영을 먼저 파괴하면 이기는 게임입니다. 따라서, 각 팀은 상대 팀 진영에 최대한 빨리 도착하는 것이 유리합니다.

지금부터 당신은 한 팀의 팀원이 되어 게임을 진행하려고 합니다. 다음은 5 x 5 크기의 맵에, 당신의 캐릭터가 (행: 1, 열: 1) 위치에 있고, 상대 팀 진영은 (행: 5, 열: 5) 위치에 있는 경우의 예시입니다.

최단거리1_sxuruo.png

위 그림에서 검은색 부분은 벽으로 막혀있어 갈 수 없는 길이며, 흰색 부분은 갈 수 있는 길입니다. 캐릭터가 움직일 때는 동, 서, 남, 북 방향으로 한 칸씩 이동하며, 게임 맵을 벗어난 길은 갈 수 없습니다.
아래 예시는 캐릭터가 상대 팀 진영으로 가는 두 가지 방법을 나타내고 있습니다.

첫 번째 방법은 11개의 칸을 지나서 상대 팀 진영에 도착했습니다.
최단거리2_hnjd3b.png

두 번째 방법은 15개의 칸을 지나서 상대팀 진영에 도착했습니다.
최단거리3_ntxygd.png

위 예시에서는 첫 번째 방법보다 더 빠르게 상대팀 진영에 도착하는 방법은 없으므로, 이 방법이 상대 팀 진영으로 가는 가장 빠른 방법입니다.

만약, 상대 팀이 자신의 팀 진영 주위에 벽을 세워두었다면 상대 팀 진영에 도착하지 못할 수도 있습니다. 예를 들어, 다음과 같은 경우에 당신의 캐릭터는 상대 팀 진영에 도착할 수 없습니다.

최단거리4_of9xfg.png

게임 맵의 상태 maps가 매개변수로 주어질 때, 캐릭터가 상대 팀 진영에 도착하기 위해서 지나가야 하는 칸의 개수의 최솟값을 return 하도록 solution 함수를 완성해주세요. 단, 상대 팀 진영에 도착할 수 없을 때는 -1을 return 해주세요.

제한사항
maps는 n x m 크기의 게임 맵의 상태가 들어있는 2차원 배열로, n과 m은 각각 1 이상 100 이하의 자연수입니다.
n과 m은 서로 같을 수도, 다를 수도 있지만, n과 m이 모두 1인 경우는 입력으로 주어지지 않습니다.
maps는 0과 1로만 이루어져 있으며, 0은 벽이 있는 자리, 1은 벽이 없는 자리를 나타냅니다.
처음에 캐릭터는 게임 맵의 좌측 상단인 (1, 1) 위치에 있으며, 상대방 진영은 게임 맵의 우측 하단인 (n, m) 위치에 있습니다
 *
 */




/*
 * 다익스트라 우선순위 큐로 실행시 효율성 만족 X -> 아마도 
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