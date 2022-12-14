#include <stdio.h>
#include <string.h>
struct Student{
    int id;
    char name[11];
    int score[8];
    int sum;
    float avr;
}student[40];
int number,course;
void Swap(int i,int j);//交换结构体
int Sum(int i);//求和
/* 通用型函数↑  功能分治函数↓*/
void Input();//输入模块
void Caculate(int Case);//计算模块
void BubleSort(int Case);//排序模块
void Search(int choice);//搜索模块
void Statistic();//分析模块
void List();//列举模块
int main()
{
    printf("Input student number(n<=30):\n");
    scanf("%d",&number);
    for(;;)
    {
        int choice;
        printf("Management for Students' scores\n"
               "1.Input record\n"
               "2.Caculate total and average score of every course\n"
               "3.Caculate total and average score of every student\n"
               "4.Sort in descending order by score\n"
               "5.Sort in ascending order by score\n"
               "6.Sort in ascending order by number\n"
               "7.Sort in dictionary order by name\n"
               "8.Search by number\n"
               "9.Search by name\n"
               "10.Statistic analysis\n"
               "11.List record\n"
               "0.Exit\n"
               "Please Input your choice:\n");
        scanf("%d",&choice);
        if(choice==0)
        {
            printf("End of program!\n");
            break;
        }
        if(choice>11||choice<0)
        {
            printf("Input error!\n");
            continue;
        }
        switch (choice) {
            case 1://输入
                Input();
                continue;
            case 2://计算总和平均（各科）
                Caculate(choice);
                continue;
            case 3://计算综合平均（按学生来）
                Caculate(choice);
                continue;
            case 4://成绩降序
                BubleSort(choice);
                continue;
            case 5://成绩升序
                BubleSort(choice);
                continue;
            case 6://学号排序，小号在上
                BubleSort(choice);
                continue;
            case 7://字典顺序
                BubleSort(choice);
                continue;
            case 8://按学号查找
                Search(choice);
                continue;
            case 9://按名字查找
                Search(choice);
                continue;
            case 10://分析
                Statistic();
                continue;
            case 11://列出所有
                List();
                continue;
        }
    }
    return 0;
}
void Swap(int i,int j)//用在冒泡里的交换函数
{
    struct Student temp;
    temp = student[i];
    student[i]=student[j];
    student[j]=temp;
    return;
}
int Sum(int k)
{
    int sum=0;
    for(int i=0;i<number;i++)
    {
        sum+=student[i].score[k];
    }
    return sum;
}
void Input()//1.输入
{
    printf("Input course number(m<=6):\n");
    scanf("%d",&course);
    printf("Input student's ID, name and score:\n");
    for(int i=0;i<number;i++)
    {
        scanf("%d",&student[i].id);
        scanf("%s",student[i].name);
        for(int j=0;j<course;j++)
        {
            scanf("%d",&student[i].score[j]);
            student[i].sum+= student[i].score[j];
            student[i].avr=(float) student[i].sum / (float) course;
        }
    }
    return;
}
void Caculate(int Case)//2,3.求和与平均值
{
    int sum;
    if(Case==2)
    {
        for (int i = 0; i < course; i++)
        {
            sum = Sum(i);
            printf("course %d:sum=%d,aver=%.0f\n", i + 1, sum, (float) sum / (float) number);
        }
    }
    else if(Case==3)
    {
        for(int i=0;i<number;i++)
        {
            printf("student %d: sum=%d,aver=%.0f\n", i + 1, student[i].sum, student[i].avr);
        }
    }
    return;
}
void BubleSort(int Case)//4,5,6,7按照成绩或学号排序,字典顺序排序
{
    for(int i=0;i<number;i++)
    {
        for(int j=i;j<number;j++)
        {
            if(Case==4&&(student[i].sum< student[j].sum))
            {
                Swap(i,j);
            }
            if(Case==5&&(student[i].sum>student[j].sum))
            {
                Swap(i,j);
            }
            if(Case==6&&(student[i].id>student[j].id))
            {
                Swap(i,j);
            }
            if(Case==7)
            {
                if (strcmp(student[i].name, student[j].name) > 0)
                {
                    Swap(i, j);
                }
            }
        }
    }
    if(Case==4) printf("Sort in descending order by score:\n");
    if(Case==5) printf("Sort in ascending order by score:\n");
    if(Case==6) printf("Sort in ascending order by number:\n");
    if(Case==7) printf("Sort in dictionary order by name:\n");
    for(int i=0;i<number;i++)
    {
        printf("%d\t%s\t",student[i].id,student[i].name);
        for(int j=0;j<course;j++)
        {
            printf("%d\t",student[i].score[j]);
        }
        printf("%d\t%.0f\n",student[i].sum,student[i].avr);
    }
    return;
}
void Search(int Case)//按照学号查找,姓名查找
{
    int temp_id;
    char temp_name[11];
    if(Case==8)
    {
        printf("Input the number you want to search:\n");
        scanf("%d",&temp_id);
    }
    else if(Case==9)
    {
        printf("Input the name you want to search:\n");
        scanf("%s",temp_name);
    }
    for(int k=0;k<number;k++)
    {
        if(Case==8&&student[k].id == temp_id)
        {
            printf("%d\t%s\t",student[k].id,student[k].name);
            for(int j=0;j<course;j++)
            {
                printf("%d\t",student[k].score[j]);
            }
            printf("%d\t%.0f\n",student[k].sum,student[k].avr);
            return;
        }
        else if(Case==9)
        {
            int str1=strlen(temp_name),str2=strlen(student[k].name);
            int flag=1;
            for(int i=0;i< str1&&i< str2;i++)
            {
                if(temp_name[i]!=student[k].name[i])
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
            {
                printf("%d\t%s\t",student[k].id,student[k].name);
                for(int j=0;j<course;j++)
                {
                    printf("%d\t",student[k].score[j]);
                }
                printf("%d\t%.0f\n",student[k].sum,student[k].avr);
                return;
            }
        }
    }
    printf("Not found!\n");
    return;
}
void Statistic()//9.分析
{
    int count_1[8]={0},count_2[8]={0},count_3[8]={0},count_4[8]={0},count_5[8]={0},count_6[8]={0};//更优解显然是二维数组，，，懒得改了
    for(int j=0;j<course;j++)
    {
        for(int i=0;i<number;i++)
        {
            if(student[i].score[j]<60)
            {
                count_1[j]++;
            }
            else if(student[i].score[j]>=60&&student[i].score[j]<70)
            {
                count_2[j]++;
            }
            else if(student[i].score[j]>=70&&student[i].score[j]<80)
            {
                count_3[j]++;
            }
            else if(student[i].score[j]>=80&&student[i].score[j]<90)
            {
                count_4[j]++;
            }
            else if(student[i].score[j]>=90&&student[i].score[j]<100)
            {
                count_5[j]++;
            }
            else if(student[i].score[j]==100)
            {
                count_6[j]++;
            }
        }
    }
    for(int i=0;i<course;i++)
    {
        printf("For course %d:\n",i+1);
        printf("<60\t%d\t%.2f%%\n",count_1[i],((float)count_1[i]/(float)number)*100);
        printf("60-69\t%d\t%.2f%%\n",count_2[i],((float )count_2[i]/(float)number)*100);
        printf("70-79\t%d\t%.2f%%\n",count_3[i],((float )count_3[i]/(float )number)*100);
        printf("80-89\t%d\t%.2f%%\n",count_4[i],((float )count_4[i]/(float )number)*100);
        printf("90-99\t%d\t%.2f%%\n",count_5[i],((float )count_5[i]/(float )number)*100);
        printf("100\t%d\t%.2f%%\n",count_6[i],((float )count_6[i]/(float )number)*100);
    }
    return;
}
void List()
{
    for(int i=0;i<number;i++)
    {
        printf("%d\t%s\t",student[i].id,student[i].name);
        for(int j=0;j<course;j++)
        {
            printf("%d\t",student[i].score[j]);
        }
        printf("%d\t%.0f\n",student[i].sum,student[i].avr);
    }
    return;
}