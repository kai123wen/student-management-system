#include<stdio.h>
#include<stdlib.h>
#include<string.h>
    FILE *fp;
typedef struct student
{
    int p;
	char stuID[10];
	char stuName[10];
	char stuSex[10];
	int English;
	int Chinese;
	int Math;
	int C;
}STUDENT;
STUDENT stu[30];
STUDENT st;
void inputInfor();//ѧ����Ϣ����
void xiugai();//ѧ����Ϣ�޸�
void search();//ѧ���ɼ���ѯ
void fenxi();//��Ŀ����
void proSearch();//��Ŀ�ɼ���ѯ
int main()
{
    int v=0,e,n,i,j,a,b=0,h=0;
    char diret,ID[10],id[10],project[10],Project[10],x,l;
    fp=fopen("1.txt","r");
            if(fp==NULL)
            {
                printf("xasc");
                exit(0);
            }
            int ccc;
            while(1)
               {
                   ccc=fscanf(fp,"%d%s%s%s%d%d%d%d",&st.p,st.stuID,st.stuName,st.stuSex,&st.English,&st.Chinese,&st.Math,&st.C);
                   if(ccc==EOF)
                   {
                       break;
                   }
                   fseek(fp,1,SEEK_CUR);
               }
            fclose(fp);
    while (e=1)
    {
    system("cls");
    printf("*************************\n");
    printf("*                       *\n");
    if (v==0)
    printf("*     >¼��ѧ���ɼ���Ϣ *\n");
      else
    printf("*      ¼��ѧ���ɼ���Ϣ *\n");
    if (v==1)
    printf("*     >�޸�ѧ����Ϣ     *\n");
    else
    printf("*      �޸�ѧ����Ϣ     *\n");
    if (v==2)
    printf("*     >ѧ�����˳ɼ���ѯ *\n");
    else
    printf("*      ѧ�����˳ɼ���ѯ *\n");
     if (v==3)
    printf("*     >��ʦ���˳ɼ���ѯ *\n");
    else
    printf("*      ��ʦ���˳ɼ���ѯ *\n");
     if (v==4)
    printf("*     >���Ƴɼ�����     *\n");
    else
    printf("*      ���Ƴɼ�����     *\n");
    if (v==5)
    printf("*     >�˳�ϵͳ         *\n");
    else
    printf("*      �˳�ϵͳ         *\n");
    printf("*************************\n");
    diret=getch();
    if (diret==72)
    {
        v=(v-1+6)%6;
    }
    if (diret==80)
    {
      v=(v+1+6)%6;
    }
     if (diret==13)
     {
        if (v==0)
    {
        system("cls");
        printf("����ѧ������");
        scanf("%d",&n);
	inputInfor(n);//ѧ����Ϣ����
    printf("�Ƿ񷵻ز˵���Y/N");
            getchar();
            scanf("%c",&x);
            if (x=='N')
            {
                return 0;
            }
	}
        if (v==1)
        {
            system("cls");
            xiugai(ID,st.p);//ѧ����Ϣ�޸�
            printf("�Ƿ񷵻ز˵���Y/N");
            getchar();
            scanf("%c",&x);
            if (x=='N')
            {
                return 0;
            }

        }
     if (v==2)
	 {
        system("cls");
        search(id,st.p);//ѧ����Ϣ��ѯ
        printf("�Ƿ񷵻ز˵���Y/N");
        getchar();
        scanf("%c",&x);
            if (x=='N')
            {
                return 0;
            }
	  }
	  if (v==3)
	  {
        system("cls");
        start:
	  	printf("��ʦ�ɼ���ѯ\n");
		printf("�������Ŀ");
		scanf("%s",project) ;
		 if (strcmp("English",project)==0||strcmp("Chinese",project)==0||strcmp("Math",project)==0||strcmp("C",project)==0)
    {
        proSearch(project,st.p);//��Ŀ�ɼ���ѯ
    }
    else
    {

        printf("�����Ŀ����,�Ƿ��������Y/N\n");
        scanf(" %c",&l);
        if (l=='Y')
        {goto start;}
    }
		printf("�Ƿ񷵻ز˵���Y/N");
        getchar();
        scanf("%c",&x);
            if (x=='N')
            {
                return 0;
            }
	   }
	   if (v==4)
	   {
	       star:
	       system("cls");
	    printf("�������Ŀ");
		scanf("%s",Project);
      if (strcmp("English",Project)==0||strcmp("Chinese",Project)==0||strcmp("Math",Project)==0||strcmp("C",Project)==0)
    {
        fenxi(Project,st.p);//��Ŀ����
    }
    else
    {

        printf("�����Ŀ����,�Ƿ��������Y/N\n");
        scanf(" %c",&l);
        if (l=='Y')
        {goto star;}
    }
		printf("�Ƿ񷵻ز˵���Y/N");
        getchar();
        scanf("%c",&x);
            if (x=='N')
            {
                return 0;
            }
	   }
	  if (v==5)
     {
         return 0;
     }
     }
    }
}
 void xiugai(char ID[10],int n)//ѧ����Ϣ�޸�
 {
    FILE *stream;
    int a;
    stream=fopen("1.txt","r");
    if (stream==NULL)
    {
        printf("fail to open");
        exit(0);
    }
    STUDENT stu[30];
    for (a=0;a<=30;a++)
    {
        fscanf(stream,"%d%s%s%s%d%d%d%d",&stu[a].p,stu[a].stuID,stu[a].stuName,stu[a].stuSex,&stu[a].English,&stu[a].Chinese,&stu[a].Math,&stu[a].C);
        fseek(stream,1,SEEK_CUR);
    }
    //fread(&stu,sizeof(stu),i,stream);
     fclose(stream);
     start:
     printf("����ѧ��ѧ��");
     scanf("%s",ID);
int i,j,k;
char l;
for (i=0;i<n;i++)
{

    if (strcmp(stu[i].stuID,ID)==0)
    {
        system("cls");
        printf("���������");
        scanf("%d",&stu[i].p);
        printf("����ѧ��");
        scanf(" %s",stu[i].stuID);
        printf("��������");
        scanf(" %s",stu[i].stuName);
        printf("����ѧ���Ա�");
        scanf(" %s",stu[i].stuSex);
        printf("����ѧ��Ӣ��ɼ�");
        scanf("%d",&stu[i].English);
        printf("����ѧ�����ĳɼ�");
        scanf("%d",&stu[i].Chinese);
        printf("����ѧ����ѧ�ɼ�");
        scanf("%d",&stu[i].Math);
        printf("����ѧ��C���Գɼ�");
        scanf("%d",&stu[i].C);
       fp=fopen("1.txt","w+");
    if (fp==NULL)
    {
        printf("error");
    }
    else
    {
      for (k=0;k<n;k++)

    fprintf(fp,"%d\t%s\t%s\t%s\t%d\t%d\t%d\t%d\n",stu[k].p,stu[k].stuID,stu[k].stuName,stu[k].stuSex,stu[k].English,stu[k].Chinese,stu[k].Math,stu[k].C);
      }

    fclose(fp);
    }
    else
    {
       printf("����ѧ�Ŵ���,�Ƿ��������Y/N\n");
        scanf(" %c",&l);
        if (l=='Y')
        {goto start;}
          else
       {
           return 0;
       }
    }
}



}
void inputInfor(int n)//ѧ����Ϣ����
{
 int i,k;
    for (i=0;i<n;i++)
    {
        system("cls");
        printf("���������<��1��ʼ�����μ�1>");
        scanf("%d",&stu[i].p);
        printf("����ѧ��");
        scanf("%s",stu[i].stuID);
        printf("��������");
        scanf("%s",stu[i].stuName);
        printf("����ѧ���Ա�");
        scanf("%s",stu[i].stuSex);
        printf("����ѧ��Ӣ��ɼ�");
        scanf("%d",&stu[i].English);
        printf("����ѧ�����ĳɼ�");
        scanf("%d",&stu[i].Chinese);
        printf("����ѧ����ѧ�ɼ�");
        scanf("%d",&stu[i].Math);
        printf("����ѧ��C���Գɼ�");
        scanf("%d",&stu[i].C);
        fp=fopen("1.txt","w+");
    if (fp==NULL)
    {
        printf("error");
    }
    else
    {
      for (k=0;k<n;k++)
      {
    fprintf(fp,"%d\t%s\t%s\t%s\t%d\t%d\t%d\t%d\n",stu[k].p,stu[k].stuID,stu[k].stuName,stu[k].stuSex,stu[k].English,stu[k].Chinese,stu[k].Math,stu[k].C);
      }

    fclose(fp);
    }
    }
}
void search(char id[10],int n)//ѧ����Ϣ��ѯ
{

    int i,j,a=1,b=1,c=1,d=1,x,y,z;
    char l;
    FILE *stream;
    int g;
    stream=fopen("1.txt","r");
    if (stream==NULL)
    {
        printf("fail to open");
        exit(0);
    }
    STUDENT stu[30];
    for (g=0;g<=30;g++)
    {
        fscanf(stream,"%d%s%s%s%d%d%d%d",&stu[g].p,stu[g].stuID,stu[g].stuName,stu[g].stuSex,&stu[g].English,&stu[g].Chinese,&stu[g].Math,&stu[g].C);
        fseek(stream,1,SEEK_CUR);
    }
    //fread(&stu,sizeof(stu),i,stream);
     fclose(stream);
     start:
       printf("ѧ�����˳ɼ���ѯ\n");
        printf("������ѧ��ѧ��");
        scanf("%s",id);
    for (i=0;i<n;i++)
   {
    if (strcmp(stu[i].stuID,id)==0)
    {
        break;
    }
    if (strcmp(stu[i].stuID,id)!=0)
    {
        printf("����ѧ�Ŵ���,�Ƿ��������Y/N\n");
        scanf(" %c",&l);
        if (l=='Y')
        {goto start;}
          else
       {
           return 0;
       }
    }
   }
   for (j=0;j<n;j++)
   {
       if (stu[j].English>stu[i].English)
       {
           a++;
       }
   }
   for (x=0;x<n;x++)
   {
       if (stu[x].Chinese>stu[i].Chinese)
       {
           b++;
       }
   }
   for (y=0;y<n;y++)
   {
       if (stu[y].Math>stu[i].Math)
       {
           c++;
       }
   }
   for (z=0;z<n;z++)
   {
       if (stu[z].C>stu[i].C)
       {
           d++;
       }
   }
       printf("%d\n",stu[i].English);
       printf("%d\n",stu[i].Chinese);
       printf("%d\n",stu[i].Math);
       printf("%d\n",stu[i].C);
       printf("Ӣ��������%d\n",a);
       printf("����������%d\n",b);
       printf("��ѧ������%d\n",c);
       printf("C����������%d\n",d);
   }
