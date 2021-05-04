// ���� ����
// ���ڸ� ���ڰ� ���� ���� ������ ������ֽ��ϴ�.����� ���� ������ �ٿ� �Ҽ��� �� �� ���� �� �ִ��� �˾Ƴ��� �մϴ�.
// �� ���� ������ ���� ���ڰ� ���� ���ڿ� numbers�� �־����� ��, ���� �������� ���� �� �ִ� �Ҽ��� �� ������ return �ϵ��� solution �Լ��� �ϼ����ּ���.

// ���ѻ���
// numbers�� ���� 1 �̻� 7 ������ ���ڿ��Դϴ�.
// numbers�� 0~9���� ���ڸ����� �̷���� �ֽ��ϴ�.
// "013"�� 0, 1, 3 ���ڰ� ���� ���� ������ ������ִٴ� �ǹ��Դϴ�.

// ����� ��
// numbers	    return
// "17"	        3
// "011"	    2

// ����� �� ����
// ���� #1
// [1, 7]���δ� �Ҽ�[7, 17, 71]�� ���� �� �ֽ��ϴ�.
// ���� #2
// [0, 1, 1]���δ� �Ҽ�[11, 101]�� ���� �� �ֽ��ϴ�.

// 11�� 011�� ���� ���ڷ� ����մϴ�.

// ����
// �����佺�׳׽��� ü�� ���� �Ҽ��� �Ǻ��ϴ� �Լ��� ����Ѵ�.
// �Է¹��� ���ڿ� ���� �и��Ͽ� next_permutation�� ���� �и��� ���� ������ ���� �����Ͽ� �����Ѵ�.
// ���Ϳ� ����� ���� �ߺ��� �����Ͽ� �ߺ��� ���� ���� �ʵ��� �Ѵ�.

// Ǯ�� �ڵ�

#include <bits/stdc++.h>
using namespace std;
#define fastio

bool IsPrime(int n) {       // �����佺�׳׽��� ü�� �̿��� �Ҽ� �Ǻ� �Լ�
    if (n < 2) return false;    // 2 �̸��� ���� false ��ȯ
    for (int i = 2; i * i <= n; i++) {      // 2���� ������ n�� ���� �ʴ� ������ �ݺ��Ͽ� �ٸ� ���� ������ �������ٸ� false ��ȯ
        if (n % i == 0) return false;
    }
    return true;        // false ��ȯ�� ���� ���� ��� �Ҽ��� true ��ȯ
}

int solution(string numbers) {
    int answer;         // �Ҽ� �� Ȯ�� ���� answer
    answer = 0;         // answer�� 0���� ����
    vector<char> v;     // numbers�� �� �ڸ����� �����ϴ� ����
    for (int i = 0; i < numbers.size(); i++) {  // numbers�� ũ�⸸ŭ �ݺ��Ͽ� �� �ڸ����� ����
        v.push_back(numbers[i]);
    }
    sort(v.begin(), v.end());       // ������������ ����

    vector<int> v2;     // v�� ���� �����Ͽ� ����� ���� �����ϴ� ����
    do {
        string tmp = "";        // tmp�� v�� ��Ҹ� ����
        for (int i = 0; i < v.size(); i++) {       // v�� ����� ��Ҹ�ŭ �ݺ�
            tmp.push_back(v[i]);        // tmp�� v�� ��� �߰�
            v2.push_back(stoi(tmp));    // tmp�� ����� ���� ����ȭ�Ͽ� v2�� ����
        }
    } while (next_permutation(v.begin(), v.end()));     // v�� ����� ��ҵ��� ������ �ݺ�
    sort(v2.begin(), v2.end());     // v2�� �������� ����
    v2.erase(unique(v2.begin(), v2.end()), v2.end());       // ���� �� v2�� ��� �� �ߺ��� �� ����

    for (int i = 0; i < v2.size(); i++) {       // v2�� ��� ��Ҹ� Ž��
        if (IsPrime(v2[i])) answer++;           // IsPrime �Լ��� ���� �Ҽ��� �Ǻ��� ��� answer + 1
    }

    return answer;
}

int main() {        // ������ ���� ���� �Լ�
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    fastio;

    string numbers;
    cin >> numbers;
    int answer = solution(numbers);
    cout << answer << endl;

    return 0;
}
