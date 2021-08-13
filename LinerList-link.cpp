/*��ͷ���ĵ�����,β�巨������ͷ�ڵ㵥������λ���ң���ֵ���ң�ǰ�壬��壬ɾ��*/

#include<stdio.h>
#include<stdlib.h>

char str[27] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };


//���ݽṹ����
 struct linklist{
	char data;
	linklist *next;//���ﶨ��ָ��Ҫ�ýṹ�����������
};
 

//β�巨����������
linklist* CreateR(linklist *L) {
	int i;
	linklist* head,*s,*p;
	head = NULL;
	L = (linklist*)malloc(sizeof(linklist));
	if (L == NULL) {
		printf("����ʧ��!\n");
	}
	else {
		head = L;//ͷ���ָ���һ���������ݵĽڵ�;
		p = L;
		for (i = 0; i < 27; i++) {//��26����ĸ����������
			s = (linklist*)malloc(sizeof(linklist));
			s->data = str[i];
			s->next = NULL;
			p->next = s;
			p = s;
		}
	}
	return head;
}

//��λ����,�ҵ���x��1-n����Ԫ�أ���������λ��
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

//��ֵ����,���ظ�λ�ýڵ�ָ��
linklist* locate(linklist* L, char key) {
	linklist* p;
	p = L->next;
	while (p!=NULL && p->data!=key) {//��������ǰ��˳�򲻿��Ե���
		p = p->next;
	}
	return p;//���pΪnull������û�ҵ�
}

//��ĳ���ڵ�pǰ����ڵ�
bool InsertBefore(linklist* L, linklist* p, char key) {
	linklist* s,*k;
	k = (linklist*)malloc(sizeof(linklist));
	k->data = key;
	s = L;
	while (s->next != p) {//�ҵ�p��ǰ���ڵ�
		s = s->next;
	}
	k->next = p;
	s->next = k;
	return true;
}

//�Ľ��汾��ĳ���ڵ�ǰ����ڵ�,ʱ�临�Ӷ�O(1)
bool InsertBefore_update(linklist* p, char key) {
	linklist* k;
	k = (linklist*)malloc(sizeof(linklist));
	k->data = p->data;
	p->data = key;
	k->next = p->next;
	p->next = k;
	return true;
}

//��ĳ���ڵ�����ڵ�
bool InserBefore_after(linklist* p, char key) {
	linklist* s;
	s = (linklist*)malloc(sizeof(linklist));
	s->data = key;
	s->next = p->next;
	p->next = s;
	return true;
}

//ɾ����i���ڵ�
char DeleteElement(linklist* L, linklist* s) {
	char key;
	linklist* p;
	p = L;
	key = s->data;
	while ( p->next != s) {
		p = p->next;
	}
	p->next = s->next;
	free(s); //һ��Ҫ�ͷ��ڴ�
	return key;
}


bool output(linklist* L) {
	linklist* p;
	p = L;
	printf("�����е�Ԫ��Ϊ��\n");
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
	printf("��26��Ԫ����%c\n", q->data);

	q = locate(L, 'z');
	printf("Ҫ��z,�ҵ���%c\n", q->data);

	InsertBefore(L, q, 'a');
	output(L);

	InsertBefore_update(q, 'b');
	output(L);

	DeleteElement(L, locate(L, 'w'));
	output(L);

}