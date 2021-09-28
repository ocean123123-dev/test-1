#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Salesman               //��Ա��Ϣ
{
	char number[10];
	char name[10];
	char gender[4];
	char birthDate[14];
	char phone[15];
	char address[80];
	char employedDate[10];
	struct Salesman* next;
}Salesman;

typedef struct ProductInformation                     //��Ʒ��Ϣ
{
	char code[10];
	char name[10];
	int totalNumber;
	float unitPrice;
	char producer[10];
	char stockDate[12];
	struct ProductInformation* next;
}ProductInformation;

typedef struct MarketingInformation                  //������Ϣ
{
	char salesman[10];
	char customer[10];
	char customerPhone[15];
	char productName[20];
	char productCode[20];
	int amount;
	float unitPrice;
	char notes[30];
	char salesDate[12];
	struct MarketingInformation* next;
}MarketingInformation;

typedef  struct Producer              //��������Ϣ
{
	char code[10];
	char name[10];
	char phone[15];
	char address[50];
	struct Producer* next;
}Producer;


typedef  struct Customer
{
	char code[10];
	char name[10];
	char phone[15];
	char address[50];
	struct Customer* next;
}Customer;


/*��Ա����������*/
void AddSalesman();
void InputMan(FILE* fp, Salesman* head);
void ReadMan(FILE* fp, Salesman* head);
Salesman* FindMan(Salesman* head, char* name);
void CheckMan();
void SearchMan(Salesman* head);
void InputAgain(FILE* fp, Salesman* head);
void AlterMan();
void ChangeMan(Salesman* head);
void DeleteMan();
Salesman* CancelMan(Salesman* head);

/*��Ʒ����������*/
void AddProduct();
void AddProductInformation();
void AddMarketingInformation();
void InputProductInformation(FILE* fp, ProductInformation* head);
void InputMarketingInformation(FILE* fp, MarketingInformation* primal);
void ReadProductInformation(FILE* fp, ProductInformation* head);
void ReadMarketingInformation(FILE* fp, MarketingInformation* primal);
void CheckProduct();
ProductInformation* FindProductInformation(ProductInformation* head, char* name);
MarketingInformation* FindMarketingInformation(MarketingInformation* primal, char* name);
void SearchProduct(ProductInformation* head, MarketingInformation* primal);
void AlterProduct();
void ChangeProductInformation(FILE* fp, ProductInformation* head);
void ChangeMarketingInformation(FILE* fp, MarketingInformation* primal);
void DeleteProduct();
ProductInformation* CancelProductInformation(ProductInformation* head);

/*�����̹���������*/
void AddProducer();
void InputProducer(FILE* fp, Producer* head);
void ReadProducer(FILE* fp, Producer* head);
Producer* FindProducer(Producer* head, char* name);
void CheckProducer();
void SearchProducer(Producer* head);
void InputAgain(FILE* fp, Producer* head);
void AlterProducer();
void ChangeProducer(Producer* head);
void DeleteProducer();
Producer* CancelProducer(Producer* head);
ProductInformation* CancelProductInformation(ProductInformation* head, char* name);
MarketingInformation* CancelMarketingInformation(MarketingInformation* primal, char* name);

/*�˿͹���������*/
void AddCustomer();
void InputCustomer(FILE* fp, Customer* head);
void ReadCustomer(FILE* fp, Customer* head);
Customer* FindCustomer(Customer* head, char* name);
void CheckCustomer();
void SearchCustomer(Customer* head);
void InputAgain(FILE* fp, Customer* head);
void AlterCustomer();
void ChangeCustomer(Customer* head);
void DeleteCustomer();
Customer* CancelCustomer(Customer* head);


/*����*/
void form()
{
	printf("\t\t   ������������������������������������������������������������\n");
	printf("\t\t   �� 1. �����Ϣ    2. ��Ϣ��ѯ ��\n");
	printf("\t\t   ��                            ��\n");
	printf("\t\t   �� 3. �޸���Ϣ    4. ɾ����Ϣ ��\n");
	printf("\t\t   ��                            ��\n");
	printf("\t\t   �� 0. �����ϼ�                ��\n");
	printf("\t\t   ������������������������������������������������������������\n");
	printf("\t\t����ѡ��(0-4):");
}

int mainSelect()
{
	int n;
	system("cls"); /*����*/
	printf("\t\t ====================================\n");
	printf("\t\t��         ������Ϣ����ϵͳ          ��\n");
	printf("\t\t ====================================\n");
	printf("\t\t  ����������������������������������������������������������������\n");
	printf("\t\t  �� 1. ��Ա����     2. ��Ʒ����  ��\n");
	printf("\t\t  ��                              ��\n");
	printf("\t\t  �� 3. �����̹���   4. �˿͹���  ��\n");
	printf("\t\t  ����������������������������������������������������������������\n");
	printf("\t\t����ѡ��(1-4):");
	scanf("%d", &n);
	return n;
}

