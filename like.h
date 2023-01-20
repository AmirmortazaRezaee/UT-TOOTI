void like(char* str , int login_check, user* head){
    if(login_check==0){
        printf(" **** You should login first! **** \n");
        return;
    }
    /*extracting the user name*/
    int username_size=0;
    for(int k=5;str[k]!=' ';k++){
        username_size++;
    }
    int postId_size=strlen(str)-(username_size+6);
    char* username=calloc(username_size, username_size*sizeof(char));
    char* postId=calloc(postId_size, postId_size*sizeof(char));
    find_user_pass(str , username , postId , 4 , username_size , postId_size);
    
    /*restricted situations*/
    if(!strcmp(username, loggedin_user->username)){
        printf(" **** You can't like your posts! **** \n");
        free(username);
        free(postId);
        return;
    }
    if(!search_username_int(head, username)){
        printf(" **** Username not found! **** \n");
        free(username);
        free(postId);
        return;
    }

    user* wanted=search_username_pointer(head, username);/*the user which we want to like his/her post*/
    /*finding the post*/
    if(wanted->head_of_posts->next_post ==NULL){
        printf(" **** The post couldn't be found! **** \n") ;
        free(username);
        free(postId);
        return;
    }else{
        post* current;
        current=(wanted->head_of_posts->next_post);
        while(strcmp(current->post_id_char , postId)){
            if(current->next_post == NULL){
                printf(" **** The post couldn't be found! **** \n") ;
                free(username);
                free(postId);
                return;
            }else{
                current=current->next_post;
            }
        }
        /*check if the user didnt like the same post more than once*/
        for(int i=0;i<sizeof(current->likers);i++){
            if(current->likers[i]==loggedin_user->user_id){
                printf(" **** You cant like a post twice! **** \n");
                free(username);
                free(postId);
                return;
            }
        }
        /*the proccess of liking*/
        current->likes +=1;
        current->likers[(sizeof(current->likers)/sizeof(int))-1]=loggedin_user->user_id;
        printf(" **** Done! **** \n");
        free(username);
        free(postId);
        return;
    }
    printf("There is a problem, please try again later!\n");
    free(username);
    free(postId);
    // free(wanted);
    
}