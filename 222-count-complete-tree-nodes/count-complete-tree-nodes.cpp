class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int l = 0, r = 0;
        for(TreeNode* tree = root; tree; tree = tree -> left) ++l;
       
        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};