int manManage()
{
	int n;
	system("cls"); /*����*/
	printf("\t\t ====================================\n");
	printf("\t\t��             ��Ա����              ��\n");
	printf("\t\t ====================================\n");
	form();
	scanf("%d", &n);
	return n;
}

int productManage()
{
	int n;
	system("cls"); /*����*/
	printf("\t\t ====================================\n");
	printf("\t\t��             ��Ʒ����              ��\n");
	printf("\t\t ====================================\n");
	form();
	scanf("%d", &n);
	return n;
}

int sellerManage()
{
	int n;
	system("cls"); /*����*/
	printf("\t\t ====================================\n");
	printf("\t\t��             �����̹���            ��\n");
	printf("\t\t ====================================\n");
	form();
	scanf("%d", &n);
	return n;
}

int customerManage()
{
	int n;
	system("cls"); /*����*/
	printf("\t\t ====================================\n");
	printf("\t\t��             �˿͹���              ��\n");
	printf("\t\t ====================================\n");
	form();
	scanf("%d", &n);
	return n;
}


//������

int main()
{
	for (;;)
	{
		switch (mainSelect())
		{
		case 1:
			switch (manManage())
			{
			case 1:
				AddSalesman();
				continue;
			case 2:
				CheckMan();
				continue;
			case 3:
				AlterMan();
				continue;
			case 4:
				DeleteMan();
				continue;
			case 0:
				break;
			}
			break;
		case 2:
			switch (productManage())
			{
			case 1:
				AddProduct();
				continue;
			case 2:
				CheckProduct();
				continue;
			case 3:
				AlterProduct();
				continue;
			case 4:
				DeleteProduct();
				continue;
			case 0:
				break;
			}
			break;
		case 3:
			switch (sellerManage())
			{
			case 1:
				AddProducer();
				continue;
			case 2:
				CheckProducer();
				continue;
			case 3:
				AlterProducer();
				continue;
			case 4:
				DeleteProducer();
				continue;
			case 0:
				break;
			}
			break;
		case 4:
			switch (customerManage())
			{
			case 1:
				AddCustomer();
				continue;
			case 2:
				CheckCustomer();
				continue;
			case 3:
				AlterCustomer();
				continue;
			case 4:
				DeleteCustomer();
				continue;
			case 0:
				break;
			}
			break;
		}
	}
	return 0;
}

/*����ʵ��*/

void AddSalesman()
{
	system("cls");
	FILE* fp;
	fp = fopen("d:\\Salesman.txt", "a+");
	int n;
	Salesman* head = NULL;
	do {
		InputMan(fp, head);
		printf("�Ƿ������ӣ���1����0����\n");
		scanf("%d", &n);
	} while (n == 1);
	fclose(fp);
}

void InputMan(FILE* fp, Salesman* head)
{
	Salesman* pnew, * ptail;
	ptail = head;
	pnew = (Salesman*)malloc(sizeof(Salesman));
	printf("����	����	�Ա�	��ϵ�绰	��ϵ��ַ	����������	��ְʱ��");
	printf("���������ʽxxxx-xx-xx\n");
	scanf("%s%s%s%s%s%s%s", pnew->number, pnew->name,
		pnew->gender, pnew->phone, pnew->address,
		pnew->birthDate, pnew->employedDate);
	fprintf(fp, "%-8s %-8s%-8s%-15s\t%-16s%-16s%s\n", pnew->number, pnew->name,
		pnew->gender, pnew->phone, pnew->address,
		pnew->birthDate, pnew->employedDate);
	fflush(fp);
	pnew->next = NULL;
	ptail = pnew;
}

void ReadMan(FILE* fp, Salesman* head)
{
	Salesman* p, * q;

	q = head;

	while (!feof(fp))
	{
		p = (Salesman*)malloc(sizeof(Salesman));
		fscanf(fp, "%10s%10s%4s%15s%80s%14s%10s", p->number, p->name, p->gender,
			p->phone, p->address, p->birthDate, p->employedDate);
		q->next = p;
		q = p;
	}
	q->next = NULL;
}

Salesman* FindMan(Salesman* head, char* number)
{
	while (head != NULL)
	{
		if (strcmp(number, head->number) == 0)
		{
			return head;
		}
		head = head->next;
	}
	return NULL;
}


void CheckMan()
{
	system("cls");
	FILE* fp;
	fp = fopen("d:\\Salesman.txt", "r");
	Salesman* head;
	head = (Salesman*)malloc(sizeof(Salesman));
	ReadMan(fp, head);
	int n;
	do {
		SearchMan(head);
		printf("�Ƿ������ѯ����1����0����\n");
		scanf("%d", &n);
	} while (n == 1);
	fclose(fp);
}

