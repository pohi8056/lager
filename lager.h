#ifndef LAGER_H
#define LAGER_H

struct item_t;
typedef struct item_t *Item; //pekare till adress

struct db_t;
typedef struct db_t *DB;

struct last_action_t;
typedef struct last_action_t *LastAction;

struct location_t;
typedef struct location_t *Location;

void print_main_menu(char *user);
void undo(DB db, LastAction latest);
void add_to_db(DB db, Item v);
void readd_to_db(DB db, LastAction lastAct);
void add_item(DB db, LastAction latest);

/**
 * @param db The database with items.
 * @param *s  String to be compared.
 * @param lastAct Latest item.
 * @brief Removes an item from the database if the database contains s.
 * Iterates through the database to check if string matches an item name.
 * If a match is found, the item gets removed from the database and is stored to the 
 * temporary lastAct item.
 * @return void
 */

void delete_by_name(DB db, char *s, LastAction lastAct);

/**
 * @param db The database with items.
 * @param shelf The shelf where the item is stored.
 * @param place Place on the shelf.
 * @param lastAct Latest item.
 * @brief Removes the item at location shelf and place.
 * Iterates through the database to check if string matches an item location.
 * If a match is found, the item gets removed from the database and is stored to the 
 * temporary lastAct item.
 * @return void
 */

void delete_by_location(DB db, char shelf, int place, LastAction lastAct);

/**
 * @param db The database with items.
 * @param lastAct Latest item.
 * @brief Asks user for either an item to be deleted or a location to be deleted.
 * The user can choose between deleting an item by name or location, in both occourences a question
 * follows asking for either name or location.
 * @return void
 */

void delete_item(DB db, LastAction lastAct);

/**
 * @param db The database with items.
 * @param item Item to be assigned a location.
 * @brief Automatically assigns an empty location for a new item.
 * Checks for the first empty location in the format A1, A2, A3, A4 B1, ..., F4 and assigns the item * to that location. 
 * @return void
 */

void assignLocation(DB db, Item item);

/**
 * @param *question Question to be asked.
 * @param item Item to be updated.
 * @param op Operation to be made where 1 is update amount and 2 is update price. 
 * @brief Asks user for integer input and validates that the reply is an integer.
 * Requests user input and validates that it contains only integers. If successful validation - updates either amount or price depending on the variable op.
 * @return void
 */

bool ask_int(char *question, Item item, int op);


/**
 * @param *question Question to be asked.
 * @param item Item to be updated.
 * @param op Operation to be made where 1 is update amount and 2 is update price. 
 * @brief Asks user for integer input and validates that the reply is an integer.
 * Requests user input and validates that it contains only integers. If successful validation - updates either amount or price depending on the variable op.
 * @return void
 */

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
