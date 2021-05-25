// 문제 설명
// 네트워크란 컴퓨터 상호 간에 정보를 교환할 수 있도록 연결된 형태를 의미합니다.예를 들어, 컴퓨터 A와 컴퓨터 B가 직접적으로 연결되어있고, 
// 컴퓨터 B와 컴퓨터 C가 직접적으로 연결되어 있을 때 컴퓨터 A와 컴퓨터 C도 간접적으로 연결되어 정보를 교환할 수 있습니다.따라서 컴퓨터 A, B, C는 모두 같은 네트워크 상에 있다고 할 수 있습니다.
// 컴퓨터의 개수 n, 연결에 대한 정보가 담긴 2차원 배열 computers가 매개변수로 주어질 때, 네트워크의 개수를 return 하도록 solution 함수를 작성하시오.

// 제한사항
// 컴퓨터의 개수 n은 1 이상 200 이하인 자연수입니다.
// 각 컴퓨터는 0부터 n - 1인 정수로 표현합니다.
// i번 컴퓨터와 j번 컴퓨터가 연결되어 있으면 computers[i][j]를 1로 표현합니다.
// computer[i][i]는 항상 1입니다.

// 입출력 예
// n	computers	                        return
// 3    [[1, 1, 0], [1, 1, 0], [0, 0, 1]]   2
// 3    [[1, 1, 0], [1, 1, 1], [0, 1, 1]]   1

// 설명
// 깊이 우선 탐색을 통해 벡터를 탐색한다.
// 탐색하고자 하는 값에서 연결된 값(1)이 있을 경우 계속 탐색하고 없을 경우 0을 반환하여 연결이 없음을 나타낸다.
// 벡터 전체를 탐색하고 연결되지 않은 값이 있을 경우 answer의 더하여 네트워크 수를 반환한다.

// 풀이 코드

#include <bits/stdc++.h>
using namespace std;
#define fastio

bool dfs(int n, vector<vector<int>>& computers) {       // 깊이 우선 탐색
    if (!computers[n][n]) return false;     // 이미 탐색된 경우 false 반환
    computers[n][n] = 0;        // 탐색한 요소는 0으로 변환
    for (int i = 0; i < computers.size(); i++) {        // 탐색이 진행되지 않은 경우 전체적으로 탐색
        if (computers[n][i]) dfs(i, computers);     // 연결된(1) 경우 해당 벡터와 연결된 다른 요소들을 dfs로 탐색
    }
    return true;        // 탐색이 완료된 경우 true 반환
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;     // 네트워크의 수
    for (int i = 0; i < n; i++) {       // n의 크기만큼 탐색
        if (computers[i][i] && dfs(i, computers)) answer++;     // 탐색을 마친 벡터 수 만큼 answer을 추가 (이미 탐색된 경우 연결된 경우이므로 0이 반환되어 네트워크 수 추가X)
    }
 
    return answer;
}

int main() {        // 실행을 위한 메인 함수
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    fastio;

    int answer = solution(3, { {1,1,0}, {1,1,0}, {0,0,1} });
    cout << answer << endl;

    return 0;
}