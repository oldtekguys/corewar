/*
** op.c for  korewar
**
** Made by Astek
** Login   <astek@epitech.net>
**
** Started on  Mon Mar 30 11:14:31 2009 Astek
*/

/*
** Ne pas passer ce fichier dans la moulinette de Norme.
*/

#include <stdlib.h>
#include "op.h"

op_t    op_tab[] =
  {
    {"live", 1, {T_DIR}, 1, 10, "alive", {0}, NULL},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", {0}, NULL},
    {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", {0}, NULL},
    {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", {0}, NULL},
    {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", {0}, NULL},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
     "et (and  r1, r2, r3   r1&r2 -> r3", {0}, NULL},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
     "ou  (or   r1, r2, r3   r1 | r2 -> r3", {0}, NULL},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
     "ou (xor  r1, r2, r3   r1^r2 -> r3", {0}, NULL},
    {"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", {0}, NULL},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
     "load index", {0}, NULL},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
     "store index", {0}, NULL},
    {"fork", 1, {T_DIR}, 12, 800, "fork", {0}, NULL},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", {0}, NULL},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
     "long load index", {0}, NULL},
    {"lfork", 1, {T_DIR}, 15, 1000, "long fork", {0}, NULL},
    {"aff", 1, {T_REG}, 16, 2, "aff", {0}, NULL},
    {0, 0, {0}, 0, 0, 0, {0}, NULL}
  };
