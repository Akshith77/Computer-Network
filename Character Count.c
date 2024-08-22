#include <stdio.h>
#include <string.h>
void characterCountFraming(char *data) {
int length = strlen(data);
printf("***Character Count Framing***\n");
printf("Length of data: %d\n", length);
printf("Data transmitted:%s\n\n",data);
}
int main() {
char data[100];
printf("Enter data: ");
scanf("%[^\n]%*c", data);
characterCountFraming(data);
return 0;
}
}