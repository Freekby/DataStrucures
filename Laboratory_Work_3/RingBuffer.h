#pragma once

#include <iostream>
#include <stdexcept>
#include <vector>

// TODO: Полетела кодироквка русских символов
/**
* @brief Øàáëîííûé êëàññ äëÿ ðåàëèçàöèè äèíàìè÷åñêîãî êîëüöåâîãî áóôåðà.
*/
template <typename T>
class RingBuffer
{
private:
	/** @brief Óêàçàòåëü íà äèíàìè÷åñêè âûäåëåííûé ìàññèâ äëÿ õðàíåíèÿ äàííûõ. */
	T* _buffer;

	/** @brief Èíäåêñ ãîëîâíîãî ýëåìåíòà. */
	size_t _head;

	/** @brief Èíäåêñ õâîñòîâîãî ýëåìåíòà. */
	size_t _tail;

	/** @brief Òåêóùèé ðàçìåð áóôåðà. */
	size_t _size;

	/** @brief Òåêóùàÿ åìêîñòü áóôåðà. */
	size_t _capacity;

public:
	/**
	* @brief Êîíñòðóêòîð êîëüöåâîãî áóôåðà.
	*/
	explicit RingBuffer(size_t capacity) : _head(0), _tail(0), _size(0), _capacity(capacity)
	{
		if (capacity <= 0)
		{
			//throw std::invalid_argument Åñëè capacity ðàâíî íóëþ èëè ìåíüøå.
			throw std::invalid_argument("capacity äîëæíî áûòü áîëüøå íóëÿ");
		}
		_buffer = new T[capacity];
	}

	/**
	* @brief Äåñòðóêòîð êîëüöåâîãî áóôåðà.
	*/
	~RingBuffer()
	{
		delete[] _buffer;
	}

	/**
	* @brief Ïðîâåðêà íà ïóñòîòó.
	*/
	bool IsEmpty() const
	{
		return _size == 0;
	}

	/**
	* @brief Ïðîâåðêà íà çàïîëíåííîñòü áóôåðà.
	*/
	bool IsFull() const
	{
		return _size == _capacity;
	}

	/**
	* @brief Âîçâðàùàåò êîëè÷åñòâî ñâîáîäíîãî ìåñòà â áóôåðå.

	*/
	size_t FreePlace() const
	{
		return _capacity - _size;
	}

	/**
	* @brief Âîçâðàùàåò êîëè÷åñòâî çàíÿòûõ ÿ÷ååê â áóôåðå.
	* @return Êîëè÷åñòâî çàíÿòûõ ÿ÷ååê.
	*/
	size_t FilledPlace() const
	{
		return _size;
	}

	/**
	* @brief Äîáàâëåíèå ýëåìåíòà â áóôåð.
	*/
	void Push(const T& data)
	{
		_buffer[_tail] = data;
		_tail = (_tail + 1) % _capacity;

		// TODO: Лишний выброс исключения. Т.к. это не является ошибкой в данной реализации.
		// Исключения используются для выброса ошибок, а не для всех отправлений сообщений пользователю.
		// Убрать или добавить возвращение значения типа bool, где True - RingBuffer переполнен,
		// а False - место есть.
		// end TODO
		// TODO: RSDN
		if (IsFull())
		{
			throw std::overflow_error("Áóôåð ïîëîí!");
		}
		_size++;
		
	}

	/**
	* @brief Èçâëå÷åíèå ýëåìåíòà èç áóôåðà.
	*/
	T Pop()
	{
		// TODO: RSDN
		if (IsEmpty())
		{
			throw std::underflow_error("Áóôåð ïóñò!");
		}
		T data = _buffer[_head];
		_head = (_head + 1) % _capacity;
		_size--;
		return data;
	}

	/**
	* @brief Âîçâðàùàåò äàííûå áóôåðà â âèäå âåêòîðà.
	*/
	std::vector<T> GetData() const
	{
		// TODO: RSDN
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