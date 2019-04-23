#ifndef DISPLAY_H
#define DISPLAY_H

#include "tree.h"
#include "file_handle.h"
#include "util.h"

void header();
void welcome();
void mainMenu();
void signupMenu();
void loginMenu();
int inputBox();
void displayId(int id);
void press_to_continue();
void errorMessageL(int status);
void errorMessageS(int status);
void ManufaturerHome(Vertex* root,int id);
void DistributorHome(Vertex* root,int id);
void ShopHome(Vertex* root,int id);


#endif
