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
    string temp = "";
    int ans = 0;
    void f(TreeNode* node){

        if(!node) return;

        temp += to_string(node->val);
        f(node->left);
        f(node->right);

        if(!node->left and !node->right){
            ans += stoi(temp);
        }

        temp.pop_back();


    }

    int sumNumbers(TreeNode* root) {
        
        f(root);

        return ans;
    }
};