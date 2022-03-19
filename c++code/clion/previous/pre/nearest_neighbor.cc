#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100;

struct Point
{
    double x, y;
    Point(double xx = 0, double yy = 0) : x(xx), y(yy) {}
    bool operator<(const Point &p) const
    {
        return x < p.x;
    }
};
Point p[maxn], tmp[maxn];

double solve(Point p[], int le, int ri)
{
    if (le >= ri)
        return INT_MAX;
    int mid = le + ri >> 1;
    double x = p[mid].x;
    double d = min(solve(p, le, mid), solve(p, mid + 1, ri));

    //归并排序中的合并操作
    int i = le, j = mid + 1, k = 0;
    while (i <= mid && j <= ri)
    {
        if (p[i].y < p[j].y)
            tmp[k++] = p[i++];
        else
            tmp[k++] = p[j++];
    }
    while (i <= mid)
        tmp[k++] = p[i++];
    while (j <= ri)
        tmp[k++] = p[j++];
    for (int i = le; i <= ri; ++i)
        p[i] = tmp[i - le];

    //求解最近点对距离
    vector<Point> v;
    for (int i = le; i <= ri; ++i)
    {
        if (fabs(p[i].x - x) > d)
            continue;
        for (int j = (int)v.size() - 1; j >= 0; --j)
        {
            double dx = p[i].x - v[j].x;
            double dy = p[i].y - v[j].y;
            if (dy >= d)
                break;
            d = min(d, sqrt(dx * dx + dy * dy));
        }
        v.push_back(p[i]);
    }
    return d;
}

int main()
{
    int n;
    cout << "Please enter the number of points: ";
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> p[i].x >> p[i].y;
    sort(p, p + n);
    cout << solve(p, 0, n - 1) << endl;
    return 0;
}
