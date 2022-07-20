typedef struct
{
    char user[31], password[31];
} Log;

void encrypt(char *pass);
void decrypt(char *pass);
void user_registration(Log *login);
int login();