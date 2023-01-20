void signup(user* head,char* str, int* users_number, int login_check){
        if(login_check!=0){
            printf(" **** You should logut first! **** \n");
            return;
        }
            /*finding the entered username and password*/
        int username_size=0;
        for(int k=7;(str[k]!=' ')&&(str[k]!='\n');k++){
            username_size++;
        }
        int password_size=strlen(str)-(username_size+8);
        char* username=calloc(username_size, username_size*sizeof(char));
        char* password=calloc(password_size, password_size*sizeof(char));
        find_user_pass(str , username , password , 6 , username_size , password_size);
        if((username==NULL)||(password==NULL)){
            printf(" **** Invalid input! **** \n");
            return;
        }
        if((!strcmp(username,"signup"))|| (!strcmp(username,"login")) || (!strcmp(username,"post"))|| (!strcmp(username,"like")) || (!strcmp(username,"logout"))||(!strcmp(username,"delete"))|| (!strcmp(username,"info")) || (!strcmp(username,"find_user")) ){
            printf(" **** The user couldn't be any of commands! **** \n");
            return;
        }
        /*searching among the usernames*/
        if(search_username_int(head , username)){
            printf(" **** Repeated username! try again! **** \n");
            
        }else{
            *users_number++;
            new_user(head, username , password , username_size, password_size);
            printf(" **** New user added! **** \n");
            
        }
        free(username);
        free(password);
      

}