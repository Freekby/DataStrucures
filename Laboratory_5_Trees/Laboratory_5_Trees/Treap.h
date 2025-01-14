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
    void Split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right)
    {
        if (node == nullptr)
        {
            left = right = nullptr;
        }
        else if (node->key <= key)
        {
            Split(node->right, key, node->right, right);
            left = node;
        }
        else
        {
            Split(node->left, key, left, node->left);
            right = node;
        }
    }

    /// <summary>
    /// Объединяет деревья.
    /// </summary>
    /// <param name="left">Первый узел для объединения.</param>
    /// <param name="right">Второй узел для объединения.</param>
    /// <returns></returns>
    TreapNode* Merge(TreapNode* left, TreapNode* right)
    {
        if (left == nullptr || right == nullptr)
        {
            return left == nullptr ? right : left;
        }

        if (left->priority > right->priority)
        {
            left->right = Merge(left->right, right);
            return left;
        }

        right->left = Merge(left, right->left);
        return right;
    }

public:

    TreapNode* GetRoot() 
    {
        return _root;
    }

    /// <summary>
    /// вставляет элемент в дерево.
    /// </summary>
    /// <param name="node">Узел для вставки.</param>
    /// <param name="key">Ключ для вставки.</param>
    void Insert(TreapNode*& node, int key)
    {
        if (!node)
        {
            node = new TreapNode(key);
            node->key = key;
            return;
        }

        TreapNode* newNode = new TreapNode(key);

        if (node->priority > newNode->priority)
        {
            if (key < node->key)
            {
                Insert(node->left, key);
            }
            else
            {
                Insert(node->right, key);
            }
            return;
        }

        newNode->key = key;
        Split(node, key, newNode->left, newNode->right);
        node = newNode;
    }

    /// <summary>
    /// удаляет элемент из дерева.
    /// </summary>
    /// <param name="node">Узел для удаления</param>
    /// <param name="key">Ключ для удаления.</param>
    void Remove(TreapNode*& node, int key)
    {
        if (!node)
        {
            return;
        }

        if (key > node->key)
        {
            Remove(node->right, key);
        }
        else if (key < node->key)
        {
            Remove(node->left, key);
        }
        else
        {
            TreapNode* temp = node;
            node = Merge(node->left, node->right);

            delete temp;
        }
    }

    void InsertNotOptimized(TreapNode*& node, int key)
    {
        TreapNode* newNode = new TreapNode(key);
        TreapNode* less = nullptr;
        TreapNode* bigger = nullptr;
        Split(node, key, less, bigger);
        node = Merge(Merge(less, newNode), bigger);
    }

    void RemoveNotOptimized(TreapNode*& node, int key, bool& success)
    {
        TreapNode* less = nullptr;
        TreapNode* equal = nullptr;
        TreapNode* bigger = nullptr;

        Split(node, key, less, bigger);
        Split(bigger, key + 1, equal, bigger);
        if (!equal)
        {
            success = false;
        }

        node = Merge(less, bigger);
        delete equal;
    }


    Treap() : _root(nullptr) {}
};
