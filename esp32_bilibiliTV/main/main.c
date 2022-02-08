#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "freertos/queue.h"
#include "freertos/event_groups.h"
#include "driver/gpio.h"
#include "esp_system.h"
#include "esp_log.h"
#include "C:\\Users\\hujingxuan\\Desktop\\esp-idf-2\\components\\newlib\\platform_include\\time.h"
#include "lvgl_helpers.h"
#include "esp_freertos_hooks.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "nvs_flash.h"
#include "C:\\Users\\hujingxuan\\Desktop\\esp-idf-2\\examples\\common_components\\protocol_examples_common\\include\\protocol_examples_common.h"
#include "lwip/err.h"
#include "lwip/sockets.h"
#include "lwip/sys.h"
#include "lwip/netdb.h"
#include "lwip/dns.h"
#include "esp_spi_flash.h"
#include "esp_err.h"
#include "cJson.h"
#include "myself.h"
#include "lv_port_indev.h"
#include "lvgl/lvgl.h"
#include "bp.c"
#include "lv_font_Common_18.c"
TaskHandle_t key_queue_test=NULL;
TaskHandle_t wifi_task_handle=NULL;
TaskHandle_t http_get_task_handle;
static int s_retry_num = 0;//wifi重新连接计数
static int wifi_connect_flag = 0;//用于WiFi连接状态判断。

static xQueueHandle http_update = NULL;
char http_queue=1;


extern lv_indev_t * indev_keypad;
//LV_USE_PERF_MONITOR

province_city my_hometown;
my_key_state key={
		.once_press=0,
		.second_press=0,
		.third_press=0,
		.long_press=0
        };
typedef struct{
	unsigned char Hour;
	unsigned char minute;
	unsigned char second;
	unsigned int Year;
	unsigned char Month;
	unsigned char Day;
}mclock;
mclock myClock={0,0,0,0,0,0};

unsigned char http_quest_count=0;//用于内存分配计数

void wifi_init_sta();



#define WEB_SERVER "restapi.amap.com"
#define WEB_PORT "80"
#define WEB_PATH "/v3/weather/weatherInfo?city=610703&key=f87019f08b1e81bf565b5be797882411&extensions=all"

static const char *TAG = "example";

static const char *REQUEST = "GET " WEB_PATH " HTTP/1.0\r\n"
    "Host: "WEB_SERVER":"WEB_PORT"\r\n"
    "User-Agent: esp-idf/1.0 esp32\r\n"
    "\r\n";


static int my_casts_size;
void delete_char(char * str, char *ch)//删除josn处理之后的无用字符
{
    if(str == NULL)
    	 return ;
    char *temp=str;
    while(*temp !='\0')
    {
            if(*temp!=*ch)
            {
            	*(str++)=*(temp++);
            	// ESP_LOGI("delete_char","%s",ch);
            }
            else
            temp++;
    }
   *str='\0';//do not miss it
}
void ClockGet(char * str)
{
	if(str == NULL)
	     return ;
	char *temp=str;
	char *ch=":";
	//(char *)heap_caps_malloc(2*sizeof(char),MALLOC_CAP_8BIT);
	char* hour=(char *)heap_caps_malloc(3*sizeof(char),MALLOC_CAP_8BIT);
	char* minute=(char *)heap_caps_malloc(3*sizeof(char),MALLOC_CAP_8BIT);
	char* second=(char *)heap_caps_malloc(3*sizeof(char),MALLOC_CAP_8BIT);
    char* year=(char *)heap_caps_malloc(5*sizeof(char),MALLOC_CAP_8BIT);
	char* month=(char *)heap_caps_malloc(3*sizeof(char),MALLOC_CAP_8BIT);
	char* day=(char *)heap_caps_malloc(3*sizeof(char),MALLOC_CAP_8BIT);

	*year=*(str);
	*(year+1)=*(str+1);
	*(year+2)=*(str+2);
	*(year+3)=*(str+3);
	*(year+4)='\0';

	*month=*(str+6);
	*(month+1)=*(str+7);
	*(month+2)='\0';

	*day=*(str+9);
	*(day+1)=*(str+10);
	*(day+2)='\0';
	char cont_=0;
	while(*temp !='\0')//取时分秒也可以像取年月日那样取，这里换一种方法单纯为了学习
	{
	 //  ESP_LOGI("ClockGet","%p     %s",temp,temp);
	   if(*temp==*ch)
	   {
		   cont_++;
		   if(cont_==1)
		   {
			   * hour=*(temp-2);//取出时
		       *(hour+1)=*(temp-1);
		       *(hour+2)='\0';
		   }
		   if(cont_==2)
		   {
		   	 * minute=*(temp-2);//取出分
		   	 *(minute+1)=*(temp-1);
		   	 *(minute+2)='\0';

		   	* second=*(temp+1);//取出秒
		   	*(second+1)=*(temp+2);
		    *(second+2)='\0';
		   }
	   }
	   temp++;
	}
	//printf("h=%s,m=%s,s=%s",hour,minute,second);
	printf("y=%s,m=%s,d=%s",year,month,day);


	myClock.Hour=(char)atoi(hour);//注atoi在<stdlib.h>中用于ascii转换数据例如"123"转成123
	myClock.minute=(char)atoi(minute);
	myClock.second=(char)atoi(second);
	myClock.Year=atoi(year);
	myClock.Month=(char)atoi(month);
	myClock.Day=(char)atoi(day);
}
void delete_GetData()//调用delete_char对数据进行处理,并得到时间数据
{
	delete_char(my_hometown.adcode,"\"");
	delete_char(my_hometown.city,"\"");
	delete_char(my_hometown.province,"\"");
	delete_char(my_hometown.reporttime,"\"");
	for(int i=0;i<my_casts_size;i++)
	{
		delete_char(my_hometown.day[i].date,"\"");
		delete_char(my_hometown.day[i].daypower,"\"");
		delete_char(my_hometown.day[i].daytemp,"\"");
		delete_char(my_hometown.day[i].dayweather,"\"");
		delete_char(my_hometown.day[i].daywind,"\"");
		delete_char(my_hometown.day[i].nightpower,"\"");
		delete_char(my_hometown.day[i].nighttemp,"\"");
		delete_char(my_hometown.day[i].nightweather,"\"");
		delete_char(my_hometown.day[i].nightwind,"\"");
		delete_char(my_hometown.day[i].week,"\"");
	}
	ClockGet(my_hometown.reporttime);
}


