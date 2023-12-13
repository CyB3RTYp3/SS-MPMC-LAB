#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void passone(char label[10],char opcode[10],char operand[10],char code[10],char nmemoics[3]);
void display();

int main()
{
    // for reading from input
    char label[10], opcode[10], operand[10];
    // for reading from optab
    char code[10], nmemoics[3];
    // call the function
    passone(label, opcode, operand, code, nmemoics);

    return 0;
}


void passone(char label[10],char opcode[10],char operand[10],char code[10],char nmemoics[3]){
    int locctr,start;

    FILE *fp1,*fp2,*fp3,*fp4;

    fp1=fopen("input.txt","r");
    fp2=fopen("optab.txt","r");

    fp3=fopen("intermid.txt","w");
    fp4=fopen("symtab.txt","w");

    fscanf(fp1,"%s\t%s\t%s",label,opcode,operand);

    if(strcmp(opcode,"START")==0){
        start=atoi(operand);
        locctr=start;
        fprintf(fp3,"\t%s\t%s\t%s\n",label,opcode,operand);        
        fscanf(fp1,"%s\t%s\t%s",label,opcode,operand);
    }
    else{
        locctr=0;
    }
        
    while(strcmp(opcode,"END")!=0){
        fprintf(fp3,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);  

        if(strcmp(label,"**")!=0){
            fprintf(fp4,"%s\t%d\n",label,locctr);
        }

        fscanf(fp2,"%s\t%s",code,nmemoics);

        while(strcmp(code,"END")!=0){
            if(strcmp(code,opcode)==0){
                locctr+=3;
                break;
            }
            fscanf(fp2,"%s\t%s",code,nmemoics);
        }

        if(strcmp(opcode,"WORD")==0){
            locctr+=3;
        }

        else if(strcmp(opcode,"BYTE")==0){
            ++locctr;
        }

        else if(strcmp(opcode,"RESW")==0){
            locctr+=(3*(atoi(operand)));
        }

        else if(strcmp(opcode,"RESB")==0){
            locctr+=atoi(operand);
        }
        
        fscanf(fp1,"%s\t%s\t%s",label,opcode,operand);
    }
    fprintf(fp3,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);

    fclose(fp4);
    fclose(fp3);
    fclose(fp2);
    fclose(fp1);

    display();

    printf("\n The length of the code is : %d",(locctr-start));

}

void display(){
    char str;
 
    FILE *fp3,*fp4;
    
    printf("\nThe contents of Ouput Table :\n\n");
    fp3=fopen("intermid.txt","r");
    str=fgetc(fp3);
    while(str!=EOF){
        printf("%c",str);
        str=fgetc(fp3);
    }
    fclose(fp3);

    printf("\nThe contents of symtab Table :\n\n");
    fp4=fopen("symtab.txt","r");
    str=fgetc(fp4);
    while(str!=EOF){
        printf("%c",str);
        str=fgetc(fp4);
    }
    fclose(fp4);

}
