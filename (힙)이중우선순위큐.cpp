// 문제 설명
// 이중 우선순위 큐는 다음 연산을 할 수 있는 자료구조를 말합니다.

// 명령어	    수신 탑(높이)
// I 숫자	    큐에 주어진 숫자를 삽입합니다.
// D 1	        큐에서 최댓값을 삭제합니다.
// D - 1	    큐에서 최솟값을 삭제합니다.
// 이중 우선순위 큐가 할 연산 operations가 매개변수로 주어질 때, 모든 연산을 처리한 후 큐가 비어있으면[0, 0] 비어있지 않으면[최댓값, 최솟값]을 return 하도록 solution 함수를 구현해주세요.

// 제한사항
// operations는 길이가 1 이상 1, 000, 000 이하인 문자열 배열입니다.
// operations의 원소는 큐가 수행할 연산을 나타냅니다.
// 원소는 “명령어 데이터” 형식으로 주어집니다. - 최댓값 / 최솟값을 삭제하는 연산에서 최댓값 / 최솟값이 둘 이상인 경우, 하나만 삭제합니다.
// 빈 큐에 데이터를 삭제하라는 연산이 주어질 경우, 해당 연산은 무시합니다.

// 입출력 예
// operations	                     return
// ["I 16", "D 1"]                   [0, 0]
// ["I 7", "I 5", "I -5", "D -1"]    [7, 5]
// 입출력 예 설명
// 16을 삽입 후 최댓값을 삭제합니다.비어있으므로[0, 0]을 반환합니다.
// 7, 5, -5를 삽입 후 최솟값을 삭제합니다.최대값 7, 최소값 5를 반환합니다.

// 설명
// 오름차순으로 정렬된 우선순위 큐와 내림차순으로 정렬된 우선순위 큐 두 개를 이용하여 최댓값과 최솟값을 확인한다.
// size변수를 통해 두 개의 우선순위 큐 중 하나의 요소가 명령어에 의해 삭제되더라도 남은 크기를 확인할 수 있게 하였다.
// 힙에 관련된 문제이지만 리스트를 사용하는 것이 더 쉽고 간단한 코드로 작성될 것 같다고 생각하였다.

//풀이 코드

#include <bits/stdc++.h>
using namespace std;
#define fastio

vector<int> solution(vector<string> operations) {       // 명령어가 저장된 벡터를 인자로 받은 함수
    vector<int> answer;         // 최댓값과 최솟값이 저장된 벡터
    priority_queue<int> pq1;    // 내림차순으로 저장되는 우선순위 큐
    priority_queue<int, vector<int>, greater<int>> pq2;     // 오름차순으로 저장되는 우선순위 큐
    int size = 0;          // 우선순위 큐의 사이즈를 나타내는 변수
    for (int i = 0; i < operations.size(); i++) {       // operations의 요소 전체를 탐색
        string str;
        if (size == 0) {        // 우선순위 큐의 사이즈가 0일 경우 pq1과 pq2를 전부 초기화
            while (!pq1.empty()) pq1.pop();
            while (!pq2.empty()) pq2.pop();
        }
        else {                  // 우선순위 큐가 비어있지 않을 경우
            if (operations[i] == "D 1") {      // D 1이 입력되었을 때 최댓값을 삭제하므로 pq1 요소 삭제
                pq1.pop();
                size--;             // 요소가 삭제되었기 때문에 size -1
            }
            else if (operations[i] == "D -1") {     // D -1이 입력되었을 때 최솟값을 삭제하므로 pq2 요소 삭제
                pq2.pop();
                size--;             // 요소가 삭제되었기 때문에 size -1
            }
        }
        if (operations[i][0] == 'I') {      // 명령어가 I로 시작하는 경우
            pq1.push(stoi(operations[i].substr(2)));        // "I 숫자"이기 때문에 "I "를 제외한 나머지 숫자 부분을 stoi를 통해 정수로 변경 후 pq1과 pq2에 삽입 
            pq2.push(stoi(operations[i].substr(2)));
            size++;
        }
    }
    if (size != 0) {        // size가 0이 아닐 경우 pq1(최댓값)과 pq2(최솟값)에서 하나 씩 삽입
        answer.push_back(pq1.top());
        answer.push_back(pq2.top());
    }
    else {                  // size가 0일 경우 0을 두 번 삽입
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}

int main() {        // 실행을 위한 메인 함수
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    fastio;

    vector<string> v;
    for (int i = 0; i < 4; i++) {
        string str;
        getline(cin, str);
        v.push_back(str);
    }
    vector<int> answer = solution(v);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }

    return 0;
}