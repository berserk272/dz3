#include <iostream>
#include <cmath>
using namespace std;

void Zaem() {
    double S, p, r, m;
    int n;
    cout << "Задание 3.1 Заём" << "\n";
    cout << "Введите сумму займа (в рублях): ";
    cin >> S;
    cout << "Введите процентную ставку (годовая): ";
    cin >> p;
    cout << "Введите срок займа (в годах): ";
    cin >> n;
    r = p / 100;
    m = (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
    cout << "Месячная выплата: " << m << " рублей" << "\n";
}

void Ssuda() {
    cout << "Задание 3.2 Ссуда" << "\n";
    double S, m, n, r, p;
    cout << "Введите сумму ссуды (S рублей): ";
    cin >> S;
    cout << "Введите месячную выплату (m рублей): ";
    cin >> m;
    cout << "Введите количество лет (n лет): ";
    cin >> n;
    double lowerBound = 0.0;
    double upperBound = 1.0;
    double epsilon = 0.0001;
    while (true) {
        r = (lowerBound + upperBound) / 2;
        double calculatedM = (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
        if (fabs(calculatedM - m) < epsilon) {
            p = r * 100;
            break;
        }
        else if (calculatedM < m) {
            lowerBound = r;
        }
        else {
            upperBound = r;
        }
    }
    cout << "Ссуда в размере " << S << " рублей, которая гасится месячными выплатами в размере " << m << " рублей в течение " << n << " лет, выдана под " << p << "% годовых." << std::endl;
}

int main(){
    setlocale(LC_ALL, "rus");
    //Zaem();
    //Ssuda();
}