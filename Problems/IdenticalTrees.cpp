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
bool areTreesIdentical(TreeNode* tree1, TreeNode* tree2){
    // Empty
    if (tree1 == nullptr && tree2 == nullptr){
        return true;
    }
    // One of them is null
    if (tree1 == nullptr || tree2 == nullptr){
        return false;
    }
    // Compare the root node data
    if (tree1->data != tree2->data){ // Root node is getting compared => 1
        return false;
    }
    return (areTreesIdentical(tree1->left, tree2->left) &&
    areTreesIdentical(tree1->right, tree2->right));
}
int main() {
    TreeNode* tree1 = new TreeNode(1);
    tree1->left = new TreeNode(2);
    tree1->right = new TreeNode(3);
    tree1->left->left = new TreeNode(4);
    tree1->left->right = new TreeNode(5);

    TreeNode* tree2 = new TreeNode(1);
    tree2->left = new TreeNode(2);
    tree2->right = new TreeNode(3);
    tree2->left->left = new TreeNode(6);
    tree2->left->right = new TreeNode(5);

    if (areTreesIdentical(tree1, tree2)){
        cout << "Trees are identical." << endl;
    }else{
        cout << "Trees are not identical." << endl;
    }
    return 0;
}
