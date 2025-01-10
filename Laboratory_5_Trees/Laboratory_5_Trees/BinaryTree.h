#pragma once

#include "BinaryTreeNode.h"

struct BinaryTree
{
private:

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

	void InorderTraversal(BinaryTreeNode* node)
	{
		if (node == nullptr)
		{
			return;
		}

		InorderTraversal(node->left);
		std::cout << node->data << " ";
		InorderTraversal(node->right);
	}


public:
	BinaryTreeNode* _root;

	BinaryTree(int data) : _root(new BinaryTreeNode(data)) {}

	~BinaryTree()
	{
		ClearTree(_root);
	}

	void AddElement(int data, BinaryTreeNode* current)
	{
		if (current->data == data)
		{
			throw "";
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

	void RemoveElement(BinaryTreeNode* deletingNode)
	{
		BinaryTreeNode* subNode = FindMin(deletingNode->right);

		if (subNode == nullptr)
		{
			delete deletingNode;
		}

		deletingNode->data = subNode->data;

		if (subNode->right == nullptr)
		{
			if (deletingNode->right == subNode)
			{
				subNode->parent->right = nullptr;
			}
			else
			{
				subNode->parent->left = nullptr;
			}

			delete subNode;
			return;
		}

		RemoveElement(subNode);
	}

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

	void InorderTraversal()
	{
		InorderTraversal(_root);
		std::cout << std::endl;
	}
};