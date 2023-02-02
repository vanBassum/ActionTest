
#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "action.h"
#include "esp_log.h"

static const char *TAG = "MAIN";

extern "C"
{
	void app_main(void);
}

class Foo
{
public:
	ESP_Base::Action<int> SomeCallback;
	
	void Run()
	{
		SomeCallback.Invoke(42);
	}
};


void CallbackHandler(int value)
{
	ESP_LOGI(TAG, "Callback value = %d", value);
}


void app_main(void)
{
	printf("Hello world!\n");
	Foo foo;
	foo.SomeCallback.Bind(CallbackHandler);
	foo.Run();
	
	while (1)
		vTaskDelay(pdMS_TO_TICKS(1000));

}