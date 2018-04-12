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
const int POTENTIOMETER_PIN_Y = 4;
const int BUTTON_PIN_NUMBER = 10;

// a global variable that represents the LED screen
RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

// the following functions are for printing messages
void print_level(int level);
void print_lives(int lives);
void game_over();

const int SIZE_COL = 25;
const int SIZE_ROW = 16;

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


class Player {
  public:
    Player() {
      x = 0;
      y = 1;
      lives = 3;
    }
    
    // getters
    int get_x() const {
      return x;
    }
    int get_y() const {
      return y;
    }
    int get_lives() const {
      return lives;
    }
    
    // setters
    void set_x(int x_arg) {
      x = x_arg;
    }

    void set_y(int y_arg) {
      y = y_arg;
    }
    
    // Modifies: lives
    void die() {
      if(lives > 0) {
        lives--;
      }
      else {
        // FIX ME LATER PLEEEEEEEEEEEEEEEEEEEAAAAAAAAAASSSSSSSSSSSSSSSSSSSSSEEEEEEEEEEEEE
        //game_over();
      }
    }
    
    // draws the Player
    void draw() {
      draw_with_rgb(AQUA); 
    }
    
    // draws black where the Player used to be
    void erase() {
      draw_with_rgb(BLACK);
    }

    void draw_with_rgb(Color color) {
        String player_arr[1][1] = {"*"};
          for(int row = 0; row < SIZE; row++) {
            for(int col = 0; col < SIZE; col++){
              if(player_arr[col][row] == "#") {
                matrix.drawPixel(x + row, y + col, color.to_333());
            }
         }
    }
    }

  private:
    int x;
    int y;
    int lives;
    const int SIZE = 2;

