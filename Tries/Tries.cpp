#include<iostream>
#include<string>
using namespace std; 

class TrieNode{
    public: char data;
            TrieNode **children;
            bool isTerminal;

            TrieNode(char data)
            {
                this->data=data;
                children=new TrieNode*[26];
                for(int i=0;i<26;i++)
                {
                    children[i]=NULL;
                }
                isTerminal=false;
            }
};

class Trie{
    private: TrieNode *root;

    public: Trie()
           {
               root=new TrieNode('\0');
           }

           void insertWord(TrieNode *root,string word)
           {
               if(word.size()==0)
               {
                   root->isTerminal=true;
                   return;
               }

               int index= word[0]-'a';
               TrieNode *child;
               if(root->children[index]!=NULL)
               {
                   child=root->children[index];
               }
               else
               {
                   child=new TrieNode(word[0]);
                   root->children[index]=child;
               }
               insertWord(child,word.substr(1));
           }

           void insertWord(string word)
           {
               insertWord(root,word);
           }

           bool Search(TrieNode *root,string word)
           {
               if(word.size()==0)
               {
                   return root->isTerminal;
               }

               int index=word[0]-'a';

               if(root->children[index]!=NULL)
               {
                   return Search(root->children[index],word.substr(1));
               }
               else
               {
                   return false;
               }
           }

           bool search(string word)
           {
               return Search(root,word);
           }

           void remove(TrieNode *root,string word)
           {
               if(word.size()==0)
               {
                   root->isTerminal=false;
                   return;
               }

               int index=word[0]-'a';
               if(root->children[index]!=NULL)
               {
                   remove(root->children[index],word.substr(1));
               }
               else
               {
                   return;
               }

               if(root->children[index]->isTerminal==false)
               {
                   for(int i=0;i<26;i++)
                   {
                       if(root->children[index]->children[i]!=NULL)
                       {
                           return;
                       }
                   }
                 delete root->children[index];
                 root->children[index]=NULL;
               }
           }

           void remove(string word)
           {
               remove(root,word);
           }
};


int main()
{
    Trie t;
    t.insertWord("dot");
    t.insertWord("note");
    t.insertWord("not");
    t.insertWord("hello");

    cout<<t.search("hello")<<endl;
    t.remove("dot");
    cout<<t.search("dot")<<endl;
    return 0;
}