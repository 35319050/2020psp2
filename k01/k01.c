#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val,double ave,int N);
extern double var_online(double square_ave,double ave);
extern double square_ave_online(double val,double square_ave,int N);
int N =0;
int main(void)
{
    double val,ave=0,square_ave=0,var=0;
    char fname[FILENAME_MAX];
    char buf[256];
    int N=0;
    FILE* fp;

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);
        N++;
        ave = ave_online(val,ave,N);
        square_ave = square_ave_online(val,square_ave,N);
        var = var_online(square_ave,ave);


    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("標本平均:%lf\n",ave);
    printf("標本分散:%lf\n",var);
    printf("平均推定値:%lf\n",ave);
    printf("分散推定値:%lf\n",N*var/(N-1));

    return 0;


}

double ave_online(double val,double ave,int N){
    
    ave = (ave*(N-1)+val)/N;
    return ave;
}

double square_ave_online(double val,double square_ave,int N){

    square_ave = (square_ave*(N-1)+(val*val))/N;
    return square_ave;
}

double var_online(double square_ave,double ave){
    
    double var;
    var = square_ave - (ave*ave);
    return var;
}
