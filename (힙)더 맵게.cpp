// 문제 설명
// 매운 것을 좋아하는 Leo는 모든 음식의 스코빌 지수를 K 이상으로 만들고 싶습니다.모든 음식의 스코빌 지수를 K 이상으로 만들기 위해 Leo는 스코빌 지수가 가장 낮은 두 개의 음식을 아래와 같이 특별한 방법으로 섞어 새로운 음식을 만듭니다.

// 섞은 음식의 스코빌 지수 = 가장 맵지 않은 음식의 스코빌 지수 + (두 번째로 맵지 않은 음식의 스코빌 지수 * 2)
// Leo는 모든 음식의 스코빌 지수가 K 이상이 될 때까지 반복하여 섞습니다.
// Leo가 가진 음식의 스코빌 지수를 담은 배열 scoville과 원하는 스코빌 지수 K가 주어질 때, 모든 음식의 스코빌 지수를 K 이상으로 만들기 위해 섞어야 하는 최소 횟수를 return 하도록 solution 함수를 작성해주세요.

// 제한 사항
// scoville의 길이는 2 이상 1, 000, 000 이하입니다.
// K는 0 이상 1, 000, 000, 000 이하입니다.
// scoville의 원소는 각각 0 이상 1, 000, 000 이하입니다.
// 모든 음식의 스코빌 지수를 K 이상으로 만들 수 없는 경우에는 - 1을 return 합니다.
// 입출력 예
// scoville	                    K	    return
// [1, 2, 3, 9, 10, 12]	        7	    2

// 입출력 예 설명
// 스코빌 지수가 1인 음식과 2인 음식을 섞으면 음식의 스코빌 지수가 아래와 같이 됩니다.
// 새로운 음식의 스코빌 지수 = 1 + (2 * 2) = 5
// 가진 음식의 스코빌 지수 = [5, 3, 9, 10, 12]

// 스코빌 지수가 3인 음식과 5인 음식을 섞으면 음식의 스코빌 지수가 아래와 같이 됩니다.
// 새로운 음식의 스코빌 지수 = 3 + (5 * 2) = 13
// 가진 음식의 스코빌 지수 = [13, 9, 10, 12]

// 모든 음식의 스코빌 지수가 7 이상이 되었고 이때 섞은 횟수는 2회입니다.

// 설명
// 우선순위 큐에 오름차순으로 값을 넣은 후 가장 작은 값이 k보다 작을 경우 그 값과 다음에 위치한 값을 계산하여 다시 큐에 삽입한다.
// 결과적으로 가장 작은 값이 k 이상일 경우 모든 값이 k 이상이므로 실행 횟수를 반환하며 종료된다.

// 풀이 코드

#include <bits/stdc++.h>
using namespace std;
#define fastio

int solution(vector<int> scoville, int K) {         // 스코빌 지수 벡터와 최소 지수 k를 인자로 받은 함수
    int answer = 0;             // 음식을 섞은 횟수
    priority_queue<int, vector<int>, greater<int>> pq;          // 오름차순으로 정렬되는 우선순위 큐
    for (int i = 0; i < scoville.size(); i++) {         // scoville의 모든 값을 우선순위 큐에 삽입
        pq.push(scoville[i]);
    }
    while (true) {
        if (pq.size() < 2 && pq.top() < K) return -1;       // pq의 크기가 2미만으로 조합이 불가능하지만 K보다 작은 스코빌 지수를 가진 경우 -1 반환
        if(pq.top() >= K) break;            // 가장 작은 수가 K이상인 경우 반복문 종료 후 섞은 횟수 반환
        int fst = pq.top();         // 위의 경우가 아닐 경우 top을 저장 후 삭제
        pq.pop();
        int scd = pq.top();         // 첫 번째 top이 삭제되어 두 번째로 작은 수가 top이 되었으니 다시 top을 저장 후 삭제
        pq.pop();
        int sum = fst + scd * 2;    // 저장한 두 값을 계산하여 sum에 저장 후 다시 큐에 삽입
        pq.push(sum);
        answer++;                   // 섞은 횟수+1
    }

    return answer;
}

int main() {        // 실행을 위한 메인 함수
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    fastio;

    vector<int> v;
    for (int i = 0; i < 6; i++) {
        int n;
        cin >> n;
        v.push_back(n);
    }
    int k;
    cin >> k;
    int answer = solution(v, k);
    cout << answer << endl;

    return 0;
}