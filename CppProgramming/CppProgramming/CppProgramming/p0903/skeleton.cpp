#include <iostream>

using namespace std;

namespace nsInt {
    // �Է� ���� ���� �����̵� 0�� ��ȯ
    int val(int n) { return 0; }
    // �Է� ���� ���� 45�� ���ϱ�
    int incr(int n) {
        int sum = n;
        for (int i = 0; i < 10; i++)
            sum += i;
        return sum;
    }
    // �Է� ���� ���� 5�� ������
    int div(int n) {
        return n / 5;
    }

    // �Է� ���� ������ 5 ����
    int sub(int n) {
        return n - 5;
    }
    // �Է� ���� ������ 15 ����
    int sub2(int n) {
        return (n - 15);
    }
}

namespace nsDouble {
    // �Է� ���� ���� 1�� ���ϱ�
    double incr(double i) {
        i = i + 1;
        return i;
    }
    // �Է� ���� ���� 10�� ����
    double sub(double i) {
        return i - 10;
    }
    // �Է¹��� ���� 5�� ���ϱ�.
    double mul(double i) {
        i = i * 5;
        return i;
    }
    // �Է� ���� ���� 7.5�� ���ϱ�.
    double plus_half_p(double i) {
        double sum = i;
        double c = 0.5;
        while (c < 3) {
            sum += c;
            //std::cout << c << endl;
            c += 0.5;
        }
        return sum;
    }

}


int main() {

    int a = 30;
    cout << "a�� ����: " << a << endl;

    double b = 3.14;
    cout << "b�� ����: " << b << endl;

    int cal_a = nsInt::div(nsInt::sub2(nsInt::incr(a)));
    double cal_b = nsDouble::sub(nsDouble::plus_half_p(nsDouble::mul(b)));



    cout << "a�� ���� ���: " << cal_a << endl;
    cout << "b�� ���� ���: " << cal_b << endl;

    return 0;


}