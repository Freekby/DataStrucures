#pragma once 

#include "stack.h" 

// TODO: Полетела кодироквка русских символов(сделано)

/**
 * @brief Класс-очередь для реализации очереди с использованием двух стеков.
 */
template <typename T>
class QTwoStacks
{
    //TODO:утечка памяти(устранено см. со стр 84)
private:
    /** @brief Первый стек, используемый для добавления элементов. */
    Stack<T> _stack1;

    /** @brief Второй стек, используемый для извлечения элементов. */
    Stack<T> _stack2;

public:
    /**
     * @brief Проверка на пустоту очереди.
     * @return true, если очередь пуста; иначе false.
     */
    bool IsEmpty() const
    {
        return _stack1.IsStackEmpty() && _stack2.IsStackEmpty();
    }

    /**
     * @brief Добавление элемента в очередь.
     * @param data Элемент, который нужно добавить.
     */
    void Enqueue(const T& data)
    {
        _stack1.Push(data);
    }

    /**
     * @brief Извлечение элемента из очереди.
     * @return Элемент, извлеченный из очереди.
     * @throws std::underflow_error Если очередь пуста.
     */
    T Dequeue()
    {
        //TODO:RSDN(сделано)
        if (IsEmpty())
        {
            throw std::underflow_error("Full free queue!");
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
     * @return Вектор с элементами очереди.
     */
    std::vector<T> GetData() const
    {
        std::vector<T> data;

        std::vector<T> data1 = _stack1.GetData();
        std::reverse(data1.begin(), data1.end());

        std::vector<T> data2 = _stack2.GetData();

        data.insert(data.end(), data2.begin(), data2.end());
        data.insert(data.end(), data1.begin(), data1.end());
        return data;
    }

    /**
     * @brief Очистка очереди, освобождение ресурсов.
     */
    void Clear()
    {
        _stack1.Clear(); 
        _stack2.Clear(); 
    }

    /**
     * @brief Деструктор класса QTwoStacks. Освобождает ресурсы, используемые стеком.
     */
    ~QTwoStacks()
    {
        Clear(); 
    }
};
