#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct account
{
	char ID[100];
	char MM[100];
	double money;
};struct account s[3];
void csh()//��ʼ�� 
{
	FILE* fp=fopen("account.txt","r");
	if(fp!=NULL)
	{
		for(int i=0;i<3;i++)
		{
			fscanf(fp,"%s%s%lf",s[i].ID,s[i].MM,&s[i].money);
		}
	}
	fclose(fp);
}
double DL()// ��¼ 
{
	struct account a;
	scanf("%s",a.ID);
	scanf("%s",a.MM);
	int i;
	for(i=0;i<3;i++)
	{
		if(!strcmp(a.ID,s[i].ID))
		{
			break;
		}
	}
	if(!strcmp(a.MM,s[i].MM))
	{
		printf("��¼�ɹ�\n");	
		return s[i].money;	 
	}
	else 
	{
		printf("��¼ʧ��\n");	
		return 1;
	}
}
void menu()
{
	printf("�˵�\n 1.�޸�����\n 2.ȡ��\n 3.���\n 4.ת��\n 5.��ѯ���\n 6.�˳�\n");	 
}
void XGMM()//�޸����� 
{
    char m[100];
    char M[100];
    int n=1;
	while(n=1)
	{
		printf("��������������룺");
		scanf("%s",m);
		printf("���ٴ�������������룺");
		scanf("%s",M);
        if(m[100]==M[100])
        {
        int i;
        strcpy(s[i].MM,m);	
	    printf("�����޸ĳɹ�"); 
	    break; 
	    }
		else
		{
		printf("�������벻һ��");
		n=1;
	    }
	}
}
void QK()//ȡ�� 
{
	int i;
	csh();
	float m;
	scanf("%f",&m);
	if(m<0||m>s[i].money)
	{
		printf("�˺�����");
		return QK();
	}
	else
	{
		s[i].money=s[i].money-m;
		printf("ȡ��ɹ�");
		printf("���:%f",s[i].money); 
	} 
}
void ZZ()//ת�� 
{
	int i,q,k,d;
	struct account z;
	double m;
	printf("������ת���˻�\n");
	scanf("%s",z.ID);
	printf("������ת�˽��\n");
	scanf("%lf",&m);
	for(q=0;q<3;q++)
	{
		if(!strcmp(z.ID,s[q].ID))
		{
			printf("����\n");
			if(m<=s[i].money)
			{
				s[q].money=s[q].money+m;
				s[i].money=s[i].money-m;
				printf("ת�˳ɹ�\n");
				printf("��%lf\n",s[i].money);
				break; 
			}
			else
			{
			 	printf("�˻�����");
				break; 
			}
		}
	}
    if(q>=3)
	{
	printf("�˺Ų�����");
    }
}
void YE()
{
	int i;
	printf("��%lf\n",s[i].money);
}
void quit()//�˳� 
{
	FILE* fp=fopen("account.txt","w");
	if(fp!=NULL)
	{
		for(int i=0;i<3;i++)
		{
			fprintf(fp,"%s\n %s\n %lf\n",s[i].ID,s[i].MM,s[i].money);
		}	
	} 
	fclose(fp);	
}
int main()
{
	int n;
	double p;
	csh();
	do
	{
		p=DL();	
	}while(p==1); 
	menu();
	int t=1;
	while(t!=0)
	{	scanf("%d",&n);
		switch(n)
		{	scanf("%d",&n);
			case 1:system("cls");XGMM();menu();break;
			case 2:system("cls");QK();menu();break;
			case 3:system("cls");menu();break;
			case 4:system("cls");ZZ();menu();break;
			case 5:system("cls");YE();menu();break;
			case 6:system("cls");t=0;quit();break;
		}
	}
	return 0;
}

