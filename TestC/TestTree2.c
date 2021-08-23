#include <stdio.h>
#include <stdlib.h>
//二叉树结点
typedef struct BiTNode{
//数据
char data;
//左右孩子指针
struct BiTNode *Ichild, *rchild;
} BiTNode, *BiTree;
//按前序遍历创建二叉树
int CreateBiTree(BiTree &T) (
char data;
//按先序次序输入二叉树中结点的值(一个字符),‘#scanf("%c", &data) ;
scanf("%c",&data)
if(data=='#') {
T=NULL;
}else{
T=(BiTree) malloc(sizeof(BiTNode));
//生成根结点
T->data=data;
//构造左子树
CreateBiTree(T->lchild);
//构造右子树
CreateBiTree(T->rchild);
}
return 0;
}
//输出
void Visit(BiT reeT) {
if(T->data!='#') {
printf("%c",T->data);
}
}

//-----前序遍历------
void PreOrder (BiTree T){
if(T!=NULL){
//访问根节点
Visit (T)
//访问左子结点
PreOrder(T->lchild);
//访问右子结点
PreOrder(T->rchild);
}
}

//----------中序遍历----------
void InOrder(BiTree T) {
if(T!=NULL){
//访问左子结点
In Order(T->Ichild);//访问根节点
Visit(T);
//访问右子结点
InOrder(T->rchild);
}
}
//----------后序遍历---------
void PosOrder (BiTree T){
if(T!=NULL){
//访问左子结点
PostOrder (T-slchild) ;
//访问右子结点
PostOrder (T->rchild) ：
//访问根节点
Visit(T);
}
}
