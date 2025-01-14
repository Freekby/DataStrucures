#pragma once


struct BinaryTreeNode
{
	/// <summary>
	/// Данные в узле.
	/// </summary>
	int data;
	/// <summary>
	/// Левый узел.
	/// </summary>
	BinaryTreeNode* left;
	/// <summary>
	/// Правый узел.
	/// </summary>
	BinaryTreeNode* right;
	/// <summary>
	/// Родительский узел.
	/// </summary>
	BinaryTreeNode* parent;

	/// <summary>
	/// Конструктор класса.
	/// </summary>
	/// <param name="data"></param>
	BinaryTreeNode(int data) : data(data), left(nullptr), right(nullptr), parent(nullptr) {}

	/// <summary>
	/// Деструктор класса.
	/// </summary>
	~BinaryTreeNode() {}
};