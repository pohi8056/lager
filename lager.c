#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "lager.h"


/**
 * @file lager.c
 * @author Pontus Hilding
 * @author Lukas Hamberg
 * @date 1 Dec 2014
 * @brief A simple inventory database.
 *
 *
 *
 * @see http://auportal.herokuapp.com/lectures/28
 */


/**
 * A structure to represent a database.
 */
struct db_t{
  Item inventory[20];
  int amount;
  LastAction latest;
};


/**
 * A structure to represent a location.
 */
struct location_t{
  char shelf;
  int place;
};


/**
 * A structure to represent a location.
 */
struct last_action_t{
  Item latest;
  int latestOp; //1 == added an item, 2 == edited an item, 3 == deleted an item, 0 == latest was undo.
  int inventoryPosition;
};

struct item_t{
  char *name;
  char *description;
  Location location;
  int price;
  int amount;
};


void print_inventory(DB database){
  printf("\n\n______Inventory_____\n");
  for (int i = 0; i <= database->amount; i++) {
    if(database->inventory[i] != NULL){
      print_item(database->inventory[i]);
      printf("- - - - - - - - - - \n");
    }
    
  }
  printf("____________________\n\n");
  printf("Number of items: %d\n", database->amount);

}


bool print_inventory_loop(DB database){
  print_inventory(database);
  
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
  printf("[2]\t edit an item. \n");
  printf("[3]\t remove an item. \n");
  printf("[4]\t list the current inventory.\n");
  printf("[5]\t undo the latest change. \n");
  printf("[6]\t exit program.\n");
  printf("________________________________________________________________\n\n");
  printf("\n \n \n \n \n");  
}


void undo(DB db, LastAction lastAct){
  
  int latestOperation = lastAct->latestOp;

  if(latestOperation != 0){
    switch(latestOperation){
   
    case 1:
      delete_by_name(db, lastAct->latest->name, lastAct);
      lastAct->latestOp = 0;
      break;

    case 2:
      printf("IM HERE");
      // delete_by_name(db, lastAct->latest->name, lastAct);
      readd_to_db(db, lastAct);
      lastAct->latestOp = 0;
      //EDIT
      break;

    case 3:
      readd_to_db(db, lastAct);
      lastAct->latestOp = 0;
      break;

    case 0:
      
      break;
    }
  }
  else{
    printf("No operation made yet!");
  }
}



/*
Item return_item(DB db, char *s){
  for(int i = 0; i < 20; i++){
    if(db->inventory[i] != NULL){
      if(strcmp(db->inventory[i]->name, s) == 0){
	return db->inventory[i];
      }
    }
  }
  return NULL;
  }*/


//*********************EDIT************************


void edit_item(DB db, LastAction lastAct){
  char name[20];
  print_inventory(db);
  printf("\nWhich item would you like to edit?: ");
  scanf("%s", name);
  while(getchar() != '\n');
  edit_by_name(db, name, lastAct);
  while(getchar() != '\n');
}

void edit_by_name(DB db, char *s, LastAction lastAct){
  for(int i = 0; i < db->amount; i++){
    if(db->inventory[i] != NULL){
      if(strcmp(db->inventory[i]->name, s) == 0){
	copy_to_last_action(db->inventory[i], lastAct);
	lastAct->inventoryPosition = i;
	lastAct->latestOp = 2;
	edit_item_parameters(db->inventory[i]);
	break;
      }
    }
  }
}


void edit_item_parameters(Item i){
  char newString[100];
  int newInt;
  print_item(i);
  printf("\nWhat would you like to edit?\n");
  switch (ask_char_question("[N]ame,[D]escription,[P]rice,[A]mount","NnDdPpAa")){
    while(getchar() != '\n');
  case 'n':
    printf("\nNew name:");
    scanf("%s", newString);
    strcpy(i->name,newString);
    break;
  case 'd':
    printf("\nNew description:");
    scanf("%s", newString);
    strcpy(i->description,newString);
    break;
  case 'p':
    printf("\nNew price:");
    scanf("%d", &newInt);
    i->price = newInt;
    break;
  case 'a':
    printf("\nNew amount:");
    scanf("%d", &newInt);
    i->amount = newInt;
    break;
  default:
    break;
      }

}



//*********************EDIT************************


void delete_by_name(DB db, char *s, LastAction lastAct){
  for(int i = 0; i < db->amount; i++){
    if(db->inventory[i] != NULL){
      if(strcmp(db->inventory[i]->name, s) == 0){
	lastAct->latest = db->inventory[i];
	lastAct->inventoryPosition = i;
	db->inventory[i] = NULL;
	db->amount--;
	break;
      }
    }
  }
}


