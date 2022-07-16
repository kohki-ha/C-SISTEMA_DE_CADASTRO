#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/music.h"

void register_music(Music *music)
{
    printf("\n\tName: ");
    setbuf(stdin, NULL);
    fgets(music->name, 21, stdin);
    music->name[strcspn(music->name, "\n")] = '\0';

    printf("\n\tAlbum: ");
    setbuf(stdin, NULL);
    fgets(music->album, 21, stdin);
    music->album[strcspn(music->album, "\n")] = '\0';

    printf("\n\tGenre: ");
    setbuf(stdin, NULL);
    fgets(music->genre, 21, stdin);
    music->genre[strcspn(music->genre, "\n")] = '\0';

    printf("\n\tSong length (min:sec): ");
    scanf("%d:%d", &music->song_length.minutes, &music->song_length.seconds);

    printf("\n\tRelease date (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &music->release_date.day, &music->release_date.month, &music->release_date.year);
}

void edit_music_name(Music *music)
{
    char option;

    do
    {
        printf("\n\n\tOld name: %s", music->name);
        printf("\n\tEdit music name? (y/n): ");
        setbuf(stdin, NULL);
        scanf("%c", &option);
        if (option == 'y')
        {
            printf("\n\tNew name: ");
            setbuf(stdin, NULL);
            fgets(music->name, 21, stdin);
            music->name[strcspn(music->name, "\n")] = '\0';
        }
        else if (option != 'n')
            printf("\n\n\tInvalid option!!!\n");
    } while (option != 'y' && option != 'n');
}

void edit_music_album(Music *music)
{
    char option;

    do
    {
        printf("\n\n\tOld album: %s", music->album);
        printf("\n\tEdit music album? (y/n): ");
        setbuf(stdin, NULL);
        scanf("%c", &option);
        if (option == 'y')
        {
            printf("\n\tNew album: ");
            setbuf(stdin, NULL);
            fgets(music->album, 21, stdin);
            music->album[strcspn(music->album, "\n")] = '\0';
        }
        else if (option != 'n')
            printf("\n\n\tInvalid option!!!\n");
    } while (option != 'y' && option != 'n');
}

void edit_music_genre(Music *music)
{
    char option;

    do
    {
        printf("\n\n\tOld genre: %s", music->genre);
        printf("\n\tEdit music genre? (y/n): ");
        setbuf(stdin, NULL);
        scanf("%c", &option);
        if (option == 'y')
        {
            printf("\n\tNew genre: ");
            setbuf(stdin, NULL);
            fgets(music->genre, 21, stdin);
            music->genre[strcspn(music->genre, "\n")] = '\0';
        }
        else if (option != 'n')
            printf("\n\n\tInvalid option!!!\n");
    } while (option != 'y' && option != 'n');
}

void edit_music_song_length(Music *music)
{
    char option;

    do
    {
        printf("\n\n\tOld music length: %d:%d\n", music->song_length.minutes, music->song_length.seconds);
        printf("\n\tEdit music length? (y/n): ");
        setbuf(stdin, NULL);
        scanf("%c", &option);
        if (option == 'y')
        {
            printf("\n\tNew song length (min:sec): ");
            scanf("%d:%d", &music->song_length.minutes, &music->song_length.seconds);
        }
        else if (option != 'n')
            printf("\n\n\tInvalid option!!!\n");
    } while (option != 'y' && option != 'n');
}

void edit_music_release_date(Music *music)
{
    char option;

    do
    {
        printf("\n\n\tOld realease date: %d/%d/%d", music->release_date.day, music->release_date.month, music->release_date.year);
        printf("\n\tEdit music realease date? (y/n): ");
        setbuf(stdin, NULL);
        scanf("%c", &option);
        if (option == 'y')
        {
            printf("\n\tNew release date (dd/mm/aaaa): ");
            scanf("%d/%d/%d", &music->release_date.day, &music->release_date.month, &music->release_date.year);
        }
        else if (option != 'n')
            printf("\n\n\tInvalid option!!!\n");
    } while (option != 'y' && option != 'n');
}

void edit_music(Music *music)
{
    char option;

    edit_music_name(music);
    edit_music_album(music);
    edit_music_genre(music);
    edit_music_song_length(music);
    edit_music_release_date(music);
}

int artists_num_of_music(Artist *artist, Music *music, int music_length)
{
    int num_musics = 0;
    for (size_t i = 0; i < music_length; i++)
    {
        if (music[i].id_artist == artist->id)
            num_musics++;
    }

    return num_musics;
}

void show_artists_musics(Artist *artist, Music *music, int music_length)
{
    printf("\n\tArtist's musics:");
    for (size_t i = 0; i < music_length; i++)
        if (artist->id == music[i].id_artist)
            printf("\n\tMusic name: %21s | ID: %-2d", music[i].name, music[i].id);
}

void edit_music_by_artist_id(Artist *artist, Music *music, int artist_length, int music_length)
{
    int id_artist;
    int id_music;
    int number_of_musics = 0;
    int found = -1;

    printf("\n\tArtist ID to be edited: ");
    scanf("%d", &id_artist);

    for (size_t i = 0; i < artist_length; i++)
        if (artist[i].id == id_artist)
            found = 1;

    if (found == 1)
    {
        if (artists_num_of_music(&artist[id_artist], music, music_length) > 0)
        {
            show_artists_musics(&artist[id_artist], music, music_length);
            printf("\n\tMusic ID to be edited: ");
            scanf("%d", &id_music);

            for (size_t i = 0; i < music_length; i++)
                if(music[i].id == id_music)
                    edit_music(&music[id_music]);
            
        }
        else
            printf("\n\tNo music registered for this artist...");
    }
    else
        printf("\n\tArtist ID not found...");
}

void edit_music_by_music_id(Music *music, int artist_length, int music_length)
{
    int id;
    int found = -1;

    printf("\n\tMusic ID to be edited: ");
    scanf("%d", &id);

    for (size_t i = 0; i < music_length; i++)
        if (id == music[i].id)
            found = 1;

    if (found == -1)
        edit_music(&music[id]);
    else
        printf("\n\tArtist music ID not found...");
}

void list_music(Music *music, int music_length, Artist *artist)
{
    printf("\n\n\tMusic list");
    printf("\n\tID | Name                  | Artist name           | Album                 | Genre                 | Song length | Release date\n");
    for (size_t i = 0; i < music_length; i++)
    {
        if (music[i].id > -1)
            printf("\t%-2d | %-21s | %-21s | %-21s | %-21s | %02d:%02d | %-2d/%-2d/%-4d\n", music[i].id, music[i].name, artist[music[i].id_artist].name, music[i].album, music[i].genre, music[i].song_length.minutes, music[i].song_length.seconds, music[i].release_date.day, music[i].release_date.month, music[i].release_date.year);
    }
}
