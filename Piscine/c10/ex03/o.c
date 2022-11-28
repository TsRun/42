#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 255

void hexDump (char *desc, void *addr, int len) {
    int i;
    unsigned char buffLine[17];
    unsigned char *pc = (unsigned char*)addr;


    if (desc != NULL){

       printf ("%s:\n", desc);

    }


    for (i = 0; i < len; i++) {


        if ((i % 16) == 0) {

            if (i != 0)

                printf ("  %s\n", buffLine);
           // if (buffLine[i]== '\0') break;

            if (pc[i] == 0x00) exit(0);

            // Prints the ADDRESS
            printf ("  %07x ", i);
        }

        // Prints the HEXCODES that represent each chars.
        printf ("%02x", pc[i]);
        if ((i % 2) == 1) 
            printf (" "); 



        if ((pc[i] < 0x20) || (pc[i] > 0x7e)){
            buffLine[i % 16] = '.';
        }

        else{

           buffLine[i % 16] = pc[i];

        }    


        buffLine[(i % 16) + 1] = '\0'; //Clears the next array buffLine


    }



    while ((i % 16) != 0) {
        printf ("   ");
        i++;
    }


    printf ("  %s\n", buffLine);
}


int main()
    {
            FILE *ptr_file;
            char buff[SIZE];

            ptr_file =fopen("input.txt","r");
            if (!ptr_file){
            printf("returning 1");
                return 1;
            }

            memset(buff, '\0', sizeof( buff) );
            fgets(buff,SIZE, ptr_file);
            hexDump ("buff", &buff, sizeof (buff));

        fclose(ptr_file);

            return 0;
    }
