void logout( int* login_check ){
    if(*login_check==0){
        printf(" **** You are not logged in yet! **** \n");
        return;
    }
    *login_check=0;
    loggedin_user=NULL;
    printf(" **** You are logged out successfully! **** \n");
}