//传前几个参数的时候i的值可以0-3随意。最好是0
static void my_malloc(char *item,province_city *str,int typ,int i)
{
	if(http_quest_count==0)
	{
		//ESP_LOGI("http_quest_count", "第0次进入，开始分配%d,%d内存...",typ,i);
		switch(typ){
		case str_city:str->city=(char *)heap_caps_malloc(strlen(item)*sizeof(char),MALLOC_CAP_8BIT);break;
		case str_adcode:str->adcode=(char *)heap_caps_malloc(strlen(item)*sizeof(char),MALLOC_CAP_8BIT);break;
		case str_province:str->province=(char *)heap_caps_malloc(strlen(item)*sizeof(char),MALLOC_CAP_8BIT);break;
		case str_reporttime:str->reporttime=(char *)heap_caps_malloc(strlen(item)*sizeof(char),MALLOC_CAP_8BIT);break;

	    case str_date:str->day[i].date=(char *)heap_caps_malloc(strlen(item)*sizeof(char),MALLOC_CAP_8BIT);break;
	    case str_week:str->day[i].week=(char *)heap_caps_malloc(strlen(item)*sizeof(char),MALLOC_CAP_8BIT);break;
	    case str_dayweather:str->day[i].dayweather=(char *)heap_caps_malloc(strlen(item)*sizeof(char),MALLOC_CAP_8BIT);break;
	    case str_nightweather:str->day[i].nightweather=(char *)heap_caps_malloc(strlen(item)*sizeof(char),MALLOC_CAP_8BIT);break;
	    case str_daytemp:str->day[i].daytemp=(char *)heap_caps_malloc(strlen(item)*sizeof(char),MALLOC_CAP_8BIT);break;
	    case str_nighttemp:str->day[i].nighttemp=(char *)heap_caps_malloc(strlen(item)*sizeof(char),MALLOC_CAP_8BIT);break;
	    case str_daywind:str->day[i].daywind=(char *)heap_caps_malloc(strlen(item)*sizeof(char),MALLOC_CAP_8BIT);break;
	    case str_nightwind:str->day[i].nightwind=(char *)heap_caps_malloc(strlen(item)*sizeof(char),MALLOC_CAP_8BIT);break;
	    case str_daypower:str->day[i].daypower=(char *)heap_caps_malloc(strlen(item)*sizeof(char),MALLOC_CAP_8BIT);break;
	    case str_nightpower:str->day[i].nightpower=(char *)heap_caps_malloc(strlen(item)*sizeof(char),MALLOC_CAP_8BIT);break;
		}
	}
	else
	{
		ESP_LOGI("http_quest_count", "第%d次进入，跳过内存分配",http_quest_count);
		if(http_quest_count>=10)
			http_quest_count=10;
	}

    switch(typ){
    case str_city:str->city=item;break;
    case str_adcode:str->adcode=item;break;
    case str_province:str->province=item;break;
    case str_reporttime:str->reporttime=item;break;

    case str_date:str->day[i].date=item;break;
    case str_week:str->day[i].week=item;break;
    case str_dayweather:str->day[i].dayweather=item;break;
    case str_nightweather:str->day[i].nightweather=item;break;
    case str_daytemp:str->day[i].daytemp=item;break;
    case str_nighttemp:str->day[i].nighttemp=item;break;
    case str_daywind:str->day[i].daywind=item;break;
    case str_nightwind:str->day[i].nightwind=item;break;
    case str_daypower:str->day[i].daypower=item;break;
    case str_nightpower:str->day[i].nightpower=item;break;

    default:printf("error\n");break;
    }
}


