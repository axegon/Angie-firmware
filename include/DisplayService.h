#pragma once

#include <Adafruit_GFX.h>

#include <Adafruit_SSD1306.h>

class DisplayService {
  private: 
    virtual void bootsplash() = 0;
  public: 
    virtual void Init(Adafruit_SSD1306 display) = 0;
    virtual void printText(const String & s) = 0;
    virtual void setCursor(int x, int y) = 0;
    virtual void clearDisplay() = 0;
    virtual void clearPrint(const String & s) = 0;
};

class DisplayImpl: public DisplayService {
  private: Adafruit_SSD1306 display;
  void bootsplash() override {
    const unsigned char epd_bitmap_bootsplash [] PROGMEM = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x7f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x01, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x07, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x1f, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x3f, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x3f, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x7f, 0xf8, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0xff, 0xf0, 0x3f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0xff, 0xe0, 0x1f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x01, 0xff, 0xc0, 0x0f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x01, 0xff, 0x80, 0x07, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x03, 0xff, 0x80, 0x07, 0xff, 0x80, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x03, 0xff, 0x00, 0x03, 0xff, 0x80, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x03, 0xfe, 0x00, 0x03, 0xff, 0xc0, 0x03, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x07, 0xfe, 0x00, 0x01, 0xff, 0xc0, 0x03, 0x9c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x07, 0xfe, 0x00, 0x01, 0xff, 0xc0, 0x07, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x07, 0xfe, 0x00, 0x01, 0xff, 0xc0, 0x06, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x07, 0xfc, 0x00, 0x01, 0xff, 0xe0, 0x0e, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x07, 0xfc, 0x00, 0x01, 0xff, 0xe0, 0x0e, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x07, 0xfc, 0x00, 0x01, 0xff, 0xe0, 0x0c, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x07, 0xfc, 0x00, 0x01, 0xff, 0xe0, 0x1c, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x07, 0xfe, 0x00, 0x01, 0xff, 0xe0, 0x1c, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x07, 0xfe, 0x00, 0x01, 0xff, 0xe0, 0x1c, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x07, 0xfe, 0x00, 0x01, 0xff, 0xe0, 0x18, 0x1c, 0xe0, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x07, 0xfe, 0x00, 0x01, 0xff, 0xe0, 0x38, 0x1f, 0xe0, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x07, 0xff, 0x00, 0x01, 0xff, 0xe0, 0x38, 0x3f, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x07, 0xff, 0x80, 0x07, 0xff, 0xe0, 0x30, 0xfc, 0x00, 0x00, 0x08, 0x1e, 0x00, 0x00, 0x00, 
        0x00, 0x07, 0xff, 0xe0, 0x1f, 0xff, 0xe0, 0x31, 0xf8, 0x00, 0x00, 0x00, 0x3f, 0x00, 0x00, 0x00, 
        0x00, 0x07, 0xff, 0xf8, 0x3f, 0xff, 0xe0, 0x7f, 0xf9, 0x30, 0x00, 0x00, 0x77, 0x00, 0x00, 0x00, 
        0x00, 0x07, 0xff, 0xf0, 0x3f, 0xff, 0xe0, 0x7e, 0x39, 0xf8, 0x07, 0x0c, 0x67, 0x00, 0x00, 0x00, 
        0x00, 0x03, 0xff, 0xf0, 0x1f, 0xff, 0xe0, 0xfc, 0x39, 0xfc, 0x1f, 0x8c, 0x7f, 0x00, 0x00, 0x00, 
        0x00, 0x03, 0xff, 0xf0, 0x7f, 0xff, 0xe3, 0xf0, 0x31, 0xdc, 0x3f, 0x9c, 0x7e, 0x60, 0x00, 0x00, 
        0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xef, 0xe0, 0x33, 0x9c, 0x79, 0xcc, 0x7f, 0xe0, 0x00, 0x00, 
        0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x60, 0x33, 0x9c, 0x61, 0xce, 0x3f, 0xc0, 0x00, 0x00, 
        0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x60, 0x33, 0x98, 0xe3, 0xce, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x60, 0x33, 0x18, 0xff, 0xce, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xe0, 0x33, 0x18, 0x7f, 0x8e, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xe0, 0x33, 0x00, 0x3d, 0x84, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xe0, 0x30, 0x00, 0x01, 0xc0, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xe0, 0x20, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xe0, 0x00, 0x00, 0x0f, 0xc0, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x60, 0x00, 0x00, 0x3f, 0xc0, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0xf8, 0xc0, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x03, 0xe0, 0xc0, 0x1f, 0xff, 0xff, 0x00, 
        0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x07, 0x81, 0xff, 0xff, 0xff, 0xff, 0xc0, 
        0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x1f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0x00, 
        0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 
        0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x3f, 0xff, 0xc1, 0xc0, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x01, 0xff, 0xf0, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x1f, 0xff, 0x80, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x7f, 0xff, 0xff, 0xfe, 0x00, 0x7f, 0xe7, 0x80, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x1f, 0xff, 0xff, 0xf8, 0x03, 0xfe, 0x03, 0xe0, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x07, 0xff, 0xff, 0xe0, 0x0f, 0xe0, 0x01, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x0f, 0x80, 0x00, 0x7f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x07, 0xe0, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    display.drawBitmap(0, 0, epd_bitmap_bootsplash, 128, 64, 1);
  }

  public: void Init(Adafruit_SSD1306 disp) override {
    display = disp;
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    clearDisplay();
    bootsplash();
    display.display();
    display.setTextSize(1);
    display.setTextColor(SSD1306_INVERSE);
    setCursor(0, 0);
  }

  /*
   * Stupidly enough, clearDisplay() doesn't actually clear the 
   * display, it only clears the buffer. So the dirty hack is
   * to clear the buffer and print a space. Yeah, dumb, I know.
   */
  void clearDisplay() override {
    display.clearDisplay();
    printText(" ");
  }

  void setCursor(int x, int y) override {
    display.setCursor(x, y);
  }

  void printText(const String & s) override {
    display.print(s);
    display.display();
  }

  void clearPrint(const String & s) override {
    clearDisplay();
    setCursor(0, 0);
    printText(s);
  }
};