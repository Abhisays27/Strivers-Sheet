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
class BSTIterator {
public:
    stack<TreeNode*> stk;
    TreeNode* cur;
    
    BSTIterator(TreeNode* root) {
        cur = root;
    }
    
    /** @return the next smallest number */
    int next() {
        while(cur){
            stk.push(cur);
            cur = cur->left;
        }
        cur = stk.top(); stk.pop();
        int val = cur->val;
        cur = cur->right;
        return val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return cur || !stk.empty();
    }
};
 

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */