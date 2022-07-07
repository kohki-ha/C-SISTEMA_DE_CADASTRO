typedef struct
{
    int day;
    int month;
    int year;
} Date;

typedef struct
{
    int id;
    char name[30];
    char genre[30];
    char album[30];
    float song_length;
    Date release_date;
} Music;