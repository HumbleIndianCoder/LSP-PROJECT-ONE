#include"../inc/header_files.h"
#include"../inc/src_defn_files.h"

#include<pthread.h>

/*1a
void *worker_thread(void *arg) {

	pthread_exit((void *)911);

}
1a*/

int main() {


	

	/*1a
	int status;
	pthread_t tid;

	
	pthread_create(&tid, NULL, worker_thread, NULL); // creates the worker thread

	pthread_join(tid, (void **)&status); // wait tills the worker thread execution is completed

	printf("\n status returned = %d \n", status);

	1a*/



	//thread_one();

	//thread_2();
	
	thread_3();




	return 0;
}
