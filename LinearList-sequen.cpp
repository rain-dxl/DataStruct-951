/*顺序存储结构线性表，建立、插入、按位删除、按值删除、定位*/
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1024

//基本数据结构
typedef struct {
	int data[MAXSIZE];
	int length;
}sequenlist;

//建立顺序表,给与1-100的初值
//为什么是sequenlist *Create,因为我们返回的应该是结构体指针，返回类型应该是sequenlist*
sequenlist *Create(sequenlist* L) {
	int i = 0;
	L = (sequenlist*)malloc(sizeof(sequenlist));//分配一个基本数据结构的内存，并将L指向其初始地址
	if (L == NULL) {//C6011警告，防止malloc内存不足
		printf("初始化失败！内存不足！\n");
	}
	else {
		L->length = 0;//初始化顺序表长度
		for (i = 1; i <= 100; i++) {//注意i是从1开始,而数组的下标是从0开始的
			L->data[i-1] = i;
			L->length++;
		}
	}
	return L;
}

//将新节点x超如顺序表L的第i个位置上，默认i为头(1)
bool insert(sequenlist* L, int x, int i = 1) {
	if (i > L->length + 1 || i < 1) {
		printf("插入位置错误\n");
		return false;
	}
	if (L->length >= MAXSIZE) {
		printf("表满！\n");
		return false;
	}
	int j = L->length ;//length表示长度（元素数量），j初始为最后一个可插入位置下标
	while (j!=i-1) {//搜索插入位置
		L->data[j] = L->data[j - 1];//元素后移操作
		j--;
	}
	L->data[j] = x;
	L->length++;
	return true;
}

//找到某个元素的位置并返回
int location(sequenlist* L, int x) {
	int j;
	for (j = 0; j < L->length; j++) {
		if (L->data[j] == x) {
			break;
		}
	}
	if (j == L->length) {
		printf("没有找到这个元素！\n");
		return L->length+1;
	}
	else {
		return j+1;
	}
}

//删除第i个元素（1~length）
int delete_location(sequenlist* L, int i) {
	if (i<1 || i>L->length) {
		printf("位置错误！\n");
		return false;
	}
	else {
		int j,b;
		b = L->data[i - 1];//用于保存删除的值
		for (j = i - 1; j < (L->length - 1); j++) {
			L->data[j] = L->data[j + 1];
		}
		L->length--;
		return b;
	}
}
	
//删除顺序表中的某个元素
bool delete_element(sequenlist* L, int x) {
	int j = 0;
	j = location(L, x);
	if (j == L->length+1 ) {
		return false;
	}
	else {
		delete_location(L, j);//删除第j个元素
	}
	return true;
}


//输出顺序存储的线性表的值
void output(sequenlist* L) {
	int i = 0;
	printf("线性表的元素为：\n");
	for (i = 0; i < L->length; i++) {
		printf("%d ", L->data[i]);//不能是'&L->data[i]',因为本身L->data[i]就是一个地址
	}
	printf("\n");
}

void main() {
	//‘sequenlist list;’ 这会直接消耗计算机内存创建一个数据结构
	sequenlist* L=NULL;
	L = Create(L);
	output(L);
	insert(L, 12, 2);//在第2个位置插入12
	output(L);
	delete_location(L, 2);//删除第2个位置元素
	output(L);
	delete_element(L, 100);//删除100
	output(L);
}