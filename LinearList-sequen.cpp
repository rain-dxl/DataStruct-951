/*˳��洢�ṹ���Ա����������롢��λɾ������ֵɾ������λ*/
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1024

//�������ݽṹ
typedef struct {
	int data[MAXSIZE];
	int length;
}sequenlist;

//����˳���,����1-100�ĳ�ֵ
//Ϊʲô��sequenlist *Create,��Ϊ���Ƿ��ص�Ӧ���ǽṹ��ָ�룬��������Ӧ����sequenlist*
sequenlist *Create(sequenlist* L) {
	int i = 0;
	L = (sequenlist*)malloc(sizeof(sequenlist));//����һ���������ݽṹ���ڴ棬����Lָ�����ʼ��ַ
	if (L == NULL) {//C6011���棬��ֹmalloc�ڴ治��
		printf("��ʼ��ʧ�ܣ��ڴ治�㣡\n");
	}
	else {
		L->length = 0;//��ʼ��˳�����
		for (i = 1; i <= 100; i++) {//ע��i�Ǵ�1��ʼ,��������±��Ǵ�0��ʼ��
			L->data[i-1] = i;
			L->length++;
		}
	}
	return L;
}

//���½ڵ�x����˳���L�ĵ�i��λ���ϣ�Ĭ��iΪͷ(1)
bool insert(sequenlist* L, int x, int i = 1) {
	if (i > L->length + 1 || i < 1) {
		printf("����λ�ô���\n");
		return false;
	}
	if (L->length >= MAXSIZE) {
		printf("������\n");
		return false;
	}
	int j = L->length ;//length��ʾ���ȣ�Ԫ����������j��ʼΪ���һ���ɲ���λ���±�
	while (j!=i-1) {//��������λ��
		L->data[j] = L->data[j - 1];//Ԫ�غ��Ʋ���
		j--;
	}
	L->data[j] = x;
	L->length++;
	return true;
}

//�ҵ�ĳ��Ԫ�ص�λ�ò�����
int location(sequenlist* L, int x) {
	int j;
	for (j = 0; j < L->length; j++) {
		if (L->data[j] == x) {
			break;
		}
	}
	if (j == L->length) {
		printf("û���ҵ����Ԫ�أ�\n");
		return L->length+1;
	}
	else {
		return j+1;
	}
}

//ɾ����i��Ԫ�أ�1~length��
int delete_location(sequenlist* L, int i) {
	if (i<1 || i>L->length) {
		printf("λ�ô���\n");
		return false;
	}
	else {
		int j,b;
		b = L->data[i - 1];//���ڱ���ɾ����ֵ
		for (j = i - 1; j < (L->length - 1); j++) {
			L->data[j] = L->data[j + 1];
		}
		L->length--;
		return b;
	}
}
	
//ɾ��˳����е�ĳ��Ԫ��
bool delete_element(sequenlist* L, int x) {
	int j = 0;
	j = location(L, x);
	if (j == L->length+1 ) {
		return false;
	}
	else {
		delete_location(L, j);//ɾ����j��Ԫ��
	}
	return true;
}


//���˳��洢�����Ա��ֵ
void output(sequenlist* L) {
	int i = 0;
	printf("���Ա��Ԫ��Ϊ��\n");
	for (i = 0; i < L->length; i++) {
		printf("%d ", L->data[i]);//������'&L->data[i]',��Ϊ����L->data[i]����һ����ַ
	}
	printf("\n");
}

void main() {
	//��sequenlist list;�� ���ֱ�����ļ�����ڴ洴��һ�����ݽṹ
	sequenlist* L=NULL;
	L = Create(L);
	output(L);
	insert(L, 12, 2);//�ڵ�2��λ�ò���12
	output(L);
	delete_location(L, 2);//ɾ����2��λ��Ԫ��
	output(L);
	delete_element(L, 100);//ɾ��100
	output(L);
}