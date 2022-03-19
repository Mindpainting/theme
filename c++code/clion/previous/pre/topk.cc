#include <iostream>
#include <cstdlib>
#define Maxsize 1000
#define Topk 50
using namespace std;

//交换
void swap(int a[], int i, int j)
{
    int tmp0;
    tmp0 = a[i];
    a[i] = a[j];
    a[j] = tmp0;
}

//输出
void display(int a[], int n)
{
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << endl;
}

//筛选—将堆中最小的元素放在堆顶
void sift(int a[], int low, int high)
{
    int i = low, j = 2 * i;
    int tmp = a[i]; //始终记录着根结点
    while (j <= high)
    {
        if (j < high && a[j] > a[j + 1])
            j++;
        if (tmp > a[j])
        {
            swap(a, i, j);
            i = j;
            j = 2 * i;
        }
        else
            break;
    }
}

//堆排序算法
void heapsort(int a[], int n)
{
    for (int j = n; j > 1; j--)
    {
        swap(a[1], a[j]);  //最后一个元素与根a[1]交换，把最小的元素a[1]放在最后一个位置
        sift(a, 1, j - 1); //对除最后一个元素的剩余的元素进行筛选，找到最小的元素
    }
}

int main()
{
    int a[Topk + 1], ra[Maxsize + 1];
    for (int i = 1; i <= Maxsize; i++) //随机产生1000个1000以内的整数
        ra[i] = rand() % 1000;
    cout << "1000个随机产生的整数：" << endl;
    display(ra, Maxsize);
    for (int j = 1; j <= Topk; j++) //将1000个数的前Topk个复制到数组a
        a[j] = ra[j];
    for (int i = Topk / 2; i >= 1; i--) //循环建立初始堆 ，从最后一个分支结点开始
        sift(a, i, Topk);
    for (int k = Topk + 1; k <= Maxsize; k++) //对从Topk往后的元素进行扫描，比堆顶元素大，则替换堆顶元素并重新调整
    {
        if (ra[k] > a[1])
        {
            a[1] = ra[k];
            sift(a, 1, Topk);
        }
    }
    cout << endl
         << "最大的" << Topk << "个数：" << endl;
    heapsort(a, Topk);
    display(a, Topk);
    return 0;
}