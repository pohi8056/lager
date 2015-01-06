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
  DB db = malloc(sizeof(struct db_t) * 20);
  LastAction latest = malloc(sizeof(struct last_action_t) * 20);
  add_item(db, latest);
  //Pontus
  //Kewl.
  //1337
  //101
  //y
  CU_ASSERT(db->amount == 1);
  CU_ASSERT(strcmp(db->inventory[0]->name,"Pontus") == 0);
  CU_ASSERT(strcmp(db->inventory[0]->description,"Kewl.") == 0);
  CU_ASSERT(db->inventory[0]->location->shelf == 'A');
  CU_ASSERT(db->inventory[0]->location->place == 1);
  CU_ASSERT(db->inventory[0]->price == 101);
  CU_ASSERT(db->inventory[0]->amount == 1337);
  free(db);
  free(latest);
}

void add_to_db(DB db, Item v);

void testAdd_to_db() {
DB db = malloc(sizeof(db) * 10);
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

  add_to_db(db, v1);
  add_to_db(db, v2);
  add_to_db(db, v3);
  add_to_db(db, v4);
  add_to_db(db, v5);
  add_to_db(db, v6);

  for(int i = 0; i < 6; i++){
    CU_ASSERT(db->inventory[i] != NULL);
  }

  CU_ASSERT(db->amount == 6);
  CU_ASSERT(db->inventory[2]->amount == 33);
  CU_ASSERT(db->inventory[2]->price == 0);
  CU_ASSERT(db->inventory[2]->name == "Banana");
  CU_ASSERT(db->inventory[2]->description == "Disgusting");
  free(v1);
  free(v2);
  free(v3);
  free(v4);
  free(v5);
  free(v6);
  free(db);
}


char ask_char_question(char* question, char* answer);

void testAsk_char_question() {
    char* question;
    char* answer;
    char result = ask_char_question(question, answer);
    if (1) {
        CU_ASSERT(0);
    }
}


_Bool ask_int(char* question, Item item, int op);

void testAsk_int() {
  /*
    char* question;
    Item item;
    int op;
    _Bool result = ask_int(question, item, op);
    if (1) {
        CU_ASSERT(0);
    }
*/
}


void ask_name(char* question, Item item, int op);

void testAsk_name() {
  /*
    char* question;
    Item item;
    int op;
    ask_name(question, item, op);
    if (1) {
        CU_ASSERT(0);
    }
*/
}


_Bool ask_yes_no(char* question);

void testAsk_yes_no() {
  /*
    char* question;
    _Bool result = ask_yes_no(question);
    if (1) {
        CU_ASSERT(0);
    }
*/
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
  /*
    Item item;
    LastAction lastAct;
    copy_to_last_action(item, lastAct);
    if (1) {
        CU_ASSERT(0);
    }
*/
}


void delete_by_location(DB db, char shelf, int place, LastAction lastAct);

void testDelete_by_location() {
  /*
    DB db;
    char shelf;
    int place;
    LastAction lastAct;
    delete_by_location(db, shelf, place, lastAct);
    if (1) {
        CU_ASSERT(0);
    }
*/
}


void delete_by_name(DB db, char* s, LastAction lastAct);

void testDelete_by_name() {
  /*
    DB db;
    char* s;
    LastAction lastAct;
    delete_by_name(db, s, lastAct);
    if (1) {
        CU_ASSERT(0);
    }
*/
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
