/*
 * Adapted by 3tawi
 * Aurora: https://github.com/pixelmatix/aurora
 * Copyright (c) 2014 Jason Coon
 *
 * http://www.stefan-petrick.de/wordpress_beta
 * Copyright (c) 2014 Stefan Petrick
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef ClockPatterns_H
#define ClockPatterns_H

class ClockPatterns : public Playlist {
  private:
  const int CENTRE_X = 32;
  const int CENTRE_Y = 16;
  public:
    typedef void (ClockPatterns::*ClockPatternFunctionPointer)(void);
    ClockPatternFunctionPointer currentItem;
    static const int PATTERN_COUNT = 19;
    ClockPatternFunctionPointer shuffledItems[PATTERN_COUNT];
    ClockPatternFunctionPointer items[PATTERN_COUNT] = {
      &ClockPatterns::drawClock0,
      &ClockPatterns::drawClock1,
      &ClockPatterns::drawClock2,
      &ClockPatterns::drawClock3,
      &ClockPatterns::drawClock4,
      &ClockPatterns::drawClock5,
      &ClockPatterns::drawClock6,
      &ClockPatterns::drawClock7,
      &ClockPatterns::drawClock8,
      &ClockPatterns::drawClock9,
      &ClockPatterns::drawClock10,
      &ClockPatterns::drawClock11,
      &ClockPatterns::drawClock12,
      &ClockPatterns::drawClock13,
      &ClockPatterns::drawClock14,
      &ClockPatterns::drawClock15,
      &ClockPatterns::drawClock16,
      &ClockPatterns::drawClock17,
      &ClockPatterns::drawClock18
    };
    
    void drawClock0() {
      readtime();
      drawclock0();
      drawtime();
    }
    void drawClock1() {
      readtime();
      drawclock1();
      drawtime();
    }
    void drawClock2() {
      readtime();
      drawclock2();
      drawtime();
    }
    void drawClock3() {
      readtime();
      drawHMTime(17);
      drawMesg(textmsg, GPFont8x16, 8, 0);
    }
    void drawClock4() {
      readtime();
      drawHMTime(1);
      drawMesg(textmsg, GPFont8x16, 8, 16);
    }
    void drawClock5() {
      readtime();
      drawHMTime(18);
      drawMesg(textmsg, GPFont16x16, 16, 0);
    }
    void drawClock6() {
      readtime();
      drawHMTime(1);
      drawMesg(textmsg, GPFont16x16, 16, 16);
    }
    void drawClock7() {
      readtime();
      drawHMTime(18);
      drawMesg(textmsg, GPFont16x16B, 16, 0);
    }
    void drawClock8() {
      readtime();
      drawHMTime(1);
      drawMesg(textmsg, GPFont16x16B, 16, 16);
    }
    void drawClock9() {
      readtime();
      drawHMTime1(14, 10);
      drawMesg(textmsg, GPFont8x8, 8, 0);
    }
    void drawClock10() {
      readtime();
      drawHMTime1(3, 1);
      drawMesg(textmsg, GPFont8x8, 8, 23);
    }
    void drawClock11() {
      readtime();
      drawHMTime1(14, 11);
      drawMesg(textmsg, GPFont8x9, 8, 0);
    }
    void drawClock12() {
      readtime();
      drawHMTime1(3, 1);
      drawMesg(textmsg, GPFont8x9, 8, 22);
    }
    void drawClock13() {
      readtime();
      drawHMTime1(14, 12);
      drawMesg(textmsg, GPFont8x12, 8, 0);
    }
    void drawClock14() {
      readtime();
      drawHMTime1(0, 19);
      drawMesg(textmsg, GPFont8x12, 8, 20);
    }
    void drawClock15() {
      readtime();
      drawHMTime2(14);
      drawMesg(textmsg, GPFont16x16, 16, 0);
    }
    void drawClock16() {
      readtime();
      drawHMTime2(0);
      drawMesg(textmsg, GPFont16x16, 16, 16);
    }
    void drawClock17() {
      readtime();
      drawHMTime2(14);
      drawMesg(textmsg, GPFont16x16B, 16, 0);
    }
    void drawClock18() {
      readtime();
      drawHMTime2(0);
      drawMesg(textmsg, GPFont16x16B, 16, 16);
    }

    void readtime() {
      if(millis() - lastTim >= 1000) {
        co0 = random(0, 91);
        flasher = !flasher;
        lastTim = millis();
      }
      if (NewRTCm != rtc.getMinute()) {
        effects.redtemphumi();
        flashSe = !flashSe;
        co1 = random(0, 91);
        NewRTCm = rtc.getMinute();
      }
    }
    
void drawHMTime(int yy) {
     String text = Mode24h ? rtc.getTime("%H%M") : rtc.getTime("%I%M");
     effects.setFont(GPFont16x16); 
     effects.setCursor(0, yy);
     effects.print(text, co1);
     effects.setFont(GPFont8x8);
     effects.setCursor(28, yy+5);
     text = flasher ? ":" : "";
     effects.print(text, co0);
     int xx = rtc.getSecond();
     xx = flashSe ? xx+2 : 61-xx;
     effects.fillEllipse(xx, yy, 2, 1, MyColor[co1]);
     effects.fillCircle(xx, yy, 1, MyColor[co0]);
    }
    
void drawHMTime1(int yy, int yd) {
     String text = Mode24h ? rtc.getTime("%H%M") : rtc.getTime("%I%M");
     effects.setFont(GPFontNu16x18); 
     effects.setCursor(0, yy);
     effects.print(text, co1);
     effects.setFont(GPFont8x8);
     effects.setCursor(28, yy+6);
     text = flasher ? ":" : "";
     effects.print(text, co0);
     int xx = rtc.getSecond();
     xx = flashSe ? xx+2 : 61-xx;
     effects.fillEllipse(xx, yd, 2, 1, MyColor[co1]);
     effects.fillCircle(xx, yd, 1, MyColor[co0]);
    }
    
void drawHMTime2(int yy) {
     String text = Mode24h ? rtc.getTime("%H%M") : rtc.getTime("%I%M");
     effects.setFont(GPFontNu16x18); 
     effects.setCursor(0, yy);
     effects.print(text, co1);
     effects.setFont(GPFont8x8);
     effects.setCursor(28, yy+6);
     text = flasher ? ":" : "";
     effects.print(text, co0);
    }

void drawMesg(String text, uint8_t* font_gp, int len, int ym) {
  uint16_t text_length = text.length();
  effects.setFont(font_gp); 
  effects.setCursor(xps, ym);
  effects.print(text, co1);
  xps -= sp1;
  if (xps < -(text_length * len)) {
    effects.getmesg();
  }
}
    
void drawclock0() {
      float radians, angle;
      int x0;
      int y0;
      int x1[12] = {28, 39, 49, 56, 50, 40, 27, 15, 5, -2, 3, 16};
      int y1[12] = {0, 1, 4, 13, 23, 26, 27, 26, 23, 13, 4, 1};
      for (int i = 5; i < 65; i+=5) {
        uint16_t color = MyColor[(co0*i)%92];
        angle =  180 - i * 6;
        radians = radians(angle);
        x0 = CENTRE_X + 25.0F * sin(radians);
        y0 = CENTRE_Y + 9.0F * cos(radians);
        effects.fillCircle(x0, y0, 1, color);
     }
      effects.setFont(GPFont8x5);
      for (int i = 0; i < 12; i++) {
        effects.setCursor(x1[i],y1[i]);
        text = (char)(i+48);
        effects.print(text, co0*(i+1));
      }
}
    
void drawclock1() {
      float radians, angle;
      int x0;
      int y0;
      for (int i = 5; i < 65; i+=5) {
        uint16_t color = MyColor[(co0*i)%92];
        angle =  180 - i * 6;
        radians = radians(angle);
        x0 = CENTRE_X + 28.0F * sin(radians);
        y0 = CENTRE_Y + 14.0F * cos(radians);
        effects.fillCircle(x0, y0, 1, color);
     }
}
    
void drawclock2() {
      float radians, angle;
      int x0;
      int y0;
      int x1[12] = {28, 39, 49, 56, 50, 40, 27, 15, 5, -2, 3, 16};
      int y1[12] = {0, 1, 4, 13, 23, 26, 27, 26, 23, 13, 4, 1};
      effects.setFont(GPFont8x5);
      for (int i = 0; i < 12; i++) {
        effects.setCursor(x1[i],y1[i]);
        text = (char)(i+48);
        effects.print(text, co0*(i+1));
      }
}

void drawHMS(float angle, int x0, int y0, int c0, int c1, int z1) {
      int x[6];
      int y[6];
      float radians = radians(angle);
      x[0] = CENTRE_X + x0 * sin(radians);
      y[0] = CENTRE_Y + y0 * cos(radians);
      radians = radians(angle+z1);
      x[1] = CENTRE_X + 4 * sin(radians);
      y[1] = CENTRE_Y + 2 * cos(radians);
      radians = radians(angle-z1);
      x[2] = CENTRE_X + 4 * sin(radians);
      y[2] = CENTRE_Y + 2 * cos(radians);
      effects.fillTriangle(CENTRE_X, CENTRE_Y, x[0], y[0], x[1], y[1], MyColor[c0]);
      effects.fillTriangle(CENTRE_X, CENTRE_Y, x[0], y[0], x[2], y[2], MyColor[c0]);
      effects.drawLine(x[0], y[0], x[1], y[1], MyColor[c1]);
      effects.drawLine(x[0], y[0], x[2], y[2], MyColor[c1]);
}

    void drawtime() {
      uint8_t second = rtc.getSecond();
      uint8_t minute = rtc.getMinute();
      uint8_t hour = rtc.getHour();
      if (hour > 12) hour -= 12;
      float angle = 180 - (30 * hour) - (minute / 2);
      drawHMS(angle, 12, 8, 0, 0, 25);
      angle = 180 - (6 * minute);
      drawHMS(angle, 22, 11, 32, 34, 20);
      angle =  180 - (second * 6);
      drawHMS(angle, 28, 14, co0, co1, 15);
      effects.fillCircle(CENTRE_X,CENTRE_Y, 2, MyColor[co1]);
      effects.fillCircle(CENTRE_X,CENTRE_Y, 1, MyColor[co0]);
    }

    int currentIndex = 0;

    int getCurrentIndex() {
      return currentIndex;
    }

    ClockPatterns() {
      this->currentItem = items[currentIndex];

      // add the items to the shuffledItems array
      for (int a = 0; a < PATTERN_COUNT; a++) {
        shuffledItems[a] = items[a];
      }

      shuffleItems();
    }

    void moveRandom(int step) {
      currentIndex += step;

      if (currentIndex >= PATTERN_COUNT) currentIndex = 0;
      else if (currentIndex < 0) currentIndex = PATTERN_COUNT - 1;


      currentItem = shuffledItems[currentIndex];
    }

    void shuffleItems() {
      for (int a = 0; a < PATTERN_COUNT; a++)
      {
        int r = random(a, PATTERN_COUNT);
        ClockPatternFunctionPointer temp = shuffledItems[a];
        shuffledItems[a] = shuffledItems[r];
        shuffledItems[r] = temp;
      }
    }

    char* Drawable::name = (char *)"Clock Patterns";

    void move(int step) {
      moveTo(currentIndex + step);
    }

    void moveTo(int index) {
      currentIndex = index;

      if (currentIndex >= PATTERN_COUNT) currentIndex = 0;
      else if (currentIndex < 0) currentIndex = PATTERN_COUNT - 1;


      currentItem = items[currentIndex];
      Serial.println(currentIndex);
    }

    unsigned int drawFrame() {
      clear();
      (this->*currentItem)();
      show();
      return 0;
    }
    
    void listClockPatterns() {
      Serial.println(F("{"));
      Serial.print(F("  \"count\": "));
      Serial.print(PATTERN_COUNT);
      Serial.println(",");
      Serial.println(F("  \"results\": ["));

      for (int i = 0; i < PATTERN_COUNT; i++) {
        Serial.print(F("    \""));
        Serial.print(i);
        if (i == PATTERN_COUNT - 1)
          Serial.println(F("\""));
        else
          Serial.println(F("\","));
      }

      Serial.println("  ]");
      Serial.println("}");
    }

    bool setClockPattern(String name) {
      for (int i = 0; i < PATTERN_COUNT; i++) {
        if (name.toInt() == i) {
          moveTo(i);
          return true;
        }
      }

      return false;
    }

    bool setClockPattern(int index) {
      if (index >= PATTERN_COUNT || index < 0)
        return false;

      moveTo(index);

      return true;
    }
};

#endif
