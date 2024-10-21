#include <iostream>
#include <algorithm> // For std::max

using namespace std;

class TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    TreeNode* root;

    BinaryTree() : root(nullptr) {}

    // Function to find the maximum profit path
    int maxProfitPath() {
        return maxProfitPathHelper(root);
    }

private:
   
    int maxProfitPathHelper(TreeNode* node) {
        if (!node) return 0;

        int leftProfit = maxProfitPathHelper(node->left);
        int rightProfit = maxProfitPathHelper(node->right);
      
        int maxCurrent = max(node->value, node->value + max(leftProfit, rightProfit));

        maxPathSum = max(maxPathSum, maxCurrent);

        return maxCurrent;
    }

    int maxPathSum = INT_MIN;
};

int main() {
    // Create a sample binary tree representing profits and losses
    BinaryTree tree;
    tree.root = new TreeNode(10);
    tree.root->left = new TreeNode(2);
    tree.root->right = new TreeNode(10);
    tree.root->left->left = new TreeNode(20);
    tree.root->left->right = new TreeNode(1);
    tree.root->right->right = new TreeNode(-25);
    tree.root->right->right->left = new TreeNode(3);
    tree.root->right->right->right = new TreeNode(4);

   
    cout << "Maximum Profit Path: " << tree.maxProfitPath() << endl;

    return 0;
}
