#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int child, shmid, i;
    char *shmptr;

    child = fork();

    if (child == 0) { // Child Process
        shmid = shmget(2041, 32, 0666 | IPC_CREAT);
        shmptr = (char *)shmat(shmid, NULL, 0);

        printf("\nPARENT WRITING:\n");
        for (i = 0; i < 10; i++) {
            shmptr[i] = 'a' + i;
            putchar(shmptr[i]);
        }
        shmptr[i] = '\0'; // Null terminate the string
        printf("\n\n%s\n", shmptr);
        wait(NULL); // Wait for child process
    } 
    else { // Parent Process
        sleep(1); // Ensure child writes first
        shmid = shmget(2041, 32, 0666);
        shmptr = (char *)shmat(shmid, NULL, 0);

        printf("\nCHILD IS READING:\n");
        for (i = 0; i < 10; i++) {
            putchar(shmptr[i]);
        }

        shmdt(shmptr); // Detach shared memory
        shmctl(shmid, IPC_RMID, NULL); // Remove shared memory
    }

    return 0;
}

