// ���� ����
// H - Index�� �������� ���꼺�� ������� ��Ÿ���� ��ǥ�Դϴ�.��� �������� H - Index�� ��Ÿ���� ���� h�� ���Ϸ��� �մϴ�.��Ű���1�� ������, H - Index�� ������ ���� ���մϴ�.

// � �����ڰ� ��ǥ�� �� n�� ��, h�� �̻� �ο�� ���� h�� �̻��̰� ������ ���� h�� ���� �ο�Ǿ��ٸ� h�� �ִ��� �� �������� H - Index�Դϴ�.

// � �����ڰ� ��ǥ�� ���� �ο� Ƚ���� ���� �迭 citations�� �Ű������� �־��� ��, �� �������� H - Index�� return �ϵ��� solution �Լ��� �ۼ����ּ���.

// ���ѻ���
// �����ڰ� ��ǥ�� ���� ���� 1�� �̻� 1, 000�� �����Դϴ�.
// ���� �ο� Ƚ���� 0ȸ �̻� 10, 000ȸ �����Դϴ�.

// ����� ��
// citations	        return
// [3, 0, 6, 1, 5]	    3
// ����� �� ����
// �� �����ڰ� ��ǥ�� ���� ���� 5���̰�, ���� 3���� ���� 3ȸ �̻� �ο�Ǿ����ϴ�.�׸��� ������ 2���� ���� 3ȸ ���� �ο�Ǿ��� ������ �� �������� H - Index�� 3�Դϴ�.

// ����
// ������������ ���� �� ���� �� ���� �ݺ��Ͽ� citations�� ��Ұ� �ݺ� Ƚ�� �̻��� ��� H-Index�� 1�� �������״�.
// citations�� ��Ұ� �ݺ� Ƚ������ ���� ��� �������� ���ķ� ���� ������ ���� �۱� ������ break�� �ݺ����� �����Ų��.
// ������ �˰����� �����ϴ� �ð��� ���� �ɷ����� �ڵ� ��ü�� ���̵��� ���� �ʾҴ�.

// Ǯ�� �ڵ�

#include <bits/stdc++.h>
using namespace std;
#define fastio

int solution(vector<int> citations) {       // ������ �Էµ� ���͸� ���ڷ� �޴� �Լ�
    int answer = 0;         // H-Index���� �����ϴ� ���� answer
    sort(citations.begin(), citations.end(), greater<int>());       // ������������ citations�� ����
    for (int i = 0; i < citations.size(); i++) {
        if (citations[i] > i) answer++;         // citations�� ũ�⸸ŭ �ݺ��Ͽ� citations�� ��Ұ� �ݺ�Ƚ������ Ŭ ��� answer+
        else break;         // ���� ��� ������ ��ҵ鵵 �۱� ������ break�� �ݺ��� ����
    }

    return answer;
}

int main() {        // ������ ���� ���� �Լ�
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