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
#include <array>
#include <deque>

#define DEBUG_MODE 1

using namespace std;
#define safedelete(x) if(x != nullptr) delete(x);
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

template<typename T>
bool IsInRange(const T& val, const T& min, const T& max)
{
    return val <= max && val >= min;
}

inline vector<tuple<int, int>> GetPathes(const tuple<int, int>& base)
{
    vector<tuple<int, int>> ways = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

    for (auto& way : ways)
    {
        get<0>(way) += get<0>(base);
        get<1>(way) += get<1>(base);
    }

    return ways;
}


class VectorToTuple
{
private:
template <typename Array, std::size_t... Idx>
static decltype(auto) array_to_tuple_impl(const Array& a, std::index_sequence<Idx...>)
{
    return std::make_tuple(a[Idx]...);
}

public:

/*
 * USAGE EXAMPLE
 * vector<int> temp = {1, 2, 3, 4}
 * VectorToTuple::vectorToTuple<string, 3>;
 */
template <typename T, std::size_t N>
static decltype(auto) vectorToTuple(const vector<T>& a)
{
	return VectorToTuple::array_to_tuple_impl(a, make_index_sequence<N>());
}
};