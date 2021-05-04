// ���� ����
// Leo�� ī���� �緯 ���ٰ� �Ʒ� �׸��� ���� �߾ӿ��� ��������� ĥ���� �ְ� �׵θ� 1���� �������� ĥ���� �ִ� ���� ��� ī���� �ý��ϴ�.
// Leo�� ������ ���ƿͼ� �Ʊ� �� ī���� ������� �������� ��ĥ�� ������ ������ ���������, ��ü ī���� ũ��� ������� ���߽��ϴ�.
// Leo�� �� ī�꿡�� ���� ������ �� brown, ����� ������ �� yellow�� �Ű������� �־��� �� ī���� ����, ���� ũ�⸦ ������� �迭�� ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

// ���ѻ���
// ���� ������ �� brown�� 8 �̻� 5, 000 ������ �ڿ����Դϴ�.
// ����� ������ �� yellow�� 1 �̻� 2, 000, 000 ������ �ڿ����Դϴ�.
// ī���� ���� ���̴� ���� ���̿� ���ų�, ���� ���̺��� ��ϴ�.

// ����� ��
// brown	yellow	return
// 10	    2[      4, 3]
// 8	    1       [3, 3]
// 24	    24      [8, 6]

// ����
// brown�� �׵θ��̰� yellow�� �߾��̱� ������ �ּ� ���̴� ��-��-���� 3�̾�� �Ѵ�.
// ��ü ī���� ���̴� brown�� yellow ���� ���̹Ƿ� ���̸� 3���� ���� �����ؼ� ��ü ũ�⿡�� ���̸� ������ �ʺ� ���Ѵ�.
// �׵θ��� ������ �κ��� yellow�̹Ƿ� ����, �ʺ� ���� 2�� ���� ���� ���� yellow�� ���̴�.

// Ǯ���ڵ�

#include <bits/stdc++.h>
using namespace std;
#define fastio

vector<int> solution(int brown, int yellow) { 
    vector<int> answer;     // �ʺ�� ���̰� ����Ǵ� ���� answer
    int sum = brown + yellow;       // ��ü Ÿ���� ���� = brown�� yellow ���� ��
    int height = 3;     // �ּ� ���̴� 3���� �����Ѵ�.

    while (true) {      // ����� ����Ǳ� ������ ���ѹݺ�
        int weight = sum / height;      // �ʺ� = ���� / ����
        if ((height - 2) * (weight - 2) == yellow) {        // �ʺ�� ���̿��� �׵θ��� ������ �κ�(2�� ��)�� yellow�� ���� ��ġ�ϴ� ���
            answer.push_back(weight);       // �ʺ�� ���̸� answer�� ����
            answer.push_back(height);
            break;      // �ݺ��� ����
        }
        height++;       // ����� ������� ���� ��� ���� + 1 �� �ٽ� �ݺ�
    }

    return answer;
}

int main() {        // ������ ���� ���� �Լ�
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
