#include "mbed.h"
#include <cstdio>

InterruptIn buttn(PC_13);

DigitalOut led1(LED1);
DigitalOut led2(LED2);

Thread th1;
Thread th2;

void thread1(){
    while(1){
        led1 = !led1;
        printf("LED1 ON \r\n");
        ThisThread::sleep_for(2s);
    }
}
void thread2(){
    while(1){
        led2 = !led2;
        printf("LED2 ON \r\n");
        ThisThread::sleep_for(5s);
    }
}

int main(){

    th1.start(thread1);

    while(1){
        printf("LED1 ON %d \r\n", th1.get_state());
        ThisThread::sleep_for(2s);
        
    
    th2.start(thread2);

    while(1){
        printf("LED2 ON %d \r\n", th2.get_state());
        ThisThread::sleep_for(5s);
        
    }

    }
}

