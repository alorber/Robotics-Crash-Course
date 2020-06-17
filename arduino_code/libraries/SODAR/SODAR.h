#include <Arduino.h>
#include <Servo.h>
#include <HC_SR04.h>

class SODAR
{
    public:
        SODAR(int, int, int, int, int, int, int, int); //Constructor, takes Servo, and HC_SR04 sensor
        bool initialize_arrays();  //set array lengths and initialize values to prevent erroneous startup data
        void set_center_resolution_and_range(int, int, int, int); //Allow user to reset center, resolution and range from what was initially sent in the constructor

        double get_forward_distance();
        int distance[];  //Array of distances from HC_SR04, each element is correlated to an element in orientation[] to give us an mapping of distance s from the robot at different angles
        int orientation[]; //Servo orientation array, each element is the degrees value we will turn the servo to, to sense the distance of an object in front
        int array_length; //Length of the distance and orientation array, logic defined in constructor
        int center;       //Angle that defines the center of the range (the forward facing direction)
        int resolution;   //discretization resolution (in deg) for scanning range
        int upper_range;  //Upper servo angle limit for scanning
        int lower_range;  //Lower servo angle limit for scanning
        long previous_millis; //Timing variable to not have to use delay() to enable estimated_servo_response_time delay through millis();
        long estimated_servo_response_time; //Estimated delay time to wait for servo to reach written position
        int num_upper_segments;  //Number of discretizations elements below center for sensor's range
        int num_lower_segments;  //Numer of discretization elements above center for sensors' range

        void update(); // Logic to check if current scanning position is finished and can move to the next (using millis() etc...)
        void next();   // Called in update(), this holds the logic for determining next servo positoin, and sending servo to that position
        void start(); // Start the scanning process
        void stop(); //Stop the scanning process
};