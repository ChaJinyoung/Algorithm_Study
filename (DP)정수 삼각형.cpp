// 문제 설명
// 위와 같은 삼각형의 꼭대기에서 바닥까지 이어지는 경로 중, 거쳐간 숫자의 합이 가장 큰 경우를 찾아보려고 합니다.아래 칸으로 이동할 때는 대각선 방향으로 한 칸 오른쪽 또는 왼쪽으로만 이동 가능합니다.예를 들어 3에서는 그 아래칸의 8 또는 1로만 이동이 가능합니다.

// 삼각형의 정보가 담긴 배열 triangle이 매개변수로 주어질 때, 거쳐간 숫자의 최댓값을 return 하도록 solution 함수를 완성하세요.

// 제한사항
// 삼각형의 높이는 1 이상 500 이하입니다.
// 삼각형을 이루고 있는 숫자는 0 이상 9, 999 이하의 정수입니다.
// 입출력 예
// triangle	                                                    result
// [[7], [3, 8], [8, 1, 0], [2, 7, 4, 4], [4, 5, 2, 6, 5]]      30

// 설명
// 삼각형의 경로를 지나 더한 값을 memo에 저장한다.
// 가장 왼쪽, 오른쪽에 위치한 경우 더하는 선택지가 없기 때문에 따로 특수 조건을 분류한다.
// 바닥에 저장된 값을 비교하여 최댓값을 반환한다.

// 풀이 코드

#include <bits/stdc++.h>
using namespace std;
#define fastio

int memo[500][500];     // 높이 500까지의 삼각형의 메모이제이션

int solution(vector<vector<int>> triangle) {        // 각 높이마다 삼각형의 수가 적힌 벡터를 매개로 받음
    int answer = 0;     // 가장 큰 수를 지나가는 경로
    memo[0][0] = triangle[0][0];        // 꼭대기의 삼각형 정보를 memo에 저장
    for (int i = 1; i < triangle.size(); i++) {     // triangle의 크기(삼각형의 높이)만큼 반복
        for (int j = 0; j < triangle[i].size(); j++) {      // 각 triangle의 이차원 벡터(삼각형의 너비)만큼 반복
            memo[i][j] = triangle[i][j];        // memo에 triangle 값 저장
            if (j == 0) memo[i][j] += memo[i - 1][0];       // 가장 왼쪽(j=0)의 경우 이전 높이의 왼쪽 값 추가
            else if (j == i) memo[i][j] += memo[i - 1][j - 1];      // 가장 오른쪽(j=i)의 경우 이전 높이의 오른쪽 값 추가
            else memo[i][j] += max(memo[i - 1][j - 1], memo[i - 1][j]);     // 중간의 경우 이전 높이의 좌측, 우측 값 중 높은 값 추가
        }
    }
    for (int i = 0; i < triangle.size(); i++) {     // 삼각형 밑바닥의 memo에 저장된 값 비교
        answer = max(answer, memo[triangle.size()-1][i]);       // 비교한 수 중 가장 큰 값을 answer에 저장
    }

    return answer;
}

int main() {        // 실행을 위한 메인 함수
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    fastio;

    int answer = solution({ { 7 }, { 3, 8 }, { 8, 1, 0 }, { 2, 7, 4, 4 }, { 4, 5, 2, 6, 5 } });
    cout << answer << endl;

    return 0;
}