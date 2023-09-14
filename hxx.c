#include "hxx.h"

/*
 * after done read user input, dump to temp file or database
 */

struct node {
  char* store_data;
  struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

/* need to load data from file before showing list */
void show_list(void) {
  struct node *point = head;
  while (point != NULL) {
    printf("%s\n", point->store_data);
    point = point->next;
  }
}

/* save data to file */
void add_list(char* user_input) {
  struct node *data = (struct node *) malloc(sizeof(struct node));
  data->store_data = user_input;
  data->next = head;
  head = data;
}

void display_help(void) {
  puts("usage:\n"
       "  hxx [option] <data>\n"
       "\nbasic crud app with linked list\n"
       "\noptions:\n"
       "  -a : add data to program list\n"
       "  -d : delete from program list\n"
       "  -v : view data that store in this program\n"
       "  -e : edit entity of node in this program.\n"
       "       for example `-e <node> <newdata>`\n"
       "  -h : show this help message\n"
       );
}

int main(int argc, char** argv) {
  int opt;
  const char* optstring = "aedhv:";
  while ((opt = getopt(argc, argv, optstring)) != -1) {
    switch (opt) {
      case 'a':
        add_list(argv[2]);
        break;
      case 'e':
        puts("edited has be saved");
        break;
      case 'v':
        show_list();
        puts("showing all record");
        break;
      case 'd':
        puts("done deleting");
        break;
      case 'h':
        display_help();
        break;
      default:
        puts("unknown options. type `hxx -h` for more info");
        break;
    }
  }
  return EXIT_SUCCESS;
}
