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
void inOrderTraversal(TreeNode* root){ // LDR
    if (root != nullptr){
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}
TreeNode* mirrorTree(TreeNode* root){
    if (root == nullptr){
        return root;
    }
    /*
     * int temp = a;
     * a = b;
     * b = temp;
     */
    // This will swap the left & right part of the tree from the root
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    // Now we need to recursively swap the left & right subtrees
    if (root->left)
        mirrorTree(root->left);
    if (root->right)
        mirrorTree(root->right);
    return root;
}
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "InOrderTraversal of original tree: ";
    inOrderTraversal(root);
    cout << endl;
    mirrorTree(root);
    cout << "InOrderTraversal of mirror tree: ";
    inOrderTraversal(root);
    cout << endl;
    return 0;
}
