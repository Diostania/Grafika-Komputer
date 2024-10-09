#include <GL/glut.h>

float angleX = 0.0f; 
float angleY = 0.0f;

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); 
    glEnable(GL_DEPTH_TEST); 
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(2.0, 3.0, 6.0,  
        0.0, 0.0, 0.0,  
        0.0, 1.0, 0.0); 

    glRotatef(angleX, 1.0f, 0.0f, 0.0f); 
    glRotatef(angleY, 0.0f, 1.0f, 0.0f); 

    
    glColor3f(0.7f, 0.7f, 0.7f); 

    // Bingkai luar lemari
    glPushMatrix();
    glScalef(1.0f, 2.0f, 0.5f); 
    glutSolidCube(2.0); 
    glPopMatrix();


    glColor3f(1.0f, 1.0f, 1.0f); 

    // Kaca atas
    for (float j = -0.5f; j <= 0.5f; j += 1.0f) {
        glPushMatrix();
        glTranslatef(j, 0.7f, 0.501f); 
        glScalef(0.9f, 0.6f, 0.02f); 
        glutSolidCube(1.0); 
        glPopMatrix();
    }

    // Kaca tengah
    for (float j = -0.5f; j <= 0.5f; j += 1.0f) {
        glPushMatrix();
        glTranslatef(j, 0.0f, 0.501f); 
        glScalef(0.9f, 0.6f, 0.02f); 
        glutSolidCube(1.0); 
        glPopMatrix();
    }

    // Kaca bawah
    for (float j = -0.5f; j <= 0.5f; j += 1.0f) {
        glPushMatrix();
        glTranslatef(j, -0.7f, 0.501f); 
        glScalef(0.9f, 0.6f, 0.02f); 
        glutSolidCube(1.0); 
        glPopMatrix();
    }

    
    glColor3f(0.0f, 0.0f, 0.0f); 

    // Pegangan pintu pertama
    glPushMatrix();
    glTranslatef(-0.35f, 0.0f, 0.52f); 
    glScalef(0.05f, 0.2f, 0.05f); 
    glutSolidCube(1.0); 
    glPopMatrix();

    // Pegangan pintu kedua
    glPushMatrix();
    glTranslatef(0.35f, 0.0f, 0.52f); 
    glScalef(0.05f, 0.2f, 0.05f); 
    glutSolidCube(1.0); 
    glPopMatrix();

    // 4. Rak dalam lemari 
    glColor3f(0.7f, 0.7f, 0.7f); 
    for (float i = -0.7f; i <= 0.7f; i += 0.7f) {
        glPushMatrix();
        glTranslatef(0.0f, i, 0.0f); 
        glScalef(0.9f, 0.05f, 0.4f); 
        glutSolidCube(2.0); 
        glPopMatrix();
    }

    glutSwapBuffers(); 
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Mengatur perspektif untuk viewport dengan sudut 3D
    gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 1.0, 10.0); 
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_UP:
        angleX -= 5.0f; 
        break;
    case GLUT_KEY_DOWN:
        angleX += 5.0f; 
        break;
    case GLUT_KEY_LEFT:
        angleY -= 5.0f; 
        break;
    case GLUT_KEY_RIGHT:
        angleY += 5.0f; 
        break;
    }
    glutPostRedisplay(); 
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Lemari Besi dengan 6 Kaca");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(keyboard); 
    glutMainLoop();
    return 0;
}