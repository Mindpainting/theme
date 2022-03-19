#include <stdio.h>
#define M 5
#define N 6
#define MaxSize 5
typedef int ElemType;

typedef struct
{
    int r;      //行号
    int c;      //列号
    ElemType d; //元素值
} TriNode;      //三元组类型

typedef struct TSM
{
    int r1;   //行数
    int c1;   //列数
    int nums; //非零元素个数
    TriNode dt[MaxSize];
} TSMatrix; //三元组顺序表类型

void CreateMat(TSMatrix &t, ElemType b[M][N])
{
    t.r1 = M;
    t.c1 = N;
    t.nums = 0;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (b[i][j] != 0)
            {
                t.dt[t.nums].r = i;
                t.dt[t.nums].c = j;
                t.dt[t.nums].d = b[i][j];
                t.nums++;
            }
        }
    }
}

//矩阵转置
//转置前，矩阵三元组表示以行序优先 ，转置后，矩阵三元组表示以原矩阵的列序优先
//即原矩阵列号靠前的，在转置后矩阵的三元组表示中越靠前
//保证转置后的矩阵三元组表示都是以行序优先
//算法一
void MatrixTranspose(TSMatrix &t, TSMatrix &t1)
{
    t1.r1 = t.c1;
    t1.c1 = t.r1;
    t1.nums = t.nums;
    int k = 0;
    for (int i = 0; i < t1.r1; i++) //找转置后矩阵第一行非零元素
    {
        for (int j = 0; j < t1.nums; j++) //对原矩阵非零元素扫描，找原矩阵三元组表示中列号靠前的元素
        {
            if (t.dt[j].c == i)
            {
                t1.dt[k].r = t.dt[j].c;
                t1.dt[k].c = t.dt[j].r;
                t1.dt[k].d = t.dt[j].d;
                k++;
            }
        }
    }
}

/*
//算法二
void  MatrixTranspose(TSMatrix& t, TSMatrix& t0)
{
	t0.r1 = t.c1;
	t0.c1 = t.r1;
	t0.nums = t.nums;
	int num[N], cpot[N];

	for (int i = 0; i < N; i++) //初始化数组元素都为0，表示矩阵每一列都有0个非零元素 ********
		num[i] = 0;

	for (int j = 0; j < t.nums; j++) //对原矩阵三元组遍历，找到三元组每个元素的列号，找到一个，数组对应该列的数值加一 
		num[t.dt[j].c]++;

	printf(" num[]: ");
	for (int i = 0; i < N; i++) 
		printf("%d ", num[i]);
	printf("\n");

	cpot[0] = 0;
	for (int i = 1; i < N; i++)  //判定条件为 N 而不是 t.nums **********
		cpot[i] = cpot[i - 1] + num[i - 1]; //下一列的第一个元素的位置 = 上一列第一个元素的位置 + 上一列非零元素的个数

	printf("cpot[]: ");
	for (int i = 0; i < N; i++)
		printf("%d ", cpot[i]);
	printf("\n");

	for (int i = 0; i < t.nums; i++)
	{
		int p = t.dt[i].c;//列号 
		int q = cpot[p];  //第一个非零元在 t0.dt[] 中的位置
		t0.dt[q].r = t.dt[i].c;
		t0.dt[q].c = t.dt[i].r;
		t0.dt[q].d = t.dt[i].d;
		cpot[p]++;//t0.dt[] p列第一个元素赋值后，则该列 cpot[p]++变为第一个元素 
	}
}
*/
//输出三元组
void OutputTSM(TSMatrix &t2)
{
    printf("          %d   %d   %d\n", t2.r1, t2.c1, t2.nums);
    printf("          *********\n");
    for (int i = 0; i < t2.nums; i++)
        printf("          %d   %d   %d\n", t2.dt[i].r, t2.dt[i].c, t2.dt[i].d);
}

//输出矩阵
void OutputM(TSMatrix &t3)
{
    int k = 0;
    for (int i = 0; i < t3.r1; i++)
    {
        printf("          ");
        for (int j = 0; j < t3.c1; j++)
        {
            if (t3.dt[k].r == i && t3.dt[k].c == j)
            {
                printf("%d ", t3.dt[k].d);
                k++;
            }
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    int a[M][N] = {{0, 1, 0, 0, 0, 0}, {3, 0, 0, 0, 0, 0}, {0, 5, 0, 0, 0, 0}, {0, 0, 0, 6, 0, 0}, {0, 0, 0, 0, 0, 7}};
    TSMatrix t, t1;
    CreateMat(t, a);
    printf("算法一：\n"); //printf("算法二：\n");
    printf("转置前矩阵：\n");
    OutputM(t);
    printf("三元组表示：\n");
    OutputTSM(t);
    MatrixTranspose(t, t1);
    printf("转置后矩阵：\n");
    OutputM(t1);
    printf("三元组表示：\n");
    OutputTSM(t1);
    return 0;
}