void find_user(char* str , user* head){
    int username_size=strlen(str)-10;
    char* username=(char*)calloc(username_size,username_size*sizeof(char));
    for(int i=0; i<username_size; i++){
        username[i]=str[10+i];
    }
    if(username==NULL){
        printf(" **** Invalid input! ****\n");
        return;
    }
    if(!search_username_int(head , username)){
        printf(" **** No user found! **** \n");
        free(username);
        return;
    }
    user* the_user=search_username_pointer(head , username);
    printf("\nusername : %s\n", the_user->username);
    post* the_post=the_user->head_of_posts->next_post;
    int counter=1;
    while(the_post!=NULL){
        printf("post %d :\n%s\npost id : %d    |    likes : %d\n\n", counter , the_post->the_post, the_post->post_id , the_post->likes);
        the_post=the_post->next_post;
        counter++;
    }
    free(username);


}