/*
    Este ejemplo es usando GL_LINES, el cual ya tiene antialiasing
*/

#include <GL/glut.h>
#include <math.h>


float a = 0.01;  
float b = 0.0;   
float c = 0.0;   

// Función que traza una parábola
void drawParabola() {
    glBegin(GL_POINTS);  
    for (float x = -100; x <= 100; x += 0.01) {
        float y = a * x * x + b * x + c;  
        glVertex2f(x, y);  
    }
    glEnd();
}


void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100, 100, -100, 100, -1, 1);  
    glMatrixMode(GL_MODELVIEW);
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);  
    glLoadIdentity();

    drawParabola();  

    glFlush();  
}

void init() {
    glClearColor(1, 1, 1, 0);  
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Parabola in OpenGL");

    init();  

    glutDisplayFunc(display);  
    glutReshapeFunc(reshape);  

    glutMainLoop();  
    return 0;
}
