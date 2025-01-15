#pragma once

#include <iostream>
#include "BinaryTreeNode.h"

struct BinaryTree
{
private:
	/// <summary>
	/// Корень дерева.
	/// </summary>
	BinaryTreeNode* _root;

	/// <summary>
	/// Очищает дерево, начиная с элемента node.
	/// </summary>
	/// <param name="node">Первый элемент для очищения.</param>
	void ClearTree(BinaryTreeNode* node)
	{
		if (node == nullptr)
		{
			return;
		}

		ClearTree(node->left);
		ClearTree(node->right);

		delete node;
	}

public:
	/// <summary>
	/// Возвращает корень дерева.
	/// </summary>
	/// <returns>указатель на корень дерева.</returns>
	BinaryTreeNode* GetRoot() 
	{
		return _root;
	}

	/// <summary>
	/// Конструктор класса.
	/// </summary>
	/// <param name="data">Данные для корневого элемента.</param>
	BinaryTree(int data) : _root(new BinaryTreeNode(data)) {}

	/// <summary>
	/// Деструктор класса.
	/// </summary>
	~BinaryTree()
	{
		ClearTree(_root);
	}

	/// <summary>
	/// Добавляет элемент в дерево.
	/// </summary>
	/// <param name="data">Данные для добавления</param>
	/// <param name="current">Текущий узел дерева</param>
	void AddElement(int data, BinaryTreeNode* current)
	{
		if (current->data == data)
		{
			throw "Data alredy exist in tree!";
		}

		if (current->data > data)
		{
			if (current->left == nullptr)
			{
				current->left = new BinaryTreeNode(data);
				current->left->parent = current;

				return;
			}

			current = current->left;
		}
		else
		{
			if (current->right == nullptr)
			{
				current->right = new BinaryTreeNode(data);
				current->right->parent = current;

				return;
			}

			current = current->right;
		}

		AddElement(data, current);
	}

	/// <summary>
	/// Удаляет элемент дерева.
	/// </summary>
	/// <param name="node">Удаляемый эелемент.</param>
	/// <param name="value">Удаляемое значение.</param>
	/// <returns>Удалённый элемент.</returns>
	BinaryTreeNode* RemoveElement(BinaryTreeNode*& node, const int value)
	{
		if (node == nullptr)
		{
			return nullptr;
		}

		if (value < node->data)
		{
			node->left = RemoveElement(node->left, value);
			if (node->left)
			{
				node->left->parent = node;
			}
		}
		else if (value > node->data)
		{
			node->right = RemoveElement(node->right, value);
			if (node->right)
			{
				node->right->parent = node;
			}
		}
		else 
		{
			// Нет дочерних узлов
			if (node->left == nullptr && node->right == nullptr)
			{
				if (node->parent)
				{
					if (node->parent->left == node)
					{
						node->parent->left = nullptr;
					}
					else
					{
						node->parent->right = nullptr;
					}
				}
				delete node;
				return nullptr;
			}

			// Один дочерний узел (правый)
			if (node->left == nullptr)
			{
				BinaryTreeNode* temp = node->right;

				if (node->parent)
				{
					if (node->parent->left == node)
					{
						node->parent->left = temp;
					}
					else
					{
						node->parent->right = temp;
					}
				}

				temp->parent = node->parent;
				delete node;

				return temp;
			}

			// Один дочерний узел (левый)
			if (node->right == nullptr)
			{
				BinaryTreeNode* temp = node->left;

				if (node->parent)
				{
					if (node->parent->left == node)
					{
						node->parent->left = temp;
					}
					else
					{
						node->parent->right = temp;
					}
				}

				temp->parent = node->parent;
				delete node;

				return temp;
			}

			// Два дочерних узла
			BinaryTreeNode* minright = FindMin(node->right);
			node->data = minright->data;
			node->right = RemoveElement(node->right, minright->data);

			if (node->right)
			{
				node->right->parent = node;
			}
		}

		return node;
	}

	/// <summary>
	/// Находит минимальный элемент дерева.
	/// </summary>
	/// <param name="node">Узел с которого начинается поиск.</param>
	/// <returns>Узел с минимальным значением.</returns>
	BinaryTreeNode* FindMin(BinaryTreeNode* node)
	{
		if (node == nullptr)
		{
			return nullptr;
		}

		while (node->left != nullptr)
		{
			node = node->left;
		}

		return node;
	}

	/// <summary>
	/// Находит максимальный элемент дерева.
	/// </summary>
	/// <param name="node">Узел с которого начинается поиск.</param>
	/// <returns>Узел с максимальным значением.</returns>
	BinaryTreeNode* FindMax(BinaryTreeNode* node)
	{
		if (node == nullptr)
		{
			return nullptr;
		}

		while (node->right != nullptr)
		{
			node = node->right;
		}

		return node;
	}

	/// <summary>
	/// Находит узел с искомым значением.
	/// </summary>
	/// <param name="data">Значение для поиска</param>
	/// <param name="node">Узел, с которого начиается поиск.</param>
	/// <returns>Узел с искомым значением.</returns>
	BinaryTreeNode* Find(int data, BinaryTreeNode* node)
	{
		if (node == nullptr)
		{
			return nullptr;
		}

		if (node->data == data)
		{
			return node;
		}

		if (node->data > data)
		{
			node = node->left;
		}
		else
		{
			node = node->right;
		}

		Find(data, node);
	}
};