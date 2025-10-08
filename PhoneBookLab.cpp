#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <fcntl.h>
#include <io.h>

using namespace std;

struct Abonent {
    wstring prizvyshche;
    wstring imya;
    wstring po_batkovi;
    wstring telefon;
};

int main() {
    // Налаштування консолі для української мови
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);

    const int PHONEBOOK_SIZE = 5;
    Abonent phoneBook[PHONEBOOK_SIZE];

    // Введення даних
    for (int i = 0; i < PHONEBOOK_SIZE; i++) {
        wcout << L"Абонент #" << i + 1 << endl;
        wcout << L"Прізвище: "; getline(wcin, phoneBook[i].prizvyshche);
        wcout << L"Ім'я: "; getline(wcin, phoneBook[i].imya);
        wcout << L"По-батькові: "; getline(wcin, phoneBook[i].po_batkovi);
        wcout << L"Телефон: "; getline(wcin, phoneBook[i].telefon);
        wcout << endl;
    }

    // Запис у файл
    wofstream outFile(L"phonebook.txt");
    for (int i = 0; i < PHONEBOOK_SIZE; i++) {
        outFile << phoneBook[i].prizvyshche << endl
            << phoneBook[i].imya << endl
            << phoneBook[i].po_batkovi << endl
            << phoneBook[i].telefon << endl;
    }
    outFile.close();

    // Читання з файлу
    Abonent phoneBookFromFile[PHONEBOOK_SIZE];
    wifstream inFile(L"phonebook.txt");
    for (int i = 0; i < PHONEBOOK_SIZE; i++) {
        getline(inFile, phoneBookFromFile[i].prizvyshche);
        getline(inFile, phoneBookFromFile[i].imya);
        getline(inFile, phoneBookFromFile[i].po_batkovi);
        getline(inFile, phoneBookFromFile[i].telefon);
    }
    inFile.close();

    // Вивід на екран
    wcout << L"=== Телефонний довідник ===" << endl;
    for (int i = 0; i < PHONEBOOK_SIZE; i++) {
        wcout << i + 1 << L". "
            << phoneBookFromFile[i].prizvyshche << L" "
            << phoneBookFromFile[i].imya << L" "
            << phoneBookFromFile[i].po_batkovi << L" "
            << phoneBookFromFile[i].telefon << endl;
    }

    return 0;
}