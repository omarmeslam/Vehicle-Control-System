#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{

    char TrafficLight;
    char AC_State[5];
    char Engine_State[5];
    char EngineTempController_State[5];
    int Speed;
    float RoomTemp;
    float EngineTemp;


}VehicleInfo;

VehicleInfo vehicle1;

char* SystemStateArr[2]={"ON","OFF"};

void SensorsSetMenu(void)
{
    printf("\nSensors set menu:- \n");
    printf("1- Turn off the engine.\n");
    printf("2- Set the traffic light color.\n");
    printf("3- Set the room temperature (Temperature Sensor)\n");
    printf("4- Set the engine temperature (Engine Temperature Sensor)\n");
}

void SetVehicleSpeed(VehicleInfo* vehicle,char color)
{
    if(color=='G')
    {
        vehicle->Speed=100;
    }
    else if(color=='O')
    {
        vehicle->Speed=30;
    }
    else if(color=='R')
    {
        vehicle->Speed=0;
    }
    else
    {

    }
}

void SetRoomTempData(VehicleInfo* vehicle,float temp)
{
    if((temp < 10.0) || (temp > 30.0))
    {
        strcpy(vehicle->AC_State,SystemStateArr[0]);
        vehicle->RoomTemp=20.0;
    }
    else
    {
        strcpy(vehicle->AC_State,SystemStateArr[1]);
        vehicle->RoomTemp=temp;
    }
}


void SetEngineTempData(VehicleInfo* vehicle,float temp)
{

    if((temp < 100) || (temp > 150))
    {
        strcpy(vehicle->EngineTempController_State,SystemStateArr[0]);
        vehicle->EngineTemp=125;
    }
    else
    {
        strcpy(vehicle->EngineTempController_State,SystemStateArr[1]);
        vehicle->EngineTemp=temp;
    }

}

void DisplayVehicleState(VehicleInfo* vehicle)
{
    printf("\n\n");
    printf("Engine State: %s\n", vehicle->Engine_State);
    printf("AC State: %s \n", vehicle->AC_State);
    printf("Vehicle Speed: %d km/hr\n", vehicle->Speed);
    printf("Room Temperature: %0.2f \n", vehicle->RoomTemp);
    printf("Engine Temperature Controller State: %s \n", vehicle->EngineTempController_State);
    printf("Engine Temperature: %0.2f \n", vehicle->EngineTemp);
    printf("\n\n");

}

int main()
{

    printf("-----------------------------------------------------------------------------------------\n");
    printf("\t\t\t\tWelcome to Vehicle Control system\n");
	printf("-----------------------------------------------------------------------------------------\n");

    printf("1- Turn on the vehicle engine.\n");
    printf("2- Turn off the vehicle engine.\n");
    printf("3- Quit the system.\n\n");

    int RunSystem=1;

    while(RunSystem)
    {
        int op=0, chose=0;
        char ScanTrafficColor;
        float ScanRoomTemp, ScanEngineTemp;

        printf("Enter the option: ");
        scanf("%d", &op);
        fflush(stdin);

        switch(op)
        {
        case 1:/*Turn on the vehicle engine*/

            SensorsSetMenu();
            printf("\n\nSystem State: %s\n", SystemStateArr[1]);
            strcpy(vehicle1.Engine_State,SystemStateArr[0]);
            printf("\nEnter the traffic light color: ");
            scanf("%c", &ScanTrafficColor);
            fflush(stdin);
            SetVehicleSpeed(&vehicle1,ScanTrafficColor);

            printf("Enter the room temperature data: ");
            scanf("%f", &ScanRoomTemp);
            fflush(stdin);
            SetRoomTempData(&vehicle1,ScanRoomTemp);

            printf("Enter the Engine temperature data: ");
            scanf("%f", &ScanEngineTemp);
            fflush(stdin);
            SetEngineTempData(&vehicle1,ScanEngineTemp);

            if(vehicle1.Speed == 30)
            {
                strcpy(vehicle1.AC_State,SystemStateArr[0]);
                vehicle1.RoomTemp=((vehicle1.RoomTemp*5)/4) + 1.0;
                strcpy(vehicle1.EngineTempController_State,SystemStateArr[0]);
                vehicle1.EngineTemp=((vehicle1.EngineTemp*5)/4) + 1.0;
            }

            DisplayVehicleState(&vehicle1);

            break;

        case 2:/*Turn off the vehicle engine*/
            printf("System State: %s\n", SystemStateArr[1]);
            strcpy(vehicle1.Engine_State,SystemStateArr[1]);
            SetVehicleSpeed(&vehicle1,'R');
            break;

        case 3:/*Quit the system*/
            RunSystem=0;
            printf("\nQuit program\n");
            break;

        }
    }


    return 0;
}
