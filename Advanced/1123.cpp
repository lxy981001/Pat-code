#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int n,num[25];
struct node{
    int data,height;
    node *left,*right;
};
node* newnode(int v){
    node* root=new node;
    root->data=v;
    root->right=root->left=NULL;
    root->height=1;
    return root;
}
int getHeight(node* root){
    if(root==NULL) return 0;
    else return root->height;
}
int getBalance(node* root){
    return getHeight(root->left)-getHeight(root->right);
}
void updataHeight(node* root){
    root->height=max(getHeight(root->left),getHeight(root->right))+1;
}
void L(node* &root){
    node* temp=root->right;
    root->right=temp->left;
    temp->left=root;
    updataHeight(root);
    updataHeight(temp);
    root=temp;
}
void R(node* &root){
    node* temp=root->left;
    root->left=temp->right;
    temp->right=root;
    updataHeight(root);
    updataHeight(temp);
    root=temp;
}
void insert(node* &root,int v){
    if(root==NULL){
        root=newnode(v);
        return;
    }
    if(v<root->data){
        insert(root->left,v);
        updataHeight(root);
        if(getBalance(root)==2){
            if(getBalance(root->left)==1){
                R(root);
            }else if(getBalance(root->left)==-1){
                L(root->left);
                R(root);
            }
        }
    }else{
        insert(root->right,v);
        updataHeight(root);
        if(getBalance(root)==-2){
            if(getBalance(root->right)==1){
                R(root->right);
                L(root);
            }else if(getBalance(root->right)==-1){
                L(root);
            }
        }
    }
}
node* Create(int a[],int n){
    node* root=NULL;
    for(int i=0;i<n;i++){
        insert(root,a[i]);
    }
    return root;
}
void BFS(node* root){
    queue<node*>q;
    q.push(root);
    int k=0;
    bool flag=true,flag1=true;
    while(!q.empty()){
        node* top=q.front();
        q.pop();
        if(top==NULL) flag1=false;
        else{
            cout<<top->data;
            if(k<n-1) cout<<" ";
            else cout<<endl;
            k++;
        }
        if(flag1==false&&top!=NULL)flag=false;
        if(top){
            q.push(top->left);
            q.push(top->right);
        }
    }
    if(flag==true )cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    node *root=Create(num,n);
    BFS(root);
    return 0;
}