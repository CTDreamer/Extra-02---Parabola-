/*
    Dibujando los diversos tipos de parábolas usando el algoritmo de punto medio
*/

#include <GL/glut.h>
#include <stdio.h>

int opcion;  

// Función para dibujar un punto en las simetrías adecuadas según la orientación
void drawSymmetricPoints(int x, int y, int orientation) {
    glBegin(GL_POINTS);
    if (orientation == 1) {         // Parábola hacia arriba
        glVertex2i(x, y);
        glVertex2i(-x, y);
    }
    else if (orientation == 2) {  // Parábola hacia abajo
        glVertex2i(x, -y);
        glVertex2i(-x, -y);
    }
    else if (orientation == 3) {  // Parábola hacia la derecha
        glVertex2i(y, x);
        glVertex2i(y, -x);
    }
    else if (orientation == 4) {  // Parábola hacia la izquierda
        glVertex2i(-y, x);
        glVertex2i(-y, -x);
    }
    glEnd();
}

// Función que implementa el algoritmo de punto medio para parábolas verticales
void midpointParabolaVerticalA(int a) {
    int x = 0;
    int y = 0;
    int p = 1 - a;  // Inicialización del parámetro de decisión

    while (x <= a) {
        drawSymmetricPoints(x, y, 1);  // Opción 1: vertical hacia arriba
        if (p < 0) {
            p = p + 2 * x + 1;
        }
        else {
            p = p + 2 * x - 2 * a + 1;
            y++;
        }
        x++;
    }
}
void midpointParabolaVerticalL(int a) {
    int x = 0;
    int y = 0;
    int p = 1 - a;  // Inicialización del parámetro de decisión

    while (x <= a) {
        drawSymmetricPoints(x, y, 2);  // Opción 1: vertical hacia arriba
        if (p < 0) {
            p = p + 2 * x + 1;
        }
        else {
            p = p + 2 * x - 2 * a + 1;
            y++;
        }
        x++;
    }
}

// Función que implementa el algoritmo de punto medio para parábolas horizontales
void midpointParabolaHorizontalD(int a) {
    int x = 0;
    int y = 0;
    int p = 1 - a;  // Inicialización del parámetro de decisión

    while (y <= a) {
        drawSymmetricPoints(y, x, 3);  // Opción 3: horizontal hacia la derecha
        if (p < 0) {
            p = p + 2 * y + 1;
        }
        else {
            p = p + 2 * y - 2 * a + 1;
            x++;
        }
        y++;
    }
}
void midpointParabolaHorizontalI(int a) {
    int x = 0;
    int y = 0;
    int p = 1 - a;  // Inicialización del parámetro de decisión

    while (y <= a) {
        drawSymmetricPoints(y, x, 4);  // Opción 3: horizontal hacia la derecha
        if (p < 0) {
            p = p + 2 * y + 1;
        }
        else {
            p = p + 2 * y - 2 * a + 1;
            x++;
        }
        y++;
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);  

    if (opcion == 1) {  // Vertical
        midpointParabolaVerticalA(50);  // Ejemplo de valor para 'a'
    }if (opcion == 2) {
        midpointParabolaVerticalL(50);
    }
    if (opcion == 3) {  // Horizontal
        midpointParabolaHorizontalD(50);  // Ejemplo de valor para 'a'
    }
    else if (opcion == 4) {
        midpointParabolaHorizontalI(50);  // Ejemplo de valor para 'a'
    }

    glFlush();  
}


void init() {
    glClearColor(1, 1, 1, 0);  
    glColor3f(0.0, 0.0, 1.0);  
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-150, 150, -100, 100); 
}

int main(int argc, char** argv) {
    printf("Selecciona la orientación de la parábola:\n");
    printf("1: Vertical hacia arriba\n");
    printf("2: Vertical hacia abajo\n");
    printf("3: Horizontal hacia la derecha\n");
    printf("4: Horizontal hacia la izquierda\n");
    scanf_s("%d", &opcion);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Parabola con Punto Medio");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
