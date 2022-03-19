#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996);
typedef struct Pol
{
    double coef; //系数
    double exp;  //指数
    struct Pol *next;
} Polynomial;

void CreateList(Pol *&L, int n) //
{
    Pol *s, *r;
    L = (Pol *)malloc(sizeof(Pol));
    r = L;
    for (int i = 0; i < n; i++)
    {
        s = (Pol *)malloc(sizeof(Pol));
        scanf("%lf%lf", &s->coef, &s->exp);
        r->next = s;
        r = s;
    }
    r->next = NULL;
}

//算法
void UPSum(Pol *&L1, Pol *&L2)
{
    Pol *p = L1->next, *q = L2->next;
    Pol *pre = L1, *t1, *t2;

    while (p != NULL && q != NULL)
    {
        if (p->exp < q->exp) //p 所指指数小于 q 所指指数
        {
            pre = p;
            p = p->next;
        }
        else if (p->exp > q->exp) //p 所指指数大于 q 所指指数
        {
            pre->next = q;
            pre = q;
            q = q->next;
            pre->next = p;
        }
        else //p,q 所指指数相等
        {
            p->coef = p->coef + q->coef;
            if (p->coef == 0)
            {
                pre->next = pre->next->next;
                t1 = p;
                p = p->next;
                free(t1);
            }
            else
            {
                p = p->next;
                pre = pre->next; //pre 始终保持指向 p 前面的一个节点，便于删除p
            }
            t2 = q; //不论 p->coef 是否为零，q 所指节点都会被删除
            q = q->next;
            free(t2);
        }
    }
    if (q != NULL)
        pre->next = q;
    free(L2);
}

//输出
void Result(Pol *L)
{
    Pol *p = L->next;
    while (p != NULL)
    {
        printf("%.0lfx^%.0lf", p->coef, p->exp);
        if (p->next != NULL)
            printf("+");
        p = p->next;
    }
    printf("\n");
}

int main()
{
    Pol *L1, *L2;
    int a, b;
    printf("请输入多项式的项数及每项的系数和指数：\n");
    printf("P(x): ");
    scanf("%d", &a);
    CreateList(L1, a);
    printf("\n");
    printf("请输入多项式的项数及每项的系数和指数：\n");
    printf("Q(x): ");
    scanf("%d", &b);
    CreateList(L2, b);
    printf("\n");
    UPSum(L1, L2);
    Result(L1);
}
