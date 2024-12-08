#pragma once

#include "stack.h"

/**
* @brief Шаблонный класс для реализации очереди с использованием двух стеков..
*/
template <typename T>
class QTwoStacks
{
private:
	/** @brief Первый стек, используемый для добавления элементов. */
	Stack<T> _stack1;

	/** @brief Второй стек, используемый для извлечения элементов. */
	Stack<T> _stack2;

public:
	/**
	* @brief Проверка на пустоту очереди.
	*/
	bool IsEmpty() const
	{
		return _stack1.IsStackEmpty() && _stack2.IsStackEmpty();
	}

	/**
	* @brief Добавление элемента в очередь.
	*/
	void Enqueue(const T& data)
	{
		_stack1.Push(data);
	}

	/**
	* @brief Извлечение элемента из очереди.
	*/
	T Dequeue()
	{
		if (IsEmpty())
		{
			throw std::underflow_error("Очередь пуста!");
		}
		if (_stack2.IsStackEmpty())
		{
			while (!_stack1.IsStackEmpty())
			{
				_stack2.Push(_stack1.Pop());
			}
		}
		return _stack2.Pop();
	}

	/**
	* @brief Получение всех данных из очереди в виде вектора.
	*/
	std::vector<T> GetData() const
	{
		//Вектор, содержащий все элементы очереди.  Порядок элементов соответствует порядку добавления в очередь.
		std::vector<T> data; 

		std::vector<T> data1 = _stack1.GetData();
		std::reverse(data1.begin(), data1.end());

		std::vector<T> data2 = _stack2.GetData();

		data.insert(data.end(), data2.begin(), data2.end());
		data.insert(data.end(), data1.begin(), data1.end());
		return data;
	}
};