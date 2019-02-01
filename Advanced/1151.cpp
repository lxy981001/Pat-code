#include<cstdio>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
const int maxn=10010;
struct node{
    int data;
    node *lchild,*rchild;
};
int pre[maxn],in[maxn];
int n,k,u,v;
node *creat(int prel,int prer,int inl,int inr){
    if(prel>prer){
        return NULL;
    }
    node *root=new node;
    root->data=pre[prel]; 
    int k;
    for( k=inl;k<=inr;k++){
        if(in[k]==pre[prel])
        break;
    }  
    int leftnum=k-inl; 
    root->lchild =creat(prel+1,prel+leftnum,inl,k-1); //下标要写对哦
    root->rchild =creat(prel+leftnum+1,prer,k+1,inr);
    return root;
}
bool findnode(int u){ //查找节点 
    for(int i=0;i<n;i++){
        if(u==pre[i])
         return true;
    }
    return false;
}
node *LCA(node *root, int u, int v) { //查找两节点最近祖先 
        if (root == NULL) return NULL;
        if (root->data== u || root->data== v) return root;
        node *left =LCA(root->lchild,u,v);
        node *right = LCA(root->rchild,u,v);
        if (left && right ) return root; //u,v分别位于左右子树的情况
        return left == NULL ? right : left;
}
int main(){
    scanf("%d %d",&k,&n);
    for(int i=0;i<n;i++)
        scanf("%d",&in[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&pre[i]);
    node *root=creat(0,n-1,0,n-1); // 尴尬，刚开始中序，先序顺序输反了，调了半天bug 
    for(int i=0;i<k;i++){
        scanf("%d %d",&u,&v);
        if(findnode(u)==false && findnode(v)==false)
           printf("ERROR: %d and %d are not found.\n", u, v);
        else if (findnode(u)==false || findnode(v)==false)
            printf("ERROR: %d is not found.\n", findnode(u)==false ? u : v);
        else {
            node *temp=LCA(root,u,v);
            if(temp->data==u || temp->data==v){
               printf("%d is an ancestor of %d.\n",temp->data==u? u:v,temp->data==u? v:u);
            }else{
                printf("LCA of %d and %d is %d.\n",u,v,temp->data);
            }
        }
    }
    return 0;
}
