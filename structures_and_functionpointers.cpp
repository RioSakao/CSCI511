#include <iostream>

using namespace std;

struct Triangle {
        char color; // 'r' = red, 'g' = green, 'b' = blue
        char shade; // 'l' = light, 'd' = dark
        short base;
        short height;
};

struct Circle {
        char color;
        char shade;
        double radius;
};

struct VT_Cir {
        void (*VT_dc)(struct Circle *);
        double (*VT_ac)(struct Circle *);
};

struct VT_Tri {
        void (*VT_dt)(struct Triangle *);
        double (*VT_at)(struct Triangle *);
};

/**Initializes x's value **/
void setTriangle(struct Triangle* x, char col, char sha, short b, short h) {
        x->color = col;
        x->shade = sha;
        x->base = b;
        x->height = h; 
}

/**Print the attribute of x**/
void drawTriangle(struct Triangle *x) {
        if (x->shade == 'd') {
                cout << "dark ";
        } else if (x->shade == 'l') {
                cout << "light ";
        }

        if (x->color == 'r') {
                cout << "red ";
        } else if (x->color == 'g'){
                cout << "green ";
        } else if (x->color == 'b'){
                cout << "blue ";
        } else {
                cout << x->color << " ";
        }
        cout << "triangle. base=" << x->base <<
                ", heigth=" << x->height << endl;
}


/**Calculate the area of the triangle by dividing by 2.0 so that a real number is calculated.**/
double areaTriangle(struct Triangle *x) {
        double area;
        
        area = (x->base) * (x->height) / 2.0;

        return area;
}

/**Initialize's x's values**/
void setCircle(struct Circle* x, char col, char sha, double r){
        x->color = col;
        x->shade = sha;
        x->radius = r;
}


/**Print the attributes of x**/
void drawCircle(struct Circle *x){
        if (x->shade == 'd') {
                cout << "dark ";
        } else if (x->shade == 'l') {
                cout << "light ";
        }

        if (x->color == 'r') {
                cout << "red ";
        } else if (x->color == 'g'){
                cout << "green ";
        } else if (x->color == 'b'){
                cout << "blue ";
        } else {
                cout << x->color << " ";
        }
        cout << "circle, radisu=" << x->radius << endl;
}

double areaCircle(struct Circle* x){
        double area;
        area = 3.14 * (x->radius) * (x->radius);
        return area;
}


int main() {
        
        short base = 10, height=5;
        struct Triangle triangle;
        struct Triangle *t = &triangle;
        setTriangle(t,'r','d',base, height);
        
        double radius = 2;
        struct Circle circle;
        struct Circle *c = &circle;
        setCircle(c, 'b', 'l', radius);

        struct VT_Cir vtcir;
        vtcir.VT_dc = drawCircle;
        vtcir.VT_ac = areaCircle;
        vtcir.VT_dc(c);
        cout << "Circle area: " << vtcir.VT_ac(c);
        cout << endl;

        struct VT_Tri vttri;
        vttri.VT_dt = drawTriangle;
        vttri.VT_at = areaTriangle;
        vttri.VT_dt(t);
        cout << "Triangle area: " << vttri.VT_at(t);
        cout << endl;

        return 0;
}
