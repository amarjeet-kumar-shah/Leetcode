class Solution {
public:
    void mappingToParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parentMap) {
        if (!root) {
            return ;
        }

        if (root->left) {
            parentMap[root->left] = root;
            mappingToParent(root->left, parentMap);
        }
        if (root->right) {
            parentMap[root->right] = root;
            mappingToParent(root->right, parentMap);   
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        parentMap[root] = nullptr;
        mappingToParent(root, parentMap);

        unordered_set<TreeNode*> visited;
        visited.insert(target);
        queue<TreeNode*> q;
        q.push(target);
        int level = 0;

        while(!q.empty()) {
            int size = q.size();

            if (level == k) {
                break;
            }

            level++;

            while(size--) {
                TreeNode* frontNode = q.front();
                q.pop();

                if (frontNode->left && visited.find(frontNode->left) == visited.end()) {
                    visited.insert(frontNode->left);
                    q.push(frontNode->left);
                }

                if (frontNode->right && visited.find(frontNode->right) == visited.end()) {
                    visited.insert(frontNode->right);
                    q.push(frontNode->right);
                }

                if (parentMap[frontNode] && visited.find(parentMap[frontNode]) == visited.end()) {
                    visited.insert(parentMap[frontNode]);
                    q.push(parentMap[frontNode]);
                }
            }
        }

        vector<int> ans;

        while(!q.empty()) {
            cout << q.front() << " ";
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};