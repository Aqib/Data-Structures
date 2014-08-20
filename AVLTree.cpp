#include <iostream>
#include <stdio.h>
using namespace std;

class node{
    public:

    int height;
node* left;
node* right;
node* prev;
int value;
node() {height=1; left=NULL; right=NULL; prev=NULL;}

};

int height1(node* a) {
    if(a==NULL) return 0;
    else return a->height;
    }

class bst{
public:
node* root;
bst() {root=NULL;}
node* root1() { return root;}


void insert(int);
void inorder(node*);
void bal(node*, node*, node*);
//void del(node*);
//node* search(int);
//node* successor(node*);
//node* pred(node*);



};

int getdiff(node* a)
{
    return height1(a->left)-height1(a->right);

}


void bst::insert(int a)
{
    if(root==NULL) {root=new node(); root->value=a; return;   }

    node* current=root;
    node* prev1=root;
    while(current!=NULL)
    { prev1=current;
        if(current->value>a) current=current->left;
        else current=current->right;

    }

   current=new node();

   current->value=a;
   current->prev=prev1;
   if(a<prev1->value) {prev1->left=current;}
   else {prev1->right=current;}
node* x,* y;
y=current;
x=y;
 while(current!=NULL)
 {
     current->height=max(height1(current->left),height1(current->right))+1;
     int d=getdiff(current);
    if(d<-1||d>1) {bal(current,y,x); break;}
    x=y;
    y=current;
    current=current->prev;
    // current->height=max(height1(current->left),height1(current->right))+1;


 }

while(root->prev!=NULL) {root=root->prev;}


}

void bst::bal(node* z,node *y, node* x)
{
//cout<<"bal "<<z->value<<" "<<y->value<<" "<<x->value<<"    ";
    if(z->left==y) {

    if(y->left==x)

    {
        z->left=y->right;
        y->right=z;
        y->prev=z->prev;
        z->prev=y;
        if(z->left!=NULL) z->left->prev=z;
        z->height=max(height1(z->left),height1(z->right))+1;
        y->height=max(height1(z),height1(x))+1;

  if(y->prev!=NULL) {if(y->prev->right==z) y->prev->right=y;
  else y->prev->left=y;
  }

    }

   else{

   y->right=x->left;
   z->left=x->right;
   x->left=y;
   x->right=z;
   x->prev=z->prev;
   if(y->right!=NULL) y->right->prev=y;
   if(z->left!=NULL) z->left->prev=z;
   y->prev=x;
   z->prev=x;

z->height=max(height1(z->left),height1(z->right))+1;
y->height=max(height1(y->left),height1(y->right))+1;
 x->height=max(height1(y),height1(z))+1;

   if(x->prev!=NULL) {if(x->prev->right==z) x->prev->right=x;
  else x->prev->left=x;

  }



   }


    }

else
{
  if(y->right==x){

  z->right=y->left;
        y->left=z;
        y->prev=z->prev;
        z->prev=y;
        if(z->right!=NULL) z->right->prev=z;
        z->height=max(height1(z->left),height1(z->right))+1;
        y->height=max(height1(z),height1(x))+1;

  if(y->prev!=NULL) {if(y->prev->right==z) y->prev->right=y;
  else y->prev->left=y;

  }

}

else {

 y->left=x->right;
   z->right=x->left;
   x->right=y;
   x->left=z;
   x->prev=z->prev;
   if(y->left!=NULL) y->left->prev=y;
   if(z->right!=NULL) z->right->prev=z;
   y->prev=x;
   z->prev=x;
z->height=max(height1(z->left),height1(z->right))+1;
y->height=max(height1(y->left),height1(y->right))+1;
 x->height=max(height1(y),height1(z))+1;

   if(x->prev!=NULL) {if(x->prev->right==z) x->prev->right=x;
  else x->prev->left=x; }




}





}

}



void bst::inorder(node* temp)
{
    if(temp==NULL) return;
   inorder(temp->left);
   printf("%d ",temp->value);
   inorder(temp->right);

}





int main()
{

    bst mytree;
    int n;
    int temp;
    scanf("%d",&n);
    for(int i=0;i<n;i++){ scanf("%d",&temp);  mytree.insert(temp); }

    mytree.inorder(mytree.root1());



}





