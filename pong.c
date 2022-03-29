#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void field(int xBall, int yBall, int yRocket1, int yRocket2) {
    printf("\e[H\e[2J\e[3J");
    for (int y = 0; y < 25; y++) {
        for (int x = 0; x < 80; x++) {
            if (y == 0 || y == 24)
                printf("\u2581");
            else if (y == yBall && x == xBall)
                printf("\u25c9");
            else if (x == 0 || x == 41 || x == 79)
                printf("\u258e");
            else if (( yRocket1 - 1 <= y && yRocket1 + 1 >= y) && (x == 2 ))
                printf("\u2593");
            else if (( yRocket2 - 1 <= y && yRocket2 + 1 >= y) && (x == 76))
                printf("\u2593");
            else
                printf(" "); }
        printf("\n"); }}
int moveRocket(char key) {
    int result;
    if (key == 'a' || key == 'A')
        result = 1;
    if (key == 'z' || key == 'Z')
        result = 2;
    if (key == 'k' || key == 'K')
        result = 3;
    if (key == 'm' || key == 'M')
        result = 4;
    return result; }
int main() {
    int xBall = 40;
    int yBall = 13;
    int yRocket1 = 13;
    int yRocket2 = 13;
    char key;
    int score_p1 = 0, score_p2 = 0;
    int dir_x = 1, dir_y = 1;
    system("stty cbreak");
    while (1) {
        field(xBall, yBall, yRocket1, yRocket2);
        printf("SCORE: %d : %d\n\n", score_p1, score_p2);
        scanf("%c", &key);
        xBall += dir_x;
        yBall += dir_y;
        if (((xBall == 3) && ((yBall == yRocket1 - 1)
                || (yBall == yRocket1) || (yBall == yRocket1 + 1)))) {
            dir_x *= (-1); }
        if (((xBall == 75) && ((yBall == yRocket2 - 1)
                || (yBall == yRocket2) || (yBall == yRocket2 + 1)))) {
            dir_x *= (-1); }
        if ( yBall == 1 || yBall == 23 ) {
            dir_y *= (-1); }
        if (xBall == 0) {
            xBall = 40;
            yBall = 13;
            score_p2++; }
        if (xBall == 78) {
            xBall = 40;
            yBall = 13;
            score_p1++; }
        if (score_p1 == 21) {
            printf("Congratuations to player 1!\n");
            break; }
        if (score_p2 == 21) {
                printf("Congratuations to player 2!\n");
                break; }
        switch (moveRocket(key)) {
            case 1 :  if (yRocket1 >= 3) {
                   yRocket1--; break; }
            case 2 :  if (yRocket1 <= 21) {
                   yRocket1++; break; }
            case 3 :  if (yRocket2 >= 3) {
                yRocket2--; break; }
            case 4 :  if (yRocket2 <= 21) {
                yRocket2++; break; } }}
    return 0; }
