#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
void addinfo();
void viewinfo();
void student();
 struct student
              { long long int rollno;
                char name[50];
                char gender[10];
                char region[20];
                int day;
                int month;
                int year;
                float emat;
                float ephy;
                float eche;
                float imat;
                float iphy;
                float iche;
                float emarksp;
                float imarksp;
                double eper;
                }s;

void main()
{   int i,n,j,p,q,h,temp,rank[1000],da[100],mo[100],ye[100],ch;
    long long int htno[100];
    double per[100];
    char na[50],gen[10],re[20],dab[10];
    char a,g,r,d;
    float emark[100],ema[100],eph[100],ech[100],imark[100];
    float imat;
    float iphy;
    float iche;
    float emarksp;
    float imarksp;
    double eper;

    while(ch!=3)
        {  printf("\n***************************************************************************************************************************************************************************************************************** \n");
           printf("\n*****                                                                                    WELCOME TO EAMCET RANK CALUCULATION SYSTEM PROJECT                                                                 *****\n");
           printf("\n***************************************************************************************************************************************************************************************************************** \n");
          printf("\n\n ***                                                                                                    1.Add Info                                                                                           ***\n\n");
          printf("\n\n ***                                                                                                    2.View Info                                                                                          ***\n\n");
          printf("\n\n ***                                                                                                    3.Exit                                                                                               ***\n\n");
          printf("\n\n                                                                                                =>  Enter your Choice :  ");
           scanf("%d",&ch);
       switch(ch)
       {
            case 1:
                   addinfo();
                   break;
           case 2:
                    viewinfo();
                    break;
           case 3: exit(1);
           default:
                  printf("                                                                                          Wrong Choice Entered !! Please Check Choice                                                                              ");
                     }

       getch();
    }
}
void addinfo()
{
     FILE *fp;
     int i,n,j,p,q,h,temp,rank[1000],da[100],mo[100],ye[100];
    long long int htno[100];
    double per[100];
    char a,g,r,d;
    float emark[100],ema[100],eph[100],ech[100],imark[100];
     fp=fopen("E:\\EAMCET FILE\\EAMCET.txt","a+");
     if(fp==NULL)
     {
         printf("cannot open file");
         return;
     }

      printf(" \n\n                                                                                        $$Enter the Number of Students to be Added : ");
     scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
     printf("\n                                              Enter Roll.Number  : ");
     scanf("%d",&s.rollno);
     fflush(stdin);
     printf("\n                                              Enter Student Name  :  ");
     gets(s.name);
     fflush(stdin) ;
     printf("\n                                              Enter Gender  :  ");
     gets(s.gender);
     fflush(stdin);
     printf("\n                                              Enter Region  :  ");
     gets(s.region);
     fflush(stdin);
     printf("\n                                              Enter Date of Birth(day/month/year)  :  ");
     scanf("%d-%d-%d",&s.day,&s.month,&s.year);
     fflush(stdin);
    printf("\n\n                                            Enter EAMCET Examination marks in Mathematics(80) : ");
    scanf("%f",&s.emat);
    fflush(stdin);
    printf("                                                Enter EAMCET Examination marks in Physics(40) : ");
    scanf("%f",&s.ephy);
    fflush(stdin);
    printf("                                                Enter EAMCET Examination marks in Chemistry(40) : ");
    scanf("%f",&s.eche);
    fflush(stdin);
    printf("                                               Enter IPE Examination marks in Mathematics(300) : ");
    scanf("%f",&s.imat);
    fflush(stdin);
    printf("                                         Enter IPE Examination marks in Physics(Including Practicals(150)) : ");
    scanf("%f",&s.iphy);
    fflush(stdin);
    printf("                                         Enter IPE Examination marks in Chemistry(Including Practicals(150)):");
    scanf("%f",&s.iche);
    fflush(stdin);
    p=s.emat+s.ephy+s.eche;
    q=s.imat+s.iphy+s.iche;
    s.emarksp=(p*(0.46875));
    s.imarksp=(q*(0.0416666666666));
    s.eper=s.emarksp+s.imarksp;
    per[i]=s.eper;
    htno[i]=s.rollno;
    emark[i]=s.emarksp;
    ema[i]=s.emat;
    eph[i]=s.ephy;
    ech[i]=s.eche;
    da[i]=s.day;
    mo[i]=s.month;
    ye[i]=s.year;
    }
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(per[j]>per[i])
        {   temp=per[j];
            per[j]=per[i];
            per[i]=temp;
            h=htno[j];
            htno[j]=htno[i];
            htno[i]=h;
            rank[i]=i;
            rank[j]=j;
            break;
                    }
        else if(per[j] == per[i])
            {      h=htno[j];
                  htno[j]=htno[i];
                  htno[i]=h;
                  rank[i]=i;
                  rank[j]=j;
                if (emark[j]>emark[i])
                {
                    r=rank[i];
                    rank[i]=rank[j];
                    rank[j]=r;
                    break;
                }
                else if(ema[j]>ema[i] && emark[j]==emark[i])
                {
                     r=rank[i];
                    rank[i]=rank[j];
                    rank[j]=r;
                    break;
                }
                 else if(eph[j]>eph[i] && ema[j]==ema[i] && emark[j]==emark[i])
                {
                     r=rank[i];
                    rank[i]=rank[j];
                    rank[j]=r;
                    break;
                }
                 else if(ech[j]>ech[i] && eph[j]==eph[i] && ema[j]==ema[i] && emark[j]==emark[i])
                {
                     r=rank[i];
                    rank[i]=rank[j];
                    rank[j]=r;
                    break;
                }
                 else if(imark[j]>imark[i] && ech[j]==ech[i] && eph[j]==eph[i] && ema[j]==ema[i] && emark[j]==emark[i])
                {
                     r=rank[i];
                    rank[i]=rank[j];
                    rank[j]=r;
                    break;
                }
                else if(ye[j]>ye[i] && imark[j]==imark[i] && ech[j]==ech[i] && eph[j]==eph[i] && ema[j]==ema[i] && emark[j]==emark[i])
                 {
                     r=rank[i];
                    rank[i]=rank[j];
                    rank[j]=r;
                    break;
                }
                 else if(ye[j]<ye[i] && imark[j]==imark[i] && ech[j]==ech[i] && eph[j]==eph[i] && ema[j]==ema[i] && emark[j]==emark[i])
                 {
                     r=rank[i];
                    rank[i]=rank[j];
                    rank[j]=r;
                    break;
                }
                 else if(mo[j]>mo[i] && ye[j]==ye[i] && imark[j]==imark[i] && ech[j]==ech[i] && eph[j]==eph[i] && ema[j]==ema[i] && emark[j]==emark[i])
                 {
                     r=rank[i];
                    rank[i]=rank[j];
                    rank[j]=r;
                    break;
                }
                 else if(mo[i]<mo[j] && ye[j]==ye[i] && imark[j]==imark[i] && ech[j]==ech[i] && eph[j]==eph[i] && ema[j]==ema[i] && emark[j]==emark[i])
                 {
                    r=rank[i];
                    rank[i]=rank[j];
                    rank[j]=r;
                    break;
                }
                else if(da[j]>da[i] && mo[j]==mo[i] && ye[j]==ye[i] && imark[j]==imark[i] && ech[j]==ech[i] && eph[j]==eph[i] && ema[j]==ema[i] && emark[j]==emark[i])
                 {
                     r=rank[i];
                    rank[i]=rank[j];
                    rank[j]=r;
                    break;
                }
                else
                {
                    r=rank[i];
                    rank[i]=rank[j];
                    rank[j]=r;
                }

            }
        }
        printf("\n              =>>Hall.ticket.no :%lld          \n                              =>>Rank : %d             \n                                  =>>Percentage: %lf \n\n\n",htno[i],rank[i],per[i]);
        fprintf(fp, " %lld %s %s %s %d-%d-%d %f %d ", &htno[i], &s.name, &s.gender, &s.region, &da[i], &mo[i], &ye[i], &per[i], &rank[i]);
        }


    {
       printf(" Data Stored Successfully");

    }
         fclose(fp);
     viewinfo();
}

void viewinfo()
{
    FILE *fp;
    fp = fopen("C:\\Users\\NITHIN M C\\OneDrive\\Desktop\\EAMCET RANK CALUCULATION PROGRAM\\EAMCET.txt", "r");
    char ch;
    char singleline[2000];
    while(!feof(fp))
    {
        fgets(singleline, 2000, fp);
        printf("\t\t\t\t\t\t\t\t\t %s", singleline);
    }
    fclose(fp);

}
