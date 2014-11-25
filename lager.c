#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "lager.h"



struct item_t{
  char *name;
  char *description;
  struct location_t *_place;
  int price;
  int amount;
};


struct db_t{
  struct item_t item[10];
  int amount;
};


struct location_t{
  char* shelf; //hyllan
  int place; //platen på hyllan
};



void print_main_menu(){

}

void add_to_db(DB db, Item v){
  db->item[db->amount++] = *v;
  // db->amount = db->amount+1;

}

void add_item(DB db){
  
  Item item = NULL;

  //item.name = ask_string_question("Name: ");
  //item.amount = ask_int_question("Amount: ");

  //print_item(item);

  if(ask_char_question("Save to db?", "Yy Nn") == 'y'){
    //*db = item;
    add_to_db(db, item);
  }
}


bool ask_yes_no(char* question){
  puts(question);
  
  
  while(true){
      switch (getchar()){
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
  
  bool shouldContinue = false;

  while(shouldContinue){
    print_main_menu();
    if(ask_yes_no("Yes?")){
      break;
    }

    /*
    switch(ask_char_question("Enter an operation.", "Ee Uu Aa Dd Cc Ll"){
    
	//End
    case 'e':
	   if(ask_char_question("Do you want to quit the program?", "Yy, Nn") == 'y'){
	     shouldContinue = false;
	   }

      case 'a':
	


      }
    */  
  }
    
  return 0;
}
