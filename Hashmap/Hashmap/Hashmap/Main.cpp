#include "HashTable.h"
#include "Dictionary.h"
#include <iostream>
#include <string>

using namespace std;
// TODO: Обнаружена проблема с кодировкой
/// <summary> /// Эта функция проверяет значение, введенное пользователем. 
/// Она гарантирует, что ввод является допустимым целым числом и запрашивает пользователя, пока не будет получен допустимый ввод. 
/// </summary>
/// <returns>Проверенное целое значение, введенное пользователем.</returns>
int CheckValue()
{
    cout << "Введите значение: ";

    string input;
    while (true)
    {
        if (cin >> input)
        {
            try
            {
                size_t pos;
                int value = stoi(input, &pos);
                if (pos == input.length())
                {
                    return value;
                }
                else
                {
                    cout << "Недопустимый ввод (не полное число). Пожалуйста, введите: ";
                }
            }
            catch (const invalid_argument& e)
            {
                cout << "Недопустимый ввод (не число). Пожалуйста, введите: ";
            }
            catch (const out_of_range& e)
            {
                cout << "Число вне диапазона. Пожалуйста, введите: ";
            }
        }
        else
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Недопустимый ввод. Пожалуйста, введите: ";
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    // TODO: Нет очистки памяти для этого объекта
    Dictionary *dict = new Dictionary();

    int choice;
    // TODO: Определять переменные на отдельных строках
    string key;
    string value;

    do
    {
        cout << endl << "Меню" << endl;
        cout << "1. Добавить запись" << endl;
        cout << "2. Удалить запись" << endl;
        cout << "3. Найти запись" << endl;
        cout << "4. Добавить запись с ключом" << endl;
        cout << "5. Добавить несколько записей" << endl;
        cout << "0. Выход" << endl;
        dict->PrintState();

        cout << "Введите ваш выбор: ";
        
        choice = CheckValue();
        switch (choice)
        {
        case 1:
            cout << "Введите ключ: ";
            cin >> key;
            cout << "Введите значение: ";
            cin >> value;
            dict->Add(key, value);
            break;

        case 2:
            cout << "Введите ключ для удаления: ";
            cin >> key;
            dict->Remove(key);
            break;

        case 3:
            cout << "Введите ключ для поиска: ";
            cin >> key;
            value = dict->Find(key);
            if (!value.empty())
                cout << "Найдено значение: " << value << endl;
            else
                cout << "Ключ не найден." << endl;
            break;

        case 4:
            cout << "Введите ключ для новой записи: ";
            cin >> key;
            cout << "Введите значение: ";
            cin >> value;
            dict->Add(key, value);
            break;

        case 5:
            cout << "Добавление нескольких записей..." << endl;
            for (int i = 0; i < 20; ++i)
            {
                dict->Add("Key" + to_string(i), "Value" + to_string(i));
            }
            break;

        case 0:
            cout << "Выход..." << endl;
            break;

        default:
            cout << "Недопустимый выбор." << endl;
        }
    } while (choice != 0);

    delete dict;
    return 0;
}
