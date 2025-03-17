class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(0);
        TreeNode* temp = dummy;
        inorder(root, temp);
        return dummy->right;
    }
    
    void inorder(TreeNode* root, TreeNode*& temp) {
        if (root == nullptr) return;
        
        inorder(root->left, temp);
        
        root->left = nullptr;
        temp->right = root;
        temp = root;
        
        inorder(root->right, temp);
    }
};