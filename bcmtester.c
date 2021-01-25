#include <stdio.h>
#include <stdlib.h>
#include <bcm2835.h>

//Test Comment

static unsigned short temp_trim1;
static short temp_trim2, temp_trim2;

static unsigned short pressure_trim1;
static short pressure_trim2, pressure_trim2, pressure_trim3, pressure_trim4;
static short pressure_trim5, pressure_trim6, pressure_trim7, pressure_trim8, pressure_trim9;

static unsigned char humidity_trim1, humidity_trim3;
static short humidity_trim2, humiditiy_trim4, humidity_trim5;

void get_temp_trim_one();
void get_temp_trim_two();
void get_temp_trim_three();

void get_pressure_trim_one();
void get_pressure_trim_two();
void get_pressure_trim_three();
void get_pressure_trim_four();
void get_pressure_trim_five();
void get_pressure_trim_six();
void get_pressure_trim_seven();
void get_pressure_trim_eight();
void get_pressure_trim_nine();
 
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
	printf("Temp_T_1 = %x\n", temp_trim1);
	
	get_temp_trim_two();
	printf("Temp_T_2 = %x\n", temp_trim2);
	
	char buf2[] = {0xE0,0xB6};
	bcm2835_i2c_write(buf2,2);
	bcm2835_i2c_end();
	
}
void get_temp_trim_one(void){
	char buf[] = {0x88};
	bcm2835_i2c_write_read_rs(buf,1,buf,2);
	temp_trim1 = (buf[1]<<8)|(buf[0]);		
}
void get_temp_trim_two(void){
	char buf[] = {0x8A};
	bcm2835_i2c_write_read_rs(buf,1,buf,2);
	temp_trim2 = (buf[1]<<8)|(buf[0]);
}
void get_temp_trim_three(void){
	char buf[] = {0x8C};
	bcm2835_i2c_write_read_rs(buf,1,buf,2);
	temp_trim3 = (buf[1]<<8)|(buf[0]);
}
void get_pressure_trim_one(void){
	char buf[] = {0x8E};
	bcm2835_i2c_write_read_rs(buf,1,buf,2);
	pressure_trim1 = (buf[1]<<8)|(buf[0]);
}
void get_pressure_trim_two(void){
	char buf[] = {0x90};
	bcm2835_i2c_write_read_rs(buf,1,buf,2);
	pressure_trim2 = (buf[1]<<8)|(buf[0]);
}
void get_pressure_trim_three(void){
	char buf[] = {0x92};
	bcm2835_i2c_write_read_rs(buf,1,buf,2);
	pressure_trim3 = (buf[1]<<8)|(buf[0]);
}
void get_pressure_trim_four(void){
	char buf[] = {0x94};
	bcm2835_i2c_write_read_rs(buf,1,buf,2);
	pressure_trim4 = (buf[1]<<8)|(buf[0]);
}
void get_pressure_trim_five(void){
	char buf[] = {0x96};
	bcm2835_i2c_write_read_rs(buf,1,buf,2);
	pressure_trim5 = {buf[1]<<8)|(buf[0]);
}
