#ifndef LCD_H_
#define LCD_H_

void LCD_write(unsigned char dc, char c);
void LCD_writeChar(char c);
void LCD_writeString(const char *str);
void LCD_gotoXY(unsigned char x, unsigned char y);
void LCD_clear(void);
void LCD_init(void);
void pin_Setup(void);

#define LCD_WIDTH	84					// 84 Pixels width
#define LCD_HEIGHT	48					// 48 Pixels height

#endif /*PCD8544_H_*/
