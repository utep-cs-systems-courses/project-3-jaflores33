COMMON_OBJECTS  =
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include

CC              = msp430-elf-gcc
AS              = msp430-elf-as
AR              = msp430-elf-ar

all: button.elf

button.elf: ${COMMON_OBJECTS} p1_interrupt_handler.o led.o stateMachine.o switches.o buzzer.o buttonMain.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lLcd -lp2sw -lTimer 



load: button.elf
	msp430loader.sh button.elf

clean:
	rm -f *.a *.o *.elf *~
