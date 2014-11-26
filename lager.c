#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "lager.h"


struct db_t{
  Item inventory[10];
  int amount;
};


struct location_t{
  char* shelf;
  int place;
};


struct item_t{
  char *name;
  char *description;
  Location location;
  int price;
  int amount;
};



bool print_inventory(DB database){
  printf("\n\n______Inventory_____\n");
  for (int i = 0; i < database->amount; i++) {
    print_item(database->inventory[i]);
    printf("- - - - - - - - - - \n");

  }
  printf("____________________\n\n");
  
  while(true){
    if(ask_yes_no("Back to main menu?\n")){
      while(getchar() != '\n');
      break;
    }
    else{
      while(getchar() != '\n');
    }
  }
  return false;
}

void print_item(Item i){

  char *itemName = i->name;
  //char *desc = i->description;
  //char *shelf = i->location->shelf;

  //int place = i->location->place;
  //int price = i->price;
  int amount = i->amount;

  printf("| Item: %s        \n",itemName);
  //printf("Description: %c \n",*desc);
  // printf("Shelf: %c \n",*shelf);

  //printf("Place: %d \n",place);
  //printf("Price: %d \n",price);
  printf("| Amount: %d        \n",amount);
}

void print_main_menu(char *name){
  printf("\n \n \n \n \n \n \n \n \n \n");  
  printf("\n \n \n \n \n \n \n \n \n \n");  
  printf("\n \n \n \n \n \n \n \n \n \n");  
  printf("\n \n \n \n \n \n \n \n \n \n");  
  printf("\n \n \n \n \n \n \n \n \n \n");  
  printf("Welcome, %s, to the IronClause Inventory Database - version 1.0!  \n", name);
  printf("________________________________________________________________ \n");
  printf("How may we help you today? \n \n");
  printf("I would like to...\n");
  printf("[1]\t add an item. \n");
  printf("[2]\t remove an item. \n");
  printf("[3]\t undo the latest change. \n");
  printf("[4]\t list the current inventory.\n");
  printf("[5]\t exit program.\n");
  printf("________________________________________________________________\n\n");
  printf("\n \n \n \n \n");  
}


void add_to_db(DB db, Item v){
  db->inventory[db->amount++] = v;
}

void add_item(DB db){
  
  Item item = malloc(sizeof(item) * 50);
  ask_name("Name: ", item);
  ask_int("Amount: ", item);
  
  while(getchar() != '\n');
  
  if(ask_yes_no("Save to database? [Y]/[N]\n")){
    while(getchar() != '\n');
    add_to_db(db, item);
  }
  else{
    while(getchar() != '\n');
  }
}


void ask_int(char *question, Item item){
  int i = 0;
  printf("%s", question);
  scanf("%d", &i);
  item->amount = i;
}

void ask_name(char *question, Item item){
  char s[50];
  printf("%s", question);
  scanf("%s", s);
  item->name = malloc(sizeof(item) +1);
  strcpy(item->name, s);
}


/*
char ask_string_question(char *question){
  char reply[50];
  item->name = malloc(sizeof(char) * 100);
  printf("%s \n", question);
  while(true){
    scanf("%s", reply);
    strcpy(item->name, reply)
    if(reply != '\0'){
      return reply;
    }
    printf("Invalid answer.");
  }
}
*/


bool ask_yes_no(char* question){
  printf("%s",question);
  while(true){
    switch (tolower(getchar())){
      while (getchar() != '\n');
    case ('y'):
      return true;
      break;
    case ('n'):
      return false;
      break;
    default:
      while (getchar() != '\n'){
      }
      break;
    }
  }
}


char ask_char_question(char *question, char *answer){
  printf("%s \n", question);
  while(true){ 
    char reply = getchar();
    while(getchar() != '\n');
    if(strchr(answer, reply)){
      return tolower(reply);
    }
    printf("Invalid answer, try [%s] \n", answer);    
  }  
}

int main(int argc, char *argv[]){
  char *user = "guest";
  if(argc == 2){
      user = argv[1];
    }
  DB db = malloc(sizeof(DB) * 1000);

  bool shouldContinue = true;

  while(shouldContinue){
    print_main_menu(user);
    switch(ask_char_question("___________________\nEnter an operation:", "12345")){
    case '5':
      if(ask_yes_no("Do you really want to exit program?")){
	shouldContinue = false;
	break;
      }
      else{
	while(getchar() != '\n'); // clear char buffer.
      }
    case '4': //list inventory
      while(print_inventory(db)){
    }
      break;
    case '3':
      //undo
      break;
    case '2':
      //remove
      break;
    case '1':
      add_item(db);    //add
      break;      
    default:
      break;
    }
  }
  
  return 0;
}
