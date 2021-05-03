#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template <typename T>
class Node {
   public:
    T data;
    Node<T> *next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};


vector<Node<int>*> constructLL(BinaryTreeNode<int> *root)
{
   vector<Node<int>*> v;
   if(root==NULL)
   {
       v.push_back(NULL);
       return v;
   }

   queue<BinaryTreeNode<int> *> Q;
   Q.push(root);
   Q.push(NULL);
   Node<int> *head=NULL;
   Node<int> *tail=NULL;

   while(!Q.empty())
   {
       BinaryTreeNode<int> *front=Q.front();

       if(front!=NULL)
       {
           Node<int> *newNode=new Node<int>(front->data);
           if(head==NULL)
           {
               head=newNode;
               tail=newNode;
           }
           else
           {
               tail->next=newNode;
               tail=newNode;
           }

       }

       if(front==NULL && Q.size()==1)
       {
           Q.pop();
           v.push_back(head);
           head=NULL;
           tail=NULL;
           break;
       }
       if(front==NULL && Q.size()>1)
       {   
           Q.push(NULL);
           v.push_back(head);
           head=NULL;
           tail=NULL;
       }

       Q.pop();

       if(front->left!=NULL)
       {
           Q.push(front->left);
       }
       if(front->right!=NULL)
       {
           Q.push(front->right);
       }
   }
   return v;
}

int main()
{
  
}