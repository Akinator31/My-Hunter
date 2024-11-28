/*
** EPITECH PROJECT, 2024
** B-MUL-100-TLS-1-1-myhunter-pavel.de-wavrechin
** File description:
** help_display
*/

#include <unistd.h>
#include "structure.h"
#include "utils.h"

static const char *help_message = "=============================\n"
    "       KFC HUNTER GAME       \n"
    "=============================\n"
    "\n"
    "DESCRIPTION:\n"
    "  In KFC HUNTER, your goal is to shoot as many chicken as possible.\n"
    "  Chicken will fly across the screen, and you need to aim and click\n"
    "  to score points.\n"
    "\n"
    "USAGE:\n"
    "  ./my_hunter [options]\n"
    "\n"
    "OPTIONS:\n"
    "  -h          Show this help message.\n"
    "\n"
    "CONTROLS:\n"
    "  Mouse       Aim and shoot.\n"
    "\n"
    "GOOD LUCK!\n";

int help(int ac, char **av)
{
    if ((ac > 2) || (my_strcmp(av[1], "-h") != 0)) {
        return 84;
    }
    write(1, help_message, my_strlen(help_message) + 1);
    return 0;
}
