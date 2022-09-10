#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char a[9][100] = {" ", " ", " ", " ", " ", " ", " ", " ", " "};

struct node
{
    char *data;
    struct node *next;
};

struct node *StackUndo[100];
int topU = -1;

int gg = 0;

void pushState()
{
    // printf("Inside PushState\n");
    int size = sizeof(StackUndo) / sizeof(StackUndo[0]);
    if (size == 0)
    {
        return;
    }
    topU++;
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    struct node *newNode;
    head->data = strdup(a[0]);
    for (int i = 1; i < 9; ++i)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = strdup(a[i]);
        temp->next = newNode;
        temp = temp->next;
    }
    temp->next = NULL;
    StackUndo[topU] = head;
}

void cpy(char *s, char *d)
{
    while (*(d++) = *(s++))
        ;
    *d = '\0';
}

void restart()
{
    gg = 0;
    topU = -1;
    for (int i = 0; i < 9; i++)
    {
        cpy(" ", a[i]);
    }
    system("cls");
    char res[4][100] = {"Restarting", "Restarting.", "Restarting..", "Restarting..."};
    for (int i = 0; i < 4; i++)
    {
        printf("%s ", res[i]);
        sleep(1);
        system("cls");
    }
}

void undo()
{
    printf("\nUndo\n");
    struct node *temp;
    if (gg == 0)
    {
        topU -= 1;
        temp = StackUndo[topU];
    }
    else
    {
        topU -= 2;
        temp = StackUndo[topU];
        gg -= 1;
    }
    int i = 0;
    while (temp != NULL)
    {
        cpy(temp->data, a[i++]);
        temp = temp->next;
    }

    usleep(1000);
}

void printState(struct node *head)
{
    printf("\nInside PrintState\n");
    struct node *temp = head;
    int i = 0;
    while (temp != NULL)
    {
        printf("%s %d", temp->data, ++i);
        temp = temp->next;
    }
}

