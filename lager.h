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
 * A structure to represent an item.
 */
typedef struct item_t *Item; //pekare till adress

/**
 * A structure to represent a database.
 */
typedef struct db_t *DB;

/**
 * A structure to represent the latest change in the database.
 */
typedef struct last_action_t *LastAction;

/**
 * A structure to represent an items location in the database.
 */
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
