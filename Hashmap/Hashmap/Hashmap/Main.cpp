#include "Dictionary.h"
#include "DictionaryWrapper.h"
#include <iostream>
#include <string>

using namespace std;

/// <summary>
/// Функция для проверки ввода целого числа пользователем.
/// Функция запрашивает у пользователя ввод целого числа и продолжает запрос до тех пор,
/// пока не будет введено корректное значение.
/// </summary>
/// <returns>Введенное пользователем целое число.</returns>
int CheckValue()
{
	cout << "Ваш ввод: ";

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
					cout << "Введено неверное значение (нечисловые символы). Повторите ввод: ";
				}
			}
			catch (const invalid_argument& e)
			{
				cout << "Введено неверное значение (не число). Повторите ввод: ";
			}
			catch (const out_of_range& e)
			{
				cout << "Введено слишком большое значение. Повторите ввод: ";
			}
		}
		else
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Ошибка ввода. Повторите ввод: ";
		}
	}
}

void DictionaryWrapper::PrintState() const
{
	std::cout << "Текущее состояние хеш-таблицы:" << std::endl;
	for (size_t i = 0; i < _dictionary.GetSize(); ++i)
	{
		std::cout << i << ": ";
		Node* current = _dictionary.GetBucket(i);
		if (current == nullptr)
		{
			std::cout << "Пусто";
		}
		else
		{
			while (current)
			{
				std::cout << "[" << current->key << ": " << current->value << "]";
				if (current->next)
					std::cout << " -> ";
				current = current->next;
			}
		}
		std::cout << std::endl;
	}

	std::cout << "Словарь (ключи и значения):" << std::endl;
	for (size_t i = 0; i < _dictionary.GetSize(); ++i)
	{
		Node* current = _dictionary.GetBucket(i);
		while (current)
		{
			std::cout << current->key << ": " << current->value << std::endl;
			current = current->next;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	DictionaryWrapper *dict = new DictionaryWrapper();

	int choice;
	string key, value;

	do
	{
		cout << endl << "Меню" << endl;
		cout << "1. Добавить элемент" << endl;
		cout << "2. Удалить элемент" << endl;
		cout << "3. Найти элемент" << endl;
		cout << "4. Добавить дублирующийся ключ" << endl;
		cout << "5. Заполнить до перехеширования" << endl;
		cout << "0. Выход" << endl;
		dict->PrintState();

		cout << "Выберите действие: ";
		
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
				cout << "Элемент не найден." << endl;
			break;

		case 4:
			cout << "Введите дублирующийся ключ: ";
			cin >> key;
			cout << "Введите значение: ";
			cin >> value;
			dict->Add(key, value);
			break;

		case 5:
			cout << "Заполнение до вызова перехеширования..." << endl;
			for (int i = 0; i < 20; ++i)
			{
				dict->Add("Key" + to_string(i), "Value" + to_string(i));
			}
			break;

		case 0:
			cout << "Выход..." << endl;
			break;

		default:
			cout << "Неверный выбор." << endl;
		}
	} while (choice != 0);

	return 0;
}