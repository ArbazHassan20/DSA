#include <iostream>
#include <sstream>
#include <string>

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

    string serialize(TreeNode* node) {
        if (!node) return "#";
        return to_string(node->value) + "," + serialize(node->left) + "," + serialize(node->right);
    }

    TreeNode* deserialize(const string& data) {
        istringstream stream(data);
        return deserializeHelper(stream);
    }

private:

    TreeNode* deserializeHelper(istringstream& stream) {
        string val;
        if (!getline(stream, val, ',')) return nullptr;
        if (val == "#") return nullptr;

        TreeNode* node = new TreeNode(stoi(val));
        node->left = deserializeHelper(stream);
        node->right = deserializeHelper(stream);
        return node;
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

   
    string serialized = tree.serialize(tree.root);
    cout << "Serialized Tree: " << serialized << endl;

    TreeNode* deserializedRoot = tree.deserialize(serialized);
    cout << "Deserialization complete!" << endl;

    return 0;
}
