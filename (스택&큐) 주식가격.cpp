// 문제 설명
// 초 단위로 기록된 주식가격이 담긴 배열 prices가 매개변수로 주어질 때, 가격이 떨어지지 않은 기간은 몇 초인지를 return 하도록 solution 함수를 완성하세요.

// 제한사항
// prices의 각 가격은 1 이상 10,000 이하인 자연수입니다.
// prices의 길이는 2 이상 100,000 이하입니다.

// 입출력 예
// prices	        return
// [1, 2, 3, 2, 3]	[4, 3, 1, 1, 0]

// 입출력 예 설명
// 1초 시점의 ₩1은 끝까지 가격이 떨어지지 않았습니다.
// 2초 시점의 ₩2은 끝까지 가격이 떨어지지 않았습니다.
// 3초 시점의 ₩3은 1초뒤에 가격이 떨어집니다. 따라서 1초간 가격이 떨어지지 않은 것으로 봅니다.
// 4초 시점의 ₩2은 1초간 가격이 떨어지지 않았습니다.
// 5초 시점의 ₩3은 0초간 가격이 떨어지지 않았습니다.


// 설명
// 해당 인덱스를 기준으로 인덱스의 값보다 작은 수가 나올 때까지의 인덱스 수를 세는 문제이다.
// 스택이나 큐의 필요성을 크게 느끼지 못했지만 최대한 활용하는 방안을 찾기 위해 큐를 사용하였다.


// 풀이코드

#include <bits/stdc++.h>
using namespace std;
#define fastio

vector<int> solution(vector<int> prices) {         // 큐의 크기와 반복문을 이용하여 큐에 지나간 
    vector<int> answer;
    queue<int> q;
    for (int i = 0; i < prices.size(); i++) {       // 입력된 벡터의 값들을 큐에 복사
        q.push(prices[i]); 
    }

    while (!q.empty()) {        // 큐 내부의 요소를 탐색 후 삭제하여 최종적으로 큐가 비어있을 때까지 반복
        int n, t = q.front();       // 반복문이 끝난 후 i값을 저장하는 변수 n, 최근 삽입된 큐의 요소를 저장한 변수 t
        int len = prices.size() - q.size();     // 삭제된 큐 요소의 수를 확인하는 변수
        for (int i = len; i < prices.size(); i++) {     // len부터 벡터의 크기까지 반복하여 큐 전체 탐색
            n = i;                          // i값을 n에 저장
            if (prices[i] < t) break;       // 큐의 front값인 t와 벡터의 요소를 비교하여 t값이 더 클 경우 반복문 중지
        }
        answer.push_back(n - len);          // answer에 n에서 len을 뺀 값(해당 요소부터 break부분까지 지나간 길이)을 answer에 삽입
        q.pop();        // q의 요소 삭제
    }
    return answer;
}

int main() {        // 입력값에 따른 출력 결과 확인을 위한 메인 함수
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    fastio;

    vector<int> v;
    for (int i = 0; i < 6; i++) {
        int k;
        cin >> k;
        v.push_back(k);
    }
    vector<int> answer = solution(v);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }

    return 0;
}
