#include<iostream>
#include<string>
using namespace std;
#define NUM 1000
void read();
void menu();
void find_num();
void write()
void add();
void modify_num();
void del_num();
void grsds();
void load(); 
void list()
struct emploee  //ְ�����ݽṹ
int n;      //Ա��������
{
 char no[10];
 char name[30];
 float wage1;      //Ա���Ļ�������
 float wage2;      //Ա����ְ����
 float wage3;      //Ա����ְ�����
 float wage4;   //Ա���ļ�Ч����
 float wage5;    //Ա����Ӧ������
 float TAXfee;     //Ա���ĸ�������˰
 float wage6;      //Ա����ʵ������
}emp[NUM],newemp;
void main()
{
 menu();
}
void menu()//������
{  int n,w1;
   
   do
   { system("cls");  
      printf("************* ְ�����ʹ���ϵͳ **************\n");
      printf("*            1-----����ְ����Ϣ                     *\n");
      printf("*            2-----���ְ����Ϣ                     *\n");
      printf("*            3-----�޸�ְ����Ϣ	                             *\n");
      printf("*            4-----ɾ��ְ����Ϣ             *\n");
      printf("*            5-----�˳�����                           *\n");
      printf("***************************************************\n");
  printf("       ��������ѡ��(1-9):[ ]\b\b");
  scanf("%d",&n);
  if(n<1||n>9)                                    //��ѡ����������ж�
         {
            w1=1;
            printf("your choice is not between 1 and 9,Please input again:");
            getchar();
          }
         else    w1=0;
      } 
    while(w1==1);
  switch(n)
  { case 1:search_num();    break;   
    case 2:add();   break;  
    case 3:modi_num();   break;    
    case 4:dele_num();   break;    
    case 5:count ();    break;    
    case 9:printf("\n��������������лл����ӭ�´ι��٣���������������\n\n");
    default:exit(0);  //�˳�ϵͳ,exit(0)�����������˳�����
  }
}
/*************************��ȡģ��**********************/
void read()
{
     FILE *fp;
     int n,i;
     if ((fp=fopen("emp.txt","wb"))==NULL)
     {
 
     printf("���ܽ���emp�ļ�\n");
     exit(1);
     }
     printf("����ְ������:");
    scanf("%d",&n);
     printf("�����ʽ:ְ���� ����  �������� ְ���� ְ�����  ��Ч����   Ӧ������  ˰ ʵ������<Enter>\n");
     for(i=0;i<n;i++)   /*  ѭ����ȡn��ְ����¼ */
     {
         printf("��%d��ְ��:",i+1);
         scanf("%s%s%s%d%f%f%f%f%f",emp[i].no,emp[i].name,
           &emp[i].wage1,&emp[i].wage2,&emp[i].wage3,&emp[i].wage4,&emp[i].wage5,&emp[i].&emp[i].TAXfee); emp[i].wage6=emp[i].wage1+emp[i].wage2+emp[i].wage3+emp[i].wage4+emp[i].wage5.TAXfee;
     }
     for(i=0;i<n;i++)      /*��n��ְ����¼д���ļ�*/
          fwrite(&emp[i],sizeof(struct emploee),1,fp);
     fclose(fp);
}
/*************************ͳ��ģ��**********************/
void grsds()
{
     FILE *fp;
     int n,num;
     if((fp=fopen("emp.txt","rb"))==NULL)
     {
         printf("���ܴ�emp�ļ�\n");
         exit(1);
     }
     printf("�����빤����:");
     scanf("%d",&num);
     printf("��¼�� ְ���� ���� ����  �������� ְ���� ְ�����  ��Ч����   Ӧ������  ˰ ʵ������\n");
     for(n=0;fread(&emp[n],sizeof(struct emploee),1,fp)!=0;n++)
     if(emp[n].wage3>=num)
     printf("%6d%6s%9s%4s%5d   %.1f   %.1f  %.1f   %.1f   %.1f   %.1f\n",n+1,emp[n].no,emp[n].name,emp[n].wage1,
             emp[n].wage2,emp[n].wage3,emp[n].wage4,emp[n].wage5,emp[n].TAXfee,emp[n].wage6);
     fclose(fp);
}
/********************ɾ��ģ��*******************/

