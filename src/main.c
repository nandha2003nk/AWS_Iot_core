
#include <stdio.h>
#include "mqtt_client.h"

int main(void)
{
    printf("================================\n");
    printf("       AWS IoT C Project        \n");
    printf("================================\n");

    MqttClient client = {0};

    if (mqtt_client_init(
            &client,
            "tcp://localhost:1883",
            "AWS_IOT_C_DEVICE"
        ) != 0)
    {
        printf("Application initialization failed.\n");
        return 1;
    }

    printf("Application initialized.\n");

    mqtt_client_cleanup(&client);

    return 0;
}
