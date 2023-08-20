// View_Plane class declarations

#ifndef VIEW_PLANE_HPP
#define VIEW_PLANE_HPP

namespace RT {

    class View_Plane {
        friend void test_def_ctor();
        friend void test_ctor(); 
    private:
        // vertical/horizontal resolution of image:
        int vres;
        int hres;
        // top, bottom, left, right.
        float t, b, l, r;

    public:
        View_Plane();
        View_Plane(int v, int h, float t, float b, float l, float r);
    };
}

#endif
