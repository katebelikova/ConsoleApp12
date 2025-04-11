#include <iostream>
#include <cstring>
#include <Windows.h>
using namespace std;

class Address {
private:
    char* surname;
    char* street;
    int houseNumber;

public:
    // Конструктор без параметрів
    Address() : surname(new char[1] { '\0' }), street(new char[1] { '\0' }), houseNumber(0) {
        cout << "Викликано конструктор без параметрiв.\n";
    }

    // Конструктор з параметрами
    Address(const char* sname, const char* str, int num) : houseNumber(num) {
        surname = new char[strlen(sname) + 1];
        strcpy_s(surname, strlen(sname) + 1, sname);

        street = new char[strlen(str) + 1];
        strcpy_s(street, strlen(str) + 1, str);

        cout << "Викликано конструктор з параметрами.\n";
    }

    // Конструктор копіювання
    Address(const Address& other) : houseNumber(other.houseNumber) {
        surname = new char[strlen(other.surname) + 1];
        strcpy_s(surname, strlen(other.surname) + 1, other.surname);

        street = new char[strlen(other.street) + 1];
        strcpy_s(street, strlen(other.street) + 1, other.street);

        cout << "Викликано конструктор копiювання.\n";
    }

    // Деструктор для очищення пам'яті
    ~Address() {
        delete[] surname;
        delete[] street;
    }

    // Метод введення прізвища
    void inputSurname() {
        cout << "Введiть прiзвище: ";
        cin.ignore();  // Ігноруємо попередній символ нового рядка
        char temp[100];
        cin.getline(temp, 100);  // Використовуємо getline для введення рядка
        delete[] surname;
        surname = new char[strlen(temp) + 1];
        strcpy_s(surname, strlen(temp) + 1, temp);
    }

    // Метод введення вулиці та номера будинку
    void inputStreetAndNumber() {
        cout << "Введiть вулицю: ";
        char tempStreet[100];
        cin.getline(tempStreet, 100);  // Використовуємо getline для введення рядка
        delete[] street;
        street = new char[strlen(tempStreet) + 1];
        strcpy_s(street, strlen(tempStreet) + 1, tempStreet);

        cout << "Введiть номер будинку: ";
        cin >> houseNumber;
    }

    // Метод зміни адреси
    void changeAddress(const char* newStreet, int newHouseNumber) {
        delete[] street;
        street = new char[strlen(newStreet) + 1];
        strcpy_s(street, strlen(newStreet) + 1, newStreet);
        houseNumber = newHouseNumber;
    }

    // Метод виведення інформації про адресу
    void printInfo() const {
        cout << "--------------------------\n";
        cout << "Прiзвище: " << surname << "\n";
        cout << "Вулиця: " << street << "\n";
        cout << "Номер будинку: " << houseNumber << "\n";
        cout << "--------------------------\n";
    }
};

int main() {
    // Встановлюємо локаль, щоб підтримувати українські символи
    setlocale(LC_ALL, "");  // для українських символів в консолі

    // Створення об'єкта без параметрів
    Address address1;
    address1.inputSurname();
    address1.inputStreetAndNumber();
    address1.printInfo();

    // Створення об'єкта з параметрами
    Address address2("Шевченко", "Хрещатик", 10);
    address2.printInfo();

    // Створення об'єкта через конструктор копіювання
    Address address3(address2);
    address3.printInfo();

    // Зміна адреси для об'єкта
    address3.changeAddress("Лесі Українки", 99);
    cout << "Після зміни адреси:\n";
    address3.printInfo();

    system("pause");

    return 0;
}