void SearchMan(Salesman* head)
{
	char number[10];
	Salesman* p;

	printf("��������Ҫ��ѯ������Ա����\n");
	scanf("%s", number);
	p = FindMan(head, number);

	if (p == NULL)
	{
		printf("û�и�����Ա\n");
		return;
	}
	else
	{
		printf("����\t����\t�Ա�\t��ϵ�绰\t��ϵ��ַ\t����������\t��ְʱ��\n");
		printf("%-8s%-8s%-8s%-15s\t%-16s%-16s%s\n", p->number, p->name, p->gender, p->phone, p->address,
			p->birthDate, p->employedDate);
	}
}


void InputAgain(FILE* fp, Salesman* head)
{
	head = head->next;
	while (head->next != NULL)
	{
		fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\n", head->number, head->name,
			head->gender, head->phone, head->address,
			head->birthDate, head->employedDate);
		head = head->next;
	}
}

void AlterMan()
{
	system("cls");
	FILE* fp;
	fp = fopen("d:\\Salesman.txt", "r");
	Salesman* head;
	head = (Salesman*)malloc(sizeof(Salesman));
	int n;
	ReadMan(fp, head);
	fclose(fp);
	do {
		fp = fopen("d:\\Salesman.txt", "w+");
		ChangeMan(head);
		printf("�Ƿ�����޸ģ���1����0����\n");
		scanf("%d", &n);
		fclose(fp);
	} while (n == 1);

	fp = fopen("d:\\Salesman.txt", "w+");
	InputAgain(fp, head);
	fclose(fp);
}

void ChangeMan(Salesman* head)
{
	char content[10], number[10];
	int type;
	Salesman* p;

	printf("��������Ҫ�޸ĵ���Ա�Ĵ���\n");
	scanf("%s", number);
	p = FindMan(head, number);

	if (p == NULL)
	{
		printf("û�и�����Ա\n");
		return;
	}

	printf("��ѡ����Ҫ�޸���Ϣ�����:\n");
	printf("(1.����\t2.����\t3.�Ա�\t4.��ϵ�绰\t5.��ϵ��ַ\t6.����������\t7.��ְʱ��)\n");
	scanf("%d", &type);

	printf("�������µ�����:\n");
	scanf("%s", content);

	switch (type)
	{
	case 1:
		strcpy(p->number, content);
		break;
	case 2:
		strcpy(p->name, content);
		break;
	case 3:
		strcpy(p->gender, content);
		break;
	case 4:
		strcpy(p->phone, content);
		break;
	case 5:
		strcpy(p->address, content);
		break;
	case 6:
		strcpy(p->birthDate, content);
		break;
	case 7:
		strcpy(p->employedDate, content);
		break;
	}
}


void DeleteMan()
{
	system("cls");
	FILE* fp;
	system("cls");
	fp = fopen("d:\\Salesman.txt", "r");
	Salesman* head;
	head = (Salesman*)malloc(sizeof(Salesman));
	int n;
	ReadMan(fp, head);
	fclose(fp);
	do {
		CancelMan(head);
		printf("�Ƿ����ɾ������1����0����\n");
		scanf("%d", &n);
	} while (n == 1);
	fp = fopen("d:\\Salesman.txt", "w+");
	InputAgain(fp, head);
	fclose(fp);
}

Salesman* CancelMan(Salesman* head)
{

	char number[10];
	Salesman* p, * pold;

	printf("��������Ҫɾ��������Ա����\n");
	scanf("%s", number);

	p = head;
	while (head != NULL && strcmp(number, p->number) == 0)
	{
		head = head->next;
		free(p);
		p = head;
	}
	if (head == NULL)
	{
		return head;
	}
	p = head->next;
	pold = head;
	while (p != NULL)
	{
		if (strcmp(number, p->number) == 0)
		{
			pold->next = p->next;
			free(p);
			p = pold->next;
		}
		else
		{
			pold = p;
			p = p->next;
		}
	}
	return head;
}



void AddProduct()
{
	system("cls");
	int type;
	printf("��ѡ����Ҫ��ӵ����͡���1.��Ʒ������Ϣ��2.��Ʒ������Ϣ\n");
	scanf("%d", &type);
	if (type == 1)
	{
		AddProductInformation();
	}
	else if (type == 2)
	{
		AddMarketingInformation();
	}
}

void AddProductInformation()
{
	FILE* fp;
	fp = fopen("d:\\ProductInformation.txt", "a+");
	ProductInformation* head = NULL;
	int n;
	do {
		InputProductInformation(fp, head);
		printf("�Ƿ������ӣ���1����0����\n");
		scanf("%d", &n);
	} while (n == 1);
	fclose(fp);
}

void AddMarketingInformation()
{
	FILE* fp;
	fp = fopen("d:\\MarketingInformation.txt", "a+");
	MarketingInformation* primal = NULL;
	//int n = 1;
	int n;
	do {
		InputMarketingInformation(fp, primal);
		printf("�Ƿ������ӣ���1����0����\n");
		scanf("%d", &n);
	} while (n == 1);
	fclose(fp);
}

