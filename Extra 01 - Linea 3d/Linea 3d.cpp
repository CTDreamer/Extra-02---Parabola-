#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

int x1, y1_global, z1, x2, y2_global, z2;

void write_pixel(int x, int y, int z) {
    glBegin(GL_POINTS);
    glVertex3i(x, y, z);
    glEnd();
}

// Función para trazar una línea en 3D usando el algoritmo de punto medio (Bresenham)
void bresenhamLine3D(int x1, int y1, int z1, int x2, int y2, int z2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int dz = z2 - z1;

    int abs_dx = abs(dx);
    int abs_dy = abs(dy);
    int abs_dz = abs(dz);

    int x = x1, y = y1, z = z1;

    if (abs_dx >= abs_dy && abs_dx >= abs_dz) {
        int p1, p2;

        if (dx >= 0) {
            p1 = 2 * dy - dx;
            p2 = 2 * dz - dx;

            for (int i = 0; i <= abs_dx; i++) {
                write_pixel(x, y, z);
                if (p1 >= 0) {
                    y += (dy >= 0) ? 1 : -1;
                    p1 -= 2 * abs_dx;
                }
                if (p2 >= 0) {
                    z += (dz >= 0) ? 1 : -1;
                    p2 -= 2 * abs_dx;
                }
                p1 += 2 * abs_dy;
                p2 += 2 * abs_dz;
                x += (dx >= 0) ? 1 : -1;
            }
        }
        else {
            p1 = 2 * dy + dx;
            p2 = 2 * dz + dx;

            for (int i = 0; i <= abs_dx; i++) {
                write_pixel(x, y, z);
                if (p1 <= 0) {
                    y += (dy >= 0) ? 1 : -1;
                    p1 += 2 * abs_dx;
                }
                if (p2 <= 0) {
                    z += (dz >= 0) ? 1 : -1;
                    p2 += 2 * abs_dx;
                }
                p1 += 2 * abs_dy;
                p2 += 2 * abs_dz;
                x -= 1;
            }
        }
    }
    else if (abs_dy >= abs_dx && abs_dy >= abs_dz) {
        int p1, p2;

        if (dy >= 0) {
            p1 = 2 * dx - dy;
            p2 = 2 * dz - dy;

            for (int i = 0; i <= abs_dy; i++) {
                write_pixel(x, y, z);
                if (p1 >= 0) {
                    x += (dx >= 0) ? 1 : -1;
                    p1 -= 2 * abs_dy;
                }
                if (p2 >= 0) {
                    z += (dz >= 0) ? 1 : -1;
                    p2 -= 2 * abs_dy;
                }
                p1 += 2 * abs_dx;
                p2 += 2 * abs_dz;
                y += (dy >= 0) ? 1 : -1;
            }
        }
        else {
            p1 = 2 * dx + dy;
            p2 = 2 * dz + dy;

            for (int i = 0; i <= abs_dy; i++) {
                write_pixel(x, y, z);
                if (p1 <= 0) {
                    x += (dx >= 0) ? 1 : -1;
                    p1 += 2 * abs_dy;
                }
                if (p2 <= 0) {
                    z += (dz >= 0) ? 1 : -1;
                    p2 += 2 * abs_dy;
                }
                p1 += 2 * abs_dx;
                p2 += 2 * abs_dz;
                y -= 1;
            }
        }
    }
    else {
        int p1, p2;

        if (dz >= 0) {
            p1 = 2 * dy - dz;
            p2 = 2 * dx - dz;

            for (int i = 0; i <= abs_dz; i++) {
                write_pixel(x, y, z);
                if (p1 >= 0) {
                    y += (dy >= 0) ? 1 : -1;
                    p1 -= 2 * abs_dz;
                }
                if (p2 >= 0) {
                    x += (dx >= 0) ? 1 : -1;
                    p2 -= 2 * abs_dz;
                }
                p1 += 2 * abs_dy;
                p2 += 2 * abs_dx;
                z += (dz >= 0) ? 1 : -1;
            }
        }
        else {
            p1 = 2 * dy + dz;
            p2 = 2 * dx + dz;

            for (int i = 0; i <= abs_dz; i++) {
                write_pixel(x, y, z);
                if (p1 <= 0) {
                    y += (dy >= 0) ? 1 : -1;
                    p1 += 2 * abs_dz;
                }
                if (p2 <= 0) {
                    x += (dx >= 0) ? 1 : -1;
                    p2 += 2 * abs_dz;
                }
                p1 += 2 * abs_dy;
                p2 += 2 * abs_dx;
                z -= 1;
            }
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);

    bresenhamLine3D(x1, y1_global, z1, x2, y2_global, z2);

    glFlush();
}

void init() {
    glClearColor(1, 1, 1, 0); 
        glColor3f(1.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 1000.0);
    glTranslatef(0.0, 0.0, -500.0);
}

int main(int argc, char** argv) {
    printf("Ingresar coordenadas de la línea (x1, y1, z1, x2, y2, z2): \n");
    scanf_s("%d %d %d %d %d %d", &x1, &y1_global, &z1, &x2, &y2_global, &z2);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Línea 3D con Punto Medio");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}