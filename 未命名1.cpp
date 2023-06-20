#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct account
{
	char ID[100];
	char MM[100];
	double money;
};struct account s[3];
void csh()//初始化 
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
double DL()// 登录 
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
		printf("登录成功\n");	
		return s[i].money;	 
	}
	else 
	{
		printf("登录失败\n");	
		return 1;
	}
}
void menu()
{
	printf("菜单\n 1.修改密码\n 2.取款\n 3.存款\n 4.转账\n 5.查询余额\n 6.退出\n");	 
}
void XGMM()//修改密码 
{
    char m[100];
    char M[100];
    int n=1;
	while(n=1)
	{
		printf("请输入你的新密码：");
		scanf("%s",m);
		printf("请再次输入你的新密码：");
		scanf("%s",M);
        if(m[100]==M[100])
        {
        int i;
        strcpy(s[i].MM,m);	
	    printf("密码修改成功"); 
	    break; 
	    }
		else
		{
		printf("两次密码不一致");
		n=1;
	    }
	}
}
void QK()//取款 
{
	int i;
	csh();
	float m;
	scanf("%f",&m);
	if(m<0||m>s[i].money)
	{
		printf("账号余额不足");
		return QK();
	}
	else
	{
		s[i].money=s[i].money-m;
		printf("取款成功");
		printf("余额:%f",s[i].money); 
	} 
}
void ZZ()//转账 
{
	int i,q,k,d;
	struct account z;
	double m;
	printf("请输入转账账户\n");
	scanf("%s",z.ID);
	printf("请输入转账金额\n");
	scanf("%lf",&m);
	for(q=0;q<3;q++)
	{
		if(!strcmp(z.ID,s[q].ID))
		{
			printf("存在\n");
			if(m<=s[i].money)
			{
				s[q].money=s[q].money+m;
				s[i].money=s[i].money-m;
				printf("转账成功\n");
				printf("余额：%lf\n",s[i].money);
				break; 
			}
			else
			{
			 	printf("账户余额不足");
				break; 
			}
		}
	}
    if(q>=3)
	{
	printf("账号不存在");
    }
}
void YE()
{
	int i;
	printf("余额：%lf\n",s[i].money);
}
void quit()//退出 
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