void InputProductInformation(FILE* fp, ProductInformation* head)
{
	ProductInformation* pnew, * ptail;
	ptail = head;
	pnew = (ProductInformation*)malloc(sizeof(ProductInformation));
	printf("����\t����\t����\t����\t����\t���ʱ��(�磺xxxx-xx-xx)\n");
	scanf("%s\t%s\t%d\t%f\t%s\t%s", pnew->code, pnew->name, &pnew->totalNumber,
		&pnew->unitPrice, pnew->producer, pnew->stockDate);
	fprintf(fp, "%-8s %-8s %-8d %-8.2f %-8s %s\n", pnew->code, pnew->name,
		pnew->totalNumber, pnew->unitPrice, pnew->producer, pnew->stockDate);
	fflush(fp);
	pnew->next = NULL;
	ptail = pnew;
}

void InputMarketingInformation(FILE* fp, MarketingInformation* primal)
{
	MarketingInformation* pnew, * ptail;
	ptail = primal;
	pnew = (MarketingInformation*)malloc(sizeof(MarketingInformation));
	printf("����Ա\t�˿�\t�˿���ϵ��ʽ\t��Ʒ����\t��Ʒ����\t��������\t�ۼ�\t˵��\t����ʱ��(�磺xxxx-xx-xx)\n");
	scanf("%s%s%s%s%s%d%f%s%s", pnew->salesman, pnew->customer, pnew->customerPhone, pnew->productName,
		pnew->productCode, &pnew->amount, &pnew->unitPrice, pnew->notes, pnew->salesDate);
	fprintf(fp, "%-8s%-8s%-16s%-16s%-16s%-8d\t%-8.2f%-8s%s\n", pnew->salesman, pnew->customer,
		pnew->customerPhone, pnew->productName, pnew->productCode, pnew->amount,
		pnew->unitPrice, pnew->notes, pnew->salesDate);
	fflush(fp);
	pnew->next = NULL;
	ptail = pnew;
}

void ReadProductInformation(FILE* fp, ProductInformation* head)
{
	ProductInformation* p, * q;

	q = head;

	while (!feof(fp))
	{
		p = (ProductInformation*)malloc(sizeof(ProductInformation));
		fscanf(fp, "%10s%10s%d%f%10s%12s", p->code, p->name, &p->totalNumber, &p->unitPrice,
			p->producer, p->stockDate);
		if (!feof(fp))
		{
			q->next = p;
			q = p;
		}
	}
	q->next = NULL;
}

void ReadMarketingInformation(FILE* fp, MarketingInformation* primal)
{
	MarketingInformation* p, * q;

	q = primal;

	while (!feof(fp))
	{
		p = (MarketingInformation*)malloc(sizeof(MarketingInformation));
		/*fscanf(fp, "%10s%10s%15s%20s%20s%d%f%30s%12%", p->salesman, p->customer,
			p->customerPhone, p->productName, p->productCode, &p->amount,
			&p->unitPrice, p->notes, p->salesDate);*/
		fscanf(fp, "%10s%10s%15s%20s%20s%d%f%30s%12s", p->salesman, p->customer,
			p->customerPhone, p->productName, p->productCode, &p->amount,
			&p->unitPrice, p->notes, p->salesDate);
		if (!feof(fp))
		{
			q->next = p;
			q = p;
		}
	}
	q->next = NULL;
}

void CheckProduct()
{
	system("cls");
	FILE* fp, * fp2;
	fp = fopen("d:\\ProductInformation.txt", "r");
	fp2 = fopen("d:\\MarketingInformation.txt", "r");
	ProductInformation* head;
	MarketingInformation* primal;
	head = (ProductInformation*)malloc(sizeof(ProductInformation));
	primal = (MarketingInformation*)malloc(sizeof(MarketingInformation));
	ReadProductInformation(fp, head);
	ReadMarketingInformation(fp2, primal);
	int n;
	do {
		SearchProduct(head, primal);
		printf("�Ƿ������ѯ����1����0����\n");
		scanf("%d", &n);
	} while (n == 1);
	fclose(fp);
	fclose(fp2);
}

ProductInformation* FindProductInformation(ProductInformation* head, char* name)
{
	while (head != NULL)
	{
		if (strcmp(name, head->code) == 0)
		{
			return head;
		}
		head = head->next;
	}
	return NULL;
}

MarketingInformation* FindMarketingInformation(MarketingInformation* primal, char* name)
{
	while (primal != NULL)
	{
		if (strcmp(name, primal->productCode) == 0)
		{
			return primal;
		}
		primal = primal->next;
	}
	return NULL;
}

