/*
 * File:   newcunittest.c
 * Author: pontushilding
 *
 * Created on Dec 4, 2014, 3:02:16 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "lager.c"


#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <CUnit/Automated.h>
#include <CUnit/Console.h>

/*
 * CUnit Test Suite
 */

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

void add_item(DB db, LastAction latest);

void testAdd_item() {
  printf("ADDITEM\n");
  DB db = malloc(sizeof(struct db_t) * 30);
  LastAction latest = malloc(sizeof(struct last_action_t) * 30);
  add_item(db, latest);
  //Pontus
  //Kewl.
  //1337
  //101
  //y
  printf("%d\n",db->amount);
  CU_ASSERT(db->amount == 1);

  printf("%s\n",db->inventory[0]->name);
  CU_ASSERT(strcmp(db->inventory[0]->name,"Pontus") == 0);

  printf("%s\n",db->inventory[0]->description);
  CU_ASSERT(strcmp(db->inventory[0]->description,"Kewl.") == 0);

  printf("%c\n",db->inventory[0]->location->shelf);
  CU_ASSERT(db->inventory[0]->location->shelf == 'A');

  printf("%d\n",db->inventory[0]->location->place);
  CU_ASSERT(db->inventory[0]->location->place == 1);

  printf("%d\n",db->inventory[0]->price);
  CU_ASSERT(db->inventory[0]->price == 101);

  printf("%d\n",db->inventory[0]->amount);
  CU_ASSERT(db->inventory[0]->amount == 1337);

  free(db);
  free(latest);
  
}

void add_to_db(DB db, Item v);

void testAdd_to_db() {
  printf("ADDTODB\n");
  DB db2 = malloc(sizeof(struct db_t) * 10);
  Item v1 = malloc(sizeof(struct item_t));
  Item v2 = malloc(sizeof(struct item_t));
  Item v3 = malloc(sizeof(struct item_t));
  Item v4 = malloc(sizeof(struct item_t));
  Item v5 = malloc(sizeof(struct item_t));
  Item v6 = malloc(sizeof(struct item_t));

  v1->name = "Apple";
  v1->description = "Red";
  v1->price = 5;
  v1->amount = 3;

  v2->name = "Pear";
  v2->description = "Green";
  v2->price = 2;
  v2->amount = 5;

  v3->name = "Banana";
  v3->description = "Disgusting";
  v3->price = 0;
  v3->amount = 33;

  v4->name = "Hat";
  v4->description = "Toppy";
  v4->price = 1;
  v4->amount = 2;

  v5->name = "12";
  v5->description = "13";
  v5->price = 5;
  v5->amount = 2;

  v6->name = "Oboy";
  v6->description = "Sweet";
  v6->price = 3;
  v6->amount = 4;

  add_to_db(db2, v1);
  add_to_db(db2, v2);
  add_to_db(db2, v3);
  add_to_db(db2, v4);
  add_to_db(db2, v5);
  add_to_db(db2, v6);


  for(int i = 0; i < 6; i++){
    CU_ASSERT(db2->inventory[i] != NULL);
  }

  CU_ASSERT(db2->amount == 6);
  CU_ASSERT(db2->inventory[2]->amount == 33);
  CU_ASSERT(db2->inventory[2]->price == 0);
  CU_ASSERT(db2->inventory[2]->name == "Banana"); //CRITICAL STATEMENT: DO NOT CHANGE
  CU_ASSERT(db2->inventory[2]->description == "Disgusting"); //CRITICAL STATEMENT: DO NOT CHANGE

  free(v1);
  free(v2);
  free(v3);
  free(v4);
  free(v5);
  free(v6);
  free(db2);
}


char ask_char_question(char* question, char* answer);

