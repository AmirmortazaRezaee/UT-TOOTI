user* search_username_pointer(user* head , char* username)
{
    if(head->next ==NULL){
        return NULL ; /*no same username found*/
    }else{
        user* current=(user*)malloc(sizeof(user));
        current=(head->next);
        while(strcmp(current->username , username)){
            if(current->next == NULL){
                return NULL;  /*no same username found*/
            }else{
                current=current->next;
            }
        }
    return current; /*a same username found*/
    }
    return NULL;
}