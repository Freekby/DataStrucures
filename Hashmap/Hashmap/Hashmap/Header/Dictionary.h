#pragma once
#include "HashTable.h"
#include <string>

/// <summary>
/// Описание класса для работы со словарем.
/// </summary>
class Dictionary
{
private:
    /// <summary>
    /// Хранит данные словаря.
    /// </summary>
    HashTable _dictionary;

public:
    /// <summary>
    /// Конструктор класса.
    /// </summary>
    /// <param name="initialSize">Начальный размер хранилища словаря.</param>
    /// <param name="loadFactor">Коэффициент загрузки хранилища.</param>
    Dictionary(size_t initialSize = 10, double loadFactor = 0.75);

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
    /// <returns>Значение, связанное с ключом, или пустую строку, если ключ не найден.</returns>
    std::string Find(const std::string& key);

    /// <summary>
    /// Возвращает размер словаря.
    /// </summary>
    /// <returns>Размер словаря.</returns>
    size_t GetSize();

    /// <summary>
    /// Получает указатель на ведро по индексу.
    /// </summary>
    /// <param name="index">Индекс.</param>
    /// <returns>Указатель на ведро.</returns>
    Node* GetBucket(size_t index) const;
};
