// 문제 설명
// 계속되는 폭우로 일부 지역이 물에 잠겼습니다.물에 잠기지 않은 지역을 통해 학교를 가려고 합니다.집에서 학교까지 가는 길은 m x n 크기의 격자모양으로 나타낼 수 있습니다.
// 아래 그림은 m = 4, n = 3 인 경우입니다.

// 가장 왼쪽 위, 즉 집이 있는 곳의 좌표는(1, 1)로 나타내고 가장 오른쪽 아래, 즉 학교가 있는 곳의 좌표는(m, n)으로 나타냅니다.
// 격자의 크기 m, n과 물이 잠긴 지역의 좌표를 담은 2차원 배열 puddles이 매개변수로 주어집니다.오른쪽과 아래쪽으로만 움직여 집에서 학교까지 갈 수 있는 최단경로의 개수를 1, 000, 000, 007로 나눈 나머지를 return 하도록 solution 함수를 작성해주세요.

// 제한사항
// 격자의 크기 m, n은 1 이상 100 이하인 자연수입니다.
// m과 n이 모두 1인 경우는 입력으로 주어지지 않습니다.
// 물에 잠긴 지역은 0개 이상 10개 이하입니다.
// 집과 학교가 물에 잠긴 경우는 입력으로 주어지지 않습니다.

// 입출력 예
// m	n	    puddles	    return
// 4	3       [[2, 2]]    4

// 설명
// memo를 통해 각 좌표마다 해당 좌표까지의 경로 수를 받는다.
// check를 통해 이동할 수 없는 지역의 좌표를 입력받고 해당 지역의 경로 수를 0으로 설정한다.
// [1,1]의 경로 수는 [0,1]의 경로 수 +[1,0]의 경로 수인것 처럼 이전 행과 열의 경로 수를 더하여 계산한다.

// 풀이 코드

#include <bits/stdc++.h>
using namespace std;
#define fastio

int memo[101][101] = { 0 };     // 이동경로의 수에 관한 메모이제이션
int check[101][101] = { 0 };    // 물에 잠긴 지역을 표시하는 체크배열

int solution(int m, int n, vector<vector<int>> puddles) {       // 행, 열, 물에 잠긴 지역의 좌표를 매개로 받음
    int answer = 0;     // 학교로 가는 경로의 수

    for (int i = 0; i < puddles.size(); i++) {      // 물에 잠긴 지역의 수 만큼 반복
        check[puddles[i][1]][puddles[i][0]] = -1;   // check 배열에 물에 잠긴 지역을 -1로 표시
    }
    memo[1][0] = 1;     // 출발 후 처음 이동 경로를 1로 지정

    for (int i = 1; i <= n; i++) {  
        for (int j = 1; j <= m; j++) {      // 행과 열 만큼 반복 
            if (check[i][j] == -1) memo[i][j] = 0;      // 물에 잠긴 지역에 대한 이동 경로 수를 0으로 하여 이동 영향 없도록 함
            else memo[i][j] = (memo[i - 1][j] + memo[i][j - 1]) % 1000000007;       // 위 지역이 아닌 경우 각각 열과 행에서 이동한 경로 수를 더함
        }
    }
    answer = memo[n][m];        // 마지막 위치인 n,m에서의 경로 수가 최종 경로 수

    return answer;
}

int main() {        // 실행을 위한 메인 함수
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    fastio;

    int answer = solution(4, 3, { {2,2} });
    cout << answer << endl;

    return 0;
}