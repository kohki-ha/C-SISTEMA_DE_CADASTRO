#include <stdlib.h>
#include <stdio.h>
#include "./lib/artist.h"
#include "./lib/music.h"
#include "./lib/menu.h"

int main(int argc, char const *argv[])
{
    Artist *artist;
    Music *music;

    artist = malloc(5 * sizeof(Artist)); // starts storage at 5
    music = malloc(5 * sizeof(Music));   // starts storage at 5

    for (size_t i = 0; i < 5; i++) // set initial values for the structs members
    {
        initialize_artist(&artist[i]);
        initialize_music(&music[i]);
    }

    menu_main(artist, music); // call main menu

    return 0;
}
