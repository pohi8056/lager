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
    DB db;
    LastAction latest;
    add_item(db, latest);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

void add_to_db(DB db, Item v);

void testAdd_to_db() {
    DB db;
    Item v;
    add_to_db(db, v);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

char ask_char_question(char* question, char* answer);

void testAsk_char_question() {
    char* question;
    char* answer;
    char result = ask_char_question(question, answer);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

_Bool ask_int(char* question, Item item, int op);

void testAsk_int() {
    char* question;
    Item item;
    int op;
    _Bool result = ask_int(question, item, op);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

void ask_name(char* question, Item item, int op);

void testAsk_name() {
    char* question;
    Item item;
    int op;
    ask_name(question, item, op);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

_Bool ask_yes_no(char* question);

void testAsk_yes_no() {
    char* question;
    _Bool result = ask_yes_no(question);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

void assignLocation(DB db, Item item);

void testAssignLocation() {
    DB db;
    Item item;
    assignLocation(db, item);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

void copy_to_last_action(Item item, LastAction lastAct);

void testCopy_to_last_action() {
    Item item;
    LastAction lastAct;
    copy_to_last_action(item, lastAct);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

void delete_by_location(DB db, char shelf, int place, LastAction lastAct);

void testDelete_by_location() {
    DB db;
    char shelf;
    int place;
    LastAction lastAct;
    delete_by_location(db, shelf, place, lastAct);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

void delete_by_name(DB db, char* s, LastAction lastAct);

void testDelete_by_name() {
    DB db;
    char* s;
    LastAction lastAct;
    delete_by_name(db, s, lastAct);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

void delete_item(DB db, LastAction lastAct);

void testDelete_item() {
    DB db;
    LastAction lastAct;
    delete_item(db, lastAct);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

void edit_by_name(DB db, char* s, LastAction lastAct);

void testEdit_by_name() {
    DB db;
    char* s;
    LastAction lastAct;
    edit_by_name(db, s, lastAct);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

void edit_item(DB db, LastAction lastAct);

void testEdit_item() {
    DB db;
    LastAction lastAct;
    edit_item(db, lastAct);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

void edit_item_parameters(Item i);

void testEdit_item_parameters() {
    Item i;
    edit_item_parameters(i);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

void print_inventory(DB database);

void testPrint_inventory() {
    DB database;
    print_inventory(database);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

_Bool print_inventory_loop(DB database);

void testPrint_inventory_loop() {
    DB database;
    _Bool result = print_inventory_loop(database);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

void print_item(Item i);

void testPrint_item() {
    Item i;
    print_item(i);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

void print_main_menu(char* user);

void testPrint_main_menu() {
    char* user;
    print_main_menu(user);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

void readd_to_db(DB db, LastAction lastAct);

void testReadd_to_db() {
    DB db;
    LastAction lastAct;
    readd_to_db(db, lastAct);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

void undo(DB db, LastAction lastAct);

void testUndo() {
    DB db;
    LastAction lastAct;
    undo(db, lastAct);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
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
