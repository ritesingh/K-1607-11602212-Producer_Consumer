# K-1607-11602212-Producer_Consumer
CSE-316(Simulation Based Project): Programming Solution to Bounded-Buffer Problem. I have used standard counting semaphores
empty, full for counting the empty and full slots in the buffer. A mutex lock is used rather than a binary semaphore for obtaining mutual 
exclusion.
There are two threads Producer and Consumer where Producer adds an item to the buffer and Consumer obtains an item from the buffer. This 
programming solution has been done for a Linux platform using thread library and will require the same to compile it successfully. Rather 
than automating the producer thread to produce data on its own using some random numbers, I have made the code user friendly where the 
user is asked to enter the data to be produced and than the amount of data to be consumed recursively. The number of calls to the producer 
and the consumer threads completely depends on the user. Main objective of this project is to achieve process synchronization such that 
both the consumer and producer threads may work exclusively in harmony.
