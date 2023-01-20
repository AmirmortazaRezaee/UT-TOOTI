void login(user* head,char* str, int* login_check){
    /*finding the entered username and password*/
    if(*login_check!=0){
        printf(" ** You are already logged in! you must logout first!! ** \n");
        return;
    }

    int username_size=0;
    for(int k=6;str[k]!=' ';k++){
        username_size++;
    }
    int password_size=strlen(str)-(username_size+7);
    char* username=calloc(username_size, username_size*sizeof(char));
    char* password=calloc(password_size, password_size*sizeof(char));
    find_user_pass(str , username , password , 5 , username_size , password_size);
    if(search_username_int(head, username)){
        user* current=search_username_pointer(head, username);
        if(!strcmp(current->password, password)){
            loggedin_user=current;
            printf(" **** You logged in successfully! **** \n");
            *login_check=1;
        }else{
            printf(" ** The password is incorrect! try again! ** \n");
        }

    }else{
        printf(" ** Username is incorrect! please try again! ** \n");
    }
    free(username);
    free(password);
}