#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct DATA
{
    int ID;
    int gender;
    int height;
}*data;

struct Val1
{
    int gender;
    int height;
};


int main(void)
{
    double val1,val2;
    int N=0,*i,ID,IDs,*j,k=0,h=0;
    char fname1[FILENAME_MAX],fname2[FILENAME_MAX];
    char buf1[256],buf2[256];
    FILE* fp1,* fp2;

    printf("Input the filename of sample height:");
    fgets(fname1,sizeof(fname1),stdin);
    fname1[strlen(fname1)-1] = '\0';

    fp1 = fopen(fname1,"r");
    if(fp1==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("Input the filename of sample ID:");
    fgets(fname2,sizeof(fname2),stdin);
    fname2[strlen(fname2)-1] = '\0';

    fp2 = fopen(fname2,"r");
    if(fp2==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("Which ID's data do you want?:");
    scanf("%d",&ID);

    while(fgets(buf1,sizeof(buf1),fp1) != NULL && fgets(buf2,sizeof(buf2),fp2) != NULL){
        struct Val1 val1;
        sscanf(buf1,"%lf,%lf",&val1.gender,&val1.height);
        sscanf(buf2,"%lf",&val2);
        struct DATA data[] = {
            {val2,val1.gender,val1.height}
        };
        IDs[i]=val2;
        i++;
    }

    if(fclose(fp1) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    if(fclose(fp2) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("---\n");
    for(j=0;j<i;j++){
        k++;
        if(ID=IDs[j]){
            printf("ID:%d\ngender:%d\nheight:%d\n",data[k].ID,data[k].gender,data[k].height);
            h=h+1;
        }  
    }
    if(h!=1){
        printf("No Data\n");
    }

    return(0);
}
    
