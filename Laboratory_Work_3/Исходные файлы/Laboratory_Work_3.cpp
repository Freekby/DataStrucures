#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <limits>
#include "QueueRingBuffer.h"
#include "QueueTwoStacks.h"
#include "RingBuffer.h"
#include "Stack.h"


// TODO: Добавить .gitignore файл(добавлено)
// TODO: Нужно убрать из отслеживания изменений git ВСЕ файлы, которые должны игнорироваться(исправлено)
// TODO: Нахождения файлов в файловой системе отличается от Solution Explorer(исправлено)
/**
 * @brief Функция для проверки ввода целого числа пользователем.
 * Функция запрашивает у пользователя ввод целого числа и продолжает запрос до тех пор,
 * пока не будет введено корректное значение.
 * @return Введенное пользователем целое число.
 */
int CheckValue() 
{
	std::cout << "Your choose: ";

	int value;
	while (true) 
	{
		if (std::cin >> value) 
		{
			return value;
		}
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid value. Try again: ";
		}
	}
}

/**
* @brief Выводит меню и обрабатывает ввод пользователя для выбранной структуры данных.
*/
void Print(const std::vector<int>& data, const std::string& typeName)
{
	//typeName Имя типа данных. data Данные для отображения.
	std::cout << std::endl << "Elements " << typeName << ":" << std::endl;
	for (int x : data)
	{
		std::cout << x << " ";
	}
	std::cout << std::endl << std::endl << "" << std::endl;
	std::cout << "0. Exit to menu" << std::endl;
	std::cout << "1. Add (Push/Enqueue) element to " << typeName << std::endl;
	std::cout << "2. Pop (Pop/Dequeue) element from " << typeName << std::endl;
}

/**
* @brief Меню для работы со стеком.
*/
void StackMenu()
{
	Stack<int>* stack = new Stack<int>();

	int choice;
	do
	{
		std::string typeName = "Stack";
		std::vector<int> stackData = stack->GetData();

		Print(stackData, typeName);

		choice = CheckValue();
		switch (choice)
		{
		case 1:
		{
			int value;
			std::cout << "Type value: ";
			value = CheckValue();
			stack->Push(value);
			break;
		}
		case 2:
		{
			try
			{
				std::cout << "Element: " << stack->Pop() << std::endl;
			}
			catch (const std::underflow_error& error)
			{
				std::cerr << "Error: " << error.what() << std::endl;
			}
			break;
		}
		case 0:
		{
			delete stack;
			std::cout << "Menu" << std::endl;
			break;
		}
		default:
		{
			std::cout << "Unfinded value." << std::endl;
		}
		}
	} while (choice != 0);
}


/**
* @brief Меню для работы с кольцевым буфером.
*/
void RingBufferMenu()
{
	RingBuffer<int>* buffer = new RingBuffer<int>(5);

	int choice;
	do
	{
		std::string typeName = "RingBuffer";
		std::vector<int> bufferData = buffer->GetData();

		Print(bufferData, typeName);

		std::cout << "3. Free place" << std::endl;
		std::cout << "4. Filled place" << std::endl;

		choice = CheckValue();
		switch (choice)
		{
		case 1:
		{
			try
			{
				int value;
				std::cout << "Type value: ";
				value = CheckValue();
				buffer->Push(value);
			}
			catch (const std::overflow_error& error)
			{
				std::cout << error.what() << std::endl;
			}
			break;
		}
		case 2:
		{
			try
			{
				std::cout << "Element: " << buffer->Pop() << std::endl;
			}
			catch (const std::underflow_error& error)
			{
				std::cerr << "Error: " << error.what() << std::endl;
			}
			break;
		}
		case 3:
		{
			std::cout << "Free place: " << buffer->FreePlace() << std::endl;
			break;
		}
		case 4:
		{
			std::cout << "Filled place: " << buffer->FilledPlace() << std::endl;
			break;
		}
		case 0:
		{
			delete buffer;
			std::cout << "Menu" << std::endl;
			break;
		}
		default:
		{
			std::cout << "Unfinded value." << std::endl;
		}
		}
	} while (choice != 0);
}

/**
* @brief Меню для работы с очередью на основе кольцевого буфера.
*/
void QueueRingBufferMenu()
{
	QueueRingBuffer<int>* queue = new QueueRingBuffer<int>(5);

	int choice;
	do
	{
		std::string typeName = "QueueRingBuffer";
		std::vector<int> queueData = queue->GetData();

		Print(queueData, typeName);

		choice = CheckValue();
		switch (choice)
		{
		case 1:
		{
			try
			{
				int value;
				std::cout << "Type value: ";
				value = CheckValue();
				queue->Enqueue(value);
			}
			catch (const std::overflow_error& error)
			{
				std::cout << error.what() << std::endl;
			}
			break;
		}
		case 2:
		{
			try
			{
				std::cout << "Element: " << queue->Dequeue() << std::endl;
			}
			catch (const std::underflow_error& error)
			{
				std::cerr << "Error: " << error.what() << std::endl;
			}
			break;
		}
		case 0:
		{
			delete queue;
			std::cout << "Exit to menu..." << std::endl;
			break;
		}
		default:
		{
			std::cout << "Unfinded value." << std::endl;
		}
		}
	} while (choice != 0);
}

/**
* @brief Меню для работы с очередью на основе двух стеков.
*/
void QueueTwoStacksMenu()
{
	QTwoStacks<int>* queue = new QTwoStacks<int>();

	int choice;
	do
	{
		std::string typeName = "QueueTwoStacks";
		std::vector<int> queueData = queue->GetData();

		Print(queueData, typeName);

		choice = CheckValue();
		switch (choice)
		{
		case 1:
		{
			int value;
			std::cout << "Type value for element: ";
			value = CheckValue();
			queue->Enqueue(value);
			break;
		}
		case 2:
		{
			try
			{
				std::cout << "Element: " << queue->Dequeue() << std::endl;
			}
			catch (const std::underflow_error& error)
			{
				std::cerr << "Error: " << error.what() << std::endl;
			}
			break;
		}
		case 0:
		{
			delete queue;
			std::cout << "Exit to menu..." << std::endl;
			break;
		}
		default:
		{
			std::cout << "Invalid command. Try again." << std::endl;
		}
		}
	} while (choice != 0);
}

/**
* @brief Главное меню программы.
*/
int main()
{
	setlocale(LC_ALL, "USA");
	int menuChoice;
	do
	{
		std::cout << std::endl;
		std::cout << std::endl << "Laboratory Work #3 " << std::endl;
		std::cout << std::endl << " Menu" << std::endl;
		std::cout << "1. Stack" << std::endl;
		std::cout << "2. Ring Buffer" << std::endl;
		std::cout << "3. Queue(RingBuffer)" << std::endl;
		std::cout << "4. Queue(TwoStacks)" << std::endl;
		std::cout << "0. Exit" << std::endl;

		menuChoice = CheckValue();

		switch (menuChoice)
		{
		case 1:
		{
			StackMenu();
			break;
		}
		case 2:
		{
			RingBufferMenu();
			break;
		}
		case 3:
		{
			QueueRingBufferMenu();
			break;
		}
		case 4:
		{
			QueueTwoStacksMenu();
			break;
		}
		case 0:
		{
			std::cout << "Exit...." << std::endl;
			break;
		}
		default:
		{
			std::cout << "Invalid command. Try again." << std::endl;
		}
		}
	} while (menuChoice != 0);

	return 0;
}