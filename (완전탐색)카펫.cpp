// 문제 설명
// Leo는 카펫을 사러 갔다가 아래 그림과 같이 중앙에는 노란색으로 칠해져 있고 테두리 1줄은 갈색으로 칠해져 있는 격자 모양 카펫을 봤습니다.
// Leo는 집으로 돌아와서 아까 본 카펫의 노란색과 갈색으로 색칠된 격자의 개수는 기억했지만, 전체 카펫의 크기는 기억하지 못했습니다.
// Leo가 본 카펫에서 갈색 격자의 수 brown, 노란색 격자의 수 yellow가 매개변수로 주어질 때 카펫의 가로, 세로 크기를 순서대로 배열에 담아 return 하도록 solution 함수를 작성해주세요.

// 제한사항
// 갈색 격자의 수 brown은 8 이상 5, 000 이하인 자연수입니다.
// 노란색 격자의 수 yellow는 1 이상 2, 000, 000 이하인 자연수입니다.
// 카펫의 가로 길이는 세로 길이와 같거나, 세로 길이보다 깁니다.

// 입출력 예
// brown	yellow	return
// 10	    2[      4, 3]
// 8	    1       [3, 3]
// 24	    24      [8, 6]

// 설명
// brown은 테두리이고 yellow는 중앙이기 때문에 최소 높이는 갈-노-갈로 3이어야 한다.
// 전체 카펫의 넓이는 brown과 yellow 수의 합이므로 높이를 3으로 부터 시작해서 전체 크기에서 높이를 나누어 너비를 구한다.
// 테두리를 제외한 부분이 yellow이므로 높이, 너비를 각각 2씩 빼고 곱한 값이 yellow의 수이다.

// 풀이코드

#include <bits/stdc++.h>
using namespace std;
#define fastio

vector<int> solution(int brown, int yellow) { 
    vector<int> answer;     // 너비와 높이가 저장되는 벡터 answer
    int sum = brown + yellow;       // 전체 타일의 넓이 = brown과 yellow 수의 합
    int height = 3;     // 최소 높이는 3부터 시작한다.

    while (true) {      // 결과가 도출되기 전까지 무한반복
        int weight = sum / height;      // 너비 = 넓이 / 높이
        if ((height - 2) * (weight - 2) == yellow) {        // 너비와 높이에서 테두리를 제외한 부분(2를 뺌)이 yellow의 수와 일치하는 경우
            answer.push_back(weight);       // 너비와 높이를 answer에 삽입
            answer.push_back(height);
            break;      // 반복문 종료
        }
        height++;       // 결과가 도출되지 않을 경우 높이 + 1 후 다시 반복
    }

    return answer;
}

int main() {        // 실행을 위한 메인 함수
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    fastio;

    int b, y;
    cin >> b >> y;
    vector<int> answer = solution(b, y);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }

    return 0;
}
