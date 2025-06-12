; [org 0x7c00]
mov ah, 0x0e 
mov al, 'H'
int 0x10

mov al, 'e'
int 0x10

mov al, 'l'
int 0x10
int 0x10

mov al, 'o'
int 0x10

mov al, ','
int 0x10

mov al, ' '
int 0x10

mov al, 'T'
int 0x10

mov al, 'h'
int 0x10

mov al, 'i'
int 0x10

mov al, 's'
int 0x10

mov al, ' '
int 0x10

mov al, 'i'
int 0x10

mov al, 's'
int 0x10

mov al, ' '
int 0x10

mov al, 'S'
int 0x10

mov al, 'a'
int 0x10

mov al, 'n'
int 0x10

mov al, 'c'
int 0x10

mov al, 'h'
int 0x10

mov al, 'a'
int 0x10

mov al, 'n'
int 0x10

mov al, 'a'
int 0x10

mov al, 39
int 0x10

mov al, 's'
int 0x10

mov al, ' '
int 0x10

mov al, 'O'
int 0x10

mov al, 'S'
int 0x10

mov al, 13
int 0x10
mov al, 10
int 0x10

; ;attempting to print the the_secret
; ;attempt 1
; mov al, "1"
; int 0x10
; mov al, the_secret
; int 0x10

; mov al, 10
; int 0x10

; ;attempt 2
; mov al, "2"
; int 0x10
; mov al, [the_secret]
; int 0x10

; mov al, 10
; int 0x10

; ;attempt 3
; mov al, "3"
; int 0x10
; mov bx, the_secret
; add bx, 0x7c00
; mov al, [bx]
; int 0x10

; mov al, 10
; int 0x10

; ;attempt 4
; mov al, "4"
; int 0x10
; mov al, [0x7c2d]
; int 0x10

mov bp, 0x8000
mov sp, bp

push 'A'
push 'B'
push 'C'

mov al, [0x7ffe]
int 0x10

mov al, [0x7ffc]
int 0x10

; mov al, [0x8000]
; int 0x10

pop bx
mov al, bl
int 0x10

pop bx
mov al, bl
int 0x10 

pop bx
mov al, bl
int 0x10

mov al, [0x8000]
int 0x10

jmp $

; the_secret:
;     db "X"w

times 510-($-$$) db 0
dw 0xaa55