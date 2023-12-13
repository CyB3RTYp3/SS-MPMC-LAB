data segment
 msg1 db 10,13, "Enter the string: $"
 str1 db 100,0,100 dup(0)
 len1 dw 0000H
 msg2 db 10,13, "Enter the string to be replaced: $"
 str2 db 20,0,20 dup(0)
 len2 dw 0000H
 msg3 db 10,13, "Enter the string to be replaced with : $"
 str3 db 20,0,20 dup(0)
 len3 dw 0000H
 msg4 db 10,13, "Output String is: $"
data ends

dispaly1  MACRO msg
    lea dx,msg
    mov ah,09h
    int 21h
ENDM

dispaly2 MACRO msg
    lea dx,msg
    mov ah,0ah
    int 21h
ENDM

string MACRO str,len
    mov al,[str+1]
    mov bl,offset len
    mov BYTE PTR [bx],al
ENDM

code segment
    assume cs:code,ds:data,es:data
    start:  mov ax,data
            mov ds,ax
            mov es,ax

            dispaly1 msg1
            dispaly2 str1
            string str1,len1

            dispaly1 msg2
            dispaly2 str2
            string str2,len2

            dispaly1 msg3 
            dispaly2 str3
            string str3,len3

            lea si,str1+2
            mov cx,len1

            dispaly1 msg4

            lea di,str2+2
            mov bx,len2

            push si
            push cx

    up:     mov al,[si]

            l1: mov ah,[di]
                cmp ah,al
                jz l2 

                pop cx
                pop si

                lea di,str2+2
                mov bx,len2

                mov dl,[si]
                mov ah,02h
                int 21H

                inc si
                dec cx

                push si
                push cx

                cmp cx,0000
                jnz up 
                jz fin
        
            
            l2: dec bx
                push si
                push cx
                mov ax,len2
                cmp ax,bx
                jnz l7


            l7: inc si
                inc di
                cmp bx,0000
                jnz l3 
                 dec cx
                jnz up
            
            l3: lea di,str3+2
                mov bx,len3

            l4: mov dl,[di]
                mov ah,02H
                int 21H

                inc di
                dec bx
                jnz l4

                lea di,str2+2
                mov bx,len2
                push si
                push cx
                jmp up
    
    fin:    mov ah,4ch
            int 21H

code ends
end start
       



      