void SearchProduct(ProductInformation* head, MarketingInformation* primal)
{
	char productCode[20];
	ProductInformation* p;
	MarketingInformation* q;

	printf("��������Ҫ��ѯ�Ĳ�Ʒ����\n");
	scanf("%s", productCode);
	p = FindProductInformation(head, productCode);

	if (p == NULL)
	{
		printf("û�иò�Ʒ\n");
	}
	else
	{
		printf("����\t����\t����\t����\t����\t���ʱ��\n");
		printf("%-8s%-8s%-8d%-8.2f%-8s%s\n", p->code, p->name, p->totalNumber,
			p->unitPrice, p->producer, p->stockDate);
	}
	q = FindMarketingInformation(primal, productCode);
	/*printf("����ʱ��\t��������\t�ۼ�\t����Ա\t�˿�\t�˿���ϵ��ʽ\t˵��\n");
	printf("%s\t%s\t%s\t%s\t%s\t%d\t%f\t%s\t%s\n", q->salesDate, q->amount, q->unitPrice,
		q->salesman, q->customer, q->customerPhone, q->notes);*/
	if (q != NULL)
	{
		printf("����Ա\t�˿�\t�˿͵绰\t��Ʒ����\t��Ʒ���\t��������\t�ۼ�\t˵��\t����ʱ��\n");
		printf("%-8s%-8s%-16s%-16s%-16s%-8d\t%-8.2f%-8s%s\n", q->salesman, q->customer, q->customerPhone,
			q->productName, q->productCode, q->amount, q->unitPrice, q->notes, q->salesDate);
	}
	else
	{
		printf("û�д˲�Ʒ��������Ϣ\n");
	}
	//primal = primal->next;
}

void InputAgain(FILE* fp, ProductInformation* head)
{
	head = head->next;
	while (head != NULL)
	{
		fprintf(fp, "%s\t%s\t%d\t%f\t%s\t%s\n", head->code, head->name,
			head->totalNumber, head->unitPrice, head->producer, head->stockDate);
		head = head->next;
	}
}

void InputAgain(FILE* fp, MarketingInformation* primal)
{
	primal = primal->next;
	while (primal != NULL)
	{
		fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%d\t%f\t%s\t%s\n", primal->salesman, primal->customer,
			primal->customerPhone, primal->productName, primal->productCode, primal->amount,
			primal->unitPrice, primal->notes, primal->salesDate);
		primal = primal->next;
	}
}

void AlterProduct()
{
	system("cls");
	FILE* fp;
	FILE* fp2;
	fp = fopen("d:\\ProductInformation.txt", "r");
	fp2 = fopen("d:\\MarketingInformation.txt", "r");
	ProductInformation* head;
	MarketingInformation* primal;
	head = (ProductInformation*)malloc(sizeof(ProductInformation));
	primal = (MarketingInformation*)malloc(sizeof(MarketingInformation));
	ReadProductInformation(fp, head);
	ReadMarketingInformation(fp2, primal);
	//fclose(fp);
	//int n = 1;
	int n;
	do {
		printf("1���޸Ĳ�Ʒ������Ϣ��2���޸Ĳ�Ʒ������Ϣ\n");
		scanf("%d", &n);

		if (n == 1)
		{
			ChangeProductInformation(fp, head);
		}
		else if (n == 2)
		{
			ChangeMarketingInformation(fp2, primal);
		}
		else
		{
			printf("�������");
		}

		printf("�Ƿ�����޸ģ���1����0����\n");
		scanf("%d", &n);
	} while (n == 1);
	fp = fopen("d:\\ProductInformation.txt", "w+");
	fp2 = fopen("d:\\MarketingInformation.txt", "w+");
	InputAgain(fp, head);
	InputAgain(fp2, primal);
	fclose(fp);
	fclose(fp2);
}



void ChangeProductInformation(FILE* fp, ProductInformation* head)
{
	char content[10], code[10];
	int type;
	ProductInformation* p;

	printf("��������Ҫ�޸ĵĲ�Ʒ����\n");
	scanf("%s", code);

	p = FindProductInformation(head, code);
	if (p == NULL)
	{
		printf("û�иò�Ʒ\n");
		return;
	}

	printf("��ѡ����Ҫ�޸���Ϣ�����:\n");
	printf("(1.����\t2.����\t3.����\t4.����\t5.����\t6.���ʱ��(�磺xxxx-xx-xx))\n");
	scanf("%d", &type);

	printf("�������µ�����:\n");
	scanf("%s", content);

	switch (type)
	{
	case 1:
		strcpy(p->code, content);
		break;
	case 2:
		strcpy(p->name, content);
		break;
	case 3:
		p->totalNumber = atoi(content);
		break;
	case 4:
		p->unitPrice = atof(content);
		break;
	case 5:
		strcpy(p->producer, content);
		break;
	case 6:
		strcpy(p->stockDate, content);
		break;
	}
}


