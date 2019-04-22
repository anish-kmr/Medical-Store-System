#ifndef DISPLAY_H
#define DISPLAY_H

#include "tree.h"

void header();
void welcome();
void mainMenu();
void signupMenu();
void loginMenu();
int inputBox();
void press_to_continue();
void errorMessageL(int status);
void errorMessageS(int status);
// void ManufaturerHome(char* id);
void DistributorHome(Vertex* root,int* id);
// void ShopHome(char* id);


#endif