static void http_get_task(void *pvParameters)
{
	ESP_LOGI("http_task", "http Start......");


	http_update = xQueueCreate(2, sizeof(uint32_t));

    const struct addrinfo hints = {
        .ai_family = AF_INET,
        .ai_socktype = SOCK_STREAM,
    };
    struct addrinfo *res;
    struct in_addr *addr;
    int s, r;
    char recv_buf[64];
    char my_date[975];
    while(1) {
        int err = getaddrinfo(WEB_SERVER, WEB_PORT, &hints, &res);

        if(err != 0 || res == NULL) {
            ESP_LOGE(TAG, "DNS lookup failed err=%d res=%p", err, res);
            vTaskDelay(1000 / portTICK_PERIOD_MS);
            continue;
        }

        /* Code to print the resolved IP.

           Note: inet_ntoa is non-reentrant, look at ipaddr_ntoa_r for "real" code */
        addr = &((struct sockaddr_in *)res->ai_addr)->sin_addr;
        ESP_LOGI(TAG, "DNS lookup succeeded. IP=%s", inet_ntoa(*addr));

        s = socket(res->ai_family, res->ai_socktype, 0);
        if(s < 0) {
            ESP_LOGE(TAG, "... Failed to allocate socket.");
            freeaddrinfo(res);
            vTaskDelay(1000 / portTICK_PERIOD_MS);
            continue;
        }
        ESP_LOGI(TAG, "... allocated socket");

        if(connect(s, res->ai_addr, res->ai_addrlen) != 0) {
            ESP_LOGE(TAG, "... socket connect failed errno=%d", errno);
            close(s);
            freeaddrinfo(res);
            vTaskDelay(4000 / portTICK_PERIOD_MS);
            continue;
        }

        ESP_LOGI(TAG, "... connected");
        freeaddrinfo(res);

        if (write(s, REQUEST, strlen(REQUEST)) < 0) {
            ESP_LOGE(TAG, "... socket send failed");
            close(s);
            vTaskDelay(4000 / portTICK_PERIOD_MS);
            continue;
        }
        ESP_LOGI(TAG, "... socket send success");

        struct timeval receiving_timeout;
        receiving_timeout.tv_sec = 5;
        receiving_timeout.tv_usec = 0;
        if (setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, &receiving_timeout,
                sizeof(receiving_timeout)) < 0) {
            ESP_LOGE(TAG, "... failed to set socket receiving timeout");
            close(s);
            vTaskDelay(4000 / portTICK_PERIOD_MS);
            continue;
        }

        /* Read HTTP response */
        bzero(my_date, sizeof(my_date));//截取有用部分的数据，去除包头
        int my_munber = 0;
        do {
            bzero(recv_buf, sizeof(recv_buf));
            r = read(s, recv_buf, sizeof(recv_buf)-1);
            for(int i = 0; i < r; i++) {
                if((i+my_munber* (sizeof(recv_buf)-1))>(537-1))
                {
                   my_date[i+my_munber* (sizeof(recv_buf)-1)-537]=recv_buf[i];
                }
                // putchar(recv_buf[i]);
            }
            my_munber++;
        } while(r > 0);
            printf("\n");
            ESP_LOGI(TAG, "------------------------------------------------");
            printf("josn解析....");
            printf("\n");
            ESP_LOGI(TAG, "------------------------------------------------");
            cJSON * root = NULL;
            cJSON * item = NULL;//cjson对象
            cJSON * forecasts = NULL;
            cJSON * daily = NULL;
            cJSON * daily_value = NULL;
            root = cJSON_Parse(my_date);
            if (!root)
            {
                printf("Error before: [%s]\n",cJSON_GetErrorPtr());
            }
            else
            {
      //   printf("%s\n", "原始Json数据:");
      //  printf("%s\n\n", cJSON_PrintUnformatted(root));
        ESP_LOGI(TAG, "-------------------------------------------------------------------------------------------");
        item = cJSON_GetObjectItem(root, "status");//
      //  printf("status = %s\n", cJSON_Print(item));

        item = cJSON_GetObjectItem(root, "info");
      //  printf("info = %s\n", cJSON_Print(item));

        item = cJSON_GetObjectItem(root, "forecasts");
        // printf("forecasts = %s\n", cJSON_Print(item));

        // int my_forecasts_size = cJSON_GetArraySize(item);
        // printf("my_forecasts_size= %d\n", my_forecasts_size);


        forecasts = cJSON_GetArrayItem(item,0);
        // printf("forecasts = %s\n", cJSON_Print(forecasts));

        item = cJSON_GetObjectItem(forecasts, "city");
       // printf("city = %s\n", cJSON_Print(item));
        my_malloc(cJSON_Print(item),&my_hometown,str_city,0);
//        lv_label_set_text_fmt(label3,"%s",my_hometown.city);//城市
        /*(注:这里cJSON_Print函数原本的传入参数和my_hometown.city类型正好相同，都是一个地址。
         * )
         */
        item = cJSON_GetObjectItem(forecasts, "adcode");
     //   printf("adcode = %s\n", cJSON_Print(item));
        my_malloc(cJSON_Print(item),&my_hometown,str_adcode,0);
//        lv_label_set_text_fmt(label2,"%s",my_hometown.adcode);//adcode

        item = cJSON_GetObjectItem(forecasts, "province");
      //  printf("province = %s\n", cJSON_Print(item));
        my_malloc(cJSON_Print(item),&my_hometown,str_province,0);
//        lv_label_set_text_fmt(label2,"%s",my_hometown.province);//省份


        item = cJSON_GetObjectItem(forecasts, "reporttime");
     //   printf("reporttime = %s\n", cJSON_Print(item));
        my_malloc(cJSON_Print(item),&my_hometown,str_reporttime,0);
//        lv_label_set_text_fmt(label4,"%s",my_hometown.reporttime);//时间


        item =  cJSON_GetObjectItem(forecasts, "casts");
        my_casts_size = cJSON_GetArraySize(item);
        for(int i=0;i<my_casts_size;i++)
        {
          daily = cJSON_GetArrayItem(item,i);//取出第i个元素
      //    printf("_________________________________________________________________________\n");
          daily_value = cJSON_GetObjectItem(daily, "date");
        //  printf("date（日期） = %s\n", cJSON_Print(daily_value));
          my_malloc(cJSON_Print(daily_value),&my_hometown,str_date,i);
//          if(i==0)
//          lv_label_set_text_fmt(label5,"今日是%s",my_hometown.day[0].date);//今日日期

          daily_value = cJSON_GetObjectItem(daily, "week");
       //   printf("week（星期） = %s\n", cJSON_Print(daily_value));
          my_malloc(cJSON_Print(daily_value),&my_hometown,str_week,i);
//          if(i==0)
//          lv_label_set_text_fmt(label6,"星期%s",cJSON_Print(daily_value));//星期

          daily_value = cJSON_GetObjectItem(daily, "dayweather");
       //   printf("dayweather（日间天气） = %s\n", cJSON_Print(daily_value));
          my_malloc(cJSON_Print(daily_value),&my_hometown,str_dayweather,i);
//          if(i==0)
//          lv_label_set_text_fmt(label7,"日间天气:%s",cJSON_Print(daily_value));//日间天气

          daily_value = cJSON_GetObjectItem(daily, "nightweather");
      //    printf("nightweather（晚间天气） = %s\n", cJSON_Print(daily_value));
          my_malloc(cJSON_Print(daily_value),&my_hometown,str_nightweather,i);
          //lv_label_set_text_fmt(label8,"晚间天气:%s",cJSON_Print(item));//晚间天气

          daily_value = cJSON_GetObjectItem(daily, "daytemp");
      //    printf("daytemp（白天温度） = %s\n", cJSON_Print(daily_value));
          my_malloc(cJSON_Print(daily_value),&my_hometown,str_daytemp,i);
     //     lv_label_set_text_fmt(label9,"白天温度:%s℃",cJSON_Print(item));//白天温度

          daily_value = cJSON_GetObjectItem(daily, "nighttemp");
      //    printf("nighttemp（晚间温度） = %s\n", cJSON_Print(daily_value));
          my_malloc(cJSON_Print(daily_value),&my_hometown,str_nighttemp,i);

          daily_value = cJSON_GetObjectItem(daily, "daywind");
       //   printf("daywind（白天风向） = %s\n", cJSON_Print(daily_value));
          my_malloc(cJSON_Print(daily_value),&my_hometown,str_daywind,i);

          daily_value = cJSON_GetObjectItem(daily, "nightwind");
      //    printf("nightwind（晚间风向） = %s\n", cJSON_Print(daily_value));
          my_malloc(cJSON_Print(daily_value),&my_hometown,str_nightwind,i);

          daily_value = cJSON_GetObjectItem(daily, "daypower");
    //      printf("daypower（白天风级） = %s\n", cJSON_Print(daily_value));
          my_malloc(cJSON_Print(daily_value),&my_hometown,str_daypower,i);

          daily_value = cJSON_GetObjectItem(daily, "nightpower");
    //      printf("nightpower（晚间风级） = %s\n", cJSON_Print(daily_value));
          my_malloc(cJSON_Print(daily_value),&my_hometown,str_nightpower,i);
  //        printf("_________________________________________________________________________\n");
        }
        delete_GetData();
        http_quest_count++;
        ESP_LOGI(TAG, "... done reading from socket. Last read return=%d errno=%d.", r, errno);
        close(s);
        char re_queue;
        xQueueReceive(http_update, &re_queue,portMAX_DELAY);
        ESP_LOGI(TAG, "Starting again!");
      }
   }
}


////----------------------------------lvgl--------------------------------
static void lv_tick_task(void)
{
  // (void)arg;
   lv_tick_inc(portTICK_PERIOD_MS);
}
char txt[]="wifi connecting...";
LVGL_state_default lvgl_weather_today={
		.high_temp="0",
		.low_temp="-5",
		.weather="晴"
};
LV_FONT_DECLARE(lv_font_Common_Chinese);//中文字体声明
LV_FONT_DECLARE(lv_font_Common_18);

LV_IMG_DECLARE(bg);                      //导入必要元素
LV_IMG_DECLARE(Temperature_scale);

LV_IMG_DECLARE(img_Sunny);
LV_IMG_DECLARE(heavy_rain);
LV_IMG_DECLARE(cloudy);
LV_IMG_DECLARE(heavy_snow);
LV_IMG_DECLARE(shade);
LV_IMG_DECLARE(light_rain);
LV_IMG_DECLARE(light_snow);
LV_IMG_DECLARE(donotknow);
LV_IMG_DECLARE(esc);

