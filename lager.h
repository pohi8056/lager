#ifndef LAGER_H
#define LAGER_H
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
 * A structure to represent an item.
 */
struct item_t;
typedef struct item_t *Item; //pekare till adress

/**
 * A structure to represent a database.
 */
struct db_t;
typedef struct db_t *DB;

/**
 * A structure to represent the latest change in the database.
 */
struct last_action_t;
typedef struct last_action_t *LastAction;

/**
 * A structure to represent an items location in the database.
 */
struct location_t;
typedef struct location_t *Location;


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



/**
 * @param name Name of the user
 * Prints the programs main menu where the name gives the user a specific welcome.
 * @return void
 */

void print_main_menu(char *user);

/**
 * @param db The database with items.
 * @param lastAct Latest item modified.
 * @brief Undo latest change.
 * Reverts the latest change made in the program depending on the latest action made. Can be undoing adding an item, deleting an item or editing an item.
 * @return void
 */

void undo(DB db, LastAction lastAct);

/**
 * @param db The database with items
 * @param v Item to be added
 * Adds an item to the database and increments the database amount.
 * @return void
 */

void add_to_db(DB db, Item v);

/**
 * @param db The database with items
 * @param lastAct Latest item modified
 * Re-adds a deleted item to the database from the latest item memory and increments the database amount.
 * @return void
 */

void readd_to_db(DB db, LastAction lastAct);


/**
 * @param db The database with items
 * @param lastAct Latest item modified
 * Asks for user input of item to be added.
 * @return void
 */

void add_item(DB db, LastAction latest);

/**
 * @param db The database with items.
 * @param *s  String to be compared.
 * @param lastAct Latest item modified
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
 * @param lastAct Latest item modified..
 * @brief Removes the item at location shelf and place.
 * Iterates through the database to check if string matches an item location.
 * If a match is found, the item gets removed from the database and is stored to the 
 * temporary lastAct item.
 * @return void
 */

void delete_by_location(DB db, char shelf, int place, LastAction lastAct);

/**
 * @param db The database with items.
 * @param lastAct Latest item modified..
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
 * @return bool
 */
void ask_name(char *question, Item item, int op);



/**
 * @param question       question printed to the terminal.
 * @brief Prints a question to the terminal and waits for user input.
 * A question is printed to the terminal and the user must enter characters representing either
 * yes or no. A 'yes' will return true, 'no' will return false.
 * @return bool
 */
bool ask_yes_no(char* question);



/**
 * @param question       question printed to the terminal.
 * @param answer         array of characters which are valid user input.
 * @brief Prints a question to the terminal and waits for user input, returning a character from answer.
 * A question is printed to the terminal and the user must enter one of the characters
 * specified by answer. The chosen character is then returned by the function.
 * @return char
 */
char ask_char_question(char *question, char *answer);



/**
 *  @param item          the item to be copied and saved.
 *  @param lastAct       stores a copy of item in case of undo action.
 *  @brief Copies the item to enable an undo action.
 *  All specifications of item are copied and saved in
 *  lastAct in case of undo action.
 */
void copy_to_last_action(Item item, LastAction lastAct);





/**
 *  @param i             the item to be printed the terminal.
 *  @brief Prints an item to terminal.
 *  All specifications for item i are printed to the terminal. 
 */
void print_item(Item i);




/**
 *  @param database      the database containing the items to be printed the terminal.
 *  @brief Prints all items in the given database to terminal.
 *  Prints all items in the given database to terminal, then asks user yes/no question.
 *  The function returns true if user answers yes, false if no.
 *  @returns bool
 */
bool print_inventory_loop(DB database);




/**
 *  @param database      the database containing the items to be printed the terminal. 
 *  @brief Prints all items in the given database to terminal.
 *  Prints all specifications of all items to terminal.  
 */
void print_inventory(DB database);





/**
 *  @param db            the database containing items.
 *  @param lastAct       used to store edit action in case of later undo action.
 *  @brief Edits a item specified by user input.
 *  If user provides name of item stored in database, said item is updated according
 *  to user input. 
 */
void edit_item(DB db, LastAction lastAct);





/**
 *  @param db            the database containing items.
 *  @param s             the name of the item to be edited.
 *  @param lastAct       used to store un-edited item in case of later undo action.
 *  @brief Edits a item specified by item name s.
 *  The item in the database with the name s will be updated according to
 *  user input. The un edited item is stored in lastAct in case user wishes to undo
 *  edit.
 */
void edit_by_name(DB db, char *s, LastAction lastAct);





/**
 *  @param i             item to be edited.
 *  @brief Edits a specification for item i depending in user input.
 *  The user specifies through terminal input what
 *  info in the item i will be edited.
 */
void edit_item_parameters(Item i);


#endif
