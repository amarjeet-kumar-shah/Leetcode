class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> temp;
            int n = q.size();


               for (int i = 0; i < n; i++) {
                TreeNode* ptr = q.front();
                q.pop();
                temp.push_back(ptr->val);
                if (ptr->left)
                    q.push(ptr->left);
                if (ptr->right)
                    q.push(ptr->right);
                }


            ans.push_back(temp);
        }
        return ans;
    }
};