void x(int n)
{
    if (strcmp(a[n - 1], " ") == 0)
    {
        strcpy(a[n - 1], "\e[32m"
                         "X"
                         "\e[0m");
    }
    else
    {
        printf("\e[32menter correct index of X\n");
        fflush(stdin);
        scanf("%d\e[0m", &n);
        x(n);
    }
}
void o(int n)
{
    if (strcmp(a[n - 1], " ") == 0)
        strcpy(a[n - 1], "\e[33m"
                         "O"
                         "\e[0m");
    else
    {
        printf("\e[33menter correct index of O\n");
        fflush(stdin);
        scanf("%d\e[0m", &n);
        o(n);
    }
}
void print(int n)
{
    system("cls");
    // printf("gg=%d\n", gg);
    printf("\e[32mPlayer 1 (X)  \e[0m-  \e[33mPlayer 2 (O)\e[0m\n\n\n");
    printf("\t\t\t\t\t\t\t\t \e[36m_________________\e[0m \n");
    printf("\t\t\t\t\t\t\t\t\e[36m|     |     |     |\e[0m\n");
    printf(
        "\t\t\t\t\t\t\t\t\e[36m|  %s\e[36m  |  %s\e[36m  |  %s\e[36m  |\e[0m\n",
        a[0], a[1], a[2]);
    printf("\t\t\t\t\t\t\t\t\e[36m|_____|_____|_____|\e[0m\n");
    printf("\t\t\t\t\t\t\t\t\e[36m|     |     |     |\e[0m\n");
    printf(
        "\t\t\t\t\t\t\t\t\e[36m|  %s\e[36m  |  %s\e[36m  |  %s\e[36m  |\e[0m\n",
        a[3], a[4], a[5]);
    printf("\t\t\t\t\t\t\t\t\e[36m|_____|_____|_____|\e[0m\n");
    printf("\t\t\t\t\t\t\t\t\e[36m|     |     |     |\e[0m\n");
    printf(
        "\t\t\t\t\t\t\t\t\e[36m|  %s\e[36m  |  %s\e[36m  |  %s\e[36m  |\e[0m\n",
        a[6], a[7], a[8]);
    printf("\t\t\t\t\t\t\t\t\e[36m|_____|_____|_____|\e[0m\n");
}
void check(int n)
{
    if (strcmp(a[0], "\e[32m"
                     "X"
                     "\e[0m") == 0 &&
        strcmp(a[1], "\e[32m"
                     "X"
                     "\e[0m") == 0 &&
        strcmp(a[2], "\e[32m"
                     "X"
                     "\e[0m") == 0)
    {
        printf("\n\t\t\t\t\t\t\t\t   \e[32mX WINS\2\2\e[0m");
        gg = 9;
    }
    else if (strcmp(a[3], "\e[32m"
                          "X"
                          "\e[0m") == 0 &&
             strcmp(a[4], "\e[32m"
                          "X"
                          "\e[0m") == 0 &&
             strcmp(a[5], "\e[32m"
                          "X"
                          "\e[0m") == 0)
    {
        printf("\n\t\t\t\t\t\t\t\t   \e[32mX WINS\2\2\e[0m");
        gg = 9;
    }
    else if (strcmp(a[6], "\e[32m"
                          "X"
                          "\e[0m") == 0 &&
             strcmp(a[7], "\e[32m"
                          "X"
                          "\e[0m") == 0 &&
             strcmp(a[8], "\e[32m"
                          "X"
                          "\e[0m") == 0)
    {
        printf("\n\t\t\t\t\t\t\t\t   \e[32mX WINS\2\2\e[0m");
        gg = 9;
    }
    else if (strcmp(a[1], "\e[32m"
                          "X"
                          "\e[0m") == 0 &&
             strcmp(a[4], "\e[32m"
                          "X"
                          "\e[0m") == 0 &&
             strcmp(a[7], "\e[32m"
                          "X"
                          "\e[0m") == 0)
    {
        printf("\n\t\t\t\t\t\t\t\t   \e[32mX WINS\2\2\e[0m");
        gg = 9;
    }
    else if (strcmp(a[0], "\e[32m"
                          "X"
                          "\e[0m") == 0 &&
             strcmp(a[3], "\e[32m"
                          "X"
                          "\e[0m") == 0 &&
             strcmp(a[6], "\e[32m"
                          "X"
                          "\e[0m") == 0)
    {
        printf("\n\t\t\t\t\t\t\t\t   \e[32mX WINS\2\2\e[0m");
        gg = 9;
    }
    else if (strcmp(a[2], "\e[32m"
                          "X"
                          "\e[0m") == 0 &&
             strcmp(a[8], "\e[32m"
                          "X"
                          "\e[0m") == 0 &&
             strcmp(a[5], "\e[32m"
                          "X"
                          "\e[0m") == 0)
    {
        printf("\n\t\t\t\t\t\t\t\t   \e[32mX WINS\2\2\e[0m");
        gg = 9;
    }
    else if (strcmp(a[0], "\e[32m"
                          "X"
                          "\e[0m") == 0 &&
             strcmp(a[4], "\e[32m"
                          "X"
                          "\e[0m") == 0 &&
             strcmp(a[8], "\e[32m"
                          "X"
                          "\e[0m") == 0)
    {
        printf("\n\t\t\t\t\t\t\t\t   \e[32mX WINS\2\2\e[0m");
        gg = 9;
    }
    else if (strcmp(a[2], "\e[32m"
                          "X"
                          "\e[0m") == 0 &&
             strcmp(a[4], "\e[32m"
                          "X"
                          "\e[0m") == 0 &&
             strcmp(a[6], "\e[32m"
                          "X"
                          "\e[0m") == 0)
    {
        printf("\n\t\t\t\t\t\t\t\t   \e[32mX WINS\2\2\e[0m");
        gg = 9;
    }

    else if (strcmp(a[0], "\e[33m"
                          "O"
                          "\e[0m") == 0 &&
             strcmp(a[1], "\e[33m"
                          "O"
                          "\e[0m") == 0 &&
             strcmp(a[2], "\e[33m"
                          "O"
                          "\e[0m") == 0)
    {
        printf("\n\t\t\t\t\t\t\t\t   \e[33mO WINS\2\2\e[0m ");
        gg = 9;
    }
    else if (strcmp(a[3], "\e[33m"
                          "O"
                          "\e[0m") == 0 &&
             strcmp(a[4], "\e[33m"
                          "O"
                          "\e[0m") == 0 &&
             strcmp(a[5], "\e[33m"
                          "O"
                          "\e[0m") == 0)
    {
        printf("\n\t\t\t\t\t\t\t\t   \e[33mO WINS\2\2\e[0m ");
        gg = 9;
    }
    else if (strcmp(a[6], "\e[33m"
                          "O"
                          "\e[0m") == 0 &&
             strcmp(a[7], "\e[33m"
                          "O"
                          "\e[0m") == 0 &&
             strcmp(a[8], "\e[33m"
                          "O"
                          "\e[0m") == 0)
    {
        printf("\n\t\t\t\t\t\t\t\t   \e[33mO WINS\2\2\e[0m ");
        gg = 9;
    }
    else if (strcmp(a[1], "\e[33m"
                          "O"
                          "\e[0m") == 0 &&
             strcmp(a[4], "\e[33m"
                          "O"
                          "\e[0m") == 0 &&
             strcmp(a[7], "\e[33m"
                          "O"
                          "\e[0m") == 0)
    {
        printf("\n\t\t\t\t\t\t\t\t   \e[33mO WINS\2\2\e[0m ");
        gg = 9;
    }
    else if (strcmp(a[0], "\e[33m"
                          "O"
                          "\e[0m") == 0 &&
             strcmp(a[3], "\e[33m"
                          "O"
                          "\e[0m") == 0 &&
             strcmp(a[6], "\e[33m"
                          "O"
                          "\e[0m") == 0)
    {
        printf("\n\t\t\t\t\t\t\t\t   \e[33mO WINS\2\2\e[0m ");
        gg = 9;
    }
    else if (strcmp(a[2], "\e[33m"
                          "O"
                          "\e[0m") == 0 &&
             strcmp(a[8], "\e[33m"
                          "O"
                          "\e[0m") == 0 &&
             strcmp(a[5], "\e[33m"
                          "O"
                          "\e[0m") == 0)
    {
        printf("\n\t\t\t\t\t\t\t\t   \e[33mO WINS\2\2\e[0m ");
        gg = 9;
    }
    else if (strcmp(a[0], "\e[33m"
                          "O"
                          "\e[0m") == 0 &&
             strcmp(a[4], "\e[33m"
                          "O"
                          "\e[0m") == 0 &&
             strcmp(a[8], "\e[33m"
                          "O"
                          "\e[0m") == 0)
    {
        printf("\n\t\t\t\t\t\t\t\t   \e[33mO WINS\2\2\e[0m ");
        gg = 9;
    }
    else if (strcmp(a[2], "\e[33m"
                          "O"
                          "\e[0m") == 0 &&
             strcmp(a[4], "\e[33m"
                          "O"
                          "\e[0m") == 0 &&
             strcmp(a[6], "\e[33m"
                          "O"
                          "\e[0m") == 0)
    {
        printf("\n\t\t\t\t\t\t\t\t   \e[33mO WINS\2\2\e[0m ");
        gg = 9;
    }
    else if (gg == 9)
    {
        printf("\n\t\t\t\t\t\t\t\t\t\033[1;31mTIE\3\3\e[0m");
    }
}
int main()
{
    system("cls");
    printf("\t\t\t\t ___________________________________________________\n");
    printf("\t\t\t\t|\t\t\e[31m    KHELO DIMAG SE\e[0m                  "
           "|\n\t\t\t\t|                                                   |\n");
    printf(
        "\t\t\t\t|\e[31mRULES:\e[0m                                             "
        "|\n\t\t\t\t|                                                   |\n");
    printf("\t\t\t\t|\e[31m#1-First person to start will have 'X'\e[0m           "
           "  |\n");
    printf("\t\t\t\t|\e[31m#2-Opponent will have 'O'\e[0m                        "
           "  |\n\t\t\t\t|                                                   "
           "|\n\t\t\t\t|\e[31mEnter Any Key To Continue\e[33m\2\2\e[0m           "
           "             |\n");
    printf("\t\t\t\t|___________________________________________________|\n");
    getch();
    int n = 0;
    pushState();
    while (gg < 9)
    {
        if (gg < 9)
        {
            print(n);
        Ou:
            printf("\e[32mEnter index of x\n");
            scanf("%d\e[0m", &n);
            x(n);
            print(n);
            pushState();
            char st;
            do
            {
                printf("Enter U for Undo or R to Restart P to Pass your turn\n");
                fflush(stdin);
                scanf("%c", &st);
                if (st == 'P' || st == 'p')
                {
                    gg++;
                    check(n);
                }
                else if (st == 'U' || st == 'u')
                {
                    undo();
                    print(n);
                    if (gg != 0)
                        goto Xu;
                    else
                        goto Ou;
                }
                else if (st == 'R' || st == 'r')
                {
                    restart();
                    continue;
                }
                else
                {
                    st = '0';
                }
            } while (st == '0');
        }

        if (gg < 9)
        {
            print(n);
        Xu:
            printf("\e[33mEnter index of o\n");
            fflush(stdin);
            scanf("%d\e[0m", &n);
            o(n);
            print(n);
            pushState();
            char st;
            do
            {
                printf("Enter U for Undo or R for Restart or P to Pass your turn\n");
                fflush(stdin);
                scanf("%c", &st);
                if (st == 'P' || st == 'p')
                {
                    gg++;
                    check(n);
                }
                else if (st == 'R' || st == 'r')
                {
                    restart();
                    continue;
                }
                else if (st == 'U' || st == 'u')
                {
                    undo();
                    print(n);
                    goto Ou;
                }
                else
                {
                    st = '0';
                }
            } while (st == '0');
        }
    }
    return 0;
}