LV_IMG_DECLARE(m1_aimg);
LV_IMG_DECLARE(m2_aimg);
LV_IMG_DECLARE(m3_aimg);
LV_IMG_DECLARE(m4_aimg);
LV_IMG_DECLARE(m5_aimg);
LV_IMG_DECLARE(m6_aimg);
LV_IMG_DECLARE(m7_aimg);
LV_IMG_DECLARE(m8_aimg);
LV_IMG_DECLARE(m9_aimg);
LV_IMG_DECLARE(m10_aimg);
LV_IMG_DECLARE(m11_aimg);
LV_IMG_DECLARE(m12_aimg);
LV_IMG_DECLARE(m13_aimg);
LV_IMG_DECLARE(m14_aimg);//空白
weather_img img_sch[]={
		{&img_Sunny,"晴"},
		{&heavy_rain,"大雨"},
		{&heavy_snow,"大雪"},
		{&cloudy,"多云"},
		{&shade,"阴"},
		{&light_rain,"小雨"},
		{&light_snow,"小雪"}

};
const void * img_matching(weather_img* str,const char * name)
{
	const void * IMG_Pointer=NULL;
	char chak_flag=0;
	//ESP_LOGI("img_matching", "sizeof=%d",sizeof(img_sch)/sizeof(*str));

    int max=sizeof(img_sch)/sizeof(*str);
	for(int i=0;i<max;i++)
	{
		if(strcmp(str[i].weather,name)==0)
		{

			//ESP_LOGI("img_matching", "common in!!%d",i);
			chak_flag=1;
			IMG_Pointer=str[i].img;
		}
	}
	if(!chak_flag)
		IMG_Pointer=&donotknow;
	chak_flag=0;
    return IMG_Pointer;
}
lv_obj_t* sgr;                    //屏幕
lv_obj_t* desktop;
/*------------------img-----------------*/
lv_obj_t * Temperature_picture;   //℃
lv_obj_t * background;            //背景图片

lv_obj_t * aimg;//动图

lv_obj_t * mImg_today;
lv_obj_t * mImg_tomorrow;
lv_obj_t * mImg_after_tomorrow;

lv_obj_t * mImg_ESC;

/*------------------lable-----------------*/
lv_obj_t * lable_Temperature;
lv_obj_t * lable_City;
lv_obj_t * lable_Time;
lv_obj_t * lable_Clock;

lv_obj_t * lable_today;
lv_obj_t * lable_tomorrow;
lv_obj_t * lable_after_tomorrow;
lv_obj_t * lable_today_temp;
lv_obj_t * lable_tomorrow_temp;
lv_obj_t * lable_after_tomorrow_temp;

lv_obj_t * wifihttp_connect;
lv_obj_t * wifi_connect_cont;
/*------------------butten-----------------*/
lv_obj_t * btn_today;
lv_obj_t * btn_tomorrow;
lv_obj_t * btn_after_tomorrow;
lv_obj_t * btn_esc;
/*------------------style-----------------*/
lv_style_t style_lable;   //样式
lv_style_t style_btn;
/*------------------timer-----------------*/
lv_timer_t * timer;
lv_timer_t * timer_a;
void style_init()
{





}
unsigned char Conter =0;//用于计算更新时间的进入次数
void ClockUpdate(uint32_t periodTime)
{
	if(http_quest_count){
	Conter++;
	int s;
	if(periodTime<1000)
		s=1000/periodTime;
	else
		s=-1;
	if(s==Conter)//时钟部分
	{
		 Conter = 0;
		 myClock.second++;
		 if(myClock.second>60)
		 {
			 myClock.minute++;
			 myClock.second=0;
		 }
		 if(myClock.minute>60)
		 {
			 myClock.minute=0;
			 myClock.Hour++;
		 }
		 if(myClock.Hour>24)
		 {
			 myClock.second=0;
			 myClock.minute=0;
			 myClock.Hour=0;
		 }
		lv_label_set_text_fmt(lable_Clock, "#ffffff %d:%d:%d#",myClock.Hour,myClock.minute,myClock.second);
	}
	else if(s==-1)
		lv_label_set_text_fmt(lable_Clock, "#ffffff time period error#");
	}
}


static unsigned char http_quest_count_last=0;


void WeatherUpdate()
{
	if(http_quest_count!=http_quest_count_last)//发生了weather更新
	{

		printf("here is WeatherUpdate\n");



		lv_img_set_src(mImg_today,img_matching(img_sch,my_hometown.day[0].dayweather) );
		lv_img_set_src(mImg_tomorrow,img_matching(img_sch,my_hometown.day[1].dayweather));
		lv_img_set_src(mImg_after_tomorrow, img_matching(img_sch,my_hometown.day[2].dayweather));

		lv_label_set_text_fmt(lable_today_temp, "#ffffff %s℃/%s℃#",my_hometown.day[0].nighttemp,my_hometown.day[0].daytemp);
		lv_label_set_text_fmt(lable_tomorrow_temp, "#ffffff %s℃/%s℃#",my_hometown.day[1].nighttemp,my_hometown.day[1].daytemp);
		lv_label_set_text_fmt(lable_after_tomorrow_temp, "#ffffff %s℃/%s℃#",my_hometown.day[2].nighttemp,my_hometown.day[2].daytemp);

		lv_label_set_text_fmt(lable_Temperature, "#ffffff %s#",my_hometown.day[0].daytemp);//温度文本
		lv_label_set_text_fmt(lable_Time, "#ffffff %d年%d月%d日#",myClock.Year,myClock.Month,myClock.Day);//文本日期
		lv_label_set_text_fmt(lable_City, "#ffffff %s  %s#",my_hometown.province,my_hometown.city);//城市文本
//		for(int i=0;i<my_casts_size;i++)
//		{
//			printf("%s\n",my_hometown.day[i].date);
//			printf("%s\n",my_hometown.day[i].daypower);
//			printf("%s\n",my_hometown.day[i].daytemp);
//			printf("%s\n",my_hometown.day[i].dayweather);
//			printf("%s\n",my_hometown.day[i].daywind);
//			printf("%s\n",my_hometown.day[i].nightpower);
//		}
		http_quest_count_last=http_quest_count;
	}


}
void my_timer(lv_timer_t * timer)
{
	 uint32_t  user_data = timer->period;
	 ClockUpdate(user_data);
	 WeatherUpdate();
}

