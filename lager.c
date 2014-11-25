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
  char* shelf; //hyllan
  int place; //platsen på hyllan
};

struct item_t{
  char *name;
  char *description;
  struct location_t place;
  int price;
  int amount;
};



void print_item(Item i){
}

void print_main_menu(){
}


void add_to_db(DB db, Item v){
  db->inventory[db->amount++] = v;
  db->amount = db->amount+1;
}

void add_item(DB db){
  
  Item item = NULL;

  //  item->name = ask_char_question("Name: ","AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz");
  //item->amount = ask_char_question("Amount: ","AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz");

  print_item(item);

  if(ask_char_question("Save to db?", "Yy Nn") == 'y'){
    //*db = item;
    add_to_db(db, item);
  }
}


bool ask_yes_no(char* question){
  puts(question);
  
  
  while(true){
    switch (tolower(getchar())){
      case ('y'):
	return true;
	break;
      case ('n'):
	return false;
	break;
      default:
	puts("Choose [y] / [n]");
	while (getchar() != '\n') {
	  break;
	}
      }
  }
  
}



char ask_char_question(char *question, char *answer){
  printf("%s [%s]\n", question, answer);
  
  while(true){  
    char reply = getchar();
    while(getchar() != '\n');

    if(strchr(answer, reply)){
     return tolower(reply);
    }   
    printf("Invalid answer, try [%s]\n", answer);    
  }
  
}


int main(void){

  bool shouldContinue = true;

  while(shouldContinue){
    print_main_menu();
    switch(ask_char_question("Enter an operation.", "Ee Uu Aa Dd Cc Ll")){
    
    case 'e':
      if(ask_yes_no("Do you really want to quit?")){
	shouldContinue = false;
	break;
      }
      
    default:
      break;
      
      
    }
  }
  
  return 0;
}
