static inline unsigned char inb(unsigned short port){
    unsigned char to_catch;
    __asm__ volatile("inb %1, %0" : ="a"(to_catch) :"Nd"(port));
    return to_catch;
};

static inline void outb(unsigned short port, unsigned char data){
    __asm__ volatile("outb %0, %1" : : "a"(data), "Nd"(port) );
};