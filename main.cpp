// main2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

#include<iostream>
#include<stdio>
using namespace std;
one;
FILE*fp;
void read();
void find();
void write();
void add();
void modify();
void Delete();
void grsds();
void load() ;
void list();
void exit();
struct emploee  //职工数据结构
int n;      //员工总人数
{
char no[10];
char name[30];
float wage1;      //员工的基本工资
float wage2;      //员工的职务工资
float wage3;      //员工的职务津贴
float wage4;   //员工的绩效工资
float wage5;    //员工的应发工资
float TAXfee;     //员工的个人所得税
float wage6;      //员工的实发工资
}
void main()
{
 menu()
}
void main()
{ int n,w1;
   
  do
	  system("color 0b");  
      printf("************* 职工工资管理系统 **************\n");
      printf("*            1-----添加职工信息                     *\n");
      printf("*            2-----查找职工信息                     *\n");
      printf("*            3-----修改职工信息	                             *\n");
      printf("*            4-----删除职工信息 *\n");
	  printf("*            6-----输出职工信息                           *\n")
      printf("*            6-----退出程序                           *\n");
      printf("***************************************************\n");
	  scanf("%d",&m);
		if(m>=1&&m<=6)
		{
			switch(m)
			{
				case 1: add();
				break;
				case 2: search();
				break;
				case 3: modify();
				break;
				case 4: Delete();
				break;
				case 5: read();
				break;
				case 6: exit(0);
			}
		}
		else
		{
			printf("\n\n无效打开文件，请重试");
		}
	}
}

 
/*************************读取模块**********************/
void read()
	{	
	int choice;
	system("cls");
	if((fp=fopen("worker.xls","r"))==NULL)
	{
		system("cls");
		printf("\n对不起，无法查询信息文件。\n\n");
		exit(0);
	}
	printf("                          =========================\n");
	printf("                                  职工信息\n");
	printf("                          =========================\n");
     printf("记录号 职工号 姓名 姓名  基本工资 职务工资 职务津贴  绩效工资   应发工资  税 实发工资\n");
	printf("          \n\n");
	while(!feof(fp))
	{
		fscanf(fp,"%s%s%s%s%s%s%s%s%s\n",one.name,one.num,one.sex,one.position,one.wanges,one.birth,one.gread,one.add,one.pnum);
		printf("%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s\n",one.name,one.num,one.sex,one.position,one.wanges,one.birth,one.gread,one.add,one.pnum);
	}
	fclose(fp);
	printf("\n\n显示完毕，请按下回车继续");
	choice=getch();
	system("cls");
}

/*************************统计模块**********************/
void grsds()
{
     FILE *fp;
     int n,num;
     if((fp=fopen("emp.txt","rb"))==NULL)
     {
         printf("不能打开emp文件\n");
         exit(1);
     }
     printf("请输入工资数:");
     scanf("%d",&num);
     printf(" 职工号 姓名 姓名  基本工资 职务工资 职务津贴  绩效工资   应发工资  税 实发工资\n");
     for(n=0;fread(&emp[n],sizeof(struct emploee),1,fp)!=0;n++)
     if(emp[n].wage3>=num)
     printf("%6d%6s%9s%4s%5d   %.1f   %.1f  %.1f   %.1f   %.1f   %.1f\n",n+1,emp[n].no,emp[n].name,emp[n].wage1,
             emp[n].wage2,emp[n].wage3,emp[n].wage4,emp[n].wage5,emp[n].TAXfee,emp[n].wage6);
     fclose(fp);
}
/********************删除模块*******************/

void Delete()
	{
	int m;
	int choice;
	int k=0;	
	long a;
	char namekey[50];
	char valid[50];
	system("cls");
	printf("\n请输入您要修改的职工姓名:");
	scanf("%s",namekey);
	if((fp=fopen("worker.xls","r+"))==NULL)
	{
		printf("\n对不起，无法查询信息文件。");
		exit(0);
	}
	while(!feof(fp))
	{
		a=ftell(fp);
		fscanf(fp,"%s%s%s%s%s\n",one.name,one.num,one.sex,one.position,one.wanges,one.birth,one.gread,one.add,one.pnum);
		if(strcmp(namekey,one.name)==0)
		{
			k=1;
			break;
		}
	}
	if(k==1)
	{
		printf("\n已查到，记录为:");
		printf("\n%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s\n",one.name,one.num,one.sex,one.position,one.wanges,one.birth,one.gread,one.add,one.pnum);
		printf("\n确定删除按1，不删除按0：");
		scanf("%d",&m);
		if(m==1)
		{
			fseek(fp,a,0);
			fprintf(fp,"%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s\n","","","","","");
		}
	}
	else
	{
		printf("\n对不起，查无此人。");
	}
	fclose(fp);
	printf("\n\n操作完成，请按下回车继续");
	choice=getch();
	system("cls");
}
/********************修改模块*******************/
void modify()
{
	int choice;
	int k=0;	
	long a;
	char namekey[50];
	system("cls");
	printf("\n请输入您要修改的职工姓名:");
	scanf("%s",namekey);
	if((fp=fopen("worker.xls","r+"))==NULL)
	{
		printf("\n对不起，无法查询信息文件。");
		exit(0);
	}
	while(!feof(fp))
	{
		a=ftell(fp);
		fscanf(fp,"%s%s%s%s%s%s%s%s%s\n",one.name,one.num,one.sex,one.position,one.wanges,one.birth,one.gread,one.add,one.pnum);
		if(!strcmp(namekey,one.name))
		{
			k=1;
			break;
		}
	}
	if(k)
	{
		printf("\n已查到，记录为:");
		printf("\n%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s\n",one.name,one.num,one.sex,one.position,one.wanges,one.birth,one.gread,one.add,one.pnum);
		printf("\n请输入需要修改的信息。\n");
		printf("（请按照：姓名  基本工资 职务工资 职务津贴  绩效工资   应发工资  税 实发工资）\n");
		scanf("%s%s%s%s%s%s%s%s%s",one.name,one.num,one.sex,one.position,one.wanges,one.birth,one.gread,one.add,one.pnum);
		fseek(fp,a,0);
		fprintf(fp,"%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s\n",one.name,one.num,one.sex,one.position,one.wanges,one.birth,one.gread,one.add,one.pnum);
	}
	else
	{
		printf("\n对不起，查无此人，无法修改。");
		fclose(fp);
	}
	printf("\n\n操作完成，请按下回车继续");
	choice=getch();
	system("cls");
}
 /*************************查询模块***********************/
