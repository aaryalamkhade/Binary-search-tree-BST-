#include<iostream>
using namespace std;

class node          
{ public:
int data;
node*left,*right;	
};
node*root;
class tree
{
	public:
	tree()
	{
		root=NULL;
	}
	void insert();
	void search();
	void delete_node();
	void display(node*root);
};
void tree::insert()
{
	int data;
	cout<<"enter the data:";
	cin>>data;
	node*temp=new node;
	temp->left=temp->right=NULL;
	temp->data=data;
	if(root==NULL)      //for the 1 st ele to insert
	{
		root=temp;
	} 
	else 
	{ node*p=root;
	node*q;
		while(1) 
	{
		if(temp->data<=p->data)       //if the data is lesser than root
		{  q=p;
			p=p->left;
			if(p==NULL)   //go at leaf
			{
			   q->left=temp;
			   return;
			}
		}
		else                  //if data is greater
		{
			q=p;
			p=p->right;
			if(p==NULL)     //go at leaf
			{
				q->right=temp;      
				return;
			}
		}
	
	}
	}
	
}
void tree::search()
{
	int data;
	cout<<"enter no to search:";
	cin>>data;
	node*p=root;
	while(1)
	{   
	  if(p!=NULL)         //will search up to the leaf node
	  {
		if(data<=p->data)       //if search data is lesser than root
		{
		
			if(data==p->data)
			{
				cout<<"Value found:";
				return;
			}
				p=p->left;
		}
		else             //if search data is greater than root
		{
		
			if(data==p->data)
			{
				cout<<"Value found:";
				return;
			}
				p=p->right;
		}
	}
	else
	{
		cout<<"Not found:";
		return;
	}
	}
}
void tree::delete_node()
{
	int data;
	cout<<"Enter the value to delete:";
	cin>>data;
	node*p=root,*q;
	q=p;
	int flag=0;
	while(1)
	{  if(p!=NULL)
	{
		if(data==p->data)      //search the ele which we have to delete
		{   flag=1; 
		    break; 
		}
		else if(data<p->data)      //go tp the left subtree
		{   q=p;
			p=p->left;
		}
		else                    //go to the right subtree
		{   q=p;
			p=p->right;
		}
	}
	else                     //if number is not present
	{  flag=0; 
	 cout<<"Number is not in the tree:";
	  break;	
	}	
	}
	if(flag==1)               //if number is present
	{  if(p->left==NULL && p->right==NULL)   //if that node has 0 child
	{    
		if(q->left!=NULL && q->left->data==data)         //if that node is present on left of the root node
		{
			q->left=NULL;
			return;
		}
		else                                 //if that node has 1 child on right
		{
			q->right=NULL;
			return;
		}
	}
	else if(p->left==NULL && p->right!=NULL)        //if that node has 1 child on left
	{
		if(q->left!=NULL && q->left->data==data)       //if that node has 1 child on left of the root node
		{
			q->left=p->right;
			return;
		}
		else             //if that node has 1 child on right of the root node
		{
			q->right=p->right;
			return;
		}
	}
	else if(p->right==NULL && p->left!=NULL)           //if that node has 1 child on left
	{
	  if(q->left!=NULL && q->left->data==data)         //if that node has 1 child on left of the root node
	  { 
	  	q->left=p->left;
	  	return;
	  }
	  else                                           //if that node has 1 child on right of the root node
	  {
	  	q->right=p->left;
	  	return;
      }
	}
	else                            //if that node has 2 child 
	{
		node*a=p->left;node*b;      //a is the inorder predessor
		int flag=0;
		while(a->right!=NULL)      //find inorder predessor
		{
			flag=1;                
			b=a;
			a=a->right;
		}
		if(flag==0)            //if the roor node which we have to delte have 2 children and those are not a leaf nodes.     
		{  node*b=p;
			p->data=a->data;
			b->left=NULL;
		}
		else                    //if in that root node which we have to delete only have 2 children and those are the leaf nodes.
		{
			p->data=a->data;
			b->right=NULL;
		}
	}
    }
    
}
void tree::display(node*root)       //Inorder display
{
	if(root==NULL)
	return;
	display(root->left);
	cout<<root->data;
	display(root->right);
}
int main()
{
	tree t;
	for(int i=0;i<11;i++)         
	t.insert();
	t.display(root);
	//t.search();
	for(int i=0;i<2;i++)
	{t.delete_node();
	t.display(root);
    }
}
