#pragma once 

#include <iostream> 
#include <stdexcept> 
#include <vector> 

// TODO: Полетела кодировка русских символов(сделано)

/**
 * @brief Шаблонный класс для реализации кольцевого буфера.
 */
template <typename T>
class RingBuffer
{
private:
	/** @brief Указатель на динамически выделенный массив для хранения данных. */
	T* _buffer;

	/** @brief Индекс следующей ячейки для записи. */
	size_t _head;

	/** @brief Индекс следующей ячейки для чтения. */
	size_t _tail;

	/** @brief Текущий размер буфера (количество элементов). */
	size_t _size;

	/** @brief Максимальная ёмкость буфера. */
	size_t _capacity;

public:
	/**
	 * @brief Конструктор кольцевого буфера.
	 * @param capacity Максимальная ёмкость буфера.
	 * @throw std::invalid_argument Если capacity меньше или равно нулю.
	 */
	explicit RingBuffer(size_t capacity) : _head(0), _tail(0), _size(0), _capacity(capacity)
	{
		if (capacity <= 0)
		{
			throw std::invalid_argument("capacity more than 0");
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
	 * @brief Проверяет, пуст ли буфер.
	 * @return true, если буфер пуст; иначе false.
	 */
	bool IsEmpty() const
	{
		return _size == 0;
	}

	/**
	 * @brief Проверяет, полон ли буфер.
	 * @return true, если буфер полон; иначе false.
	 */
	bool IsFull() const
	{
		return _size == _capacity;
	}

	/**
	 * @brief Возвращает количество свободных ячеек в буфере.
	 * @return Количество свободных ячеек.
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
	 * @brief Добавляет элемент в буфер. Если буфер полон, выбрасывает исключение.
	 * @param data Элемент для добавления в буфер.
	 * @throw std::overflow_error Если буфер полон.
	 */
	void Push(const T& data)
	{
		if (IsFull()) 
		{
			throw std::overflow_error("Full buffer!"); 
		}

		_buffer[_tail] = data; 
		_tail = (_tail + 1) % _capacity; 
		_size++; 
	}

	/**
	 * @brief Извлекает элемент из буфера. Если буфер пуст, выбрасывает исключение.
	 * @return Извлечённый элемент из буфера.
	 * @throw std::underflow_error Если буфер пуст.
	 */
	T Pop()
	{
		if (IsEmpty()) 
		{
			throw std::underflow_error("Free buffer!"); 
		}

		T data = _buffer[_head]; 
		_head = (_head + 1) % _capacity; 
		_size--;
		return data; 
	}

	/**
	 * @brief Возвращает данные из буфера в виде вектора.
	 * @return Вектор, содержащий данные из буфера.
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
