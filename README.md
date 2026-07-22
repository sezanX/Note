
<!-- https://drive.google.com/drive/folders/13A3_XRpf0PNNRk0-tUewrhS0Yy4Mf0pg
-->
 https://sezanx.github.io/Note/

https://sezanx.github.io/Note/nu2/


# https://sezanx.github.io/assembly/




<!-- https://drive.google.com/drive/folders/1XElsU8R8JXMZ0M1Sy30VZdTvrliPLOrl?usp=#include<stdio.h>

int main (){
    int r1=5, r2=5, r3=5;
    // printf("Enter three resource instanes: ");
    // scanf("%d %d %d", &r1, &r2, &r3);
    // printf("%d\t%d\t%d\n", r1, r2, r3);

    int p1=3, p2=3, p3=3;
    // printf("Enter three process instances: ");
    // scanf("%d %d %d", &p1, &p2, &p3);
    // printf("%d\t%d\t%d\n", p1, p2, p3);

    int allocated[3][3] = {{1,1,1}, {1,1,1}, {1,1,1}};

    int required[3][3] = {{1,1,1}, {1,1,1}, {1,1,1}};
    int avail1=r1-allocated[0][0], avail2=r2-allocated[0][1], avail3=r3-allocated[0][2];
    // printf("Available instances: %d\t%d\t%d\n", avail1, avail2, avail3);

    for (int i=1; i<=3; i++){
        if (avail1>= required[i-1][0] && avail2>=required[i-1][1] && avail3>=required[i-1][2]){
            avail1+=allocated[i-1][0];
            avail2+=allocated[i-1][1];
            avail3+=allocated[i-1][2];
            printf("Process %d is completed\n", i);
        }
        else{
            //bankers alogrithm
            printf("Process %d is not completed\n", i);
        }
    }


    return 0;
}

