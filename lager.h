#ifndef LAGER_H
#define LAGER_H

struct item_t;
typedef struct item_t *Item; //pekare till adress
struct db_t;
typedef struct db_t *DB;
struct location_t;


void add_to_db(DB db, Item v);
void print_main_menu();
void add_item(DB db);
bool ask_yes_no(char* question);
char ask_char_question(char *question, char *answer);
void print_item(Item i);



#endif
