#pragma once
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <limits>
#include <list>
#include <stack>
#include <set>
#include <cmath>
#include <limits>
#include <optional>
#include <unordered_map>
#include <unordered_set>


using namespace std;





/*
 * 거리의 제곱의 형태로 반환. 일반적인 코드테스트의 경우에서는 해당 상태로 사용. 만약 필요하다면, sqrt 적용하여 처리.
 */
template<typename T>
T GetDistance(const std::tuple<T, T>& basePoint, const std::tuple<T, T>& targetPoint)
{
    auto [x0, y0] = basePoint;
    auto [x1, y1] = targetPoint;

    return pow(get<0>(targetPoint) - get<0>(basePoint), 2) + pow(get<1>(targetPoint) - get<1>(basePoint), 2);
}


template<typename T>
optional<T> GetLinear(const tuple<T, T> p1, const tuple<T, T> p2)
{
	auto[p1x, p1y] = p1;
    auto[p2x, p2y] = p2;


    if(p2x - p1x == 0)
		return nullopt;

    return (p2y - p1y) / (p2x - p1y);
}