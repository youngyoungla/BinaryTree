#include "binarytree.h"
 // 二叉树从上到下遍历
void test()
{
	int a[]={1,2,3,'#',4,5,'#','#','#','#',6,7,'#',8,9};
	BinaryTree b1(a,sizeof(a)/sizeof(a[0]));
//	b1.PreOrder();
    b1.floor_print();
}
int main()
{
	test();
	return 0;
}

