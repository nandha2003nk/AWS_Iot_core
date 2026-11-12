
#include <stdio.h>

#include "mqtt_client.h"

int mqtt_client_init(
    MqttClient *client,
    const char *broker_uri,
    const char *client_id
)
{
    if (client == NULL || broker_uri == NULL || client_id == NULL)
    {
        return -1;
    }

    client->handle = NULL;
    client->initialized = 0;

    int rc = MQTTAsync_create(
        &client->handle,
        broker_uri,
        client_id,
        MQTTCLIENT_PERSISTENCE_NONE,
        NULL
    );

    if (rc != MQTTASYNC_SUCCESS)
    {
        printf("MQTT client creation failed: %d\n", rc);
        return -1;
    }

    client->initialized = 1;

    printf("MQTT client created successfully.\n");

    return 0;
}

void mqtt_client_cleanup(MqttClient *client)
{
    if (client == NULL || !client->initialized)
    {
        return;
    }

    MQTTAsync_destroy(&client->handle);

    client->initialized = 0;

    printf("MQTT client destroyed.\n");
}
