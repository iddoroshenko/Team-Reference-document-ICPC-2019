double sqr(double a)
	{return a * a;}
bool doubleEqual(double a, double b)
	{return fabs(a - b) < 1e-9;}
bool doubleLessOrEqual(double a, double b) 
	{return a < b || doubleEqual(a, b);}
bool doubleLess(double a, double b)
	{return a < b && !doubleEqual(a, b);}
bool doubleGreaterOrEqual(double a, double b) 
	{return a > b || doubleEqual(a, b);}
bool doubleGreater(double a, double b) 
	{return a > b && !doubleEqual(a, b);}
double mySqrt(double a){
        if(doubleLess(a, 0) ) 
        {
                throw "sqrt(-1)";
        }
        if(a < 0) return 0; 
        return sqrt(a);
}
struct Point{ 
private: double x, y; 
public:
        Point(): x(0), y(0) {} 
        Point(double x, double y): x(x), y(y) {} 
        void scan() ...
        void print() ...
		operators...
		// vector multiplication 
        double operator*(const Point & p) const { 
                return x * p.y - y * p.x;}
        double length() const {return mySqrt(*this % *this);}
		// destination between 2 points
        double distTo(const Point & p) const 
        {return (*this - p).length();}
		// between point and line(A, B)
        double distTo(const Point & A, const Point & B) const 
        {
                double d = A.distTo(B);
				// double triangle square
                double s = (*this - A) * (*this - B); 
				// method of squares
                return abs(s) / d; 
        }
 
        Point normalize(double k = 1) const 
        {
                double len = length();
                if(doubleEqual(len, 0) ) 
                {
                        if(doubleEqual(k, 0) )
                        {
                                return Point();
                        }
                        throw "zero-size vector"; 
                }
                return *this * (k / len);
        }
		// height from point to line
        Point getH(const Point & A, const Point & B) const 
        {
                Point C = *this;
                Point v = B - A;
                Point u = C - A; 
                double k = v % u / v.length(); 
                v = v.normalize(k); 
                Point H = A + v; 
                return H;
        }
 
        Point rotate() const // counterclockwise
        {return Point(-y, x);}
		// turn to an angle of alpha counterclockwise 
		//(or clockwise if alpha < 0)
        Point rotate(double alpha) const 
        { return rotate(cos(alpha), sin(alpha) ); }
 
        Point rotate(double cosa, double sina) const 
        {
                Point v = *this;
                Point u = v.rotate();
                Point w = v * cosa + u * sina; 
                return w;
        }
 
        bool isZero() const
        { return doubleEqual(x, 0) && doubleEqual(y, 0);}
		// is point on line(A, B)
        bool isOnLine(const Point & A, const Point & B) const 
        {return doubleEqual( (A - *this) * (B - *this), 0);}
 
        bool isInSegment(const Point & A, const Point & B) const 
        { return isOnLine(A, B) && 
		doubleLessOrEqual( (A - *this) % (B - *this), 0 );}
 
        bool isInSegmentStrictly(const Point & A, const Point & B) const 
        {return isOnLine(A, B) && 
		doubleLess( (A - *this) % (B - *this), 0 );}
		// angle between vector and OX
        double getAngle() const
        { return atan2(y, x); }
		// oriented angle between 2 vectors
        double getAngle(Point u) const 
        {
                Point v = *this;
                return atan2(v * u, v % u); 
        }
 
};
 
 
int getIntersection // between line(A,B) and line(C, D)
        (
                const Point & A,
                const Point & B,
                const Point & C,
                const Point & D,
                Point & O
        )
{
        Point v = B - A; 
        double s1 = (C - A) * (D - A);
        double s2 = (D - B) * (C - B); 
        double s = s1 + s2; 
        if(doubleEqual(s, 0) ) 
        {
                if(!A.isOnLine(C, D) ) // lines are collinear
				{
                        return 0; // intersection is empty
                }
                return 2; //intersection is not empty
        }
        v = v / s;
        v = v * s1; 
        O = A + v; 
        return 1; // one intersection point
}
 
 // between two circles with centers A and B and rasius rA and rB
int getIntersection 
     ( const Point & A, double rA,const Point & B,double rB,  Point & M, Point & N )
{
        double d = A.distTo(B); 
		//circles do not touch
        if(doubleLess(rA + rB, d) || doubleLess(d, fabs(rA - rB)) ) 
        {
                return 0;
        }
		// proection length
        double a = (sqr(rA) - sqr(rB) + sqr(d) ) / 2 / d; 
		// dist between intersection point and line (A, B)
        double h = mySqrt(sqr(rA) - sqr(a)); 
        Point v = B - A; 
        Point u = v.rotate(); 
        v = v.normalize(a);
        u = u.normalize(h); 
        Point H = A + v;
        M = H + u;
        N = H - u;
		//if u = 0, circles have intersection in 1 point
        if(u.isZero() ) return 1; 
        return 2;
}
 
 
 
int getIntersection // between line and circle
        (
                const Point & A,
                const Point & B,
                const Point & O,
                double r,
                Point & M,
                Point & N
        )
{
        double h = O.distTo(A, B);
        if(doubleLess(r, h) ) 
        {
                return 0;
        }
        Point H = O.getH(A, B);
        Point v = B - A; 
        double k = mySqrt(sqr(r) - sqr(h) ); 
        v = v.normalize(k);
        M = H + v;
        N = H - v;
        if(v.isZero() ) return 1;
        return 2;
}
 
 
int getTangent  //  from point to cicle
        (
                const Point & A,
                const Point & O,
                double r,
                Point & M,
                Point & N
        )
{
        Point v = O - A;
        double d = v.length();
        if(doubleLess(d, r) ) return 0; // point is inside circle
        double alpha = asin(r / d); 
        double L = mySqrt(sqr(d) - sqr(r)); 
        v = v.normalize(L); 
        M = A + v.rotate(alpha);  
        N = A - v.rotate(alpha); 
        if(doubleEqual(r, d) ) return 1;
        return 2;
}
 
 
void getOutTangent  // between two circles
        (
                Point A,
                double rA,
                Point B,
                double rB,
                pair<Point, Point> & P,
                pair<Point, Point> & Q
        )
{
        if(rA > rB)
        {
                swap(rA, rB);
                swap(A, B);
        }
        Point u = (A - B).rotate(asin(r / d)).rotate().normalize(rA);
        P.first = A + u;
        Q.first = A - u;
        Point T1, T2;
        getTangent(A, B, rB - rA, T1, T2);
        P.second = T1 + u;
        Q.second = T2 - u;
}