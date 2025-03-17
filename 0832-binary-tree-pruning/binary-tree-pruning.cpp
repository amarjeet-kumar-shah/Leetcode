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
bool check(TreeNode*root){
    if (root==nullptr ) return false;
    if (root->val==1) return true;
    bool left=check(root->left);
    bool right=check(root->right);
    if (left==false && right==false) return false ;
    else return true;
}
void preorder(TreeNode*root, unordered_map<TreeNode*,TreeNode*> & mp ){
    if (root==nullptr ) return ;
    bool left=check(root->left);
    if (left==true){
        preorder(root->left, mp);
        preorder(root->right,mp);
        return ;
        
    }

    bool right=check(root->right);
     if (right==true){
        preorder(root->left,mp);
        
        preorder(root->right,mp);
        return;
    }
    if(root->val==1){
        preorder(root->left,mp);
        preorder(root->right,mp);
        return;
    }

    else {
           TreeNode*parent=mp[root];
           if (parent==nullptr ) {
            root->left=nullptr;
            root->right=nullptr ;
            return ;
           }
           if (parent->left==root){
            parent->left=nullptr ;
           }
           else{
            parent->right=nullptr;
           }
    }
}
    TreeNode* pruneTree(TreeNode* root) {
        if (root==nullptr ) return nullptr;
        unordered_map<TreeNode*,TreeNode*> mp;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        mp[root]=nullptr ;
        while (!q.empty()){
            TreeNode*temp=q.front();
            q.pop();
            if (temp==nullptr ){
                if (!q.empty()){
                    q.push(nullptr);
                }
            }
            else{
                if (temp->left){
                    mp[temp->left]=temp;
                    q.push(temp->left);
                }
                if (temp->right){
                    mp[temp->right]=temp;
                    q.push(temp->right);
                }
            }
        }
        preorder(root, mp);
        if (root->left==nullptr && root->right==nullptr && root->val==0) return nullptr ;
        return root;
        
    }
};