void testAsk_char_question() {
  printf("ASKCHARQUESTION\n");
  char* question = "Printed question.";
  char* answer = "DdAaSsGgZz";
  char result1 = ask_char_question(question, answer);
  char result2 = ask_char_question(question, answer);
  char result3 = ask_char_question(question, answer);
  char result4 = ask_char_question(question, answer);
  char result5 = ask_char_question(question, answer);
  //D
  //A
  //s
  //G
  //z
  printf("%c\n",result1);
  CU_ASSERT(result1 == 'd');
  printf("%c\n",result2);
  CU_ASSERT(result2 == 'a');
  printf("%c\n",result3);
  CU_ASSERT(result3 == 's');
  printf("%c\n",result4);
  CU_ASSERT(result4 == 'g');
  printf("%c\n",result5);
  CU_ASSERT(result5 == 'z');
}


_Bool ask_int(char* question, Item item, int op);

void testAsk_int() {
  printf("ASKINT\n");
  char* question1 = "Amount: ";
  char* question2 = "Price: ";

  Item item1 = malloc(sizeof(struct item_t));
  Item item2 = malloc(sizeof(struct item_t));


  int op1 = 1;
  int op2 = 2;

  bool result1 = ask_int(question1, item1, op1);
  //22
  bool result2 = ask_int(question2, item1, op2);
  //33
  //  bool result3 = ask_int(question2, item2, op2); //SHOULD FAIL
  //  //'f'
  //  bool result4 = ask_int(question1, item2, op1); //SHOULD FAIL
  //  //'w'

  CU_ASSERT(item1->amount == 22);
  CU_ASSERT(item1->price == 33);

  printf("%d\n",result1);
  CU_ASSERT(result1 == true);
  printf("%d\n",result2);
  CU_ASSERT(result2 == true);
  //printf("%d\n",result3);
  //CU_ASSERT(result3 == false);
  //printf("%d\n",result4);
  //CU_ASSERT(result4 == false);

  free(item1);
  free(item2);
}


void ask_name(char* question, Item item, int op);

void testAsk_name() {
  printf("ASKNAME");
   char* question = "ask_name question";
   Item item = malloc(sizeof(struct item_t) * 100);
   int op1 = 1;
   int op2 = 2;
   ask_name(question, item, op1);
   //bulbasaur
   ask_name(question, item, op2);
   //pikachu
   printf("\n%s\n",item->name);
   CU_ASSERT(strcmp(item->name,"bulbasaur") == 0);
   printf("\n%s\n",item->description);
   CU_ASSERT(strcmp(item->description,"pikachu") == 0);
   free(item);
}


bool ask_yes_no(char* question);

void testAsk_yes_no() { 
  
  char* question = "Ask yes no question: ";
  bool result1 = ask_yes_no(question);
  //y
  bool result2 = ask_yes_no(question); //SHOULD FAIL
  //n
  //_Bool result3 = ask_yes_no(question); //SHOULD FAIL
  //g
  //_Bool result4 = ask_yes_no(question); //SHOULD FAIL
  //2
  
  CU_ASSERT(result1);
  printf("\nAsk yes no: %d\n", result1);
  CU_ASSERT(!result2);
  printf("Ask yes no: %d\n", result2);

  //CU_ASSERT(!result3);
  //printf("Ask yes no: %d\n", result3);

  //CU_ASSERT(!result4);
}


void assignLocation(DB db, Item item);

void testAssignLocation() {
  /*
    DB db;
    Item item;
    assignLocation(db, item);
    if (1) {
        CU_ASSERT(0);
    }
*/
}


void copy_to_last_action(Item item, LastAction lastAct);

void testCopy_to_last_action() {
  
  Item item = malloc(sizeof(struct item_t)*10);
  item->name = "Apple";
  item->description = "Red";
  item->price = 5;
  item->amount = 3;
  item->location = malloc(sizeof(struct location_t)*3);
  item->location->place = 3;
  item->location->shelf = 'A';
  
  LastAction lastAct = malloc(sizeof(struct last_action_t)*10);
  copy_to_last_action(item, lastAct);
  printf("\n First: %s, Second: %s\n", item->name, lastAct->latest->name);
  CU_ASSERT(!strcmp(item->name, lastAct->latest->name));
  CU_ASSERT(!strcmp(item->description, lastAct->latest->description));
  CU_ASSERT(item->price == lastAct->latest->price);
  CU_ASSERT(item->amount == lastAct->latest->amount);
  CU_ASSERT(item->location->place == lastAct->latest->location->place);
  CU_ASSERT(item->location->shelf == lastAct->latest->location->shelf);

  free(item);
  free(lastAct);
}


