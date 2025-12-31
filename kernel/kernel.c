void dummy_test_entrypoint() {
}

//experimenting
unsigned int seed = 123456789;
int rand() {
    seed = seed * 1103515245+12345;
    return (unsigned int)(seed/65536) % 32768;
}

// char* video_memory =(char*) (0xb8000 + 320);
// char* memory = (char*) (0xb8000 + 1920);
//so here since im having to manually calculate the cursor point, 
//i will attempt to attempt to make it handle text scrolling without overwriting into memory
// *video_memory = 'X';

// volatile char* video_memory = (volatile char*) 0xb8000;
#define VIDEO_MEMORY ((volatile char*) 0xb8000)

int cursor_x = 0;
int cursor_y = 0;
//addition more
int test_var = 0;
#define VGA_WIDTH 80
#define VGA_HEIGHT 25

void terminal_clear(){
    for(int i = 0; i < VGA_WIDTH * VGA_HEIGHT * 2; i += 2){
        VIDEO_MEMORY[i] = ' ';
        VIDEO_MEMORY[i + 1] = 0x0f;
    }
    cursor_x = 0;
    cursor_y = 0;
}

//to find where bios left off
void terminal_scroll(){
    for(int i = 0; i < (VGA_HEIGHT - 1) * VGA_WIDTH * 2; i++){
        VIDEO_MEMORY[i] = VIDEO_MEMORY[i + VGA_WIDTH * 2];
    }

    for (int i = (VGA_HEIGHT - 1) * VGA_WIDTH * 2; i < VGA_HEIGHT * VGA_WIDTH * 2; i += 2) {
        VIDEO_MEMORY[i] = ' ';
        VIDEO_MEMORY[i + 1] = 0x0f;
    }
}

void init_video(){
    int last_char_index = 0;

    for (int i = 0; i < VGA_WIDTH * VGA_HEIGHT; i++) {

        if (VIDEO_MEMORY[i*2] != 0 && VIDEO_MEMORY[i*2] != ' ') {
            last_char_index = i;
        }
    }

    cursor_x = 0;
    cursor_y = (last_char_index / VGA_WIDTH) + 1;

    if (cursor_y >= VGA_HEIGHT) {
        terminal_scroll();
        cursor_y = VGA_HEIGHT - 1;
    }
}

void terminal_putc(char c){
    if(c == '\n'){
        cursor_x = 0;
        cursor_y++;
    }
    else{
        int offset = (cursor_y * VGA_WIDTH + cursor_x) * 2;
        VIDEO_MEMORY[offset] = c;
        VIDEO_MEMORY[offset + 1] = 0x0f;
        cursor_x++;
    }

    if (cursor_x >= VGA_WIDTH) {
        cursor_x = 0;
        cursor_y++;
    }

    if (cursor_y >= VGA_HEIGHT) {
        terminal_scroll();
        cursor_y = VGA_HEIGHT - 1;
    }
}

void terminal_write(char* data) {
    int i = 0;
    while (data[i] != 0) {
        terminal_putc(data[i]);
        i++;
    }
}

void main() {

    

    // char* message = "Hello, This is Sanchana's OS! :)";

    // int i = 0;
    // while(message[i] != 0){
    //     video_memory[i*2] = message[i];
    //     video_memory[i*2 + 1] = 0x1c;  //change colour(red on blue rn)
    //     i++;
    // }

    // terminal_clear(); //clearing BIOS messages
    // cursor_y = 14;
    // cursor_y++;
    init_video();
    terminal_write("Hello, Welcome to Sanchana's OS! :)\n");
    terminal_write("------------------------------\n");

    // terminal_write("Testing scroll functionality:\n");

    // char* numbers = "123456789";
    // for (int i = 0; i < 20; i++) {
    //     terminal_write("Log entry number: ");
    //     terminal_putc(numbers[i % 9]); 
    //     terminal_write("\n");

    //     for(int d=0; d<1000000; d++){}; 
    // }

    // terminal_write("yay scroll works!");

    // //experimenting
    // while(1){
    //     int pos = rand()%2000;
    //     char random_char =(rand() % 93) + 33; //pick a random ascii character
    //     memory[pos * 2] = random_char;
    //     memory[pos * 2 + 1] = 0x02;
    //     for (int d = 0; d < 50000; d++) {} //delay loop so it doesnt go very fast
    // }
}
