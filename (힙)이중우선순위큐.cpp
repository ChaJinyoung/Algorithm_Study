// ���� ����
// ���� �켱���� ť�� ���� ������ �� �� �ִ� �ڷᱸ���� ���մϴ�.

// ��ɾ�	    ���� ž(����)
// I ����	    ť�� �־��� ���ڸ� �����մϴ�.
// D 1	        ť���� �ִ��� �����մϴ�.
// D - 1	    ť���� �ּڰ��� �����մϴ�.
// ���� �켱���� ť�� �� ���� operations�� �Ű������� �־��� ��, ��� ������ ó���� �� ť�� ���������[0, 0] ������� ������[�ִ�, �ּڰ�]�� return �ϵ��� solution �Լ��� �������ּ���.

// ���ѻ���
// operations�� ���̰� 1 �̻� 1, 000, 000 ������ ���ڿ� �迭�Դϴ�.
// operations�� ���Ҵ� ť�� ������ ������ ��Ÿ���ϴ�.
// ���Ҵ� ����ɾ� �����͡� �������� �־����ϴ�. - �ִ� / �ּڰ��� �����ϴ� ���꿡�� �ִ� / �ּڰ��� �� �̻��� ���, �ϳ��� �����մϴ�.
// �� ť�� �����͸� �����϶�� ������ �־��� ���, �ش� ������ �����մϴ�.

// ����� ��
// operations	                     return
// ["I 16", "D 1"]                   [0, 0]
// ["I 7", "I 5", "I -5", "D -1"]    [7, 5]
// ����� �� ����
// 16�� ���� �� �ִ��� �����մϴ�.��������Ƿ�[0, 0]�� ��ȯ�մϴ�.
// 7, 5, -5�� ���� �� �ּڰ��� �����մϴ�.�ִ밪 7, �ּҰ� 5�� ��ȯ�մϴ�.

// ����
// ������������ ���ĵ� �켱���� ť�� ������������ ���ĵ� �켱���� ť �� ���� �̿��Ͽ� �ִ񰪰� �ּڰ��� Ȯ���Ѵ�.
// size������ ���� �� ���� �켱���� ť �� �ϳ��� ��Ұ� ��ɾ ���� �����Ǵ��� ���� ũ�⸦ Ȯ���� �� �ְ� �Ͽ���.
// ���� ���õ� ���������� ����Ʈ�� ����ϴ� ���� �� ���� ������ �ڵ�� �ۼ��� �� ���ٰ� �����Ͽ���.

//Ǯ�� �ڵ�

#include <bits/stdc++.h>
using namespace std;
#define fastio

vector<int> solution(vector<string> operations) {       // ��ɾ ����� ���͸� ���ڷ� ���� �Լ�
    vector<int> answer;         // �ִ񰪰� �ּڰ��� ����� ����
    priority_queue<int> pq1;    // ������������ ����Ǵ� �켱���� ť
    priority_queue<int, vector<int>, greater<int>> pq2;     // ������������ ����Ǵ� �켱���� ť
    int size = 0;          // �켱���� ť�� ����� ��Ÿ���� ����
    for (int i = 0; i < operations.size(); i++) {       // operations�� ��� ��ü�� Ž��
        string str;
        if (size == 0) {        // �켱���� ť�� ����� 0�� ��� pq1�� pq2�� ���� �ʱ�ȭ
            while (!pq1.empty()) pq1.pop();
            while (!pq2.empty()) pq2.pop();
        }
        else {                  // �켱���� ť�� ������� ���� ���
            if (operations[i] == "D 1") {      // D 1�� �ԷµǾ��� �� �ִ��� �����ϹǷ� pq1 ��� ����
                pq1.pop();
                size--;             // ��Ұ� �����Ǿ��� ������ size -1
            }
            else if (operations[i] == "D -1") {     // D -1�� �ԷµǾ��� �� �ּڰ��� �����ϹǷ� pq2 ��� ����
                pq2.pop();
                size--;             // ��Ұ� �����Ǿ��� ������ size -1
            }
        }
        if (operations[i][0] == 'I') {      // ��ɾ I�� �����ϴ� ���
            pq1.push(stoi(operations[i].substr(2)));        // "I ����"�̱� ������ "I "�� ������ ������ ���� �κ��� stoi�� ���� ������ ���� �� pq1�� pq2�� ���� 
            pq2.push(stoi(operations[i].substr(2)));
            size++;
        }
    }
    if (size != 0) {        // size�� 0�� �ƴ� ��� pq1(�ִ�)�� pq2(�ּڰ�)���� �ϳ� �� ����
        answer.push_back(pq1.top());
        answer.push_back(pq2.top());
    }
    else {                  // size�� 0�� ��� 0�� �� �� ����
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}

int main() {        // ������ ���� ���� �Լ�
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