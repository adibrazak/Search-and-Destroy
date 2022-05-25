# EV3-Search-and-Destroy
While keep maintain to be inside the box (play area), the EV3 will detect an object inside the play area and push the object outside of the play area. 

EV3 LEGO® Mindstorms® was programmed using Eclipse with c4ev3 software package to move while keep maintain to be inside the play area. The EV3 will find the object inside the play area and push it outside the area.

Robot was programmed as follows:

1. Using ultrasonic sensor, EV3 can detect object inside the play area.
2. EV3 is program to rotate and keep checking for nearby object.
3. If after certain rotation angle, EV3 still could not find the object, it will move to new location.
4. Then, it will rotate and find object again.
5. EV3 will move forward when detecting certain object that is below the range threshold. (In this case, below 40cm)
6. Using light sensor, EV3 can read the percentage of reflected light.
7. EV3 will stop moving forward (pushing) when certain reflected light threshold is detected. (In this case, below 15%)

The program is written in C/C++ using Eclipse with c4ev3 software package. Link for references on c4ev3 https://c4ev3.github.io/

EV3 demonstration https://youtu.be/2x8ts4f_3dY 
