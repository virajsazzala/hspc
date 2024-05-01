#include <bits/stdc++.h>
using namespace std;

class Point {
    const double _px, _py;
    
    public:
        Point(double px = 0.0, double py = 0.0) : _px(px), _py(py) {}    

        auto get_point() { return make_tuple(_px, _py); }
        
        static double distance(Point pa, Point pb) {
            auto [pax, pay] = pa.get_point();
            auto [pbx, pby] = pb.get_point();
            return sqrt(((pbx - pax) * (pbx - pax)) + ((pby - pay) * (pby - pay)));
        }

        friend ostream& operator<<(ostream&, Point& p) {
            cout << "(" << p._px << ", " << p._py << ") ";
            return cout;
        }      
};

class Rectangle : public Point {
    Point _pa, _pb, _pc;

    public:
        Rectangle(Point pa, Point pb, Point pc) : _pa(pa), _pb(pb), _pc(pc) {}
        
        double area() {
            double dab = distance(_pa, _pb);
            double dbc = distance(_pb, _pc);
            double dac = distance(_pa, _pc);
            double hyp = (max(max(dab, dbc), dac));

            if (hyp == dab) return dbc * dac;
            else if (hyp == dbc) return dac * dab;
            else return dab * dbc;
        }

        friend ostream& operator<<(ostream&, Rectangle& r) {
            cout << "Area of rectangle with vertices " << r._pa << r._pb << r._pc << "is " << r.area() << endl;
            return cout;
        }
};

int main() {
    /* parsing file */
    ifstream data("data/prob1.txt");

    /* ex: ["3", "0.0 0.0 0.0 1.0 1.0 0.0", ... ] */
    string ts; vector<string> fdat;    
    while(getline(data, ts)) 
        fdat.push_back(ts);

    /* ex: [[0.0, 0.0, 0.0, 1.0, 1.0, 0.0], ... ] */
    vector<vector<double>> idat;
    for (auto i = fdat.begin() + 1; i != fdat.end(); i++) {
        stringstream ss(*i); vector<double> tdat;
        while(getline(ss, ts, ' '))
            tdat.push_back(stod(ts));
        idat.push_back(tdat);
    }

    /* result */
    for (auto& i : idat) {
        Point pa(i[0], i[1]), pb(i[2], i[3]), pc(i[4], i[5]);
        Rectangle r(pa, pb, pc);
        cout << r;
    }

    return 0;
}