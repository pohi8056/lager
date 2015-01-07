#include "lager.h"


int main(int argc, char *argv[]){
  
  char *user = "guest";
  if(argc == 2){
      user = argv[1];
    }
  DB db = malloc(sizeof(DB) * 500);
  LastAction latest = malloc(sizeof(LastAction)*10);

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
  free(db->latest);
  free(db);
  return 0;
}