void delete_by_location(DB db, char shelf, int place, LastAction lastAct);

void testDelete_by_location() {
  
  DB db = malloc(sizeof(struct db_t)*10);
  Item item1 = malloc(sizeof(struct item_t)*10);
  Item item2 = malloc(sizeof(struct item_t)*10);
  Item item3 = malloc(sizeof(struct item_t)*10);

  item1->location = malloc(sizeof(struct location_t)*2);
  item1->location->place = 1;
  item1->location->shelf = 'A';

  item1->name = "Pear";
  item1->description = "Green";
  item1->price = 2;
  item1->amount = 4;

  item2->location = malloc(sizeof(struct location_t)*2);
  item2->location->place = 2;
  item2->location->shelf = 'A';

  item2->name = "Apple";
  item2->description = "Red";
  item2->price = 5;
  item2->amount = 3;

  item3->location = malloc(sizeof(struct location_t)*2);
  item3->location->place = 3;
  item3->location->shelf = 'A';

  item3->name = "Banana";
  item3->description = "Yellow";
  item3->price = 1;
  item3->amount = 4;

  db->inventory[0] = item1;
  db->inventory[1] = item2;
  db->inventory[2] = item3;
  db->amount = 3;

  char shelf = 'A';
  int place = 2;

  LastAction lastAct = malloc(sizeof(struct last_action_t)*10);
  delete_by_location(db, shelf, place, lastAct);
  
  CU_ASSERT(db->inventory[0] != NULL);
  CU_ASSERT(db->inventory[1] == NULL);
  CU_ASSERT(db->inventory[2] != NULL);
  CU_ASSERT(db->amount == 2);
  CU_ASSERT(lastAct->inventoryPosition == 1);
  CU_ASSERT(!strcmp(lastAct->latest->name, "Apple"));
  CU_ASSERT(!strcmp(lastAct->latest->description, "Red"));
  CU_ASSERT(lastAct->latest->price == 5);
  CU_ASSERT(lastAct->latest->amount == 3);

  free(db);
  free(item1);
  free(item2);
  free(item3);
}


void delete_by_name(DB db, char* s, LastAction lastAct);

void testDelete_by_name() {
  
  DB db = malloc(sizeof(struct db_t)*10);
  Item item1 = malloc(sizeof(struct item_t)*10);
  Item item2 = malloc(sizeof(struct item_t)*10);
  Item item3 = malloc(sizeof(struct item_t)*10);

  item1->name = "Pear";
  item1->description = "Green";
  item1->price = 2;
  item1->amount = 4;

  item2->name = "Apple";
  item2->description = "Red";
  item2->price = 5;
  item2->amount = 3;


  item3->name = "Banana";
  item3->description = "Yellow";
  item3->price = 1;
  item3->amount = 4;

  db->inventory[0] = item1;
  db->inventory[1] = item2;
  db->inventory[2] = item3;
  db->amount = 3;
  char* s = "Apple";

  LastAction lastAct = malloc(sizeof(struct last_action_t)*10);
  delete_by_name(db, s, lastAct);
  
  CU_ASSERT(db->inventory[0] != NULL);
  CU_ASSERT(db->inventory[1] == NULL);
  CU_ASSERT(db->inventory[2] != NULL);
  CU_ASSERT(db->amount == 2);
  CU_ASSERT(lastAct->inventoryPosition == 1);
  CU_ASSERT(!strcmp(lastAct->latest->name, "Apple"));
  CU_ASSERT(!strcmp(lastAct->latest->description, "Red"));
  CU_ASSERT(lastAct->latest->price == 5);
  CU_ASSERT(lastAct->latest->amount == 3);

  free(db);
  free(item1);
  free(item2);
  free(item3);
}


void delete_item(DB db, LastAction lastAct);

