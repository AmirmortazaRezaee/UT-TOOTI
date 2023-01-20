void info(int login_check){
    if(login_check==0){
        printf(" **** You should login first! **** \n");
        return;
    }
    printf("\nusername : %s\npassword : %s\n", loggedin_user->username , loggedin_user->password);
    post* the_post=loggedin_user->head_of_posts->next_post;
    int counter=1;
    while(the_post!=NULL){
        printf("\npost %d :\n%s\npost id : %d    |    likes : %d\n\n", counter , the_post->the_post, the_post->post_id , the_post->likes);
        the_post=the_post->next_post;
        counter++;
    }
    //free(the_post);
    
}