#include <stdlib.c>
#include <string.h>


struct goods{
  char *name;
  char *description;
  place _place;
  int price;
  int amount;
};


struct place{
  char letter;
  int number;
};

typedef struct db_t *db_t;

struct db_t{
  struct goods item[10];
  int amount;


};



void mainMenu(){




}


void add_to_db(database db, struct goods v){
  db->item[db->amount++] = v;
  // db->amount = db->amount+1;

}



void addItem(database db){
  
  struct goods item;

  item.name = ask_string_question("Name: ");
  item.amount = ask_int_question("Amount: ");

  print_item(item);

  if(ask_char_question("Save to db?", "Yy Nn") == 'y'){
    add_to_db(db, item);
  }
  





}


char ask_char_question(char *question, char *answer){
  printf("%s [%s]\n", question, answer);
  


  while(true){  
    char reply = getChar();

    if(strchr(answer, reply)){
     return toLower(reply);
    }
      

    while(getchar() != '\n');

    printf("Invalid answer, try [%s]\n", answer);    
  }
  
}





int main(void){
  
  bool shouldContinue = false;

  while(shouldContinue){
    mainMenu();

    switch(ask_char_question("Enter an operation.", "Ee Uu Aa Dd Cc Ll"){
    
	//End
    case 'e':
	   if(ask_char_question("Do you want to quit the program?", "Yy, Nn") == 'y'){
	     shouldContinue = false;
	   }

      case 'a':
	


      }
      
      }
  
  return 0;
}
