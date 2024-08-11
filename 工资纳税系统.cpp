#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
struct worker
{
	int number;//ְ����
	char name[16];//����
	char sex;//�Ա�
	char post[20];//��λ
	double allowance;//н��
	double tax;//��˰
};
double Taxation(double wage);//�������˰��
void TextScanf(struct worker* p, int& n);//��ȡԭʼ��������
void TextPrint(struct worker* p, int n);//�ı�д��
void TextFormat(struct worker* p, int n);//��ʽ��
void InputMessage(struct worker* p, int m, int n);//mΪ����ǰ�û�����,nΪ�����û���
void OutputMessage(struct worker* p, int n);//nΪ���û�����
void Operate();//����ʵ�ֺ���
void Function();//����ѡ��
void AlterMessage(struct worker* p, struct worker* q, int n);//�޸���Ϣ
void DeleteMessage(struct worker* p, struct worker* q, int m, int& n);//mΪְ����,nΪ���û�����
void Move(struct worker* p, int m, int n);//�ƶ�����(����ǰ��),mΪɾ��λ��,nΪ�û���
void FindNumber(struct worker* p, int n);
void FindName(struct worker* p, int n);
void FindSex(struct worker* p, int n);
void FindPost(struct worker* p, int n);
void FindAllowance(struct worker* p, int n);
void IncreaseWage(struct worker* p, int n);
void DecreaseWage(struct worker* p, int n);
void IncreaseNumber(struct worker* p, int n);
void DecreaseNumber(struct worker* p, int n);
void Copy(struct worker* p, struct worker* q, int m, int n);//�����ṹ�帨��
void CopyWhole(struct worker* p, struct worker* q, int n);//�����ṹ�帴��
int main()
{
	Operate();
	//MessageBox(NULL, TEXT("ѧ����"), TEXT("C&C++"), MB_OK);

	return 0;
}
void Operate()
{
	char strOptions[20];
	int n = 0;//nΪ����ǰ�û�����
	Function();
	printf("�����������ʽ(���or����):");
	struct worker* p = (worker*)malloc(sizeof(worker) * n);//����ṹ��
	struct worker* q = (worker*)malloc(sizeof(worker) * n);//�����ṹ��

	TextScanf(p, n);
	TextScanf(q, n);

	do
	{
		scanf("%s", strOptions);
		getchar();
		if (strcmp(strOptions, "����") == 0 || strcmp(strOptions, "1") == 0)
		{
			int iPerson;
			printf("�������ְ������:");
			scanf("%d", &iPerson);
			InputMessage(p, n, iPerson);
			Copy(q, p, n, iPerson);
			n = n + iPerson;
			printf("\n��������������ʽ(���or����):");
		}
		else if (strcmp(strOptions, "�޸�") == 0 || strcmp(strOptions, "2") == 0)
		{
			AlterMessage(p, q, n);
			printf("\n��������������ʽ(���or����):");
		}
		else if (strcmp(strOptions, "ɾ��") == 0 || strcmp(strOptions, "3") == 0)
		{
			int iNumber;
			printf("������ɾ��ְ����:");
			scanf("%d", &iNumber);
			DeleteMessage(p, q, iNumber, n);
			printf("\n��������������ʽ(���or����):");
		}
		else if (strcmp(strOptions, "��ѯ") == 0 || strcmp(strOptions, "4") == 0)
		{
			printf("\n**********���ҷ�ʽ**********\n");
			printf("a:ְ���Ų���\n");
			printf("b:��������\n");
			printf("c:�Ա����\n");
			printf("d:��λ����\n");
			printf("e:н�ʲ���\n");
			printf("****************************\n\n");
			char chFindWay;
			printf("��������ҷ�ʽ:");
			scanf("%c", &chFindWay);
			getchar();
			if (chFindWay == 'a')
			{
				DecreaseNumber(q, n);
				FindNumber(q, n);
				CopyWhole(q, p, n);
			}
			else if (chFindWay == 'b')
			{
				FindName(p, n);
			}
			else if (chFindWay == 'c')
			{
				FindSex(p, n);
			}
			else if (chFindWay == 'd')
			{
				FindPost(p, n);
			}
			else if (chFindWay == 'e')
			{
				FindAllowance(p, n);
			}
			printf("\n��������������ʽ(���or����):");
		}
		else if (strcmp(strOptions, "����") == 0 || strcmp(strOptions, "5") == 0)
		{
			printf("\n**********����ʽ**********\n");
			printf("a:ְ���Ž���\n");
			printf("b:ְ��������\n");
			printf("c:н�ʽ���\n");
			printf("d:н������\n");
			printf("****************************\n\n");
			char chWay;
			printf("����������ʽ:");
			scanf("%c", &chWay);
			getchar();
			if (chWay == 'a')
			{
				DecreaseNumber(p, n);
				DecreaseNumber(q, n);
			}
			else if (chWay == 'b')
			{
				IncreaseNumber(p, n);
				IncreaseNumber(q, n);
			}
			else if (chWay == 'c')
			{
				DecreaseWage(p, n);
				DecreaseWage(q, n);
			}
			else if (chWay == 'd')
			{
				IncreaseWage(p, n);
				IncreaseWage(q, n);
			}
			printf("\n��������������ʽ(���or����):");
		}
		else if (strcmp(strOptions, "��ʾ") == 0 || strcmp(strOptions, "6") == 0)
		{
			OutputMessage(p, n);
			printf("\n��������������ʽ(���or����):");
		}
		else if (strcmp(strOptions, "����") == 0 || strcmp(strOptions, "7") == 0)
		{
			TextPrint(p, n);
			printf("\n����ɹ���\n");
			printf("\n��������������ʽ(���or����):");
		}
		else if (strcmp(strOptions, "���") == 0 || strcmp(strOptions, "8") == 0)
		{
			TextFormat(p, n);
			TextFormat(q, n);
			n = 0;
			printf("\n�ļ��Ѹ�ʽ����\n");
			printf("\n��������������ʽ(���or����):");
		}
		else if (strcmp(strOptions, "�˳�") == 0 || strcmp(strOptions, "0") == 0)
		{
			printf("\n�����˳��ɹ���\n");
		}
		else
		{
			printf("\n�������(��δ�д˹���),����������:");
		}
	} while (strcmp(strOptions, "�˳�") != 0 && strcmp(strOptions, "0") != 0);

	free(p);
	free(q);
}
void TextScanf(struct worker* p, int& n)
{
	FILE* fp;
	fp = fopen("taxes.txt", "r+");
	if (fp == NULL)
	{
		printf("�ļ���ʧ�ܣ�");
		exit(0);
	}
	int i = 0;
	while (fscanf(fp, "%d", &(p + i)->number) != EOF)
	{
		fscanf(fp, "%d\t", &(p + i)->number);
		fscanf(fp, "%s\t", (p + i)->name);
		fscanf(fp, "%c\t", &(p + i)->sex);
		fscanf(fp, "%s\t", (p + i)->post);
		fscanf(fp, "%lf\t", &(p + i)->allowance);
		fscanf(fp, "%lf\t", &(p + i)->tax);
		i++;
	}
	n = i;
	fclose(fp);
}
void TextPrint(struct worker* p, int n)
{
	FILE* fp;
	fp = fopen("taxes.txt", "w+");
	if (fp == NULL)
	{
		printf("�ļ���ʧ�ܣ�");
		exit(0);
	}
	int i = 0;
	for (i = 0; i < n; i++)
	{
		fprintf(fp, "%-6d\t", (p + i)->number);
		fprintf(fp, "%-6s\t", (p + i)->name);
		fprintf(fp, "%-3c\t", (p + i)->sex);
		fprintf(fp, "%-6s\t", (p + i)->post);
		fprintf(fp, "%-12.2lf\t", (p + i)->allowance);
		fprintf(fp, "%-12.2lf\n", Taxation((p + i)->allowance));
	}
	fclose(fp);
}
void TextFormat(struct worker* p, int n)
{
	FILE* fp;
	fp = fopen("taxes.txt", "w+");
	if (fp == NULL)
	{
		printf("�ļ���ʧ�ܣ�");
		exit(0);
	}
	int i = 0;
	for (i = 0; i < n; i++)
	{
		(p + i)->number = 0;
		strcpy((p + i)->name, "");
		strcpy((p + i)->post, "");
		(p + i)->sex = NULL;
		(p + i)->allowance = 0;
		(p + i)->tax = 0;
	}

	fclose(fp);
}
void Function()
{
	printf("----------����ѡ��----------\n");
	printf("1:����\n");
	printf("2:�޸�\n");
	printf("3:ɾ��\n");
	printf("4:��ѯ\n");
	printf("5:����\n");
	printf("6:��ʾ\n");
	printf("7:����\n");
	printf("8:���\n");
	printf("0:�˳�\n");
	printf("----------------------------\n\n");
}
void AlterMessage(struct worker* p, struct worker* q, int n)
{
	int i = 0;
	int iNumber;
	printf("�������޸�ְ����:");
	scanf("%d", &iNumber);
	while ((p + i)->number != iNumber && i < n)
	{
		i++;
	}
	if ((p + i)->number == iNumber)
	{
		printf("�������޸��������Ա�(M/F)����λ��н��(�Կո�ֿ�):\n");
		scanf("%s", (p + i)->name);
		getchar();
		scanf("%c", &(p + i)->sex);
		scanf("%s", (p + i)->post);
		getchar();
		scanf("%lf", &(p + i)->allowance);
		(q + i)->number = (p + i)->number;
		strcmp((q + i)->name, (p + i)->name);
		(q + i)->sex = (p + i)->sex;
		strcmp((q + i)->post, (p + i)->post);
		(q + i)->allowance = (p + i)->allowance;
	}
	else
	{
		printf("\n��ְ����δ��ע�ᣡ\n");
	}
}
void DeleteMessage(struct worker* p, struct worker* q, int m, int& n)
{
	int i = 0;
	while ((p + i)->number != m && i < n)
	{
		i++;
	}
	if ((p + i)->number != m)
	{
		printf("\n�޸�ְ������Ϣ��ɾ��ʧ�ܣ�\n");
	}
	else if (i != n - 1)
	{
		Move(p, i, n);
		Move(q, i, n);
		n = n - 1;
	}
	else if (i == n - 1)
	{
		(p + n - 1)->number = 0;
		strcpy((p + n - 1)->name, "");
		strcpy((p + n - 1)->post, "");
		(p + n - 1)->sex = NULL;
		(p + n - 1)->allowance = 0;
		(q + n - 1)->number = 0;
		strcpy((q + n - 1)->name, "");
		strcpy((q + n - 1)->post, "");
		(q + n - 1)->sex = NULL;
		(q + n - 1)->allowance = 0;
		n = n - 1;
	}
}
void Move(struct worker* p, int m, int n)
{
	int i = 0;
	for (i = m; i < n - 1; i++)
	{
		(p + i)->number = (p + i + 1)->number;
		strcpy((p + i)->name, (p + i + 1)->name);
		(p + i)->sex = (p + i + 1)->sex;
		strcpy((p + i)->post, (p + i + 1)->post);
		(p + i)->allowance = (p + i + 1)->allowance;
	}
}
void FindNumber(struct worker* p, int n)
{
	int i = 0;
	int iNumber;
	printf("�������ѯְ����:");
	scanf("%d", &iNumber);
	printf("\n");
	if (iNumber > (p + n / 2)->number)
	{
		while ((p + i)->number != iNumber && i < n / 2)
		{
			i++;
		}
		if ((p + i)->number == iNumber)
		{
			printf("%-6d ", (p + i)->number);
			printf("%-6s ", (p + i)->name);
			printf("%-3c ", (p + i)->sex);
			printf("%-6s ", (p + i)->post);
			printf("%-6.2lf ", (p + i)->allowance);
			printf("%-6.2lf\n", Taxation((p + i)->allowance));
		}
		else
		{
			printf("���޸�ְ����ְ����\n");
		}
	}
	else
	{
		i = n / 2;
		while ((p + i)->number != iNumber && i < n)
		{
			i++;
		}
		if ((p + i)->number == iNumber)
		{
			printf("%-6d ", (p + i)->number);
			printf("%-6s ", (p + i)->name);
			printf("%-3c ", (p + i)->sex);
			printf("%-6s ", (p + i)->post);
			printf("%-6.2lf ", (p + i)->allowance);
			printf("%-6.2lf\n", Taxation((p + i)->allowance));
		}
		else
		{
			printf("���޸�ְ����ְ����\n");
		}
	}
}
void FindName(struct worker* p, int n)
{
	int i = 0;
	int iCount = 0;
	char strName[16];
	printf("����������:");
	scanf("%s", strName);
	getchar();
	printf("\n");
	for (i = 0; i < n; i++)
	{
		if (strcmp(strName, (p + i)->name) == 0)
		{
			printf("%-6d ", (p + i)->number);
			printf("%-6s ", (p + i)->name);
			printf("%-3c ", (p + i)->sex);
			printf("%-6s ", (p + i)->post);
			printf("%-6.2lf ", (p + i)->allowance);
			printf("%-6.2lf\n", Taxation((p + i)->allowance));
			iCount++;
		}
	}
	if (iCount == 0)
	{
		printf("���޸�Ա����Ϣ��\n");
	}
}
void FindSex(struct worker* p, int n)
{
	int i = 0;
	int iCount = 0;
	char chSex;
	printf("�������Ա�(M/F):");
	scanf("%c", &chSex);
	printf("\n");
	for (i = 0; i < n; i++)
	{
		if (chSex == (p + i)->sex)
		{
			printf("%-6d ", (p + i)->number);
			printf("%-6s ", (p + i)->name);
			printf("%-3c ", (p + i)->sex);
			printf("%-6s ", (p + i)->post);
			printf("%-6.2lf ", (p + i)->allowance);
			printf("%-6.2lf\n", Taxation((p + i)->allowance));
			iCount++;
		}
	}
	if (iCount == 0 && chSex == 'M')
	{
		printf("��������Ա����\n");
	}
	else if (iCount == 0 && chSex == 'F')
	{
		printf("����Ů��Ա����\n");
	}
}
void FindPost(struct worker* p, int n)
{
	int i = 0;
	int iCount = 0;
	char strPost[20];
	printf("�������λ����:");
	scanf("%s", strPost);
	getchar();
	printf("\n");
	for (i = 0; i < n; i++)
	{
		if (strcmp(strPost, (p + i)->post) == 0)
		{
			printf("%-6d ", (p + i)->number);
			printf("%-6s ", (p + i)->name);
			printf("%-3c ", (p + i)->sex);
			printf("%-6s ", (p + i)->post);
			printf("%-6.2lf ", (p + i)->allowance);
			printf("%-6.2lf\n", Taxation((p + i)->allowance));
			iCount++;
		}
	}
	if (iCount == 0)
	{
		printf("���޸ø�λԱ����Ϣ��\n");
	}
}
void FindAllowance(struct worker* p, int n)
{
	int i = 0;
	int iCount = 0;
	double dAllowance;
	printf("�������ѯн��:");
	scanf("%lf", &dAllowance);
	printf("\n");
	for (i = 0; i < n; i++)
	{
		if ((p + i)->allowance == dAllowance)
		{
			printf("%-6d ", (p + i)->number);
			printf("%-6s ", (p + i)->name);
			printf("%-3c ", (p + i)->sex);
			printf("%-6s ", (p + i)->post);
			printf("%-6.2lf ", (p + i)->allowance);
			printf("%-6.2lf\n", Taxation((p + i)->allowance));
			iCount++;
		}
	}
	if (iCount == 0)
	{
		printf("���޸�н��ְ����\n");
	}
}
void IncreaseWage(struct worker* p, int n)
{
	int i = 0;
	int j = 0;
	int iNumber;
	char strName[16];
	char chSex;
	char strPost[20];
	double dAllowance;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if ((p + j)->allowance > (p + j + 1)->allowance)
			{
				iNumber = (p + j)->number;
				(p + j)->number = (p + j + 1)->number;
				(p + j + 1)->number = iNumber;
				strcpy(strName, (p + j)->name);
				strcpy((p + j)->name, (p + j + 1)->name);
				strcpy((p + j + 1)->name, strName);
				chSex = (p + j)->sex;
				(p + j)->sex = (p + j + 1)->sex;
				(p + j + 1)->sex = chSex;
				strcpy(strPost, (p + j)->post);
				strcpy((p + j)->post, (p + j + 1)->post);
				strcpy((p + j + 1)->post, strPost);
				dAllowance = (p + j)->allowance;
				(p + j)->allowance = (p + j + 1)->allowance;
				(p + j + 1)->allowance = dAllowance;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if ((p + j)->number > (p + j + 1)->number &&
				(p + j)->allowance == (p + j + 1)->allowance)
			{
				iNumber = (p + j)->number;
				(p + j)->number = (p + j + 1)->number;
				(p + j + 1)->number = iNumber;
				strcpy(strName, (p + j)->name);
				strcpy((p + j)->name, (p + j + 1)->name);
				strcpy((p + j + 1)->name, strName);
				chSex = (p + j)->sex;
				(p + j)->sex = (p + j + 1)->sex;
				(p + j + 1)->sex = chSex;
				strcpy(strPost, (p + j)->post);
				strcpy((p + j)->post, (p + j + 1)->post);
				strcpy((p + j + 1)->post, strPost);
				dAllowance = (p + j)->allowance;
				(p + j)->allowance = (p + j + 1)->allowance;
				(p + j + 1)->allowance = dAllowance;
			}
		}
	}
}
void DecreaseWage(struct worker* p, int n)
{
	int i = 0;
	int j = 0;
	int iNumber;
	char strName[16];
	char chSex;
	char strPost[20];
	double dAllowance;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if ((p + j)->allowance < (p + j + 1)->allowance)
			{
				iNumber = (p + j)->number;
				(p + j)->number = (p + j + 1)->number;
				(p + j + 1)->number = iNumber;
				strcpy(strName, (p + j)->name);
				strcpy((p + j)->name, (p + j + 1)->name);
				strcpy((p + j + 1)->name, strName);
				chSex = (p + j)->sex;
				(p + j)->sex = (p + j + 1)->sex;
				(p + j + 1)->sex = chSex;
				strcpy(strPost, (p + j)->post);
				strcpy((p + j)->post, (p + j + 1)->post);
				strcpy((p + j + 1)->post, strPost);
				dAllowance = (p + j)->allowance;
				(p + j)->allowance = (p + j + 1)->allowance;
				(p + j + 1)->allowance = dAllowance;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if ((p + j)->number < (p + j + 1)->number &&
				(p + j)->allowance == (p + j + 1)->allowance)
			{
				iNumber = (p + j)->number;
				(p + j)->number = (p + j + 1)->number;
				(p + j + 1)->number = iNumber;
				strcpy(strName, (p + j)->name);
				strcpy((p + j)->name, (p + j + 1)->name);
				strcpy((p + j + 1)->name, strName);
				chSex = (p + j)->sex;
				(p + j)->sex = (p + j + 1)->sex;
				(p + j + 1)->sex = chSex;
				strcpy(strPost, (p + j)->post);
				strcpy((p + j)->post, (p + j + 1)->post);
				strcpy((p + j + 1)->post, strPost);
				dAllowance = (p + j)->allowance;
				(p + j)->allowance = (p + j + 1)->allowance;
				(p + j + 1)->allowance = dAllowance;
			}
		}
	}
}
void IncreaseNumber(struct worker* p, int n)
{
	int i = 0;
	int j = 0;
	int iNumber;
	char strName[16];
	char chSex;
	char strPost[20];
	double dAllowance;
	for (i = 0; i < n - 1; i++)
	{
		int min = i;
		for (j = i; j < n; j++)
		{
			if ((p + min)->number > (p + j)->number)
			{
				min = j;
			}
		}
		if (min != i)
		{
			iNumber = (p + min)->number;
			(p + min)->number = (p + i)->number;
			(p + i)->number = iNumber;
			strcpy(strName, (p + min)->name);
			strcpy((p + min)->name, (p + i)->name);
			strcpy((p + i)->name, strName);
			chSex = (p + min)->sex;
			(p + min)->sex = (p + i)->sex;
			(p + i)->sex = chSex;
			strcpy(strPost, (p + min)->post);
			strcpy((p + min)->post, (p + i)->post);
			strcpy((p + i)->post, strPost);
			dAllowance = (p + min)->allowance;
			(p + min)->allowance = (p + i)->allowance;
			(p + i)->allowance = dAllowance;
		}
	}
}
void DecreaseNumber(struct worker* p, int n)
{
	int i = 0;
	int j = 0;
	int iNumber;
	char strName[16];
	char chSex;
	char strPost[20];
	double dAllowance;
	for (i = 0; i < n - 1; i++)
	{
		int max = i;
		for (j = i; j < n; j++)
		{
			if ((p + max)->number < (p + j)->number)
			{
				max = j;
			}
		}
		if (max != i)
		{
			iNumber = (p + max)->number;
			(p + max)->number = (p + i)->number;
			(p + i)->number = iNumber;
			strcpy(strName, (p + max)->name);
			strcpy((p + max)->name, (p + i)->name);
			strcpy((p + i)->name, strName);
			chSex = (p + max)->sex;
			(p + max)->sex = (p + i)->sex;
			(p + i)->sex = chSex;
			strcpy(strPost, (p + max)->post);
			strcpy((p + max)->post, (p + i)->post);
			strcpy((p + i)->post, strPost);
			dAllowance = (p + max)->allowance;
			(p + max)->allowance = (p + i)->allowance;
			(p + i)->allowance = dAllowance;
		}
	}
}
void Copy(struct worker* p, struct worker* q, int m, int n)
{
	int i = 0;
	for (i = m; i < m + n; i++)
	{
		(p + i)->number = (q + i)->number;
		strcpy((p + i)->name, (q + i)->name);
		(p + i)->sex = (q + i)->sex;
		strcpy((p + i)->post, (q + i)->post);
		(p + i)->allowance = (q + i)->allowance;
	}
}
void CopyWhole(struct worker* p, struct worker* q, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		(p + i)->number = (q + i)->number;
		strcpy((p + i)->name, (q + i)->name);
		(p + i)->sex = (q + i)->sex;
		strcpy((p + i)->post, (q + i)->post);
		(p + i)->allowance = (q + i)->allowance;
	}
}
void InputMessage(struct worker* p, int m, int n)
{
	int i = 0;
	printf("������ְ���š��������Ա�(M/F)����λ��н��(�Կո�ֿ�):\n");
	for (i = m; i < m + n; i++)
	{
		scanf("%d", &(p + i)->number);
		scanf("%s", (p + i)->name);
		getchar();
		scanf("%c", &(p + i)->sex);
		scanf("%s", (p + i)->post);
		getchar();
		scanf("%lf", &(p + i)->allowance);
	}
}
void OutputMessage(struct worker* p, int n)
{
	int i = 0;
	printf("\nԱ����˰״����(ְ���š��������Ա𡢸�λ��н�ʡ���˰):\n");
	for (i = 0; i < n; i++)
	{
		printf("%-6d ", (p + i)->number);
		printf("%-6s ", (p + i)->name);
		printf("%-3c ", (p + i)->sex);
		printf("%-9s ", (p + i)->post);
		printf("%-12.2lf ", (p + i)->allowance);
		printf("%-12.2lf\n", Taxation((p + i)->allowance));
	}
}
double Taxation(double wage)
{
	if (wage <= 1600)
		return 0;
	else if (wage > 1600 && wage <= 2100)
		return (wage - 1600) * 0.05;
	else if (wage > 2100 && wage <= 3600)
		return 25 + (wage - 2100) * 0.1;
	else if (wage > 3600 && wage <= 6600)
		return 175 + (wage - 3600) * 0.15;
	else if (wage > 6600 && wage <= 21600)
		return 625 + (wage - 6600) * 0.2;
	else if (wage > 21600 && wage <= 41600)
		return 3625 + (wage - 21600) * 0.25;
	else if (wage > 41600 && wage <= 61600)
		return 8625 + (wage - 41600) * 0.3;
	else if (wage > 61600 && wage <= 81600)
		return 14625 + (wage - 61600) * 0.35;
	else if (wage > 81600 && wage <= 101600)
		return 21625 + (wage - 81600) * 0.4;
	else if (wage > 101600)
		return 29625 + (wage - 101600) * 0.45;
}