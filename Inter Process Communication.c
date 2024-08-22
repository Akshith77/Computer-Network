#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
struct msg_buffer {
long msg_type;
char msg_text[100];
};
int main() {
pid_t pid;
key_t key;
int msgid;
struct msg_buffer message;
key = ftok("/tmp", 'a');
msgid = msgget(key, 0666 | IPC_CREAT);
if (msgid == -1) {
perror("msgget");
exit(1);
}
pid = fork();
if (pid < 0) {
perror("fork");
exit(1);
}
if (pid == 0) {
printf("Receiver process (PID: %d) waiting for message...\n", getpid());
msgrcv(msgid, &message, sizeof(message), 1, 0);
printf("Received message: %s\n", message.msg_text);
msgctl(msgid, IPC_RMID, NULL);
printf("Message queue removed.\n");
exit(0);
}
else {
printf("Sender process (PID: %d) sending message...\n", getpid());
message.msg_type = 1;
strcpy(message.msg_text, "Hello from sender!");
msgsnd(msgid, &message, sizeof(message), 0);
printf("Message sent.\n");
}
return 0;
}