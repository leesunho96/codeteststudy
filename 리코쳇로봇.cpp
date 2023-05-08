#include "stdafx.h"


typedef struct Path
{
public:
	Path() : PresentPoint(pair<int, int>(0, 0)), weight(0){};
	Path(const pair<int, int>& point, const int& weight) : PresentPoint(point), weight(weight){};
    bool operator==(const Path& rhs) const
	{return this->PresentPoint == rhs.PresentPoint && this->weight == rhs.weight;};
    bool operator!=(const Path& rhs) const
    {
        return this->PresentPoint != rhs.PresentPoint || this->weight != rhs.weight;
    };

	pair<int, int> PresentPoint;
	int weight;
} Path;

enum Direction
{
	Top = 0, Bottom, Left, Right
};

bool visited[100][100];
int weight[100][100];

const char ROBOT = 'R';
const char DISTURBANCE = 'D';
const char TARGET = 'G';
const char EMPTY = '.';
const Path INVALIDPATH = Path(pair<int, int>(-1, -1), -1);

void GetPoint(pair<int, int>& point, const vector<string> *board, const char target);
int solution(vector<string> board);
Path Move(const Direction direction, Path basePoint, const vector<string>& board, const pair<int, int>& Max);
int GetSmallerOne(const int& a, const int& b) {return a < b ? a : b; };


int solution(vector<string> board)
{
	for (int i = 0; i < 100; i++)
	{
        for (int j = 0; j < 100; j++)
        {
	        visited[i][j] = false;
            weight[i][j] = INT_MAX;
        }
	}


    const int width = board.at(0).size();
    const int height = board.size();
    const pair<int, int> MAX = pair<int, int>(height, width);
    queue<Path> PathStack;
    pair<int, int> startPoint;
    pair<int, int> endPoint;

    GetPoint(startPoint, &board, ROBOT);
    GetPoint(endPoint, &board, TARGET);

    PathStack.push(Path(startPoint, 0));
    visited[startPoint.first][startPoint.second] = true;

    while(!PathStack.empty())
    {
	    Path present = PathStack.front();
        PathStack.pop();

        if(present.PresentPoint == endPoint)
        {
            weight[present.PresentPoint.first][present.PresentPoint.second]
        	=
            GetSmallerOne(weight[present.PresentPoint.first][present.PresentPoint.second], present.weight);
        	continue;
        }


        vector<Path> movingResult;
        movingResult.emplace_back(Move(Direction::Left, present, board, MAX));
        movingResult.emplace_back(Move(Direction::Right, present, board, MAX));
        movingResult.emplace_back(Move(Direction::Top, present, board, MAX));
        movingResult.emplace_back(Move(Direction::Bottom, present, board, MAX));

        for(auto& a : movingResult)
        {
	        if(a != INVALIDPATH && visited[a.PresentPoint.first][a.PresentPoint.second] == false)
	        {
                visited[a.PresentPoint.first][a.PresentPoint.second] = true;
                PathStack.push(a);
	        }
        }      

    }


    if(weight[endPoint.first][endPoint.second] == INT_MAX)
		return -1;

    return weight[endPoint.first][endPoint.second];
}

void GetPoint(pair<int, int>& point, const vector<string> *board, const char target)
{
    for (int j = 0; j < board->size(); j++)
    {
	    for (int i = 0; i < board->at(j).length(); i++)
	    {
		    if(board->at(j).at(i) == target)
		    {point = pair<int, int>(j, i); return;}
	    }
    }
    point = pair<int, int>(-1, -1);
}


Path Move(const Direction direction, Path basePoint, const vector<string>& board, const pair<int, int>& Max)
{
	int weight = 0;

    const Path temp = basePoint;

	switch(direction)
	{
	case Top:
		if(basePoint.PresentPoint.first == 0)
			break;

	    while(basePoint.PresentPoint.first > 0 && board[basePoint.PresentPoint.first - 1][basePoint.PresentPoint.second] != DISTURBANCE)
	    {
		    basePoint.PresentPoint.first -= 1;	        
	    }
        basePoint.weight += 1;
    break;
	case Bottom:
        if (basePoint.PresentPoint.first == Max.first - 1)
            break;
        while (basePoint.PresentPoint.first < Max.first - 1 && board[basePoint.PresentPoint.first + 1][basePoint.PresentPoint.second] != DISTURBANCE)
        {
            basePoint.PresentPoint.first += 1;
        }
        basePoint.weight += 1;

    break;
	case Left:
        if (basePoint.PresentPoint.second == 0)
            break;
        while (basePoint.PresentPoint.second > 0 && board[basePoint.PresentPoint.first][basePoint.PresentPoint.second - 1] != DISTURBANCE)
        {
            basePoint.PresentPoint.second -= 1;
        }
        basePoint.weight += 1;
    break;
	case Right:
        if (basePoint.PresentPoint.second == Max.second - 1)
            break;
        while (basePoint.PresentPoint.second < Max.second - 1 && board[basePoint.PresentPoint.first][basePoint.PresentPoint.second + 1] != DISTURBANCE)
        {
            basePoint.PresentPoint.second += 1;
        }
        basePoint.weight += 1;
    break;
	}


    if(temp == basePoint)
		return INVALIDPATH;
    if(board[basePoint.PresentPoint.first][basePoint.PresentPoint.second] == ROBOT)
		return INVALIDPATH;
    
    return basePoint;
}

int main()
{
	vector<string> inputValue;
    inputValue.emplace_back(string("...D..R"));
    inputValue.emplace_back(string(".D.G..."));
    inputValue.emplace_back(string("....D.D"));
    inputValue.emplace_back(string("D....D."));
    inputValue.emplace_back(string("..D...."));

    //inputValue.emplace_back(string(".D.R"));
    //inputValue.emplace_back(string("...."));
    //inputValue.emplace_back(string(".G.."));
    //inputValue.emplace_back(string("...D"));

    cout << solution(inputValue);

}
