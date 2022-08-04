/* I have used Caeser Cipher algorthim to encrypt and decrypt the string, This was my First semester project 
    With this project i got myself into good knowledge about string and ASCII Characters */

#include <stdio.h>

void encrypt(char *string, int key)
{
    char *ptr = string;

    while (*ptr != '\0')
    {
        if (*ptr >= 'a' && *ptr <= 'z')
        {

            int value = *ptr - 'a';     /* to make the range of value lie in between 0 to 25, i have
                                           subtracted ascii value  of pointing char from 'a' */
            value = (value + key) % 26; /* for the values don't exceeds more than ascii character of z ,i have used
                                           modulo 26  */
            *ptr = 'a' + value;         /* So final the pointing character will change from orginal character to
                                           the value added character */
                                        /* For example: string is abz and caeser key is 13 so pointer pointing to first
                                           character is decreased by 'a' so value=0 and then value becomes (0+13)%26
                                           which is 13 so 'a' + 13 =110 which is 'n' */
        }

        else if (*ptr >= 'A' && *ptr <= 'Z')
        {

            int value = *ptr - 'A';
            value = (value + key) % 26;
            *ptr = 'A' + value;
        }

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

            int value = *ptr - 'a';
            value = (value - key) % 26;
            if (value < 0)
            {
                value = value + 26; /* if the value is negative, then 26 is added in order to maintain the range of value
                                       that lies between 0 to 25.*/
            }
            *ptr = 'a' + value;
        }

        else if (*ptr >= 'A' && *ptr <= 'Z')
        {

            int value = *ptr - 'A';
            value = (value - key) % 26;
            if (value < 0)
            {
                value = value + 26; /* if the value is negative, then 26 is added in order to maintain the range of value
                                       that lies between 0 to 25.*/
            }
            *ptr = 'A' + value;
        }

        *ptr++;
    }
}

int main()
{

    char *string;
    int x, key;
    printf("Enter Caeser key \n");
    scanf("%d", &key);

    do
    {

        printf("\nPlease choose following options:\n");
        printf("1 = Encrypt the string.\n");
        printf("2 = Decrypt the string.\n");
        printf("3 = Exit Program.\n");
        scanf("%d", &x);
        if (x == 3)
            break;

        fflush(stdin); // The function fflush(stdin) is used to flush the output buffer of the stream.

        printf("Please enter key word \n");
        gets(string);

        switch (x)
        {
        case 1:

            encrypt(string, key);
            printf("Encrypted string is %s\n", string);

            break;
        case 2:

            decrypt(string, key);
            printf("Decrypted string is %s\n", string);

            break;

        default:

            printf("Please enter valid option\n");

            break;
        }
    } while (1);

    return 0;
}
