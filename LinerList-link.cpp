/*带头结点的单链表,尾插法创建带头节点单链表，按位查找，按值查找，前插，后插，删除*/

#include<stdio.h>
#include<stdlib.h>

char str[27] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };


//数据结构类型
 struct linklist{
	char data;
	linklist *next;//这里定义指针要用结构体上面的名字
};
 

//尾插法创建单链表
linklist* CreateR(linklist *L) {
	int i;
	linklist* head,*s,*p;
	head = NULL;
	L = (linklist*)malloc(sizeof(linklist));
	if (L == NULL) {
		printf("创建失败!\n");
	}
	else {
		head = L;//头结点指向第一个不存数据的节点;
		p = L;
		for (i = 0; i < 27; i++) {//将26个字母存入链表中
			s = (linklist*)malloc(sizeof(linklist));
			s->data = str[i];
			s->next = NULL;
			p->next = s;
			p = s;
		}
	}
	return head;
}

//按位查找,找到第x（1-n）个元素，返回它的位置
linklist* Get(linklist* head, int x) {
	linklist* p;
	int i=0;
	p = head;
	while (p->next!=NULL && i<x) {
		p = p->next;
		i++;
	}
	if (i == x) {
		return p;
	}
	else {
		return NULL;
	}
}

//按值查找,返回该位置节点指针
linklist* locate(linklist* L, char key) {
	linklist* p;
	p = L->next;
	while (p!=NULL && p->data!=key) {//两个条件前后顺序不可以调换
		p = p->next;
	}
	return p;//如果p为null，就是没找到
}

//在某个节点p前插入节点
bool InsertBefore(linklist* L, linklist* p, char key) {
	linklist* s,*k;
	k = (linklist*)malloc(sizeof(linklist));
	k->data = key;
	s = L;
	while (s->next != p) {//找到p的前驱节点
		s = s->next;
	}
	k->next = p;
	s->next = k;
	return true;
}

//改进版本在某个节点前插入节点,时间复杂度O(1)
bool InsertBefore_update(linklist* p, char key) {
	linklist* k;
	k = (linklist*)malloc(sizeof(linklist));
	k->data = p->data;
	p->data = key;
	k->next = p->next;
	p->next = k;
	return true;
}

//在某个节点后插入节点
bool InserBefore_after(linklist* p, char key) {
	linklist* s;
	s = (linklist*)malloc(sizeof(linklist));
	s->data = key;
	s->next = p->next;
	p->next = s;
	return true;
}

//删除第i个节点
char DeleteElement(linklist* L, linklist* s) {
	char key;
	linklist* p;
	p = L;
	key = s->data;
	while ( p->next != s) {
		p = p->next;
	}
	p->next = s->next;
	free(s); //一定要释放内存
	return key;
}


bool output(linklist* L) {
	linklist* p;
	p = L;
	printf("链表中的元素为：\n");
	while (p->next != NULL) {
		printf("%c ", p->next->data);
		p = p->next;
	}
	printf("\n");
	return true;
}

int main() {
	linklist* L=NULL;
	L=CreateR(L);
	output(L);

	linklist* q;
	q = Get(L, 26);
	printf("第26个元素是%c\n", q->data);

	q = locate(L, 'z');
	printf("要找z,找到了%c\n", q->data);

	InsertBefore(L, q, 'a');
	output(L);

	InsertBefore_update(q, 'b');
	output(L);

	DeleteElement(L, locate(L, 'w'));
	output(L);

}