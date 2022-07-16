#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/menu.h"

void initialize_artist(Artist *artist)
{
    artist->id = -1;
    artist->age = -1;
    strcpy(artist->name, "NOT REGISTERED");
    strcpy(artist->gender, "NOT REGISTERED");
    strcpy(artist->country, "NOT REGISTERED");
}

void initialize_music(Music *music)
{
    music->id = -1;
    music->id_artist = -1;
    strcpy(music->name, "NOT REGISTERED");
    strcpy(music->album, "NOT REGISTERED");
    strcpy(music->genre, "NOT REGISTERED");
    music->song_length.minutes = -1;
    music->song_length.seconds = -1;
    music->release_date.day = -1;
    music->release_date.month = -1;
    music->release_date.year = -1;
}

int select_artist(Artist *artist, int artist_length)
{
    int id;
    int artist_exist = 0;

    printf("\n\tSelect an artist ID to register a music: ");
    scanf("%d", &id);

    for (size_t i = 0; i < artist_length; i++) // check if thre is an artist with this ID 
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

Artist *realloc_artist(Artist *artist, int *artist_length)
{
    (*artist_length) += 5;
    artist = realloc(artist, (*artist_length) * sizeof(Artist)); // realloc with new length

    for (size_t i = ((*artist_length) - 5); i < (*artist_length); i++) // initialize new artists
        initialize_artist(&artist[i]);

    return artist;
}

Artist *register_artist_option(Artist *artist, int *artist_length, int *counter_artist)
{
    if ((*counter_artist) > (*artist_length) - 1) // realloc when it passes the limit
        artist = realloc_artist(artist, artist_length);

    artist[(*counter_artist)].id = (*counter_artist); // gives a value for the artist's ID
    register_artist(&artist[(*counter_artist)]);

    (*counter_artist)++; // increments for the next ID

    return artist;
}

Music *realloc_music(Music *music, int *music_length)
{
    (*music_length) += 5; 
    music = realloc(music, (*music_length) * sizeof(Music)); // realloc with new length

    for (size_t i = ((*music_length) - 4); i < (*music_length); i++) // initialize new musics
        initialize_music(&music[i]);

    return music;
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

Music *register_music_option(Artist *artist, int artist_length, Music *music, int *music_length, int *counter_music)
{
    int id;

    if (verify_registered_artist(artist, artist_length) != 0) // checks if there are any artists açready registered
    {
        do
        {
            id = select_artist(artist, artist_length); // choose an artist to which the music will be registered

            if (id != -1) // if artist was find
            {
                printf("\n\n\t%d\n", (*counter_music));

                if ((*counter_music) > (*music_length) - 1)
                    music = realloc_music(music, music_length);

                music[(*counter_music)].id = (*counter_music);
                music[(*counter_music)].id_artist = id;

                register_music(&music[(*counter_music)]);

                (*counter_music)++;
            }
            else
                printf("\n\n\tArtist not found...");
        } while (id == -1);
    }
    else
        printf("\n\n\tNo registered artist... you must have at least one registered artist!!");

    return music;
}

void edit_artist_option(Artist *artist, Music *music, int artist_length, int music_length)
{
    char option_edit_by;

    if (verify_registered_artist(artist, artist_length) != 0)
    {
        option_edit_by = menu_edit_by();

        if (option_edit_by == '1') // edit by artist ID
            edit_artist_by_artist_id(artist, music, artist_length);
        else if (option_edit_by == '2') // edit by music ID
        {
            if (verify_registered_music(music, music_length) != 0)
                edit_artist_by_music_id(artist, music, artist_length, music_length);
            else
                printf("\n\tNo music registered... you must have at least one registered music!!");
        }
        else
            printf("\n\n\tInvalid option!!!");
    }
    else
        printf("\n\n\tNo registered artist... you must have at least one registered artist!!");
}

void edit_music_option(Artist *artist, Music *music, int artist_length, int music_length)
{
    char option_edit_by;

    if (verify_registered_music(music, music_length) != 0)
    {
        option_edit_by = menu_edit_by();

        if (option_edit_by == '1') // edit by artist ID
            edit_music_by_artist_id(artist, music, artist_length, music_length);
        else if (option_edit_by == '2') // edit by music ID
            edit_music_by_music_id(music, artist_length, music_length);
        else
            printf("\n\n\tInvalid option!!!");
    }
    else
        printf("\n\tNo music registered... you must have at least one registered music!!");
}

void remove_artist_option(Artist *artist, Music *music, int artist_length, int music_length)
{
    char option_edit_by;
    int id;

    option_edit_by = menu_edit_by();

    if (option_edit_by == '1') // by artist ID
    {
        printf("\n\tArtist ID to be removed: ");
        scanf("%d", &id);
        remove_artist_by_artist_id(artist, music, artist_length, music_length, id);
    }
    else if (option_edit_by == '2') // by music ID
    {
        if (verify_registered_music(music, music_length) != 0)
            remove_artist_by_music_id(artist, music, artist_length, music_length);
        else
            printf("\n\tNo music registered... you must have at least one registered music!!");
    }
    else
        printf("\n\n\tInvalid option!!!");
}

char menu_register()
{
    char option;

    printf("\n\n\t0 - Skip");
    printf("\n\t1 - Register an artist");
    printf("\n\t2 - Register a music");
    printf("\n\t>>> ");
    setbuf(stdin, NULL);
    scanf("%c", &option);

    return option;
}

char menu_edit_main()
{
    char option;

    printf("\n\n\t0 - Skip");
    printf("\n\t1 - Edit artist");
    printf("\n\t2 - Edit music");
    printf("\n\t>>> ");
    setbuf(stdin, NULL);
    scanf("%c", &option);

    return option;
}

char menu_edit_by()
{
    char option;

    printf("\n\t1 - Edit by artist ID");
    printf("\n\t2 - Edit by music ID");
    printf("\n\t>>> ");
    setbuf(stdin, NULL);
    scanf("%c", &option);

    return option;
}

char menu_list()
{
    char option;

    printf("\n\n\t0 - Skip");
    printf("\n\t1 - List all");
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

    printf("\n\n\t0 - Skip");
    printf("\n\t1 - Remove an artist");
    printf("\n\t2 - Remove a music");
    printf("\n\t>>> ");
    setbuf(stdin, NULL);
    scanf("%c", &option);

    return option;
}

char menu_search()
{
    char option;

    printf("\n\n\t0 - Skip");
    printf("\n\t1 - Search an artist");
    printf("\n\t2 - Search a music");
    printf("\n\t>>> ");
    setbuf(stdin, NULL);
    scanf("%c", &option);

    return option;
}

void list_all(Artist *artist, Music *music, int artist_length, int music_length)
{
    if (verify_registered_artist(artist, artist_length) != 0 && verify_registered_music(music, music_length) != 0)
    {
        list_artist(artist, artist_length);
        list_music(music, music_length, artist);
    }
    else if (verify_registered_artist(artist, artist_length) != 0 && verify_registered_music(music, music_length) == 0)
        list_artist(artist, artist_length);
    else if (verify_registered_artist(artist, artist_length) == 0 && verify_registered_music(music, music_length) != 0)
        list_music(music, music_length, artist);
    else
        printf("\n\tNo artists and no music to list...");
}

void menu_main(Artist *artist, Music *music)
{
    char option_main_menu;
    char option_sub_menu;
    char option_edit_by;
    int artist_length = 5;
    int music_length = 5;
    int counter_artist = 0;
    int counter_music = 0;
    int id;

    do
    {
        option_main_menu = menu_options();

        switch (option_main_menu)
        {
        case '1':
            do
            {
                option_sub_menu = menu_register();
                if (option_sub_menu == '0')
                    break;

                if (option_sub_menu == '1')
                    artist = register_artist_option(artist, &artist_length, &counter_artist);
                else if (option_sub_menu == '2')
                    music = register_music_option(artist, artist_length, music, &music_length, &counter_music);
                else
                    printf("\n\n\tInvalid option!!!");
            } while (option_sub_menu != '1' && option_sub_menu != '2');
            break;

        case '2':
            do
            {
                option_sub_menu = menu_edit_main();
                if (option_sub_menu == '0')
                    break;

                if (option_sub_menu == '1') // edit artist
                    edit_artist_option(artist, music, artist_length, music_length);
                else if (option_sub_menu == '2') // edit music
                    edit_music_option(artist, music, artist_length, music_length);
                else
                    printf("\n\n\tInvalid option!!!");

            } while (option_sub_menu != '1' && option_sub_menu != '2');
            break;

        case '3':
            do
            {
                option_sub_menu = menu_list();
                if (option_sub_menu == '0')
                    break;

                if (option_sub_menu == '1') // list all
                    list_all(artist, music, artist_length, music_length);
                else if (option_sub_menu == '2') // list an artist
                    list_artist(artist, artist_length);
                else if (option_sub_menu == '3') // list a music
                    list_music(music, music_length, artist);
                else
                    printf("\n\n\tInvalid option!!!");
            } while (option_sub_menu != '1' && option_sub_menu != '2' && option_sub_menu != '3');
            break;

        case '4':
            do
            {
                option_sub_menu = menu_remove();
                if (option_sub_menu == '0')
                    break;

                if (option_sub_menu == '1') // remove an artist
                    remove_artist_option(artist, music, artist_length, music_length);
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
                if (option_sub_menu == '0')
                    break;

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