static char short_press_reconnect_ENABLE=0;
void mtimer_a(lv_timer_t * timer)
{
	if((wifi_connect_flag==0)||(wifi_connect_flag==2))
	{
	    static uint8_t page_id = 0;
	    if (page_id == 0){page_id = 1;lv_img_set_src(aimg, &m1_aimg);}
	    else if (page_id == 1){page_id = 2;lv_img_set_src(aimg, &m2_aimg);}
    	else if (page_id == 2){page_id = 3;lv_img_set_src(aimg, &m3_aimg);}
    	else if (page_id == 3){page_id = 4;lv_img_set_src(aimg, &m4_aimg);}
	    else if (page_id == 4){page_id = 5;lv_img_set_src(aimg, &m5_aimg);}
	    else if (page_id == 5){page_id = 6;lv_img_set_src(aimg, &m6_aimg);}
	    else if (page_id == 6){page_id = 7;lv_img_set_src(aimg, &m7_aimg);}
	    else if (page_id == 7){page_id = 8;lv_img_set_src(aimg, &m8_aimg);}
	    else if (page_id == 8){page_id = 9;lv_img_set_src(aimg, &m9_aimg);}
	    else if (page_id == 9){page_id = 10;lv_img_set_src(aimg, &m10_aimg);}
	    else if (page_id == 10){page_id = 11;lv_img_set_src(aimg, &m11_aimg);}
	    else if (page_id == 11){page_id = 12;lv_img_set_src(aimg, &m12_aimg);}
	    else if (page_id == 12){page_id = 0;lv_img_set_src(aimg, &m13_aimg);}

	    lv_label_set_text_fmt(wifi_connect_cont, "#ffffff WIFI Trying to connect %d times#",s_retry_num+1);

	    if(wifi_connect_flag==2)
	    {
	    	lv_label_set_text(wifihttp_connect, "#ffffff Please try reconnecting#");
	    	short_press_reconnect_ENABLE=1;
	    }
	    else if(wifi_connect_flag==2)
	    {

	    	lv_label_set_text(wifihttp_connect, "#ffffff wifi正在连接.....#");
	    }

	}
	else if(wifi_connect_flag==1)
	{

		lv_label_set_text(wifihttp_connect, "#ffffff wifi连接成功#");
		lv_label_set_text(wifi_connect_cont, "#ffffff hello#");
		lv_img_set_src(aimg, &m14_aimg);
		lv_scr_load(sgr);//加载屏幕
	}

}
void my_event_cb(lv_event_t * event)
{
	 ESP_LOGI("my_event_cb", "press!!!!!!");
	 lv_scr_load(desktop);
}
void my_event_cb_updata(lv_event_t * event)
{
	xQueueSend(http_update,&http_queue,0);
}
void weather_show()
{

    lv_group_t *grp =lv_group_create();//创建分组
    lv_indev_set_group(indev_keypad, grp);

	 lv_style_init(&style_btn);//创建一个样式
	 lv_style_set_bg_opa(&style_btn,10);
	// lv_style_set_border_width(&style_btn, 1);
	// lv_style_set_border_color(&style_btn, lv_color_black());


	 background = lv_img_create(sgr);//显示背景
	 lv_img_set_src(background, &bg);

	 Temperature_picture = lv_img_create(sgr);//温标
	 lv_img_set_src(Temperature_picture, &Temperature_scale);
	 lv_obj_set_pos(Temperature_picture, 54, 24);



	 btn_today = lv_btn_create(sgr);//第一天按钮
     lv_obj_set_pos(btn_today, 0, 130);
     lv_obj_set_size(btn_today,80,110);
	 lv_obj_add_style(btn_today, &style_btn, 0);

	 btn_tomorrow = lv_btn_create(sgr);//第二天按钮
	 lv_obj_set_pos(btn_tomorrow, 80, 130);
	 lv_obj_set_size(btn_tomorrow,80,110);
	 lv_obj_add_style(btn_tomorrow, &style_btn, 0);

	 btn_after_tomorrow = lv_btn_create(sgr);//第三天按钮
	 lv_obj_set_pos(btn_after_tomorrow, 160, 130);
	 lv_obj_set_size(btn_after_tomorrow,80,110);
	 lv_obj_add_style(btn_after_tomorrow, &style_btn, 0);

	 btn_esc = lv_btn_create(sgr);
	 mImg_ESC=lv_img_create(btn_esc);
	 lv_img_set_src(mImg_ESC, &esc);
	 lv_obj_set_pos(mImg_ESC, -14, -7);
	 lv_obj_set_size(btn_esc,21,21);
	 lv_obj_set_pos(btn_esc, 205, 10);
	 lv_obj_add_style(btn_esc, &style_btn, 0);

	 lv_group_add_obj(grp,btn_esc);
     lv_group_add_obj(grp,btn_today);
	 lv_group_add_obj(grp,btn_tomorrow);
	 lv_group_add_obj(grp,btn_after_tomorrow);

	 lv_obj_add_event_cb(btn_esc, my_event_cb, LV_EVENT_PRESSED, NULL);
	 lv_obj_add_event_cb(btn_today, my_event_cb_updata, LV_EVENT_PRESSED, NULL);
	 mImg_today = lv_img_create(btn_today);//第一天天气图标
	 lv_img_set_src(mImg_today,img_matching(img_sch,"无") );
	 lv_obj_align_to(mImg_today, btn_today, LV_ALIGN_CENTER, 0, 0);

	 mImg_tomorrow = lv_img_create(btn_tomorrow);//第二天天气图标
	 lv_img_set_src(mImg_tomorrow,img_matching(img_sch,"无"));
	 lv_obj_align_to(mImg_tomorrow, btn_tomorrow, LV_ALIGN_CENTER, 0, 0);

	 mImg_after_tomorrow = lv_img_create(btn_after_tomorrow);//第三天天气图标
	 lv_img_set_src(mImg_after_tomorrow, img_matching(img_sch,"无"));
	 lv_obj_align_to(mImg_after_tomorrow, btn_after_tomorrow, LV_ALIGN_CENTER, 0, 0);


     lable_today = lv_label_create(btn_today);//第一天文本
     lv_obj_set_style_text_font(lable_today,&lv_font_Common_Chinese,0);//使用中文
     lv_label_set_recolor(lable_today, true);           //使能着色
     lv_label_set_text(lable_today, "#ffffff 今天#");
     lv_obj_align_to(lable_today, btn_today, LV_ALIGN_TOP_MID, 0, 5);


     lable_tomorrow = lv_label_create(btn_tomorrow);//第二天文本
     lv_obj_set_style_text_font(lable_tomorrow,&lv_font_Common_Chinese,0);
     lv_label_set_recolor(lable_tomorrow, true);           //使能着色
     lv_label_set_text(lable_tomorrow, "#ffffff 明天#");
     lv_obj_align_to(lable_tomorrow, btn_tomorrow, LV_ALIGN_TOP_MID, 0, 5);

     lable_after_tomorrow = lv_label_create(btn_after_tomorrow);//第三天文本
     lv_obj_set_style_text_font(lable_after_tomorrow,&lv_font_Common_Chinese,0);
     lv_label_set_recolor(lable_after_tomorrow, true);           //使能着色
     lv_label_set_text(lable_after_tomorrow, "#ffffff 后天#");
     lv_obj_align_to(lable_after_tomorrow,btn_after_tomorrow, LV_ALIGN_TOP_MID, 0, 5);

     lable_today_temp = lv_label_create(btn_today);//第一天温度
     lv_obj_set_style_text_font(lable_today_temp,&lv_font_Common_18,0);//使用中文
     lv_label_set_recolor(lable_today_temp, true);           //使能着色
     lv_label_set_text(lable_today_temp, "#ffffff 0℃/0℃#");
     lv_obj_align_to(lable_today_temp, btn_today, LV_ALIGN_BOTTOM_MID, 0, -5);

     lable_tomorrow_temp = lv_label_create(btn_tomorrow);//第二天温度
     lv_obj_set_style_text_font(lable_tomorrow_temp,&lv_font_Common_18,0);
     lv_label_set_recolor(lable_tomorrow_temp, true);           //使能着色
     lv_label_set_text(lable_tomorrow_temp, "#ffffff 0℃/0℃#");
     lv_obj_align_to(lable_tomorrow_temp, btn_tomorrow, LV_ALIGN_BOTTOM_MID, 0, -5);

     lable_after_tomorrow_temp = lv_label_create(btn_after_tomorrow);//第三天温度
     lv_obj_set_style_text_font(lable_after_tomorrow_temp,&lv_font_Common_18,0);
     lv_label_set_recolor(lable_after_tomorrow_temp, true);           //使能着色
     lv_label_set_text(lable_after_tomorrow_temp, "#ffffff 0℃/0℃#");
     lv_obj_align_to(lable_after_tomorrow_temp,btn_after_tomorrow, LV_ALIGN_BOTTOM_MID, 0, -5);

	         lable_Temperature = lv_label_create(sgr);//温度文本
	         lv_obj_set_style_text_font(lable_Temperature,&lv_font_montserrat_40,0);
	         lv_label_set_recolor(lable_Temperature, true);           //使能着色
	         lv_label_set_text(lable_Temperature, "#ffffff 0#");
	         lv_obj_set_pos(lable_Temperature, 10, 10);

	         lable_City = lv_label_create(sgr);//城市文本
	         lv_obj_set_style_text_font(lable_City,&lv_font_Common_Chinese,0);
	         lv_label_set_recolor(lable_City, true);           //使能着色
	         lv_label_set_text(lable_City, "#ffffff 正在获取...#");
	         lv_obj_set_pos(lable_City, 10, 55);

	         lable_Time = lv_label_create(sgr);//时间文本
	         lv_obj_set_style_text_font(lable_Time,&lv_font_Common_Chinese,0);
	         lv_label_set_recolor(lable_Time, true);           //使能着色
	         lv_label_set_text(lable_Time, "#ffffff 正在获取...#");
	         lv_obj_set_pos(lable_Time, 10, 80);

	         lable_Clock = lv_label_create(sgr);//时间文本
	         lv_obj_set_style_text_font(lable_Clock,&lv_font_Common_Chinese,0);
	         lv_label_set_recolor(lable_Clock, true);           //使能着色
	         lv_label_set_text_fmt(lable_Clock, "#ffffff %d:%d:%d#",myClock.Hour,myClock.minute,myClock.second);
	         lv_obj_set_pos(lable_Clock, 10, 105);
}
void text(void)
{
		sgr=lv_obj_create(NULL);//创建屏幕
		desktop=lv_obj_create(NULL);//创建屏幕
    	lv_scr_load(desktop);//加载屏幕

    	/*******************************************************************
    	 * 开启一个定时器，定时回调时钟和天气刷新，参数2必须小于1000且能被1000整除
    	 * 不然会导致读秒偏差太大
    	 * *******************************************************************
    	 * */
        timer = lv_timer_create(my_timer,200,NULL);
        timer_a = lv_timer_create(mtimer_a,150,NULL);//加载动画定时器回调


        static lv_style_t style_bg;
        lv_style_init(&style_bg);
        lv_style_set_bg_color(&style_bg, lv_color_black());
        lv_obj_add_style(desktop, &style_bg, 0);    //将背景设置为黑色


        aimg = lv_img_create(desktop);//显示透明动图
       	lv_img_set_src(aimg, &m14_aimg);
        lv_obj_center(aimg);



        wifihttp_connect = lv_label_create(desktop);//时间文本
		lv_obj_set_style_text_font(wifihttp_connect,&lv_font_Common_Chinese,0);
		lv_label_set_recolor(wifihttp_connect, true);           //使能着色
		lv_label_set_text(wifihttp_connect, "#ffffff wifi正在连接.....#");
		lv_obj_set_pos(wifihttp_connect, 60, 90);


		wifi_connect_cont = lv_label_create(desktop);//时间文本
		lv_label_set_recolor(wifi_connect_cont, true);           //使能着色
		lv_label_set_text_fmt(wifi_connect_cont, "#ffffff WIFI Trying to connect %d times#",s_retry_num+1);
		lv_obj_set_pos(wifi_connect_cont, 10, 130);
        /*
         * 目前没用，留作后期拓展
         * */
//        lv_group_t *grp_main =lv_group_create();//创建分组
//        lv_indev_set_group(indev_keypad, grp_main);
//
//        lv_obj_t * btn1 = lv_btn_create(desktop);
//
//
//        lv_obj_t * btn2 = lv_btn_create(desktop);
//        lv_obj_set_pos(btn2, 0, 80);
//
//        lv_obj_t * btn3 = lv_btn_create(desktop);
//        lv_obj_set_pos(btn3, 0, 160);
//
//        lv_group_add_obj(grp_main,btn1);
//        lv_group_add_obj(grp_main,btn2);
//       	lv_group_add_obj(grp_main,btn3);

    	weather_show();

}
SemaphoreHandle_t xGuiSemaphore;
static void gui_task(void *arg)
{
   xGuiSemaphore = xSemaphoreCreateMutex();
   lv_init();
   lvgl_driver_init();

   /* Example for 1) */
   static lv_disp_draw_buf_t draw_buf;
   lv_color_t *buf1 = heap_caps_malloc(DLV_HOR_RES_MAX * DLV_VER_RES_MAX * sizeof(lv_color_t), MALLOC_CAP_DMA);
   lv_color_t *buf2 = heap_caps_malloc(DLV_HOR_RES_MAX * DLV_VER_RES_MAX * sizeof(lv_color_t), MALLOC_CAP_DMA);

   lv_disp_draw_buf_init(&draw_buf, buf1, buf2, DLV_HOR_RES_MAX * DLV_VER_RES_MAX); /*Initialize the display buffer*/

   static lv_disp_drv_t disp_drv;         /*A variable to hold the drivers. Must be static or global.*/
   lv_disp_drv_init(&disp_drv);           /*Basic initialization*/
   disp_drv.draw_buf = &draw_buf;         /*Set an initialized buffer*/
   disp_drv.flush_cb = disp_driver_flush; /*Set a flush callback to draw to the display*/
   disp_drv.hor_res = 240;                /*Set the horizontal resolution in pixels*/
   disp_drv.ver_res = 240;                /*Set the vertical resolution in pixels*/
   lv_disp_drv_register(&disp_drv);       /*Register the driver and save the created display objects*/

   esp_register_freertos_tick_hook(lv_tick_task);
   ESP_LOGI("LVGL","lv_port_indev_init");

   lv_port_indev_init();
   text();
   ESP_LOGI("LVGL"," text(); over");
   while (1)
   {
      /* Delay 1 tick (assumes FreeRTOS tick is 10ms */
      vTaskDelay(pdMS_TO_TICKS(10));

      /* Try to take the semaphore, call lvgl related function on success */
      if (pdTRUE == xSemaphoreTake(xGuiSemaphore, portMAX_DELAY))
      {
    	// ESP_LOGI("lv_timer_handler"," up date!!!");
         lv_timer_handler();
         xSemaphoreGive(xGuiSemaphore);
      }
   }
}


