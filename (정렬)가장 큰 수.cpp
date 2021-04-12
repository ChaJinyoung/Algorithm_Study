// 문제 설명
// 0 또는 양의 정수가 주어졌을 때, 정수를 이어 붙여 만들 수 있는 가장 큰 수를 알아내 주세요.

// 예를 들어, 주어진 정수가[6, 10, 2]라면[6102, 6210, 1062, 1026, 2610, 2106]를 만들 수 있고, 이중 가장 큰 수는 6210입니다.

// 0 또는 양의 정수가 담긴 배열 numbers가 매개변수로 주어질 때, 순서를 재배치하여 만들 수 있는 가장 큰 수를 문자열로 바꾸어 return 하도록 solution 함수를 작성해주세요.

// 제한 사항
// numbers의 길이는 1 이상 100, 000 이하입니다.
// numbers의 원소는 0 이상 1, 000 이하입니다.
// 정답이 너무 클 수 있으니 문자열로 바꾸어 return 합니다.
// 입출력 예
// numbers	            return
// [6, 10, 2]	        "6210"
// [3, 30, 34, 5, 9]	"9534330"

// 설명
// 정렬 기준을 정하는 함수 cmp를 통해 두 수를 이었을 때 더 높은 수가 되는 내림차순으로 정렬한다.
// 정렬 후 문자열이 0일 경우(모든 수를 더해도 0이 나오는 경우), 0을 즉시 반환한다.

// 풀이 코드

#include <bits/stdc++.h>
using namespace std;
#define fastio

bool cmp(string a, string b) {      // 정렬 시 두 문자열을 이었을 때 큰 순으로 정렬하는 함수 cmp
    return a + b > b + a;           // ex: a가 2이고 b가 3인 경우 23보다 32가 크기 때문에 3, 2 순으로 정렬
}

string solution(vector<int> numbers) {      // 정수가 입력된 벡터를 인자로 받는 함수
    string answer = "";         // 반환 결과를 저장하는 문자열 answer
    vector<string> v;       // 정수를 문자열로 바꾸어 저장하기 위한 벡터 v
    for (int i = 0; i < numbers.size(); i++) {  
        v.push_back(to_string(numbers[i]));     // numbers의 모든 정수를 문자열로 변환하여 v에 저장
    }
    sort(v.begin(), v.end(), cmp);      // cmp함수를 기반으로 정렬
    
    for (int i = 0; i < v.size(); i++) {
        answer += v[i];         // answer을 v에 저장된 문자열 순서대로 더하여 이어붙임
        if (answer == "0") return answer;       // answer이 0일 경우(가장 큰 수가 0일 경우) 0 반환 후 종료
    }

    return answer;
}

int main() {        // 실행을 위한 메인 함수
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    fastio;

    vector<int> v;
    for (int i = 0; i < 5; i++) {
        int n;       
        cin >> n;
        v.push_back(n);
    }
    string answer = solution(v);
    cout << answer << endl;

    return 0;
}