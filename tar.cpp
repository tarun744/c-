#include <iostream>
#include <queue>
#include <stack>
#include <map>

using namespace std;


class node
{
public:
    int data;
    node* left,*right;
};

void levelorder(node* root)
{
    queue<node *>q;

    q.push(root);

    while(!q.empty())
    {
        node* temp = q.front();
        cout<<temp->data;
        q.pop();
        if(temp->right)
        {
            q.push(temp->right);
        }
        if(temp->left)
        {
            q.push(temp->left);
        }


    }

}
void inverse(node* root)
{
    stack<node *>s;
    queue<node *>q;

    q.push(root);

    while(!q.empty())
    {
        node* temp = q.front();
        s.push(temp);



        q.pop();
        if(temp->right)
        {
            q.push(temp->right);
        }
        if(temp->left)
        {
            q.push(temp->left);
        }


    }
    while(!s.empty())
    {
        root=s.top();
        cout<<root->data;
        s.pop();
    }


}

void dia(node* root,int d,map<int,vector<int>> &m)
{
    if(root==NULL)
    {
        return;
    }
    m[d].push_back(root->data);
    dia(root->left,d+1,m);
    dia(root->right,d,m);
}
void diagnol(node* root)
    {
        int d=0;
        map<int,vector<int>> m;
        dia(root,d,m);
         map<int,vector<int>> :: iterator it;
        for (it=m.begin(); it!=m.end(); it++)
        {
        for (int i=0; i<it->second.size(); ++i)
            cout << it->second[i] << " ";
        cout << endl;
        }
    }
void verticalorder(node* root,int hd,map<int,vector<int>> &m)
{
    if(root==NULL)
    {
        return;
    }

    m[hd].push_back(root->data);

    verticalorder(root->left,hd-1,m);
    verticalorder(root->right,hd+1,m);
}

void vertical(node* root)
{
    map<int,vector<int>> m;
    int hd=0;

    verticalorder(root,hd,m);

    map<int,vector<int>> :: iterator it;

    for (it=m.begin(); it!=m.end(); it++)
    {
        for (int i=0; i<it->second.size(); ++i)
            cout << it->second[i] << " ";
        cout << endl;
    }
}

void view(node* root,int hd,int l,map<int,pair<int,int>>& m)
{
    if(root==NULL)
        {
            return;
        }
    if(m.count(hd) == 0)
        {
            m[hd] = make_pair(root->data,l);
        }
        else
        if(m[hd].second>l)
        {
            m[hd] = make_pair(root->data,l);
        }
        view(root->left,hd-1,l+1,m) ;
        view(root->right,hd+1,l+1,m) ;
}

void topView(node * root)
{

        int hd=0;
        int l=0;
        map<int,pair<int,int>> m;
        view(root,hd,l,m);
        //map<int,vector<int>> :: iterator it;
     for (auto it = m.begin(); it != m.end(); it++)
        {
        cout << it->second.first << " ";
        }

}

int height(node* root)
{
    if(root==NULL)
    {
        return 0;
    }


    int l=height(root->left);
    int r=height(root->right);

    if(l>r)
    {
        return l+1;

    }
    else
        return r+1;
}


void splitaftertwo(node* root)
{
    stack<node* > s1;
    stack<node* > s2;

    if(root==NULL)
    {
        return;
    }
    s1.push(root);
    while(!s1.empty()||!s2.empty())
    {
        while(!s1.empty())
        {
            node* temp = s1.top();
            s1.pop();
            cout<<temp->data ;


             if(temp->right)
            {
                s2.push(temp->right);
            }

            if(temp->left)
            {
                s2.push(temp->left);
            }
           
        }
        while(!s2.empty())
        {
            node* temp= s2.top();
            s2.pop();
            cout<<temp->data;

            if(temp->left)
                {
                    s1.push(temp->left);
                }
            if(temp->right)
            {
                s1.push(temp->right);

            }
        }
    }  
}

// bool balancedtree(node* root,bool balan)
// {
//     if(root==NULL)
//     {
//         return 0;
//     }
    
