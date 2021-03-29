// 문제 설명
// 전화번호부에 적힌 전화번호 중, 한 번호가 다른 번호의 접두어인 경우가 있는지 확인하려 합니다.
// 전화번호가 다음과 같을 경우, 구조대 전화번호는 영석이의 전화번호의 접두사입니다.

// 구조대 : 119
// 박준영 : 97 674 223
// 지영석 : 11 9552 4421
// 전화번호부에 적힌 전화번호를 담은 배열 phone_book 이 solution 함수의 매개변수로 주어질 때, 어떤 번호가 다른 번호의 접두어인 경우가 있으면 false를 그렇지 않으면 true를 return 하도록 solution 함수를 작성해주세요.

// 제한 사항
// phone_book의 길이는 1 이상 1, 000, 000 이하입니다.
// 각 전화번호의 길이는 1 이상 20 이하입니다.
// 같은 전화번호가 중복해서 들어있지 않습니다.
// 입출력 예제
// phone_book	                            return
// ["119", "97674223", "1195524421"]    	false
// ["123", "456", "789"]	                true
// ["12", "123", "1235", "567", "88"]	    false

// 입출력 예 설명
// 입출력 예 #1
// 앞에서 설명한 예와 같습니다.

// 입출력 예 #2
// 한 번호가 다른 번호의 접두사인 경우가 없으므로, 답은 true입니다.

// 입출력 예 #3
// 첫 번째 전화번호, “12”가 두 번째 전화번호 “123”의 접두사입니다.따라서 답은 false입니다.

// 설명
// 길이가 짧은 번호부터 긴 번호까지 정렬 후 반복문을 통해 접두사를 탐색
// 효율성을 높이기 위해 접두사를 발견한 경우 즉시 리턴을 하여 함수 종료

// 풀이 코드

#include <bits/stdc++.h>
using namespace std;
#define fastio

bool solution(vector<string> phone_book) {      // 
    bool answer = true;                     // 접두사 여부를 확인하는 bool 변수 answer
    sort(phone_book.begin(), phone_book.end());    // phone_book 정렬
    for (int i = 0; i < phone_book.size() - 1; i++) {       // phone_book 전체를 탐색
        if (phone_book[i + 1].find(phone_book[i]) == 0) {   // phone의 요소가 다음 요소에 포함되는 경우
            answer = false;                                 // answer를 false 처리 후 반환
            return answer;
        }
    }

    return answer;      // 탐색 끝까지 접두사가 없을 경우 true 반환
}

int main() {        // 실행을 위한 메인 함수
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    fastio;

    vector<string> v;
    for (int i = 0; i < 3; i++) {
        string str;
        cin >> str;
        v.push_back(str);
    }
    bool answer = solution(v);
    if (answer) cout << "true" << endl;
    else cout << "false" << endl;

    return 0;
}