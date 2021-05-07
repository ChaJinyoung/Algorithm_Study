// 문제 설명
// 조이스틱으로 알파벳 이름을 완성하세요.맨 처음엔 A로만 이루어져 있습니다.
// ex) 완성해야 하는 이름이 세 글자면 AAA, 네 글자면 AAAA

// 조이스틱을 각 방향으로 움직이면 아래와 같습니다.

// ▲ - 다음 알파벳
// ▼ - 이전 알파벳(A에서 아래쪽으로 이동하면 Z로)
// ◀ - 커서를 왼쪽으로 이동(첫 번째 위치에서 왼쪽으로 이동하면 마지막 문자에 커서)
// ▶ - 커서를 오른쪽으로 이동
// 예를 들어 아래의 방법으로 "JAZ"를 만들 수 있습니다.

// - 첫 번째 위치에서 조이스틱을 위로 9번 조작하여 J를 완성합니다.
// - 조이스틱을 왼쪽으로 1번 조작하여 커서를 마지막 문자 위치로 이동시킵니다.
// - 마지막 위치에서 조이스틱을 아래로 1번 조작하여 Z를 완성합니다.
// 따라서 11번 이동시켜 "JAZ"를 만들 수 있고, 이때가 최소 이동입니다.
// 만들고자 하는 이름 name이 매개변수로 주어질 때, 이름에 대해 조이스틱 조작 횟수의 최솟값을 return 하도록 solution 함수를 만드세요.

// 제한 사항
// name은 알파벳 대문자로만 이루어져 있습니다.
// name의 길이는 1 이상 20 이하입니다.

// 입출력 예
// name	        return
// "JEROEN"	    56
// "JAN"	    23

// 설명
// 모든 문자가 A에서 시작하기 때문에 A를 기준으로 앞뒤로 빠른 값을 먼저 찾아 더한다.
// 해당 문자를 원하는 알파벳으로 맞춘 후 문자를 기준으로 앞뒤를 탐색하여 A가 아닌 값이 더 가까운 위치를 찾는다.

// 풀이 코드

#include <bits/stdc++.h>
using namespace std;
#define fastio

int solution(string name) {
    int answer = 0;     // 조이스틱을 조작한 횟수를 저장하는 변수 answer
    int l = 0, r = name.size() - 1;     // 문자를 탐색할 때 이전으로 돌아가기 위한 변수 l과 다음 위치를 찾는 변수 r
    for (int i = 0; i < name.size(); i++) {     // name의 문자 전체를 탐색
        int t = name.size();
        l += min(name[i] - 'A', 'Z' - name[i] + 1);     // 해당 알파벳이 A를 기준으로 더 적게 움직일 수 있는 횟수만큼 추가
        int next = i + 1;       // 다음 위치로 탐색한 횟수를 저장하는 변수 next
        while (next < t && name[next] == 'A') next++;       // A가 아닌 값이 나올 때까지 next값을 계속 더하며 탐색
        
        r = min(r, i + t - next + min(i, t - next));        // 해당 문자 기준으로 이전과 이후 중 더 빠른 경로만큼의 값을 r에 저장
    }
    l += r;     // r의 위치만큼 시작지점 l값 추가
    answer = l;     // 위의 과정을 통해 조작한 횟수를 answer에 저장
    return answer;
}

int main() {        // 실행을 위한 메인 함수
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    fastio;

    string str;
    cin >> str;
    int answer = solution(str);
    cout << answer << endl;

    return 0;
}