#include <iostream>
#include <stdio.h>
using namespace std;

class node{
    public:
node* left;
node* right;
node* prev;
int value;
node() { left=NULL; right=NULL; prev=NULL;}

};

class bst{
public:
node* root;
bst() {root=NULL;}
node* root1() { return root;}


void insert(int);
void inorder(node*);
void del(node*);
node* search(int);
node* successor(node*);
node* pred(node*);



};

node* bst::search(int key)
{
    node* current=root;
    while(current->value!=key)
    {
        if(current->value>key) current=current->left;
        else current=current->right;


    }

    return current;





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

}

void bst::del(node* z)
{

  node * pre=z->prev;
   if(z->left==NULL&&z->right==NULL) {if(pre->left==z) pre->left=NULL;
   else pre->right=NULL;


     }

   else if(z->left==NULL) { if(pre->left==z) {pre->left=z->right;  pre->left->prev=pre;//cout<<z->prev->left->value<<" 2"<<endl;
   }
                      else {pre->right=z->right; pre->right->prev=pre; // cout<<z->prev->right->value<<" 2"<<endl;
                      }

                      }

   else if(z->right==NULL) { if(pre->left==z) {pre->left=z->left;  pre->left->prev=pre;}
                      else {pre->right=z->left;  pre->right->prev=pre;}

                       }

   else
   {
       node* pre1=pred(z);
       z->value=pre1->value;
       del(pre1);

   }





   }


node* bst::successor(node* a)
{
    if(a->right==NULL)
    {
        node* current=a;
        while(current->prev->left!=current&&current!=root)
        {
            current=current->prev;

        }

        if(current==root) return root;
        else return current->prev;

    }

else{

node* current=a->right;
while(current->left!=NULL)  {

current=current->left;
}

return current;
}




}

node* bst::pred(node* a)
{
    if(a->left==NULL)
    {
        node* current=a;
        while(current->prev->right!=current&&current!=root)
        {
            current=current->prev;

        }

        if(current==root) return root;
        else return current->prev;

    }

else{

node* current=a->left;
while(current->right!=NULL)  {

current=current->right;
}

return current;
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
 

}





