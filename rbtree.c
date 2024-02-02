/*
** rbtree.c for epitech in /home/chapui_s/travaux/rbtree/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Mon Feb 16 00:30:33 2015 chapui_s
** Last update Mon Feb 16 00:51:05 2015 chapui_s
*/

#include "rbtree.h"

t_rbnode *root_rbtree = (t_rbnode *)0;

static inline int is_red(t_rbnode *node) { return ((node) ? (node->color == RED) : (0)); }

static inline int my_compare(unsigned int key1, unsigned int key2) { return ((key1 == key2) ? (0) : ((key1 < key2) ? (-1) : (1))); }

static void flip_color(t_rbnode *node) {
  node->color = !(node->color);
  node->left->color = !(node->left->color);
  node->right->color = !(node->right->color);
}

static t_rbnode *rotate_left(t_rbnode *left) {
  t_rbnode *right;

  if (!left) return ((t_rbnode *)0);
  right = left->right;
  left->right = right->left;
  right->left = left;
  right->color = left->color;
  left->color = RED;
  return (right);
}

static t_rbnode *rotate_right(t_rbnode *right) {
  t_rbnode *left;

  if (!right) return ((t_rbnode *)0);
  left = right->left;
  right->left = left->right;
  left->right = right;
  left->color = right->color;
  right->color = RED;
  return (left);
}

t_rbnode *create_node(t_key key, t_value value) {
  t_rbnode *new;

  if ((new = (t_rbnode *)malloc(sizeof(*new))) == (t_rbnode *)0) return ((t_rbnode *)0);
  new->key = key;
  new->value = value;
  new->color = RED;
  new->left = (t_rbnode *)0;
  new->right = (t_rbnode *)0;
  return (new);
}

static t_rbnode *insert_this(t_rbnode *node, t_key key, t_value value) {
  int res;

  if (!node) return (create_node(key, value));
  res = my_compare(key, node->key);
  if (res == 0)
    node->value = value;
  else if (res < 0)
    node->left = insert_this(node->left, key, value);
  else
    node->right = insert_this(node->right, key, value);
  if (is_red(node->right) && !is_red(node->left)) node = rotate_left(node);
  if (is_red(node->left) && is_red(node->left->left)) node = rotate_right(node);
  if (is_red(node->left) && is_red(node->right)) flip_color(node);
  return (node);
}

void insert(t_key key, t_value value) {
  root_rbtree = insert_this(root_rbtree, key, value);
  if (root_rbtree) root_rbtree->color = BLACK;
}

t_value get_key(t_rbnode *node, t_key key) {
  int cmp;

  while (node) {
    if (!(cmp = my_compare(key, node->key))) return (node->value);
    node = ((cmp < 0) ? (node->left) : (node->right));
  }
  return (0);
}

static t_rbnode *min(t_rbnode *node) {
  if (!node) return ((t_rbnode *)0);
  while (node->left) node = node->left;
  return (node);
}

inline t_rbnode *balance_me_that(t_rbnode *node) {
  if (is_red(node->right)) node = rotate_left(node);
  if (is_red(node->left) && is_red(node->left->left)) node = rotate_right(node);
  if (is_red(node->left) && is_red(node->right)) flip_color(node);
  return (node);
}

static t_rbnode *move_red_to_left(t_rbnode *node) {
  flip_color(node);
  if (node && node->right && is_red(node->right->left)) {
    node->right = rotate_right(node->right);
    node = rotate_left(node);
    flip_color(node);
  }
  return (node);
}

static t_rbnode *move_red_to_right(t_rbnode *node) {
  flip_color(node);
  if (node && node->left && is_red(node->left->left)) {
    node = rotate_right(node);
    flip_color(node);
  }
  return (node);
}

static t_rbnode *remove_min(t_rbnode *node) {
  if (!node) return ((t_rbnode *)0);
  if (!node->left) {
    free(node);
    return ((t_rbnode *)0);
  }
  if (!is_red(node->left) && !is_red(node->left->left)) node = move_red_to_left(node);
  node->left = remove_min(node->left);
  return (balance_me_that(node));
}

static t_rbnode *remove_it(t_rbnode *node, t_key key) {
  t_rbnode *tmp;

  if (!node) return ((t_rbnode *)0);
  if (my_compare(key, node->key) == -1) {
    if (node->left) {
      if (!is_red(node->left) && !is_red(node->left->left)) node = move_red_to_left(node);
      node->left = remove_key(node->left, key);
    }
  } else {
    if (is_red(node->left)) node = rotate_right(node);
    if (!my_compare(key, node->key) && !node->right) {
      free(node);
      return ((t_rbnode *)0);
    }
    if (node->right) {
      if (!is_red(node->right) && !is_red(node->right->left)) node = move_red_to_right(node);
      if (!my_compare(key, node->key)) {
        tmp = min(node->right);
        node->key = tmp->key;
        node->value = tmp->value;
        node->right = remove_min(node->right);
      } else
        node->right = remove_key(node->right, key);
    }
  }
  return (balance_me_that(node));
}

t_rbnode *remove_key(t_rbnode *node, t_key key) {
  node = remove_it(node, key);
  if (node) node->color = BLACK;
  return (node);
}

t_rbnode *erase_tree(t_rbnode *node) {
  if (node) {
    if (node->left) erase_tree(node->left);
    if (node->right) erase_tree(node->right);
    node->left = (t_rbnode *)0;
    node->right = (t_rbnode *)0;
    free(node);
  }
  return ((t_rbnode *)0);
}
