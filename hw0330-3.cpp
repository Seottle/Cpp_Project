/*************************************************************************
	> File Name: hw0330-3.cpp
	> Author: Seottle
	> Mail: 874688169@qq.com
	> Created Time: Wed 29 Jun 2022 02:38:13 PM CST
 ************************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val_){
        val = val_;
        left = nullptr;
        right = nullptr;
    }
};
void traval(TreeNode* root){
    if(root == nullptr) return;
    printf("%d----", root -> val);
    traval(root -> left);
    traval(root -> right);
}
//我这个是前序遍历生成二叉树
TreeNode* buildTree(list<int>& nums){
    if(nums.empty()){
        return NULL;
    }
    int val = nums.front();
    nums.pop_front();
    if(val == 0){
        return NULL;
    }
    TreeNode* root = new TreeNode(val);
    root -> left = buildTree(nums);
    root -> right = buildTree(nums);
    return root;
}
//层次遍历生成二叉树,null的孩子不写出来
TreeNode* build(vector<int> nums){
    if(nums.empty()) return NULL;
    int val = nums[0];
    
    TreeNode* root = new TreeNode(val);
    
    queue<TreeNode*> Q;
    Q.push(root);
    for(int i = 1; i < nums.size();){
        TreeNode* parent = Q.front();
        Q.pop();
        int leftnode = nums[i++];
        if(leftnode != 0){
            parent -> left = new TreeNode(leftnode);
            Q.push(parent -> left);
        }else{
            parent -> left = NULL;
        }
        int rightnode = nums[i++];
        if(rightnode != 0){
            parent -> right = new TreeNode(rightnode);
            Q.push(parent -> right);
        }else{
            parent -> right = NULL;
        }
        cout << parent -> val << endl;
    }
    return root;
}
//适用于层次遍历的建树方法  
TreeNode* constructTree(vector<int> nums, int index){
    if(index >= nums.size() || nums[index] == 0) return NULL;
    TreeNode* root = new TreeNode(nums[index]);
    root -> left = constructTree(nums, 2*index + 1);
    root -> right = constructTree(nums, 2*index + 2);
    return root;
}
vector<TreeNode*> ans;
unordered_map<string, int> hash1;
string find(TreeNode* root){
    if(root == NULL) return "#";
    
    string left = find(root -> left);
    string right = find(root -> right);

    string subtree = left + "," + right + "," + to_string(root -> val);
    hash1[subtree]++;
    if(hash1[subtree] == 2){
        ans.push_back(root);
    }
    return subtree;
}
string treetostring(TreeNode* root){
    if(root == NULL) return "null";
    string ans = to_string(root -> val);
    queue<TreeNode*> Q;
    Q.push(root);
    while(!Q.empty()){
        int size = Q.size();
        for(int i = 0; i < size; ++i){
            TreeNode* node = Q.front();
            Q.pop();
            if(node -> left == NULL && node -> right == NULL) break;
            if(node -> left){
                Q.push(node -> left);
                ans += "," + to_string(node -> left -> val);
            }else{
                ans += ",null";
            }
            if(node -> right){
                Q.push(node -> right);
                ans += "," + to_string(node -> right -> val);
            }else{
                ans += ",null";
            }
        }
    }
    return ans;
}
int layerprint(TreeNode* root){
    if(root == NULL) return 0;
    int lever = 0;
    queue<TreeNode*> Q;
    Q.push(root);
    while(!Q.empty()){
        int size = Q.size();
        for(int i = 0; i < size; ++i){
            TreeNode* node = Q.front();
            cout << node -> val << "-";
            Q.pop();
            if(node -> left){
                Q.push(node -> left);
            }
            
            if(node -> right){
                Q.push(node -> right);
            }
        }
        lever++;
    }
    return lever;
}
int getH(TreeNode* root){
    
}
int main(){
    string str;
    cin >> str;
    vector<int> nums;
    list<int> L;
    for(int i = 1; i < str.size();){
        if(isdigit(str[i])){
            L.push_back(str[i] - '0');
            nums.push_back(str[i] - '0');
            i += 2;
        }else{
            nums.push_back(0);
            L.push_back(0);
            i += 5;
        }
    }
    for(auto i : nums){
        cout << i << " ";
    }
    cout << endl;
    //cout << nums.size() << endl;
    TreeNode* root = constructTree(nums, 0);
    //TreeNode* root = buildTree(L);
    //layerprint(root);
    find(root);
    cout << endl;
    //cout << ans.size() << endl;
    TreeNode* ret;
    int MAX = INT_MIN;
    for(auto T : ans){
        //string s = treetostring(T);
        int x = layerprint(T);
        if(x > MAX){
            MAX = x;
            ret = T;
        }
        cout << endl;
        //cout << s << endl;
    }
    string s = treetostring(ret);
    cout << '[' << s << ']' << endl;
    return 0; 
}
