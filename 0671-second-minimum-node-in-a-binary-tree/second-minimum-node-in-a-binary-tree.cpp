
class Solution {
public:
    typedef TreeNode Node;
    void Solve(Node* &root, int &mini, int &ans){
        if(!root) return;

        if(root->val > mini){
            // If root->val greater than mini but this is first time so simply make ans = root->val else maintain the minimum in ans which is just greater than mini
            if(ans == -1) ans = root->val;

            else ans = min(ans, root->val);
        }

        Solve(root->left, mini, ans);
        Solve(root->right, mini, ans);
        return;
    }
    int findSecondMinimumValue(Node* root) {
        // Here mini is smallest number this tree can have
        int mini = root->val;
        int ans = -1;
        Solve(root, mini, ans);
        return ans;
    }
};