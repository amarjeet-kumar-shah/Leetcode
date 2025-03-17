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
class CBTInserter {
private:
    TreeNode *root;
    int num_of_elements = 0;

    int findNoOfElements(TreeNode *root, int h = 0){
        if (root == NULL) return 0;
        return 1 + findNoOfElements(root->left) + findNoOfElements(root->right);
    }
public:
    CBTInserter(TreeNode* root) {
        this->root = root;
        num_of_elements = findNoOfElements(root);
    }
    
    int insert(int val) {
        int k = num_of_elements + 1;
        vector<bool> path;
        while(k > 0) {
            path.push_back(k%2);
            k /= 2;
        }
        reverse(path.begin(),path.end());
        int n = path.size();

        TreeNode *tmp = root;
        for (int i=1;i<n-1;++i) {
            if (path[i]) tmp = tmp->right;
            else tmp = tmp->left;
        }

        if (path[n-1]) tmp->right = new TreeNode(val);
        else tmp->left = new TreeNode(val);

        num_of_elements++;

        return tmp->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */