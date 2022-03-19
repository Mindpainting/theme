#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996); //解决VS报严重性代码错误

/* 通讯录 */

typedef struct LNode
{
    char name[20];
    double ph_number;
    struct LNode *next;
} LinkNode;

//创建通讯录
LNode *CreateList(LNode *&L)
{
    LNode *s, *r;
    int n;
    L = (LNode *)malloc(sizeof(LNode));
    r = L;

    printf("请输入要创建联系人的个数：");
    scanf("%d", &n);
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        s = (LNode *)malloc(sizeof(LNode));

        printf("请输入第%d个联系人的姓名，电话：\n", i + 1);
        scanf("%s%lf", &s->name, &s->ph_number);
        printf("\n");

        r->next = s;
        r = s;
    }
    r->next = NULL;
    return L;
}

//添加联系人
void ListInsert(LNode *&L)
{
    LNode *new_s, *r = L;
    while (r->next != NULL)
    {
        r = r->next;
    }
    new_s = (LNode *)malloc(sizeof(LNode));

    printf("请输入要添加的联系人的姓名，电话：\n");
    scanf("%s%lf", &new_s->name, &new_s->ph_number);
    printf("\n");

    r->next = new_s;
    r = new_s;
    r->next = NULL;
}

//查找联系人
bool Locate(LNode *&L)
{
    LNode *p = L->next;
    char name_[20];

    printf("请输入要查找的联系人的姓名：\n");
    scanf("%s", &name_);
    printf("\n");

    while (p != NULL && strcmp(p->name, name_) != 0) //注意判断条件
    {
        p = p->next;
    }
    if (p == NULL)
        return false;
    else
        return true;
}

//修改联系人
bool ModifyList(LNode *&L)
{
    LNode *p = L;
    char name_[20];
    double ph_number_;

    printf("请输入要修改的联系人的姓名：\n");
    scanf("%s", name_);
    printf("\n");

    while (p != NULL && strcmp(p->name, name_) != 0) //注意判断条件
    {
        p = p->next;
    }
    if (p == NULL)
        return false;
    else
    {
        printf("请输入修改后的电话号码为：\n");
        scanf("%lf", &ph_number_);
        printf("\n");
        p->ph_number = ph_number_;
        return true;
    }
}

//删除联系人
bool ListDelete(LNode *&L)
{
    LNode *p = L->next, *q = L;
    char name_[20];

    printf("请输入要删除联系人的姓名：\n");
    scanf("%s", name_);
    printf("\n");

    while (p != NULL && strcmp(p->name, name_) != 0) //注意判断条件
    {
        p = p->next;
        q = q->next;
    }
    if (p == NULL)
        return false;
    else
    {
        q->next = q->next->next;
        free(p);
        return true;
    }
}

//加载通讯录
void DispList(LNode *L)
{
    int i = 0;
    LNode *p = L->next;
    while (p != NULL)
    {
        printf("姓名：%s  电话：%.0lf\n", p->name, p->ph_number);
        p = p->next;
        i++;
    }
}

int main()
{
    printf("*****************************************\n");
    printf("*                                       *\n");
    printf("*            1：添加联系人              *\n");
    printf("*                                       *\n");
    printf("*            2: 查找联系人              *\n");
    printf("*                                       *\n");
    printf("*            3: 修改联系人              *\n");
    printf("*                                       *\n");
    printf("*            4: 删除联系人              *\n");
    printf("*                                       *\n");
    printf("*            5: 加载通讯录              *\n");
    printf("*                                       *\n");
    printf("*****************************************\n");
    printf("\n");

    LNode *L = CreateList(L);
    int operand;
    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        printf("请输入您要执行操作的操作数：\n");
        scanf("%d", &operand);
        switch (operand)
        {
        case 1:
            ListInsert(L);
            break;
        case 2:
            if (Locate(L) == 1)
            {
                printf("找到该联系人\n");
                printf("\n");
                break;
            }
            else
            {
                printf("未找到改联系人\n");
                printf("\n");
                break;
            }
        case 3:
            if (ModifyList(L) == 1)
            {
                printf("修改成功\n");
                printf("\n");
                break;
            }
            else
            {
                printf("修改失败\n");
                printf("\n");
                break;
            }
        case 4:
            if (ListDelete(L) == 1)
            {
                printf("删除成功\n");
                printf("\n");
                break;
            }
            else
            {
                printf("删除失败\n");
                printf("\n");
                break;
            }
        case 5:
            DispList(L);
            break;
        default:
            printf("ERROR!!!\n");
        }
    }
    return 0;
}
