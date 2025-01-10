#pragma once


struct BinaryTreeNode
{
	int data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	BinaryTreeNode* parent;

	BinaryTreeNode(int data) : data(data), left(nullptr), right(nullptr), parent(nullptr) {}
	~BinaryTreeNode() {}
};