    // sets private data members x and y to initial values
    void initialize(int x_arg, int y_arg) {
      x = x_arg;
      y = y_arg;
    }
};


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

    void maze_setup(int level) {
      if(level == 1) {
        void draw_with_rgb(Color maze_color) {
          String maze_array_one[SIZE_COL][SIZE_ROW] {
            "#"," ","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#",
            "#"," ","#"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ","#"," ","#",
            "#"," ","#"," ","#","#","#"," ","#","#","#","#","#","#","#","#","#","#","#","#","#"," ","#"," ","#",
            "#"," ","#"," ","#"," ","#"," "," "," ","#"," "," "," "," "," "," "," "," ","#"," "," ","#"," ","#",
            "#"," ","#"," ","#"," ","#","#","#"," ","#"," ","#","#","#","#","#","#","#","#"," ","#","#"," ","#",
            "#"," ","#"," ","#"," "," "," ","#"," ","#"," ","#"," "," "," ","#"," "," "," "," "," "," "," ","#",
            "#"," ","#"," ","#"," ","#"," ","#"," ","#"," "," "," ","#"," "," "," ","#"," "," ","#","#","#","#",
            "#"," ","#"," ","#"," ","#"," ","#"," ","#","#","#","#","#","#","#","#","#","#"," "," "," "," ","#",
            "#"," ","#"," ","#"," ","#"," ","#"," "," "," "," "," "," "," "," "," "," ","#"," ","#","#"," ","#",
            "#"," ","#"," ","#"," ","#","#","#","#","#","#","#","#","#","#","#","#"," ","#"," ","#"," "," ","#",
            "#"," ","#"," ","#"," "," "," "," "," "," "," "," "," "," "," "," ","#"," ","#"," ","#","#"," ","#",
            "#"," ","#"," ","#","#","#"," ","#","#","#","#","#","#","#","#","#","#"," ","#","#","#","#","#","#",
            "#"," ","#"," "," "," ","#"," "," "," "," "," "," "," "," "," "," ","#"," "," "," "," "," "," "," ",
            "#"," ","#","#","#"," ","#","#","#","#","#","#","#","#","#","#"," ","#","#","#","#","#","#","#"," ",
            "#"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ","#"," ",
            "#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"," "};
            
    for(int row = 0; row < SIZE_ROW; row++) {
          for(int col = 0; col < SIZE_COL; col++) {
            if(maze_array_one[col][row] == "#") {
              matrix.drawPixel(x + row, y + col, maze_color.to_333());
            }
         }
      }
   }
 }
  if(level == 2) {
    void draw_with_rgb_two(Color maze_color) {
          String maze_array_two[SIZE_COL][SIZE_ROW] {
            "#"," ","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#",
            "#"," ","#"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ","#"," ","#",
            "#"," ","#"," ","#","#","#"," ","#","#","#","#","#","#","#","#","#","#","#","#","#"," ","#"," ","#",
            "#"," ","#"," ","#"," ","#"," "," "," ","#"," "," "," "," "," "," "," "," ","#"," "," ","#"," ","#",
            "#"," ","#"," ","#"," ","#","#","#"," ","#"," ","#","#","#","#","#","#","#","#"," ","#","#"," ","#",
            "#"," ","#","#","#"," "," "," ","#"," ","#"," ","#"," "," "," ","#"," "," "," "," "," "," "," ","#",
            "#"," "," "," "," "," ","#"," ","#"," ","#"," "," "," ","#"," "," "," ","#"," "," ","#","#","#","#",
            "#","#","#","#","#"," ","#"," ","#"," ","#","#","#","#","#","#","#","#","#","#"," "," "," "," ","#",
            "#"," "," "," ","#"," ","#"," ","#"," "," "," "," "," "," "," "," "," "," ","#"," ","#","#"," ","#",
            "#","#","#"," ","#"," ","#","#","#","#","#","#","#","#","#","#","#","#"," ","#"," ","#"," "," ","#",
            "#"," ","#"," ","#"," "," "," "," "," "," "," "," "," "," "," "," ","#"," ","#"," ","#","#"," ","#",
            "#"," ","#"," ","#","#","#"," ","#","#","#","#","#","#","#","#","#","#"," ","#","#","#","#","#","#",
            "#"," ","#"," "," "," ","#"," "," "," "," "," "," "," "," "," "," ","#"," "," "," "," "," "," "," ",
            "#"," ","#","#","#"," ","#","#","#","#","#","#","#","#","#","#"," ","#","#","#","#","#","#","#"," ",
            "#"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ","#"," ",
            "#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"," "};
            
    for(int row = 0; row < SIZE_ROW; row++) {
          for(int col = 0; col < SIZE_COL; col++) {
            if(maze_array_two[col][row] == "#") {
              matrix.drawPixel(x + row, y + col, maze_color.to_333());
            }
         }
      }
   }
  }
    }
  };

void setup(){
      matrix.setTextSize(1);
      print_lives(player.get_lives());
      delay(2000);
      matrix.fillScreen(BLACK.to_333());
      matrix.setCursor(0, 0);
      print_level(level);
      delay(2000);
      matrix.fillScreen(BLACK.to_333());
      delay(2000);
      //DONT FORGET TO GET RID OF THIS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 }
 void update(int potentiometer_value, int potentiometer_y) {
      time = millis();
      
      player.erase();
      player.set_x(potentiometer_value / 32);
      player.draw();

      player.erase();
      player.set_y(potentiometer_y / 16);
      player.draw();

      matrix.print("HELP");
  }

    bool get_level_cleared() {
        //return level_cleared();
    }
    private:
    int level;
    unsigned long time;
    unsigned long now;
    Player player;
    Maze maize[16];
};

// a global variable that represents the game Space Invaders
Game game;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN_NUMBER, INPUT);
  matrix.begin();
  game.setup();
}


void loop() {
  int potentiometer_value = analogRead(POTENTIOMETER_PIN_NUMBER);
  int potentiometer_y = analogRead(POTENTIOMETER_PIN_Y);
}


// Displays the level number.
void print_level(int level) {
  matrix.print("Level:");
  matrix.print(level);
}

// Displays the number of lives.
void print_lives(int lives) {
  matrix.print("Lives:");
  matrix.print(lives);
}

// Displays "Game Over!" message when player dies. 
void game_over() {
    matrix.print("Game Over!");
}
