#include "display.h"
#include <stdio.h>
#include <stdlib.h>

void header(){
    printf("\t _______________________________________________________________________________\n");
    printf("\t|                                                                               |\n");
    printf("\t|       M E D I C A L   S T O R E    M A N A G E M E N T    S Y S T E M         |\n");
    printf("\t|                                                                               |\n");
    printf("\t|_______________________________________________________________________________|\n");
}

void welcome(){
    printf("\t|                                                                               |\n");
    printf("\t|              Welcome to our Medical Store Management System !                 |\n");
    printf("\t|                        Some more information here                             |\n");
    printf("\t|_______________________________________________________________________________|\n");
}
void signupMenu(){
    printf("\t|                                                                               |\n");
    printf("\t|  1.    SIGNUP                                                                 |\n");
    printf("\t|  2.    LOGIN                                                                  |\n");
    printf("\t|_______________________________________________________________________________|\n");
}
int inputBox(){
    int choice;
    printf("\t|                                                                               |\n");
    printf("\t|   ENTER YOUR CHOICE  :   ");
    scanf("%1d",&choice);
    
    return choice;
}
// int main(){
//     header();
//     welcome();
//     signupMenu();
//     inputBox();
//     system("clear");
//     header();
//     welcome();
    
// }