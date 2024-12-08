#pragma once

#include <vector>
#include <stdexcept>

/**
* @brief Шаблонный класс для реализации стека.
*/
template <typename T>
class Stack
{
private:
	/**
	* @brief Структура узла стека.
	*/
	struct Node
	{
		/** @brief Данные, хранящиеся в узле. */
		T data;

		/** @brief Указатель на следующий узел. */
		Node* next;

		/**
		* @brief Конструктор узла.
		*/
		Node(const T& data) : data(data), next(nullptr) {}
	};

	/** @brief Указатель на вершину стека. */
	Node* _top;

public:
	/**
	* @brief Конструктор стека.
	*/
	Stack() : _top(nullptr) {}

	/**
	* @brief Деструктор стека.
	*/
	~Stack()
	{
		while (!IsStackEmpty())
		{
			Pop();
		}
	}

	/**
	* @brief Проверка на пустоту стека.
	*/
	bool IsStackEmpty() const
	{
		return _top == nullptr;
	}

	/**
	* @brief Добавление элемента в стек.
	*/
	void Push(const T& data)
	{
		Node* newNode = new Node(data);
		newNode->next = _top;
		_top = newNode;
	}

	/**
	* @brief Извлечение элемента из стека.
	* @return Верхний элемент стека.
	* @throw std::underflow_error Если стек пуст.
	*/
	T Pop()
	{
		if (IsStackEmpty())
		{
			throw std::underflow_error("Стек пуст!");
		}
		T data = _top->data;
		Node* temp = _top;
		_top = _top->next;
		delete temp;
		return data;
	}

	/**
	* @brief Возвращает данные стека в виде вектора.
	* @return Вектор, содержащий данные стека.
	*/
	std::vector<T> GetData() const
	{
		std::vector<T> data;
		Node* current = _top;
		while (current != nullptr)
		{
			data.push_back(current->data);
			current = current->next;
		}
		return data;
	}
};