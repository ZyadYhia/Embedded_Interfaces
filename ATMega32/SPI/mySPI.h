/*
 * mySPI.h
 *
 * Created: 3/21/2022 10:58:07 PM
 *  Author: User
 */ 


#ifndef MYSPI_H_
#define MYSPI_H_

#define SPI_MASTER 1
#define SPI_SLAVE  0

#define SPI_Pre_4   1
#define SPI_Pre_16  2
#define SPI_Pre_64  3
#define SPI_Pre_128 4
#define SPI_Pre_2   5
#define SPI_Pre_8   6
#define SPI_Pre_32  7

#define SS   4
#define SCK  7
#define MOSI 5
#define MISO 6

void SPI_init(int);
void SPI_MASTER_send(char);
char SPI_SLAVE_receive();
void SPI_MASTER_send_str(char*);
void SPI_MASTER_send_num(int);


#endif /* MYSPI_H_ */