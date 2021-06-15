#include"../inc/header_files.h"
#include"../inc/src_defn_files.h"

#include<pthread.h>


void *worker_thread(void *arg) {

	pthread_exit((void *)911);

}

int main() {


	int status;
	pthread_t tid;

	pthread_create(&tid, NULL, worker_thread, NULL); // creates the worker thread

	pthread_join(tid, (void **)&status); // wait tills the worker thread execution is completed

	printf("\n status returned = %d \n", status);


	return 0;
}
