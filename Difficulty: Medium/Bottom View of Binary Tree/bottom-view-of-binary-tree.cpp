/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // Your Code Here
        vector<int>ans;
        if(!root)return ans;
        map<int,int>mpp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            Node* temp = p.first;
            int verti = p.second;
            mpp[verti] = temp->data;
            if(temp->left){
                q.push({temp->left,verti-1});
            }
            if(temp->right){
                q.push({temp->right,verti+1});
            }
        }
        for(auto mp:mpp){
            ans.push_back(mp.second);
        }
        return ans;
    }
};