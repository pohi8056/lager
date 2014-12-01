#ifndef LAGER_H
#define LAGER_H

/**
 * @file lager.h
 * @author Pontus Hilding
 * @author Lukas Hamberg
 * @date 1 Dec 2014
 * @brief A simple inventory database.
 *
 *
 *
 *
 * @see http://auportal.herokuapp.com/lectures/28
 */


/**
 * A structure to represent a database.
 */
struct item_t;


/**
 * A structure to represent a database.
 */
typedef struct item_t *Item; //pekare till adress

struct db_t;
typedef struct db_t *DB;

struct last_action_t;
typedef struct last_action_t *LastAction;

struct location_t;
typedef struct location_t *Location;


void undo(DB db, LastAction latest);

void readd_to_db(DB db, LastAction lastAct);

void add_to_db(DB db, Item v);
void add_item(DB db, LastAction latest);

void delete_by_name(DB db, char *s, LastAction lastAct);
void delete_by_location(DB db, char shelf, int place, LastAction lastAct);
void delete_item(DB db, LastAction lastAct);

void assignLocation(DB db, Item item);

bool ask_int(char *question, Item item, int op);
void ask_name(char *question, Item item, int op);
bool ask_yes_no(char* question);
char ask_string_question(char *question);
char ask_char_question(char *question, char *answer);
Item return_item(DB db, char *s);
void copy_to_last_action(Item item, LastAction lastAct);
void print_item(Item i);
bool print_inventory_loop(DB database);
void print_inventory(DB database);

void edit_item(DB db, LastAction lastAct);
void edit_by_name(DB db, char *s, LastAction lastAct);
void edit_item_parameters(Item i);


#endif
