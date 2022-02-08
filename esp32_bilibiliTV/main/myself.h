#ifndef _MYSELF_H
#define _MYSELF_H
//#include "C:\Users\hujingxuan\Desktop\vscode\esp_lvgl2\132121\components\lvgl\src\font\lv_font_Common_Chinese.c"

enum str_type{
	str_city=0,
	str_adcode,
	str_province,
	str_reporttime,
	str_date,
	str_week,
	str_dayweather,
	str_nightweather,
	str_daytemp,
	str_nighttemp,
	str_daywind,
	str_nightwind,
	str_daypower,
	str_nightpower,
};
typedef struct
{
    char *date;
    char *week;
    char *dayweather;
    char *nightweather;
    char *daytemp;
    char *nighttemp;
    char *daywind;
    char *nightwind;
    char *daypower;
    char *nightpower;
}day_data;
typedef struct{
	char *city;
	char *adcode;
	char *province;
	char *reporttime;
	day_data day[4];
}province_city;
typedef struct{
	char once_press;
	char second_press;
	char third_press;
	char long_press;
}my_key_state;

typedef struct{
	char* high_temp;
	char* low_temp;
	char* weather;
}LVGL_state_default;

typedef struct{
	const void * img;
	const char * weather;
}weather_img;




#endif
