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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>q;
        vector<int>ans;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            TreeNode* last = nullptr;
            while(size--){
                TreeNode* top = q.front();
                q.pop();
                last = top;
                if(top){
                q.push(top->left);
                q.push(top->right);
                }
            }
            if(last)ans.push_back(last->val);
        }
        return ans;
    }
};