// wifi 事件
#define EXAMPLE_ESP_WIFI_SSID      "DESKTOP"
#define EXAMPLE_ESP_WIFI_PASS      "11111111"
#define EXAMPLE_ESP_MAXIMUM_RETRY  9
/* FreeRTOS event group to signal when we are connected*/
static EventGroupHandle_t s_wifi_event_group;

/* The event group allows multiple bits for each event, but we only care about two events:
 * - we are connected to the AP with an IP
 * - we failed to connect after the maximum amount of retries */
#define WIFI_CONNECTED_BIT BIT0
#define WIFI_FAIL_BIT      BIT1





static void event_handler(void* arg, esp_event_base_t event_base,
                                int32_t event_id, void* event_data)
{
    if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_START) {
        esp_wifi_connect();
    } else if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_DISCONNECTED) {
        if (s_retry_num < EXAMPLE_ESP_MAXIMUM_RETRY) {
            esp_wifi_connect();
            s_retry_num++;
            ESP_LOGI(TAG, "retry to connect to the AP");
        } else {
            xEventGroupSetBits(s_wifi_event_group, WIFI_FAIL_BIT);
        }
        ESP_LOGI(TAG,"connect to the AP fail");
    } else if (event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP) {
        ip_event_got_ip_t* event = (ip_event_got_ip_t*) event_data;
        ESP_LOGI(TAG, "got ip:" IPSTR, IP2STR(&event->ip_info.ip));
        s_retry_num = 0;
        xEventGroupSetBits(s_wifi_event_group, WIFI_CONNECTED_BIT);
    }
}

