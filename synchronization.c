#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<string.h>

void teacher();
void student1();
void student2();
void student3();
sem_t s;
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
