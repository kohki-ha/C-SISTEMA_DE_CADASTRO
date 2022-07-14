#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/artist.h"

void register_artist(Artist *artist)
{
    printf("\n\tName: ");
    setbuf(stdin, NULL);
    fgets(artist->name, 30, stdin);
    artist->name[strcspn(artist->name, "\n")] = '\0';
    printf("\n%s\n", artist->name);

    printf("\n\tAge: ");
    scanf("%d", &artist->age);
    printf("\n%d\n", artist->age);

    printf("\n\tGender: ");
    setbuf(stdin, NULL);
    fgets(artist->gender, 30, stdin);
    artist->gender[strcspn(artist->gender, "\n")] = '\0';
    printf("\n%s\n", artist->gender);

    printf("\n\tCountry: ");
    setbuf(stdin, NULL);
    fgets(artist->country, 30, stdin);
    artist->country[strcspn(artist->country, "\n")] = '\0';
    printf("\n%s\n", artist->country);
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

int verify_artist_musics(Artist *artist)
{
    int music_amount = 0;

    for (size_t i = 0; i < 5; i++)
        if (artist->music[i].id != -1)
            music_amount++;

    return music_amount;
}

void edit_artist_name(Artist *artist)
{
    char option;

    do
    {
        printf("\n\n\tEdit artist name? (y/n): ");
        setbuf(stdin, NULL);
        scanf("%c", &option);
        if (option == 'y')
        {
            printf("\n\tNew name: ");
            setbuf(stdin, NULL);
            fgets(artist->name, 30, stdin);
            artist->name[strcspn(artist->name, "\n")] = '\0';
            printf("\n%s\n", artist->name);
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
        printf("\n\n\tEdit artist age? (y/n): ");
        setbuf(stdin, NULL);
        scanf("%c", &option);
        if (option == 'y')
        {
            printf("\n\tNew age: ");
            scanf("%d", &artist->age);
            printf("\n%d\n", artist->age);
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
        printf("\n\n\tEdit artist gender? (y/n): ");
        setbuf(stdin, NULL);
        scanf("%c", &option);
        if (option == 'y')
        {
            printf("\n\tNew gender: ");
            setbuf(stdin, NULL);
            fgets(artist->gender, 30, stdin);
            artist->gender[strcspn(artist->gender, "\n")] = '\0';
            printf("\n%s\n", artist->gender);
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
        printf("\n\n\tEdit artist country? (y/n): ");
        setbuf(stdin, NULL);
        scanf("%c", &option);
        if (option == 'y')
        {
            printf("\n\tNew country: ");
            setbuf(stdin, NULL);
            fgets(artist->country, 30, stdin);
            artist->country[strcspn(artist->country, "\n")] = '\0';
            printf("\n%s\n", artist->country);
        }
        else if (option != 'n')
            printf("\n\n\tInvalid option!!!\n");
    } while (option != 'y' && option != 'n');
}

void edit_artist_music_name(Artist *artist, int i)
{
    char option;

    do
    {
        printf("\n\n\tEdit music name? (y/n): ");
        setbuf(stdin, NULL);
        scanf("%c", &option);
        if (option == 'y')
        {
            printf("\n\tNew name: ");
            setbuf(stdin, NULL);
            fgets(artist->music[i].name, 30, stdin);
            artist->music[i].name[strcspn(artist->music[i].name, "\n")] = '\0';
            printf("\n%s\n", artist->music[i].name);
        }
        else if (option != 'n')
            printf("\n\n\tInvalid option!!!\n");
    } while (option != 'y' && option != 'n');
}

void edit_artist_music_album(Artist *artist, int i)
{
    char option;

    do
    {
        printf("\n\n\tEdit music album? (y/n): ");
        setbuf(stdin, NULL);
        scanf("%c", &option);
        if (option == 'y')
        {
            printf("\n\tNew album: ");
            setbuf(stdin, NULL);
            fgets(artist->music[i].album, 30, stdin);
            artist->music[i].album[strcspn(artist->music[i].album, "\n")] = '\0';
            printf("\n%s\n", artist->music[i].album);
        }
        else if (option != 'n')
            printf("\n\n\tInvalid option!!!\n");
    } while (option != 'y' && option != 'n');
}

void edit_artist_music_genre(Artist *artist, int i)
{
    char option;

    do
    {
        printf("\n\n\tEdit music genre? (y/n): ");
        setbuf(stdin, NULL);
        scanf("%c", &option);
        if (option == 'y')
        {
            printf("\n\tNew genre: ");
            setbuf(stdin, NULL);
            fgets(artist->music[i].genre, 30, stdin);
            artist->music[i].genre[strcspn(artist->music[i].genre, "\n")] = '\0';
            printf("\n%s\n", artist->music[i].genre);

        }
        else if (option != 'n')
            printf("\n\n\tInvalid option!!!\n");
    } while (option != 'y' && option != 'n');

}

void edit_artist_music_song_length(Artist *artist, int i)
{
    char option;

    do
    {
        printf("\n\n\tEdit music length? (y/n): ");
        setbuf(stdin, NULL);
        scanf("%c", &option);
        if (option == 'y')
        {
            printf("\n\tNew song length (min:sec): ");
            scanf("%d:%d", &artist->music[i].song_length.minutes, &artist->music[i].song_length.seconds);
            printf("\n%d:%d\n", artist->music[i].song_length.minutes, artist->music[i].song_length.seconds);

        }
        else if (option != 'n')
            printf("\n\n\tInvalid option!!!\n");
    } while (option != 'y' && option != 'n');

}

void edit_artist_music_release_date(Artist *artist, int i)
{
    char option;

    do
    {
        printf("\n\n\tEdit music realease date? (y/n): ");
        setbuf(stdin, NULL);
        scanf("%c", &option);
        if (option == 'y')
        {
            printf("\n\tNew release date (dd/mm/aaaa): ");
            scanf("%d/%d/%d", &artist->music[i].release_date.day, &artist->music[i].release_date.month, &artist->music[i].release_date.year);
            printf("%d/%d/%d", artist->music[i].release_date.day, artist->music[i].release_date.month, artist->music[i].release_date.year);

        }
        else if (option != 'n')
            printf("\n\n\tInvalid option!!!\n");
    } while (option != 'y' && option != 'n');

}

void edit_artist(Artist *artist, Music *music)
{
    char option;

    edit_artist_name(artist);
    edit_artist_age(artist);
    edit_artist_gender(artist);
    edit_artist_country(artist);

    if (verify_artist_musics(artist) == 0)
        printf("\n\tNo music registered for this artist...");
    else
    {
        printf("\n\n\tArtist: %s", artist->name);

        for (size_t i = 0; i < 5; i++)
            if (artist->music[i].id != -1)
            {
                printf("\n\tMusic ID: %d", artist->music[i].id);

                edit_artist_music_name(artist, i);
                edit_artist_music_album(artist, i);
                edit_artist_music_genre(artist, i);
                edit_artist_music_song_length(artist, i);
                edit_artist_music_release_date(artist, i);

                music[artist->music[i].id] = artist->music[i];
            }
    }
}

void edit_artist_by_artist_id(Artist *artist, Music *music, int artist_length)
{
    int id;
    int found = -1;

    printf("\n\tArtist id to be edited: ");
    scanf("%d", &id);

    for (size_t i = 0; i < artist_length; i++)
        if (artist[i].id == id)
            found = 1;

    if (found > -1)
        edit_artist(&artist[id], music);
    else
        printf("\n\tArtist id not found...");
}

void edit_artist_by_music_id(Artist *artist, Music *music, int artist_length, int music_length)
{
    int id;
    int found = -1;

    printf("\n\tArtist music id to be edited: ");
    scanf("%d", &id);

    for (size_t i = 0; i < artist_length; i++)
        for (size_t j = 0; j < music_length; j++)
            if (artist[i].music[j].id == id)
                found = 1;

    if (found > -1)
        edit_artist(&artist[id], music);
    else
        printf("\n\tArtist music id not found...");
}