void testDelete_item() {
/*
    DB db;
    LastAction lastAct;
    delete_item(db, lastAct);
    if (1) {
        CU_ASSERT(0);
    }
*/
}


void edit_by_name(DB db, char* s, LastAction lastAct);

void testEdit_by_name() {
  /*
    DB db;
    char* s;
    LastAction lastAct;
    edit_by_name(db, s, lastAct);
    if (1) {
        CU_ASSERT(0);
    }
*/
}


void edit_item(DB db, LastAction lastAct);

void testEdit_item() {
  /*
    DB db;
    LastAction lastAct;
    edit_item(db, lastAct);
    if (1) {
        CU_ASSERT(0);
    }
*/
}


void edit_item_parameters(Item i);

void testEdit_item_parameters() {
  /*
    Item i;
    edit_item_parameters(i);
    if (1) {
        CU_ASSERT(0);
    }
*/
}

void print_inventory(DB database);

void testPrint_inventory() {
/*
DB database;
    print_inventory(database);
    if (1) {
        CU_ASSERT(0);
    }
*/
}


_Bool print_inventory_loop(DB database);

void testPrint_inventory_loop() {
  /*
    DB database;
    _Bool result = print_inventory_loop(database);
    if (1) {
        CU_ASSERT(0);
    }
*/
}


void print_item(Item i);

void testPrint_item() {
  /*
    Item i;
    print_item(i);
    if (1) {
        CU_ASSERT(0);
    }
*/
}


void print_main_menu(char* user);

void testPrint_main_menu() {
/*
    char* user;
    print_main_menu(user);
    if (1) {
        CU_ASSERT(0);
    }
*/
}


void readd_to_db(DB db, LastAction lastAct);

void testReadd_to_db() {
  /*    DB db;
    LastAction lastAct;
    readd_to_db(db, lastAct);
    if (1) {
        CU_ASSERT(0);
    }
*/
}



void undo(DB db, LastAction lastAct);

void testUndo() {
  /*
  DB db;
  LastAction lastAct;
  undo(db, lastAct);
  if (1) {
    CU_ASSERT(0);
  }
*/
}


int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("newcunittest", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testAdd_item", testAdd_item)) ||
            (NULL == CU_add_test(pSuite, "testAdd_to_db", testAdd_to_db)) ||
            (NULL == CU_add_test(pSuite, "testAsk_char_question", testAsk_char_question)) ||
            (NULL == CU_add_test(pSuite, "testAsk_int", testAsk_int)) ||
            (NULL == CU_add_test(pSuite, "testAsk_name", testAsk_name)) ||
            (NULL == CU_add_test(pSuite, "testAsk_yes_no", testAsk_yes_no)) ||
            (NULL == CU_add_test(pSuite, "testAssignLocation", testAssignLocation)) ||
            (NULL == CU_add_test(pSuite, "testCopy_to_last_action", testCopy_to_last_action)) ||
            (NULL == CU_add_test(pSuite, "testDelete_by_location", testDelete_by_location)) ||
            (NULL == CU_add_test(pSuite, "testDelete_by_name", testDelete_by_name)) ||
            (NULL == CU_add_test(pSuite, "testDelete_item", testDelete_item)) ||
            (NULL == CU_add_test(pSuite, "testEdit_by_name", testEdit_by_name)) ||
            (NULL == CU_add_test(pSuite, "testEdit_item", testEdit_item)) ||
            (NULL == CU_add_test(pSuite, "testEdit_item_parameters", testEdit_item_parameters)) ||
            (NULL == CU_add_test(pSuite, "testPrint_inventory", testPrint_inventory)) ||
            (NULL == CU_add_test(pSuite, "testPrint_inventory_loop", testPrint_inventory_loop)) ||
            (NULL == CU_add_test(pSuite, "testPrint_item", testPrint_item)) ||
            (NULL == CU_add_test(pSuite, "testPrint_main_menu", testPrint_main_menu)) ||
            (NULL == CU_add_test(pSuite, "testReadd_to_db", testReadd_to_db)) ||
            (NULL == CU_add_test(pSuite, "testUndo", testUndo))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
