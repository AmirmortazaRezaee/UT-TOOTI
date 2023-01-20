int search_username_int(user* head , char* username)
{
    if(head->next ==NULL){
        return 0 ; /*no same username found*/
    }else{
        user* current=(head->next);
        while(strcmp(current->username , username)){
            if(current->next == NULL){
                return 0;  /*no same username found*/
            }else{
                current=current->next;
            }
        }
    return 1; /*a same username found*/
    }



    return 0;
}