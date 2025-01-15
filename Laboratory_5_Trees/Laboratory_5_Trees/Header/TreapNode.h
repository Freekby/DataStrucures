#pragma once

struct TreapNode
{
    /// <summary>
    /// Ключ.
    /// </summary>
    int key;
    /// <summary>
    /// Приоритет.
    /// </summary>
    int priority;
    /// <summary>
    /// Левый узел.
    /// </summary>
    TreapNode* left;
    /// <summary>
    /// Правый узел.
    /// </summary>
    TreapNode* right;

    /// <summary>
    /// Конструктор класса.
    /// </summary>
    /// <param name="k">Ключ.</param>
    TreapNode(int k) : key(k), priority(10), left(nullptr), right(nullptr) {}
};