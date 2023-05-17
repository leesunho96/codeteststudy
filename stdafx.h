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
 * �Ÿ��� ������ ���·� ��ȯ. �Ϲ����� �ڵ��׽�Ʈ�� ��쿡���� �ش� ���·� ���. ���� �ʿ��ϴٸ�, sqrt �����Ͽ� ó��.
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