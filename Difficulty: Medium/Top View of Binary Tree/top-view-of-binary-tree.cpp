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
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        queue<pair<Node*,int>>q;
        map<int,int>mpp;
        q.push({root,0});
        while(!q.empty()){
            Node* temp = q.front().first;
            int verti = q.front().second;
            q.pop();
            if(mpp.find(verti)==mpp.end()){
                mpp[verti] = temp->data;
            }
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