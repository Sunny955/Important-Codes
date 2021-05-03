#include<iostream>
using namespace std;

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
	

class BST {
    // Define the data members
    BinaryTreeNode<int> *root;
   public:
    BST() 
    { 
        // Implement the Constructor
        root=NULL;
    }

	/*----------------- Public Functions of BST -----------------*/
    private: BinaryTreeNode<int> *remove(int data,BinaryTreeNode<int>* node)
    		{
               	if(node==NULL)
               	{
                   return NULL;
               	}
            
                if(data>node->data)
                {
                    node->right=remove(data,node->right);
                }
                else if(data<node->data)
                {
                    node->left=remove(data,node->left);
                }
                else
                {
                    if(node->left==NULL && node->right==NULL)
                    {
                        delete node;
                        return NULL;
                    }
                    
                    if(node->left!=NULL && node->right==NULL)
                    {
                        BinaryTreeNode<int> *temp=node->left;
                        node->left=NULL;
                        delete node;
                        return temp;
                    }
                    
                    if(node->right!=NULL && node->left==NULL)
                    {
                     	BinaryTreeNode<int> *temp=node->right;
                        node->right=NULL;
                        delete node;
                        return temp;
                    }
                    
                    if(node->right!=NULL && node->left!=NULL)
                    {
                     	BinaryTreeNode<int> *temp=node->right;
                        while(temp->left!=NULL)
                        {
                            temp=temp->left;
                        }
                        int newData=temp->data;
                        node->data=newData;
                        node->right=remove(newData,node->right);
                        return node;
                    }
                }
             return node;
    		}
    
            void printTree(BinaryTreeNode<int> *node)
    		{
           		if(node==NULL)
          	 	{
               		return;
           		}
                
                cout<<node->data<<":";
           		
                if(node->left!=NULL)
           		{
               		cout<<"L:"<<node->left->data<<",";
           		}
           		if(node->right!=NULL)
           		{
               		cout<<"R:"<<node->right->data<<endl;
           		}
        
          		printTree(node->left);
          		printTree(node->right);
    		}
    
            BinaryTreeNode<int> *insert(int data,BinaryTreeNode<int> *node)
    		{
         		if(node==NULL)
                {
                    BinaryTreeNode<int> *newNode=new BinaryTreeNode<int>(data);
                    return newNode;
                } 
                
                if(data>node->data)
                {
                    node->right=insert(data,node->right);
                }
                else
                {
                    node->left=insert(data,node->left);
                }
                
         		return node;       
    		
            }
    
            bool search(int data,BinaryTreeNode<int> *node)
    		{
            	if(node==NULL)
            	{
                	return false;
            	}
            	if(node->data==data)
            	{
                	return true;
            	}
        
            	if(node->data>data)
            	{
                	return search(data,node->left);   
            	}
            
            	if(node->data<data)
            	{
                	return search(data,node->right);
            	}
    		}
    
    public:
    		void remove(int data)
            { 
       			// Implement the remove() function 
                this->root=remove(data,this->root);
         
    		}

    
            void print() 
            { 
                // Implement the print() function
                printTree(root);
            }

            void insert(int data) 
            { 
                // Implement the insert() function 
                this->root=insert(data,this->root);
            }


            bool search(int data)
            {
                // Implement the search() function 
                return search(data,root);
            }
};

int main() {
    BST *tree = new BST();
    int choice, input, q;
    cin >> q;
    while (q--) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cin >> input;
                tree->remove(input);
                break;
            case 3:
                cin >> input;
                cout << ((tree->search(input)) ? "true\n" : "false\n");
                break;
            default:
                tree->print();
                break;
        }
    }
}
