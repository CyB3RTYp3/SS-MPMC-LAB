data segment
  msg1 db 10,13, "Enter the string: $"
  msg2 db 10,13, "vowel count is : $"
  vowel db 'a','e','i','o','u','$'
  databuff db 100,0,100 dup("$")
data ends

code segment
    assume cs:code,ds:data
        start:mov ax,data
              mov ds,ax

              lea dx,msg1
              mov ah,09h
              int 21h

              lea dx,databuff
              mov ah,0ah
              int 21h
              mov si,dx

              lea dx,msg2
              mov ah,09h
              int 21h

              mov bl,00h

        outer: lea di,vowel
               mov cx,0005h
               mov al,[si]

               inner:   cmp al,[di]
                        jz fin
                        inc di
                        dec cx
                        jnz inner
                        jmp next
                
                fin:    inc bl
        
        next:   inc si 
                cmp databuff[si],0ah
                jne outer

                mov dl,bl
                add dl,30h

                mov ah,02h
                int 21h

                mov ah,4ch
                int 21h
code ends
end start




              

              


