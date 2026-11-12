
#ifndef MQTT_CLIENT_H
#define MQTT_CLIENT_H

#include <MQTTAsync.h>

typedef struct
{
    MQTTAsync handle;
    int initialized;

} MqttClient;

int mqtt_client_init(
    MqttClient *client,
    const char *broker_uri,
    const char *client_id
);

void mqtt_client_cleanup(MqttClient *client);

#endif
