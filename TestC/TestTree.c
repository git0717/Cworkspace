#include <stdio.h>
#include <stdlib.h>

typedef struct treenode{
    char str;
    struct treenode *left;
    struct treenode *right;
}*btree,treenode;

void createtree(btree btre, char *str, int num){
    int lr = 0; // left 0, right 1
    int top = 0;
    btree p;
    btree pstack[num];

    for(int i=0; i < num; i++){
        switch(str[i]){
            case '(':
                {
                    printf("(");
                    lr = 0;
                    top ++;
                    pstack[top] = p;
                    break;
                }
            case ')':
                {
                    printf(")");
                    if(top < 1){
                        printf("stack is empty\n");
                        exit(0);
                    }
                    top --;
                    break;
                }
            case ',':
                {
                    printf(",");
                    lr = 1;
                    break;
                }
            default:
                {
                    printf("d");
                    p = (btree)malloc(sizeof(treenode));
                    p->left = p->right = NULL;
                    p->str = str[i];
                    if(top == 0){
                        btre->str = p->str;
                        break;
                    }
                    if(lr == 0){
                        pstack[top]->left = p;
                    }
                    else
                        pstack[top]->right = p;
                }
        }
    }
    btre->right = pstack[1]->right;
    btre->left = pstack[1]->left;
}
//-----前序遍历------
void preorder(btree btre){
    btree p = btre;
    
    if(p != NULL){
        printf("%c->",p->str);
        preorder(p->left); //访问左子结点
        preorder(p->right);//访问右子结点
    }
}
//----------中序遍历----------
void inorder(btree btre){
    btree p = btre;

    if(p != NULL){
        inorder(p->left);
        printf("%c->",p->str);
        inorder(p->right);
    }
}
//----------后序遍历---------
void postorder(btree btre){
    btree p = btre;

    if(p != NULL){
        postorder(p->left);//访问左子结点
        postorder(p->right);//访问右子结点
        printf("%c->",p->str);
    }
}
//----------清理树结构---------
void cleartree(btree btre){
    if(btre != NULL){
        cleartree(btre->left);//清理左子结点
        cleartree(btre->right);//清理右子结点
        free(btre);
        btre = NULL;
        printf(".");
    }
}

char search(btree btre,char x){
    if(btre == NULL){
        return 'N';
    }else{
        if(x == btre->str){
            return btre->str;
        }else{
            if(x == search(btre->left,x)){
                return x;
            }
            if(x == search(btre->right,x)){
                return x;
            }
            return 'N';
        }
    }
}

int main(){
//       1
//    2      3
//  4  5      6
//       7  
//1(2(4,5(7,)),3(,6))
    char *str = "1(2(4,5(7,)),3(,6))"; 
    printf("%s\n",str);
    btree btre = (btree)malloc(sizeof(treenode));
    createtree(btre, str, 19);  //二叉树转字符长度
    printf("\n前序结果--->:\n");
    preorder(btre);
    printf("\n中序结果--->:\n");
    inorder(btre);
    printf("\n后序结果--->:\n");
    postorder(btre);
    
    char c = search(btre,'d');
    printf("\nsearch result:%c",c);
    printf("\nclear");
    cleartree(btre);
    printf("\n");
    system("pause");
}