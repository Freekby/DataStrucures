#pragma once

#include <iostream>
#include <stdexcept>
#include <vector>

/**
* @brief ��������� ����� ��� ���������� ������������� ���������� ������.
*/
template <typename T>
class RingBuffer
{
private:
	/** @brief ��������� �� ����������� ���������� ������ ��� �������� ������. */
	T* _buffer;

	/** @brief ������ ��������� ��������. */
	size_t _head;

	/** @brief ������ ���������� ��������. */
	size_t _tail;

	/** @brief ������� ������ ������. */
	size_t _size;

	/** @brief ������� ������� ������. */
	size_t _capacity;

public:
	/**
	* @brief ����������� ���������� ������.
	*/
	explicit RingBuffer(size_t capacity) : _head(0), _tail(0), _size(0), _capacity(capacity)
	{
		if (capacity <= 0)
		{
			//throw std::invalid_argument ���� capacity ����� ���� ��� ������.
			throw std::invalid_argument("capacity ������ ���� ������ ����");
		}
		_buffer = new T[capacity];
	}

	/**
	* @brief ���������� ���������� ������.
	*/
	~RingBuffer()
	{
		delete[] _buffer;
	}

	/**
	* @brief �������� �� �������.
	*/
	bool IsEmpty() const
	{
		return _size == 0;
	}

	/**
	* @brief �������� �� ������������� ������.
	*/
	bool IsFull() const
	{
		return _size == _capacity;
	}

	/**
	* @brief ���������� ���������� ���������� ����� � ������.

	*/
	size_t FreePlace() const
	{
		return _capacity - _size;
	}

	/**
	* @brief ���������� ���������� ������� ����� � ������.
	* @return ���������� ������� �����.
	*/
	size_t FilledPlace() const
	{
		return _size;
	}

	/**
	* @brief ���������� �������� � �����.
	*/
	void Push(const T& data)
	{
		_buffer[_tail] = data;
		_tail = (_tail + 1) % _capacity;
		if (IsFull())
		{
			throw std::overflow_error("����� �����!");
		}
		_size++;
		
	}

	/**
	* @brief ���������� �������� �� ������.
	*/
	T Pop()
	{
		if (IsEmpty())
		{
			throw std::underflow_error("����� ����!");
		}
		T data = _buffer[_head];
		_head = (_head + 1) % _capacity;
		_size--;
		return data;
	}

	/**
	* @brief ���������� ������ ������ � ���� �������.
	*/
	std::vector<T> GetData() const
	{
		std::vector<T> data;
		if (IsEmpty()) return data;

		size_t current = _head;
		for (size_t i = 0; i < _size; ++i)
		{
			data.push_back(_buffer[current]);
			current = (current + 1) % _capacity;
		}
		return data;
	}
};