// 문제 설명
// 트럭 여러 대가 강을 가로지르는 일 차선 다리를 정해진 순으로 건너려 합니다. 모든 트럭이 다리를 건너려면 최소 몇 초가 걸리는지 알아내야 합니다. 트럭은 1초에 1만큼 움직이며, 다리 길이는 bridge_length이고 다리는 무게 weight까지 견딥니다.
// ※ 트럭이 다리에 완전히 오르지 않은 경우, 이 트럭의 무게는 고려하지 않습니다.

// 예를 들어, 길이가 2이고 10kg 무게를 견디는 다리가 있습니다. 무게가 [7, 4, 5, 6]kg인 트럭이 순서대로 최단 시간 안에 다리를 건너려면 다음과 같이 건너야 합니다.

// 경과 시간     다리를 지난 트럭	   다리를 건너는 트럭	    대기 트럭
// 0	        []	                []	                    [7,4,5,6]
// 1~2	        []  	            [7]	                    [4,5,6]
// 3	        [7]	                [4]	                    [5,6]
// 4	        [7]	                [4,5]	                [6]
// 5	        [7,4]	            [5]	                    [6]
// 6~7	        [7,4,5]	            [6]	                    []
// 8	        [7,4,5,6]	        []	                    []
// 따라서, 모든 트럭이 다리를 지나려면 최소 8초가 걸립니다.

// solution 함수의 매개변수로 다리 길이 bridge_length, 다리가 견딜 수 있는 무게 weight, 트럭별 무게 truck_weights가 주어집니다. 이때 모든 트럭이 다리를 건너려면 최소 몇 초가 걸리는지 return 하도록 solution 함수를 완성하세요.

// 제한 조건
// bridge_length는 1 이상 10,000 이하입니다.
// weight는 1 이상 10,000 이하입니다.
// truck_weights의 길이는 1 이상 10,000 이하입니다.
// 모든 트럭의 무게는 1 이상 weight 이하입니다.

// 입출력 예
// bridge_length	    weight  	truck_weights	                    return
// 2	                10	        [7,4,5,6]	                        8
// 100          	    100	        [10]	                            101
// 100	                100	        [10,10,10,10,10,10,10,10,10,10] 	11


// 설명
// 큐를 다리라고 생각하고 시간의 흐름에 따라 트럭의 움직임을 큐로 표현하였다.
// 트럭이 움직이는 경우 트럭의 무게를 삽입하고 트럭이 위치하지 않은 경우 빈 값인 0을 삽입하여 풀이하였다.


// 풀이 코드

#include <bits/stdc++.h>
using namespace std;
#define fastio

int solution(int bridge_length, int weight, vector<int> truck_weights) {    // 큐를 이용한 풀이코드
    int answer = 0;         // 트럭이 다리를 지나는데 걸리는 시간
    int sum = 0;          // 다리 위를 지나가는 트럭의 총 무게 합
    int k = 0;          // 트럭의 차례를 확인하는 변수
    queue<int> q;       // 큐를 통해 각 초마다 지나가는 트럭 확인
    while(true) {
        if (k == truck_weights.size()) {    // truck_weights는 트럭의 무게가 저장된 벡터로 k를 통해 마지막 트럭이 들어온 경우를 확인
            answer += bridge_length;        // 이후 트럭이 다리를 건너지 않으므로 다리의 길이만큼 시간 초+
            break;                          // 반복문 중지
        }
        answer++;                   // 매 초마다 반복되므로 시간 초 1+
        if (q.size() == bridge_length) {        // 큐의 크기가 다리의 길이와 같은 경우 => 트럭이 큐에 삽입된 후 삽입된 0을 통해 큐의 후면(back)의 트럭이 다리를 전부 지남을 확인
            sum -= q.front();                   // 다리를 지난 트럭의 무게만큼 sum의 크기를 감소시켜 트럭이 전부 지남을 표현
            q.pop();                            // 큐에서 삭제
        }
        if (sum + truck_weights[k] <= weight) {     // 다리를 지나고 있는 트럭의 무게와 다음 트럭의 무게 합이 다리의 무게보다 작은 경우
            sum += truck_weights[k];                // 다리에 해당 트럭을 보냄으로 트럭 무게+
            q.push(truck_weights[k]);               // 큐에 삽입 후 k를 1+ 하여 다음 트럭 확인
            k++;
        }
        else {                                      // 다리의 무게보다 큰 경우
            q.push(0);                              // 비어있는 값인 0을 삽입 => 16~19줄의 q의 크기를 통해 다리 길이만큼의 시간 경과 확인
        }
    }

    return answer;
}

int main() {            // 직접 코드를 실행하여 입력에 따른 출력 결과를 확인할 수 없기 때문에 메인함수를 통해 변수를 입력받아 실행결과 확인
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    fastio;

    int len, wei;
    vector<int> v;
    cin >> len >> wei;
    for (int i = 0; i < 10; i++) {
        int k;
        cin >> k;
        v.push_back(k);
    }
    int answer = solution(len, wei, v);
    cout << answer << endl;

    return 0;
}
