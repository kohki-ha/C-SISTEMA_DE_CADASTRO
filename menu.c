#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

Artist *realloc_artist(Artist *artist, int *artist_length)
{
    (*artist_length) += 5;
    artist = realloc(artist, (*artist_length) * sizeof(Artist));

    for (size_t i = ((*artist_length) - 4); i < (*artist_length); i++)
        initialize_artist(&artist[i]);

    return artist;
}

Music *realloc_music(Music *music, int *music_length)
{
    (*music_length) += 5;
    music = realloc(music, (*music_length) * sizeof(Music));

    for (size_t i = ((*music_length) - 4); i < (*music_length); i++)
        initialize_music(&music[i]);

    return music;
}

void initialize_artist(Artist *artist)
{
    artist->id = -1;
    artist->age = -1;
    strcpy(artist->name, "NOT REGISTERED");
    strcpy(artist->gender, "NOT REGISTERED");
    strcpy(artist->country, "NOT REGISTERED");

    for (size_t i = 0; i < 5; i++)
    {
        artist->music[i].id = -1;
        strcpy(artist->music[i].name, "NOT REGISTERED");
        strcpy(artist->music[i].album, "NOT REGISTERED");
        strcpy(artist->music[i].genre, "NOT REGISTERED");
        artist->music[i].song_length.minutes = -1;
        artist->music[i].song_length.seconds = -1;
        artist->music[i].release_date.day = -1;
        artist->music[i].release_date.month = -1;
        artist->music[i].release_date.year = -1;
    }
}

void initialize_artist_music(Artist *artist)
{
    for (size_t i = 0; i < 5; i++)
    {
        artist->music[i].id = -1;
        strcpy(artist->music[i].name, "NOT REGISTERED");
        strcpy(artist->music[i].album, "NOT REGISTERED");
        strcpy(artist->music[i].genre, "NOT REGISTERED");
        artist->music[i].song_length.minutes = -1;
        artist->music[i].song_length.seconds = -1;
        artist->music[i].release_date.day = -1;
        artist->music[i].release_date.month = -1;
        artist->music[i].release_date.year = -1;
    }
}

void initialize_music(Music *music)
{
    music->id = -1;
    strcpy(music->name, "NOT REGISTERED");
    strcpy(music->album, "NOT REGISTERED");
    strcpy(music->genre, "NOT REGISTERED");
    music->song_length.minutes = -1;
    music->song_length.seconds = -1;
    music->release_date.day = -1;
    music->release_date.month = -1;
    music->release_date.year = -1;
}

int verify_registered_artist(Artist *artist, int artist_length)
{
    int are_registered = 0;

    for (size_t i = 0; i < artist_length; i++)
        if (artist[i].id > -1)
            are_registered++;

    return are_registered;
}

int verify_registered_music(Music *music, int music_length)
{
    int are_registered = 0;

    for (size_t i = 0; i < music_length; i++)
        if (music[i].id > -1)
            are_registered++;

    return are_registered;
}

int select_artist(Artist *artist, int artist_length)
{
    int id;
    int artist_exist = 0;

    printf("\n\tSelect an artist ID to register a music: ");
    scanf("%d", &id);

    for (size_t i = 0; i < artist_length; i++)
        if (artist[i].id == id)
            artist_exist = 1;

    if (artist_exist == 1)
        return id;
    else
        return -1;
}

char menu_options()
{
    char option;

    printf("\n\n\n\tMENU\n");
    printf("\n\t0 - Exit\n");
    printf("\n\t1 - Register");
    printf("\n\t(artist & music)\n");
    printf("\n\t2 - Edit");
    printf("\n\t(artist & music)\n");
    printf("\n\t3 - List");
    printf("\n\t(all & artist & music)\n");
    printf("\n\t4 - Remove");
    printf("\n\t(artist & music)\n");
    printf("\n\t5 - Search");
    printf("\n\t(artist & music)\n");
    printf("\n\t6 - Export data\n");
    printf("\n\t7 - Clear screen\n");
    printf("\n\t>>> ");
    setbuf(stdin, NULL);
    scanf("%c", &option);

    return option;
}

void register_artist_option(Artist *artist, int artist_length, int *counter_artist)
{
    if ((*counter_artist) > artist_length - 1)
        artist = realloc_artist(artist, &artist_length);

    printf("\n\n\t%d\n", (*counter_artist));
    artist[(*counter_artist)].id = (*counter_artist);
    register_artist(&artist[(*counter_artist)]);
    (*counter_artist)++;
}

