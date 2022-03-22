/*
* lcd1602.h
*
* Created: 2/27/2022 2:01:00 AM
*  Author: User
*/


#ifndef LCD1602_H_
#define LCD1602_H_


void lcd_init();
void lcd_clear();
void lcd_cmd(char);
void lcd_write(char);
void lcd_write_str(char*);
void lcd_write_num(unsigned int);
void lcd_goto_xy(int, int);

void lcd_init_4bits();
void lcd_clear_4bits();
void lcd_cmd_4bits(char);
void lcd_write_4bits(char);
void lcd_write_str_4bits(char*);
void lcd_write_num_4bits(unsigned int);
void lcd_goto_xy_4bits(int, int);


#endif /* LCD1602_H_ */