#pragma once
#include <iostream>

#include "TreapNode.h"

class Treap
{
private:
    TreapNode* root;

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

    TreapNode* Merge(TreapNode* left, TreapNode* right)
    {
        if (left == nullptr) return right;
        if (right == nullptr) return left;

        if (left->priority > right->priority)
        {
            left->right = Merge(left->right, right);
            return left;
        }
        else
        {
            right->left = Merge(left, right->left);
            return right;
        }
    }

    void Insert(TreapNode*& node, int key)
    {
        if (node == nullptr)
        {
            node = new TreapNode(key);
            return;
        }

        if (key < node->key)
        {
            Insert(node->left, key);
            if (node->left->priority > node->priority)
            {
                node = Merge(node->left, node);
            }
        }
        else if (key > node->key)
        {
            Insert(node->right, key);
            if (node->right->priority > node->priority)
            {
                node = Merge(node, node->right);
            }
        }
        else
        {
            throw "Duplicate keys are not allowed.";
        }
    }

    void Remove(TreapNode*& node, int key)
    {
        if (node == nullptr)
        {
            throw "Key not found.";
        }

        if (key < node->key)
        {
            Remove(node->left, key);
        }
        else if (key > node->key)
        {
            Remove(node->right, key);
        }
        else
        {
            TreapNode* temp = node;
            node = Merge(node->left, node->right);
            delete temp;
        }
    }

    void Inorder(TreapNode* node)
    {
        if (node != nullptr)
        {
            Inorder(node->left);
            std::cout << node->key << " ";
            Inorder(node->right);
        }
    }

public:
    Treap() : root(nullptr) {}

    void Insert(int key)
    {
        Insert(root, key);
    }

    void Remove(int key)
    {
        Remove(root, key);
    }

    void Inorder()
    {
        Inorder(root);
        std::cout << std::endl;
    }
};