void ChangeMarketingInformation(FILE* fp, MarketingInformation* primal)
{
	char content[30], productCode[20];
	int type;
	MarketingInformation* p;

	printf("��������Ҫ�޸ĵĲ�Ʒ����\n");
	scanf("%s", &productCode);

	p = FindMarketingInformation(primal, productCode);
	if (p == NULL)
	{
		printf("û�иò�Ʒ\n");
		return;
	}

	printf("��ѡ����Ҫ�޸���Ϣ�����:\n");
	printf("(1������Ա��2���˿ͣ�3���˿͵绰��4����Ʒ���ƣ�5����Ʒ��ţ�6������������7���ۼۣ�8��˵����9������ʱ�䣩\n");
	scanf("%d", &type);

	printf("�������µ�����:\n");
	scanf("%s", content);

	switch (type)
	{
	case 1:
		strcpy(p->salesman, content);
		break;
	case 2:
		strcpy(p->customer, content);
		break;
	case 3:
		strcpy(p->customerPhone, content);
		break;
	case 4:
		strcpy(p->productName, content);
		break;
	case 5:
		strcpy(p->productCode, content);
		break;
	case 6:
		p->amount = atoi(content);
		break;
	case 7:
		p->unitPrice = atof(content);
		break;
	case 8:
		strcpy(p->notes, content);
		break;
	case 9:
		strcpy(p->salesDate, content);
		break;
	}
}

void DeleteProduct()
{
	system("cls");
	FILE* fp;
	FILE* fp2;
	fp = fopen("d:\\ProductInformation.txt", "r");
	fp2 = fopen("d:\\MarketingInformation.txt", "r");
	ProductInformation* head;
	MarketingInformation* primal;
	head = (ProductInformation*)malloc(sizeof(ProductInformation));
	primal = (MarketingInformation*)malloc(sizeof(MarketingInformation));
	int n;
	char productCode[20];
	ReadProductInformation(fp, head);
	ReadMarketingInformation(fp2, primal);
	fclose(fp);
	fclose(fp2);
	do {
		printf("��������Ҫɾ���Ĳ�Ʒ����\n");
		scanf("%s", productCode);
		CancelProductInformation(head, productCode);
		CancelMarketingInformation(primal, productCode);
		printf("�Ƿ����ɾ������1����0����\n");
		scanf("%d", &n);
	} while (n == 1);

	fp = fopen("d:\\ProductInformation.txt", "w+");
	fp2 = fopen("d:\\MarketingInformation.txt", "w+");
	InputAgain(fp, head);
	InputAgain(fp2, primal);
	fclose(fp);
	fclose(fp2);
}

ProductInformation* CancelProductInformation(ProductInformation* head, char* code)
{

	//char name[10];
	ProductInformation* p, * pold;

	//printf("��������Ҫɾ���Ĳ�Ʒ����\n");
	//scanf("%s", name);

	p = head;
	while (head != NULL && strcmp(code, p->code) == 0)
	{
		head = head->next;
		free(p);
		p = head;
	}
	if (head == NULL)
	{
		return head;
	}
	p = head->next;
	pold = head;
	while (p != NULL)
	{
		if (strcmp(code, p->code) == 0)
		{
			pold->next = p->next;
			free(p);
			p = pold->next;
		}
		else
		{
			pold = p;
			p = p->next;
		}
	}
	return head;
}

MarketingInformation* CancelMarketingInformation(MarketingInformation* primal, char* code)
{
	MarketingInformation* p, * pold;
	p = primal;
	while (primal != NULL && strcmp(code, p->productCode) == 0)
	{
		primal = primal->next;
		free(p);
		p = primal;
	}
	if (primal == NULL)
	{
		return primal;
	}
	p = primal->next;
	pold = primal;
	while (p != NULL)
	{
		if (strcmp(code, p->productCode) == 0)
		{
			pold->next = p->next;
			free(p);
			p = pold->next;
		}
		else
		{
			pold = p;
			p = p->next;
		}
	}
	return primal;
}


void AddProducer()
{
	system("cls");
	FILE* fp;
	fp = fopen("d:\\Producer.txt", "a+");
	int n;
	Producer* head = NULL;
	do {
		InputProducer(fp, head);
		printf("�Ƿ������ӣ���1����0����\n");
		scanf("%d", &n);
	} while (n == 1);
	fclose(fp);
}

void InputProducer(FILE* fp, Producer* head)
{
	Producer* pnew, * ptail;
	ptail = head;
	pnew = (Producer*)malloc(sizeof(Producer));
	printf("���\t����\t��ϵ�绰\t��ϵ��ַ\n");
	scanf("%s%s%s%s", pnew->code, pnew->name, pnew->phone, pnew->address);
	fprintf(fp, "%-8s %-8s %-16s %s\n", pnew->code, pnew->name, pnew->phone, pnew->address);
	fflush(fp);
	pnew->next = NULL;
	ptail = pnew;
}


void ReadProducer(FILE* fp, Producer* head)
{
	Producer* p, * q;

	q = head;

	while (!feof(fp))
	{
		p = (Producer*)malloc(sizeof(Producer));
		fscanf(fp, "%10s%10s%15s%50s", p->code, p->name, p->phone, p->address);
		q->next = p;
		q = p;
	}
	q->next = NULL;
}


