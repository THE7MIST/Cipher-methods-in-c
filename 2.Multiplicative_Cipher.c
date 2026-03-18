#include <stdio.h>
#include <ctype.h>

int keycheck(int key)
{
    if (key == 0 | key == 1)
    {
        return 1;
    }

    int runfor = key < 26 ? key : 26;

    for (int i = 2; i <= runfor; i++)
    {
        if (key % i == 0 && 26 % i == 0)
        {
            return 1;
        }
    }
    return 0;
}

int encrypt(char *text, int key)
{
    if (keycheck(key))
    {
        return 0;
    }
    while (*text)
    {
        if (isalpha(*text))
        {
            char base = islower(*text) ? 'a' : 'A';
            *text = ((*text - base) * key) % 26 + base;
        }
        text++;
    }
    return 1;
}

void decrypt(char *text, int key)
{

    int inverseKey;
    for (inverseKey = 1; inverseKey < 26; inverseKey++)
    {
        if ((key * inverseKey) % 26 == 1)
        {
            break;
        }
    }

    while (*text)
    {
        if (isalpha(*text))
        {
            char base = islower(*text) ? 'a' : 'A';
            *text = ((*text - base + 26) * inverseKey) % 26 + base;
        }
        text++;
    }
}

int main()
{
    char text[100];
    int key;
    char output[200];

    printf("Enter text to encrypt/decrypt: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter key (an integer): ");
    scanf("%d", &key);

    printf("Choose operation: e->encryption or d->decryption: ");
    char choice;
    scanf(" %c", &choice);

    switch (choice)
    {
    case 'e':
        if (encrypt(text, key))
            snprintf(output, 200, "Encrypted text: %s\n", text);
        else
            snprintf(output, 200, "Invalid Key");
        printf("%s\n", output); 
        break;
    case 'd':
        decrypt(text, key);
        printf("Decrypted text: %s\n", text);
        break;
    default:
        printf("Invalid choice.\n");
        return 1;
    }

    return 0;
}







PS1='\[\e[38;5;46m\][\u@\h \w \[\e[38;5;240m\]cpu:$(uptime | awk -F"load average:" "{print \$2}" | cut -d, -f1) mem:$(free -m | awk "/Mem:/ {printf \"%d%%\", \$3/\$2 * 100}") bg:$(jobs -p | wc -l) cmd:$(history 1 | awk "{print \$1}") \[\e[38;5;46m\]] ▶\[\e[0m\] '