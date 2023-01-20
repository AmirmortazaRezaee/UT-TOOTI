void delete(char* str, int login_check){
    if(login_check==0){
        printf(" **** You should login first! **** \n");
        return;
    }
    /*finding the post id*/
    int id_size=strlen(str)-7;
    char* id_char=(char*)calloc(id_size,id_size*sizeof(char));
    for(int i=0; i<id_size; i++){
        id_char[i]=str[7+i];
    }

    int id_num=0;
    for(int j=0;j<id_size;j++){
        id_num*=10;
        id_num+= id_char[j]-48;
    }
   /*finding the post*/
    if(loggedin_user->head_of_posts->next_post ==NULL){
        printf(" **** The post couldn't be found! **** \n") ;
        return;
    }else{
        post* current=(post*)malloc(sizeof(post));
        current=(loggedin_user->head_of_posts->next_post);
        while(current->post_id != id_num){
            if(current->next_post == NULL){
                printf(" **** The post couldn't be found! **** \n") ;
                return;
            }else{
                current=current->next_post;
            }
        }
        /*now we have current post*/

        post* previous=(post*)malloc(sizeof(post));
        previous=(loggedin_user->head_of_posts);
        while(previous->next_post!=current){
            previous=previous->next_post;
        }
        /*now we have both current an previous post*/
        previous->next_post = current->next_post;
        free(current);
        loggedin_user->realnum--;
        printf(" **** Done! **** \n");
        return;
        
    }
    

}