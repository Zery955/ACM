#include<ext/rope>

using namespace __gnu_cxx;  // ע�����ƿռ�

rope<int> rp;

int main() {

    rp.push_back(x); // ��ĩβ���� x

    rp.insert(pos, x); // �� pos ������ x

    rp.erase(pos, x); // �� pos ��ɾ�� x ��Ԫ��

    rp.length(); // ���� rp �Ĵ�С

    rp.size(); // ͬ��

    rp.replace(pos, x); // �� pos ����Ԫ���滻�� x

    rp.substr(pos, x); // �� pos ����ʼ��ȡ x ��Ԫ��

    rp.copy(pos, x, s); // �� pos ����ʼ���� x ��Ԫ�ص� s ��

    rp[x]; // ���ʵ� x ��Ԫ��

    rp.at(x); // ͬ��

    return 0;
}