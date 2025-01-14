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
    /// ���������� �������.
    /// </summary>
    /// <param name="left">������ ���� ��� �����������.</param>
    /// <param name="right">������ ���� ��� �����������.</param>
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
    /// ��������� ������� � ������.
    /// </summary>
    /// <param name="node">���� ��� �������.</param>
    /// <param name="key">���� ��� �������.</param>
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
    /// ������� ������� �� ������.
    /// </summary>
    /// <param name="node">���� ��� ��������</param>
    /// <param name="key">���� ��� ��������.</param>
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
    /// ��������� ������� � ������
    /// </summary>
    /// <param name="key">���� ��� ������.</param>
    void Insert(int key)
    {
        insert(_root, key);
    }

    /// <summary>
    /// ������� ������� �� ������.
    /// </summary>
    /// <param name="key">���� ��� �������.</param>
    void Remove(int key)
    {
        remove(_root, key);
    }
};
