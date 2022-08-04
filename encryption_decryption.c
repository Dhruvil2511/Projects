// Program to Encrypt or  Decrypt Password
#include <stdio.h>
#include <string.h>

void encrypt(char *string, int key)
{
    char *ptr = string;

    while (*ptr != '\0')
    {
        if (*ptr >= 'a' && *ptr <= 'z') // abz
        {
   
            *ptr=*ptr+key;

            if (*ptr > 'z')
            {
                
                *ptr = *ptr - 'z' + 'a' - 1;
            }
                  
            
        }

        // else if (*ptr >= 'A' && *ptr <= 'Z')
        // {
        //     if (*ptr > 'Z')
        //     {
        //         *ptr = *ptr - 'Z' + 'A' - 1;
        //     }
        //     else
        //     {
        //         *ptr = *ptr + key;
        //     }
        // }

        *ptr++;
    }
}
void decrypt(char *string, int key)
{
    char *ptr = string;

    while (*ptr != '\0')
    {
        if (*ptr >= 'a' && *ptr <= 'z')
        {
            *ptr = *ptr + key;
        }
        if (*ptr > 'z')
        {
            *ptr = *ptr + 'z' - 'a' + 1;
        }
        else if (*ptr >= 'A' && *ptr <= 'Z')
        {
            *ptr = *ptr + key;
        }
        if (*ptr > 'Z')
        {
            *ptr = *ptr + 'Z' - 'A' + 1;
        }

        *ptr++;
    }
}

int main()
{
    char *string;
    int x, key;
    printf("Please enter the key\n");
    scanf("%d", &key);
    fflush(stdin);
    printf("Enter word to encrypt\n");
    gets(string);
    printf("\nPlease choose following options:\n");
    printf("1 = Encrypt the string.\n");
    printf("2 = Decrypt the string.\n");
    scanf("%d", &x);
    switch (x)
    {
    case 1:
        encrypt(string, key);
        //printf("Encrypted password is %s\n", string);
        break;

    case 2:
        decrypt(string, key);
        printf("Decrypted password is %s\n", string);
        break;

    default:
        printf("Please enter valid number\n");
        break;
    }

    return 0;
}