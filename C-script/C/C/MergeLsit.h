/******************************************************/
/*已知线性表La和Lb中的数据元素按照非递减排列。               */
/*归并La和Lb得到新的线性表Lc，Lc的数据元素也按值非递减排列    */
/******************************************************/
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE  100
typedef struct{
    int elem[MAX_SIZE];
    int len;
}sqLsit;

void MergerList(sqLsit *La, sqLsit *Lb, sqLsit *Lc){
    int i, j, k;
    i = j = k = 0;
    if (La->len + Lb->len <=MAX_SIZE){
        while (i<La->len && j<Lb->len){
            if (La->elem[i]<Lb->elem[j]){
                Lc->elem[k] = La->elem[i];
                i++;
                k++;
            }
            else{
                Lc->elem[k] = Lb->elem[j];
                j++;
                k++;
            }
        }
        while (i<La->len){
            Lc->elem[k] = La->elem[i];
            i++;
            k++;
        }
        while (j<Lb->len){
            Lc->elem[k] = Lb->elem[j];
            j++;
            k++;
        }
        Lc->len = La->len+Lb->len;
    }
    else printf("out of bound");
}

void print(sqLsit *l){
    int i;
    for (i=0;i<l->len;i++){
        printf("%d",l->elem[i]);
    }
    printf("\n");
}

void StartMergeList(){
    sqLsit La;
    sqLsit Lb;
    sqLsit Lc;
    int i;
    printf("input the len of La");
    scanf("%d", &La.len);
    printf("input the elem of La");
    for(i=0;i<La.len;i++){
        scanf("%d",&La.elem[i]);
    }
    printf("input the len of Lb");
    scanf("%d",&Lb.len);
    printf("input the elem of Lb");
    for(i=0;i<Lb.len;i++){
        scanf("%d",&Lb.elem[i]);
    }
    MergerList(&La, &Lb, &Lc);
    print(&Lc);
}