void find()
{	
	int l;
	system("cls");
	printf(" 按姓名查找请按: 1\n");
	printf(" 按工号查找请按: 2\n");
	scanf("%d",&l);
	if(l>0&&l<3)
	{
		switch(l)
		{
			case 1:nameway();
			break;
			case 2:numway();
			break;
		}
	}
	else 
	{
		printf("\n\n无效指令，请重试");
	}
}
void nameway()
{
	int choice;
	int k=0;
	char nam[50];
	printf("\n请输入您要查询的职工姓名:");
	scanf("%s",nam);
	if((fp=fopen("worker.xls","rb"))==NULL)
	{
		printf("\n对不起，无法查询信息文件。");
		exit(0);
	}
	while(!feof(fp))
	{
		fscanf(fp,"%s%s%s%s%s%s%s%s%s\n",one.name,one.num,one.sex,one.position,one.wanges,one.birth,one.gread,one.add,one.pnum);
		if(strcmp(nam,one.name)==0)
		{
			printf("\n\n已查到，记录为：");
			printf("%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s\n",one.name,one.num,one.sex,one.position,one.wanges,one.birth,one.gread,one.add,one.pnum);
			k=1;
		}
	}
	if(k==0)
	{
		printf("\n\n对不起，查无此人。\n");
		fclose(fp);
	}
	printf("\n\n操作完成，请按下回车继续");
	choice=getch();
	system("cls");
}

void numway()
{
	int i=0;
	int choice;
	char numb[50];
	printf("   输入你要查询的工号\n");
	scanf("%s",numb);
	if((fp=fopen("worker.xls","rb"))==NULL)
	{
		printf("\n对不起，无法查询信息文件。");
		exit(0);
	}
	while(!feof(fp))
	{
		fscanf(fp,"%s%s%s%s%s%s%s%s%s\n",one.name,one.num,one.sex,one.position,one.wanges,one.birth,one.gread,one.add,one.pnum);
		if(!strcmp(numb,one.num))
		{
			printf("\n\n已查到，记录为：");
			printf("%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s\n",one.name,one.num,one.sex,one.position,one.wanges,one.birth,one.gread,one.add,one.pnum);
			i=1;
		}
	}
	if(!i)
	{
		printf("\n\n对不起，查无此人。");
		fclose(fp);
	}
	printf("\n\n操作完成，请按下回车继续");
	choice=getch();
	system("cls");
}
/*******************浏览模块********************/
void list()
{    int i;
     FILE *fp;
     if((fp=fopen("emp.txt","r"))==NULL)
     {     
         printf("不能打开emp文件\n");
         exit(0);
     }
     printf("姓名  基本工资 职务工资 职务津贴  绩效工资   应发工资  税 实发工资\n");
     for(i=0;fread(&emp[i],sizeof(struct emploee),1,fp)!=0;i++)
     {
          printf("%6d%6s%9s%4s%5d  %.1f  %.1f     %.1f    %.1f    %.1f   %.1f\n",i+1,emp[i].no,emp[i].name,emp[i].wage1,
                   emp[i].wage2,emp[i].wage3emp[i].wage4,emp[i].wage5,emp[i].TAXfee,emp[i].wage6);
    }
    fclose(fp);
}
/******************添加模块*******************/
void add()
{
	int choice;
	system("cls");
	if((fp=fopen("worker.xls","a"))==NULL)
	{
		printf("\n对不起，无法查询信息文件。\n\n");
		exit(0);
	}
	printf("                    *********************************\n");
	printf("                         请输入需要添加的职工信息      \n");
	printf("                    *********************************\n");
	printf("         职工号   姓名  基本工资 职务工资 职务津贴  绩效工资   应发工资  税  实发工资\n");
	scanf("%s%s%s%s%s%s%s%s%s",one.name,one.num,one.sex,one.position,one.wanges,one.birth,one.gread,one.add,one.pnum);
	fprintf(fp,"%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s\n",one.name,one.num,one.sex,one.position,one.wanges,one.birth,one.gread,one.add,one.pnum);
	fclose(fp);
	printf("\n\n操作完成，请按下回车继续");
	choice=getch();
	system("cls");
}
/*************************保存模块**********************/
void write()          //加载记录或可以计算记录个数的函数
{
     FILE *fp;
     int i,w;
     w=1;
     system( "cls" ); 
    if((fp=fopen("emp.txt","rb"))==NULL)      //以输出打开方式,在此前的记录被覆盖
    {
        printf("\nCannot open file\n");
        w=0;
        return ;
    }
    n=0;
    for(i=0;!feof(fp);i++)
    {   
        fread(&emp[i],sizeof(struct emploee),1,fp);
        n++;
    }
    n=n-1;
          fclose(fp);
    if(w==1) 
    {
        printf("Load file ok!");
        getchar();
        getchar();
        menu();                
    }
}
