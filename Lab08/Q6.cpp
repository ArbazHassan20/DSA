#include <iostream>
#include <memory>

using namespace std;

class TreeNode {
    int val;
    unique_ptr<TreeNode> left;
    unique_ptr<TreeNode> right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void findSwappedNodes(TreeNode* root, TreeNode*& prev, TreeNode*& first, TreeNode*& second) {
    if (!root) return;

    findSwappedNodes(root->left.get(), prev, first, second);

    if (prev && root->val < prev->val) {
     
        if (!first) first = prev;
        second = root;
    }
    prev = root;

    findSwappedNodes(root->right.get(), prev, first, second);
}

void recoverTree(TreeNode* root) {
    TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;

    findSwappedNodes(root, prev, first, second);

    if (first && second) {
        swap(first->val, second->val);
    }
}

void inorderTraversal(const unique_ptr<TreeNode>& root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}


int main() {
    auto root = make_unique<TreeNode>(3);
    root->left = make_unique<TreeNode>(1);
    root->right = make_unique<TreeNode>(4);
    root->right->left = make_unique<TreeNode>(2);

    cout << "Inorder Traversal before recovery: ";
    inorderTraversal(root);
    cout << endl;

    recoverTree(root.get());

    cout << "Inorder Traversal after recovery: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
