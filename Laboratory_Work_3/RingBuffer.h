#pragma once

#include <iostream>
#include <stdexcept>
#include <vector>

/**
* @brief Шаблонный класс для реализации динамического кольцевого буфера.
*/
template <typename T>
class RingBuffer
{
private:
	/** @brief Указатель на динамически выделенный массив для хранения данных. */
	T* _buffer;

	/** @brief Индекс головного элемента. */
	size_t _head;

	/** @brief Индекс хвостового элемента. */
	size_t _tail;

	/** @brief Текущий размер буфера. */
	size_t _size;

	/** @brief Текущая емкость буфера. */
	size_t _capacity;

public:
	/**
	* @brief Конструктор кольцевого буфера.
	*/
	explicit RingBuffer(size_t capacity) : _head(0), _tail(0), _size(0), _capacity(capacity)
	{
		if (capacity <= 0)
		{
			//throw std::invalid_argument Если capacity равно нулю или меньше.
			throw std::invalid_argument("capacity должно быть больше нуля");
		}
		_buffer = new T[capacity];
	}

	/**
	* @brief Деструктор кольцевого буфера.
	*/
	~RingBuffer()
	{
		delete[] _buffer;
	}

	/**
	* @brief Проверка на пустоту.
	*/
	bool IsEmpty() const
	{
		return _size == 0;
	}

	/**
	* @brief Проверка на заполненность буфера.
	*/
	bool IsFull() const
	{
		return _size == _capacity;
	}

	/**
	* @brief Возвращает количество свободного места в буфере.

	*/
	size_t FreePlace() const
	{
		return _capacity - _size;
	}

	/**
	* @brief Возвращает количество занятых ячеек в буфере.
	* @return Количество занятых ячеек.
	*/
	size_t FilledPlace() const
	{
		return _size;
	}

	/**
	* @brief Добавление элемента в буфер.
	*/
	void Push(const T& data)
	{
		_buffer[_tail] = data;
		_tail = (_tail + 1) % _capacity;
		if (IsFull())
		{
			throw std::overflow_error("Буфер полон!");
		}
		_size++;
		
	}

	/**
	* @brief Извлечение элемента из буфера.
	*/
	T Pop()
	{
		if (IsEmpty())
		{
			throw std::underflow_error("Буфер пуст!");
		}
		T data = _buffer[_head];
		_head = (_head + 1) % _capacity;
		_size--;
		return data;
	}

	/**
	* @brief Возвращает данные буфера в виде вектора.
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