void register_music_option(Artist *artist, int artist_length, Music *music, int *music_length, int *counter_music)
{
    int id;
    int aux = 0;

    if (verify_registered_artist(artist, artist_length) != 0)
    {
        do
        {
            id = select_artist(artist, artist_length);

            if (id != -1)
            {
                if ((*counter_music) > (*music_length) - 1)
                    music = realloc_music(music, music_length);

                printf("\n\n\t%d\n", (*counter_music));
                music[(*counter_music)].id = (*counter_music);
                register_music(&music[(*counter_music)]);

                for (size_t i = 0; i < 5; i++)
                    if (artist[id].music[i].id == -1)
                    {
                        artist[id].music[i] = music[(*counter_music)];
                        aux = 1;
                        break;
                    }
                if (aux = 0)
                    printf("\n\tNo music storage for this artist...");

                (*counter_music)++;
            }
            else
                printf("\n\n\tArtist not found...");
        } while (id == -1);
    }
    else
        printf("\n\n\tNo registered artist... you must have at least one registered artist!!");
}

char menu_register()
{
    char option;

    printf("\n\n\t1 - Register an artist");
    printf("\n\t2 - Register a music");
    printf("\n\t>>> ");
    setbuf(stdin, NULL);
    scanf("%c", &option);

    return option;
}

char menu_edit()
{
    char option;

    printf("\n\n\t1 - Edit by artist ID");
    printf("\n\t2 - Edit by music ID");
    printf("\n\t>>> ");
    setbuf(stdin, NULL);
    scanf("%c", &option);

    return option;
}

char menu_list()
{
    char option;

    printf("\n\n\t1 - List all");
    printf("\n\t2 - List an artist");
    printf("\n\t3 - List a music");
    printf("\n\t>>> ");
    setbuf(stdin, NULL);
    scanf("%c", &option);

    return option;
}

char menu_remove()
{
    char option;

    printf("\n\n\t1 - Remove an artist");
    printf("\n\t2 - Remove a music");
    printf("\n\t>>> ");
    setbuf(stdin, NULL);
    scanf("%c", &option);

    return option;
}

char menu_search()
{
    char option;

    printf("\n\n\t1 - Search an artist");
    printf("\n\t2 - Search a music");
    printf("\n\t>>> ");
    setbuf(stdin, NULL);
    scanf("%c", &option);

    return option;
}

void menu_main(Artist *artist, Music *music)
{
    char option_main_menu;
    char option_sub_menu;
    int artist_length = 5;
    int music_length = 5;
    int counter_artist = 0;
    int counter_music = 0;

    do
    {
        option_main_menu = menu_options();

        switch (option_main_menu)
        {

        case '1':
            do
            {
                option_sub_menu = menu_register();

                if (option_sub_menu == '1')
                    register_artist_option(artist, artist_length, &counter_artist);
                else if (option_sub_menu == '2')
                    register_music_option(artist, artist_length, music, &music_length, &counter_music);
                else
                    printf("\n\n\tInvalid option!!!");
            } while (option_sub_menu != '1' && option_sub_menu != '2');
            break;

        case '2':
            do
            {
                option_sub_menu = menu_edit();

                if (option_sub_menu == '1')
                    edit_artist_by_artist_id(artist, music, artist_length);
                else if (option_sub_menu == '2')
                {
                    if (verify_registered_music(music, music_length) != 0)
                        edit_artist_by_music_id(artist, music, artist_length, music_length);
                    else
                        printf("\n\tNo music registered...");
                }
                else
                    printf("\n\n\tInvalid option!!!");
            } while (option_sub_menu != '1' && option_sub_menu != '2');
            break;

        case '3':
            do
            {
                option_sub_menu = menu_list();

                if (option_sub_menu == '1') // list all
                {
                    /// list_all();
                    printf("\na\n");
                }
                else if (option_sub_menu == '2') // list an artist
                {
                    /// list_artist();
                    printf("\na\n");
                }

                else if (option_sub_menu == '3') // list a music
                {
                    /// list_music();
                    printf("\na\n");
                }
                else
                    printf("\n\n\tInvalid option!!!");
            } while (option_sub_menu != '1' && option_sub_menu != '2' && option_sub_menu != '3');
            break;

        case '4':
            do
            {
                option_sub_menu = menu_remove();

                if (option_sub_menu == '1') // remove an artist
                {
                    /// remove_artist();
                    printf("\na\n");
                }
                else if (option_sub_menu == '2') // remove a music
                {
                    /// remove_music();
                    printf("\na\n");
                }
                else
                    printf("\n\n\tInvalid option!!!");
            } while (option_sub_menu != '1' && option_sub_menu != '2');
            break;

        case '5':
            do
            {
                option_sub_menu = menu_search();

                if (option_sub_menu == '1') // search an artist
                {
                    /// search_artist();
                }
                else if (option_sub_menu == '2') // search a music
                {
                    /// search_music();
                }
                else
                    printf("\n\n\tInvalid option!!!");
            } while (option_sub_menu != '1' && option_sub_menu != '2');

            break;

        case '6': // export data
            /// export_data();
            break;

        case '7': // clear screen
            system(CLEAN);
            break;

        case '0': // exit
            break;

        default:
            printf("\n\n\tInvalid option!!!");
            break;
        }
    } while (option_main_menu != '0');
}
