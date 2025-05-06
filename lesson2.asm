; Hello World Program - Lesson 2
; Author: Jacob Shamer
; Course: CMSC 313 - Mo/We 10:00AM 
; Compile: nasm -f elf32 -g -F dwarf -o lesson2.o lesson2.asm
; Link: ld -m elf_i386 -o lesson2 lesson2.o
; Run: ./lesson2
 
SECTION .data
msg     db      'Hello World!', 0Ah
 
SECTION .text
global  _start
 
_start:
 
    mov     edx, 13
    mov     ecx, msg
    mov     ebx, 1
    mov     eax, 4
    int     80h
 
    mov     ebx, 0
    mov     eax, 1
    int     80h