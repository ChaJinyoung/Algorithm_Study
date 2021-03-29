// 문제 설명
// 스파이들은 매일 다른 옷을 조합하여 입어 자신을 위장합니다.

// 예를 들어 스파이가 가진 옷이 아래와 같고 오늘 스파이가 동그란 안경, 긴 코트, 파란색 티셔츠를 입었다면 다음날은 청바지를 추가로 입거나 동그란 안경 대신 검정 선글라스를 착용하거나 해야 합니다.

// 종류	    이름
// 얼굴	    동그란 안경, 검정 선글라스
// 상의	    파란색 티셔츠
// 하의	    청바지
// 겉옷	    긴 코트
// 스파이가 가진 의상들이 담긴 2차원 배열 clothes가 주어질 때 서로 다른 옷의 조합의 수를 return 하도록 solution 함수를 작성해주세요.

// 제한사항
// clothes의 각 행은[의상의 이름, 의상의 종류]로 이루어져 있습니다.
// 스파이가 가진 의상의 수는 1개 이상 30개 이하입니다.
// 같은 이름을 가진 의상은 존재하지 않습니다.
// clothes의 모든 원소는 문자열로 이루어져 있습니다.
// 모든 문자열의 길이는 1 이상 20 이하인 자연수이고 알파벳 소문자 또는 '_' 로만 이루어져 있습니다.
// 스파이는 하루에 최소 한 개의 의상은 입습니다.
// 입출력 예
// clothes	                                                                                     return
// [["yellowhat", "headgear"], ["bluesunglasses", "eyewear"], ["green_turban", "headgear"]]      5
// [["crowmask", "face"], ["bluesunglasses", "face"], ["smoky_makeup", "face"]]                  3
// 입출력 예 설명
// 예제 #1
// headgear에 해당하는 의상이 yellow_hat, green_turban이고 eyewear에 해당하는 의상이 blue_sunglasses이므로 아래와 같이 5개의 조합이 가능합니다.

// 1. yellow_hat
// 2. blue_sunglasses
// 3. green_turban
// 4. yellow_hat + blue_sunglasses
// 5. green_turban + blue_sunglasses

// 예제 #2
// face에 해당하는 의상이 crow_mask, blue_sunglasses, smoky_makeup이므로 아래와 같이 3개의 조합이 가능합니다.

// 1. crow_mask
// 2. blue_sunglasses
// 3. smoky_makeup

// 설명
// map이 중복된 키 값을 저장하지 않는 점을 이용하여 종류를 key 값으로, 종류의 수를 value값으로 하여 각 옷의 종류를 세어 계산하였다.
// 옷을 입는 가지 수는 각 옷의 종류에 따른 옷의 수 + 1을 곱한 후 -1을 한 값이다. (옷을 하나 이상 입어야 하기 때문)
 
// 풀이 코드

#include <bits/stdc++.h>
using namespace std;
#define fastio

int solution(vector<vector<string>> clothes) {      // 이차원 벡터 clothes를 인자로 받는 함수
    int answer = 0;                             // 옷을 입는 가짓수를 나타내는 answer
    map<string, int> m;                         // 옷의 종류를 key, 해당 종류의 옷의 수를 value로 갖는 map
    for (int i = 0; i < clothes.size(); i++) {  // clothes 전체 탐색
        m.insert(make_pair(clothes[i][1], 0));  // map에 clothes에서 탐색한 옷의 종류가 없을 경우 새로 삽입
        m.find(clothes[i][1])->second++;        // map에 삽입된 옷의 종류가 존재하는 경우 + 1 (없는 경우에도 위에서 새로 삽입되어 1의 값을 가짐)
    }
    map<string, int> ::iterator it;             // m의 iterator
    answer++;       // 곱셈을 위해 answer + 1
    for (it = m.begin(); it != m.end(); it++) { // m의 전체를 탐색하여 value값 + 1를 answer에 곱
        answer *= it->second + 1;
    }
    answer--;       // 옷을 입지않은 경우의 수 -1

    return answer;
}

int main() {        // 실행을 위한 메인 함수
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    fastio;

    vector<vector<string>> v;
    for (int i = 0; i < 3; i++) {
        string str1, str2;
        vector<string> v2;
        cin >> str1 >> str2;
        v2.push_back(str1);
        v2.push_back(str2);
        v.push_back(v2);
    }
    int answer = solution(v);
    cout << answer << endl;

    return 0;
}