//     int l=balancedtree(root->left,balan);
//     int r = balancedtree(root->right,balan);
    
//     if((l-r)==0)
//     {
//         balan = true;
//         cout<<balan;
//     }
//     if(l-r>1)
//         balan= false;
//         cout<<balan;

//     if(r>l)
//     {
//         return r+1;

//     }
//     else
//     if(l>r)
//     {
//         return l+1;
//     }
// }


int diameter(node* root)
{
    if(root==NULL)
    {
        return 0 ;
    }

    int l = height(root->left);
    int r = height(root->right);
    int s=l+r+1;

    int x=diameter(root->left);
    int y=diameter(root->right);
    int z=max(s,max(x,y));
    // int y=diameter(root->left);
    // int x=diameter(root->right);

    // int z=x+y;
    //cout<<max(z,s);
    return z;
}

void diagona(node* root)
{
    if(root==NULL)
    {
        return;
    }

    queue<node* > q;
    q.push(root);


    
    
    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();
        

        // if(temp==NULL)
        // {
        //     if (q.empty())
        //         return;
  
        //     // output nextline
        //     cout << endl;
  
        //     // push delimiter again
        //     q.push(NULL);
        // }
        cout<<"\n";
        while (temp!= NULL)
        {    
        cout<<temp->data<<" ";
        q.push(temp->left);
        temp=temp->right;            /* code */
        }
        

    }
}
int diam(node* root)
{
    if(root==NULL)
    {
        return height(root);
    }

    int l=diam(root->left);
    int r=diam(root->right);

    return l+r+1;




}
void ultapulta(node* root)
{
    if(root==NULL)
    {
        return ;
    }

    queue<node* >q;

    q.push(root);
    
    while(!q.empty())
    {
       node* temp = q.front();
    q.pop();
    cout<<temp->data<<"\n";
        if(temp->left)
        {
            cout<<temp->left->data<<" "<<temp->right->data;
        }

        q.push(temp->left);
        node* first = q.front();
        q.pop();
        q.push(temp->right);
        node* second = q.front();
        q.pop();

        cout << " " << first->left->data << " " << second->right->data;
        cout << " " << first->right->data << " " << second->left->data;
  

        if(temp->left->left)
        {
            
            q.push(first->left);
            q.push(second->left);
            q.push(first->right);
            q.push(second->left);
        }


    }


}






node* newNode(int data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return(Node);
}
int main()
{
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->left->right->right = newNode(5);
    root->left->right->right->right = newNode(6);
    int h=height(root);
    bool balan=true;
    //cout<<"level order traversal \n";
//levelorder(root);
    cout<<"Top view \n";
    //inverselevelorder(root);
    topView(root);
    cout<<"\n";
    cout<<"\n";
    cout<<"level order \n";
    levelorder(root);
    cout<<"\n";
    cout<<"\n";
    cout<<"vertical order \n";
    vertical(root);
    cout<<"\n";
    cout<<"\n";
    cout<<"ddd";
    cout<<"inverse lever order \n";
    inverse(root);
    cout<<"\n";
    cout<<"\n";
    cout<<"height \n";
    cout<<h;
    cout<<"\n";
    cout<<"\n";
    cout<<"dia \n";
    diagnol(root);
    cout<<"\n";  
    cout<<"\n";
    cout<<"split after 1 \n";
    splitaftertwo(root);
    cout<<"\n";
    cout<<"\n";
    cout<<"balanced heigvbnht \n";
    //balancedtree(root,true);
    cout<<"\n";
    cout<<"\n";
    cout<<"DIAMETER";
    int p=diameter(root);
    cout<<p;
    cout<<"\n";
    cout<<"\n";
    cout<<"DIAG PART2f";
    diagona(root);
    cout<<"\n \n";
    cout<<"diameter \n";
    int o=diam(root);
    cout<<o;
    cout<<"ultapulta";
    cout<<"\n \n";
    ultapulta(root);
    return 0;
}




















