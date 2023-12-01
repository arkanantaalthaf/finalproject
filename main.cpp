#include <GL/glut.h>

// RUANG INTEROGASI

// KURSI

// Struktur untuk merepresentasikan voxel
struct Voxel {
    float x, y, z;
    float size;
};

void drawVoxel(const Voxel& voxel) {
    glBegin(GL_QUADS);
    glVertex3f(voxel.x - voxel.size / 2, voxel.y - voxel.size / 2, voxel.z + voxel.size / 2);
    glVertex3f(voxel.x + voxel.size / 2, voxel.y - voxel.size / 2, voxel.z + voxel.size / 2);
    glVertex3f(voxel.x + voxel.size / 2, voxel.y + voxel.size / 2, voxel.z + voxel.size / 2);
    glVertex3f(voxel.x - voxel.size / 2, voxel.y + voxel.size / 2, voxel.z + voxel.size / 2);

    glVertex3f(voxel.x - voxel.size / 2, voxel.y - voxel.size / 2, voxel.z - voxel.size / 2);
    glVertex3f(voxel.x + voxel.size / 2, voxel.y - voxel.size / 2, voxel.z - voxel.size / 2);
    glVertex3f(voxel.x + voxel.size / 2, voxel.y + voxel.size / 2, voxel.z - voxel.size / 2);
    glVertex3f(voxel.x - voxel.size / 2, voxel.y + voxel.size / 2, voxel.z - voxel.size / 2);
    glEnd();
}

void drawChair() {
    // Backrest
    Voxel backrest = { 0.0f, 0.5f, 0.0f, 0.2f };
    drawVoxel(backrest);

    // Seat
    Voxel seat = { 0.0f, 0.2f, 0.0f, 0.3f };
    drawVoxel(seat);

    // Legs
    Voxel leg1 = { -0.2f, 0.0f, -0.2f, 0.1f };
    Voxel leg2 = { 0.2f, 0.0f, -0.2f, 0.1f };
    Voxel leg3 = { -0.2f, 0.0f, 0.2f, 0.1f };
    Voxel leg4 = { 0.2f, 0.0f, 0.2f, 0.1f };

    drawVoxel(leg1);
    drawVoxel(leg2);
    drawVoxel(leg3);
    drawVoxel(leg4);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(1.0, 1.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glColor3f(0.5, 0.5, 0.9);
    drawChair();

    glutSwapBuffers();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(45.0, 1.0, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Voxel-Like Rendering - Simple Chair");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

// ------------------------------------------------------------------------------------------

// MEJA

const int gridSize = 16; // Ukuran grid
const float voxelSize = 0.1; // Ukuran voxel

void drawVoxel(float x, float y, float z) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glutSolidCube(voxelSize);
    glPopMatrix();
}

void drawTable() {
    glColor3f(0.5, 0.35, 0.05); // Warna kayu

    // Gambar meja menggunakan voxel
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j) {
            for (int k = 0; k < gridSize; ++k) {
                if (i == 0 || i == gridSize - 1 || j == 0 || j == gridSize - 1 || k == 0 || k == gridSize - 1) {
                    float x = i * voxelSize - 0.5;
                    float y = j * voxelSize - 0.5;
                    float z = k * voxelSize - 0.5;
                    drawVoxel(x, y, z);
                }
            }
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(1.0, 1.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    drawTable();

    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)width / (double)height, 1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Meja 3D dengan Voxel Rendering");
    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}

// ------------------------------------------------------------------------------------------

// PINTU BESERTA GAGANGNYA

const int gridSize = 16;     // Ukuran grid
const float voxelSize = 0.1; // Ukuran voxel

void drawVoxel(float x, float y, float z) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glutSolidCube(voxelSize);
    glPopMatrix();
}

void drawDoor() {
    glColor3f(0.5, 0.2, 0.0); // Warna kayu pintu

    // Gambar pintu menggunakan voxel
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j) {
            for (int k = 0; k < gridSize; ++k) {
                if (i == 0 || i == gridSize - 1 || j == 0 || j == gridSize - 1 || k == 0 || k == gridSize - 1) {
                    float x = i * voxelSize - 0.5;
                    float y = j * voxelSize - 0.5;
                    float z = k * voxelSize - 0.5;
                    drawVoxel(x, y, z);
                }
            }
        }
    }

    // Gambar gagang pintu
    glColor3f(0.8, 0.8, 0.8); // Warna gagang pintu
    float handleSize = voxelSize * 2.0;
    drawVoxel(0.0, 0.0, gridSize * voxelSize - handleSize);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(1.0, 1.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    drawDoor();

    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)width / (double)height, 1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Pintu 3D dengan Voxel Rendering");
    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}

// ------------------------------------------------------------------------------------------

// MEJA KECIL

void drawSmallTable() {
    glColor3f(0.5, 0.35, 0.05); // Warna kayu

    // Gambar meja kecil menggunakan voxel
    float tableSize = 0.4;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                float x = i * voxelSize - 1.0;
                float y = j * voxelSize - 0.5;
                float z = k * voxelSize - 0.5;
                drawVoxel(x, y, z);
            }
        }
    }
}

// LAMPU

void drawCeilingLamp() {
    glColor3f(0.8, 0.8, 0.8); // Warna lampu langit-langit

    // Gambar lampu langit-langit menggunakan voxel
    float lampSize = 0.3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                float x = i * voxelSize - 0.5;
                float y = k * voxelSize + 1.0;
                float z = j * voxelSize - 0.5;
                drawVoxel(x, y, z);
            }
        }
    }
}

// DINDING

void drawInterrogationRoom() {
    // Gambar dinding ruang interogasi menggunakan voxel
    glColor3f(0.8, 0.8, 0.8); // Warna dinding

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 5; ++j) {
            for (int k = 0; k < 10; ++k) {
                if (i == 0 || i == 9 || j == 0 || j == 4 || k == 0 || k == 9) {
                    float x = i * voxelSize - 4.5;
                    float y = j * voxelSize - 2.0;
                    float z = k * voxelSize - 4.5;
                    drawVoxel(x, y, z);
                }
            }
        }
    }

    // Tambahan objek di ruang interogasi
    drawSmallTable();
    drawCeilingLamp();
}

void displayInterrogationRoom() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(1.0, 3.0, 4.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    drawInterrogationRoom();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Ruang Interogasi 3D dengan Voxel Rendering");
    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(displayInterrogationRoom);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}
