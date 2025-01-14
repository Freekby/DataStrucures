#pragma once
#include <iostream>

#include "TreapNode.h"

class Treap
{
private:
    /// <summary>
    /// Корень дерева.
    /// </summary>
    TreapNode* _root;

    /// <summary>
    /// Разделяет дерево.
    /// </summary>
    /// <param name="node">Узел для разделения</param>
    /// <param name="key">Ключ для разделения.</param>
    /// <param name="left">Левый узел.</param>
    /// <param name="right">Правый узел.</param>
    void split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right)
    {
        if (node == nullptr)
        {
            left = right = nullptr;
        }
        else if (node->key <= key)
        {
            split(node->right, key, node->right, right);
            left = node;
        }
        else
        {
            split(node->left, key, left, node->left);
            right = node;
        }
    }

    /// <summary>
    /// Объединяет деревья.
    /// </summary>
    /// <param name="left">Первый узел для объединения.</param>
    /// <param name="right">Второй узел для объединения.</param>
    /// <returns></returns>
    TreapNode* merge(TreapNode* left, TreapNode* right)
    {
        if (left == nullptr || right == nullptr)
        {
            return left == nullptr ? right : left;
        }

        if (left->priority > right->priority)
        {
            left->right = merge(left->right, right);
            return left;
        }
        right->left = merge(left, right->left);
        return right;
    }

    /// <summary>
    /// вставляет элемент в дерево.
    /// </summary>
    /// <param name="node">Узел для вставки.</param>
    /// <param name="key">Ключ для вставки.</param>
    void insert(TreapNode*& node, int key)
    {
        if (node == nullptr)
        {
            node = new TreapNode(key);
            return;
        }

        if (key < node->key)
        {
            insert(node->left, key);
            if (node->left->priority > node->priority)
            {
                node = merge(node->left, node);
            }
        }
        else if (key > node->key)
        {
            insert(node->right, key);
            if (node->right->priority > node->priority)
            {
                node = merge(node, node->right);
            }
        }
        else
        {
            throw "Duplicate keys are not allowed.";
        }
    }

    /// <summary>
    /// удаляет элемент из дерева.
    /// </summary>
    /// <param name="node">Узел для удаления</param>
    /// <param name="key">Ключ для удаления.</param>
    void remove(TreapNode*& node, int key)
    {
        if (node == nullptr)
        {
            throw "Key not found.";
        }

        if (key < node->key)
        {
            remove(node->left, key);
        }
        else if (key > node->key)
        {
            remove(node->right, key);
        }
        else
        {
            TreapNode* temp = node;
            node = merge(node->left, node->right);
            delete temp;
        }
    }

public:
    Treap() : _root(nullptr) {}

    /// <summary>
    /// Вставляет элемент в дерево
    /// </summary>
    /// <param name="key">Ключ для втавки.</param>
    void Insert(int key)
    {
        insert(_root, key);
    }

    /// <summary>
    /// удаляет элемент из дерева.
    /// </summary>
    /// <param name="key">Ключ для вставки.</param>
    void Remove(int key)
    {
        remove(_root, key);
    }
};
