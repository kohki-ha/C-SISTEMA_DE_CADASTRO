#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/artist.h"

void register_artist(Artist *artist)
{
    printf("\n\tName: ");
    setbuf(stdin, NULL);
    fgets(artist->name, 21, stdin);
    artist->name[strcspn(artist->name, "\n")] = '\0';

    printf("\n\tAge: ");
    scanf("%d", &artist->age);

    printf("\n\tGender: ");
    setbuf(stdin, NULL);
    fgets(artist->gender, 21, stdin);
    artist->gender[strcspn(artist->gender, "\n")] = '\0';

    printf("\n\tCountry: ");
    setbuf(stdin, NULL);
    fgets(artist->country, 21, stdin);
    artist->country[strcspn(artist->country, "\n")] = '\0';
}

char edit_artist_options(Artist *artist)
{
    char option;

    printf("\n\n\t1 - Edit name");
    printf("\n\t2 - Edit age");
    printf("\n\t2 - Edit gender");
    printf("\n\t2 - Edit country");
    printf("\n\t>>> ");
    setbuf(stdin, NULL);
    scanf("%c", &option);

    return option;
}

void edit_artist_name(Artist *artist)
{
    char option;

    do
    {
        printf("\n\n\tOld name: %s", artist->name);
        printf("\n\tEdit artist name? (y/n): ");
        setbuf(stdin, NULL);
        scanf("%c", &option);
        if (option == 'y')
        {
            printf("\n\tNew name: ");
            setbuf(stdin, NULL);
            fgets(artist->name, 21, stdin);
            artist->name[strcspn(artist->name, "\n")] = '\0';
        }
        else if (option != 'n')
            printf("\n\n\tInvalid option!!!\n");
    } while (option != 'y' && option != 'n');
}

void edit_artist_age(Artist *artist)
{
    char option;

    do
    {
        printf("\n\n\tOld age: %d", artist->age);
        printf("\n\tEdit artist age? (y/n): ");
        setbuf(stdin, NULL);
        scanf("%c", &option);
        if (option == 'y')
        {
            printf("\n\tNew age: ");
            scanf("%d", &artist->age);
        }
        else if (option != 'n')
            printf("\n\n\tInvalid option!!!\n");
    } while (option != 'y' && option != 'n');
}

void edit_artist_gender(Artist *artist)
{
    char option;

    do
    {
        printf("\n\n\tOld gender: %s", artist->gender);
        printf("\n\tEdit artist gender? (y/n): ");
        setbuf(stdin, NULL);
        scanf("%c", &option);
        if (option == 'y')
        {
            printf("\n\tNew gender: ");
            setbuf(stdin, NULL);
            fgets(artist->gender, 21, stdin);
            artist->gender[strcspn(artist->gender, "\n")] = '\0';
        }
        else if (option != 'n')
            printf("\n\n\tInvalid option!!!\n");
    } while (option != 'y' && option != 'n');
}

void edit_artist_country(Artist *artist)
{
    char option;

    do
    {
        printf("\n\n\tOld country: %s", artist->country);
        printf("\n\tEdit artist country? (y/n): ");
        setbuf(stdin, NULL);
        scanf("%c", &option);
        if (option == 'y')
        {
            printf("\n\tNew country: ");
            setbuf(stdin, NULL);
            fgets(artist->country, 21, stdin);
            artist->country[strcspn(artist->country, "\n")] = '\0';
        }
        else if (option != 'n')
            printf("\n\n\tInvalid option!!!\n");
    } while (option != 'y' && option != 'n');
}

void edit_artist(Artist *artist, Music *music)
{
    edit_artist_name(artist);
    edit_artist_age(artist);
    edit_artist_gender(artist);
    edit_artist_country(artist);
}

void edit_artist_by_artist_id(Artist *artist, Music *music, int artist_length)
{
    int id;
    int found = -1;

    printf("\n\tArtist ID to be edited: ");
    scanf("%d", &id);

    for (size_t i = 0; i < artist_length; i++)
        if (artist[i].id == id)
            found = 1;

    if (found > -1)
        edit_artist(&artist[id], music);
    else
        printf("\n\tArtist ID not found...");
}

void edit_artist_by_music_id(Artist *artist, Music *music, int artist_length, int music_length)
{
    int id;
    int found = -1;

    printf("\n\tArtist's music ID to be edited: ");
    scanf("%d", &id);

    for (size_t i = 0; i < music_length; i++)
        if(id == music[i].id_artist)
            found = 1;
    
    if (found > -1)
        edit_artist(&artist[music[id].id_artist], music);
    else
        printf("\n\tArtist music ID not found...");
}

void list_artist(Artist *artist, int artist_length)
{
    printf("\n\n\tArtist list");
    printf("\n\tID | Name                  | Age | Gender                | Country             \n");
    for (size_t i = 0; i < artist_length; i++)
        if (artist[i].id > -1)
            printf("\t%-2d | %-21s | %-3d | %-21s | %-21s\n", artist[i].id, artist[i].name, artist[i].age, artist[i].gender, artist[i].country);
}

void remove_artist_by_artist_id(Artist *artist, Music *music, int artist_length, int music_length, int id)
{
    for (size_t i = 0; i < artist_length; i++)
        if(artist[i].id == id)
        {
            for (size_t j = 0; j < music_length; j++)
            {
                if(music[j].id_artist == artist[i].id)
                    music[j].id = -1;
            }

            artist[i].id = -1;
        }    
}

void remove_artist_by_music_id(Artist *artist, Music *music, int artist_length, int music_length)
{
    int id;

    printf("\n\tArtist's music ID to be removed: ");
    scanf("%d", &id);

    for (size_t i = 0; i < music_length; i++)
        if(music[i].id == id)
            for (size_t j = 0; j < artist_length; j++)
                if(music[i].id_artist == artist[j].id)
                    remove_artist_by_artist_id(artist, music, artist_length, music_length, id);
}