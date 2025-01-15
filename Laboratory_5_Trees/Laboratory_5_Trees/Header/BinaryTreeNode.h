#pragma once


struct BinaryTreeNode
{
	/// <summary>
	/// ������ � ����.
	/// </summary>
	int data;
	/// <summary>
	/// ����� ����.
	/// </summary>
	BinaryTreeNode* left;
	/// <summary>
	/// ������ ����.
	/// </summary>
	BinaryTreeNode* right;
	/// <summary>
	/// ������������ ����.
	/// </summary>
	BinaryTreeNode* parent;

	/// <summary>
	/// ����������� ������.
	/// </summary>
	/// <param name="data"></param>
	BinaryTreeNode(int data) : data(data), left(nullptr), right(nullptr), parent(nullptr) {}

	/// <summary>
	/// ���������� ������.
	/// </summary>
	~BinaryTreeNode() {}
};