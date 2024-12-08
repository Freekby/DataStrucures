#pragma once

#include "stack.h"

/**
* @brief ��������� ����� ��� ���������� ������� � �������������� ���� ������..
*/
template <typename T>
class QTwoStacks
{
private:
	/** @brief ������ ����, ������������ ��� ���������� ���������. */
	Stack<T> _stack1;

	/** @brief ������ ����, ������������ ��� ���������� ���������. */
	Stack<T> _stack2;

public:
	/**
	* @brief �������� �� ������� �������.
	*/
	bool IsEmpty() const
	{
		return _stack1.IsStackEmpty() && _stack2.IsStackEmpty();
	}

	/**
	* @brief ���������� �������� � �������.
	*/
	void Enqueue(const T& data)
	{
		_stack1.Push(data);
	}

	/**
	* @brief ���������� �������� �� �������.
	*/
	T Dequeue()
	{
		if (IsEmpty())
		{
			throw std::underflow_error("������� �����!");
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
	* @brief ��������� ���� ������ �� ������� � ���� �������.
	*/
	std::vector<T> GetData() const
	{
		//������, ���������� ��� �������� �������.  ������� ��������� ������������� ������� ���������� � �������.
		std::vector<T> data; 

		std::vector<T> data1 = _stack1.GetData();
		std::reverse(data1.begin(), data1.end());

		std::vector<T> data2 = _stack2.GetData();

		data.insert(data.end(), data2.begin(), data2.end());
		data.insert(data.end(), data1.begin(), data1.end());
		return data;
	}
};