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

    for (size_t i = 0; i < artist_length; i++) // check if there is an artist with this ID
        if (artist[i].id == id)
            artist_exist = 1;

    if (artist_exist == 1)
        return id;
    else
        return -1;
}

int verify_registered_artist(Artist *artist, int artist_length)
{
    int are_registered = 0;

    for (size_t i = 0; i < artist_length; i++) // checks how many artist are registered
        if (artist[i].id > -1)
            are_registered++;

    return are_registered;
}

int verify_registered_music(Music *music, int music_length)
{
    int are_registered = 0;

    for (size_t i = 0; i < music_length; i++) // checks how many musics are registered
        if (music[i].id > -1)
            are_registered++;

    return are_registered;
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
    printf("\n\t4 - delete");
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

char menu_by()
{
    char option;

    printf("\n\t1 - By artist ID");
    printf("\n\t2 - By music ID");
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

char menu_delete()
{
    char option;

    printf("\n\n\t0 - Skip");
    printf("\n\t1 - delete an artist");
    printf("\n\t2 - delete a music");
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

Artist *realloc_artist(Artist *artist, int *artist_length)
{
    (*artist_length) += 5;
    artist = realloc(artist, (*artist_length) * sizeof(Artist)); // realloc with new length

    for (size_t i = ((*artist_length) - 5); i < (*artist_length); i++) // initialize new artists
        initialize_artist(&artist[i]);

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

Artist *register_artist_option(Artist *artist, int *artist_length, int *counter_artist)
{
    if ((*counter_artist) > (*artist_length) - 1) // realloc when it passes the limit
        artist = realloc_artist(artist, artist_length);

    artist[(*counter_artist)].id = (*counter_artist); // gives a value for the artist's ID

    register_artist(&artist[(*counter_artist)]);

    (*counter_artist)++; // increments for the next ID

    return artist;
}

Music *register_music_option(Artist *artist, int artist_length, Music *music, int *music_length, int *counter_music)
{
    int id;

    if (verify_registered_artist(artist, artist_length) != 0) // checks if there are any artists açready registered
    {
        do // artist's ID must exist
        {
            id = select_artist(artist, artist_length); // choose an artist to which the music will be registered

            if (id != -1) // register a music if the artist was find
            {
                if ((*counter_music) > (*music_length) - 1) // realloc when the index is over size
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
    char option_by;

    if (verify_registered_artist(artist, artist_length) != 0) // checks if it has at least one artist
    {
        option_by = menu_by();

        if (option_by == '1') // by artist ID
            edit_artist_by_artist_id(artist, music, artist_length);
        else if (option_by == '2') // by music ID
        {
            if (verify_registered_music(music, music_length) != 0) // checks if it has at least one music
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
    char option_by;

    if (verify_registered_music(music, music_length) != 0) // checks if it has at least one music
    {
        option_by = menu_by();

        if (option_by == '1') // by artist ID
            edit_music_by_artist_id(artist, music, artist_length, music_length);
        else if (option_by == '2') // by music ID
            edit_music_by_music_id(music, artist_length, music_length);
        else
            printf("\n\n\tInvalid option!!!");
    }
    else
        printf("\n\tNo music registered... you must have at least one registered music!!");
}

void list_all_option(Artist *artist, Music *music, int artist_length, int music_length)
{
    if (verify_registered_artist(artist, artist_length) != 0 && verify_registered_music(music, music_length) != 0) // checks if it has at least one artist & music
    {
        list_artist(artist, music, artist_length, music_length);
        printf("\n");
        list_music(music, music_length, artist);
    }
    else if (verify_registered_artist(artist, artist_length) != 0) // checks if it has at least one artist
        list_artist(artist, music, artist_length, music_length);
    else if (verify_registered_music(music, music_length) != 0) // checks if it has at least one music
        list_music(music, music_length, artist);
    else
        printf("\n\tNo artists and no musics to list...");
}

void list_artist_option(Artist *artist, Music *music, int artist_length, int music_length)
{
    if (verify_registered_artist(artist, artist_length) != 0) // checks if it has at least one artist
        list_artist(artist, music, artist_length, music_length);
    else
        printf("\n\tNo artists and no musics to list...");
}

void list_music_option(Artist *artist, Music *music, int music_length)
{
    if (verify_registered_music(music, music_length) != 0 != 0) // checks if it has at least one music
        list_music(music, music_length, artist);
    else
        printf("\n\tNo artists and no musics to list...");
}

void delete_artist_option(Artist *artist, Music *music, int artist_length, int music_length)
{
    char option_by;
    int alert = 1;
    int id;

    option_by = menu_by();

    if (verify_registered_artist(artist, artist_length) != 0) // checks if it has at least one artist
    {
        if (option_by == '1') // by artist ID
        {
            printf("\n\tArtist ID to be deleted: ");
            scanf("%d", &id);

            delete_artist_by_artist_id(artist, music, artist_length, music_length, id, alert);
        }
        else if (option_by == '2') // by music ID
        {
            if (verify_registered_music(music, music_length) != 0) // checks if it has at least one music
                delete_artist_by_music_id(artist, music, artist_length, music_length);
            else
                printf("\n\tNo music registered... you must have at least one registered music!!");
        }
        else
            printf("\n\n\tInvalid option!!!");
    }
    else
        printf("\n\n\tNo registered artist... you must have at least one registered artist!!");
}

void delete_music_option(Artist *artist, Music *music, int artist_length, int music_length)
{
    char option_by;

    if (verify_registered_music(music, music_length) != 0) // checks if it has at least one music
    {
        option_by = menu_by();

        if (option_by == '1') // by artist ID
            delete_music_by_artist_id(artist, music, artist_length, music_length);
        else if (option_by == '2') // by music ID
            delete_music_by_music_id(artist, music, music_length);
        else
            printf("\n\n\tInvalid option!!!");
    }
    else
        printf("\n\tNo music registered... you must have at least one registered music!!");
}

void serach_artist_option(Artist *artist, Music *music, int artist_length, int music_length)
{
    char option_by;

    if (verify_registered_artist(artist, artist_length) != 0) // checks if it has at least one artist
    {
        option_by = menu_by();

        if (option_by == '1') // by artist ID
            search_artist_by_artist_id(artist, music, artist_length, music_length);
        else if (option_by == '2') // by music ID
            search_artist_by_music_id(artist, music, artist_length, music_length);
        else
            printf("\n\n\tInvalid option!!!");
    }
    else
        printf("\n\tNo artist registered... you must have at least one registered artist!!");
}

void serach_music_option(Artist *artist, Music *music, int artist_length, int music_length)
{
    char option_by;

    if (verify_registered_music(music, music_length) != 0) // checks if it has at least one music
    {
        option_by = menu_by();

        if (option_by == '1') // by artist ID
            search_music_by_artist_id(artist, music, artist_length, music_length);
        else if (option_by == '2') // by music ID
            search_music_by_music_id(artist, music, artist_length, music_length);
        else
            printf("\n\n\tInvalid option!!!");
    }
    else
        printf("\n\tNo music registered... you must have at least one registered music!!");
}

void export_option(Artist *artist, Music *music, int artist_length, int music_length)
{
    if (verify_registered_artist(artist, artist_length) != 0) // checks if it has at least one artist
        export_artist(artist, artist_length);
    else
        printf("\n\tNo artist registered... you must have at least one registered artist!!");

    if (verify_registered_music(music, music_length) != 0) // checks if it has at least one music
        export_music(music, artist, music_length);
    else
        printf("\n\tNo music registered... you must have at least one registered music!!");
}

void exit_option(Artist *artist, Music *music, int counter_artist, int counter_music, int first_time)
{
    FILE *save_data;

    if (first_time == 1)                     // if it's first time using this software
        save_data = fopen("data.dat", "wb"); // create the file to put the data
    else
        save_data = fopen("data.dat", "r+b"); // open existing file to add new data

    if (save_data == NULL)
    {
        printf("Error opening file...\n");
        exit(1);
    }

    artist = realloc(artist, counter_artist * sizeof(Artist)); // realloc with new length
    music = realloc(music, counter_music * sizeof(Music));     // realloc with new length

    fwrite(&counter_artist, sizeof(int), 1, save_data);
    fwrite(&counter_music, sizeof(int), 1, save_data);
    fwrite(artist, sizeof(Artist), counter_artist, save_data);
    fwrite(music, sizeof(Music), counter_music, save_data);

    fclose(save_data);
}

void menu_main(Artist *artist, Music *music, int first_time)
{
    char option_main_menu;
    char option_sub_menu;
    int artist_length = 5;
    int music_length = 5;
    int counter_artist = 0;
    int counter_music = 0;
    FILE *load;

    if (first_time == 0) // load preview data when not the first time using this software
    {
        load = fopen("data.dat", "r+b");

        fread(&artist_length, sizeof(int), 1, load);
        fread(&music_length, sizeof(int), 1, load);

        counter_artist = artist_length;
        counter_music = music_length;

        artist = realloc(artist, artist_length * sizeof(Artist)); // realloc with new length
        music = realloc(music, music_length * sizeof(Music));     // realloc with new length

        fread(artist, sizeof(Artist), artist_length, load);
        fread(music, sizeof(Music), music_length, load);

        fclose(load);
    }

    do // exit from main menu when option is '0'
    {
        option_main_menu = menu_options();

        switch (option_main_menu)
        {
        case '1': // register
            do    // option must be '1', '2' or '0'
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

        case '2': // edit
            do    // option must be '1', '2' or '0'
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

        case '3': // list
            do    // option must be '1', '2' or '0'
            {
                option_sub_menu = menu_list();
                if (option_sub_menu == '0')
                    break;

                if (option_sub_menu == '1') // list all
                    list_all_option(artist, music, artist_length, music_length);
                else if (option_sub_menu == '2') // list an artist
                    list_artist_option(artist, music, artist_length, music_length);
                else if (option_sub_menu == '3') // list a music
                    list_music_option(artist, music, music_length);
                else
                    printf("\n\n\tInvalid option!!!");
            } while (option_sub_menu != '1' && option_sub_menu != '2' && option_sub_menu != '3');
            break;

        case '4': // delete
            do    // option must be '1', '2' or '0'
            {
                option_sub_menu = menu_delete();
                if (option_sub_menu == '0')
                    break;

                if (option_sub_menu == '1') // delete an artist
                    delete_artist_option(artist, music, artist_length, music_length);
                else if (option_sub_menu == '2') // delete a music
                    delete_music_option(artist, music, artist_length, music_length);
                else
                    printf("\n\n\tInvalid option!!!");
            } while (option_sub_menu != '1' && option_sub_menu != '2');
            break;

        case '5': // search
            do    // option must be '1', '2' or '0'
            {
                option_sub_menu = menu_search();
                if (option_sub_menu == '0')
                    break;

                if (option_sub_menu == '1') // search an artist
                    serach_artist_option(artist, music, artist_length, music_length);
                else if (option_sub_menu == '2') // search a music
                    serach_music_option(artist, music, artist_length, music_length);
                else
                    printf("\n\n\tInvalid option!!!");
            } while (option_sub_menu != '1' && option_sub_menu != '2');
            break;

        case '6': // export data
            export_option(artist, music, artist_length, music_length);
            break;

        case '7': // clear screen
            system(CLEAN);
            break;

        case '0': // exit
            exit_option(artist, music, counter_artist, counter_music, first_time);
            break;

        default:
            printf("\n\n\tInvalid option!!!");
            break;
        }
    } while (option_main_menu != '0');
}
