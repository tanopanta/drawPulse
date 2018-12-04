#include <M5Stack.h>

#include "drawPulse.h"



DrawPulse::DrawPulse() {
    ;
}

// 画面表示を初期化
void DrawPulse::init(int min, int max) {
    maxValue = max;
    minValue = min;
    
    
    lastMax = maxValue;
    lastMin = minValue;

    nowMax = minValue;
    nowMin = maxValue;
    
    tmpValue = minValue;

    xPos = 0;
    drawGrid();
}

// 縦軸の値を追加し線をつなぐ
void DrawPulse::addValue(int value) {
    if(value < nowMin) {
        nowMin = value;
    }
    if(nowMax < value) {
        nowMax = value;
    }

    if(xPos > 0) {
        int y = (int)(LCD_HEIGHT - (float)(value - lastMin) / (lastMax - lastMin) * LCD_HEIGHT);

        M5.Lcd.drawLine(xPos - 1, tmpValue, xPos, y, WHITE); //一個前の点と結ぶ

        tmpValue = y;
    }

    xPos++;

    //画面の端まで来ていたら画面初期化
    if (xPos > LCD_WIDTH) {
        xPos = 0;

        M5.Lcd.fillScreen(BLACK);
        drawGrid();

        lastMin = nowMin - 20;
        lastMax = nowMax + 20;

        nowMin = maxValue;
        nowMax = minValue;

    }
}


// 軸の描画
void DrawPulse::drawGrid() {
    for (int x = 0; x <= LCD_WIDTH; x += DOTS_DIV) { 
        M5.Lcd.drawLine(x, 0, x, LCD_HEIGHT, GREY); // Vertical Line
    }
    for (int y = 0; y <= LCD_HEIGHT; y += DOTS_DIV) { // Horizontal Line
        M5.Lcd.drawLine(0, y, LCD_WIDTH, y, GREY);
    }
}

// 画面左上に文字列を表示
void DrawPulse::showMsg(const String &s) {
    M5.Lcd.setCursor(0, 0);
    M5.Lcd.setTextSize(3);
    M5.Lcd.print(s);
}