//求二叉树树和为某一值的路径
#include "binarytree.h"
void test()
{
 // int a[]={1,2,3,'#','#',4,'#','#',6,7};
  //BinaryTree b1(a,sizeof(a)/sizeof(a[0]));
  //b1.path_add(7);
  
	int a[]={10,5,4,'#','#',7,'#','#',12};
	BinaryTree b1(a,sizeof(a)/sizeof(a[0]));
	b1.path_add(22);
}
int main()
{
	test();
	return 0;
}
