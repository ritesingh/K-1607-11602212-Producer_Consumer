//A Completely menu driven program for bounded buffer problem, 11602212-Ritesh Singh.
#include<semaphore.h>
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define len 10

sem_t full,empty; //standard semaphore variables
pthread_t prod[10],cons[10];
pthread_mutex_t mutex; //mutex lock

int buff[len];
int count=0;


void *consumers(void *y)
{
  int val;
  sem_wait(&full);
  pthread_mutex_lock(&mutex);
  val=buff[--count];
  buff[count+1]=0;
  printf("Consumed item::%d\n",val);
  pthread_mutex_unlock(&mutex);
  sem_post(&empty);
  pthread_exit(NULL);
}


void *producers(void *y)
{
  printf("\n\nEnter the number to be produced and wait 3 sec: ");
  int val;
  scanf("%d",&val);
  sem_wait(&empty);
  pthread_mutex_lock(&mutex);
  printf("\nJust produced %d in buffer::",val);
  buff[count++]=val;

  printf("\n _____________________________________________________________________");
  printf("\n |");
  for (int n=0; n<len; n++)
  {
     if(buff[n]!=0)
     printf("   %d   |",buff[n]);
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

  while(1)
  {
  	printf("\n\n 1.Produce\n 2.Consume\n 3.Exit\n What to do? ");
  	scanf("%d",&ch);
  	switch(ch)
  	{
  	   case 1: {

	 			 printf("\nHow many items would you like to produce: ");
         			 scanf("%d",&a);

 	 			 for(int i=0;i<a;i++)
 	 			 {
   		 			pthread_create(&prod[i],NULL,producers,NULL);
    		 			sleep(3);
  				  }

	 			 for(int i=0;i<a;i++)
 	 			 {
    					pthread_join(prod[i],NULL);
  			          }

               }break;


	   case 2:    {

  	 			   printf("\nHow many items would you like to consume: ");
  	 			   scanf("%d",&b);

			           for(int i=0;i<b;i++)
 	 			   {
  	  				 if(count==0)
	  				 {
 		 			  printf("\nBuffer is empty first Produce Item \n");
 					  break;
  	  				 }



					 pthread_create(&cons[0],NULL,consumers,NULL);
  	   				 sleep(1);
          			   }

 			           for(int i=0;i<b;i++)
    	 			   {
 		 			pthread_join(cons[0],NULL);
 	 			   }

    		       }break;
 case 3:
   			 {
 				 exit(0);
   			 }break;

         }//end of switch
      }//end of while

return 0;

}//end of main function

