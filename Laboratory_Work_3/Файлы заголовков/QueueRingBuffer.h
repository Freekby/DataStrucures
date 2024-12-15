#pragma once

#include "RingBuffer.h"

// TODO: Полетела кодироквка русских символов(сделано)

/*@brief Шаблонный класс для реализации очереди на основе кольцевого буфера. */
template <typename T>
class QueueRingBuffer
{
private:
    /*@brief Кольцевой буфер, используемый для реализации очереди.*/
    RingBuffer<T> _buffer;

public:
    /*@brief Конструктор очереди.
     * @param capacity Ёмкость кольцевого буфера.
    */
    explicit QueueRingBuffer(size_t capacity) : _buffer(capacity) {}

    /*@brief Проверка на пустоту очереди.
     * @return true, если очередь пуста; false в противном случае.
    */
    bool IsEmpty() const { return _buffer.IsEmpty(); }

    /*@brief Проверка на заполненность очереди.
     * @return true, если очередь заполнена; false в противном случае.
    */
    bool IsFull() const { return _buffer.IsFull(); }

    /*@brief Добавление элемента в очередь.
     @param data Элемент, который нужно добавить.
    */
    void Enqueue(const T & data)
    {
        _buffer.Push(data);
    }

    /*@brief Извлечение элемента из очереди.
     *@return Элемент, извлечённый из очереди.
     *@throw std::runtime_error Если очередь пуста.
    */
    T Dequeue()
    {   //TODO:RSDN(сделано)
        if (IsEmpty())
        {
            throw std::underflow_error("Full free queue!");
        }

        return _buffer.Pop();
    }

    /*@brief Возвращает все данные очереди в виде вектора.
    * @return Вектор, содержащий данные очереди.
    */
    std::vector<T> GetData() const
    {
        return _buffer.GetData();
    }
};