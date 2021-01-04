#include"libOne.h"
int createTriangle() {
    struct SHAPE_VERTEX vertices[3];
    vertices[0].x = 0;
    vertices[0].y = -1;
    vertices[1].x = 0.5;
    vertices[1].y = 1;
    vertices[2].x = -0.5;
    vertices[2].y = 1;
    return createShape(vertices, 3);
}
int createPolygon() {
    const int NUM = 5;
    struct SHAPE_VERTEX vertices[NUM];
    float deg = 360.0f / NUM;
    angleMode(DEGREES);
    for (int i = 0; i < NUM; i++) {
        vertices[i].x = sin(deg*i);
        vertices[i].y = -cos(deg*i);
    }
    return createShape(vertices, NUM);
}
void gmain() {
    window(1000, 1000);
    int triangleIdx = createTriangle();
    int polygonIdx = createPolygon();
    float deg = 0;
    angleMode(DEGREES);
    while (notQuit) {
        //deg += 1;
        clear(200);
        strokeWeight(5);
        fill(0, 255, 0);
        shape(triangleIdx, 250, 500, deg, 200);
        fill(0, 255, 255);
        shape(polygonIdx, 650, 500, deg, 200);
    }
}
