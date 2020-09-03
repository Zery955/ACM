#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<double, double> pdd;
const double eps = 1e-10;
const double pi = acos(-1);
inline int sgn(double d){if(fabs(d) < eps) return 0;if(d > 0) return 1;return -1;}
inline double rad(double _deg){return _deg / 180.0 * pi;}
inline double deg(double _rad){return _rad / pi * 180.0;}
struct Point{
	double x, y;
	void read(){scanf("%lf%lf", &x, &y);}
	Point():x(0.0), y(0.0){}
	Point(double a, double b = 0.0): x(a), y(b){}
	Point(const Point& p): x(p.x), y(p.y){}
	Point operator + (const Point& a){return {x + a.x, y + a.y};}
	Point operator - (const Point& a){return {x - a.x, y - a.y};}
	double operator * (const Point& a){return x * a.x + y * a.y;}
	double operator ^ (const Point& a){return x * a.y - y * a.x;}
	bool operator == (const Point& p){return sgn(x - p.x) == 0 && sgn(y - p.y) == 0;}
	bool operator < (const Point &p) const{
		if(sgn(x - p.x) == 0) 
			return sgn(y - p.y) == -1;
		return sgn(x - p.x) == -1;
	}
	double length(){return sqrt(x * x + y * y);}
}typedef Vector;
struct Line{
	Point a, b;
	void read(){a.read(); b.read();}
	Line() : a(0.0, 0.0) , b(0.0, 0.0){}
};
struct Segment{
	Point a, b;
	void read(){a.read(); b.read();}
	Segment() : a(0.0, 0.0) , b(0.0, 0.0){}
	Segment(Point _a, Point _b) : a(_a), b(_b){}
};
double Distance(const Point &a, const Point &b) 
{
	double x = a.x - b.x;
	double y = a.y - b.y;
	return sqrt(x * x + y * y);
}
Point Projection(Point p, Line l)
{ 
	// 点在直线上的投影点
	Vector v1 = l.b - l.a;
	Vector v2 = p - l.a;
	double k1 = v1 * v2;
	double k2 = v1.length();
	k1 /= k2 * k2;
	return {l.a.x + v1.x * k1, l.a.y+ v1.y * k1};
}
Point Reflection(Point p, Line l)
{
	// 点关于直线对称
	Point p0 = Projection(p, l);
	Vector v0 = p0 - p;
	return p0 + v0;
}
int ccw(Point p, Segment sg)
{	// Counter_Clockwise
	// p 关于(sg.a -> sg.b)的位置关系
	Vector v0 = sg.b - sg.a;
	Vector v1 = p - sg.a;
	
	int fcross = sgn(v0 ^ v1);
	
	if(fcross == 1) return 1; // 逆时针方向
	if(fcross == -1) return -1; // 顺时针方向
	
	int fdot = sgn(v0 * v1);
	
	if(fdot == -1) return 2; // 反向线段外共线
	if(v0.length() < v1.length()) return -2; //正向线段外共线
	return 0; //点在线段上
}
bool isParallel(Line l1, Line l2)
{
	//没有判断重合
	return sgn((l1.b - l1.a) ^ (l2.b - l2.a)) == 0;
}
bool isOrthogonal(Line l1, Line l2)
{
	//正交
	return sgn((l1.b - l1.a) * (l2.b - l2.a)) == 0;
}
bool isIntersection(Segment sg1, Segment sg2)
{
	// 判断线段是否有交点
	return ccw(sg2.a, sg1) * ccw(sg2.b, sg1) <= 0 && ccw(sg1.a, sg2) * ccw(sg1.b, sg2) <= 0;
}
bool isConvex(vector<Point> p)
{
	//判断凸包(顺时针或逆时针给点)
	if(p.size() < 3) return 0;
	bool flag1 = 1, flag2 = 1;
	int n = p.size();
	for(int i = 0; i < n; ++i)
	{
		if(ccw(p[i], {p[(i + 1) % n], p[(i + 2) % n]}) == -1) flag1 = 0; //逆时针方向
		if(ccw(p[i], {p[(i + 1) % n], p[(i + 2) % n]}) == 1) flag2 = 0; //顺时针方向
	}
	return flag1 || flag2;
}
double Area(vector<Point> p)
{
	//计算多边形面积
	double res = 0;
	int n = p.size();
	for(int i = 0; i < n; ++i)
		res += (p[i] ^ p[(i + 1) % n]);
	return fabs(res / 2.0);
}

int main()
{

	return 0;
}