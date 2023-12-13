#include<stdio.h>
#include <stdlib.h>
#include<string.h>

int main(){
char a[20],ad[20],label[20],opcode[20],operand[20],symbol[20];
int start,len,actual_len,addr,prevaddr,finaddr,diff,add,j=0;
FILE *fp1,*fp2,*fp3,*fp4;
char nmemonics[15][15]={"LDA","STA","LDCH","STCH"};
char code[15][15]={"33","44","53","57"};

fp1= fopen("intermid.txt","r");
fp2= fopen("symtab.txt","r");

fp3=fopen("output.txt","w");
fp4= fopen("objcode.txt","w");

fscanf(fp1,"%s %s %s",label,opcode,operand);

while(strcmp(opcode,"END")!=0){
    prevaddr=addr;
    fscanf(fp1,"%d %s %s %s %s",&addr,label,opcode,operand);
}

finaddr=addr;

rewind(fp1);

fscanf(fp1,"%s %s %s",label,opcode,operand);

if(strcmp(opcode,"START")==0){
    fprintf(fp3,"\t%s\t%s\t%s\n",label,opcode,operand);
    fprintf(fp4,"H %s00 %s00 %d\n",label,opcode,finaddr);
    fscanf(fp1,"%d %s %s %s ",&addr,label,opcode,operand);
    start=addr;
    diff=prevaddr-start;
    fprintf(fp4,"T 00%d %d",prevaddr,diff);
}

while(strcmp(opcode,"END")!=0){

    if(strcmp(opcode,"BYTE")==0){
        fprintf(fp3,"%d\t%s\t%s\t%s",addr,label,opcode,operand);
        len=strlen(operand);
        actual_len=len-3;

        for( int i=2;i<(actual_len+2);i++){
            sprintf(ad,"%X",operand[i]);
            fprintf(fp3,"%s",ad);
            fprintf(fp4," %s\n",ad);
        }
        fprintf(fp3,"\n");
    }
    else if(strcmp(opcode,"WORD")==0){
        len=strlen(operand);
        sprintf(a,"%d",atoi(operand));

        fprintf(fp3,"%d\t%s\t%s\t%s\t%s\n",addr,label,opcode,operand,a);
        fprintf(fp4," 0000%s",a);
    }
    else if ((strcmp(opcode, "RESW") == 0) || (strcmp(opcode, "RESB") == 0)){
        fprintf(fp3,"%d\t%s\t%s\t%s\n",addr,label,opcode,operand);
    }
    else{
        while(strcmp(opcode,nmemonics[j])!=0){
            j++;
        }

        if(strcmp(operand,"COPY")==0){
            fprintf(fp3,"%d\t%s\t%s\t%s\t%s0000\n",addr,label,opcode,operand,code[j]);
        }
        else{
            rewind(fp2);
            fscanf(fp2,"%s %d",symbol,&add);

            while(strcmp(symbol,operand)!=0){
                 fscanf(fp2,"%s %d",symbol,&add);
            }

            fprintf(fp3,"%d\t%s\t%s\t%s\t%s%d\n",addr,label,opcode,operand,code[j],add);
            fprintf(fp4," %s%d",code[j],add);
        }
    }
    fscanf(fp1,"%d %s %s %s",&addr,label,opcode,operand);
}
fprintf(fp3,"%d\t%s\t%s\t%s\n",addr, label, opcode, operand);
fprintf(fp4,"\nE 00%d",start);
  fclose(fp4);
  fclose(fp3);
  fclose(fp2);
  fclose(fp1);
}



