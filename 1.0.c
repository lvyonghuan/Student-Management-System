#include <stdio.h>
struct Student{
   int id;
   int score;
}student[40];
void Input(int number)//1.输入
{
   printf("Input student's ID, name and score:\n");
   for(int i=0;i<number;i++)
   {
       scanf("%d%d",&student[i].id,&student[i].score);
   }
   return;
}
void Caculate(int number)//2.求和与平均值
{
   int sum=0;
   for(int i=0;i<number;i++)
   {
       sum+=student[i].score;
   }
   printf("sum=%d,aver=%.2f\n",sum,(float )sum/(float)number);
   return;
}
void BubleSort(int number,int Case)//3,4按照成绩或学号排序
{
   for(int i=0;i<number;i++)
   {
       for(int j=i;j<number;j++)
       {
           if(Case==3&&(student[i].score< student[j].score))
           {
               struct Student temp;
               temp = student[i];
               student[i]=student[j];
               student[j]=temp;
           }
           if(Case==4&&(student[i].id>student[j].id))
           {
               struct Student temp;
               temp = student[i];
               student[i]=student[j];
               student[j]=temp;
           }
       }
   }
   if(Case==3) printf("Sort in descending order by score:\n");
   if(Case==4) printf("Sort in ascending order by number:\n");
   for(int i=0;i<number;i++)
   {
       printf("%d\t%d\n",student[i].id,student[i].score);
   }
   return;
}
void Search(int number)//按照学号查找
{
   int temp;
   printf("Input the number you want to search:\n");
   scanf("%d",&temp);
   while(number>0)
   {
       if(student[number-1].id==temp)
       {
           printf("%d\t%d\n",student[number-1].id,student[number-1].score);
           return;
       }
       number--;
   }
   printf("Not found!\n");
   return;
}
void Statistic(int n)//6.分析
{
   int count_1=0,count_2=0,count_3=0,count_4=0,count_5=0,count_6=0;
   for(int i=0;i<n;i++)
   {
       if(student[i].score<60)
       {
           count_1++;
       }
       else if(student[i].score>=60&&student[i].score<70)
       {
           count_2++;
       }
       else if(student[i].score>=70&&student[i].score<80)
       {
           count_3++;
       }
       else if(student[i].score>=80&&student[i].score<90)
       {
           count_4++;
       }
       else if(student[i].score>=90&&student[i].score<100)
       {
           count_5++;
       }
       else if(student[i].score==100)
       {
           count_6++;
       }
   }
   printf("<60\t%d\t%.2f%%\n",count_1,((float)count_1/(float)n)*100);
   printf("60-69\t%d\t%.2f%%\n",count_2,((float )count_2/(float)n)*100);
   printf("70-79\t%d\t%.2f%%\n",count_3,((float )count_3/(float )n)*100);
   printf("80-89\t%d\t%.2f%%\n",count_4,((float )count_4/(float )n)*100);
   printf("90-99\t%d\t%.2f%%\n",count_5,((float )count_5/(float )n)*100);
   printf("100\t%d\t%.2f%%\n",count_6,((float )count_6/(float )n)*100);
   return;
}
void List(int n)
{
   for(int i=0;i<n;i++)
   {
       printf("%d\t%d\n",student[i].id,student[i].score);
   }
   return;
}
int main()
{
   int number;
   printf("Input student number(n<30):\n");
   scanf("%d",&number);
   for(;;)
   {
       int choice;
       printf("Management for Students' scores\n"
              "1.Input record\n"
              "2.Caculate total and average score of course\n"
              "3.Sort in descending order by score\n"
              "4.Sort in ascending order by number\n"
              "5.Search by number\n"
              "6.Statistic analysis\n"
              "7.List record\n"
              "0.Exit\n"
              "Please Input your choice:\n");
       scanf("%d",&choice);
       if(choice==0)
       {
           printf("End of program!\n");
           break;
       }
       if(choice>7||choice<0)
       {
           printf("Input error!\n");
           continue;
       }
       switch (choice) {
           case 1:
               Input(number);
               continue;
           case 2:
               Caculate(number);
               continue;
           case 3:
               BubleSort(number,choice);
               continue;
           case 4:
               BubleSort(number,choice);
               continue;
           case 5:
               Search(number);
               continue;
           case 6:
               Statistic(number);
               continue;
           case 7:
               List(number);
               continue;
       }
   }
   return 0;
}
