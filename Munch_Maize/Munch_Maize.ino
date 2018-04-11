#include <gamma.h>
#include <RGBmatrixPanel.h>
#include <Adafruit_GFX.h>

// define the wiring of the LED screen
const uint8_t CLK  = 8;
const uint8_t LAT = A3;
const uint8_t OE = 9;
const uint8_t A = A0; 
const uint8_t B = A1;
const uint8_t C = A2;

// define the wiring of the inputs
const int POTENTIOMETER_PIN_NUMBER = 5;
const int BUTTON_PIN_NUMBER = 10;

class Color {
  public:
    int red;
    int green;
    int blue;
    
    Color() {
      red = 0;
      green = 0;
      blue = 0;
    }
    
    Color(int r, int g, int b) {
      red = r;
      green = g;
      blue = b;
    }
    
    uint16_t to_333() const {
      //return matrix.Color333(red, green, blue);
    }
};

const Color BLACK(0, 0, 0);
const Color RED(4, 0, 0);
const Color ORANGE(6, 1, 0);
const Color YELLOW(4, 4, 0);
const Color GREEN(0, 4, 0);
const Color BLUE(0, 0, 4);
const Color PURPLE(1, 0, 2);
const Color WHITE(4, 4, 4);
const Color LIME(2, 4, 0);
const Color AQUA(0, 4, 4);

class Game {
  public:
    Game() {
      level = 1;
      time = 0;
    }

    // non-default constructor for Game constructor 
    Game(int level_arg){
      level = level_arg;
    }

    //void setup()

    bool get_level_cleared() {
        //return level_cleared();
    }
    private:
    int level;
    unsigned long time;
    unsigned long now;
};


void setup() {
   Serial.begin(9600);
  pinMode(BUTTON_PIN_NUMBER, INPUT);
  //matrix.begin();
  //game.setup();

}

void loop() {
int potentiometer_value = analogRead(POTENTIOMETER_PIN_NUMBER);
  
}


// Displays the level number.
void print_level(int level) {
  //matrix.print("Level:");
  //matrix.print(level);
}

// Displays the number of lives.
void print_lives(int lives) {
  //matrix.print("Lives:");
  //matrix.print(lives);
}

// Displays "Game Over!" message when player dies. 
void game_over() {
    //matrix.print("Game Over!");
}
