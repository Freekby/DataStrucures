#pragma once 

#include <vector> 
#include <stdexcept> 

// TODO: Полетела кодироквка русских символов(сделано)

/**
 * @brief Шаблонный класс для реализации стека.
 */
template <typename T>
class Stack
{
private:
	/**
	 * @brief Узел стека.
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

	/** @brief Указатель на верхний элемент стека. */
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
		Clear(); 
	}

	/**
	 * @brief Проверяет, пуст ли стек.
	 * @return true, если стек пуст; иначе false.
	 */
	bool IsStackEmpty() const
	{
		return _top == nullptr;
	}

	/**
	 * @brief Добавляет элемент в стек.
	 * @param data Элемент для добавления в стек.
	 */
	void Push(const T& data)
	{
		Node* newNode = new Node(data);
		newNode->next = _top;
		_top = newNode;
	}

	/**
	 * @brief Извлекает элемент из стека.
	 * @return Возвращает верхний элемент стека.
	 * @throw std::underflow_error Если стек пуст.
	 */
	T Pop()
	{
		if (IsStackEmpty())
		{
			throw std::underflow_error("Free stack!");
		}

		T data = _top->data;
		Node* temp = _top;
		_top = _top->next;
		delete temp;
		return data;
	}

	/**
	 * @brief Получает данные стека в виде вектора.
	 * @return Вектор, содержащий данные стека.
	 */
	std::vector<T> GetData() const
	{
		//TODO:RSDN(сделано)
		std::vector<T> data;
		Node* current = _top;
		while (current != nullptr)
		{
			data.push_back(current->data);
			current = current->next;
		}

		return data;
	}

	/**
	 * @brief Очищает стек, удаляя все элементы.
	 */
	void Clear()
	{
		while (!IsStackEmpty()) 
		{
			Pop(); 
		}
	}
};
