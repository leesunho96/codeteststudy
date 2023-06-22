#pragma once
#include <iostream>
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
#include <tuple>
#include <cassert>
#include <thread>
#include <mutex>
#include <functional>
#include <type_traits>
#include <sstream>
#include <memory>


#define DEBUG_MODE 1

#define safedelete(x) if(x != nullptr) delete(x);

using namespace std;

template <typename T>
ostream& operator<<(ostream& stream, const vector<T>& values)
{
	cout << "{ ";
	for (const auto a : values)
		stream << a << " ";
	cout << "}";
	return stream;
}

template <typename T>
ostream& operator<<(ostream& stream, const vector<vector<T>>& values)
{
	cout << "{ ";
	for (const auto a : values)
		stream << a << " ";
	cout << "}";
	return stream;
}

template <typename ...Ts, size_t ...Is>
ostream& println_tuple_impl(ostream& os, tuple<Ts...> tuple, index_sequence<Is...>)
{
	static_assert(sizeof...(Is) == sizeof...(Ts), "Indices must have same number of elements as tuple types!");
	static_assert(sizeof...(Ts) > 0, "Cannot insert empty tuple into stream.");
	auto last = sizeof...(Ts); // assuming index sequence 0,...,N-1
	return ((os << get<Is>(tuple) << " "), ...);
}

template <typename ...Ts>
ostream& operator<<(ostream& os, const tuple<Ts...>& tuple)
{
	return println_tuple_impl(os, tuple, index_sequence_for<Ts...>{});
}


namespace MATH
{
	/*
	 * 거리의 제곱의 형태로 반환. 일반적인 코드테스트의 경우에서는 해당 상태로 사용. 만약 필요하다면, sqrt 적용하여 처리.
	 */
	template <typename T>
	T GetDistance(const tuple<T, T>& basePoint, const tuple<T, T>& targetPoint)
	{
		auto [x0, y0] = basePoint;
		auto [x1, y1] = targetPoint;

		return pow(get<0>(targetPoint) - get<0>(basePoint), 2) + pow(get<1>(targetPoint) - get<1>(basePoint), 2);
	}

	template <typename T>
	optional<T> GetLinear(const tuple<T, T> p1, const tuple<T, T> p2)
	{
		auto [p1x, p1y] = p1;
		auto [p2x, p2y] = p2;


		if (p2x - p1x == 0)
			return nullopt;

		return (p2y - p1y) / (p2x - p1y);
	}


	// min <= val <= max
	template <typename T>
	bool IsInRange(const T& val, const T& min, const T& max)
	{
		return val <= max && val >= min;
	}

	// 0 <= compareVal <= maxVal
	template <typename T>
	bool IsInRange(const T& compareVal, const T& maxVal)
	{
		return IsInRange<T>(compareVal, 0, maxVal);
	}
}

namespace UTILITY
{
	inline vector<tuple<int, int>> GetPathes(const tuple<int, int>& base, const int height, const int width)
	{
		vector<tuple<int, int>> ways = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
		vector<tuple<int, int>> output;

		for (auto& way : ways)
		{
			const auto [wayX, wayY] = way;
			const auto [baseX, baseY] = base;

			if (MATH::IsInRange(wayX + baseX, height) && MATH::IsInRange(wayY + baseY, width))
				output.emplace_back(make_tuple(wayY + baseY, wayX + baseX));
		}
		return output;
	}

	inline vector<tuple<int, int>> GetPathes(const tuple<int, int>& base)
	{
		return GetPathes(base, numeric_limits<int>::max(), numeric_limits<int>::max());
	}

	class VectorToTuple
	{
	private:
		template <typename Array, size_t... Idx>
		static decltype(auto) array_to_tuple_impl(const Array& a, index_sequence<Idx...>)
		{
			return make_tuple(a[Idx]...);
		}

	public:
		/*
		 * USAGE EXAMPLE
		 * vector<int> temp = {1, 2, 3, 4}
		 * VectorToTuple::vectorToTuple<string, 3>;
		 */
		template <typename T, size_t N>
		static decltype(auto) vectorToTuple(const vector<T>& a)
		{
			assert(N > a.size(), "Container's value doesn't enough for tuple Size");
			return VectorToTuple::array_to_tuple_impl(a, make_index_sequence<N>());
		}
	};


	template <typename T, typename mapValueType>
	bool FindInSetandSetMap(set<T>& setVal, unordered_map<T, mapValueType>& mapVal, const T& key)
	{
		const bool&& result = (!setVal.contains(key));
		setVal.insert(key);

		if (result)
			mapVal[key] += static_cast<mapValueType>(1);
		else
			mapVal[key] = static_cast<mapValueType>(1);

		return result;
	}

