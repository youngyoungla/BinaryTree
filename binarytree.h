#pragma once
#include <iostream>
#include <queue>
using namespace std;

struct BinaryTreeNode
{
	BinaryTreeNode(int val)
	:_val(val)
	,_left(NULL)
	,_right(NULL)
	{}

	BinaryTreeNode* _left;
	BinaryTreeNode* _right;
	int _val;
};
class BinaryTree
{
	public:
		BinaryTree(int* a,int size)
		{
			int index=0;
			_root=_create(a,index,size);
		}
		void PreOrder()
		{
          _preorder(_root);
		}
	void floor_print()//层次遍历
	{
      _floor(_root);
	}
	void path_add(int expectedSum)
	{
		vector<int> path;
		int currentSum=0;
		_path_add(_root,path,currentSum,expectedSum);
	}
	private:
	   void _path_add(BinaryTreeNode* root,vector<int>& path,int& currentSum,int expectedSum)
	   {
		   if(root==NULL)
		   {
			   return;
		   }
		   currentSum+=root->_val;
		   path.push_back(root->_val);
		   //叶子节点
		   if(root->_left==NULL&&root->_right==NULL)
		   {
			   if(currentSum==expectedSum)
				 {
					 for(int i=0;i<path.size();i++)
					 {
						 cout<<path[i]<<"->";
					 }
					 cout<<endl;
				 }
				   currentSum-=root->_val;
				   path.pop_back();
			   	   return ;
			  
		   }

		   //非叶子节点
		   if(root->_left!=NULL)
		   {
			   _path_add(root->_left,path,currentSum,expectedSum);
		   }
		   if(root->_right!=NULL)
		   {
			   _path_add(root->_right,path,currentSum,expectedSum);
		   }

	   }
	   void _floor(BinaryTreeNode* root)
	   {
		   if(root==NULL)
		   {
			   return;
		   }
		 queue<BinaryTreeNode*> q1;
		 q1.push(root);
		 while(!q1.empty())
		 {
		   BinaryTreeNode* top=q1.front();
		   cout<<top->_val<<"->";
		   q1.pop();
		   BinaryTreeNode* left=top->_left;
		   BinaryTreeNode* right=top->_right;

		   if(left!=NULL)
		   {
		    //	   cout<<left->_val<<"->";
			   q1.push(left);
		   }
		   if(right!=NULL)
		   {
			//   cout<<right->_val<<"->";
			   q1.push(right);
		   }

		 }

	   }
		BinaryTreeNode* _create(int *a,int& index,int size)
		{
			BinaryTreeNode* root=NULL;
			if(a[index]!='#'&&index<size)
			{
               root=new BinaryTreeNode(a[index]);
			   root->_left=_create(a,++index,size);
			   root->_right=_create(a,++index,size);
			}
			return root;
		}
		void _preorder(BinaryTreeNode* root)
		{
			if(root==NULL)
			{
				return;
			}
			cout<<root->_val<<"->";
			_preorder(root->_left);
			_preorder(root->_right);
			
		}
	private:
		BinaryTreeNode* _root;
};
