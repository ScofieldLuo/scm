/*********************************************************************
這個 lib 在 Adafruit_SSD1306 的基礎上實現 OLCD 文本輸出自動滾屏功能
*********************************************************************/

#include "Adafruit_SSD1306_text.h"


void Adafruit_SSD1306_text::_init(){
  display.begin(SSD1306_SWITCHCAPVCC);
  display.setTextSize(1);       // text size
  display.setTextColor(WHITE); // text color
  display.setTextWrap(false); // turn off text wrapping so we can do scrolling
  display.clearDisplay();
  display.setTextWrap(false);
}

//向LCD輸出字符串(自動換行)
void Adafruit_SSD1306_text::_scm(String s){
    int lines = _getlines(s);
    int newlines = curlines + lines;
    
    //將新增內容添加到數組 screen[]
    int i = 0;
    while (i < lines){
        screen[curlines + i] = _getlinestr(s, i + 1);
        i++;
    }
    
    //如果累計行標示 > 8 (0-8可以正常顯示), 則刷新數組 screen
    if (newlines > 8){
        i = 0;
        while(i < 8){
            screen[i] = screen[i + newlines - 8];
            i++;
        }
        curlines = 8;
    } else{
        curlines = newlines;
    }
    display.clearDisplay();
    
    //重新顯示 screen [0 - 7]
    i = 0;
    while(i < curlines){
        display.setCursor(0, i * 8);
        display.println(screen[i]);
        i++;
    }
    display.display();
}

//返回字符串行數 (按字體1計算, 每行顯示21個字符)
void Adafruit_SSD1306_text::_getlines(){
    int j = s.length();
    int i = int(j / 21);
    if (i * 21 == j) 
        return i;
    else
        return i + 1;
}

//返回第幾行的字符串
void Adafruit_SSD1306_text::_getlinestr(){
    int i = 1;
    int len = s.length();
    if(_getlines(s) < line) return "_getlinestr()_error_";
    if(len > 21 * line)
        return s.substring((line - 1) * 21, (line - 1) * 21 + 21);
    else
        return s.substring((line - 1) * 21);
}
}
