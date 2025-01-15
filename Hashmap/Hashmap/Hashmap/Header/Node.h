#pragma once 
#include <string>;
/// <summary>
/// Структура для представления узла в хеш-таблице.
/// </summary>
struct Node
{
    /// <summary>
    /// Ключ узла.
    /// </summary>
    std::string key;

    /// <summary>
    /// Значение узла.
    /// </summary>
    std::string value;
    
    /// <summary>
    /// Указатель на следующий узел.
    /// </summary>
    Node *next;

    /// <summary>
    /// Конструктор для создания узла.
    /// </summary>
    /// <param name="k">Ключ.</param>
    /// <param name="v">Значение.</param>
    Node(const std::string &k, const std::string &v): key(k), value(v), next(nullptr) {}
};
