#ifdef _WIN32
#define CLEAN "cls"
#else
#define CLEAN "clear"
#endif

#ifndef __MUSIC_TYPE__
#define __MUSIC_TYPE__
typedef struct
{
    int day;
    int month;
    int year;
} Date;

typedef struct
{
    int minutes;
    int seconds;
} Song_length;

typedef struct
{
    int id;
    char name[30];
    char album[30];
    char genre[30];
    Song_length song_length;
    Date release_date;
} Music;
#endif //__MUSIC_TYPE__

#ifndef __ARTIST_TYPE__
#define __ARTIST_TYPE__
typedef struct
{
    int id;
    char name[30];
    int age;
    char gender[30];
    char country[30];
    Music *music;
} Artist;
#endif //__ARTIST_TYPE__

#ifndef __ARTIST_H__
#define __ARTIST_H__

void register_artist(Artist *artist);
char edit_artist_options(Artist *artist);
int verify_registered_artist(Artist *artist, int artist_length);
int verify_registered_music(Music *music, int music_length);
void edit_artist_name(Artist *artist);
void edit_artist_age(Artist *artist);
void edit_artist_gender(Artist *artist);
void edit_artist_country(Artist *artist);
void edit_artist_music_name(Artist *artist, int i);
void edit_artist_music_album(Artist *artist, int i);
void edit_artist_music_genre(Artist *artist, int i);
void edit_artist_music_song_length(Artist *artist, int i);
void edit_artist_music_release_date(Artist *artist, int i);
void edit_artist(Artist *artist, Music *music);
void edit_artist_by_artist_id(Artist *artist, Music *music, int artist_length);
void edit_artist_by_music_id(Artist *artist, Music *music, int artist_length, int music_length);

#endif //__ARTIST_H__

#ifndef __MUSIC_H__
#define __MUSIC_H__

void register_music(Music *music);

#endif //__MUSIC_H__

#ifndef __MENU_H__
#define __MENU_H__

Artist *realloc_artist(Artist *artist, int *artist_length);
Music *realloc_music(Music *music, int *music_length);
void initialize_artist(Artist *artist);
void initialize_artist_music(Artist *artist);
void initialize_music(Music *music);
void invalid_option();
int check_registered(Artist *artist, int artist_length);
int select_artist(Artist *artist, int artist_length);
char menu_options();
void register_artist_option(Artist *artist, int artist_length, int *counter_artist);
void register_music_option(Artist *artist, int artist_length, Music *music, int *music_length, int *counter_music);
char menu_register();
char menu_edit();
char menu_list();
char menu_remove();
char menu_search();
void menu_main(Artist *artist, Music *music);

#endif //__MENU_H__