void del_num()
{
     FILE *fp;
     int i,j,n;
     char num[5];
     if((fp=fopen("emp.txt","rb"))==NULL)
     {
         printf("���ܴ�emp�ļ�\n");
         exit(1);
      }
     printf("ɾ��ǰ:\n");
     printf("��¼�� ְ���� ����  �������� ְ���� ְ�����  ��Ч����   Ӧ������  ˰ ʵ������\n");
    for(n=0;fread(&emp[n],sizeof(struct emploee),1,fp);n++)
     printf("%6d%6s%9s%4s%5d   %.1f   %.1f   %.1f   %.1f   %.1f   %.1f\n",n+1,emp[n].no,emp[n].name,emp[n].wage1,emp[n].wage2,emp[n].wage3,emp[n].wage4,emp[n].wage5,
	 emp[n].TAXfee,emp[n].wage6);/*nΪemp�ļ��м�¼��*/
     printf("Ҫɾ����ְ����:");
     scanf("%s",num);
     for(i=0;(strcmp(emp[i].no,num)!=0&&i<n);i++)
     if(i>=n)
     {
          printf("\tû��%sְ���ŵ�ְ��\n",num);
          exit(2);
     }
     fclose(fp);
     fp=fopen("emp.dat","w+");
     if(n==1)  /*һ����¼�Ѿ�ɾ����*/
     {
           fclose(fp);
           exit(3);
     }
     for(j=0;j<i;j++)
        fwrite(&emp[j],sizeof(struct emploee),1,fp);
     for(j=i+1;j<n;j++)
         fwrite(&emp[j],sizeof(struct emploee),1,fp);
     printf("ɾ����:\n");
     fseek(fp,0,SEEK_SET);
     printf("��¼�� ְ���� ����  �������� ְ���� ְ�����  ��Ч����   Ӧ������  ˰ ʵ������\n");
     for(i=0;fread(&emp[i],sizeof(struct emploee),1,fp);i++)
         printf("%6d%6s%9s%4s%5d%   %.1f    %.1f   %.1f   %.1f   %.1f   %.1f\n",i+1,emp[i].no,emp[i].name,emp[i].wage1,
                 emp[i].wage2,emp[i].wage3,emp[i].wage4,emp[i].wage5,emp[i].TAXfee,emp[i].wage6);
       fclose(fp);
}
/********************�޸�ģ��*******************/
void modify _num()
{
     FILE *fp;
     int i,j;
     char num[5];
     if((fp=fopen("emp.txt","rb+"))==NULL)
     {
         printf("���� ��emp�ļ�\n");
         exit(1);
     }
     printf("Ҫ�޸ĵ�ְ����:");
     scanf("%s",num);
     for(i=0;fread(&emp[i],sizeof(struct emploee),1,fp);i++)
    if(!strcmp(emp[i].no,num))break;
     if(feof(fp))
     {
          printf("\tû��%sְ���ŵ�ְ��\n",num);
          exit(2);
     }
     printf("��¼�� ְ����   ����  �������� ְ���� ְ�����  ��Ч����   Ӧ������  ˰  ʵ������\n");
     printf("%6d%6s%9s%4s%5d%   %.1f   %.1f   %.1f   %.1f   %.1f   %.1f\n",i+1,emp[i].no,emp[i].name,emp[i].wage1,
              emp[i].wage2,emp[i].wage3,emp[i].wage4,emp[i].wage5,emp[i].TAXfee,emp[i].wage6);
    printf("�����ʽ:ְ����   ����  �������� ְ���� ְ�����  ��Ч����   Ӧ������  ˰ <Enter>\n");
    printf("��%d����¼:",i+1);
    scanf("%s%s%s%d%f%f%f%f%f",newemp.no,newemp.name,
               &newemp.wage1,&newemp.wage2,&newemp.wage3,&newemp.wage4,&newemp.wage5,&newemp.TAXfee);//��ȡ�µ�ְ����¼
             newemp.wage6=newemp.wage1+newemp.wage2+&newemp.wage3+&newemp.wage4+&newemp.wage5-newemp.TAXfee;
    fseek(fp,-(long)sizeof(struct emploee),SEEK_CUR);  //�ļ�ָ��ָ����޸ĵļ�¼��ͷ
     fwrite(&newemp,sizeof(struct emploee),1,fp);  //��newemp���ǵ�ǰ��¼
     printf(" �޸ĺ�:\n");
    fseek(fp,0,SEEK_SET);        //��ʾ�޸ĺ���ļ�����
     printf("��¼�� ְ����    ����  �������� ְ���� ְ�����  ��Ч����   Ӧ������  ˰  ʵ������\n");
     for(i=0;fread(&emp[i],sizeof(struct emploee),1,fp)!=0;i++)
         printf("%6d%6s%9s%4s%5d   %.1f   %.1f  %.1f   %.1f  %.1f   %.1f\n",i+1,emp[i].no,emp[i].name,emp[i].wage1,
                   emp[i].wage2,emp[i].wage3,emp[i].wage4,emp[i].wage5,emp[i].TAXfee,emp[i].wage6);
    fclose(fp);
}
 /*************************��ѯģ��***********************/
