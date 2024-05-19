#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "aislar.h"

int aislar_palabras(char *s) {
    char *p1 = s; // pointer *p1 reads all the string
    char *p2 = s; // pointer *p2 writes the final string
    // skip all the characters that are not in the alfabet
    while ((('a' <= *p1 && *p1 <= 'z') || ('A' <= *p1 && *p1 <= 'Z'))==0){
        if (*p1 == '\0'){   // if we finish the string
            *p2 = '\0';
            return 0;
        }
        p1++;
    }
    // start: *p1 is in a word
    int inword = 1; //0 if we aren't in a word, in word==1
    int n = 1; // count hoy many words are in the final string
    while (*p1!='\0') {
        // p1 can be an alfabetic character -> add character to p2 and move forward (p1++ and p2++)
        if (('a' <= *p1 && *p1 <= 'z') || ('A' <= *p1 && *p1 <= 'Z')){
            // if we were not in a word, now we are, so we add a space to p2 before adding the character
            if (inword == 0){
                *p2 = ' ';
                n++;
                p2++;
            }
            inword = 1; // changes to 1 because now we are in a word
             *p2 = *p1; // add character to p2
            p1++;
            p2++;
        } else { 
            inword = 0; // changes to 0 because we did not read an alfabetic character and we are not in a word
            p1++;       // move forward
        }
    }
    // we end the string with '\0'
    *p2 = '\0';
    return n;
}

char *palabras(char *s) {
    int s_length = strlen(s);
    //printf("String s length: %d\n", s_length);
    // first malloc of s
    char *s1_malloc = malloc(s_length+1);
    // copy s to s1_malloc
    strcpy(s1_malloc, s);
    // use aislar_palabras to modify s1_malloc
    aislar_palabras(s1_malloc);
    // new length of s1_malloc
    int s1_length = strlen(s1_malloc);
    // second malloc of s
    char *s2_malloc = malloc(s1_length+1);
    // copy s1_malloc to s2_malloc
    strcpy(s2_malloc, s1_malloc);
    // free s1_malloc
    free(s1_malloc);
    // return s2_malloc
    return s2_malloc;
}


int main(){
    // funcion aislar_palabras
    printf("---------- Test 1 ----------\n");
    char str[]=" return ( 'a'<=ch && ch<='z') || ('A'<=ch && ch<='Z');";
    // apply the function aislar_palabras
    printf("Solucion: n=9 y str es 'return a ch ch z A ch ch Z' \n");
    printf("Numero de palabras: %d\n", aislar_palabras(str));
    // final string
    printf("String resultante: '%s'\n", str);

    printf("---------- Test 1.1 ----------\n");
    char str2[]="'a'<=<='')||(';";
    // apply the function aislar_palabras
    printf("Solucion: n=1 y str es 'a' \n");
    printf("Numero de palabras: %d\n", aislar_palabras(str2));
    // final string
    printf("String resultante: '%s'\n", str2);

    printf("---------- Test 1.2 ----------\n");
    char str3[]="''<=<='')||(';";
    // apply the function aislar_palabras
    printf("Solucion: n=0 y str es '' \n");
    printf("Numero de palabras: %d\n", aislar_palabras(str3));
    // final string
    printf("String resultante: '%s'\n", str3);

    printf("---------- Test 1.3 ----------\n");
    char str4[]="a";
    // apply the function aislar_palabras
    printf("Solucion: n=1 y str es 'a' \n");
    printf("Numero de palabras: %d\n", aislar_palabras(str4));
    // final string
    printf("String resultante: '%s'\n", str4);


    printf("---------- Test 2 ----------\n");
    char *r= palabras(" speed * time + dist ");
    // apply the function palabras
    printf("Solucion: r es 'speed time dist' \n");
    printf("String resultante: '%s'\n", r);
    return 1;
}
