#include<stdio.h>
#include<string.h>

char input[10],label[10],ch2;
int w=0,start,lenght=0,end,count=0,address,taddr,i=0;
FILE *fp1,*fp2;

// Function to check formatting and line breaks
void check(){
    count++;
    address++;
    if(count==4){
        fprintf(fp2," ");
        i++;
        if(i==4){
            fprintf(fp2,"\n\n%x\t",address);
            i=0;
        }
        count=0;
    }
}

int main(){
   fp1=fopen("input.txt","r");
   fp2=fopen("output.txt","w");

   // Read the first string from the input file
   fscanf(fp1,"%s",input);

   // Loop until the end of file marker "E" is encountered
   while (strcmp(input,"E")!=0)
   {
    if(strcmp(input,"H")==0){
        // Header record: Read label, start address, end address
        fscanf(fp1,"%s %x %x %s",label,&start,&end,input);
        address=start;
    }else if(strcmp(input,"T")==0){
        // Text record: Read text address, length, and input
        fscanf(fp1,"%x %x %s",&taddr,&lenght,input);

         // Fill gaps with "xx" until the next text address is reached
        while(address < taddr){
            fprintf(fp2,"XX");
            check();
        }

        if(w==0){
            // Print text address at the beginning of the line
            fprintf(fp2,"%x\t",taddr);
            w=1;
        }

        // Data record: Print the characters from the input
        fprintf(fp2,"%c%c",input[0],input[1]);
        check();
        fprintf(fp2,"%c%c",input[2],input[3]);
        check();
        fprintf(fp2,"%c%c",input[4],input[5]);
        check();

        // Read the next string from the input
        fscanf(fp1,"%s",input);
    }else{
        // Data record: Print the characters from the input
        fprintf(fp2,"%c%c",input[0],input[1]);
        check();
        fprintf(fp2,"%c%c",input[2],input[3]);
        check();
        fprintf(fp2,"%c%c",input[4],input[5]);
        check();

        // Read the next string from the input
        fscanf(fp1,"%s",input);
    }

   }
   fclose(fp1);
   fclose(fp2);

   // Print the contents of the output file
   printf("The contents of output text \n");
   fp2=fopen("output.txt","r");
   ch2=fgetc(fp2);
   while (ch2!=EOF)
   {
    printf("%c",ch2);
    ch2=fgetc(fp2);
   }
   fclose(fp2);   

}



