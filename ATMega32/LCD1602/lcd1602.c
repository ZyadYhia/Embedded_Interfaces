/*
* lcd1602.c
*
* Created: 2/27/2022 2:22:20 AM
*  Author: User
*/

#ifndef RS
#define RS			 1
#endif

#ifndef RW
#define RW			 2
#endif

#ifndef EN
#define EN			 3
#endif

#ifndef lcd_data
#define lcd_data	 PORTA
#endif

#ifndef ctr
#define ctr			 PORTB
#endif

#ifndef ctr_dir
#define ctr_dir		 DDRB
#endif

#ifndef lcd_data_dir
#define lcd_data_dir DDRA
#endif
#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

void lcd_cmd(char cmd){
	ctr &= ~(1<<RS); // access command register
	lcd_data = cmd; // Send Command
	ctr |= (1<<EN); // Rising Edge
	_delay_ms(100);
	ctr &= ~(1<<EN); // Falling Edge
}

void lcd_init(){
	ctr &= ~(1<<RW); // Write Mode always
	ctr_dir |= ((1<<RS) | (1<<EN));
	lcd_data_dir = 0xFF;
	// 8Bits Mode
	lcd_cmd(0x38);
	// Clear
	lcd_cmd(0x01);
	// return home
	lcd_cmd(0x02);
	//automatic cursor
	lcd_cmd(0x06);
	// Display on and cursor blink
	lcd_cmd(0x0F);
}

void lcd_write(char data){
	ctr |= (1<<RS);
	lcd_data = data;
	ctr |= (1<<EN); // Rising Edge
	_delay_ms(10);
	ctr &= ~(1<<EN); // Falling Edge
}

void lcd_clear(){
	_delay_ms(1);
	lcd_cmd(0x01);
	// return home
	lcd_cmd(0x02);
	_delay_ms(1);
}

void lcd_write_str(char* str){
	for (int i = 0; str[i] != '\0'; i++)
	{
		lcd_write(str[i]);
	}
}

void lcd_goto_xy(int row, int col){
	// 0x8X -> first row
	// 0xCX -> second row
	if (row == 0 && col < 16)
	{
		lcd_cmd(0x80 | col);
	}
	else if(row == 1 && col < 16)
	{
		lcd_cmd(0xC0 | col);
		} else {
		lcd_goto_xy(0, 0);
		lcd_write_str("OUT OF DIMENSION");
	}
	
}

void lcd_write_num(unsigned int num){
	char strNumber[8];
	//redix is what determine what number system i'm using for itoa()
	//itoa() -> integer to array
	itoa(num, strNumber, 10);
	lcd_write_str(strNumber);
}

//---------------------------------------------------------

void lcd_cmd_4bits(char cmd){
	ctr &= ~(1<<RS); // access command register
	lcd_data &= 0x0F;
	lcd_data |= (0xF0 & cmd); // Send MSBs Command
	ctr |= (1<<EN); // Rising Edge
	_delay_ms(100);
	ctr &= ~(1<<EN); // Falling Edge
	lcd_data &= 0x0F;
	lcd_data |= (cmd<<4); // Send LSBs Command
	ctr |= (1<<EN); // Rising Edge
	_delay_ms(100);
	ctr &= ~(1<<EN); // Falling Edge
}

void lcd_init_4bits(){
	ctr &= ~(1<<RW); // Write Mode always
	ctr_dir |= ((1<<RS) | (1<<EN) | (1<<RW));
	lcd_data_dir |= 0xF0;
	// 4Bits Mode
	lcd_cmd(0x28);
	// Clear
	lcd_cmd_4bits(0x01);
	// return home
	lcd_cmd_4bits(0x02);
	//automatic cursor
	lcd_cmd_4bits(0x06);
	// Display on and cursor blink
	lcd_cmd_4bits(0x0F);
}

void lcd_write_4bits(char data){
	ctr |= (1<<RS);
	
	lcd_data &= 0x0F;
	lcd_data |= (0xF0 & data); // Send MSBs Command
	
	ctr |= (1<<EN); // Rising Edge
	_delay_ms(10);
	ctr &= ~(1<<EN); // Falling Edge
	
	lcd_data &= 0x0F;
	lcd_data |= (data<<4); // Send LSBs Command
	ctr |= (1<<EN); // Rising Edge
	_delay_ms(10);
	ctr &= ~(1<<EN); // Falling Edge
}

void lcd_clear_4bits(){
	_delay_ms(1);
	lcd_cmd_4bits(0x01);
	// return home
	lcd_cmd_4bits(0x02);
	_delay_ms(1);
}

void lcd_write_str_4bits(char* str){
	for (int i = 0; str[i] != '\0'; i++)
	{
		lcd_write_4bits(str[i]);
	}
}

void lcd_goto_xy_4bits(int row, int col){
	// 0x8X -> first row
	// 0xCX -> second row
	if (row == 0 && col < 16)
	{
		lcd_cmd_4bits(0x80 | col);
	}
	else if(row == 1 && col < 16)
	{
		lcd_cmd_4bits(0xC0 | col);
	} 
	else {
		lcd_goto_xy_4bits(0, 0);
		lcd_write_str_4bits("OUT OF DIMENSION");
	}
	
}

void lcd_write_num_4bits(unsigned int num){
	char strNumber[8];
	//redix is what determine what number system i'm using for itoa()
	//itoa() -> integer to array
	itoa(num, strNumber, 10);
	lcd_write_str_4bits(strNumber);
}
