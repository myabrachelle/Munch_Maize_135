#include <gamma.h>
#include <RGBmatrixPanel.h>
#include <Adafruit_GFX.h>

//Defines the wiring to the LED screen.
const uint8_t CLK  = 8;
const uint8_t LAT = A3;
const uint8_t OE = 9;
const uint8_t A = A0; 
const uint8_t B = A1;
const uint8_t C = A2;

//Define the wiring to the inputs.
const int POTENTIOMETER_PIN_NUMBER = 5;
const int POTENTIOMETER_PIN_Y = 4;
const int BUTTON_PIN_NUMBER = 10;

//A global variable that represents the LED screen.
RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

//The following functions are for printing messages.
void print_opening();
void print_level(int level);
void print_lives(int lives);
void game_over();

//Global constants for the maze sizes.
const int SIZE_COL = 28;
const int SIZE_ROW = 16;

//Global constant for Player and Fruit sizes.
const int SIZE = 2;

//Our only maze, unfortunately. :(
const bool maze_array[SIZE_ROW][SIZE_COL] {
  {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,0},
  {0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,0,0,1,0},
  {0,1,0,1,1,1,0,1,1,1,1,0,1,1,1,1,0,0,0,1,0,1,0,1,0,1,1,0},
  {0,1,1,1,0,1,0,1,0,0,0,0,0,0,0,1,1,1,0,1,0,1,1,1,0,1,0,0},
  {0,0,0,0,0,1,0,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0,1,1,0},
  {0,1,1,1,1,1,0,0,0,0,0,0,1,0,1,0,0,0,0,1,0,1,1,1,0,0,1,0},
  {0,1,0,0,0,1,0,1,1,1,1,0,1,0,1,0,1,1,1,1,0,1,0,1,0,0,1,0},
  {0,1,0,1,1,1,0,1,0,0,1,0,1,0,1,1,1,0,0,0,0,1,0,1,1,1,1,0},
  {0,1,0,1,0,0,0,1,0,1,1,0,1,0,1,0,0,0,1,1,1,1,0,0,0,0,0,0},
  {0,1,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,1,1,0,0,0,0,1,1,1,1,0},
  {0,1,0,0,0,0,0,0,0,1,1,1,1,0,1,0,1,0,0,0,1,1,1,1,0,0,0,0},
  {0,1,1,1,1,1,1,1,0,1,0,0,0,0,1,0,1,1,1,1,1,1,0,0,0,1,1,1},
  {0,0,0,0,0,0,0,1,0,1,0,1,1,1,1,0,1,0,0,0,0,1,0,1,1,1,0,0},
  {0,1,1,1,1,1,1,1,0,1,0,1,0,0,0,0,1,1,1,1,0,1,1,1,0,1,1,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
  
//Color class definition.
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
      return matrix.Color333(red, green, blue);
    }
};

const Color BLACK(0, 0, 0);
const Color RED(4, 0, 0);
const Color ORANGE(6, 1, 0);
const Color YELLOW(4, 4, 0);
const Color GREEN(0, 4, 0);
const Color BLUE(0, 0, 4);
const Color PURPLE(1, 0, 1);
const Color WHITE(4, 4, 4);
const Color LIME(2, 4, 0);
const Color AQUA(0, 4, 4);
const Color FUSCHIA(4, 0, 1);

//Definition for the Player class.
class Player {
  public:
    Player() {
      x = 0;
      y = 0;
      lives = 3;
    }
    
    //Gets x-coordinate.
    int get_x() const {
      return x;
    }
    
    //Gets y-coordinate.
    int get_y() const {
      return y;
    }

    //Gets Player's lives.
    int get_lives() const {
      return lives;
    }

    //Initializes the Player's initial coordinates for each level.
    void initialize(int x_arg, int y_arg) {
      x = x_arg;
      y = y_arg;
    }
    
    //Sets x-coordinate.
    void set_x(int x_arg) {
      if(x_arg >= 0 && x_arg < 32) {
        x = x_arg;
      }
      else {
        if(x_arg < 0) {
          x = 0;
        }
        if(x_arg > 32) {
          x = 31;
        }
      }
    }

    //Sets y-coordinate.
    void set_y(int y_arg) {
      if(y_arg >= 0 && y_arg < 16) {
        y = y_arg;
      }
      else {
        if(y_arg < 0) {
          y = 0;
        }
        if(y_arg > 16) {
          y = 15;
        }
      }
    }
    
    //Modifies Player's lives.
    void die() {
      if(lives > 0) {
        lives--;
      }
      else {
        game_over();
      }
    }
    
    //Draws the Player.
    void draw() {
      draw_with_rgb(YELLOW); 
    }
    
    //Draws black where the Player used to be.
    void erase() {
      draw_with_rgb(BLACK);
    }

  private:
    int x;
    int y;
    int lives;
    
    //Goes through the Player array to draw in corresponding pixels.
    void draw_with_rgb(Color color) {
      String player_array[1][1] = {"*"};
      for(int row = 0; row < SIZE; row++) {
        for(int col = 0; col < SIZE; col++) {
          if(player_array[col][row] == "*") {
            matrix.drawPixel(x + row, y + col, color.to_333());
          }
        }
      }
    }
};

//Definition for the Fruit class.
class Fruit {
  public:
    Fruit() {
      x = 0;
      y = 0;
      collected = false;
    }

    //Getter for collected value.
    bool has_been_collected() {
      return collected;
    }

    //Gets x-coordinate.
    int get_x() const {
      return x;
    }

