#pragma once
#include "HashTable.h"
#include <string>
// TODO: Исправить кодировку комментариев
// TODO: Это не является оберткой, это должен быть словарь (Dictionary)
/// <summary>
/// Описание класса для работы со словарем.
/// </summary>
class Dictionary
{
private:
    // TODO: Комментарии над комментируемом коде. Тоже можно использовать summary
    HashTable _dictionary; // Хранит данные словаря.

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
    /// Печатает текущее состояние словаря.
    /// </summary>
    void PrintState() const;
};
