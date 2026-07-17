#include <stdio.h>

int main(){
    int rooms[] = { 1, 0 }; 
    int agentLocation = 0;

    // 2. Setup Performance Trackers
    int totalActions = 0;
    int totalCleans = 0;
    int maxSteps = 3;

    // 3. The Simulation Loop
    for (int step = 0; step < maxSteps; step++) 
    {
        // Sensor: Check if current room is dirty
        if (rooms[agentLocation] == 1) 
        {
            printf("\nStep %d: Room %d is dirty. Action: SUCK.", step, agentLocation);
            rooms[agentLocation] = 0; // The room is now clean
            totalCleans++;
            totalActions++;
        } 
        else 
        {
            // Action: Move to the other room
            int nextRoom = (agentLocation == 0) ? 1 : 0;
            printf("\nStep %d: Room %d is clean. Action: MOVE to Room %d.", step, agentLocation, nextRoom);
            agentLocation = nextRoom;
            totalActions++;
        }
    }

    // 4. Calculate Performance
    double performanceRatio = (double)totalActions / (double)totalCleans;
    printf("\nTotal Actions: %d", totalActions);
    printf("\nTotal Cleans: %d", totalCleans);
    printf("\nPerformance Ratio: %f\n", performanceRatio);

    return 0;
}