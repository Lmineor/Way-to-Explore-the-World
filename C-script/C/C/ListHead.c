#include <stdlib.h>
#include <stdio.h>
#include "mydefine.h"
#define LIST_INIT_SIZE     100 //线性表存储空间的初始分配量
#define LISTINCREMENT        10 //线性表存储空间的分配增量

typedef struct {
    int   *elem; //存储空间地址
    int    length ;  //当前长度
    int    listsize;    // 当前分配的存贮容量（以sizeof(EleType）为单位
}SqList;


int InitList_Sq(SqList *L){
    //构造一个空的线性表L。
    L->elem = (int *)malloc(LIST_INIT_SIZE*sizeof(int));//分配内存空间
    if (!L->elem) exit(OVERFLOW); //存储分配失败
    L->length = 0;
    L->listsize = LIST_INIT_SIZE; // 初始存储容量
    return OK;
}//InitList_Sq



int ListInsert_Sq(SqList *L, int i, int e){
    //在顺序表L中第i个位置之前插入新的元素e
    // i的合法值为1<= i<=ListLength_Sq(L)+1
    if (i<1 || i>L->length+1) return ERROR;
    if (L->length>=L->listsize){
        //当前存储空间已满，增加分配
        int *newbase; //新的基址
        newbase = (int *)realloc(L->elem, (L->listsize+LISTINCREMENT)*sizeof(int));//在已有的基础上增加空间
        if (!newbase) exit(ERROR);//存储分配失败
        L->elem = newbase; //将新基址赋值给L
        L->listsize += LISTINCREMENT; // 增加存储容量
    }
    int *q,*p;
    q = &(L->elem[i-1]);//q为插入位置，例如插入位置为5 ，但是实际上应该是从零开始的话第四个位置
    for (p = &(L->elem[L->length-1]);p>=q;p--) *(p+1) = *p;//插入位置之后的元素后移
    *q = e;//插入e
    L->length++;//表长增1
    return OK;
}//ListInsert_Sq

void print_sql(SqList *L){
    int i;
    for (i=0;i<L->length;i++){
        printf("%d",L->elem[i]);
    }
}


void start(){
    printf("输入原始序列大小：");
    SqList L;
    int index,tar;
    int i;
    printf("输入原始序列大小：");
    scanf("%d",&L.length);
    printf("输入原始序列：");
    for (i=0;i<L.length;i++){
        scanf("%d",&L.elem[i]);
    }
    printf("输入您要插入的位置：");
    scanf("%d",&index);
    printf("输入您要插入的元素：");
    scanf("%d",&tar);
    ListInsert_Sq(&L,index,tar);
    print_sql(&L);
}


int main(){
    start();
    return OK;
}