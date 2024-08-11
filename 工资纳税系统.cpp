#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
struct worker
{
	int number;//职工号
	char name[16];//姓名
	char sex;//性别
	char post[20];//岗位
	double allowance;//薪资
	double tax;//纳税
};
double Taxation(double wage);//计算缴纳税款
void TextScanf(struct worker* p, int& n);//读取原始保留数据
void TextPrint(struct worker* p, int n);//文本写入
void TextFormat(struct worker* p, int n);//格式化
void InputMessage(struct worker* p, int m, int n);//m为增加前用户总数,n为增加用户数
void OutputMessage(struct worker* p, int n);//n为总用户数量
void Operate();//功能实现函数
void Function();//操作选项
void AlterMessage(struct worker* p, struct worker* q, int n);//修改信息
void DeleteMessage(struct worker* p, struct worker* q, int m, int& n);//m为职工号,n为总用户数量
void Move(struct worker* p, int m, int n);//移动函数(数据前移),m为删除位置,n为用户数
void FindNumber(struct worker* p, int n);
void FindName(struct worker* p, int n);
void FindSex(struct worker* p, int n);
void FindPost(struct worker* p, int n);
void FindAllowance(struct worker* p, int n);
void IncreaseWage(struct worker* p, int n);
void DecreaseWage(struct worker* p, int n);
void IncreaseNumber(struct worker* p, int n);
void DecreaseNumber(struct worker* p, int n);
void Copy(struct worker* p, struct worker* q, int m, int n);//辅助结构体辅助
void CopyWhole(struct worker* p, struct worker* q, int n);//辅助结构体复制
int main()
{
	Operate();
	//MessageBox(NULL, TEXT("学不会"), TEXT("C&C++"), MB_OK);

	return 0;
}
void Operate()
{
	char strOptions[20];
	int n = 0;//n为操作前用户数量
	Function();
	printf("请输入操作方式(序号or中文):");
	struct worker* p = (worker*)malloc(sizeof(worker) * n);//主体结构体
	struct worker* q = (worker*)malloc(sizeof(worker) * n);//辅助结构体

	TextScanf(p, n);
	TextScanf(q, n);

	do
	{
		scanf("%s", strOptions);
		getchar();
		if (strcmp(strOptions, "增加") == 0 || strcmp(strOptions, "1") == 0)
		{
			int iPerson;
			printf("输入添加职工数量:");
			scanf("%d", &iPerson);
			InputMessage(p, n, iPerson);
			Copy(q, p, n, iPerson);
			n = n + iPerson;
			printf("\n请继续输入操作方式(序号or中文):");
		}
		else if (strcmp(strOptions, "修改") == 0 || strcmp(strOptions, "2") == 0)
		{
			AlterMessage(p, q, n);
			printf("\n请继续输入操作方式(序号or中文):");
		}
		else if (strcmp(strOptions, "删除") == 0 || strcmp(strOptions, "3") == 0)
		{
			int iNumber;
			printf("请输入删除职工号:");
			scanf("%d", &iNumber);
			DeleteMessage(p, q, iNumber, n);
			printf("\n请继续输入操作方式(序号or中文):");
		}
		else if (strcmp(strOptions, "查询") == 0 || strcmp(strOptions, "4") == 0)
		{
			printf("\n**********查找方式**********\n");
			printf("a:职工号查找\n");
			printf("b:姓名查找\n");
			printf("c:性别查找\n");
			printf("d:岗位查找\n");
			printf("e:薪资查找\n");
			printf("****************************\n\n");
			char chFindWay;
			printf("请输入查找方式:");
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
			printf("\n请继续输入操作方式(序号or中文):");
		}
		else if (strcmp(strOptions, "排序") == 0 || strcmp(strOptions, "5") == 0)
		{
			printf("\n**********排序方式**********\n");
			printf("a:职工号降序\n");
			printf("b:职工号升序\n");
			printf("c:薪资降序\n");
			printf("d:薪资升序\n");
			printf("****************************\n\n");
			char chWay;
			printf("请输入排序方式:");
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
			printf("\n请继续输入操作方式(序号or中文):");
		}
		else if (strcmp(strOptions, "显示") == 0 || strcmp(strOptions, "6") == 0)
		{
			OutputMessage(p, n);
			printf("\n请继续输入操作方式(序号or中文):");
		}
		else if (strcmp(strOptions, "保存") == 0 || strcmp(strOptions, "7") == 0)
		{
			TextPrint(p, n);
			printf("\n保存成功！\n");
			printf("\n请继续输入操作方式(序号or中文):");
		}
		else if (strcmp(strOptions, "清空") == 0 || strcmp(strOptions, "8") == 0)
		{
			TextFormat(p, n);
			TextFormat(q, n);
			n = 0;
			printf("\n文件已格式化！\n");
			printf("\n请继续输入操作方式(序号or中文):");
		}
		else if (strcmp(strOptions, "退出") == 0 || strcmp(strOptions, "0") == 0)
		{
			printf("\n操作退出成功！\n");
		}
		else
		{
			printf("\n输入错误(或未有此功能),请重新输入:");
		}
	} while (strcmp(strOptions, "退出") != 0 && strcmp(strOptions, "0") != 0);

	free(p);
	free(q);
}
void TextScanf(struct worker* p, int& n)
{
	FILE* fp;
	fp = fopen("taxes.txt", "r+");
	if (fp == NULL)
	{
		printf("文件打开失败！");
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
		printf("文件打开失败！");
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
		printf("文件打开失败！");
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
	printf("----------操作选项----------\n");
	printf("1:增加\n");
	printf("2:修改\n");
	printf("3:删除\n");
	printf("4:查询\n");
	printf("5:排序\n");
	printf("6:显示\n");
	printf("7:保存\n");
	printf("8:清空\n");
	printf("0:退出\n");
	printf("----------------------------\n\n");
}
void AlterMessage(struct worker* p, struct worker* q, int n)
{
	int i = 0;
	int iNumber;
	printf("请输入修改职工号:");
	scanf("%d", &iNumber);
	while ((p + i)->number != iNumber && i < n)
	{
		i++;
	}
	if ((p + i)->number == iNumber)
	{
		printf("请输入修改姓名、性别(M/F)、岗位、薪资(以空格分开):\n");
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
		printf("\n该职工号未被注册！\n");
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
		printf("\n无该职工号信息，删除失败！\n");
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
	printf("请输入查询职工号:");
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
			printf("暂无该职工号职工！\n");
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
			printf("暂无该职工号职工！\n");
		}
	}
}
void FindName(struct worker* p, int n)
{
	int i = 0;
	int iCount = 0;
	char strName[16];
	printf("请输入名字:");
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
		printf("暂无该员工信息！\n");
	}
}
void FindSex(struct worker* p, int n)
{
	int i = 0;
	int iCount = 0;
	char chSex;
	printf("请输入性别(M/F):");
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
		printf("暂无男性员工！\n");
	}
	else if (iCount == 0 && chSex == 'F')
	{
		printf("暂无女性员工！\n");
	}
}
void FindPost(struct worker* p, int n)
{
	int i = 0;
	int iCount = 0;
	char strPost[20];
	printf("请输入岗位名称:");
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
		printf("暂无该岗位员工信息！\n");
	}
}
void FindAllowance(struct worker* p, int n)
{
	int i = 0;
	int iCount = 0;
	double dAllowance;
	printf("请输入查询薪资:");
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
		printf("暂无该薪资职工！\n");
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
	printf("请输入职工号、姓名、性别(M/F)、岗位、薪资(以空格分开):\n");
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
	printf("\n员工纳税状况表(职工号、姓名、性别、岗位、薪资、纳税):\n");
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