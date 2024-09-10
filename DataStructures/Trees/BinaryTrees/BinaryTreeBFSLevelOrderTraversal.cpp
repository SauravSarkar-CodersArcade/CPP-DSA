#include <iostream>
#include <queue>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};
//class BinaryTree {
//public:
//    TreeNode* root;
//    BinaryTree() : root(nullptr) {}
//    // Level Order Traversal
//    void levelOrderTraversal(){
//        if (root == nullptr){
//            return;
//        }
//        queue<TreeNode*> q;
//        q.push(root);
//        while (!q.empty()){
//            TreeNode* node = q.front();
//            q.pop();
//            cout << node->val << " ";
//            // Left Side
//            if (node->left != nullptr){
//                q.push(node->left);
//            }
//            // Right Side
//            if (node->right != nullptr){
//                q.push(node->right);
//            }
//        }
//    }
//};
void levelOrderTraversal(TreeNode* root){
    if (root == nullptr){
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        cout << node->val << " ";
        // Left Side
        if (node->left != nullptr){
            q.push(node->left);
        }
        // Right Side
        if (node->right != nullptr){
            q.push(node->right);
        }
    }
}
int main() {
//    BinaryTree tree;
//    tree.root = new TreeNode(1);
//    tree.root->left = new TreeNode(2);
//    tree.root->right = new TreeNode(3);
//    tree.root->left->left = new TreeNode(4);
//    tree.root->left->right = new TreeNode(5);
//    tree.root->right->right = new TreeNode(6);
//
//    cout << "Level Order Traversal: ";
//    tree.levelOrderTraversal();
    TreeNode* root;
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    cout << "Level Order Traversal: ";
    levelOrderTraversal(root);
    return 0;
}
