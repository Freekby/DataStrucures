#pragma once

#include <string>
#include <iostream>

/// <summary>
/// Структура для хранения пары ключ-значение.
/// </summary>
struct Node 
{
    std::string key; ///< Ключ.
    std::string value; ///< Значение.
    Node* next; ///< Указатель на следующую пару.

    /// <summary>
    /// Конструктор элемента хеш-таблицы.
    /// </summary>
    /// <param name="k">Ключ.</param>
    /// <param name="v">Значение.</param>
    Node(const std::string& k, const std::string& v) : key(k), value(v), next(nullptr) {}
};

/// <summary>
/// Класс HashTable реализует хеш-таблицу.
/// </summary>
class HashTable 
{
private:
    Node** _table; ///< Массив указателей на списки.
    size_t _size; ///< Размер таблицы.
    double _maxLoadFactor; ///< Максимальный коэффициент заполнения.
    size_t _count; ///< Текущее количество элементов.

    /// <summary>
    /// Преобразование в индекс массива.
    /// </summary>
    /// <param name="key">Ключ.</param>
    /// <returns>Индекс массива.</returns>
    size_t GetIndex(const std::string& key) const;

    /// <summary>
    /// Перехеширование.
    /// </summary>
    void Rehash();

public:
    /// <summary>
    /// Конструктор хеш-таблицы.
    /// </summary>
    /// <param name="initialSize">Начальный размер.</param>
    /// <param name="loadFactor">Максимальный коэффициент заполнения.</param>
    HashTable(size_t initialSize = 10, double loadFactor = 0.75);

    /// <summary>
    /// Деструктор хеш-таблицы.
    /// </summary>
    ~HashTable();

    /// <summary>
    /// Добавляет элемент в хеш-таблицу.
    /// </summary>
    /// <param name="key">Ключ.</param>
    /// <param name="value">Значение.</param>
    void Insert(const std::string& key, const std::string& value);

    /// <summary>
    /// Удаляет элемент по ключу.
    /// </summary>
    /// <param name="key">Ключ.</param>
    void Remove(const std::string& key);

    /// <summary>
    /// Ищет значение по ключу.
    /// </summary>
    /// <param name="key">Ключ.</param>
    /// <returns>Найденное значение или пустая строка, если элемент не найден.</returns>
    std::string Find(const std::string& key) const;

    /// <summary>
    /// Хеш-функция.
    /// </summary>
    /// <param name="key">Ключ.</param>
    /// <returns>Хеш как число.</returns>
    size_t static GetHash(const std::string& key);

    /// <summary>
    /// Получает бакет по индексу.
    /// </summary>
    /// <param name="index">Индекс.</param>
    /// <returns>Бакет.</returns>
    Node* GetBucket(size_t index) const;

    /// <summary>
    /// Получает размер таблицы.
    /// </summary>
    /// <returns>Размер таблицы.</returns>
    size_t GetSize() const;

    /// <summary>
    /// Получает количество элементов.
    /// </summary>
    /// <returns>Количество элементов.</returns>
    size_t GetCount() const;
};
