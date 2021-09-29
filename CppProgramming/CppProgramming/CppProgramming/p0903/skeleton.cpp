#include <iostream>

using namespace std;

namespace nsInt {
    // 입력 받은 수가 무엇이든 0을 반환
    int val(int n) { return 0; }
    // 입력 받은 수에 45를 더하기
    int incr(int n) {
        int sum = n;
        for (int i = 0; i < 10; i++)
            sum += i;
        return sum;
    }
    // 입력 받은 수를 5로 나누기
    int div(int n) {
        return n / 5;
    }

    // 입력 받은 수에서 5 빼기
    int sub(int n) {
        return n - 5;
    }
    // 입력 받은 수에서 15 빼기
    int sub2(int n) {
        return (n - 15);
    }
}

namespace nsDouble {
    // 입력 받은 수에 1을 더하기
    double incr(double i) {
        i = i + 1;
        return i;
    }
    // 입력 받은 수에 10을 빼기
    double sub(double i) {
        return i - 10;
    }
    // 입력받은 수에 5를 곱하기.
    double mul(double i) {
        i = i * 5;
        return i;
    }
    // 입력 받은 수에 7.5를 더하기.
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
    cout << "a의 값은: " << a << endl;

    double b = 3.14;
    cout << "b의 값은: " << b << endl;

    int cal_a = nsInt::div(nsInt::sub2(nsInt::incr(a)));
    double cal_b = nsDouble::sub(nsDouble::plus_half_p(nsDouble::mul(b)));



    cout << "a의 연산 결과: " << cal_a << endl;
    cout << "b의 연산 결과: " << cal_b << endl;

    return 0;


}