void delete_by_location(DB db, char shelf, int place, LastAction lastAct){
  for(int i = 0; i < 20; i++){
    if(db->inventory[i] != NULL){
      printf("%c", db->inventory[i]->location->shelf);
      if(db->inventory[i]->location->shelf == toupper(shelf) && db->inventory[i]->location->place == place){
	lastAct->latest = db->inventory[i];
	lastAct->inventoryPosition = i;
	db->inventory[i] = NULL;
	db->amount--;
	break;
      }
    }
  }
}


void delete_item(DB db, LastAction lastAct){
  char reply = ask_char_question("Delete by location or name? [L/N]", "LlNn");
  char shelf;
  int amountChecker = db->amount;
  char name[20];
  char place;
  switch(reply){
  case 'l':
    shelf = ask_char_question("Shelf: ", "AaBbCcDdEeFf");
    place = ask_char_question("Place: ", "1234");
    printf("%c %d\n", shelf, atoi(&place));
    delete_by_location(db, shelf, atoi(&place), lastAct);
    break;

  case 'n':
    printf("Name of item to be deleted: ");
    scanf("%s", name);
    printf("%s", name);
    delete_by_name(db, name, lastAct);
    while(getchar() != '\n');
    break;
  }

  if(amountChecker > db->amount){
    printf("IM HEREEEE");
    lastAct->latestOp = 3;
  }
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


void readd_to_db(DB db, LastAction lastAct){
  db->inventory[lastAct->inventoryPosition] = lastAct->latest;
  db->amount++;
}


void copy_to_last_action(Item item, LastAction lastAct){
  lastAct->latest = malloc(sizeof(struct item_t) * 10);
  lastAct->latest->name = malloc(sizeof(char) * 20);
  lastAct->latest->description = malloc(sizeof(char) * 30);
  lastAct->latest->location = malloc(sizeof(struct location_t) * 2);

  strcpy(lastAct->latest->name, item->name);
  strcpy(lastAct->latest->description, item->description);
  lastAct->latest->price = item->price;
  lastAct->latest->amount = item->amount;
  lastAct->latest->location->place = item->location->place;
  lastAct->latest->location->shelf = item->location->shelf;
}

void add_item(DB db, LastAction lastAct){
  
  Item item = malloc(sizeof(struct item_t) * 50);
  bool validAmount = false;
  bool validPrice = false;
  ask_name("Name: ", item, 1);
  ask_name("Description: ", item, 2);

  validAmount = ask_int("Amount: ", item, 1);
  if(validAmount == true){
    validPrice = ask_int("Price: ", item, 2);
    if(validPrice == true){
      if(ask_yes_no("Save to database? [Y / N] ")){
	while(getchar() != '\n');
	add_to_db(db, item);
	assignLocation(db, item);
	copy_to_last_action(item, lastAct);
	lastAct->latestOp = 1;
      }
      else{
	while(getchar() != '\n');
      }
    }else{
      while(getchar() != '\n');
    }
  }else{
    while(getchar() != '\n');
  }
}



bool ask_int(char *question, Item item, int op){
  int i = 0;
  char garbage;
  printf("%s", question);
  if(scanf("%d%c", &i, &garbage) != 2 || garbage != '\n'){
    printf("Input not an integer.\n");
    return false;
  }
  else{
    switch(op){  
    case 1:
      item->amount = i;
      break;
      
    case 2:
      item->price = i;
      break;
    }
    return true;
  }
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
  LastAction latest = malloc(sizeof(struct last_action_t)*10);

  bool shouldContinue = true;

  while(shouldContinue){
    print_main_menu(user);
    switch(ask_char_question("___________________\nEnter an operation:", "123456")){

    case '6':
      if(ask_yes_no("Do you really want to exit program?")){
	shouldContinue = false;
	break;
      }
      else{
	while(getchar() != '\n'); // clear char buffer.
      }
      break;

    case '5':                  //undo
      undo(db, latest);
      break;
    case '4':                  //list
      while(print_inventory_loop(db)){
      }
      break;
    case '3':
      delete_item(db, latest); //remove
      break;
    case '2':                  //edit
      edit_item(db,latest);
      break;
    case '1':
      add_item(db, latest);    //add
      break;      
    default:
      break;
    }
  }
  
  return 0;
}
