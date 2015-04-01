#define MAX_VALUE 10
#define TRUE 1
#define FALSE 0
#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

char numberB[MAX_VALUE]={0, 1, 3, 7, 15, 31, 63, 127, 255, 255};
char numberD[MAX_VALUE]={1, 1, 1, 1,  1,  1,   1,  1,   1,   3};

void setup(){
	DDRB=255;
	DDRD=3;
}

void fill_heart(){
	for(char i = 0; i < MAX_VALUE; i++){
		PORTB=numberB[i];
		PORTD=numberD[i];
		_delay_ms(200);
	}
}

void clean(){
	PORTB=0;
	PORTD=0;
}

void blink(char longBlink){
	clean();
	_delay_ms(0);
	
	PORTB=255;
	PORTD=3;
	(longBlink == TRUE) ? _delay_ms(700) : _delay_ms(400);
	
	clean();
	_delay_ms(200);
}

int main(void) {
	setup();
	while(1){
		fill_heart();
		clean();
		_delay_ms(200);
		blink(TRUE);
		blink(FALSE);
		blink(FALSE);
	}
	return 0;
}