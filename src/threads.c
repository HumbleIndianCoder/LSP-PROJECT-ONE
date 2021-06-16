#include"../inc/header_files.h"
#include"../inc/src_defn_files.h"

#include<pthread.h>


/* THREAD-1 */


void *mythread(void *varg) {

	sleep(10);

	printf(" MY THREAD is called \n");

	return NULL;
}


void thread_one() {


	pthread_t tid;

	printf("\n Before Thread \n");
	pthread_create(&tid, NULL, mythread, NULL);

	pthread_join(tid, NULL);

	printf("\n After Thread \n");
	

}




/* THREAD-2 */
/* Threads with static & global variables,
 * passing arguments to threads
 */

int g=0; // global variable

void *thread_2_routine(void *varg) {

	unsigned long int *pid = (unsigned long int *)varg;

	static int s=0; // static variable
	int v=0;        // local variable

	v++;
	s++;
	g++;

	printf(" \n Thread ID: %lu ; v=%d ;  s=%d ; g=%d \n", *pid, v, s, g);

	//pthread_exit(NULL);
	
	return NULL;	


}

void thread_2() {

	pthread_t tid;

	//int pass_arg = 2;

	printf("\n BEGIn \n");

	for(int i=0;i<3;i++) {
		pthread_create(&tid, NULL, thread_2_routine, (void *)&tid);
		
		//pthread_join(tid, NULL);
		//sleep(3);
	}

	pthread_exit(NULL);
	//pthread_join(tid, NULL);

	//printf("\n THE END \n");


}



/* THREAD-3 
 * example for pthread_cond_wait() & pthread_mutex_lock() 
 */

// Declaration of COND variable
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

// Declaration of MUTEX variable
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;


int done=1;
int check=0;


void *foo(void *varg) {

	unsigned long int *pid = (unsigned long int *)varg;


	// Thread needs to acquire the lock before entering the Critical Section
	pthread_mutex_lock(&lock);

	/* CRITICAL SECTION begins */
	if(done == 1) {

		done=2;
		printf("\n Conditonal wait makes this thread %lu to wait for the other thread to signal  \n", *pid);

		check = check+1;
		
		pthread_cond_wait(&cond, &lock); // this releases the lock so that the other thread can acquire it

		

	} else {

		check = check-1;
		printf("\n Signal the other thread from this thread %lu to continue its execution \n", *pid);

		pthread_cond_signal(&cond);

	}
	
	printf("\n The value of check = %d in thread %lu \n", check, *pid);

	/* CRITICAL SECTION ends */
	pthread_mutex_unlock(&lock);


	//printf("\n The value of check = %d \n", check);



	return NULL;
}


void thread_3() {

	pthread_t tid1, tid2;

	printf(" \n BEGin \n");
	pthread_create(&tid1, NULL, foo, (void *)&tid1);

	//printf(" \n Going to Sleep ...\n");
	//sleep(5);

	printf(" \n Creating 2nd thread \n");
	pthread_create(&tid2, NULL, foo, (void *)&tid2);

	printf(" \n Waiting for 2nd thread to complete \n");
	pthread_join(tid2, NULL);

}



















