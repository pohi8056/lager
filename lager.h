#ifndef LAGER_H
#define LAGER_H

typedef struct item_t *Item; //pekare till adress

typedef struct db_t *DB;

void add_to_db(DB db, Item v);
void print_main_menu();
void add_item(DB db);
bool ask_yes_no(char* question);
char ask_char_question(char *question, char *answer);
void print_item(Item i);



#endif
