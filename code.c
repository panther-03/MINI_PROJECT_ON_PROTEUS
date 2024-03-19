#include<reg51.h> 
#define lcd_data_port P3 /* P1 port as data port */ 
sbit rs=P2^0; /* Register select pin */ 
sbit rw=P2^1; /* Read/Write pin */ 
sbit en=P2^2; /* Enable pin */ 
void delay(unsigned int count) /* Function to provide delay Approx 1ms */ 
{ 
int i,j; 
for(i=0;i<count;i++) 
for(j=0;j<112;j++); 
} 
void LCD_Command (unsigned char cmd) /* LCD16x2 command function */ { 
lcd_data_port = cmd; 
rs = 0; /* command reg. */ 
rw = 0; /* Write operation */ 
en = 1; 
delay(1); 
en = 0; 
delay(5); 
} 
void LCD_Char (unsigned char char_data) /* LCD data write function */ 
{ 
lcd_data_port = char_data; 
rs = 1; /* Data reg.*/ 
rw = 0; /* Write operation*/ 
en = 1; 
delay(1); 
en = 0; 
delay(5); 
} 
void LCD_String (unsigned char str) / Send string to LCD function */ { 
int i; 
for(i=0; str[i] != 0; i++) /* Send each char of string till the NULL */ 
{ 
LCD_Char (str[i]); /* Call LCD data write */ 
} 
} 
void LCD_Scroll() /* Function to scroll the LCD display */ 
{ 
LCD_Command(0x18); /* Command for shifting the entire display to the left 
*/ 
delay(300); /* Adjust delay for speed of scrolling */ 
} 
void LCD_Init (void) /* LCD Initialize function */ 
{ 
delay(20); /* LCD Power ON Initialization time >15ms */ LCD_Command (0x38); /* Initialization of 16X2 LCD in 8bit mode */ LCD_Command (0x0F); /* Display ON Cursor Blinking */ LCD_Command (0x06); /* Auto Increment cursor */ LCD_Command (0x01); /* clear display */ 
LCD_Command (0x80); /* cursor at home position */ 
} 
void main() 
{ 
LCD_Init(); /* initialization of LCD */ 
LCD_String("WELCOME TO JIIT"); /* write string on 2nd line */ while(1) /* Infinite loop for scrolling */ 
{ 
LCD_Scroll(); /* Call the scroll function */ 
} 
}
