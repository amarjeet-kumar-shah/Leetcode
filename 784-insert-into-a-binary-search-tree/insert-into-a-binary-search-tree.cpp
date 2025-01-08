/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newnode=new TreeNode(val);
        if (!root)  return newnode;
        TreeNode* curr=root;
        while(curr){
            if(curr->val <val){
                if(curr->right==nullptr){
                    curr->right=newnode;
                    break;}
                curr=curr->right;
            }
            if(curr->val >val){
                if(curr->left==nullptr){
                    curr->left=newnode;
                    break;}
                curr=curr->left;
            }
        }
        return root;
    }
};