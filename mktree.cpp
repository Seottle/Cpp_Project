/*************************************************************************
	> File Name: mktree.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 07 May 2022 05:07:43 PM CST
 ************************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    public:
        int val;
        TreeNode* leftchild;
        TreeNode* rightchild;
        TreeNode(int val_){
            val = val_;
        }
};

/*
TreeNode* creatTree(TreeNode* root, int val){
    if(root == NULL || val == -1){
        root = new TreeNode();
        root -> val = val;
        return root;
    }
    if(val < root -> val){
        root -> leftchild = creatTree(root -> leftchild, val);
    }else{
        root -> rigthchild = creatTree(root -> rightchild, val);
    }
    return root;
}
*/
TreeNode* creatTree(deque<int> q){
    TreeNode* node = NULL;
    if(q.empty()){
        return NULL;
    }
    int data = q.front();
    if(data == -1){
        return NULL;
    }
    q.pop_front();
    if(data != -1){
        node = new TreeNode(data);
        node -> leftchild = creatTree(q);
        node -> rightchild = creatTree(q);
    }
    return node;
}
void pretraver(TreeNode* root){
    if(root == NULL) return;
    cout << root -> val << "";
    pretraver(root -> leftchild);
    //cout << "中序:" << root -> val << " ";
    pretraver(root -> rightchild);
}
int main(){
    //TreeNode *root = NULL;
    deque<int> nums = {5, 4, 6, 3, 7};
    TreeNode *root = creatTree(nums);
    /*
    for(auto i : nums){
        root  = creatTree(root, i); 
    }
    */
    pretraver(root);
    
    return 0;
}

