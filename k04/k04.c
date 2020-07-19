#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct human_data
{
    int ID;
    int gender;
    double height;
};


int main(void)
{   
    int ID,i,j=0;
    char fname[FILENAME_MAX];
    char buf[256],buf2[256];
    FILE* fp;
    FILE* fp2;
    struct human_data human [14];

    printf("input the filename of sample height:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    fp2 = fopen(fname,"r");
    if(fp2==NULL)
    {
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("input the filename of sample ID:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    fp = fopen(fname,"r");
    if(fp==NULL)
    {
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    i=0;
    while(fgets(buf,sizeof(buf),fp) != NULL ){
        sscanf(buf,"%d",&human [i].ID);
        i++;
    }
    i=0;
    fgets(buf2,sizeof(buf2),fp2);
    while(fgets(buf2,sizeof(buf2),fp2)!= NULL){
        sscanf(buf2,"%d,%lf",&human[i].gender,&human[i].height);
        i++;
    }
    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }
     if(fclose(fp2) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("Which ID's data do you want? : ");
    scanf("%d",&ID);
    printf("---\n");

    for(i=0;i<14;i++){
        if(ID==human [i].ID){
            printf("ID : %d\n" ,human[i].ID);
            if(human[i].gender==1){
                printf("gender : Male\n");
            }
            else{
                printf("gender : Female\n");
            }
            printf("height : %.1lf\n" ,human[i].height);
            j++; 
        }
    }

    if(j==0){
        printf("No data");
    }

return 0;
}

    
