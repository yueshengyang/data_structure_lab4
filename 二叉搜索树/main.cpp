#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct celltype{
    int data;
    celltype *lchild,*rchild;
    int counts;
}* BST;
BST Search(int k,BST F)
{
    if(F==NULL)
        return NULL;
    else if(k==F->data)
        return F;
    else if(k<F->data)
        return (Search(k,F->lchild));
    else if(k>F->data)
        return (Search(k,F->rchild));
    return NULL;
}
void Insert(int R,BST &F)
{

    if(F==NULL){
        F=new celltype;
        F->data=R;
        F->lchild=NULL;
        F->rchild=NULL;
        F->counts=1;
    }
    else if(R==F->data){
        F->counts++;
    }
    else if(R<F->data)
        Insert(R,F->lchild);
    else if(R>F->data)
        Insert(R,F->rchild);
}
int delete_min(BST &F)
{
    int tmp;
    BST P;
    if(F->lchild==NULL){
        P=F;
        tmp=F->data;
        F=F->lchild;
        delete P;
        return tmp;
    }
    else
        return (delete_min(F->lchild));
}
void Delete(int k,BST &F)
{
    if(F!=NULL){
        if(k<F->data)
        Delete(k,F->lchild);
        else if(k>F->data)
        Delete(k,F->rchild);
        else{
            if(F->counts>1)
                F->counts--;
            else if(F->lchild==NULL)
                F=F->rchild;
            else if(F->rchild==NULL)
                F=F->lchild;
            else
                F->data=delete_min(F->rchild);
        }
    }

}
BST creat_BST()
{
    BST F=NULL;
    int key;
    cin>>key;
    while(key){
        Insert(key,F);
        cin>>key;
    }
    return F;
}
void menu()
{
    cout<<"请输入您选择的功能："<<endl;
    cout<<"1、建立二叉搜索树"<<endl;
    cout<<"2、删除节点"<<endl;
    cout<<"3、插入节点"<<endl;
    cout<<"4、搜索节点"<<endl;
    cout<<"0、结束运行"<<endl;
}
int main()
{
    BST F=NULL;
    int choose=1;
    while (choose){
    menu();
    cin>>choose;
    switch(choose)
    {
   case 1:
    cout<<"请输入您的搜索二叉树数据，输入0结束输入"<<endl;
    F=creat_BST();
    cout<<"二叉搜索树建立完成"<<endl;
    //system("pause");
    //system("cls");
    break;
   case 2:
    cout<<"请输入要删除节点的data值"<<endl;
    int k;
    cin>>k;
    Delete( k,F);
    cout<<"节点删除完毕"<<endl;
    //system("pause");
    //system("cls");
    break;
   case 3:
    cout<<"请输入要插入的节点data值"<<endl;
    cin>>k;
    Insert(k,F);
    cout<<"节点插入完毕"<<endl;
    //system("pause");
    //system("cls");
    break;
   case 4:
    cout<<"请输入要搜索的节点data值"<<endl;
    cin>>k;
    BST f;
    f=Search(k,F);
    if(f==NULL)
        cout<<"搜索二叉树中不存在此节点"<<endl;
    else
        cout<<"节点存在于搜索二叉树中其值为："<<f->data<<endl;
    //system("pause");
    //system("cls");
    break;
   case 0:
    exit(0);
    }
    }
    return 0;
}
