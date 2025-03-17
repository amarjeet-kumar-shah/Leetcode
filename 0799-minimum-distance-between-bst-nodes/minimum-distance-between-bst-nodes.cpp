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
void inorder(TreeNode*root, vector<int> & ans){
    if (root==nullptr ) return;
    inorder(root->left, ans);
   ans.push_back(root->val);
   inorder(root->right,ans);
}
    int minDiffInBST(TreeNode* root) {
        // pta ni kese krna h dekhte h kese krenge
        vector<int> ans;
        inorder(root, ans);

        int sum=INT_MAX;
        int n=ans.size();
        for(int i=0;i<n-1;i++){
            int diff=ans[i+1]-ans[i];
            sum=min(sum,diff)
            ;
        }
        return sum;

        
        
    }
};