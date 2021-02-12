#include"libOne.h"
#include"package.h"
#include"sound.h"
struct UNKO {
    float px = 0, py = 0, vx = 0, vy = 0, deg;
    int hp = 0;
};
void loadImages(int* img, int num, const char* filename, int startIdx=0,const char* extname="png") {
    char str[64];
    for (int i = startIdx; i < num; i++) {
        sprintf_s(str, "%s%d.%s", filename, i, extname);
        img[i] = loadImage(str);
    }
}
void gmain() {
     
#if 1
    createPackage("assets","package");
#endif
    window(1920, 1080, full);
    
    loadPackage("package");

    const int numImages=8;
    int img[numImages];
    loadImages(img, numImages, "assets\\a");

    int unkoImg         = loadImage("assets\\unkoWhite.png");
    int gorillaImg      = loadImage("assets\\gorilla.png");
    int playerGuImg     = loadImage("assets\\Janken\\playerGu.png");
    int playerChokiImg  = loadImage("assets\\Janken\\playerChoki.png");
    int playerPaImg     = loadImage("assets\\Janken\\playerPa.png");
    int bgmSnd          = loadSound("assets\\sounds\\bgm_battle02.wav");
    int onaraSnd        = loadSound("assets\\sounds\\sitDown.wav");
    deletePackage();

    playLoopSound(bgmSnd);
    rectMode(CENTER);
    angleMode(DEGREES);
    const int numUnkos = 256;
    UNKO u[numUnkos];
    float deg = 0;
    int triggerCnt = 0;
    int interval = 1;

    float px = width / 2;
    float py = height -450;
    int animCnt = 0;
    int animInterval = 10;
    while (notQuit) {
        if (isTrigger(MOUSE_LBUTTON)) {
            playSound(onaraSnd);
        }
        if (isPress(MOUSE_LBUTTON)) {
            if (++triggerCnt % interval == 0) {
                for (int i = 0; i < numUnkos; i++) {
                    if (u[i].hp == 0) {
                        u[i].px = mouseX + sin(deg) * 10;
                        u[i].py = -50;
                        u[i].deg = 0;// deg;
                        u[i].vx = 0;//sin(deg) * 5;
                        u[i].vy = 10;// -cos(deg) * 5;
                        u[i].hp = 1;
                        deg += 6;
                        break;
                    }
                }
            }
        }
        if (isPress(MOUSE_RBUTTON)) {
            if (++triggerCnt % interval == 0) {
                for (int i = 0; i < numUnkos; i++) {
                    if (u[i].hp == 0) {
                        u[i].px = mouseX;
                        u[i].py = mouseY;
                        u[i].deg = deg;
                        u[i].vx = sin(deg) * 5;
                        u[i].vy = -cos(deg) * 5;
                        u[i].hp = 1;
                        deg += 6;
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < numUnkos; i++) {
            if (u[i].hp) {
                u[i].px += u[i].vx;
                u[i].py += u[i].vy;
                if (u[i].px < -50 ||
                    u[i].px > width + 50 ||
                    u[i].py < -50 ||
                    u[i].py > height + 50
                    ) {
                    u[i].hp = 0;
                }
            }
        }
        clear(100,100,100);
        //fill(0,128, 0);
        //rect(width / 2, height / 2 + 200, width, height);
        //image(playerGu.Img, width / 3, height / 4);
        //image(playerChokiImg, width / 3, height / 2);
        //image(playerPaImg, width / 3, height / 4 * 3);
        imageColor(143, 105, 68);
        imageColor(255, 125, 240);
        
        for (int i = 0; i < numUnkos; i++) {
            if (u[i].hp) {
                image(unkoImg, u[i].px, u[i].py,u[i].deg);
            }
        }
        imageColor(255);

        if (isPress(MOUSE_RBUTTON)) {
            fill(143, 105, 68);
            noStroke();
            circle(mouseX, mouseY, 110);
        }
        if (isTrigger(KEY_D)) {
            animCnt++;
            animCnt %= 8;
        }
        if (isTrigger(KEY_A)) {
            animCnt--;
            if (animCnt < 0)animCnt = 7;
        }
        //image(img[animCnt], px, py);
        if (isTrigger(KEY_S)) {
            animInterval++;
        }
        if (isTrigger(KEY_W)) {
            if (animInterval > 1) {
                animInterval--;
            }
        }
        int animIdx = ++animCnt / animInterval % numImages;
        if (animCnt >= animInterval * numImages+1) {
            animCnt = 0;
        }
        image(img[animIdx], px, py);
        textSize(300);
        text(animIdx, width/2, 300);
    }
}