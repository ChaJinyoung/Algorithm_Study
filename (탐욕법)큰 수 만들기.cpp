// 문제 설명
// 어떤 숫자에서 k개의 수를 제거했을 때 얻을 수 있는 가장 큰 숫자를 구하려 합니다.
// 예를 들어, 숫자 1924에서 수 두 개를 제거하면[19, 12, 14, 92, 94, 24] 를 만들 수 있습니다.이 중 가장 큰 숫자는 94 입니다.
// 문자열 형식으로 숫자 number와 제거할 수의 개수 k가 solution 함수의 매개변수로 주어집니다.number에서 k 개의 수를 제거했을 때 만들 수 있는 수 중 가장 큰 숫자를 문자열 형태로 return 하도록 solution 함수를 완성하세요.

// 제한 조건
// number는 1자리 이상, 1, 000, 000자리 이하인 숫자입니다.
// k는 1 이상 number의 자릿수 미만인 자연수입니다.

// 입출력 예
// number	        k	    return
// "1924"	        2	    "94"
// "1231234"	    3	    "3234"
// "4177252841"	    4	    "775841"


// 설명
// 전체 문자열에서 k개의 수를 제거하여 가장 큰 수를 만드는 것이기 때문에 문자열의 길이 - k 만큼 반복한다.
// 각 자리에서 k번 뒤의 수까지 비교하여 가장 큰 수를 answer에 삽입하는 과정을 반복한다.
// 삽입된 숫자보다 앞의 수를 삽입할 수 없으므로 삽입 후 다음 수부터 탐색할 수 있도록 한다.

// 풀이 코드

#include <bits/stdc++.h>
using namespace std;
#define fastio

string solution(string number, int k) {
    string answer = "";     // 수를 저장할 문자열 answer

    int tmp = 0;        // j의 시작값을 정하는 변수 tmp
    for (int i = 0; i < number.size() - k; i++) {   // number의 길이에서 k값 만큼 뺀 만큼 반복
        char c = ' ';       // 가장 큰 수를 저장할 문자 변수 c
        for (int j = tmp; j <= i + k; j++) {        // tmp부터 시작하여 현재 탐색 중인 수부터 k번째 뒤까지 중 가장 큰 수를 저장
            if (c < number[j]) {        // c에 계속 큰 수를 저장하여 마지막에 가장 큰 수가 저장
                c = number[j];
                tmp = j;        // j번째 수가 가장 크기 때문에 tmp를 j값으로 대입하여 다음 반복 시 j 이후의 수 탐색
            }
        }
        answer += c;        // 저장한 문자를 answer에 추가
        tmp++;           // 다음 반복 시 tmp값을 두 번 탐색하는 것을 방지하기 위해 1+
    }

    return answer;
}

int main() {        // 실행을 위한 메인 함수
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    fastio;

    string str;
    int k;
    cin >> str >> k;
    string answer = solution(str, k);
    cout << answer << endl;

    return 0;
}