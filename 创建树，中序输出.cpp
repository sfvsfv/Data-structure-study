#include<iostream>
using namespace std;
typedef int KeyType;
typedef struct {
    KeyType  key;
} ElemType;
typedef struct BitNode {
    ElemType data;
    struct BitNode* lchild, * rchild;
}BitNode, * BiTree;

BiTree insert(BiTree b, BiTree s)
{
    if (b == NULL) b = s;
    else if (s->data.key > b->data.key) b->rchild = insert(b->rchild, s);
    else if (s->data.key < b->data.key) b->lchild = insert(b->lchild, s);
    return b;
}

BiTree creat() {
    int k;
    BiTree t, s;
    t = NULL;
    scanf_s("%d", &k);
    while (k != -1) {
        s = (BiTree)malloc(sizeof(BitNode));
        s->data.key = k;
        s->lchild = NULL;
        s->rchild = NULL;
        t = insert(t, s);
        scanf_s("%d", &k);
    }
    return t;
}
void inorder(BiTree t) {
    if (t) {
        inorder(t->lchild);
        printf_s("%3d", t->data);
        inorder(t->rchild);
    }
}
void main() {
    BiTree t;
    printf_s("输入数据，以-1结束:");
    t = creat();
    printf_s("中序序列为:");
    inorder(t);
}