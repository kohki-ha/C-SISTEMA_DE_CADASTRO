#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/music.h"

void register_music(Music *music)
{
    printf("\n\tName: ");
    setbuf(stdin, NULL);
    fgets(music->name, 30, stdin);
    music->name[strcspn(music->name, "\n")] = '\0';
    printf("\n%s\n", music->name);

    printf("\n\tAlbum: ");
    setbuf(stdin, NULL);
    fgets(music->album, 30, stdin);
    music->album[strcspn(music->album, "\n")] = '\0';
    printf("\n%s\n", music->album);

    printf("\n\tGenre: ");
    setbuf(stdin, NULL);
    fgets(music->genre, 30, stdin);
    music->genre[strcspn(music->genre, "\n")] = '\0';
    printf("\n%s\n", music->genre);

    printf("\n\tSong length (min:sec): ");
    scanf("%d:%d", &music->song_length.minutes, &music->song_length.seconds);
    printf("\n%d:%d\n", music->song_length.minutes, music->song_length.seconds);

    printf("\n\tRelease date (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &music->release_date.day, &music->release_date.month, &music->release_date.year);
    printf("%d/%d/%d", music->release_date.day, music->release_date.month, music->release_date.year);
}