void proSearch(char project[10],int n)//��Ŀ�ɼ���ѯ
{
    int i;
    FILE *stream;
    int a;
    stream=fopen("1.txt","r");
    if (stream==NULL)
    {
        printf("fail to open");
        exit(0);
    }
    STUDENT stu[30];
    for (a=0;a<=30;a++)
    {
        fscanf(stream,"%d%s%s%s%d%d%d%d",&stu[a].p,stu[a].stuID,stu[a].stuName,stu[a].stuSex,&stu[a].English,&stu[a].Chinese,&stu[a].Math,&stu[a].C);
        fseek(stream,1,SEEK_CUR);
    }
    //fread(&stu,sizeof(stu),i,stream);
           fclose(stream);
    if (strcmp("English",project)==0)
    {
           for (i=0;i<n;i++)
           {
               printf("%s:%d\n",stu[i].stuName,stu[i].English);
           }
    }
    else if (strcmp("Chinese",project)==0)
    {
           for (i=0;i<n;i++)
           {
               printf("%s:%d\n",stu[i].stuName,stu[i].Chinese);
           }
    }
    else if (strcmp("Math",project)==0)
    {
           for (i=0;i<n;i++)
           {
               printf("%s:%d\n",stu[i].stuName,stu[i].Math);
           }
    }
    else if (strcmp("C",project)==0)
    {
           for (i=0;i<n;i++)
           {
               printf("%s:%d\n",stu[i].stuName,stu[i].C);
           }
    }
    else {
            printf("�����Ŀ����\n");
         }
}
void fenxi(char Project[10],int n)//��Ŀ����
{
      FILE *stream;
    int a,i,e,ch,m,c,x,y,z,h,x1,y1,z1,h1;
    stream=fopen("1.txt","r");
    if (stream==NULL)
    {
        printf("fail to open");
        exit(0);
    }
    STUDENT stu[30];
    for (a=0;a<=30;a++)
    {
        fscanf(stream,"%d%s%s%s%d%d%d%d",&stu[a].p,stu[a].stuID,stu[a].stuName,stu[a].stuSex,&stu[a].English,&stu[a].Chinese,&stu[a].Math,&stu[a].C);
        fseek(stream,1,SEEK_CUR);
    }
    //fread(&stu,sizeof(stu),i,stream);
           fclose(stream);
    if (strcmp("English",Project)==0)
    {
           printf("������Ӣ��ɼ������");
           scanf("%d",&e);
           printf("������ѧ��\n");
           for (x=0;x<n;x++)
           {
               if (stu[x].English<e)
               {
                 printf("%s:%d\n",stu[x].stuName,stu[x].English) ;
               }
           }
           printf("����ѧ��\n");
           for (x1=0;x1<n;x1++)
           {
               if (stu[x1].English>=e)
               {
                 printf("%s:%d\n",stu[x1].stuName,stu[x1].English) ;
               }
           }

    }
        else if (strcmp("Chinese",Project)==0)
    {
           printf("���������ĳɼ������");
           scanf("%d",&ch);
           printf("������ѧ��\n");
           for (y=0;y<n;y++)
           {
               if (stu[y].Chinese<ch)
               {
                 printf("%s:%d\n",stu[y].stuName,stu[y].Chinese) ;
               }
           }
           printf("����ѧ��\n");
           for (y1=0;y1<n;y1++)
           {
               if (stu[y1].Chinese>=ch)
               {
                 printf("%s:%d\n",stu[y1].stuName,stu[y1].Chinese) ;
               }
           }

    }
    else if (strcmp("Math",Project)==0)
    {
           printf("��������ѧ�ɼ������");
           scanf("%d",&m);
           printf("������ѧ��\n");
           for (z=0;z<n;z++)
           {
               if (stu[z].Math<m)
               {
                 printf("%s:%d\n",stu[z].stuName,stu[z].Math) ;
               }
           }
           printf("����ѧ��\n");
           for (z1=0;z1<n;z1++)
           {
               if (stu[z1].Math>=m)
               {
                 printf("%s:%d\n",stu[z1].stuName,stu[z1].Math) ;
               }
           }

    }
    else  if (strcmp("C",Project)==0)
    {
           printf("��������ѧ�ɼ������");
           scanf("%d",&c);
           printf("������ѧ��\n");
           for (h=0;h<n;h++)
           {
               if (stu[h].C<c)
               {
                 printf("%s:%d\n",stu[h].stuName,stu[h].C) ;
               }
           }
           printf("����ѧ��\n");
           for (h1=0;h1<n;h1++)
           {
               if (stu[h1].C>=c)
               {
                 printf("%s:%d\n",stu[h1].stuName,stu[h1].C) ;
               }
           }

    }
}
