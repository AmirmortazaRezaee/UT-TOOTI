void file(user* head){
    user* current=head->next;
    if(current==NULL){
        return;
    }
    FILE* accounts_output=fopen("accounts.txt" , "w");
    FILE* posts_output=fopen("posts.txt" , "w");
    while(current!=NULL){
        fprintf (accounts_output, "%s %s %d\n", current->username, current->password , current->realnum);
        if(current->realnum!=0){
            post* curr_post=current->head_of_posts->next_post;
            while(curr_post!=NULL){
                fprintf (posts_output, "%s %s %d\n", curr_post->the_post, current->username , curr_post->likes);
                curr_post=curr_post->next_post;

            }
        }
        current=current->next;
    }

}