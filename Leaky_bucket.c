#include <stdio.h>
#include <unistd.h>
#define MAX_PACKET_SIZE 100
#define BUCKET_SIZE 500
#define OUTPUT_RATE 50
struct LeakyBucket {
int bucket_size;
int output_rate;
int content;
};
void leaky_bucket_init(struct LeakyBucket lb, int bucket_size, int output_rate) {
lb.bucket_size = bucket_size;
lb.output_rate = output_rate;
lb.content = 0;

}
void leaky_bucket_input(struct LeakyBucket lb, int packet_size) {
if ((lb.content + packet_size) > lb.bucket_size) {
printf("Bucket Overflow\n");
} else {
lb.content += packet_size;
}
}
void leaky_bucket_output(struct LeakyBucket lb) {
if (lb.content < lb.output_rate) {
printf("Bucket Underflow\n");
} else {
printf("Packet of size %d sent\n", lb.output_rate);
lb.content -= lb.output_rate;
}
}
int main() {
struct LeakyBucket lb;
int packets[] = {50, 100, 150, 200, 250};
int i;
leaky_bucket_init(lb, BUCKET_SIZE, OUTPUT_RATE);
for (i = 0; i < 5; i++) {
usleep(1000000); // Simulating time
printf("\nIncoming packet size: %d\n", packets[i]);
leaky_bucket_input(lb, packets[i]);
printf("Bucket content: %d\n", lb.content);
leaky_bucket_output(lb);
printf("After outgoing, bucket content: %d\n", lb.content);
}
return 0;
}