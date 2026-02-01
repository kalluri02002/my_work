int main(){
    FILE *afile;
    char ch;
    afile=fopen("text.txt","w");
    if(afile==NULL){
        printf("file doesnt exits\n");
    }
    else{
        ferror()
        clearerr()
        ch=fgetc(afile);
        while(ch !=EOF){
            putchar(ch);
            ch=fgetc(afile);
        }
        printf("\nfile open success fully\n");

    }
    fclose(afile);
}