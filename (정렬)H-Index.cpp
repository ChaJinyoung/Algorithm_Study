// 문제 설명
// H - Index는 과학자의 생산성과 영향력을 나타내는 지표입니다.어느 과학자의 H - Index를 나타내는 값인 h를 구하려고 합니다.위키백과1에 따르면, H - Index는 다음과 같이 구합니다.

// 어떤 과학자가 발표한 논문 n편 중, h번 이상 인용된 논문이 h편 이상이고 나머지 논문이 h번 이하 인용되었다면 h의 최댓값이 이 과학자의 H - Index입니다.

// 어떤 과학자가 발표한 논문의 인용 횟수를 담은 배열 citations가 매개변수로 주어질 때, 이 과학자의 H - Index를 return 하도록 solution 함수를 작성해주세요.

// 제한사항
// 과학자가 발표한 논문의 수는 1편 이상 1, 000편 이하입니다.
// 논문별 인용 횟수는 0회 이상 10, 000회 이하입니다.

// 입출력 예
// citations	        return
// [3, 0, 6, 1, 5]	    3
// 입출력 예 설명
// 이 과학자가 발표한 논문의 수는 5편이고, 그중 3편의 논문은 3회 이상 인용되었습니다.그리고 나머지 2편의 논문은 3회 이하 인용되었기 때문에 이 과학자의 H - Index는 3입니다.

// 설명
// 내림차순으로 정렬 후 높은 수 부터 반복하여 citations의 요소가 반복 횟수 이상일 경우 H-Index를 1씩 증가시켰다.
// citations의 요소가 반복 횟수보다 작을 경우 내림차순 정렬로 인해 이후의 수도 작기 때문에 break로 반복문을 종료시킨다.
// 문제의 알고리즘을 이해하는 시간이 오래 걸렸지만 코딩 자체는 난이도가 높지 않았다.

// 풀이 코드

#include <bits/stdc++.h>
using namespace std;
#define fastio

int solution(vector<int> citations) {       // 정수가 입력된 벡터를 인자로 받는 함수
    int answer = 0;         // H-Index값을 저장하는 변수 answer
    sort(citations.begin(), citations.end(), greater<int>());       // 내림차순으로 citations을 정렬
    for (int i = 0; i < citations.size(); i++) {
        if (citations[i] > i) answer++;         // citations의 크기만큼 반복하여 citations의 요소가 반복횟수보다 클 경우 answer+
        else break;         // 작을 경우 이후의 요소들도 작기 때문에 break로 반복문 종료
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
    int answer = solution(v);
    cout << answer << endl;

    return 0;
}