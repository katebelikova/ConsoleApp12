#include <iostream>
#include <list>
#include <set>
#include <iterator>
#include <algorithm>
#include <string>
#include <iomanip>
#include <windows.h> 

using namespace std;

// Програма 1
void program1() {
    cout << "--- ПРОГРАМА 1 ---\n";
    list<double> container = { 1.5, -3.2, 0, 4.4, -2.1 };

    cout << "Початковий контейнер:\n";
    for (double x : container) cout << x << " ";
    cout << "\n";

    container.push_back(10);
    container.remove(-3.2);
    container.push_back(7.7);
    container.push_back(8.8);

    cout << "Після змін:\n";
    for (double x : container) cout << x << " ";
    cout << "\n";

    list<double> secondContainer = { 7.7, 8.8 };

    container.insert(container.end(), secondContainer.begin(), secondContainer.end());

    cout << "Перший контейнер після вставки:\n";
    for (double x : container) cout << x << " ";
    cout << "\n";

    cout << "Другий контейнер:\n";
    for (double x : secondContainer) cout << x << " ";
    cout << "\n";
}

// Програма 2
void program2() {
    cout << "--- ПРОГРАМА 2 ---\n";
    list<pair<string, double>> container = {
        {"Анна", 2.5},
        {"Іван", -1.1},
        {"Олег", 0},
        {"Марія", 4.3}
    };

    cout << "Початковий список:\n";
    for (auto& p : container)
        cout << p.first << ": " << p.second << "\n";

    for (auto& p : container) {
        if (p.first == "Іван") p.second = 1.1;
    }

    cout << "Після змін:\n";
    for (auto& p : container)
        cout << p.first << ": " << p.second << "\n";

    list<pair<string, double>> secondContainer = {
        {"Сергій", 3.3},
        {"Лена", 2.2}
    };

    container.insert(container.end(), secondContainer.begin(), secondContainer.end());

    cout << "Перший контейнер після вставки:\n";
    for (auto& p : container)
        cout << p.first << ": " << p.second << "\n";

    cout << "Другий контейнер:\n";
    for (auto& p : secondContainer)
        cout << p.first << ": " << p.second << "\n";
}

// Програма 3
void program3() {
    cout << "--- ПРОГРАМА 3 ---\n";
    set<pair<string, double>> container = {
        {"А", 4.4},
        {"Б", 2.2},
        {"В", 6.6},
        {"Г", 1.1}
    };

    cout << "Відсортований список (спадання):\n";
    for (auto& p : container)
        cout << p.first << ": " << p.second << "\n";

    auto it = find_if(container.begin(), container.end(), [](const pair<string, double>& p) {
        return p.second > 3.0;
        });

    if (it != container.end())
        cout << "Знайдено > 3.0: " << it->first << ": " << it->second << "\n";

    set<pair<string, double>> newContainer;
    for (auto& p : container)
        if (p.second > 3.0)
            newContainer.insert(p);

    cout << "Елементи в set (>3.0):\n";
    for (auto& p : newContainer)
        cout << p.first << ": " << p.second << "\n";

    set<pair<string, double>> mergedContainer = container;
    mergedContainer.insert(newContainer.begin(), newContainer.end());

    cout << "Злитий контейнер:\n";
    for (auto& p : mergedContainer)
        cout << p.first << ": " << p.second << "\n";

    int count = count_if(mergedContainer.begin(), mergedContainer.end(), [](const pair<string, double>& p) {
        return p.second > 3.0;
        });

    cout << "Кількість елементів > 3.0: " << count << "\n";

    auto found = find_if(mergedContainer.begin(), mergedContainer.end(), [](const pair<string, double>& p) {
        return p.second < 1.0;
        });

    if (found != mergedContainer.end())
        cout << "Є елемент < 1.0? Так\n";
    else
        cout << "Є елемент < 1.0? Ні\n";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    program1();
    program2();
    program3();

    return 0;
}
