/*
** EPITECH PROJECT, 2024
** B-MUL-100-TLS-1-1-myhunter-pavel.de-wavrechin
** File description:
** engine
*/

#ifndef INCLUDED_ENGINE_H
    #define INCLUDED_ENGINE_H
    #include "my_hunter.h"
    #include "structure.h"
    #include "ressources.h"

engine_t *load_game(char *title, int width, unsigned int height, unsigned int default_framerate);

#endif