// ���� ����
// �����̵��� ���� �ٸ� ���� �����Ͽ� �Ծ� �ڽ��� �����մϴ�.

// ���� ��� �����̰� ���� ���� �Ʒ��� ���� ���� �����̰� ���׶� �Ȱ�, �� ��Ʈ, �Ķ��� Ƽ������ �Ծ��ٸ� �������� û������ �߰��� �԰ų� ���׶� �Ȱ� ��� ���� ���۶󽺸� �����ϰų� �ؾ� �մϴ�.

// ����	    �̸�
// ��	    ���׶� �Ȱ�, ���� ���۶�
// ����	    �Ķ��� Ƽ����
// ����	    û����
// �ѿ�	    �� ��Ʈ
// �����̰� ���� �ǻ���� ��� 2���� �迭 clothes�� �־��� �� ���� �ٸ� ���� ������ ���� return �ϵ��� solution �Լ��� �ۼ����ּ���.

// ���ѻ���
// clothes�� �� ����[�ǻ��� �̸�, �ǻ��� ����]�� �̷���� �ֽ��ϴ�.
// �����̰� ���� �ǻ��� ���� 1�� �̻� 30�� �����Դϴ�.
// ���� �̸��� ���� �ǻ��� �������� �ʽ��ϴ�.
// clothes�� ��� ���Ҵ� ���ڿ��� �̷���� �ֽ��ϴ�.
// ��� ���ڿ��� ���̴� 1 �̻� 20 ������ �ڿ����̰� ���ĺ� �ҹ��� �Ǵ� '_' �θ� �̷���� �ֽ��ϴ�.
// �����̴� �Ϸ翡 �ּ� �� ���� �ǻ��� �Խ��ϴ�.
// ����� ��
// clothes	                                                                                     return
// [["yellowhat", "headgear"], ["bluesunglasses", "eyewear"], ["green_turban", "headgear"]]      5
// [["crowmask", "face"], ["bluesunglasses", "face"], ["smoky_makeup", "face"]]                  3
// ����� �� ����
// ���� #1
// headgear�� �ش��ϴ� �ǻ��� yellow_hat, green_turban�̰� eyewear�� �ش��ϴ� �ǻ��� blue_sunglasses�̹Ƿ� �Ʒ��� ���� 5���� ������ �����մϴ�.

// 1. yellow_hat
// 2. blue_sunglasses
// 3. green_turban
// 4. yellow_hat + blue_sunglasses
// 5. green_turban + blue_sunglasses

// ���� #2
// face�� �ش��ϴ� �ǻ��� crow_mask, blue_sunglasses, smoky_makeup�̹Ƿ� �Ʒ��� ���� 3���� ������ �����մϴ�.

// 1. crow_mask
// 2. blue_sunglasses
// 3. smoky_makeup

// ����
// map�� �ߺ��� Ű ���� �������� �ʴ� ���� �̿��Ͽ� ������ key ������, ������ ���� value������ �Ͽ� �� ���� ������ ���� ����Ͽ���.
// ���� �Դ� ���� ���� �� ���� ������ ���� ���� �� + 1�� ���� �� -1�� �� ���̴�. (���� �ϳ� �̻� �Ծ�� �ϱ� ����)
 
// Ǯ�� �ڵ�

#include <bits/stdc++.h>
using namespace std;
#define fastio

int solution(vector<vector<string>> clothes) {      // ������ ���� clothes�� ���ڷ� �޴� �Լ�
    int answer = 0;                             // ���� �Դ� �������� ��Ÿ���� answer
    map<string, int> m;                         // ���� ������ key, �ش� ������ ���� ���� value�� ���� map
    for (int i = 0; i < clothes.size(); i++) {  // clothes ��ü Ž��
        m.insert(make_pair(clothes[i][1], 0));  // map�� clothes���� Ž���� ���� ������ ���� ��� ���� ����
        m.find(clothes[i][1])->second++;        // map�� ���Ե� ���� ������ �����ϴ� ��� + 1 (���� ��쿡�� ������ ���� ���ԵǾ� 1�� ���� ����)
    }
    map<string, int> ::iterator it;             // m�� iterator
    answer++;       // ������ ���� answer + 1
    for (it = m.begin(); it != m.end(); it++) { // m�� ��ü�� Ž���Ͽ� value�� + 1�� answer�� ��
        answer *= it->second + 1;
    }
    answer--;       // ���� �������� ����� �� -1

    return answer;
}

int main() {        // ������ ���� ���� �Լ�
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    fastio;

    vector<vector<string>> v;
    for (int i = 0; i < 3; i++) {
        string str1, str2;
        vector<string> v2;
        cin >> str1 >> str2;
        v2.push_back(str1);
        v2.push_back(str2);
        v.push_back(v2);
    }
    int answer = solution(v);
    cout << answer << endl;

    return 0;
}