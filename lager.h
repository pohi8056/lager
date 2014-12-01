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
void delete_by_name(DB db, char *s, LastAction lastAct);
void delete_by_location(DB db, char shelf, int place, LastAction lastAct);
void delete_item(DB db, LastAction lastAct);
void assignLocation(DB db, Item item);
bool ask_int(char *question, Item item, int op);
void ask_name(char *question, Item item, int op);
bool ask_yes_no(char* question);
char ask_string_question(char *question);
char ask_char_question(char *question, char *answer);


void print_item(Item i);
bool print_inventory(DB database);



#endif
