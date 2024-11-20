/*
** EPITECH PROJECT, 2024
** B-MUL-100-TLS-1-1-myhunter-pavel.de-wavrechin
** File description:
** event_manager
*/

#include <SFML/Graphics.h>
#include "../../include/my_hunter.h"
#include "../../include/structure.h"
#include "../../include/event.h"

void analyse_event(sfRenderWindow *window, sfEvent *event)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window);
}