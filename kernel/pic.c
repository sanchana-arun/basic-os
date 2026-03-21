#include "port.h"

void pic_init(){

    //outb(port, data)
    outb(0x20, 0x11);
    outb(0xA0, 0x11);

    outb(0x21, 0x20);
    outb(0xA1, 0x28);
}