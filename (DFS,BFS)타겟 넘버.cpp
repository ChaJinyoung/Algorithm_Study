// ���� ����
// n���� ���� �ƴ� ������ �ֽ��ϴ�.�� ���� ������ ���ϰų� ���� Ÿ�� �ѹ��� ������� �մϴ�.���� ���[1, 1, 1, 1, 1]�� ���� 3�� ������� ���� �ټ� ����� �� �� �ֽ��ϴ�.
// - 1 + 1 + 1 + 1 + 1 = 3
// + 1 - 1 + 1 + 1 + 1 = 3
// + 1 + 1 - 1 + 1 + 1 = 3
// + 1 + 1 + 1 - 1 + 1 = 3
// + 1 + 1 + 1 + 1 - 1 = 3
// ����� �� �ִ� ���ڰ� ��� �迭 numbers, Ÿ�� �ѹ� target�� �Ű������� �־��� �� ���ڸ� ������ ���ϰ� ���� Ÿ�� �ѹ��� ����� ����� ���� return �ϵ��� solution �Լ��� �ۼ����ּ���.

// ���ѻ���
// �־����� ������ ������ 2�� �̻� 20�� �����Դϴ�.
// �� ���ڴ� 1 �̻� 50 ������ �ڿ����Դϴ�.
// Ÿ�� �ѹ��� 1 �̻� 1000 ������ �ڿ����Դϴ�.

// ����� ��
// numbers	        target	    return
// [1, 1, 1, 1, 1]	3	        5

// ����
// ���� �켱 Ž������ ������ ��� ���� Ž���Ѵ�.
// Ž���� ���� ���ϰų� ���� ��� ����� ���� ����Լ��� ���� �����Ѵ�.
// ��� ���� �������� �� Ÿ�� �ѹ��� ��ġ�ϴ� ��� �߰����� Ž���� ������ �� �������� ���ư���. 

// Ǯ�� �ڵ�

#include <bits/stdc++.h>
using namespace std;
#define fastio

int tmp = 0;        // target�� �Ǵ� ������ ���� ���� ��������

void dfs(vector<int>& numbers, int target, int sum, int cnt) {      // ����Լ��̱� ������ ������ �� sum�� ���� �� cnt�� �Ű������� �߰��� ����ϴ� ���� �켱 Ž��
    if (cnt == numbers.size()) {        // ������ Ƚ���� numbers�� ũ��� ���� ���(��� ���� Ž���� ���)
        if (sum == target) tmp++;       // ������ �� sum�� target�� ���� ��� tmp�� �߰� �� ��ȯ
        return;
    }
    dfs(numbers, target, sum + numbers[cnt], cnt + 1);      // sum���� Ž���� ���� ���� ���
    dfs(numbers, target, sum - numbers[cnt], cnt + 1);      // sum���� Ž���� ���� �� �� ���
}

int solution(vector<int> numbers, int target) {
    int answer = 0;     // tmp�� ���� ��ȯ�ϴ� answer
    dfs(numbers, target, 0, 0);     // numbers�� target�� ���� ���� �켱 Ž��(���� ���� 0, 0�� sum�� cnt�� 0���� �������� �ǹ�)
    answer = tmp;
    return answer;
}

int main() {        // ������ ���� ���� �Լ�
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    fastio;

    int answer = solution({1,1,1,1,1}, 3);
    cout << answer << endl;

    return 0;
}