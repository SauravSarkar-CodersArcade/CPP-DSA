#include <iostream>
using namespace std;
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
void inOrderTraversal(TreeNode* root){ // LDR
    if (root != nullptr){
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}
TreeNode* insert(TreeNode* root, int key){
    if (root == nullptr){
//       TreeNode* node = new TreeNode(key);
//       return node;
        return new TreeNode(key);
    }
    if (key < root->data){
        root->left = insert(root->left, key);
    }else if(key > root->data){
        root->right = insert(root->right, key);
    }
    return root;
}
TreeNode* search(TreeNode* root, int key){
    if (root == nullptr || root->data == key){
        return root;
    }
    if (root->data < key){
        return search(root->right, key);
    }
    return search(root->left, key);
}
TreeNode* findMin(TreeNode* root){
    TreeNode* current = root;
    while (current && current->left != nullptr){
        current = current->left;
    }
    return current;
}
TreeNode* deleteNode(TreeNode* root, int key){
    if (root == nullptr){
        return root;
    }
    if (key < root->data){
        root->left = deleteNode(root->left, key);
    } else if (key > root->data){
        root->right = deleteNode(root->right, key);
    } else{
        // Only one child
        if (root->left == nullptr){
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }else if (root->right == nullptr){
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        // Node with two children
        // Finding the in-order successor to replace the root node of that tree
        TreeNode* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    TreeNode* root = nullptr;
    root = insert(root, 50);
    insert(root,30);
    insert(root,20);
    insert(root,40);
    insert(root,70);
    insert(root,90);
    insert(root,80);
    cout << "InOrderTraversal: ";
    inOrderTraversal(root);
    cout << endl;
    int key = 80;
    TreeNode* result = search(root, key);
    if (result == nullptr){
        cout << "Value not found..!!" << endl;
    } else{
        cout << "Value " << key << " found in the BST." << endl;
    }
    cout << "\nDelete 30\n";
    root = deleteNode(root,30);
    cout << "InOrderTraversal: ";
    inOrderTraversal(root);
    cout << endl;
    cout << "\nDelete 50\n";
    root = deleteNode(root,50);
    cout << "InOrderTraversal: ";
    inOrderTraversal(root);
    cout << endl;
    return 0;
}
