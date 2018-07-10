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
void inputInfor();//学生信息输入
void xiugai();//学生信息修改
void search();//学生成绩查询
void fenxi();//科目分析
void proSearch();//科目成绩查询
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
    printf("*     >录入学生成绩信息 *\n");
      else
    printf("*      录入学生成绩信息 *\n");
    if (v==1)
    printf("*     >修改学生信息     *\n");
    else
    printf("*      修改学生信息     *\n");
    if (v==2)
    printf("*     >学生本人成绩查询 *\n");
    else
    printf("*      学生本人成绩查询 *\n");
     if (v==3)
    printf("*     >教师本人成绩查询 *\n");
    else
    printf("*      教师本人成绩查询 *\n");
     if (v==4)
    printf("*     >各科成绩分析     *\n");
    else
    printf("*      各科成绩分析     *\n");
    if (v==5)
    printf("*     >退出系统         *\n");
    else
    printf("*      退出系统         *\n");
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
        printf("输入学生人数");
        scanf("%d",&n);
	inputInfor(n);//学生信息输入
    printf("是否返回菜单？Y/N");
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
            xiugai(ID,st.p);//学生信息修改
            printf("是否返回菜单？Y/N");
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
        search(id,st.p);//学生信息查询
        printf("是否返回菜单？Y/N");
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
	  	printf("教师成绩查询\n");
		printf("请输入科目");
		scanf("%s",project) ;
		 if (strcmp("English",project)==0||strcmp("Chinese",project)==0||strcmp("Math",project)==0||strcmp("C",project)==0)
    {
        proSearch(project,st.p);//科目成绩查询
    }
    else
    {

        printf("输入科目错误,是否继续输入Y/N\n");
        scanf(" %c",&l);
        if (l=='Y')
        {goto start;}
    }
		printf("是否返回菜单？Y/N");
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
	    printf("请输入科目");
		scanf("%s",Project);
      if (strcmp("English",Project)==0||strcmp("Chinese",Project)==0||strcmp("Math",Project)==0||strcmp("C",Project)==0)
    {
        fenxi(Project,st.p);//科目分析
    }
    else
    {

        printf("输入科目错误,是否继续输入Y/N\n");
        scanf(" %c",&l);
        if (l=='Y')
        {goto star;}
    }
		printf("是否返回菜单？Y/N");
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
 void xiugai(char ID[10],int n)//学生信息修改
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
     printf("输入学生学号");
     scanf("%s",ID);
int i,j,k;
char l;
for (i=0;i<n;i++)
{

    if (strcmp(stu[i].stuID,ID)==0)
    {
        system("cls");
        printf("请输入序号");
        scanf("%d",&stu[i].p);
        printf("输入学号");
        scanf(" %s",stu[i].stuID);
        printf("输入姓名");
        scanf(" %s",stu[i].stuName);
        printf("输入学生性别");
        scanf(" %s",stu[i].stuSex);
        printf("输入学生英语成绩");
        scanf("%d",&stu[i].English);
        printf("输入学生语文成绩");
        scanf("%d",&stu[i].Chinese);
        printf("输入学生数学成绩");
        scanf("%d",&stu[i].Math);
        printf("输入学生C语言成绩");
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
       printf("输入学号错误,是否继续输入Y/N\n");
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
void inputInfor(int n)//学生信息输入
{
 int i,k;
    for (i=0;i<n;i++)
    {
        system("cls");
        printf("请输入序号<从1开始，依次加1>");
        scanf("%d",&stu[i].p);
        printf("输入学号");
        scanf("%s",stu[i].stuID);
        printf("输入姓名");
        scanf("%s",stu[i].stuName);
        printf("输入学生性别");
        scanf("%s",stu[i].stuSex);
        printf("输入学生英语成绩");
        scanf("%d",&stu[i].English);
        printf("输入学生语文成绩");
        scanf("%d",&stu[i].Chinese);
        printf("输入学生数学成绩");
        scanf("%d",&stu[i].Math);
        printf("输入学生C语言成绩");
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
void search(char id[10],int n)//学生信息查询
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
       printf("学生本人成绩查询\n");
        printf("请输入学生学号");
        scanf("%s",id);
    for (i=0;i<n;i++)
   {
    if (strcmp(stu[i].stuID,id)==0)
    {
        break;
    }
    if (strcmp(stu[i].stuID,id)!=0)
    {
        printf("输入学号错误,是否继续输入Y/N\n");
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
       printf("英语排名：%d\n",a);
       printf("语文排名：%d\n",b);
       printf("数学排名：%d\n",c);
       printf("C语言排名：%d\n",d);
   }
void proSearch(char project[10],int n)//科目成绩查询
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
            printf("输入科目错误\n");
         }
}
void fenxi(char Project[10],int n)//科目分析
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
           printf("请输入英语成绩及格分");
           scanf("%d",&e);
           printf("不及格学生\n");
           for (x=0;x<n;x++)
           {
               if (stu[x].English<e)
               {
                 printf("%s:%d\n",stu[x].stuName,stu[x].English) ;
               }
           }
           printf("及格学生\n");
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
           printf("请输入语文成绩及格分");
           scanf("%d",&ch);
           printf("不及格学生\n");
           for (y=0;y<n;y++)
           {
               if (stu[y].Chinese<ch)
               {
                 printf("%s:%d\n",stu[y].stuName,stu[y].Chinese) ;
               }
           }
           printf("及格学生\n");
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
           printf("请输入数学成绩及格分");
           scanf("%d",&m);
           printf("不及格学生\n");
           for (z=0;z<n;z++)
           {
               if (stu[z].Math<m)
               {
                 printf("%s:%d\n",stu[z].stuName,stu[z].Math) ;
               }
           }
           printf("及格学生\n");
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
           printf("请输入数学成绩及格分");
           scanf("%d",&c);
           printf("不及格学生\n");
           for (h=0;h<n;h++)
           {
               if (stu[h].C<c)
               {
                 printf("%s:%d\n",stu[h].stuName,stu[h].C) ;
               }
           }
           printf("及格学生\n");
           for (h1=0;h1<n;h1++)
           {
               if (stu[h1].C>=c)
               {
                 printf("%s:%d\n",stu[h1].stuName,stu[h1].C) ;
               }
           }

    }
}
