#include <GL/glut.h>

float angleX = 0.0f; // Sudut rotasi di sumbu X
float angleY = 0.0f; // Sudut rotasi di sumbu Y

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Background hitam
    glEnable(GL_DEPTH_TEST); // Aktifkan depth test untuk 3D
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Mengatur posisi kamera untuk perspektif 3D
    gluLookAt(2.0, 3.0, 6.0,  // Posisi kamera di koordinat (x, y, z)
        0.0, 0.0, 0.0,  // Titik yang dilihat kamera (pusat lemari)
        0.0, 1.0, 0.0); // Arah vertikal (up vector)

    // Terapkan rotasi berdasarkan input keyboard
    glRotatef(angleX, 1.0f, 0.0f, 0.0f); // Rotasi di sumbu X
    glRotatef(angleY, 0.0f, 1.0f, 0.0f); // Rotasi di sumbu Y

    // 1. Warna badan lemari (abu-abu)
    glColor3f(0.7f, 0.7f, 0.7f); // Warna abu-abu

    // Bingkai luar lemari
    glPushMatrix();
    glScalef(1.0f, 2.0f, 0.5f); // Skala sesuai proporsi gambar
    glutSolidCube(2.0); // Bingkai dasar lemari
    glPopMatrix();

    // 2. Warna jendela/pintu kaca (putih)
    glColor3f(1.0f, 1.0f, 1.0f); // Warna putih untuk kaca

    // Membuat enam kaca, dua di atas, dua di tengah, dua di bawah
    // Kaca atas
    for (float j = -0.5f; j <= 0.5f; j += 1.0f) {
        glPushMatrix();
        glTranslatef(j, 0.7f, 0.501f); // Posisi kaca atas
        glScalef(0.9f, 0.6f, 0.02f); // Skala kaca
        glutSolidCube(1.0); // Kaca
        glPopMatrix();
    }

    // Kaca tengah
    for (float j = -0.5f; j <= 0.5f; j += 1.0f) {
        glPushMatrix();
        glTranslatef(j, 0.0f, 0.501f); // Posisi kaca tengah
        glScalef(0.9f, 0.6f, 0.02f); // Skala kaca
        glutSolidCube(1.0); // Kaca
        glPopMatrix();
    }

    // Kaca bawah
    for (float j = -0.5f; j <= 0.5f; j += 1.0f) {
        glPushMatrix();
        glTranslatef(j, -0.7f, 0.501f); // Posisi kaca bawah
        glScalef(0.9f, 0.6f, 0.02f); // Skala kaca
        glutSolidCube(1.0); // Kaca
        glPopMatrix();
    }

    // 3. Warna pegangan pintu (hitam)
    glColor3f(0.0f, 0.0f, 0.0f); // Warna hitam

    // Pegangan pintu pertama
    glPushMatrix();
    glTranslatef(-0.35f, 0.0f, 0.52f); // Posisi pegangan pintu pertama
    glScalef(0.05f, 0.2f, 0.05f); // Skala pegangan
    glutSolidCube(1.0); // Pegangan pintu pertama
    glPopMatrix();

    // Pegangan pintu kedua
    glPushMatrix();
    glTranslatef(0.35f, 0.0f, 0.52f); // Posisi pegangan pintu kedua
    glScalef(0.05f, 0.2f, 0.05f); // Skala pegangan
    glutSolidCube(1.0); // Pegangan pintu kedua
    glPopMatrix();

    // 4. Rak dalam lemari (tetap abu-abu)
    glColor3f(0.7f, 0.7f, 0.7f); // Warna abu-abu untuk rak
    for (float i = -0.7f; i <= 0.7f; i += 0.7f) {
        glPushMatrix();
        glTranslatef(0.0f, i, 0.0f); // Posisi setiap rak
        glScalef(0.9f, 0.05f, 0.4f); // Skala rak
        glutSolidCube(2.0); // Rak
        glPopMatrix();
    }

    glutSwapBuffers(); // Tukar buffer untuk menampilkan gambar
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Mengatur perspektif untuk viewport dengan sudut 3D
    gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 1.0, 10.0); // Field of view, aspect ratio, z-near, z-far
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(int key, int x, int y) {
    // Menangani input dari tombol panah
    switch (key) {
    case GLUT_KEY_UP:
        angleX -= 5.0f; // Rotasi ke atas
        break;
    case GLUT_KEY_DOWN:
        angleX += 5.0f; // Rotasi ke bawah
        break;
    case GLUT_KEY_LEFT:
        angleY -= 5.0f; // Rotasi ke kiri
        break;
    case GLUT_KEY_RIGHT:
        angleY += 5.0f; // Rotasi ke kanan
        break;
    }
    glutPostRedisplay(); // Meminta redisplay setelah rotasi
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Lemari Besi dengan 6 Kaca");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(keyboard); // Fungsi untuk menangani input keyboard khusus (tombol panah)
    glutMainLoop();
    return 0;
}