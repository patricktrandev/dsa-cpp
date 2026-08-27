#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    
    
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BinaryTree {
public:

    void preorder(TreeNode* root) {
        if (!root) return;
        std::cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        std::cout << root->val << " ";
        inorder(root->right);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                currentLevel.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            result.push_back(currentLevel);
        }
        return result;
    }

    
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }
};

int main() {
    /*
        
             1
            / \
           2   3
          / \
         4   5
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    BinaryTree tree;

    cout << "Inorder Traversal: ";
    tree.inorder(root); // Output: 4 2 5 1 3
    cout << "\n";

    cout << "Max Depth: " << tree.maxDepth(root) << "\n"; // Output: 3

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}