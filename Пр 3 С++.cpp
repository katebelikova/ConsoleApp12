#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <windows.h>

using namespace std;

struct Sportsman {
    int number;
    string surname;
    int birthYear;
    string sport;
    string country;
    int place;
};

class SportsmanArray {
private:
    vector<Sportsman> list;

public:
    SportsmanArray() {}

    SportsmanArray(const SportsmanArray& other) {
        list = other.list;
    }

    void add(const Sportsman& s) {
        list.push_back(s);
    }

    void input() {
        int n;
        cout << "Кількість спортсменів: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            Sportsman s;
            cout << "\nСпортсмен #" << (i + 1) << endl;
            s.number = i + 1;
            cout << "Прізвище: ";
            cin >> s.surname;
            cout << "Рік народження: ";
            cin >> s.birthYear;
            cout << "Вид спорту (футбол, хокей, шахи, теніс): ";
            cin >> s.sport;
            cout << "Країна (Україна, Литва, Чехія, Китай): ";
            cin >> s.country;
            cout << "Зайняте місце (1-8): ";
            cin >> s.place;
            list.push_back(s);
        }
    }

    void display() const {
        cout << left << setw(5) << "№"
            << setw(15) << "Прізвище"
            << setw(15) << "Рік нар."
            << setw(15) << "Спорт"
            << setw(15) << "Країна"
            << setw(10) << "Місце" << endl;

        for (const auto& s : list) {
            cout << left << setw(5) << s.number
                << setw(15) << s.surname
                << setw(15) << s.birthYear
                << setw(15) << s.sport
                << setw(15) << s.country
                << setw(10) << s.place << endl;
        }
    }

    void display(string country, string sport, int minAge) const {
        int currentYear = 2025;
        cout << "\nФутболісти з " << country << " старші за " << minAge << " років:\n";
        for (const auto& s : list) {
            if (s.country == country && s.sport == sport && (currentYear - s.birthYear) > minAge) {
                cout << s.surname << " (" << s.birthYear << "), місце: " << s.place << endl;
            }
        }
    }

    void sortByPlace() {
        sort(list.begin(), list.end(), [](const Sportsman& a, const Sportsman& b) {
            return a.place < b.place;
            });
    }

    explicit operator int() const {
        return list.size();
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    SportsmanArray arr;
    arr.input();

    cout << "\n--- Усі спортсмени ---\n";
    arr.display();

    cout << "\n--- Сортовані за місцем ---\n";
    arr.sortByPlace();
    arr.display();

    arr.display("Україна", "футбол", 28);

    int count = static_cast<int>(arr);
    cout << "\nКількість спортсменів (через явне приведення типу): " << count << endl;

    SportsmanArray arrCopy = arr;
    cout << "\n--- Копія масиву ---\n";
    arrCopy.display();

    return 0;
}
