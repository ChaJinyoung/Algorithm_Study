// 문제 설명
// n개의 음이 아닌 정수가 있습니다.이 수를 적절히 더하거나 빼서 타겟 넘버를 만들려고 합니다.예를 들어[1, 1, 1, 1, 1]로 숫자 3을 만들려면 다음 다섯 방법을 쓸 수 있습니다.
// - 1 + 1 + 1 + 1 + 1 = 3
// + 1 - 1 + 1 + 1 + 1 = 3
// + 1 + 1 - 1 + 1 + 1 = 3
// + 1 + 1 + 1 - 1 + 1 = 3
// + 1 + 1 + 1 + 1 - 1 = 3
// 사용할 수 있는 숫자가 담긴 배열 numbers, 타겟 넘버 target이 매개변수로 주어질 때 숫자를 적절히 더하고 빼서 타겟 넘버를 만드는 방법의 수를 return 하도록 solution 함수를 작성해주세요.

// 제한사항
// 주어지는 숫자의 개수는 2개 이상 20개 이하입니다.
// 각 숫자는 1 이상 50 이하인 자연수입니다.
// 타겟 넘버는 1 이상 1000 이하인 자연수입니다.

// 입출력 예
// numbers	        target	    return
// [1, 1, 1, 1, 1]	3	        5

// 설명
// 깊이 우선 탐색으로 벡터의 모든 수를 탐색한다.
// 탐색한 수를 더하거나 빼는 모든 경우의 수를 재귀함수를 통해 실행한다.
// 모든 값을 연산했을 때 타겟 넘버와 일치하는 경우 추가적인 탐색을 종료한 후 이전으로 돌아간다. 

// 풀이 코드

#include <bits/stdc++.h>
using namespace std;
#define fastio

int tmp = 0;        // target이 되는 조합의 수에 대한 전역변수

void dfs(vector<int>& numbers, int target, int sum, int cnt) {      // 재귀함수이기 때문에 연산한 값 sum과 연산 수 cnt를 매개변수로 추가로 사용하는 깊이 우선 탐색
    if (cnt == numbers.size()) {        // 연산한 횟수가 numbers의 크기와 같은 경우(모든 수를 탐색한 경우)
        if (sum == target) tmp++;       // 연산한 값 sum이 target과 같은 경우 tmp를 추가 후 반환
        return;
    }
    dfs(numbers, target, sum + numbers[cnt], cnt + 1);      // sum에서 탐색한 수를 더해 재귀
    dfs(numbers, target, sum - numbers[cnt], cnt + 1);      // sum에서 탐색한 수를 뺀 후 재귀
}

int solution(vector<int> numbers, int target) {
    int answer = 0;     // tmp의 값을 반환하는 answer
    dfs(numbers, target, 0, 0);     // numbers와 target에 대해 깊이 우선 탐색(뒤의 인자 0, 0은 sum과 cnt를 0으로 시작함을 의미)
    answer = tmp;
    return answer;
}

int main() {        // 실행을 위한 메인 함수
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    fastio;

    int answer = solution({1,1,1,1,1}, 3);
    cout << answer << endl;

    return 0;
}