# K-1607-11602212-Producer_Consumer
CSE-316(Simulation Based Project): Programming Solution to Bounded-Buffer Problem. I have used standard counting semaphores
empty, full for counting the empty and full slots in the buffer. A mutex lock is used rather than a binary semaphore for obtaining mutual exclusion.
There are two threads Producer and Consumer where Producer adds an item to the buffer and Consumer obtains an item from the
buffer. This programming solution has been done for a linux platform using thread library and will require the same to compile
it successfully. The main objective of this project is to achieve process synchronization such that both the consumer and producer threads may work exclusively in harmony.

