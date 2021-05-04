// 문제 설명
// 한자리 숫자가 적힌 종이 조각이 흩어져있습니다.흩어진 종이 조각을 붙여 소수를 몇 개 만들 수 있는지 알아내려 합니다.
// 각 종이 조각에 적힌 숫자가 적힌 문자열 numbers가 주어졌을 때, 종이 조각으로 만들 수 있는 소수가 몇 개인지 return 하도록 solution 함수를 완성해주세요.

// 제한사항
// numbers는 길이 1 이상 7 이하인 문자열입니다.
// numbers는 0~9까지 숫자만으로 이루어져 있습니다.
// "013"은 0, 1, 3 숫자가 적힌 종이 조각이 흩어져있다는 의미입니다.

// 입출력 예
// numbers	    return
// "17"	        3
// "011"	    2

// 입출력 예 설명
// 예제 #1
// [1, 7]으로는 소수[7, 17, 71]를 만들 수 있습니다.
// 예제 #2
// [0, 1, 1]으로는 소수[11, 101]를 만들 수 있습니다.

// 11과 011은 같은 숫자로 취급합니다.

// 설명
// 에라토스테네스의 체를 통해 소수를 판별하는 함수를 사용한다.
// 입력받은 문자열 수를 분리하여 next_permutation를 통해 분리된 수를 순열에 따라 조합하여 저장한다.
// 벡터에 저장된 수의 중복을 제거하여 중복된 값을 세지 않도록 한다.

// 풀이 코드

#include <bits/stdc++.h>
using namespace std;
#define fastio

bool IsPrime(int n) {       // 에라토스테네스의 체를 이용한 소수 판별 함수
    if (n < 2) return false;    // 2 미만의 수는 false 반환
    for (int i = 2; i * i <= n; i++) {      // 2부터 제곱이 n을 넘지 않는 수까지 반복하여 다른 수로 나누어 떨어진다면 false 반환
        if (n % i == 0) return false;
    }
    return true;        // false 반환이 되지 않은 경우 소수로 true 반환
}

int solution(string numbers) {
    int answer;         // 소수 수 확인 변수 answer
    answer = 0;         // answer은 0부터 시작
    vector<char> v;     // numbers의 각 자릿수를 저장하는 벡터
    for (int i = 0; i < numbers.size(); i++) {  // numbers의 크기만큼 반복하여 각 자릿수를 저장
        v.push_back(numbers[i]);
    }
    sort(v.begin(), v.end());       // 오름차순으로 정렬

    vector<int> v2;     // v의 수를 조합하여 만드는 값을 저장하는 벡터
    do {
        string tmp = "";        // tmp에 v의 요소를 조합
        for (int i = 0; i < v.size(); i++) {       // v에 저장된 요소만큼 반복
            tmp.push_back(v[i]);        // tmp에 v의 요소 추가
            v2.push_back(stoi(tmp));    // tmp에 저장된 값을 정수화하여 v2에 삽입
        }
    } while (next_permutation(v.begin(), v.end()));     // v에 저장된 요소들의 순열을 반복
    sort(v2.begin(), v2.end());     // v2를 오름차순 정렬
    v2.erase(unique(v2.begin(), v2.end()), v2.end());       // 정렬 후 v2의 요소 중 중복된 값 삭제

    for (int i = 0; i < v2.size(); i++) {       // v2의 모든 요소를 탐색
        if (IsPrime(v2[i])) answer++;           // IsPrime 함수를 통해 소수로 판별된 경우 answer + 1
    }

    return answer;
}

int main() {        // 실행을 위한 메인 함수
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    fastio;

    string numbers;
    cin >> numbers;
    int answer = solution(numbers);
    cout << answer << endl;

    return 0;
}
