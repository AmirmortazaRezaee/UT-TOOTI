void find_user_pass(char* str, char*username, char*password, int commands_len, int username_size , int password_size)
{

    for(int i=0;i<username_size;i++){
        *(username+i)=*(str+i+1+commands_len);
    }
    for(int j=0;j<password_size;j++){
        *(password+j)=*(str+commands_len+username_size+2+j);
    }

}