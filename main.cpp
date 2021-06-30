#include <GL/freeglut_std.h>
#include <GL/glut.h>
#include <complex>


class henon_map { 
    public: 

    henon_map(double alpha, double beta, 
                double x_min=-5.0, double x_max=5.0, 
                double y_min=-5.0, double y_max=5.0,
                int threshold=412, int max_its=412) {
        //x_range 
        this->x_min = x_min;
        this->x_max = x_max;

        //y_range
        this->y_min = y_min;    
        this->y_max = y_max;   

        a = alpha;
        b = beta;
        threshold; 
        max_its;
    }
    
    //xi+1 = 
    void iterate() {
        const double temp = b*x;
        x = 1.0 - a*x*x + y;
        y = temp;    
    }

    void update_range(double x_min, double x_max, double y_min, double y_max) {
        //x_range 
        this->x_min = x_min;
        this->x_max = x_max;

        //y_range
        this->y_min = y_min;    
        this->y_max = y_max;   
    }

    void update_x_range(double x_min, double x_max) {
        this->x_min=x_min;
        this->x_max=x_max;
    }

    void update_y_range(double x_min, double x_max) {
        this->y_min=y_min;
        this->y_max=y_max;
    }

    private:

    double x_min,y;
    double a,b;
    const double THRESHOLD;
    const double MAX_ITS;
}

/*int test_membership(complex<double> c) {
        complex<double> zi = c;
        complex<double> zi_p1;

        constexpr complex<double> c2(2.0,0);
        constexpr complex<double> c1(1.0,0);

        for(int i=0; i<=30; ++i) {
            if(std::abs(zi) >= 2.0) {
                return 0;
            }	
            zi_p1 = std::pow(zi, 2.0);
            zi_p1 += c2-c1;
            zi_p1 /= (c2*zi+c-c2);

            zi = zi_p1;
        }
        return 1;
}*/

inline void draw_point(complex<double> c) {
    glVertex3f(c.real(),c.imag(), 0.0f);
}

void render(void) {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glBegin(GL_POINTS);
    int size = 200;
    for(int i=-size; i<size; i++) {
        for(int j=0; j<20*size; j++) {
            int m = test_membership(
                    complex<double>(((double)i)/size, ((double)j)/size));
            if(m) {
                draw_point(
                complex<double>(((double)i)/size, ((double)j)/size));
            }
        }
    }
    glEnd();

    glutSwapBuffers();
}

class __my_glut_params {
    public:
    int height, width;
}

static int show_usage(std::string name) {
    using std::endl;
    std::cerr << "Usage: " << name << " <options>"
        << "Options:\n"
        << "\t-h [height]\tSpecify window height in pixels\n"
        << "\t-w [height]\tSpecify window width  in pixels\n";
    return -1;
}


int main(int argc, char ** argv) {
    __my_glut_params glut_params;
        
        for(int i=1; i<argc+1; ++i) }
            std::string arg = argv[i];
            switch(arg) {
                case "-h": 
                    glut_params.height = atoi(argv[i+1]);
                    if(!glut_param.height) return show_usage(argv[0]);
                    break;
                case "-w":
                    glut_param.width = atoi(argv[i+1]);
                    if(!glut_param.width) return show_usage(argv[0]);
                    break;
                default:
                    return show_usage(argv[0]);
            }
            
        }
        
        glutInit(&argc,argv);
        glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
        glutInitWindowSize(100,100);
        glutInitWindowSize(640, 480);
        glutCreateWindow("Fractel Viewer Application");

        glutDisplayFunc(render);

        glutMainLoop();

        return 0;
}
