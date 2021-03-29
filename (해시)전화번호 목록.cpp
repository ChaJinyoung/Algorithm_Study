// ���� ����
// ��ȭ��ȣ�ο� ���� ��ȭ��ȣ ��, �� ��ȣ�� �ٸ� ��ȣ�� ���ξ��� ��찡 �ִ��� Ȯ���Ϸ� �մϴ�.
// ��ȭ��ȣ�� ������ ���� ���, ������ ��ȭ��ȣ�� �������� ��ȭ��ȣ�� ���λ��Դϴ�.

// ������ : 119
// ���ؿ� : 97 674 223
// ������ : 11 9552 4421
// ��ȭ��ȣ�ο� ���� ��ȭ��ȣ�� ���� �迭 phone_book �� solution �Լ��� �Ű������� �־��� ��, � ��ȣ�� �ٸ� ��ȣ�� ���ξ��� ��찡 ������ false�� �׷��� ������ true�� return �ϵ��� solution �Լ��� �ۼ����ּ���.

// ���� ����
// phone_book�� ���̴� 1 �̻� 1, 000, 000 �����Դϴ�.
// �� ��ȭ��ȣ�� ���̴� 1 �̻� 20 �����Դϴ�.
// ���� ��ȭ��ȣ�� �ߺ��ؼ� ������� �ʽ��ϴ�.
// ����� ����
// phone_book	                            return
// ["119", "97674223", "1195524421"]    	false
// ["123", "456", "789"]	                true
// ["12", "123", "1235", "567", "88"]	    false

// ����� �� ����
// ����� �� #1
// �տ��� ������ ���� �����ϴ�.

// ����� �� #2
// �� ��ȣ�� �ٸ� ��ȣ�� ���λ��� ��찡 �����Ƿ�, ���� true�Դϴ�.

// ����� �� #3
// ù ��° ��ȭ��ȣ, ��12���� �� ��° ��ȭ��ȣ ��123���� ���λ��Դϴ�.���� ���� false�Դϴ�.

// ����
// ���̰� ª�� ��ȣ���� �� ��ȣ���� ���� �� �ݺ����� ���� ���λ縦 Ž��
// ȿ������ ���̱� ���� ���λ縦 �߰��� ��� ��� ������ �Ͽ� �Լ� ����

// Ǯ�� �ڵ�

#include <bits/stdc++.h>
using namespace std;
#define fastio

bool solution(vector<string> phone_book) {      // 
    bool answer = true;                     // ���λ� ���θ� Ȯ���ϴ� bool ���� answer
    sort(phone_book.begin(), phone_book.end());    // phone_book ����
    for (int i = 0; i < phone_book.size() - 1; i++) {       // phone_book ��ü�� Ž��
        if (phone_book[i + 1].find(phone_book[i]) == 0) {   // phone�� ��Ұ� ���� ��ҿ� ���ԵǴ� ���
            answer = false;                                 // answer�� false ó�� �� ��ȯ
            return answer;
        }
    }

    return answer;      // Ž�� ������ ���λ簡 ���� ��� true ��ȯ
}

int main() {        // ������ ���� ���� �Լ�
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    fastio;

    vector<string> v;
    for (int i = 0; i < 3; i++) {
        string str;
        cin >> str;
        v.push_back(str);
    }
    bool answer = solution(v);
    if (answer) cout << "true" << endl;
    else cout << "false" << endl;

    return 0;
}