    //Gets y-coordinate.
    int get_y() const {
      return y;
    }

    //Initializes the Fruit's initial coordinates for each level.
    void initialize(int x_arg, int y_arg) {
      x = x_arg;
      y = y_arg;
    }

    //Sets x-coordinate.
    void set_x(int x_arg) {
      x = x_arg;
    }

    //Sets y-coordinate.
    void set_y(int y_arg) {
      y = y_arg;
    }

    //Sets collected variable to true.
    void has_been_picked() {
      collected = true;
    }

    //Draws the Fruit.
    void draw(Color fruit_color) {
      draw_with_rgb(fruit_color); 
    }
    
    //Draws black where the Fruit used to be.
    void erase() {
      draw_with_rgb(BLACK);
    }

private:
  int x;
  int y;
  bool collected;

  //Goes through Fruit array to draw in corresponding pixels.
  void draw_with_rgb(Color color) {
    String fruit_array[1][1] = {"*"};
      for(int row = 0; row < SIZE; row++) {
        for(int col = 0; col < SIZE; col++) {
          if(fruit_array[col][row] == "*") {
            matrix.drawPixel(x + row, y + col, color.to_333());
          }
        }
      }
  }
};

//Definition of the Game class.
class Game {
  public:
    Game() {
      level = 1;
      time = 0;
    }

    //Sets up maze.
    void maze_setup() {
      matrix.fillScreen(BLACK.to_333());
      
      for(int row = 0; row < SIZE_ROW; row++) {
        for(int col = 0; col < SIZE_COL; col++) {
          if(maze_array[row][col] == 0) {
            matrix.drawPixel(col, row, BLUE.to_333());
          }
        }
      }
    }

    //This is the collection function, assumedly. Let it werk, Mama!
    void fruit_collection(Fruit fruit) {
      if(player.get_x() == fruit.get_x() && player.get_y() == fruit.get_y()) {
        if(fruit.has_been_collected() == false && time > 0) {
          fruit.has_been_picked();
          time -= 5000;
        }
      }
    }

    //Draws clock.
    void clock_setup() {
      for(int row = 0; row < 4; row++) {
        for(int col = 28; col < 32; col++) {
          matrix.drawPixel(col, row, WHITE.to_333());
        }
      }
    }
    
    //Countdown for clock
    void clock_countdown() {
      if(time % 5000 == 0) {
        matrix.drawPixel(31, 0, BLACK.to_333());
        matrix.drawPixel(31, 1, BLACK.to_333());
        matrix.drawPixel(30, 0, BLACK.to_333());
        matrix.drawPixel(30, 1, BLACK.to_333());       
      }
      if(time >= 10000) {
        matrix.drawPixel(31, 2, BLACK.to_333());
        matrix.drawPixel(31, 3, BLACK.to_333());
        matrix.drawPixel(30, 2, BLACK.to_333());
        matrix.drawPixel(30, 3, BLACK.to_333());
      }
      if(time >= 15000) {
        matrix.drawPixel(29, 2, BLACK.to_333());
        matrix.drawPixel(29, 3, BLACK.to_333());
        matrix.drawPixel(28, 2, BLACK.to_333());
        matrix.drawPixel(28, 3, BLACK.to_333());
      }
      if(time >= 20000) {
        matrix.drawPixel(29, 0, BLACK.to_333());
        matrix.drawPixel(29, 1, BLACK.to_333());
        matrix.drawPixel(28, 0, BLACK.to_333());
        matrix.drawPixel(28, 1, BLACK.to_333());
      } 
      if(time >= 21000) {
        player.erase();
        game_over();
       }
    }
     
    void setup() {
        //Printing starting values for player
        matrix.setTextSize(1);
        print_opening();
        delay(2000);
        matrix.fillScreen(BLACK.to_333());
        print_level(1);
        delay(2000);
        matrix.fillScreen(BLACK.to_333());
        print_lives(3);
        delay(2000);
      
        maze_setup();

        player.initialize(1, 0);
        player.draw();
        
        orange.initialize(19, 14);
        orange.draw(ORANGE);
        
        cherry.initialize(9, 14);
        cherry.draw(RED);
        
        passionfruit.initialize(1, 14);
        passionfruit.draw(FUSCHIA);

        clock_setup();
        clock_time = millis();
    }
    
    void update(int potentiometer_value, int potentiometer_y) {
      time = millis();
      player.erase();
      player.set_x(potentiometer_value / 32); 
      player.set_y(potentiometer_y / 16);
      player.draw();
     
      if(maze_array[player.get_y()][player.get_x()] != 0) {
        player.erase();
        player.set_x((potentiometer_value / 32) - 1); 
        player.set_y((potentiometer_y / 16) - 1);
        player.draw();
        matrix.drawPixel(potentiometer_value, potentiometer_y, BLUE.to_333());
      }
      clock_countdown();
    }
      
      bool get_level_cleared() {
        return level_cleared();
      }

private:
  int level;
  unsigned long time;
  unsigned long now;
  Player player;
  Fruit orange;
  Fruit cherry;
  Fruit passionfruit;
  bool clock_array[4][4] {
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0}};
  unsigned long clock_time;
  
  bool level_cleared() {
  }
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

  game.update(potentiometer_value, potentiometer_y);
}

// Displays the opening message.
void print_opening() {
  matrix.print("Munch Maize");
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
  matrix.fillScreen(BLACK.to_333());
  matrix.print("Game Over!");
  delay(1000);
}
