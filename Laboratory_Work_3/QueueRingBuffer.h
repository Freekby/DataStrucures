#pragma once

#include "RingBuffer.h"
// TODO: Полетела кодироквка русских символов
/**
* @brief Øàáëîííûé êëàññ äëÿ ðåàëèçàöèè î÷åðåäè íà îñíîâå êîëüöåâîãî áóôåðà.
*/
template <typename T>
class QueueRingBuffer
{
private:
	/** @brief Êîëüöåâîé áóôåð, èñïîëüçóåìûé äëÿ ðåàëèçàöèè î÷åðåäè. */
	RingBuffer<T> _buffer;

public:
	/**
	* @brief Êîíñòðóêòîð î÷åðåäè.
	* @param capacity Åìêîñòü êîëüöåâîãî áóôåðà.
	*/
	explicit QueueRingBuffer(size_t capacity) : _buffer(capacity) {}

	/**
	* @brief Ïðîâåðêà íà ïóñòîòó î÷åðåäè.
	* @return true, åñëè î÷åðåäü ïóñòà; false â ïðîòèâíîì ñëó÷àå.
	*/
	bool IsEmpty() const { return _buffer.IsEmpty(); }

	/**
	* @brief Ïðîâåðêà íà çàïîëíåííîñòü î÷åðåäè.
	* @return true, åñëè î÷åðåäü çàïîëíåíà; false â ïðîòèâíîì ñëó÷àå.
	*/
	bool IsFull() const { return _buffer.IsFull(); }

	/**
	* @brief Äîáàâëåíèå ýëåìåíòà â î÷åðåäü.
	* @param data Ýëåìåíò, êîòîðûé íóæíî äîáàâèòü.
	*/
	void Enqueue(const T& data)
	{
		_buffer.Push(data);
	}

	/**
	* @brief Èçâëå÷åíèå ýëåìåíòà èç î÷åðåäè.
	* @return Ýëåìåíò, èçâëå÷åííûé èç î÷åðåäè.
	* @throw std::runtime_error Åñëè î÷åðåäü ïóñòà.
	*/
	T Dequeue()
	{
		// TODO: RSDN
		if (IsEmpty())
		{
			throw std::underflow_error("Î÷åðåäü ïóñòà!");
		}
		return _buffer.Pop();
	}

	/**
	* @brief Âîçâðàùàåò âñå äàííûå î÷åðåäè â âèäå âåêòîðà.
	* @return Âåêòîð, ñîäåðæàùèé äàííûå î÷åðåäè.
	*/
	std::vector<T> GetData() const
	{
		return _buffer.GetData();
	}
};