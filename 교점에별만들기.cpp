//https://school.programmers.co.kr/learn/courses/30/lessons/87377
#pragma once
#include "stdafx.h"

#define EQUATION tuple<int, int, int>
#define POINT tuple<int, int>
#define CROSS tuple<float, float>
#define INVALIDVALUE CROSS(numeric_limits<int>::max(), numeric_limits<int>::max())
#define XVAL 0
#define YVAL 1
#define ZVAL 2



std::tuple<int, int> operator+(const std::tuple<int, int>& lhs, const std::tuple<int, int>& rhs) {
    int x1, x2, y1, y2;
    std::tie(x1, x2) = lhs;
    std::tie(y1, y2) = rhs;
    return std::make_tuple(x1 + y1, x2 + y2);
}

std::tuple<int, int> operator-(const std::tuple<int, int>& lhs, const std::tuple<int, int>& rhs) {
    int x1, x2, y1, y2;
    std::tie(x1, x2) = lhs;
    std::tie(y1, y2) = rhs;
    return std::make_tuple(x1 - y1, x2 - y2);
}


std::tuple<int, int> operator/(const std::tuple<int, int>& lhs, const std::tuple<int, int>& rhs) {
    int x1, x2, y1, y2;
    std::tie(x1, x2) = lhs;
    std::tie(y1, y2) = rhs;
    return std::make_tuple(x1 / y1, x2 / y2);
}


CROSS GetCrossPoint(const EQUATION& eq1, const EQUATION& eq2)
{
    CROSS result = INVALIDVALUE;

    if (get<XVAL>(eq1) * get<YVAL>(eq2) - get<XVAL>(eq2) * get<YVAL>(eq1) == 0.0f)
        return result;

    long double x, y;
    long double a, b, p;
    long double c, d, q;

    a = get<XVAL>(eq1);
    b = get<YVAL>(eq1);
    p = -get<ZVAL>(eq1);

    c = get<XVAL>(eq2);
    d = get<YVAL>(eq2);
    q = -get<ZVAL>(eq2);

    y = (a * q - c * p) / (a * d - b * c);
    x = (d * p - b * q) / (a * d - b * c);

    result = CROSS((float)x, (float)y);
    return result;
}

set<POINT> GetValidResult(vector<CROSS>& inputValue)
{
    set<POINT> result;

    for (auto& temp : inputValue)
    {

        float tempX = get<0>(temp);
        float tempY = get<1>(temp);

        if (tempX == numeric_limits<float>::max() || tempY == numeric_limits<float>::max())
            continue;

        if ((tempX - (int)(tempX) == 0.0f) && (tempY - (int)(tempY) == 0.0f))
            result.insert(POINT(tempX, tempY));
    }

    return result;
}



vector<string> solution(vector<vector<int>> line)
{
    vector<EQUATION> inputEquation;
    set<POINT> result;
    vector<CROSS> results;


    for (auto a : line)
    {
        inputEquation.push_back(EQUATION(a[0], a[1], a[2]));
    }



    for (int i = 0; i < inputEquation.size() - 1; i++)
    {
        for (int j = i + 1; j < line.size(); j++)
        {
            results.push_back(GetCrossPoint(inputEquation[i], inputEquation[j]));
        }
    }

    result = GetValidResult(results);

    POINT minP(numeric_limits<int>::max(), numeric_limits<int>::max());
    POINT maxP(numeric_limits<int>::lowest(), numeric_limits<int>::lowest());

    for (auto a : result)
    {
        if (get<XVAL>(a) > get<XVAL>(maxP))
        {
            get<XVAL>(maxP) = get<XVAL>(a);
        }

        if (get<XVAL>(a) < get<XVAL>(minP))
        {
            get<XVAL>(minP) = get<XVAL>(a);
        }

        if (get<YVAL>(a) > get<YVAL>(maxP))
        {
            get<YVAL>(maxP) = get<YVAL>(a);
        }

        if (get<YVAL>(a) < get<YVAL>(minP))
        {
            get<YVAL>(minP) = get<YVAL>(a);
        }

    }

    string temp("");

    for (size_t i = 0; i < get<XVAL>(maxP) - get<XVAL>(minP) + 1; i++)
    {
        temp += ".";
    }

    vector<string> answer(get<YVAL>(maxP) - get<YVAL>(minP) + 1, temp);

    set<POINT> finalResult;
    for (auto a : result)
    {
        POINT temp = a - minP;
        finalResult.insert(temp);
    }

    int xSize = answer[0].size() - 1;
    int ySize = answer.size() - 1;

    for (auto a : finalResult)
    {
        int tempY = get<YVAL>(a);

        answer[ySize - get<YVAL>(a)][get<XVAL>(a)] = '*';
    }
    return answer;
}


int main()
{
	vector<vector<int>> line;

    long long input[] =  /*{ 0, 1, -1 ,  1, 0, -1 ,  1, 0, 1 } ;*/{ 2, -1, 4, -2, -1, 4, 0, -1, 1, 5, -8, -12, 5, 8, 12};

    for (long long i = 0; i < sizeof(input) / 3 / 4; i++)
    {
	    vector<int> lines;
        lines.push_back(input[3 * i]);
        lines.push_back(input[3 * i + 1]);
        lines.push_back(input[3 * i + 2]);
        line.emplace_back(lines);
    }

	vector<string> result = solution(line);


    for(auto a : result)
    {
	    cout << a << endl;
    }

}