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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        if(root==NULL)return {};

        vector<vector<int>> ans;
        queue<pair<TreeNode*,pair<int,int>>> q;
        map<int,map<int,multiset<int>>> mp;

        q.push({root,{0,0}});

        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto p=q.front();q.pop();

                TreeNode* node=p.first;
                int row=p.second.first;
                int col=p.second.second;

                mp[col][row].insert(node->val);
                if(node->left)q.push({node->left,{row+1,col-1}});
                if(node->right)q.push({node->right,{row+1,col+1}});
            }
        }

        for(auto &it:mp){
            vector<int> v;
            for(auto &itt:it.second){
                for(auto &ele:itt.second){
                    v.push_back(ele);
                }
            }
            ans.push_back(v);
        }

        return ans;
    }
};