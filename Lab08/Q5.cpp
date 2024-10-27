#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class TreeNode {
    int val;
    unique_ptr<TreeNode> left;
    unique_ptr<TreeNode> right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

unique_ptr<TreeNode> sortedArrayToBST(const vector<int>& nums, int start, int end) {
    if (start > end) return nullptr;

    int mid = start + (end - start) / 2;  
    auto node = make_unique<TreeNode>(nums[mid]); 
  
    node->left = sortedArrayToBST(nums, start, mid - 1);
    node->right = sortedArrayToBST(nums, mid + 1, end);

    return node;
}

unique_ptr<TreeNode> sortedArrayToBST(const vector<int>& nums) {
    return sortedArrayToBST(nums, 0, nums.size() - 1);
}

void inorderTraversal(const unique_ptr<TreeNode>& root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    vector<int> sortedArray = {-8, -1, 2, 7, 11};

    unique_ptr<TreeNode> root = sortedArrayToBST(sortedArray);

    cout << "Inorder Traversal of the constructed BST: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
