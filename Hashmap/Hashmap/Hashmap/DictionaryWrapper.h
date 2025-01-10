#pragma once
#include "Dictionary.h"
#include <string>

/// <summary>
/// Класс-обертка для работы со словарем.
/// </summary>
class DictionaryWrapper
{
private:
    HashTable _dictionary; // Хеш-таблица для хранения данных.

public:
    /// <summary>
    /// Конструктор словаря.
    /// </summary>
    /// <param name="initialSize">Начальный размер хеш-таблицы.</param>
    /// <param name="loadFactor">Максимальный коэффициент загрузки.</param>
    DictionaryWrapper(size_t initialSize = 10, double loadFactor = 0.75);

    /// <summary>
    /// Добавляет пару ключ-значение.
    /// </summary>
    /// <param name="key">Ключ.</param>
    /// <param name="value">Значение.</param>
    void Add(const std::string& key, const std::string& value);

    /// <summary>
    /// Удаляет элемент по ключу.
    /// </summary>
    /// <param name="key">Ключ.</param>
    void Remove(const std::string& key);

    /// <summary>
    /// Находит значение по ключу.
    /// </summary>
    /// <param name="key">Ключ.</param>
    /// <returns>Значение, связанное с ключом, или пустая строка, если элемент не найден.</returns>
    std::string Find(const std::string& key);

    /// <summary>
    /// Выводит текущее состояние словаря и хеш-таблицы.
    /// </summary>
    void PrintState() const;
};
