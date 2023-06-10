#include <iostream>
#include <iterator>
using namespace std;

struct Triangle;
struct Circle;

struct VT_Tri {
        void (*VT_dt)(struct Triangle *);
        double (*VT_at)(struct Triangle *);
};

struct VT_Cir {
        void (*VT_dc)(struct Circle *);
        double (*VT_ac)(struct Circle *);
};

struct Triangle {
        char color; // 'r' = red, 'g' = green, 'b' = blue
        char shade; // 'l' = light, 'd' = dark
        struct VT_Tri vttri;
        short base;
        short height;
};

struct Circle {
        char color;
        struct VT_Cir vtcir;
        char shade;
        double radius;
};

double areaCircle(struct Circle* x){
        double area;
        area = 3.14 * (x->radius) * (x->radius);
        return area;
}

double areaTriangle(struct Triangle *x) {
        double area;

        area = (x->base) * (x->height) / 2.0;

        return area;
}

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

/**Initializes x's value **/
void setTriangle(struct Triangle* x, char col, char sha, short b, short h) {
        x->color = col;
        x->shade = sha;
        x->base = b;
        x->height = h;
        (x->vttri).VT_dt = drawTriangle;
        (x->vttri).VT_at = areaTriangle;
}

/**Initialize's x's values**/
void setCircle(struct Circle* x, char col, char sha, double r){
        x->color = col;
        x->shade = sha;
        x->radius = r;
        (x->vtcir).VT_dc = drawCircle;
        (x->vtcir).VT_ac = areaCircle;
}

union shape_ptr {
        struct Circle* cir_ptr;
        struct Triangle* tri_ptr;
};

void do_poly(union shape_ptr shape){
        shape.tri_ptr->vttri.VT_dt(shape.tri_ptr);
        shape.tri_ptr->vttri.VT_at(shape.tri_ptr);
}

int main() {
        
        short base = 10, height=5;
        double radius = 2;
        struct Circle circle1; struct Circle circle2;
        struct Triangle triangle1; struct Triangle triangle2;
        struct Triangle *t1=&triangle1;
        struct Triangle *t2=&triangle2;
        struct Circle *c1=&circle1;
        struct Circle *c2=&circle2;
        setCircle(c1, 'b', 'l', radius);
        setCircle(c2, 'r', 'l', radius);
        setTriangle(t1,'b','d',base, height);
        setTriangle(t2,'r','d',base, height);
        
        union shape_ptr ptr1, ptr2, ptr3, ptr4;
        
        ptr1.cir_ptr = c1; ptr2.cir_ptr = c2;
        ptr3.tri_ptr = t1; ptr4.tri_ptr = t2;
        union shape_ptr shapes[4]={ptr1,ptr2,ptr3,ptr4};
        /**
         * do_poly() works because Circle *cir_ptr and Trianfle *tri_ptr inside of union shape_ptr are
         *  sharing same memory location.
         * Which means that members of both Circle struct and Triangle struct are also sharing same
         *  memory location.
         **/
        for(int i=0; i<4; i++) {
                do_poly(shapes[i]);
        }

        return 0;
}
