#include <stdio.h>
#include <string.h>
#include "genlib.h"
#include "simpio.h"




int main(){

    FILE *infile;
    FILE *outfile;
    int nscan;
    char c;

    infile = fopen("i10f9.dat","r");
    outfile = fopen("o10f9.dat","w");


    c = fgetc(infile);

    while(TRUE){

            if(c==',' || c == '.'){


                    fputc(c,outfile);
                    c = fgetc(infile);
                    if (c != ' ' && c!= EOF){
                        fputc(' ',outfile);
                    }



            }
            if(c != EOF){
            fputc(c,outfile);
            c = fgetc(infile);
            }else break;

    }


    fclose(infile);
    fclose(outfile);


    return 0;
}
