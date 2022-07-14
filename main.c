#include <stdlib.h>
#include <stdio.h>
#include "lib/artist.h"
#include "lib/music.h"
#include "lib/menu.h"

int main(int argc, char const *argv[])
{
    Artist *artist = malloc(5 * sizeof(Artist));
    Music *music = malloc(5 * sizeof(Music));

    artist = malloc(5 * sizeof(Artist));
    music = malloc(5 * sizeof(Music));

    for (size_t i = 0; i < 5; i++)
        artist[i].music = malloc(5 * sizeof(Music));

    for (size_t i = 0; i < 5; i++)
    {
        initialize_artist(&artist[i]);
        initialize_music(&music[i]);
    }

    menu_main(artist, music);

    return 0;
}
