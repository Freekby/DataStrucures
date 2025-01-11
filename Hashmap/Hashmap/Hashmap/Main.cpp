#include "Dictionary.h"
#include "DictionaryWrapper.h"
#include <iostream>
#include <string>

using namespace std;
// TODO: Полетела кодировка
/// <summary>
/// ������� ��� �������� ����� ������ ����� �������������.
/// ������� ����������� � ������������ ���� ������ ����� � ���������� ������ �� ��� ���,
/// ���� �� ����� ������� ���������� ��������.
/// </summary>
/// <returns>��������� ������������� ����� �����.</returns>
int CheckValue()
{
	cout << "��� ����: ";

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
					cout << "������� �������� �������� (���������� �������). ��������� ����: ";
				}
			}
			catch (const invalid_argument& e)
			{
				cout << "������� �������� �������� (�� �����). ��������� ����: ";
			}
			catch (const out_of_range& e)
			{
				cout << "������� ������� ������� ��������. ��������� ����: ";
			}
		}
		else
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "������ �����. ��������� ����: ";
		}
	}
}

// TODO: реализуемый метод наодится не в том cpp файле
void DictionaryWrapper::PrintState() const
{
	std::cout << "������� ��������� ���-�������:" << std::endl;
	for (size_t i = 0; i < _dictionary.GetSize(); ++i)
	{
		std::cout << i << ": ";
		Node* current = _dictionary.GetBucket(i);
		if (current == nullptr)
		{
			std::cout << "�����";
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

	std::cout << "������� (����� � ��������):" << std::endl;
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
	// TODO: нет очистки памяти этого объекта
	DictionaryWrapper *dict = new DictionaryWrapper();

	int choice;
	// TODO: Определять переменные на разных строках
	string key, value;

	do
	{
		cout << endl << "����" << endl;
		cout << "1. �������� �������" << endl;
		cout << "2. ������� �������" << endl;
		cout << "3. ����� �������" << endl;
		cout << "4. �������� ������������� ����" << endl;
		cout << "5. ��������� �� ���������������" << endl;
		cout << "0. �����" << endl;
		dict->PrintState();

		cout << "�������� ��������: ";
		
		choice = CheckValue();
		switch (choice)
		{
		case 1:
			cout << "������� ����: ";
			cin >> key;
			cout << "������� ��������: ";
			cin >> value;
			dict->Add(key, value);
			break;

		case 2:
			cout << "������� ���� ��� ��������: ";
			cin >> key;
			dict->Remove(key);
			break;

		case 3:
			cout << "������� ���� ��� ������: ";
			cin >> key;
			value = dict->Find(key);
			if (!value.empty())
				cout << "������� ��������: " << value << endl;
			else
				cout << "������� �� ������." << endl;
			break;

		case 4:
			cout << "������� ������������� ����: ";
			cin >> key;
			cout << "������� ��������: ";
			cin >> value;
			dict->Add(key, value);
			break;

		case 5:
			cout << "���������� �� ������ ���������������..." << endl;
			for (int i = 0; i < 20; ++i)
			{
				dict->Add("Key" + to_string(i), "Value" + to_string(i));
			}
			break;

		case 0:
			cout << "�����..." << endl;
			break;

		default:
			cout << "�������� �����." << endl;
		}
	} while (choice != 0);

	return 0;
}