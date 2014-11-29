#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "lager.h"


struct db_t{
  Item inventory[20];
  int amount;
};


struct location_t{
  char shelf;
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
  char *desc = i->description;
  char shelf = i->location->shelf;

  int place = i->location->place;
  int price = i->price;
  int amount = i->amount;

  printf("Item: %s \n",itemName);
  printf("Description: %s \n",desc);
   printf("Shelf: %c \n",shelf);

  printf("Place: %d \n",place);
  printf("Amount: %d \n",amount);
  printf("Price: $%d\n", price);
  printf("Total value: $%d\n",price*amount);
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

void assignLocation(DB db, Item item){
  item->location = malloc(sizeof(struct location_t)*20);
  char *shelfs = "ABCDEF";
  int place = 0;
  int j = 0;

  for(int i = 0; i < 20; i++){
    if(db->inventory[i] != NULL){
      if(i % 4 == 0 && i != 0){
	j++;
	place = 0;
      }
      place++;
      item->location->place = place;
      printf("%c\n",shelfs[j]);
      item->location->shelf = shelfs[j];
    }
  }    
}


void add_to_db(DB db, Item v){
  db->inventory[db->amount++] = v;
}


void add_item(DB db){
  
  Item item = malloc(sizeof(item) * 50);

  bool validInput = false;
  ask_name("Name: ", item, 1);
  ask_name("Description: ", item, 2);
  
  validInput = ask_int("Amount: ", item, 1);
  ask_int("Price: ", item, 2);
  while(getchar() != '\n');
  
  if(validInput == true){
    if(ask_yes_no("Save to database? [Y / N] ")){
      while(getchar() != '\n');
      //*db = item;
      add_to_db(db, item);
      assignLocation(db, item);
      

    }
    else{
      while(getchar() != '\n');
    }
  }
}


bool ask_int(char *question, Item item, int op){
  int i = 0;
  //int check = 0;
  //printf("%s\n", isdigit(amount));
  printf("%s", question);
  //while(getchar() != '\n');
  scanf("%d", &i);
  //check = isdigit(amount);
  //intAmount = atoi(&amount);
  //printf("%d\n", atoi(&amount));
  
  //if(check != 0){
  switch(op){

  case 1:
    item->amount = i;
    break;

  case 2:
    item->price = i;
    break;
  }
    return true;
    //}else{
    //printf("Invalid input. Integers only. ");
    //return false;
    //}
}

void ask_name(char *question, Item item, int op){
  char s[150];
  printf("%s", question);
  scanf("%s", s);
  switch(op){
  case 1:
    item->name = malloc(sizeof(item) +1);
    strcpy(item->name, s);
    break;

  case 2:
    item->description = malloc(sizeof(item) + 10);
    strcpy(item->description, s);
    break;
  }
  while(getchar() != '\n');

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
