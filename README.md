# Blood_1
Motor car project with stm32. This will be a long during project, both learning and applying on the car.

***** Function: *****
- The car moves following the black line to reach the destination.
- Stop when encounting abstacles, then warning.
- Communicate to ESP32 to be able to get demand from smart phone.

***** Components: *****
- Stm32f103c8t6
- Module Sensor determining line
- Esp32
- 4 active wheel, working independently

***** Operation *****
- Automatic:
  + Travel on the black line
  + without line, it gets to destination by position from rada. Find route to reach to terminal place
- Manual:
  + Moving in any direction, that controled by a controler

<=========================================================================================>
There are 3 temperature sensors which are put in a line
If signal is 0, no line is recognized
If signal is 1, line is recognized
/*
=> 2^3 cases
   no      |     case          |        position      |          respond          |
   1             0 0 0                                          run back
   2             0 1 0                                          go straight
   3             1 1 0                                          turn left
   4             1 0 0                                          turn left
   5             0 1 1                                          turn right
   6             0 0 1                                          turn right             
   7             1 0 1                                          run back to check 
   8             1 1 1                                          run back to check
 */  
