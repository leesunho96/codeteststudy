/*
 *https://school.programmers.co.kr/learn/courses/30/lessons/42579
 *
 *
 *문제 설명
스트리밍 사이트에서 장르 별로 가장 많이 재생된 노래를 두 개씩 모아 베스트 앨범을 출시하려 합니다. 노래는 고유 번호로 구분하며, 노래를 수록하는 기준은 다음과 같습니다.

속한 노래가 많이 재생된 장르를 먼저 수록합니다.
장르 내에서 많이 재생된 노래를 먼저 수록합니다.
장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록합니다.
노래의 장르를 나타내는 문자열 배열 genres와 노래별 재생 횟수를 나타내는 정수 배열 plays가 주어질 때, 베스트 앨범에 들어갈 노래의 고유 번호를 순서대로 return 하도록 solution 함수를 완성하세요.

제한사항
genres[i]는 고유번호가 i인 노래의 장르입니다.
plays[i]는 고유번호가 i인 노래가 재생된 횟수입니다.
genres와 plays의 길이는 같으며, 이는 1 이상 10,000 이하입니다.
장르 종류는 100개 미만입니다.
장르에 속한 곡이 하나라면, 하나의 곡만 선택합니다.
모든 장르는 재생된 횟수가 다릅니다.
입출력 예
genres	plays	return
["classic", "pop", "classic", "classic", "pop"]	[500, 600, 150, 800, 2500]	[4, 1, 3, 0]
입출력 예 설명
classic 장르는 1,450회 재생되었으며, classic 노래는 다음과 같습니다.

고유 번호 3: 800회 재생
고유 번호 0: 500회 재생
고유 번호 2: 150회 재생
pop 장르는 3,100회 재생되었으며, pop 노래는 다음과 같습니다.

고유 번호 4: 2,500회 재생
고유 번호 1: 600회 재생
따라서 pop 장르의 [4, 1]번 노래를 먼저, classic 장르의 [3, 0]번 노래를 그다음에 수록합니다.

장르 별로 가장 많이 재생된 노래를 최대 두 개까지 모아 베스트 앨범을 출시하므로 2번 노래는 수록되지 않습니다.
 */


#include "stdafx.h"

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    set<string> sGenre;
    unordered_map<int,tuple<string, int>> mPlays;
    unordered_map<string, int> mGenreScore;
    unordered_map<string, set<int>> mMusicListinGenre;

    const int musicSize = genres.size();


    auto printFunc = [&]()
    {
	    for (auto a : sGenre)
			cout << a << " ";
        cout << endl;


        for (auto a : mPlays)
        {
	        cout << "index : " <<  get<0>(a) << "  Genre : " << get<0>(get<1>(a)) << " Score : " << get<1>(get<1>(a)) << " \n";
        }
        cout << endl;

        for (auto a : mGenreScore)
        {
	        cout << "GenreName : " << get<0>(a) << " TotalScore : "  << get<1>(a) << " ";
        }
        cout << endl;

        for (auto a : mMusicListinGenre)
        {
	        cout << "\nGnreName : "  << get<0>(a) << "\n  PlayList : ";
            for (auto b : get<1>(a))
				cout << b << " ";
        }
        cout << endl;
    };




    for (int i = 0; i < musicSize; i++)
    {
	    const string& genreName = genres.at(i);
        const int& playTime = plays.at(i);

        // mPlay 초기화
	    mPlays[i] = make_tuple(genreName, playTime);
        // mGenreScore 초기화
        mGenreScore[genreName] += playTime;
        // mMusicListInGenre 초기화        
        mMusicListinGenre[genreName].insert(i);
    }


    








    // for order.
    vector<tuple<string, int>> genreVector(mGenreScore.begin(), mGenreScore.end());

    auto compare = [&](const tuple<string, int>& val1, const tuple<string, int>& val2)
    {
	    return get<1>(val1) > get<1>(val2);
    };

    auto compare2 = [&](const int& val1, const int& val2)
    {
	    return get<1>(mPlays[val1]) > get<1>(mPlays[val2]);
    };

    ranges::sort(genreVector.begin(), genreVector.end(), compare);



	for (auto genre : genreVector)
	{
		auto& gnereName = get<0>(genre);
        set<int>& musicList = mMusicListinGenre[gnereName];


        vector<int> vMusicList(musicList.begin(), musicList.end());

        sort(vMusicList.begin(), vMusicList.end(), compare2);



        answer.push_back(vMusicList[0]);

        if(vMusicList.size() > 1)
			answer.push_back(vMusicList[1]);


	}

    

    return answer;
}

int main()
{
	vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
    vector<int> plays = { 500, 600, 150, 800, 2500 };

    auto result = solution(genres, plays);
    for (auto a : result)
    {
	    cout << a << "  " ;
    }
}
