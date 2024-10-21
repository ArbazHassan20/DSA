#include <iostream>
#include <deque>
#include <vector>

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

    void printZigzag() {
        if (!root) return;

        deque<TreeNode*> currentLevel;
        currentLevel.push_back(root);
        bool leftToRight = true;

        while (!currentLevel.empty()) {
            int levelSize = currentLevel.size();
            vector<int> levelValues;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node;

                if (leftToRight) {
                    node = currentLevel.front();
                    currentLevel.pop_front();
                    levelValues.push_back(node->value);

                    if (node->left) currentLevel.push_back(node->left);
                    if (node->right) currentLevel.push_back(node->right);
                } else {
                    node = currentLevel.back();
                    currentLevel.pop_back();
                    levelValues.push_back(node->value);

                    if (node->right) currentLevel.push_front(node->right);
                    if (node->left) currentLevel.push_front(node->left);
                }
            }

            for (int value : levelValues) {
                cout << value << " ";
            }
            cout << endl;

            leftToRight = !leftToRight;
        }
    }
};

int main() {
    // Create a sample binary tree
    BinaryTree tree;
    tree.root = new TreeNode(1);
    tree.root->left = new TreeNode(2);
    tree.root->right = new TreeNode(3);
    tree.root->left->left = new TreeNode(4);
    tree.root->left->right = new TreeNode(5);
    tree.root->right->left = new TreeNode(6);
    tree.root->right->right = new TreeNode(7);

    // Print the tree in zigzag order
    cout << "Zigzag Order Traversal:" << endl;
    tree.printZigzag();

    return 0;
}
