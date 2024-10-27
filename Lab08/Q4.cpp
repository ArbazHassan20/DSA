#include <iostream>
#include <memory>

using namespace std;

class TreeNode {
    int val;
    unique_ptr<TreeNode> left;
    unique_ptr<TreeNode> right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool areIdentical(const unique_ptr<TreeNode>& t1, const unique_ptr<TreeNode>& t2) {
    // If both nodes are null, they are identical
    if (!t1 && !t2) return true;
    
    if (!t1 || !t2) return false;
    
    return (t1->val == t2->val) && areIdentical(t1->left, t2->left) && areIdentical(t1->right, t2->right);
}

bool isSubtree(const unique_ptr<TreeNode>& T1, const unique_ptr<TreeNode>& T2) {
    if (!T2) return true; 
    if (!T1) return false; 

    if (areIdentical(T1, T2)) return true;
    return isSubtree(T1->left, T2) || isSubtree(T1->right, T2);
}

// Example usage
int main() {
    // Create T1
    auto T1 = make_unique<TreeNode>(1);
    T1->left = make_unique<TreeNode>(2);
    T1->right = make_unique<TreeNode>(3);
    T1->left->left = make_unique<TreeNode>(4);
    T1->left->right = make_unique<TreeNode>(5);
    T1->right->left = make_unique<TreeNode>(6);
    T1->right->right = make_unique<TreeNode>(7);

    // Create T2
    auto T2 = make_unique<TreeNode>(3);
    T2->left = make_unique<TreeNode>(6);
    T2->right = make_unique<TreeNode>(7);

    // Check if T2 is a subtree of T1
    if (isSubtree(T1, T2)) {
        cout << "T2 is a subtree of T1" << endl;
    } else {
        cout << "T2 is not a subtree of T1" << endl;
    }

    return 0;
}
