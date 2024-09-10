#include <iostream>
using namespace std;
class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        data = val;
        left = right = nullptr;
    }
};
void preOrderTraversal(TreeNode* root){ // DLR
    if (root != nullptr){
        cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}
void inOrderTraversal(TreeNode* root){ // LDR
    if (root != nullptr){
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}
void postOrderTraversal(TreeNode* root){ // LRD
    if (root != nullptr){
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->data << " ";
    }
}
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->right->left = new TreeNode(9);
    root->right->right->left = new TreeNode(15);
    cout << "PreOrderTraversal: ";
    preOrderTraversal(root);
    cout << endl;
    cout << "InOrderTraversal: ";
    inOrderTraversal(root);
    cout << endl;
    cout << "PostOrderTraversal: ";
    postOrderTraversal(root);
    cout << endl;
    return 0;
}
