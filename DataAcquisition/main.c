#include <stdio.h>
#include <stdlib.h>
//#include "c:/Users/shawn/gtec/gNEEDaccess Client API/C/GDSClientAPI.h"
//extern "C" {
    #include "../C/GDSClientAPI.h"
//}


#define SERVER_IP "127.0.0.1"  // Change if needed
#define SERVER_PORT 50223      // Default g.NEEDaccess server port

int main() {
    GDS_HANDLE connectionHandle;
    GDS_ENDPOINT serverEndpoint, localEndpoint;
    GDS_RESULT result;

    // Initialize the API
    GDS_Initialize();

    // Set up server endpoint
    snprintf(serverEndpoint.IpAddress, IP_ADDRESS_LENGTH_MAX, SERVER_IP);
    serverEndpoint.Port = SERVER_PORT;
    
    // Set up local endpoint
    snprintf(localEndpoint.IpAddress, IP_ADDRESS_LENGTH_MAX, "127.0.0.1"); // Loopback address
    localEndpoint.Port = 0; // Auto-select port

    // Connect to the server
    result = GDS_Connect(serverEndpoint, localEndpoint, NULL, 0, 0, &connectionHandle, NULL);
    if (result.ErrorCode != GDS_ERROR_SUCCESS) {
        printf("Failed to connect to server: %s\n", result.ErrorMessage);
        return -1;
    }
    printf("Connected to g.NEEDaccess server.\n");

    // Start data acquisition
    result = GDS_StartAcquisition(connectionHandle);
    if (result.ErrorCode != GDS_ERROR_SUCCESS) {
        printf("Failed to start acquisition: %s\n", result.ErrorMessage);
        GDS_Disconnect(&connectionHandle);
        return -1;
    }
    printf("Data acquisition started.\n");

    // Start streaming
    result = GDS_StartStreaming(connectionHandle);
    if (result.ErrorCode != GDS_ERROR_SUCCESS) {
        printf("Failed to start streaming: %s\n", result.ErrorMessage);
        GDS_StopAcquisition(connectionHandle);
        GDS_Disconnect(&connectionHandle);
        return -1;
    }
    printf("Streaming started.\n");

    // Clean up
    GDS_StopStreaming(connectionHandle);
    GDS_StopAcquisition(connectionHandle);
    GDS_Disconnect(&connectionHandle);
    GDS_Uninitialize();
    printf("Disconnected and cleaned up.\n");

    return 0;
}
