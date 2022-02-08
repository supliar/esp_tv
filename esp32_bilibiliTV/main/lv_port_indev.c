/**
 * @file lv_port_indev_templ.c
 *
 */

 /*Copy this file as "lv_port_indev.c" and set this value to "1" to enable content*/
#if 1

/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include "lv_port_indev.h"
#include "C:\Users\hujingxuan\Desktop\vscode\esp_lvgl2\132121\components\lvgl\lvgl.h"




static void keypad_init(void);
static void keypad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);
static uint32_t keypad_get_key(void);






lv_indev_t * indev_keypad;

void lv_port_indev_init(void)
{
    static lv_indev_drv_t indev_drv;
    keypad_init();
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_KEYPAD;
    indev_drv.read_cb = keypad_read;
    indev_keypad = lv_indev_drv_register(&indev_drv);
}

/*------------------
 * Keypad
 * -----------------*/

/*Initialize your keypad*/
static void keypad_init(void)
{
    /*Your code comes here*/
}

/*Will be called by the library to read the mouse*/
static void keypad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    static uint32_t last_key = 0;

    /*Get the current x and y coordinates*/
 //   mouse_get_xy(&data->point.x, &data->point.y);

    /*Get whether the a key is pressed and save the pressed key*/
    uint32_t act_key = keypad_get_key();
    if(act_key != 0) {
        data->state = LV_INDEV_STATE_PR;

        /*Translate the keys to LVGL control characters according to your key definitions*/
        switch(act_key) {
        case 1:
            act_key = LV_KEY_NEXT;
          //  printf("get key.once_press!!!!!!!!!!!!!!\n");
            break;
        case 2:
            act_key = LV_KEY_PREV;
            break;
        case 3:
            act_key = LV_KEY_ESC;
            break;
        case 4:
            act_key = LV_KEY_ENTER;
          //  printf("LV_KEY_ENTER!!!!!!!!!!!!!!\n");
            break;
        }

        last_key = act_key;
    } else {
        data->state = LV_INDEV_STATE_REL;
    }
    data->key = last_key;
}

/*Get the currently being pressed key.  0 if no key is pressed*/
static uint32_t keypad_get_key(void)
{
    /*Your code comes here*/
	uint8_t key_value = 0;
    if(key.once_press==1)
    {
        key.once_press=0;
      //  printf("key.once_press!!!!!!!!!!!!!!\n");
        key_value = 1;
    }
    else if(key.second_press==1)
    {
    	key.second_press=0;
    	key_value = 2;
    }

    else if(key.third_press==1)
    {
    	key.third_press=0;
    	key_value = 3;
    }

    else if(key.long_press==1)
    {
    	key.long_press=0;
    	key_value = 4;
    }
    else
    	key_value = 0;
    return key_value;
}
#else /*Enable this file at the top*/

/*This dummy typedef exists purely to silence -Wpedantic.*/
typedef int keep_pedantic_happy;
#endif
