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
/*
int findHeight(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int lh = findHeight(root->left);
        int rh = findHeight(root->right);
        return 1 + max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int maxi = INT_MIN;
        int lh = findHeight(root->left);
        int rh = findHeight(root->right);
        maxi = max(maxi, lh+rh);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return maxi;
    }
*/
class Solution {
private:
    int height(TreeNode *root, int &diameter){
        if(!root){
            return 0;
        }
        int lh = height(root->left, diameter);
        int rh = height(root->right, diameter);
        diameter = max(diameter, lh + rh);
        return 1 + max(lh, rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root){
        int diameter = 0;
        height(root, diameter);
        return diameter;        
    }    
};