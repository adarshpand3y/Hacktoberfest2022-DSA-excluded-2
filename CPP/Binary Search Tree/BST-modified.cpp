#include<iostream>
#include<queue>
using namespace std;

template <typename T>

class BinarySearchTree
{
	public:
		T data;
		BinarySearchTree* left;
		BinarySearchTree* right;
	BinarySearchTree(T data)
	{
		this->data=data;
		left=NULL;
		right=NULL;
	}
	~BinarySearchTree()
	{
		delete left;
		delete right;
	}
};
//----------------------------------------------------------------------
//input of binary tree

BinarySearchTree<int>* takeinputlevelwise()
{
	int rootdata;
	cout<<"enter rootdata: ";
	cin>>rootdata;
	if(rootdata==-1)
	{
	return NULL;
	}
	BinarySearchTree<int>* root=new BinarySearchTree<int>(rootdata);
	queue<BinarySearchTree<int>*> pn;
	pn.push(root);
	while(pn.size()!=0)
	{
		BinarySearchTree<int>*front=pn.front();
		pn.pop();
		int leftchild;
		cout<<"enter left child of "<<front->data;
		cin>>leftchild;
		if(leftchild!=-1)
		{
			BinarySearchTree<int>*child=new BinarySearchTree<int>(leftchild);
			front->left=child;
			pn.push(child);
		}
		int rightchild;
		cout<<"enter right child of "<<front->data<<": ";
		cin>>rightchild;
		if(rightchild!=-1)
		{
			BinarySearchTree<int>*child1=new  BinarySearchTree<int>(rightchild);
			front->right=child1;
			pn.push(child1);
		}
	}
	return root;
}
//---------------------------------------------------------------------
//searching element

	bool searchTree(BinarySearchTree<int>*root,int s_element)
{
	if(root==NULL)
	{
		return false;
	}
	if(root->data==s_element)
	{
		return true;
	}
	else
	{
		if(s_element>root->data)
		{
			searchTree(root->right,s_element);
		}
		else
		{
			searchTree(root->left,s_element);
		}
	}
	
}
//--------------------------------------------------------------

void printElementInRange(BinarySearchTree<int>*root,int k1,int k2)
{
	if(root==NULL)
	return;
	
	if(k1<=root->data && k2>=root->data)
	cout<<root->data<<" ";
	
	if(root->data>k1)
	{
		printElementInRange(root->left,k1,k2);
	}
	
	if(root->data<=k2)
	{
		printElementInRange(root->right,k1,k2);
	}
}

//-----------------------------------------------------------

//checkbalancetree
int getmax(BinarySearchTree<int>*root)
{
	if(root==NULL)
	return INT_MIN;
	
	return max(root->data,max(getmax(root->left),getmax(root->right)));
}
int getmin(BinarySearchTree<int>*root)
{
	if(root==NULL)
	return INT_MAX;
	
	return min(root->data,min(getmin(root->left),getmin(root->right)));
}


bool checkBalancedTree(BinarySearchTree<int>*root)
{
	if(root==NULL)
	return true;
	
	int maxnum=getmax(root->left);
	int minnum=getmin(root->right);
	
	if((maxnum<root->data) && (minnum>=root->data) && (checkBalancedTree(root->left))
	 && (checkBalancedTree(root->right)))
	{
		return true;
	}
}
//--------------------------------------------------------------------

//method 2 for checking BST

class isBSTcheck
{
	public:
		int minimum;
		int maximum;
		bool isBST;
};

isBSTcheck findBST(BinarySearchTree<int>*root)
{
	if(root==NULL)
	{
		isBSTcheck obj;
		obj.isBST=true;
		obj.maximum=INT_MIN;
		obj.minimum-INT_MAX;
		return obj;
	}
	
	isBSTcheck leftoutput=findBST(root->left);
	isBSTcheck rightoutput=findBST(root->right);
	
	int min1=min(root->data,min(leftoutput.minimum , rightoutput.minimum));
	int max1=max(root->data,max(leftoutput.maximum , rightoutput.maximum));
	
	bool returnvalue=(leftoutput.isBST) && (rightoutput.isBST)
	 && (root->data>leftoutput.maximum) && (root->data<=rightoutput.minimum);
	
	isBSTcheck obj;
	obj.isBST=returnvalue;
	obj.maximum=max1;
	obj.minimum=min1;
	
	return obj;
}

//-----------------------------------------------------------------------------

//methd 3: for checkBST

bool BST3 (BinarySearchTree<int>*root, int min=INT_MIN,int max=INT_MAX)
{
	if(root==NULL)
	{
		return true;
	}
	if(root->data<min || root->data>max)
	{
		return false;
		
	}
	bool leftside=BST3(root->left,min,root->data-1);
	bool rightside=BST3(root->right,root->data,max);
	
	return (leftside&&rightside);
}

	BinarySearchTree<int>* createBST(int arr[],int start,int end)
	{
		if(start >end)
		{
			return NULL;
		}
			int mid=(start+(end-1))/2;
			
			BinarySearchTree<int>*root=new BinarySearchTree<int>(arr[mid]);
			
			root->left=createBST(arr,start,mid-1);
			root->right=createBST(arr,mid+1,end);
			
			return root;			
		
		
		
	}


	 void Preordertraversal(BinarySearchTree<int>*root)
{
	if(root==NULL)
	return;
	cout<<"\n"<<root->data<<" ";
	Preordertraversal(root->left);
	Preordertraversal(root->right);
}









//12 6 14 3 7 13 16  -1 -1 -1 -1 -1 -1 -1 -1
//-------------------------------------------------------------
int main()
{
	BinarySearchTree<int>*root;
	root=takeinputlevelwise();
	findBST(root);

//method 2
	isBSTcheck obj=findBST(root);
	cout<<endl;
	cout<<"minimum element in BST is "<<obj.minimum<<endl;
	cout<<"maximum element in BST is "<<obj.maximum<<endl;
	cout<<"BST of given tree is "<<obj.isBST;
	
//method 3
/*	cout<<endl;
	cout<<"BST is "<<BST3(root);

	int arr[]={1,2,3,4,5,6,7};
	int start=0;
	int end=sizeof(arr)/sizeof(arr[0]);
	 BinarySearchTree<int>*root;
	 
	 root=createBST(arr,start,end-1);
	 Preordertraversal(root);
*/
/*	
	cout<<"tree is BST"<<check(root).isBST ;

	int elt;
	cout<<"enter element to be searched: ";
	cin>>elt;
	bool ans=searchTree(root,elt);
	if(ans==true)
	cout<<"\nelement found";
	else
	cout<<"\nelement not found";
	
	int k1,k2;
	cout<<"enter ranges: ";
	cin>>k1>>k2;
	printElementInRange(root,k1,k2);
	

if(checkBalancedTree(root))
cout<<"\nit is a bst";
else
cout<<"\nit is not a bst";	
	return 0;
	*/
}

