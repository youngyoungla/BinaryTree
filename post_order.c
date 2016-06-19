#include <iostream>
using namespace std;

//搜索二叉树： 左子树上的所有值小于根节点的值，右子树的值大于根节点的值
bool Is_postorder(int* a, ssize_t size)
{
	int root =a[size-1];
    int i=0;
	int _size=0;
	//左子树
	while(a[i]<root)
	{
		i++;
	}
    _size=i;
	//右子树
	for(;i<size-1;i++)
	{
		if(a[i]<root)
		{
			return false;
		}
	}
	if(_size>1)
	Is_postorder(a,_size);
	if(size-_size-1>1)
	Is_postorder(a+_size-1,size-_size-1);
    return true;	

}
void test()
{
	int a[]={7,4,6,5};
   cout<<Is_postorder(a,sizeof(a)/sizeof(a[0]))<<endl;
}
int main()
{
	test();
	return 0;
}
