/*
** main.c for epitech in /home/chapui_s/travaux/rbtree/main.c
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Mon Feb 16 00:46:44 2015 chapui_s
** Last update Mon Feb 16 01:55:11 2015 chapui_s
*/

#include <time.h>
#include "rbtree.h"

extern t_rbnode *root_rbtree;

int main()
{

  /* root_rbtree = NULL; */
  /* insert(16, 16); */
  /* insert(24, 24); */
  /* insert(32, 32); */
  /* insert(40, 40); */
  /* insert(48, 48); */
  /* insert(80, 80); */
  /* insert(31426, 31426); */
  /* insert(31424, 31424); */
  /* root_rbtree = remove_k(root_rbtree, 31426); */
  /* root_rbtree = remove_k(root_rbtree, 31424); */
  /* root_rbtree = remove_k(root_rbtree, 24); */
  /* root_rbtree = remove_k(root_rbtree, 40); */
  /* root_rbtree = remove_k(root_rbtree, 48); */
  /* print_ascii_tree(root_rbtree); */

  unsigned int i;
  int a;
  srandom(time(NULL));
  for (i = 0; i < 30; ++i) {
    /* printf("\nboucle numero %d\n", i); */
    a = random() % 100;
    insert(a, a);
//    insert(i + 'A', i + 'A');
    /* if (i % 50 == 0 && i > 0) */
    /*   remove_key(root_rbtree, random() % i); */
    /* print_ascii_tree(root_rbtree); */
  }

  /* remove_key(root_rbtree, 70); */
  /* remove_key(root_rbtree, 70); */
  /* remove_key(root_rbtree, 70); */
  /* insert(70, 70); */
  /* insert(70, 70); */
  /* insert(70, 70); */
  /* insert(70, 70); */
  /* insert(70, 70); */
  /* remove_key(root_rbtree, 72); */
  /* remove_key(root_rbtree, 68); */
  /* remove_key(root_rbtree, 69); */
  /* remove_key(root_rbtree, 65); */
  /* remove_key(root_rbtree, 66); */

  /* insert(66, 66); */
  /* insert(75, 75); */
  /* insert(76, 76); */
  /* insert(77, 77); */

  /* for (unsigned int i = 65; i < 75; ++i) */
  /*   root_rbtree = remove_key(root_rbtree, i); */

//  root_rbtree = erase_tree(root_rbtree);
//  print_ascii_tree(root_rbtree);
//  printf("root_rbtree: %c\n", root_rbtree->key);
  erase_tree(root_rbtree);
  return (0);
}
