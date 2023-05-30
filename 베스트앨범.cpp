/*
 *https://school.programmers.co.kr/learn/courses/30/lessons/42579
 *
 *
 *���� ����
��Ʈ���� ����Ʈ���� �帣 ���� ���� ���� ����� �뷡�� �� ���� ��� ����Ʈ �ٹ��� ����Ϸ� �մϴ�. �뷡�� ���� ��ȣ�� �����ϸ�, �뷡�� �����ϴ� ������ ������ �����ϴ�.

���� �뷡�� ���� ����� �帣�� ���� �����մϴ�.
�帣 ������ ���� ����� �뷡�� ���� �����մϴ�.
�帣 ������ ��� Ƚ���� ���� �뷡 �߿����� ���� ��ȣ�� ���� �뷡�� ���� �����մϴ�.
�뷡�� �帣�� ��Ÿ���� ���ڿ� �迭 genres�� �뷡�� ��� Ƚ���� ��Ÿ���� ���� �迭 plays�� �־��� ��, ����Ʈ �ٹ��� �� �뷡�� ���� ��ȣ�� ������� return �ϵ��� solution �Լ��� �ϼ��ϼ���.

���ѻ���
genres[i]�� ������ȣ�� i�� �뷡�� �帣�Դϴ�.
plays[i]�� ������ȣ�� i�� �뷡�� ����� Ƚ���Դϴ�.
genres�� plays�� ���̴� ������, �̴� 1 �̻� 10,000 �����Դϴ�.
�帣 ������ 100�� �̸��Դϴ�.
�帣�� ���� ���� �ϳ����, �ϳ��� � �����մϴ�.
��� �帣�� ����� Ƚ���� �ٸ��ϴ�.
����� ��
genres	plays	return
["classic", "pop", "classic", "classic", "pop"]	[500, 600, 150, 800, 2500]	[4, 1, 3, 0]
����� �� ����
classic �帣�� 1,450ȸ ����Ǿ�����, classic �뷡�� ������ �����ϴ�.

���� ��ȣ 3: 800ȸ ���
���� ��ȣ 0: 500ȸ ���
���� ��ȣ 2: 150ȸ ���
pop �帣�� 3,100ȸ ����Ǿ�����, pop �뷡�� ������ �����ϴ�.

���� ��ȣ 4: 2,500ȸ ���
���� ��ȣ 1: 600ȸ ���
���� pop �帣�� [4, 1]�� �뷡�� ����, classic �帣�� [3, 0]�� �뷡�� �״����� �����մϴ�.

�帣 ���� ���� ���� ����� �뷡�� �ִ� �� ������ ��� ����Ʈ �ٹ��� ����ϹǷ� 2�� �뷡�� ���ϵ��� �ʽ��ϴ�.
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

        // mPlay �ʱ�ȭ
	    mPlays[i] = make_tuple(genreName, playTime);
        // mGenreScore �ʱ�ȭ
        mGenreScore[genreName] += playTime;
        // mMusicListInGenre �ʱ�ȭ        
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
