#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void main (){
	
	
	pid_t pid , pid_hijo;

//se crea un proceso hijo, la funcion fork() devuelve:
//un valor negativo -> si se produce cualquier error
//un valor positivo (pid del hijo) -> si estamos en el proceso padre

	pid = fork();

	if(pid==0){
		fork();
	//estamos en el proceso hijo
	printf("Soy el Hijo y el nombre del alumno es Luis Angel \n");
	printf("Mi padre es el proceso: %d \n",getppid());
	}

	else
	{
	//estamos en el proceso padreg
	pid_hijo = wait(NULL);// sirve para esperar al hijo
	printf("soy el padre y mi pid es: %d \n",getpid());
	printf("mi padre es el proceso: %d \n",pid_hijo);
	}

	exit(0);
}
