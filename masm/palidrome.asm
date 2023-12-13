data segment 
    msg1 db 10,13 ,"Enter the string : $"
    msg2 db 10,13,"palindrome $"
    msg3 db 10,13 , "Not palindrome $"
    n db 09h dup(?)
data ends

code segment
    assume cs:code,ds:data
    start:  mov ax,data
            mov ds,ax

            mov si,offset n
            mov di,offset n 

            lea dx,msg1
            mov ah,09h
            int 21h

            mov cl,00h

    scan:   mov ah,01h
            int 21h

            cmp al,0dh
            jz ended
            mov [si],al
            inc si
            inc cl
            jmp scan

    ended:  dec si
            mov bl,[si]
            cmp [di],bl
            jnz notpal
            inc di
            dec cl
            jnz ended

    pal:     lea dx,msg2
             mov ah,09h
             int 21h
             jmp fin
    
    notpal: lea dx,msg3
            mov ah,09h
            int 21h

    fin:    mov ah,4ch
            int 21h


code ends
end start

