void new_post( char* str, int login_check){

    if(login_check==0){
            printf(" **** You should login at first! **** \n");
            return;
        }
    post* last_post=loggedin_user->head_of_posts;
    while(last_post->next_post != NULL){
        last_post=last_post->next_post;
    }

    post* new_post=(post*)malloc(sizeof(post));
    /*inserting the username*/
    new_post->user=(char*)malloc((strlen(loggedin_user->username)+1)*sizeof(char));
    strcpy((new_post->user), (loggedin_user->username));
    (new_post->user)[strlen(loggedin_user->username)]='\0';
    /*extracting the post*/
    int post_size=strlen(str)-5;
    char* post=calloc(post_size, post_size*sizeof(char));
    for(int i=0; i<post_size; i++){
        post[i]=str[5+i];
    }
    if(post==NULL){
        printf(" **** Invalid input! ****\n");
        return;
    }
    new_post->the_post=(char*)malloc((post_size+1)*sizeof(char));
    strcpy((new_post->the_post), post);
    (new_post->the_post)[post_size]='\0';
    (loggedin_user->numofposts)++;
    new_post->post_id=loggedin_user->numofposts;
    int a=loggedin_user->numofposts;
    int b=0;
    char* num=(char*)malloc(sizeof(char));
    int j=0;
   while(a!=0){
    b=a%10;
    num=(char *)realloc(num,sizeof(char)*(j+1));
    num[j]=b+48;
    a/=10;
    j++;
   }
    num[j]='\0';
    new_post->post_id_char=(char*)calloc(strlen(num),strlen(num)*sizeof(char));
    for(int i=0;i<strlen(num);i++){
        new_post->post_id_char[i]=num[strlen(num)-1-i];
    }
    new_post->likes=0;

    new_post->likers=(int*)calloc(1,sizeof(int));
    loggedin_user->realnum++;

    /*linking*/
    last_post->next_post=new_post;
    new_post->next_post=NULL;
    last_post=new_post;
    printf(" **** Post saved! **** \n");



}