void find_num()
{
     FILE *fp;
     int i; 
     char num[5];
     if((fp=fopen("emp.txt","rb"))==NULL)
     {
          printf("���ܴ�emp�ļ�\n");
          exit(1);
     }
     printf("Ҫ��ѯ��ְ����:");
     scanf("%s",num);
     for(i=0;fread(&emp[i],sizeof(struct emploee),1,fp);i++)
         if(!strcmp(emp[i].no,num)) break;
    if(feof(fp))
    {
        printf("\t���޴���\n");
        exit(2);
    }
     printf("��¼�� ְ����   ����  �������� ְ���� ְ�����  ��Ч����   Ӧ������  ˰  ʵ������\n");
     printf("%6d%6s%9s%4s%5d  %.1f  %.1f  %.1f  %.1f   %.1f   %.1f\n",i+1,emp[i].no,emp[i].name,emp[i].wage1,
               emp[i].wage2,emp[i].wage3,emp[i].wage4,emp[i].wage5,emp[i].TAXfee,emp[i].wage6);
       fclose(fp);
}
/*******************���ģ��********************/
void list()
{    int i;
     FILE *fp;
     if((fp=fopen("emp.txt","r"))==NULL)
     {     
         printf("���ܴ�emp�ļ�\n");
         exit(0);
     }
     printf("��¼�� ְ����     ����  �������� ְ���� ְ�����  ��Ч����   Ӧ������  ˰ ʵ������\n");
     for(i=0;fread(&emp[i],sizeof(struct emploee),1,fp)!=0;i++)
     {
          printf("%6d%6s%9s%4s%5d  %.1f  %.1f     %.1f    %.1f    %.1f   %.1f\n",i+1,emp[i].no,emp[i].name,emp[i].wage1,
                   emp[i].wage2,emp[i].wage3emp[i].wage4,emp[i].wage5,emp[i].TAXfee,emp[i].wage6);
    }
    fclose(fp);
}
/******************���ģ��*******************/
    void add()
{
      FILE *fp;
      int n,i,j;
      if((fp=fopen("emp.txt","ab+"))==NULL)
      {
          printf("���ܴ�emp�ļ�\n");
           exit(0);
      }
    printf("Ҫ׷�ӵ�ְ������:");
      scanf("%d",&n);
      for(i=0;i<n;i++) 
      { 
          printf("�����ʽ:ְ����    ����  �������� ְ���� ְ�����  ��Ч����   Ӧ������  ˰ <Enter>\n");
         printf("׷�Ӽ�¼:\n");
         scanf("%s%s%s%d%f%f%f%f%f",newemp.no,newemp.name,
			 &newemp.wage1,&newemp.wage2,&newemp.wage3,&newemp.wage4,&newemp.wage5,&newemp.TAXfee);
             newemp.wage6=newemp.wage1+newemp.wage2+newemp.wage3+newmp.wage4+newemp.wage5-newemp.TAXfee;//��ȡһ���µ�ְ����¼
        fwrite(&newemp,sizeof(struct emploee),1,fp);   //����ְ����¼д���ļ�
      }
      fclose(fp);
}
/*************************����ģ��**********************/
void load()          //���ؼ�¼����Լ����¼�����ĺ���
{
     FILE *fp;
     int i,w;
     w=1;
     system( "cls" ); 
    if((fp=fopen("emp.txt","rb"))==NULL)      //������򿪷�ʽ,�ڴ�ǰ�ļ�¼������
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