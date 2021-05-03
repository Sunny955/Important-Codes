#include <bits/stdc++.h>
using namespace std;

// int x[4]={0,1,-1,0};
// int y[4]={-1,0,0,1};
// bool solve(int i,int j,vector<vector<char>>& board,vector<vector<int>>&vis,int k,string word,int m,int n)
// {
//         if(k==word.size())
//             return true;
//         if(i<0||j<0||i>=m||j>=n)
//             return false;
//         if(vis[i][j]||word[k]!=board[i][j])
//             return false;
//         vis[i][j]=1;
//         for(int r=0;r<4;r++)
//         {
//             if(solve(i+x[r],j+y[r],board,vis,k+1,word,m,n))
//                 return true; 
//         } 
//         vis[i][j]=0;
//        return false;
// }

// bool exist(vector<vector<char>>& board, string word) 
// {
//     int m=board.size();
//     int n=board[0].size();
//     vector<vector<int>>vis(m,vector<int>(n,0));
//     for(int i=0;i<board.size();i++)
//     {
//         for(int j=0;j<board[i].size();j++)
//         {
//             if(word[0]==board[i][j])
//             {
//                 int k=0;
//                 if(solve(i,j,board,vis,k,word,m,n))
//                     return true;
//             }
//         }
//     }
//     return false;
// }

bool helper(vector<vector<char>>& board,string word,bool **visited,int x,int y,int n,int m,int k)
    {    
        if(k==word.size() && x>=0 && y>=0 && x<n && y<m)
        {
            return true;
        }
        if(x<0 || y<0 || x>=n || y>=m)
        {
            return false;
        }
        
        visited[x][y]=true;
        
        if(x+1<n && y<m && board[x+1][y]==char(word[0]) && visited[x+1][y]==false)
        {
            return helper(board,word.substr(1),visited,x+1,y,n,m,k+1);   
        }
        if(x-1>=0 && y<m && board[x-1][y]==char(word[0]) && visited[x-1][y]==false)
        {
            return helper(board,word.substr(1),visited,x-1,y,n,m,k+1);
        }
        if(x>=0 && x<n && y+1<m && board[x][y+1]==char(word[0]) && visited[x][y+1]==false)
        {
            return helper(board,word.substr(1),visited,x,y+1,n,m,k+1);
        }
        if(x>=0 && x<n && y-1>=0 && board[x][y-1]==char(word[0]) && visited[x][y-1]==false)
        {
            return helper(board,word.substr(1),visited,x,y-1,n,m,k+1);
        }
        
        visited[x][y]=false;
        return false;
    }
    
bool exist(vector<vector<char>>& board, string word)
    {
        int n,m;
        n=board.size();
        m=board[0].size();
        
        bool **visited=new bool*[n];
        for(int i=0;i<n;i++)
        {
            visited[i]=new bool[m];
            for(int j=0;j<m;j++)
            {
                visited[i][j]=false;
            }
        }
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]==char(word[0]))
                {
                    int k=0;
                    if(helper(board,word,visited,i,j,n,m,k))
                    {
                        return true;
                    }  
                }
            }    
        }
        
        return false;
}

int main()
{
    vector<vector<char>> matrix;
    int n,m;
    char a;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        vector<char> input;
        for(int j=0;j<m;j++)
        {   cin>>a;
            input.push_back(a);
        }
        matrix.push_back(input);
        input.clear();
    }
    string word;
    cin>>word;
    bool ans=exist(matrix,word);
    cout<<ans<<endl;
}