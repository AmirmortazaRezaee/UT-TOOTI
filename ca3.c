#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct post_n{
    char* user;
    int post_id;
    char* post_id_char;
    int likes;
    char* the_post;
    int* likers;
    struct post_n* next_post;
}post;

typedef struct user_n{
    int user_id;
    char* username;
    char* password;
    int numofposts;
    int realnum;
    post* head_of_posts;
    struct user_n* next;
}user;
user* loggedin_user;


#include "functions.h"

int main()
{

    user* head=(user*)malloc(sizeof(user));
    head->next=NULL;
    head->user_id=0;
    user* last_user=head;
    int users_number=0;
    int login_check=0;
    printf("\n\n\t\t\t## UT TOOTI ##\n\n\ttell me what to do : \n\n");
    while(1)
    {   
        char* str=(char*)malloc(sizeof(char));
        char* command=(char*)calloc(10,10*sizeof(char));

        /****************************/
        /*get the string*/
        int p=-1;
        while(str[p]!='\n'){
        p++;
        str=(char *)realloc(str,sizeof(char)*(p+1));
        str[p]=getchar();
        }
        str[p]='\0';
        /*finding the command*/
        int i=0;
        do{
            command[i]=str[i];
            i++;
        }while(str[i]!=' '&&str[i]!='\n'&&str[i]!='\0');
        /************************/

        if(!strcmp(command, "signup"))
        {
            signup(head, str , &users_number, login_check);
        }
        else if(!strcmp(command, "login"))
        {
            login(head , str,&login_check);
        }
        else if(!strcmp(command, "logout"))
        {
            logout( &login_check);
        }
        else if(!strcmp(command, "post"))
        {
            new_post(str  ,login_check);
        }
        else if(!strcmp(command, "like"))
        {
            like(str, login_check,head);
        }
        else if(!strcmp(command, "delete"))
        {
            delete(str, login_check);
        }
        else if(!strcmp(command, "info"))
        {
            info(login_check);
        }
        else if(!strcmp(command, "find_user"))
        {
            find_user(str , head);
        }
        else if(!strcmp(command, "exit"))
        {
            file(head);
            printf(" **** See you soon! **** \n");
            getchar();
            break;
        }else{
            printf(" **** Invalid input **** \n");
        }
        free(str);
        free(command);
    }
    return 0;
}