void wifi_init_sta(void)
{
    s_wifi_event_group = xEventGroupCreate();

    ESP_ERROR_CHECK(esp_netif_init());

    ESP_ERROR_CHECK(esp_event_loop_create_default());
    esp_netif_create_default_wifi_sta();

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));

    esp_event_handler_instance_t instance_any_id;
    esp_event_handler_instance_t instance_got_ip;
    ESP_ERROR_CHECK(esp_event_handler_instance_register(WIFI_EVENT,
                                                        ESP_EVENT_ANY_ID,
                                                        &event_handler,
                                                        NULL,
                                                        &instance_any_id));
    ESP_ERROR_CHECK(esp_event_handler_instance_register(IP_EVENT,
                                                        IP_EVENT_STA_GOT_IP,
                                                        &event_handler,
                                                        NULL,
                                                        &instance_got_ip));

    wifi_config_t wifi_config = {
        .sta = {
            .ssid = EXAMPLE_ESP_WIFI_SSID,
            .password = EXAMPLE_ESP_WIFI_PASS,
            /* Setting a password implies station will connect to all security modes including WEP/WPA.
             * However these modes are deprecated and not advisable to be used. Incase your Access point
             * doesn't support WPA2, these mode can be enabled by commenting below line */
	     .threshold.authmode = WIFI_AUTH_WPA2_PSK,

            .pmf_cfg = {
                .capable = true,
                .required = false
            },
        },
    };
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA) );
    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifi_config) );
    ESP_ERROR_CHECK(esp_wifi_start());

    ESP_LOGI("wifi_task", "wifi_init_sta finished.");

    /* Waiting until either the connection is established (WIFI_CONNECTED_BIT) or connection failed for the maximum
     * number of re-tries (WIFI_FAIL_BIT). The bits are set by event_handler() (see above) */
    EventBits_t bits = xEventGroupWaitBits(s_wifi_event_group,
            WIFI_CONNECTED_BIT | WIFI_FAIL_BIT,
            pdFALSE,
            pdFALSE,
            portMAX_DELAY);

    /* xEventGroupWaitBits() returns the bits before the call returned, hence we can test which event actually
     * happened. */
    if (bits & WIFI_CONNECTED_BIT)
    {
    	wifi_connect_flag=1;
        ESP_LOGI("wifi_task", "connected to ap SSID:%s password:%s",EXAMPLE_ESP_WIFI_SSID, EXAMPLE_ESP_WIFI_PASS);
        /*wifi连接成功，开始创建http_task*/
        ESP_ERROR_CHECK(nvs_flash_init());
        ESP_ERROR_CHECK(esp_netif_init());
        //ESP_ERROR_CHECK(esp_event_loop_create_default());
        xTaskCreate(&http_get_task, "http_get_task", 4096, NULL, 5, http_get_task_handle);
    }
    else if (bits & WIFI_FAIL_BIT)
    {
    	wifi_connect_flag=2;//提示可以重新开始连接
        ESP_LOGI("wifi_task", "Failed to connect to SSID:%s, password:%s",EXAMPLE_ESP_WIFI_SSID, EXAMPLE_ESP_WIFI_PASS);
    }
    else
    {
        ESP_LOGE("wifi_task", "UNEXPECTED EVENT");
    }

    /* The event will not be processed after unregister */
    ESP_ERROR_CHECK(esp_event_handler_instance_unregister(IP_EVENT, IP_EVENT_STA_GOT_IP, instance_got_ip));
    ESP_ERROR_CHECK(esp_event_handler_instance_unregister(WIFI_EVENT, ESP_EVENT_ANY_ID, instance_any_id));
    vEventGroupDelete(s_wifi_event_group);
}
void wifi_task(void *pvParameter)
{
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
      ESP_ERROR_CHECK(nvs_flash_erase());
      ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);
    while(1)
    {
	 wifi_init_sta();
	// ESP_LOGE("wifi_task", " wifi_task TaskSuspend");
    // vTaskSuspend(wifi_task_handle);
	 vTaskDelete(NULL);
    }
}
/*-----------------------------------------------------------------------------------------
 * Key test
 * ----------------------------------------------------------------------------------------*/
#define key_cont_time 800   //ms

// 定义按下按钮枚举类型
typedef enum {
	KEY_NULL=0,
	KEY_SHORT_PRESS,
	KEY_DOUBLE_PRESS,
	KEY_THREE_PRESS,
	KEY_LONG_PRESS=10  //注这个值不能是4，否则在key_cont_time时间内。按四次也会被认为是KEY_LONG_PRESS。
} alink_key_t;