Producer* FindProducer(Producer* head, char* code)
{
	while (head != NULL)
	{
		if (strcmp(code, head->code) == 0)
		{
			return head;
		}
		head = head->next;
	}
	return NULL;
}


void CheckProducer()
{
	system("cls");
	FILE* fp;
	fp = fopen("d:\\Producer.txt", "r");
	Producer* head;
	head = (Producer*)malloc(sizeof(Producer));
	ReadProducer(fp, head);
	int n;
	do {
		SearchProducer(head);
		printf("�Ƿ������ѯ����1����0����\n");
		scanf("%d", &n);
	} while (n == 1);
	fclose(fp);
}

void SearchProducer(Producer* head)
{
	char code[10];
	Producer* p;

	printf("��������Ҫ��ѯ�Ľ����̱��\n");
	scanf("%s", code);
	p = FindProducer(head, code);

	if (p == NULL)
	{
		printf("û�иý�����\n");
		return;
	}
	else
	{
		printf("���\t����\t��ϵ�绰\t��ϵ��ַ\n");
		printf("%-8s%-8s%-16s%s\n", p->code, p->name, p->phone, p->address);
	}
}



void InputAgain(FILE* fp, Producer* head)
{
	head = head->next;
	while (head->next != NULL)
	{
		fprintf(fp, "%s\t%s\t%s\t%s\n", head->code, head->name, head->phone, head->address);
		head = head->next;
	}
}


void AlterProducer()
{
	system("cls");
	FILE* fp;
	fp = fopen("d:\\Producer.txt", "r");
	Producer* head;
	head = (Producer*)malloc(sizeof(Producer));
	int n;
	ReadProducer(fp, head);
	fclose(fp);
	do {
		fp = fopen("d:\\Producer.txt", "w+");
		ChangeProducer(head);
		printf("�Ƿ�����޸ģ���1����0����\n");
		scanf("%d", &n);
		fclose(fp);
	} while (n == 1);

	fp = fopen("d:\\Producer.txt", "w+");
	InputAgain(fp, head);
	fclose(fp);
}

void ChangeProducer(Producer* head)
{
	char content[10], code[10];
	int type;
	Producer* p;

	printf("��������Ҫ�޸ĵĽ����̵ı��\n");
	scanf("%s", code);
	p = FindProducer(head, code);

	if (p == NULL)
	{
		printf("û�иý�����\n");
		return;
	}

	printf("��ѡ����Ҫ�޸���Ϣ�����:\n");
	printf("(1.����\t2.��ϵ�绰\t3.��ϵ��ַ)\n");
	scanf("%d", &type);

	printf("�������µ�����:\n");
	scanf("%s", content);

	switch (type)
	{
	case 1:
		strcpy(p->name, content);
		break;
	case 2:
		strcpy(p->phone, content);
		break;
	case 3:
		strcpy(p->address, content);
		break;
	}
}


void DeleteProducer()
{
	system("cls");
	FILE* fp;
	system("cls");
	fp = fopen("d:\\Producer.txt", "r");
	Producer* head;
	head = (Producer*)malloc(sizeof(Producer));
	int n;
	ReadProducer(fp, head);
	fclose(fp);
	do {
		CancelProducer(head);
		printf("�Ƿ����ɾ������1����0����\n");
		scanf("%d", &n);
	} while (n == 1);

	fp = fopen("d:\\Producer.txt", "w+");
	InputAgain(fp, head);
	fclose(fp);
}

Producer* CancelProducer(Producer* head)
{

	char code[10];
	Producer* p, * pold;

	printf("��������Ҫɾ���Ľ����̱��\n");
	scanf("%s", code);

	p = head;
	while (head != NULL && strcmp(code, p->code) == 0)
	{
		head = head->next;
		free(p);
		p = head;
	}
	if (head == NULL)
	{
		return head;
	}
	p = head->next;
	pold = head;
	while (p != NULL)
	{
		if (strcmp(code, p->code) == 0)
		{
			pold->next = p->next;
			free(p);
			p = pold->next;
		}
		else
		{
			pold = p;
			p = p->next;
		}
	}
	return head;
}




void AddCustomer()
{
	system("cls");
	FILE* fp;
	fp = fopen("d:\\Customer.txt", "a+");
	int n;
	Customer* head = NULL;
	do {
		InputCustomer(fp, head);
		printf("�Ƿ������ӣ���1����0����\n");
		scanf("%d", &n);
	} while (n == 1);
	fclose(fp);
}

