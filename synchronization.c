#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<string.h>

void teacher();
void student1();
void student2();
void student3();
sem_t s;
int flag1 =0;
char a[10],b[10],c[10];
char str1[] = "pen";
char str2[] = "paper";
char str3[] = "question paper";

main()
{
	sem_init(&s,0,1);
	pthread_t teacher_thread,student_thread;
	
	pthread_create(&teacher_thread,NULL,teacher,NULL);
	pthread_join(teacher_thread,NULL);
	
	
}

void teacher()
{
	sem_wait(&s);
	printf("Select 2 resources to be kept on shared table");
	printf("1st Resource : ");
	gets(a);
	strlwr(a);
	printf("2nd Resorce : ");
	gets(b);
	strlwr(b);
	sem_post(&s);
	
}

void student1()//has question paper with him already,need pen and paer to execute
{
	sem_wait(&s);
	printf("Pen and Paper are selected");
	flag1=1;
	printf("\nStudent 1 has been allocated all resouces");
	printf("\nStudent 1 completed the assignment.");
	sem_post(&s);
}

void student2()//has paper with him already,need pen and question paper to execute
{
	sem_wait(&s);
	printf("Pen and Question Paper are selected");
	flag2=1;
	printf("\nStudent 2 has been allocated all resouces");
	printf("\nStudent 2 completed the assignment.");
	sem_post(&s);
}

void student3()//has pen with him already,need paper and question paper to execute
{
	sem_wait(&s);
	printf("Paper and Question Paper are selected");
	flag3=1;
	printf("\nStudent 3 has been allocated all resouces");
	printf("\nStudent 3 completed the assignment.");
	sem_post(&s);
}
