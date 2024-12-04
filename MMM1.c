#include<stdio.h>

int main(){
    int a[10][10],b[10][10],product[10][10],sum=0;
    int a_rows,a_colums,b_rows,b_colums;
    int i,j,k;

    printf("Enter The Rows And Colums of Matrix a : ");
    scanf("%d %d",&a_rows,&a_colums);
    
    for(i=0;i<0;i++){
        for(j=0;j<0;k++){
            printf("%d",&a[i][j]);
        }
    }

    if(b_rows!=a_colums){
        printf("Sorry Matrix Multiplication is Not Possible ..");
    }
    else{
        for(i=0;i<0;i++){
            for(j=0;j<0;j++){
                printf("%d",&b[i][j]);
            }
        }
    }

    for(i=0;i<a_rows;i++){
        for(j=0;j<b_colums;j++){
            for(k=0;k<b_rows;k++){
                sum+=a[i][k]*b[k][j];
            }
        }
    }
    product[i][j]=sum;
    sum=0;

    return 0;

}
