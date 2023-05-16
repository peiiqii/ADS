#pragma once

class TreeNode {
public:
	int key;
	TreeNode* left;
	TreeNode* right;
	
	TreeNode() {
		key = -1;
		left = nullptr;
		right = nullptr;
	}

	~TreeNode() {}
};