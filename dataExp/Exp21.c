/*************************************************************************
    > File Name: Exp21.c
    > Author: Yiyao Mao
    > Mail: amaoworks@gmail.com 
    > Created Time: 2017年12月24日 星期日 17时40分10秒
 ************************************************************************/

#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1
#define STACK_INT_SIZE 10  /*存储空间初始分配量*/
#define STACKINCREMENT 5  /*存储空间分配增量*/

typedef  int ElemType; /*定义元素的类型*/
typedef struct{
    ElemType *base;
    ElemType *top;
    int stacksize;     /*当前已分配的存储空间*/
} SqStack;

int InitStack(SqStack *S);   /*构造空栈*/
int push(SqStack *S,ElemType e); /*入栈*/
int Pop(SqStack *S,ElemType *e);  /*出栈*/
int CreateStack(SqStack *S);     /*创建栈*/
void PrintStack(SqStack *S);   /*出栈并输出栈中元素*/

int InitStack(SqStack *S){
    S->base=(ElemType *)malloc(STACK_INT_SIZE *sizeof(ElemType));
    if(!S->base) return ERROR;
    S->top=S->base;
    S->stacksize=STACK_INT_SIZE;
    return OK;
}/*InitStack*/

int Push(SqStack *S,ElemType e){
	if(S->top - S->base >= S->stacksize){
		S->base = (ElemType *)realloc(S->base ,(S->stacksize+STACKINCREMENT)*sizeof(ElemType));
		if(!S->base){
			return ERROR;
		}
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	S->top = e;
	S->top++;
	return OK;
}/*Push*/

int Pop(SqStack *S,ElemType *e){
	if(S->base == S->top){
		return ERROR;
	}
	S->top--;
	*e = S->top;
	return OK;
}/*Pop*/

int CreateStack(SqStack *S){
    int e;
    if(InitStack(S))
        printf("Init Success!\n");
    else{
        printf("Init Fail!\n");
        return ERROR;
    }
    printf("input data:(Terminated by inputing a character)\n");
    while(scanf("%d",&e))
        Push(S,e);
    return OK;
}/*CreateStack*/

void PrintStack(SqStack *S){
    ElemType e;
    while(Pop(S,&e))
        printf("%3d",e);
}/*Pop_and_Print*/

int main(int argc ,char **argv){
    SqStack ss;
    printf("\n1-createStack\n");
    CreateStack(&ss);
    printf("\n2-Pop&Print\n");
    PrintStack(&ss);
    return 0;
}