	template <typename T, typename mapValueType, typename compare>
	bool FindInSetandSetMap(set<T, compare>& setVal, unordered_map<T, mapValueType>& mapVal, const T& key)
	{
		const bool&& result = (!setVal.contains(key));
		setVal.insert(key);

		if (result)
			mapVal[key] += static_cast<mapValueType>(1);
		else
			mapVal[key] = static_cast<mapValueType>(1);

		return result;
	}


	template <typename T, typename mapValueType, typename Hash>
	bool FindInSetandSetMap(set<T>& setVal, unordered_map<T, mapValueType, Hash>& mapVal, const T& key)
	{
		const bool&& result = (!setVal.contains(key));
		setVal.insert(key);

		if (result)
			mapVal[key] += static_cast<mapValueType>(1);
		else
			mapVal[key] = static_cast<mapValueType>(1);

		return result;
	}

	template <typename T, typename mapValueType, typename compare, typename Hash>
	bool FindInSetandSetMap(set<T, compare>& setVal, unordered_map<T, mapValueType, Hash>& mapVal, const T& key)
	{
		const bool&& result = (!setVal.contains(key));
		setVal.insert(key);

		if (result)
			mapVal[key] = static_cast<mapValueType>(1);
		else
			mapVal[key] += static_cast<mapValueType>(1);

		return result;
	}


	template <typename Conatiner, typename T>
	bool AllSameInContainer(const Conatiner& input, const T& Val)
	{
		using ElemenType = remove_reference_t<decltype(*(begin(input)))>;

		static_assert(is_same_v<ElemenType, T>, "Container element Type and Val Type must same");

		bool answer = false;

		for (auto val : input)
		{
			if (val != Val)
				return false;
		}

		return true;
	}
}

namespace TESTFUNC
{
	// Primary template for the IsVector struct
	template <typename T>
	struct IsVector : false_type
	{
	};

	// Specialization for vector types
	template <typename... Args>
	struct IsVector<vector<Args...>> : true_type
	{
	};

	// Helper function to check if a type is a vector
	template <typename T>
	bool CheckIsVector()
	{
		return IsVector<T>::value;
	}


	template <typename T>
	void PrintAllIngredient(const string& type, const vector<T>& input)
	{
		cout << type << " { ";
		for (const auto& str : input)
			cout << str << " , ";
		cout << " }" << endl;
	}

	template <typename T>
	void PrintAllIngredient(const vector<T>& input)
	{
		PrintAllIngredient<T>("", input);
	}


	template <typename... Args, size_t... Is>
	void PrintParameterHelper(const tuple<Args...>& printTuple, index_sequence<Is...>)
	{
		((cout << (get<Is>(printTuple)) << endl), ...);
	}

	template <typename... Args>
	void PrintParameter(const tuple<Args...>& printTuple)
	{
		constexpr size_t tupleSize = sizeof...(Args);
		PrintParameterHelper(printTuple, make_index_sequence<tupleSize>());
	}

	template <typename Func, typename ResultType, typename... Args>
	void TestFunction(Func func, const tuple<Args...>& args, ResultType expected)
	{
		auto result = apply(func, args);

		PrintParameter(args);

		if (result == expected)
			cout << "Test passed! Result: " << result << endl;
		else
			cout << "Test failed! Expected: " << expected << ", Result: " << result << endl;
		cout << endl;
	}
}

namespace DEBUGFUNC
{
	template <typename T>
	void printStr_impl(const string& str, const T& val)
	{
		int i = str.find('%');

		if (i == -1)
			static_assert(true, "Semantic Error in printStr_impl");

		i > 0 ? (cout << string(str.begin(), str.begin() + i)) : (cout << string());

		cout << val;

		if (str.begin() + 1 + i < str.end())
			cout << string(str.begin() + i + 1, str.end());
	}

	template <typename T, typename... Args>
	void printStr_impl(const string& str, const T& val, Args ... args)
	{
		int i = str.find('%');

		if (i == -1)
			static_assert(true, "Semantic Error in printStr_impl");

		i > 0 ? printStr_impl(string(str.begin(), str.begin() + i + 1), val) : printStr_impl(string("%"), val);

		printStr_impl(string(str.begin() + i + 2, str.end()), args...);
	}

	template <typename T, typename... Args>
	void printStr(const string& str, const T& val, Args ... args)
	{
#ifdef DEBUG_MODE
		printStr_impl(str, val, args...);
#endif
	}
}


using namespace MATH;
using namespace UTILITY;
using namespace DEBUGFUNC;
using namespace TESTFUNC;
