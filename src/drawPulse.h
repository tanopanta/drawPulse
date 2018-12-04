#ifndef DRAW_PULSE_H
#define DRAW_PULSE_H

const int LCD_WIDTH = 320;
const int LCD_HEIGHT = 240;
const int DOTS_DIV = 30;
#define GREY 0x7BEF

class DrawPulse {
public:
    DrawPulse();
    void init(int min = 0, int max = 4096);
    void addValue(int value);
    void showMsg(const String &);
protected:
    void drawGrid();
private:
    int maxValue;
    int minValue;
    
    int xPos; //横軸の現在位置
    
    //次の画面の基準値
    int nowMin;
    int nowMax;

    //描画中の画面の基準値
    int lastMin; 
    int lastMax;

    int tmpValue;
};

#endif // DRAW_PULSE_H