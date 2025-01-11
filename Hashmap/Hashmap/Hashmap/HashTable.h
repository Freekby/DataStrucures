#pragma once

#include <string>
#include <iostream>

/// <summary>
/// Структура для представления узла в хеш-таблице.
/// </summary>
// TODO: Один файл должен содержать один класс или структуру
struct Node 
{
    // TODO: Комментарии над комментируемом коде. Тоже можно использовать summary
    std::string key; ///< Ключ узла.
    std::string value; ///< Значение узла.
    Node* next; ///< Указатель на следующий узел.

    /// <summary>
    /// Конструктор для создания узла.
    /// </summary>
    /// <param name="k">Ключ.</param>
    /// <param name="v">Значение.</param>
    Node(const std::string& k, const std::string& v) : key(k), value(v), next(nullptr) {}
};

/// <summary>
/// Класс HashTable представляет хеш-таблицу.
/// </summary>
class HashTable 
{
private:
    // TODO: Комментарии над комментируемом коде. Тоже можно использовать summary
    Node** _table; ///< Указатель на массив узлов.
    size_t _size; ///< Размер хеш-таблицы.
    double _maxLoadFactor; ///< Максимальный коэффициент загрузки.
    size_t _count; ///< Количество элементов в хеш-таблице.

    /// <summary>
    /// Получает индекс для заданного ключа.
    /// </summary>
    /// <param name="key">Ключ.</param>
    /// <returns>Индекс в хеш-таблице.</returns>
    size_t GetIndex(const std::string& key) const;

    /// <summary>
    /// Перераспределяет элементы в хеш-таблице.
    /// </summary>
    void Rehash();

public:
    /// <summary>
    /// Конструктор для создания хеш-таблицы.
    /// </summary>
    /// <param name="initialSize">Начальный размер хранилища.</param>
    /// <param name="loadFactor">Коэффициент загрузки хранилища.</param>
    HashTable(size_t initialSize = 10, double loadFactor = 0.75);

    /// <summary>
    /// Деструктор для освобождения ресурсов хеш-таблицы.
    /// </summary>
    ~HashTable();

    /// <summary>
    /// Вставляет пару ключ-значение в хеш-таблицу.
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
    /// Находит значение по ключу.
    /// </summary>
    /// <param name="key">Ключ.</param>
    /// <returns>Значение, связанное с ключом, или пустую строку, если ключ не найден.</returns>
    std::string Find(const std::string& key) const;

    /// <summary>
    /// Вычисляет хеш для заданного ключа.
    /// </summary>
    /// <param name="key">Ключ.</param>
    /// <returns>Хеш-значение.</returns>
    size_t static GetHash(const std::string& key);

    /// <summary>
    /// Получает указатель на ведро по индексу.
    /// </summary>
    /// <param name="index">Индекс.</param>
    /// <returns>Указатель на ведро.</returns>
    Node* GetBucket(size_t index) const;

    /// <summary>
    /// Возвращает размер хеш-таблицы.
    /// </summary>
    /// <returns>Размер хеш-таблицы.</returns>
    size_t GetSize() const;

    /// <summary>
    /// Возвращает количество элементов в хеш-таблице.
    /// </summary>
    /// <returns>Количество элементов.</returns>
    size_t GetCount() const;
};
