#include<bits/stdc++.h>
using namespace std;

struct treeNode{
    int data;
    treeNode* left;
    treeNode* right; 

    treeNode(int d){
        data = d;
        left = right = NULL;
    }
};
void MorrisTraversal(treeNode* root){
    treeNode *current, *pred;

    if(root == NULL){
        return;
    }
    current = root;
    while(current != NULL){

        //1st step
        if(current->left == NULL){
            cout<<current->data<<" ";
            current = current->right;
        }
        else{
            //2nd step
            //find inorder predecessor of current
            pred = current->left;//initialise 
            while(pred->right != NULL && pred->right != current){ 
            /* pred->right != current (this takes care of never ending loops inside a tree traversal)*/
                pred = pred->right;
            }
            //3rd step
            //Make current as the right child of its inorder predecessor
            if(pred->right == NULL){
                pred->right = current;
                current = current->left;
            }
            else{
                pred->right = NULL;
                cout<<current->data<<" ";
                current = current->right;
            }
        }
    }
}
int main(){
    treeNode * root = new treeNode(1);
    root->left = new treeNode(2);
    root->right = new treeNode(3);
    root->left->left = new treeNode(4);
    root->left->right = new treeNode(5);
    cout<<"Added to git :"<<endl;
    cout<<"Morris Traversal result of provided binary tree is as follows -"<<endl;
    MorrisTraversal(root);
 
    return 0;
}