void InputCustomer(FILE* fp, Customer* head)
{
	Customer* pnew, * ptail;
	ptail = head;
	pnew = (Customer*)malloc(sizeof(Customer));
	printf("���\t����\t��ϵ�绰\t��ϵ��ַ\n");
	scanf("%s%s%s%s", pnew->code, pnew->name, pnew->phone, pnew->address);
	fprintf(fp, "%-8s %-8s %-16s %s\n", pnew->code, pnew->name, pnew->phone, pnew->address);
	fflush(fp);
	pnew->next = NULL;
	ptail = pnew;
}


void ReadCustomer(FILE* fp, Customer* head)
{
	Customer* p, * q;

	q = head;

	while (!feof(fp))
	{
		p = (Customer*)malloc(sizeof(Customer));
		fscanf(fp, "%10s%10s%15s%50s", p->code, p->name, p->phone, p->address);
		q->next = p;
		q = p;
	}
	q->next = NULL;
}

Customer* FindCustomer(Customer* head, char* code)
{
	while (head != NULL)
	{
		if (strcmp(code, head->code) == 0)
		{
			return head;
		}
		head = head->next;
	}
	return NULL;
}


void CheckCustomer()
{
	system("cls");
	FILE* fp;
	fp = fopen("d:\\Customer.txt", "r");
	Customer* head;
	head = (Customer*)malloc(sizeof(Customer));
	ReadCustomer(fp, head);
	int n;
	do {
		SearchCustomer(head);
		printf("�Ƿ������ѯ����1����0����\n");
		scanf("%d", &n);
	} while (n == 1);
	fclose(fp);
}

void SearchCustomer(Customer* head)
{
	char code[10];
	Customer* p;

	printf("��������Ҫ��ѯ�Ĺ˿ͱ��\n");
	scanf("%s", code);
	p = FindCustomer(head, code);

	if (p == NULL)
	{
		printf("û�иù˿�\n");
		return;
	}
	else
	{
		printf("���\t����\t��ϵ�绰\t��ϵ��ַ\n");
		printf("%-8s%-8s%-16s%s\n", p->code, p->name, p->phone, p->address);
	}
}


void InputAgain(FILE* fp, Customer* head)
{
	head = head->next;
	while (head->next != NULL)
	{
		fprintf(fp, "%s\t%s\t%s\t%s\n", head->code, head->name, head->phone, head->address);
		head = head->next;
	}
}


void AlterCustomer()
{
	system("cls");
	FILE* fp;
	fp = fopen("d:\\Customer.txt", "r");
	Customer* head;
	head = (Customer*)malloc(sizeof(Customer));
	int n;
	ReadCustomer(fp, head);
	fclose(fp);
	do {
		fp = fopen("d:\\Customer.txt", "w+");
		ChangeCustomer(head);
		printf("�Ƿ�����޸ģ���1����0����\n");
		scanf("%d", &n);
		fclose(fp);
	} while (n == 1);

	fp = fopen("d:\\Customer.txt", "w+");
	InputAgain(fp, head);
	fclose(fp);
}

void ChangeCustomer(Customer* head)
{
	char content[10], code[10];
	int type;
	Customer* p;

	printf("��������Ҫ�޸ĵĹ˿͵ı��\n");
	scanf("%s", code);
	p = FindCustomer(head, code);

	if (p == NULL)
	{
		printf("û�иù˿�\n");
		return;
	}

	printf("��ѡ����Ҫ�޸���Ϣ�����:\n");
	printf("(1.����\t2.��ϵ�绰\t3.��ϵ��ַ)\n");
	scanf("%d", &type);

	printf("�������µ�����:\n");
	scanf("%s", content);

	switch (type)
	{
	case 1:
		strcpy(p->name, content);
		break;
	case 2:
		strcpy(p->phone, content);
		break;
	case 3:
		strcpy(p->address, content);
		break;
	}
}



void DeleteCustomer()
{
	system("cls");
	FILE* fp;
	system("cls");
	fp = fopen("d:\\Customer.txt", "r");
	Customer* head;
	head = (Customer*)malloc(sizeof(Customer));
	int n;
	ReadCustomer(fp, head);
	fclose(fp);
	do {
		CancelCustomer(head);
		printf("�Ƿ����ɾ������1����0����\n");
		scanf("%d", &n);
	} while (n == 1);

	fp = fopen("d:\\Customer.txt", "w+");
	InputAgain(fp, head);
	fclose(fp);
}

Customer* CancelCustomer(Customer* head)
{

	char code[10];
	Customer* p, * pold;

	printf("��������Ҫɾ���Ĺ˿ͱ��\n");
	scanf("%s", code);

	p = head;
	while (head != NULL && strcmp(code, p->code) == 0)
	{
		head = head->next;
		free(p);
		p = head;
	}
	if (head == NULL)
	{
		return head;
	}
	p = head->next;
	pold = head;
	while (p != NULL)
	{
		if (strcmp(code, p->code) == 0)
		{
			pold->next = p->next;
			free(p);
			p = pold->next;
		}
		else
		{
			pold = p;
			p = p->next;
		}
	}
	return head;
}
