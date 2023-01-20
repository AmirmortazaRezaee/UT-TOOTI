void new_user(user* head , char* username , char* password , int username_size, int password_size){
    user* last_user=head;
    while(last_user->next!=NULL){
        last_user=last_user->next;
    }
    user* new_user=(user*)malloc(sizeof(user));
    new_user->username=(char*)malloc((username_size+1)*sizeof(char));
    new_user->password=(char*)malloc((password_size+1)*sizeof(char));
    strcpy(new_user->username, username);
    strcpy(new_user->password, password);
    (new_user->username)[username_size]='\0';
    (new_user->password)[password_size]='\0';
    new_user->user_id=(last_user->user_id)+1;
    new_user->head_of_posts=(post*)malloc(sizeof(post));
    new_user->head_of_posts->user=(char*)malloc((username_size+1)*sizeof(char));
    strcpy(new_user->head_of_posts->user, username);
    (new_user->head_of_posts->user)[username_size]='\0';
    new_user->head_of_posts->post_id=0;
    new_user->head_of_posts->next_post=NULL;
    new_user->numofposts=0;
    new_user->realnum=0;
    last_user->next=new_user;
    new_user->next=NULL;
    last_user=new_user;
    
}