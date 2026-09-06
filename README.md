
### 📋 Extreme Desktop Mode

Click the copy button below, then paste it into your browser's bookmarks bar:

```text
javascript:(function()%7Bvar%20metas=document.getElementsByTagName('meta');for(var%20i=metas.length-1;i%3E=0;i--)%7Bif(metas%5Bi%5D.name&&metas%5Bi%5D.name.toLowerCase()==='viewport')%7Bmetas%5Bi%5D.parentNode.removeChild(metas%5Bi%5D);%7D%7Dvar%20meta=document.createElement('meta');meta.name='viewport';meta.content='width=1280,%20initial-scale=0.3,%20maximum-scale=2.0,%20user-scalable=yes';document.getElementsByTagName('head')%5B0%5D.appendChild(meta);document.body.style.width='1280px';document.documentElement.style.width='1280px';document.body.style.minWidth='1280px';document.documentElement.style.minWidth='1280px';document.body.style.overflowX='auto';try%7BObject.defineProperty(navigator,'userAgent',%7Bget:function()%7Breturn%20'Mozilla/5.0%20(Windows%20NT%2010.0;%20Win64;%20x64)%20AppleWebKit/537.36%20(KHTML,%20like%20Gecko)%20Chrome/114.0.0.0%20Safari/537.36';%7D%7D);%7Dcatch(e)%7B%7Dalert('Extreme%20Desktop%20Mode%20Applied!');%7D)();




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

