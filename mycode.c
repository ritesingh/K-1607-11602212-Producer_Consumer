#include<semaphore.h>
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

#define len 10

sem_t full,empty;
pthread_t prod[10],cons[10];
pthread_mutex_t mutex;

int buff[len];
int count=0,i;


void *consumers(void *y)
{
  int val;
  sem_wait(&full);
  pthread_mutex_lock(&mutex);
  val=buff[--count];
  printf("Consumed item::%d\n",val);
  pthread_mutex_unlock(&mutex);
  sem_post(&empty);
  pthread_exit(NULL);
}


void *producers(void *y){
  printf("\n\nEnter the number to be produced and wait 3 sec: ");
  int val;
  scanf("%d",&val);
  sem_wait(&empty);
  pthread_mutex_lock(&mutex);
  printf("\nJust produced %d in buffer::",val);
  buff[count++]=val;
  printf("\n _____________________________________________________________________");
  printf("\n |");

  for (i=0;i<len;i++)
  {
    if(buff[i]!=0)
    printf("   %d   |",buff[i]);
  }

  pthread_mutex_unlock(&mutex);
  sem_post(&full);
  pthread_exit(NULL);
}


int main()
{
  int a,b,ch;
  sem_init(&empty,0,5);//intially 5
  sem_init(&full,0,0);//initially 0
  printf("\n\n 1.Produce\n 2.Consume\n 3.Exit\n What to do? ");
  scanf("%d",&ch);

  if(ch==1)
    {
	     printf("\nHow many items would you like to produce: ");
         scanf("%d",&a);

 	 for(i=0;i<a;i++)
 	 {
   		     pthread_create(&prod[i],NULL,producers,NULL);
    		 Sleep(3);
  	 }

	 for(i=0;i<a;i++)
 	 {
    		pthread_join(prod[i],NULL);
  	 }
            main();
     }

else if(ch==2)
  {
  	 printf("\nHow many items would you like to consume: ");
  	 scanf("%d",&b);

	 for(i=0;i<b;i++)
 	 {
  	   if(buff[0]==0)
	   {
  		 printf("\nBuffer is empty first Produce Item \n");
 		 break;
  	   }

 	   pthread_create(&cons[i],NULL,consumers,NULL);
  	   Sleep(1);
          }

  	 for(i=0;i<b;i++)
    	 {
 		 pthread_join(cons[i],NULL);
 	 }
         main();
     }
  else
    {
        exit(0);
    }

return 0;
}
