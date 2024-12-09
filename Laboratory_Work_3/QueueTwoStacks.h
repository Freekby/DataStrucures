#pragma once

#include "stack.h"

// TODO: Полетела кодироквка русских символов
/**
* @brief Øàáëîííûé êëàññ äëÿ ðåàëèçàöèè î÷åðåäè ñ èñïîëüçîâàíèåì äâóõ ñòåêîâ..
*/
template <typename T>
class QTwoStacks
{
private:
	// TODO: Утечка памяти. Добавить деструктор с очисткой стеков
	/** @brief Ïåðâûé ñòåê, èñïîëüçóåìûé äëÿ äîáàâëåíèÿ ýëåìåíòîâ. */
	Stack<T> _stack1;

	// TODO: Утечка памяти. Добавить деструктор с очисткой стеков
	/** @brief Âòîðîé ñòåê, èñïîëüçóåìûé äëÿ èçâëå÷åíèÿ ýëåìåíòîâ. */
	Stack<T> _stack2;

public:
	/**
	* @brief Ïðîâåðêà íà ïóñòîòó î÷åðåäè.
	*/
	bool IsEmpty() const
	{
		return _stack1.IsStackEmpty() && _stack2.IsStackEmpty();
	}

	/**
	* @brief Äîáàâëåíèå ýëåìåíòà â î÷åðåäü.
	*/
	void Enqueue(const T& data)
	{
		_stack1.Push(data);
	}

	/**
	* @brief Èçâëå÷åíèå ýëåìåíòà èç î÷åðåäè.
	*/
	T Dequeue()
	{
		// TODO: RSDN
		if (IsEmpty())
		{
			throw std::underflow_error("Î÷åðåäü ïóñòà!");
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
	* @brief Ïîëó÷åíèå âñåõ äàííûõ èç î÷åðåäè â âèäå âåêòîðà.
	*/
	std::vector<T> GetData() const
	{
		//Âåêòîð, ñîäåðæàùèé âñå ýëåìåíòû î÷åðåäè.  Ïîðÿäîê ýëåìåíòîâ ñîîòâåòñòâóåò ïîðÿäêó äîáàâëåíèÿ â î÷åðåäü.
		std::vector<T> data; 

		std::vector<T> data1 = _stack1.GetData();
		std::reverse(data1.begin(), data1.end());

		std::vector<T> data2 = _stack2.GetData();

		data.insert(data.end(), data2.begin(), data2.end());
		data.insert(data.end(), data1.begin(), data1.end());
		return data;
	}
};