#include"libOne.h"
#include"package.h"
void gmain() {
#if 0
    setNumFiles(5);
    setFilename(0, "unko.png");
    setFilename(1, "gorilla.png");
    setFilename(2, "playerGu.png");
    setFilename(3, "playerChoki.png");
    setFilename(4, "playerPa.png");
    createPackage("image.pak");
#endif
    window(1920, 1080, full);
    loadPackage("image.pak");
    int unkoImg = loadImageFromPak("unko.png");
    int gorillaImg = loadImageFromPak("gorilla.png");
    int playerGuImg = loadImageFromPak("playerGu.png");
    int playerChokiImg = loadImageFromPak("playerChoki.png");
    int playerPaImg = loadImageFromPak("playerPa.png");
    deletePackage();

    rectMode(CENTER);
    while (notQuit) {
        clear(5);
        image(unkoImg, width / 6, height / 2);
        image(playerGuImg, width / 3, height / 4);
        image(playerChokiImg, width / 3, height / 2);
        image(playerPaImg, width / 3, height / 4*3);
        image(gorillaImg, width / 4 * 3, height / 2);
    }
}