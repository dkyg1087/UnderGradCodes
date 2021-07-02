%{
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 200
#define DEBUG 0
struct polynomial {
     char name;
     double coef[SIZE];
};

%}

%union{
     struct polynomial* poly;
     double num;
     char * name;
}

%token NUMBER
%token ADD SUB MUL DIV POW
%token LEFT RIGHT VAR
%token END
%token DIFF

%left ADD SUB
%left MUL DIV
%right POW

%start Input

%%

Input:
    
     | Input Line
;

Line:
     END
     | Polynomial END {
          if(DEBUG)printf("Printing polynomial\n");
          printf("Result : ");
          char var = $<poly>1->name;
          if(var == '?'){
               printf("%+.4f\n",$<poly>1->coef[0]);
          }
          else{
               int i = SIZE-1;
               for(;i>=0;i--){
                    if($<poly>1->coef[i]!=0){
                         printf(" %+.2f%",$<poly>1->coef[i]);
                         if(i>=1)printf("%c",var);
                         if(i>=2)printf("^%d",i);
                    }
               }
               printf("\n");
          }
     }
;
Polynomial:
     NUMBER {
          if(DEBUG)printf("create number as polynomial\n");
          struct polynomial* ptr = ( struct polynomial*)malloc(sizeof(struct polynomial));
          int i;
          for(i = 1 ;i<SIZE ;i++)ptr->coef[i]=0;
          ptr->coef[0]=$<num>1;
          ptr -> name = '?';
          $<poly>$ =  ptr;
     }
|    VAR {
          if(DEBUG)printf("create variable as polynomial\n");
          struct polynomial * ptr = ( struct polynomial *)malloc(sizeof(struct polynomial));
          int i;
          for(i = 0 ;i<SIZE ;i++)ptr->coef[i]=0;
          ptr -> coef[1]=1;
          ptr -> name = *$<name>1;
          $<poly>$ =  ptr;
     }
|    Polynomial ADD Polynomial { 
          if(DEBUG)printf("Adding polynomials\n");
          if($<poly>1->name != $<poly>3->name &&  $<poly>1->name != '?' && $<poly>3->name != '?'){
               printf("You are adding two different variables together!! \n");
               YYABORT;
          }
          char name = $<poly>1->name == '?' ? $<poly>3->name : $<poly>1->name ;
          $<poly>1->name = name;
          int i=0;
          for(i = 0;i<SIZE;i++ )$<poly>1->coef[i] += $<poly>3 -> coef[i]; 
          $<poly>$ = $<poly>1;
     }
|    Polynomial SUB Polynomial{
          if(DEBUG)printf("Subtracting polynomials\n");
          if($<poly>1->name != $<poly>3->name &&  $<poly>1->name != '?' && $<poly>3->name != '?'){
               printf("You are subtracting two different variables together!! \n");
               YYABORT;
          }
          char name = $<poly>1->name == '?' ? $<poly>3->name : $<poly>1->name ;
          $<poly>1->name = name;
          int i=0;
          for(i = 0;i<SIZE;i++ )$<poly>1->coef[i] -= $<poly>3 -> coef[i]; 
          $<poly>$ = $<poly>1;
     }
|    Polynomial MUL Polynomial{
          if(DEBUG)printf("Multiplying polynomials\n");
          if($<poly>1->name != $<poly>3->name &&  $<poly>1->name != '?' && $<poly>3->name != '?'){
               printf("You are multiplying two different variables together!! \n");
               YYABORT;
          }
          char name = $<poly>1->name == '?' ? $<poly>3->name : $<poly>1->name ;
          double new_coef[SIZE] = {};
          int i=0,j=0;
          for(i = 0;i<SIZE;i++){
               for(j = 0;j<SIZE;j++){
                    int product = $<poly>1->coef[i] * $<poly>3 -> coef[j];
                    if(i+j < SIZE) new_coef[i+j] += product;
                    else if(product != 0){
                         printf("You are multiplying to a degree equal to or greater than 200!!\n");
                         YYABORT;
                    }
               }
          }
          $<poly>1 -> name = name;
          for(i = 0 ;i<SIZE;i++)$<poly>1->coef[i]=new_coef[i];
          $<poly>$ = $<poly>1;
     }
|    Polynomial DIV Polynomial{
          if(DEBUG)printf("Devidinging polynomials\n");
          if($<poly>3->name != '?'){
               printf("This calculator currently does not support polynomial division.\n");
               YYABORT;
          }
          char name = $<poly>1->name == '?' ? $<poly>3->name : $<poly>1->name ;
          $<poly>1->name = name;
          int i=0;
          for(i = 0;i<SIZE;i++ )$<poly>1->coef[i] /= $<poly>3 -> coef[0]; 
          $<poly>$ = $<poly>1;
     }
|    Polynomial POW Polynomial{
          if(DEBUG)printf("Powering polynomials\n");
          if($<poly>3->name != '?'){
               printf("This calculator currently does not support polynomial powering.\n");
               YYABORT;
          }
          double times = $<poly>3 -> coef[0];
          if(times != (int)times){
               printf("This calculator currently does not support decimal number powering.");
               YYABORT;
          }
          int k=0;
          char name = $<poly>1->name;
          double final_coef[SIZE]={};
          final_coef[0]=1;
          for(k = (int)times;k>0;k--){
               double new_coef[SIZE] = {};
               int i=0,j=0;
               for(i = 0;i<SIZE;i++){
                    for(j = 0;j<SIZE;j++){
                         int product = $<poly>1->coef[i] * final_coef[j];
                         if(i+j < SIZE) new_coef[i+j] += product;
                         else if(product != 0){
                              printf("You are powering to a degree equal to or greater than 200!!\n");
                              YYABORT;
                         }
                    }
               }
               for(i=0;i<SIZE;i++)final_coef[i]=new_coef[i];
          }
          for(k = 0 ;k<SIZE;k++)$<poly>1->coef[k]=final_coef[k];
          $<poly>$ = $<poly>1;
     }
|    LEFT Polynomial RIGHT {$<poly>$ = $<poly>2;}
|    DIFF LEFT Polynomial RIGHT {
          int i=0;
          for(i=0;i<SIZE;i++)$<poly>3->coef[i]*=i;
          for(i=0;i<SIZE-1;i++)$<poly>3->coef[i] = $<poly>3->coef[i+1];
          char name = '?';
          for(i=1;i<SIZE;i++)if($<poly>3->coef[i]!=0)name = $<poly>3->name;
          $<poly>3 -> name = name;
          $<poly>$ = $<poly>3;
     }
;

%%

int yyerror(char *s) {
  printf("%s\n", s);
}

int main() {
     yyparse();
}