#define KEY_GPIO		0		//按钮连接的GPIO，这里使用BOOT引脚GPIO0
// 创建队列的句柄
static xQueueHandle gpio_evt_queue = NULL;
//创建按键识别消息队列
static xQueueHandle key_queue = NULL;
// GPIO中断处理函数
void IRAM_ATTR gpio_isr_handler(void *arg) {
	uint32_t gpio_num = (uint32_t) arg;
	xQueueSendFromISR(gpio_evt_queue, &gpio_num, NULL);
}
// 按键GPIO初始化
void KeyInit(uint32_t key_gpio_pin) {
	//配置GPIO结构体
	gpio_config_t io_conf;
	io_conf.intr_type = GPIO_INTR_ANYEDGE;		// 下降沿和上升沿触发中断
	io_conf.pin_bit_mask = 1 << key_gpio_pin;	// 设置GPIO号
	io_conf.mode = GPIO_MODE_INPUT;				// 模式输入
	io_conf.pull_up_en = GPIO_PULLUP_ENABLE;	// 端口上拉使能
	gpio_config(&io_conf);

	// 设置GPIO中断类型
	gpio_set_intr_type(key_gpio_pin, GPIO_INTR_ANYEDGE);// 下降沿和上升沿触发中断
	// 初始化GPIO事件队列
	gpio_evt_queue = xQueueCreate(2, sizeof(uint32_t));
	// 安装GPIO中断服务
	gpio_install_isr_service(0);
	// 添加GPIO中断事件回调函数
	gpio_isr_handler_add(key_gpio_pin, gpio_isr_handler, (void *) key_gpio_pin);
}
// 按键扫描函数，任务中调用
esp_err_t alink_key_scan(TickType_t ticks_to_wait)
{
	uint32_t io_num;
	BaseType_t press_key = pdFALSE;
	BaseType_t release_key = pdFALSE;
	int backup_time = 0;
	while (1) {
		// 接收从消息队列发来的消息
		xQueueReceive(gpio_evt_queue, &io_num, ticks_to_wait);
		if (gpio_get_level(io_num) == 0) {//当前低电平，记录下用户按下按键的时间点
			press_key = pdTRUE;
			backup_time = esp_timer_get_time();
			//如果当前GPIO口的电平已经记录为按下，则开始减去上次按下按键的时间点
		} else if (press_key) {
			//记录抬升时间点
			release_key = pdTRUE;
			backup_time = esp_timer_get_time() - backup_time;
		}
		//近当按下标志位和按键弹起标志位都为1时候，才执行回调
		if (press_key & release_key) {
			press_key = pdFALSE;
			release_key = pdFALSE;
			//如果大于0.5s则回调长按，否则就短按回调
			if (backup_time > 500000) {
				return KEY_LONG_PRESS;
			} else {
				return KEY_SHORT_PRESS;
			}
		}
	}
}

esp_timer_handle_t oneshot_timer ;
esp_err_t once_timer_occupy=0;
int key_state=0;
int key_resive=0;
static void oneshot_timer_callback(void* arg)
{
   // int64_t time_since_boot = esp_timer_get_time();
   // ESP_LOGI(TAG, "One-shot timer called, time since boot: %lld us,key_state=%d", time_since_boot,key_state);
    key_resive=key_state;

    if(key_resive)//注:应为是在中断中判断，所以只能当作标志，具体按键功能需要放在主函数实现。
    {
    		switch (key_resive) {

    				case KEY_SHORT_PRESS:
    					ESP_LOGI(TAG,"Button Short Down data=%d\r\n",key_resive);
    					xQueueSendFromISR(key_queue, &key_resive, NULL);
    					break;
    				case KEY_DOUBLE_PRESS:
    					ESP_LOGI(TAG,"Button double Down data=%d\r\n",key_resive);
    					xQueueSendFromISR(key_queue, &key_resive, NULL);
    					break;
    				case KEY_THREE_PRESS:
    					ESP_LOGI(TAG,"Button three Down data=%d\r\n",key_resive);
    					xQueueSendFromISR(key_queue, &key_resive, NULL);
    					break;
    				default:
    					ESP_LOGI(TAG,"Button three Down data=%d\r\n",key_resive);
    					xQueueSendFromISR(key_queue, &key_resive, NULL);
    					break;
    		}
    		key_resive=0;
      }
    ESP_ERROR_CHECK(esp_timer_delete(oneshot_timer));//一次定时结束之后删除这个定时器
    once_timer_occupy=0;
    key_state=0;
}
void once_timer_init_ms(int time)
{
	if(!once_timer_occupy)
	{
		const esp_timer_create_args_t oneshot_timer_args = {
        .callback = &oneshot_timer_callback,
        .name = "one-shot"
        };//单次定时器配置
		ESP_ERROR_CHECK(esp_timer_create(&oneshot_timer_args, &oneshot_timer));
		ESP_ERROR_CHECK(esp_timer_start_once(oneshot_timer, 1000*time));
		once_timer_occupy=1;
		key_state=1;
	//	ESP_LOGI(TAG, "open the once_time successful time=%lld,key_state=%d",esp_timer_get_time(),key_state);
	}
	else
	{
		key_state++;
		//ESP_LOGI("once_timer", "once_time is in use");
	}

}


void key_expand(esp_err_t state)
{
	if(state==KEY_SHORT_PRESS)
	{
		once_timer_init_ms(key_cont_time);
	}
	if(state==KEY_LONG_PRESS)
	{
		ESP_LOGI(TAG,"Button Long Down data=%d\r\n",state);
		xQueueSend(key_queue, &state, NULL);
	}
	//ESP_LOGI("--------------------------------","key_resive= %d\r\n",key_resive);
}
// 按键中断任务
void key_trigger_Task(void *arg) {
	esp_err_t ret = 0;
	KeyInit(KEY_GPIO);
	while (1) {
		ret = alink_key_scan(portMAX_DELAY);//这个任务循环不能一直跑，会卡在这一步死等消息
		if (ret == -1)
		vTaskDelete(NULL);
	    key_expand(ret);
	}
	vTaskDelete(NULL);
}

void key_queue_test_task(void* arg)
{
	//初始化按键返回值消息队列
	key_queue = xQueueCreate(2, sizeof(uint32_t));
	esp_err_t key_queue_resive=0;

	while(1)
	{
		//printf("wait for key_queue.....\n");
		xQueueReceive(key_queue, &key_queue_resive, portMAX_DELAY);
		printf("resive key_queue data=%d\n",key_queue_resive);
		if(key_queue_resive==KEY_SHORT_PRESS)
		{
			//put your short press function
			key.once_press=1;//注：必须在使用之后由用户自己清零
			if(short_press_reconnect_ENABLE==1)//连接失败允许重新连接
			{
				short_press_reconnect_ENABLE=0;
				lv_scr_load(sgr);//加载weather屏幕

			}

		}
		else if(key_queue_resive==KEY_DOUBLE_PRESS)
		{
			//put your double press function
			key.second_press=1;
		}
		else if((key_queue_resive>=KEY_THREE_PRESS)&&(key_queue_resive!=KEY_LONG_PRESS))
		{
			//put your three press function
			key.third_press=1;
		}
		else if(key_queue_resive==KEY_LONG_PRESS)
		{
			//put your long press function
			//printf("here--------------");
			key.long_press=1;
		}
		else
		{
			printf("Congratulations on triggering an error that can't be triggered at all");
		}
		key_queue_resive=0;
	}
}


//--------------------------------------
void set_up(void)
{
	http_quest_count=0;
}

void app_main(void)
{
	set_up();
	xTaskCreatePinnedToCore(gui_task, "gui task", 1024 * 4, NULL, 4, NULL, 0);
	// 参数：任务函数，任务别名，任务堆栈的深度，参数的指针，任务优先级，回传句柄
   xTaskCreate(&wifi_task,"WIFI_Task",1024*3,NULL,5,wifi_task_handle);


    xTaskCreate(key_queue_test_task, "key_queue_test_task", 1024 * 2, NULL, 11, key_queue_test);
   	xTaskCreate(key_trigger_Task, "key_trigger_Task", 1024 * 2, NULL, 10, NULL);

}
