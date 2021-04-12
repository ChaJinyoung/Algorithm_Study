// ���� ����
// 0 �Ǵ� ���� ������ �־����� ��, ������ �̾� �ٿ� ���� �� �ִ� ���� ū ���� �˾Ƴ� �ּ���.

// ���� ���, �־��� ������[6, 10, 2]���[6102, 6210, 1062, 1026, 2610, 2106]�� ���� �� �ְ�, ���� ���� ū ���� 6210�Դϴ�.

// 0 �Ǵ� ���� ������ ��� �迭 numbers�� �Ű������� �־��� ��, ������ ���ġ�Ͽ� ���� �� �ִ� ���� ū ���� ���ڿ��� �ٲپ� return �ϵ��� solution �Լ��� �ۼ����ּ���.

// ���� ����
// numbers�� ���̴� 1 �̻� 100, 000 �����Դϴ�.
// numbers�� ���Ҵ� 0 �̻� 1, 000 �����Դϴ�.
// ������ �ʹ� Ŭ �� ������ ���ڿ��� �ٲپ� return �մϴ�.
// ����� ��
// numbers	            return
// [6, 10, 2]	        "6210"
// [3, 30, 34, 5, 9]	"9534330"

// ����
// ���� ������ ���ϴ� �Լ� cmp�� ���� �� ���� �̾��� �� �� ���� ���� �Ǵ� ������������ �����Ѵ�.
// ���� �� ���ڿ��� 0�� ���(��� ���� ���ص� 0�� ������ ���), 0�� ��� ��ȯ�Ѵ�.

// Ǯ�� �ڵ�

#include <bits/stdc++.h>
using namespace std;
#define fastio

bool cmp(string a, string b) {      // ���� �� �� ���ڿ��� �̾��� �� ū ������ �����ϴ� �Լ� cmp
    return a + b > b + a;           // ex: a�� 2�̰� b�� 3�� ��� 23���� 32�� ũ�� ������ 3, 2 ������ ����
}

string solution(vector<int> numbers) {      // ������ �Էµ� ���͸� ���ڷ� �޴� �Լ�
    string answer = "";         // ��ȯ ����� �����ϴ� ���ڿ� answer
    vector<string> v;       // ������ ���ڿ��� �ٲپ� �����ϱ� ���� ���� v
    for (int i = 0; i < numbers.size(); i++) {  
        v.push_back(to_string(numbers[i]));     // numbers�� ��� ������ ���ڿ��� ��ȯ�Ͽ� v�� ����
    }
    sort(v.begin(), v.end(), cmp);      // cmp�Լ��� ������� ����
    
    for (int i = 0; i < v.size(); i++) {
        answer += v[i];         // answer�� v�� ����� ���ڿ� ������� ���Ͽ� �̾����
        if (answer == "0") return answer;       // answer�� 0�� ���(���� ū ���� 0�� ���) 0 ��ȯ �� ����
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
    string answer = solution(v);
    cout << answer << endl;

    return 0;
}