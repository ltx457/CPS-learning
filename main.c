#include <xc.h>

#define FCY 12800000UL
#include <libpic30.h>

#include "lcd.h"
#include "led.h"

// Configuration bits
#pragma config FNOSC = PRIPLL
#pragma config POSCMD = XT
#pragma config FWDTEN = OFF

#define MAX_COUNT 31U

void show_names(void);
void show_counter(unsigned int counter);
void show_binary(unsigned int counter);

int main(void)
{
    unsigned int counter = 0;

    // Initialize LCD and LEDs
    lcd_initialize();
    led_init();

    // Display group members
    show_names();
    __delay_ms(4000);

    while (1)
    {
        // Display counter on LCD
        show_counter(counter);

        // Display counter on 5 LEDs
        show_binary(counter);

        // Delay for visible counting
        __delay_ms(1000);

        // Increment counter: 0 to 31
        counter++;

        if (counter > MAX_COUNT)
        {
            counter = 0;
        }
    }

    return 0;
}

// Display group members one by one
void show_names(void)
{
    lcd_clear();
    lcd_locate(0, 0);
    lcd_printf("Tianxiang Li");
    __delay_ms(2000);

    lcd_clear();
    lcd_locate(0, 0);
    lcd_printf("Shaunak Salvi");
    __delay_ms(2000);

    lcd_clear();
    lcd_locate(0, 0);
    lcd_printf("Khalil Zaier");
    __delay_ms(2000);
}

// Display current counter on LCD
void show_counter(unsigned int counter)
{
    lcd_clear();

    lcd_locate(0, 0);
    lcd_printf("Counter:");

    lcd_locate(0, 1);
    lcd_printf("%u", counter);
}

// Display binary counter on LEDs
void show_binary(unsigned int counter)
{
    led_display_binary(counter);
}