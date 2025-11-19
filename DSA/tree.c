#include<stdio.h>
#include<stdlib.h>
 typedef struct node
{
    int data;
    struct node *left,*right;


}treenode;
treenode * createnode(int data){
    treenode *newnode=(treenode*)malloc(sizeof(treenode));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;

}
treenode * insert(treenode *root,int data){
    if(root==NULL){
        return createnode(data);
    }
    if(root->data>data){
        root->left=insert(root->left,data);

    }
    else{
        root->right=insert(root->right,data);
    }
    return root;
}
void inoder(treenode * root){
    if(root ==NULL){
        return;
    }
    inoder(root->left);
    printf("%d ",root->data);
    inoder(root->right);
}
 int height(treenode * root){
    if(root==NULL){
        return 0;//-1 heihjt will be 2
    }
    int left_height=height(root->left);
    int right_height=height(root->right);
    return(left_height>right_height?left_height:right_height)+1;
 }
int main(){
    treenode* root = NULL;

    root = insert(root, 40);
    insert(root, 20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 60);
    insert(root, 50);
    insert(root, 70);

    printf("Inorder traversal with static count:\n");
   // inorder(root);
    inoder(root);
    printf("\nheigth is tree %d\n",height(root));

}