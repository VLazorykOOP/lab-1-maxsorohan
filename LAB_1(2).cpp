#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    int N;
    cout << "Введіть розмір масиву N: ";
    cin >> N;

    int arr[N];

    srand(time(0));

    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 21 - 10; 
    }

    // Виводимо масив
    cout << "Масив: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int negative_index = -1;
    int last_index = -1;

    for (int i = 0; i < N; i++) {
        if (arr[i] < 0 && negative_index == -1) {
            negative_index = i;
        }
        if (arr[i] > 0 && arr[i] % 2 == 0 && negative_index != -1) {
            last_index = i;
        }
    }

    if (negative_index != -1) {
        cout << "Номер першого від'ємного елемента: " << negative_index << endl;
    } else {
        cout << "Від'ємних елементів не знайдено." << endl;
    }

    if (last_index != -1) {
        cout << "Номер останнього парного додатнього елемента праворуч від першого від'ємного: " << last_index << endl;
    } else {
        cout << "Парних додатних елементів праворуч від першого від'ємного не знайдено." << endl;
    }

    return 0;
}
