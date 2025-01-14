#pragma once
#include <iostream>

#include "TreapNode.h"

class Treap
{
private:
    /// <summary>
    /// ������ ������.
    /// </summary>
    TreapNode* _root;

    /// <summary>
    /// ��������� ������.
    /// </summary>
    /// <param name="node">���� ��� ����������</param>
    /// <param name="key">���� ��� ����������.</param>
    /// <param name="left">����� ����.</param>
    /// <param name="right">������ ����.</param>
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
    /// ���������� �������.
    /// </summary>
    /// <param name="left">������ ���� ��� �����������.</param>
    /// <param name="right">������ ���� ��� �����������.</param>
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
    /// ��������� ������� � ������.
    /// </summary>
    /// <param name="node">���� ��� �������.</param>
    /// <param name="key">���� ��� �������.</param>
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
    /// ������� ������� �� ������.
    /// </summary>
    /// <param name="node">���� ��� ��������</param>
    /// <param name="key">���� ��� ��������.</param>
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
