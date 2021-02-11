#include"libOne.h"
#include"package.h"
void gmain() {

#if 1
    //createPackage("assets","package");
#endif
    window(1920, 1080, full);
    loadPackage("package");
    int unkoImg = loadImage("assets\\unko.png");
    int gorillaImg = loadImage("assets\\gorilla.png");
    int playerGuImg = loadImage("assets\\Janken\\playerGu.png");
    int playerChokiImg = loadImage("assets\\Janken\\playerChoki.png");
    int playerPaImg = loadImage("assets\\Janken\\playerPa.png");
    deletePackage();

    rectMode(CENTER);
    float gPx = width/2;
    float gPy = 540;
    float gRad = 0;
    float gVx = 1;
    float uPx = gPx;
    float uPy = gPy+120;
    float uVy = 10;
    while (notQuit) {
        gPx = width/2+sin(gRad)*300;
        gRad += 0.05;
        uPy += uVy;
        if (uPy > height + 50) {
            uPx = gPx;
            uPy = gPy + 120;
        }
        clear(5);
        fill(60, 120, 240);
        rect(width / 2, height / 2, width, height);
        fill(0,128, 0);
        rect(width / 2, height / 2 + 200, width, height);
        //image(playerGuImg, width / 3, height / 4);
        //image(playerChokiImg, width / 3, height / 2);
        //image(playerPaImg, width / 3, height / 4 * 3);
        image(unkoImg, uPx, uPy);
        image(gorillaImg, gPx, gPy);
    }
}