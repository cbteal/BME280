#include <stdio.h>
#include <stdlib.h>
#include <bcm2835.h>

//Test Comment

unsigned short TEMP_TRIM1;
short TEMP_TRIM2;
short TEMP_TRIM3;

unsigned short PRESSURE_TRIM1;
short PRESSURE_TRIM2;
short PRESSURE_TRIM3;
short PRESSURE_TRIM4;
short PRESSURE_TRIM6;
short PRESSURE_TRIM7;
short PRESSURE_TRIM8;
short PRESSURE_TRIM9;

unsigned char HUMIDITY_TRIM1;
short HUMIDITY_TRIM2;
unsigned char HUMIDITY_TRIM3;
short HUMIDITY_TRIM4;
short HUMIDITY_TRIM5;

void get_temp_trim_one();
void get_temp_trim_two();
 
int main(void){
	int init_ok, i2c_ok;
	char buf[]= {0xFA};
	init_ok = bcm2835_init();
	if (init_ok == 0){
		printf("bcm2835_init() failed\n");
		exit(EXIT_FAILURE);
	}
	bcm2835_i2c_setClockDivider(BCM2835_I2C_CLOCK_DIVIDER_2500);
	i2c_ok = bcm2835_i2c_begin();
	if (i2c_ok == 1){
		printf("i2c_begin successful\n");
	}
	//bcm2835_i2c_setSlaveAddress(0x76);
	//bcm2835_i2c_write_read_rs(buf,1,buf,3);
	//bcm2835_i2c_write(buf,1);
	//bcm2835_i2c_read(buf,3);
	//printf("User Reg1 = %x\n",buf[0]);
	//printf("User Reg2 = %x\n",buf[1]);
	//printf("User Reg3 = %x\n",buf[2]);
	
	get_temp_trim_one();
	printf("Temp_T_1 = %x\n", TEMP_TRIM1);
	
	get_temp_trim_two();
	printf("Temp_T_2 = %x\n", TEMP_TRIM2);
	
	char buf2[] = {0xE0,0xB6};
	bcm2835_i2c_write(buf2,2);
	bcm2835_i2c_end();
	
}
void get_temp_trim_one(void){
	char buf[] = {0x88};
	bcm2835_i2c_write_read_rs(buf,1,buf,2);
	TEMP_TRIM1 = (buf[1]<<8)|(buf[0]);	
	
}
void get_temp_trim_two(void){
	char buf[] = {0x8A};
	bcm2835_i2c_write_read_rs(buf,1,buf,2);
	TEMP_TRIM2 = (buf[1]<<8)|(buf[0]);
}
