#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<string.h>
#include<stdlib.h>

void teacher();
void student1();
void student2();
void student3();
sem_t s;
int flag1 =0,flag2=0,flag3=0;
char a[10],b[10],c[10];
char str1[] = "pen";
char str2[] = "paper";
char str3[] = "question paper";


int main()
{
	sem_init(&s,0,1);
	pthread_t teacher_thread,student_thread;
	
	printf("\n\tSelect any 2 resorces to be kept on shared table:\n\n\t\t\t PEN\n \t\t\t PAPER\n\t\t\t QUESTION PAPER\n");
	
	while(flag1==0 || flag2==0 || flag3==0)
	{

	pthread_create(&teacher_thread,NULL,teacher,NULL);
	pthread_join(teacher_thread,NULL);
		
	
	if( ( (strcmp(str1,a)==0 && strcmp(str2,b)==0 ) || (strcmp(str1,b)==0 && strcmp(str2,a)==0 ) ) && flag1==0)
	{
		pthread_create(&student_thread,NULL,student1,NULL);
		pthread_join(student_thread,NULL);
	}
	else if( ( (strcmp(str1,a)==0 && strcmp(str3,b)==0 ) || (strcmp(str1,b)==0 && strcmp(str3,a)==0 ) ) && flag2==0)
	{
		pthread_create(&student_thread,NULL,student2,NULL);
		pthread_join(student_thread,NULL);
	}
	else if( ( (strcmp(str2,a)==0 && strcmp(str3,b)==0 ) || (strcmp(str2,b)==0 && strcmp(str3,a)==0 ) ) && flag3==0)
	{
		pthread_create(&student_thread,NULL,student3,NULL);
		pthread_join(student_thread,NULL);
	}
	else
	{
		printf("Try Again");
		}
	}
	printf("\n\t\t\tALL 3 STUDENTS COMPLETED THEIR ASSIGNMENTS.\n");
	
	
	
	
}

void teacher()
{
	sem_wait(&s);
	printf("\n1st Resource : ");
	gets(a);
	strlwr(a);
	printf("\n2nd Resorce : ");
	gets(b);
	strlwr(b);
	sem_post(&s);
	
}

void student1()//has question paper with him already,need pen and paer to execute
{
	sem_wait(&s);
	printf("Pen and Paper are selected");
	flag1=1;
	printf("\n\nStudent 1 has been allocated all resouces");
	printf("\nStudent 1 completed the assignment.\n");
	sem_post(&s);
}

void student2()//has paper with him already,need pen and question paper to execute
{
	sem_wait(&s);
	printf("Pen and Question Paper are selected");
	flag2=1;
	printf("\n\nStudent 2 has been allocated all resouces");
	printf("\nStudent 2 completed the assignment.\n");
	sem_post(&s);
}

void student3()//has pen with him already,need paper and question paper to execute
{
	sem_wait(&s);
	printf("Paper and Question Paper are selected");
	flag3=1;
	printf("\n\nStudent 3 has been allocated all resouces");
	printf("\nStudent 3 completed the assignment.\n");
	sem_post(&s);
}
