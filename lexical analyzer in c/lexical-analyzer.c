#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
#define and &&
#define or ||
bool isDelimiter(char chr)
{
    return (chr == ' ' || chr == '+' || chr == '-' || chr == '*' || chr == '/' || chr == ',' || chr == ';' || chr == '%' || chr == '>' || chr == '<' || chr == '=' || chr == '(' || chr == ')' || chr == '[' || chr == ']' || chr == '{' || chr == '}');
}
bool isOperator(char chr)
{
    // return (chr == '+' || chr == '-' || chr == '*' || chr == '/' || chr == '>' || chr == '<' || chr == '=');
    return (chr == '+' || chr == '-' || chr == '*' || chr == '/' || chr == '=');
}
bool isKeyword(char *str)
{
    const char *keywords[] = {"auto", "break", "case", "char",
                              "const", "continue", "default", "do",
                              "double", "else", "enum", "extern",
                              "float", "for", "goto", "if",
                              "int", "long", "register", "return",
                              "short", "signed", "sizeof", "static",
                              "struct", "switch", "typedef", "union",
                              "unsigned", "void", "volatile", "while"};

    for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++)
    {
        if (strcmp(str, keywords[i]) == 0)
        {
            return true;
        }
    }
    return false;
}
bool isValidIdentifier(char *str)
{
    return (!isdigit(str[0]) and !isDelimiter(str[0]));
}

bool isInteger(char *str)
{
    if (str == NULL || *str == '\0')
    {
        return false;
    }
    int i = 0;
    while (isdigit(str[i]))
    {
        i++;
    }
    return str[i] == '\0';
}

int main()
{
    FILE *input;
    char ch;
    int l = 1, t = 0;
    input = fopen("input.txt", "r");
    ch = fgetc(input);
    char str[MAX];
    while (ch != EOF)
    {
        int i=0;
        if (isDelimiter(ch))
        {
            if(ch!=' ') printf("%7d\t %7d\t Special symbol\t %7c\n", l, t, ch);
            t++;
        }
        else if (isOperator(ch))
        {
            printf("%7d\t %7d\t Operator\t %7c\n", l, t, ch);
            t++;
        }
        else if (isalpha(ch))
        {
            str[i] = ch;
            i++;
            ch = fgetc(input);

            while (isalnum(ch))
            {
                str[i] = ch;
                i++;
                ch = fgetc(input);
            }

            str[i] = '\0';

            if (isKeyword(str))
            {
                printf("%7d\t %7d\t Keyword\t %7s\n", l, t, str);
                t++;
            }
            else
            {
                printf("%7d\t %7d\t Identifier\t %7s\n", l, t, str);
                t++;
            }
            if (isOperator(ch))
            {
                printf("%7d\t %7d\t Operator\t %7c\n", l, t, ch);
                t++;
            }
        }
        else if (ch == '\n')
        {
            l++;
        }
        
        ch = fgetc(input);
    }
    printf("\n");
}