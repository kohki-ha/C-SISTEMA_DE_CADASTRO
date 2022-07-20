#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/login.h"

void encrypt(char *pass)
{
    for (size_t i = 0; pass[i] != '\0'; i++)
    {
        pass[i] = pass[i] + 3;
    }
}

void decrypt(char *pass)
{
    for (size_t i = 0; pass[i] != '\0'; i++)
    {
        pass[i] = pass[i] - 3;
    }
}

void user_registration(Log *login)
{
    printf("\n\tREGISTER USER\n");
    printf("\n\tUser name: ");
    setbuf(stdin, NULL);
    fgets(login->user, 31, stdin);
    login->user[strcspn(login->user, "\n")] = '\0';

    printf("\n\tPassword: ");
    setbuf(stdin, NULL);
    fgets(login->password, 31, stdin);
    login->password[strcspn(login->password, "\n")] = '\0';

    encrypt(login->password);
}

void user_login(Log *login)
{
    char buffer[31];

    decrypt(login->password);
    printf("\n\tUser: %s", login->user);

    while (1) // password must be correct
    {
        printf("\n\tPassword: ");
        setbuf(stdin, NULL);
        fgets(buffer, 31, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        if (strcmp(buffer, login->password) == 0) // validates password
        {
            printf("\n\tCorrect password!\n\n");
            break;
        }
        else
            printf("\n\tWrong password...\n\n");
    }
}

int login()
{
    FILE *f;
    Log login;
    int aux;

    f = fopen("login.dat", "rb"); // only read mode, file must exist

    if (f == NULL) // create login
    {
        f = fopen("login.dat", "wb"); // only write mode, creates login file

        if (f == NULL)
        {
            printf("Error opening file...\n");
            exit(1);
        }

        aux = 1;
        user_registration(&login);
        fwrite(&login, sizeof(Log), 1, f);
    }
    else // login
    {
        aux = 0;
        fread(&login, sizeof(Log), 1, f);
        user_login(&login);
    }

    fclose(f);

    return aux;
}
