//
//  main.cpp
//  Munch Maize Debug
//
//  Created by Tyler Warner on 4/18/18.
//  Copyright © 2018 Tyler Warner. All rights reserved.
//

#include <iostream>
using namespace std;

//#include <gamma.h>
//#include <RGBmatrixPanel.h>
//#include <Adafruit_GFX.h>

//Global constants for the maze sizes.
const int SIZE_COL = 28;
const int SIZE_ROW = 16;


const bool maze_array[SIZE_ROW][SIZE_COL] {
    {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,0},
    {0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,0,0,1,0},
    {0,1,0,1,1,1,0,1,1,1,1,0,1,1,1,1,0,0,0,1,0,1,0,1,0,1,1,0},
    {0,1,1,1,0,1,0,1,0,0,0,0,0,0,0,1,1,1,0,1,0,1,1,1,0,1,0,0},
    {0,0,0,1,0,1,0,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0,1,1,0},
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

int main() {
    for(int i = 0; i < SIZE_ROW; i++) {
        for(int j = 0; j < SIZE_COL; j++) {
            cout << maze_array[i][j] << " ";
        }
    }
    
    
   /* player.erase();
    
    if(counter % 500 == 0) {
        if(potentiometer_y < 312) {
            if(maze_test[player.get_x()][player.get_y() - 1] == true) {
                player.set_y(player.get_y() - 1);
            }
        }
        if(potentiometer_y > 712) {
            if(maze_test[player.get_x()][player.get_y() + 1] == true) {
                player.set_y(player.get_y() + 1);
            }
        }
        if(potentiometer_x < 312) {
            if(maze_test[player.get_x() - 1][player.get_y()] == true) {
                player.set_x(player.get_x() - 1);
            }
        }
        if(potentiometer_x > 712) {
            if(maze_test[player.get_x() + 1][player.get_y()] == true) {
                player.set_x(player.get_x() + 1);
            }
            //maze_test[3][4] = false;
            if (maze_test[3][4] == false) {
                player.set_x(player.get_x() - 1);
            }
        }
    }
    
    player.draw(); */
    
    return 0;
}

/*//Defines the wiring to the LED screen.
const uint8_t CLK  = 8;
const uint8_t LAT = A3;
const uint8_t OE = 9;
const uint8_t A = A0;
const uint8_t B = A1;
const uint8_t C = A2;

//Define the wiring to the inputs.
const int POTENTIOMETER_PIN_NUMBER = 5;
const int POTENTIOMETER_PIN_Y = 4;

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
    {0,0,0,1,0,1,0,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0,1,1,0},
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

//Test maze.
const bool maze_test[5][5] {
    {0,1,0,0,0},
    {0,1,1,1,0},
    {0,1,0,1,0},
    {0,1,0,1,1},
    {0,0,0,0,0}};

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
const Color BROWN(0, 7, 3);

//Definition for the Player class.
class Player {
public:
    Player() {
        x = 1;
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
    
    // sets private data members x and y to initial values
    void initialize(int x_arg, int y_arg) {
        x = x_arg;
        y = y_arg;
    }
    
    //Sets x-coordinate.
    void set_x(int x_arg) {
        if(x_arg > 0 && x_arg < 32) {
            x = x_arg;
        }
        else {
            if(x_arg <= 0) {
                x = 1;
            }
            if(x_arg > 26) {
                x = 26;
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
                y = 1;
            }
            if(y_arg > 15) {
                y = 14;
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
    
    //Player move function.
    int move(int move_val) {
        //Moves the Player right.
        if (move_val == 1) {
            return x += 1;
        }
        //Moves the Player left.
        if(move_val == 2) {
            return x -= 1;
        }
        //Moves the Player down.
        if (move_val == 3) {
            return y += 1;
        }
        //Moves the Player up.
        if(move_val == 4) {
            return y -= 1;
        }
    }
    
private:
    int x;
    int y;
    int lives;
    
    //Goes through the Player array to draw in corresponding pixels.
    void draw_with_rgb(Color color) {
        char player_array[1][1] = {'*'};
        for (int row = 0; row < 1; row++) {
            for (int col = 0; col < 1; col++) {
                if (player_array[col][row] == '*') {
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

//Definition of the Bird class.
class Bird {
public:
    Bird() {
        x = 0;
        y = 0;
    }
    
    //Gets x-coordinate.
    int get_x() const {
        return x;
    }
    
    //Gets y-coordinate.
    int get_y() const {
        return y;
    }
    
    
    //Initializes the Bird's initial coordinates for each level.
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
    
    //Draws the Bird.
    void draw() {
        draw_with_rgb(BROWN);
    }
    
    //Draws black where the Player used to be.
    void erase() {
        draw_with_rgb(BLACK);
    }
    
    void move() {
        erase();
        x++;
        draw();
    }
    /*while(x > x_arg) {
     //erase();
     x--;
     //draw();
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
        
        for(int row = 0; row < 5; row++) {
            for(int col = 0; col < 5; col++) {
                if(maze_test[row][col] == 0) {
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
    
    //Countdown for clock.
    void clock_countdown() {
        if(time >= 11000) {
            matrix.drawPixel(31, 0, BLACK.to_333());
            matrix.drawPixel(31, 1, BLACK.to_333());
            matrix.drawPixel(30, 0, BLACK.to_333());
            matrix.drawPixel(30, 1, BLACK.to_333());
        }
        if(time >= 16000) {
            matrix.drawPixel(31, 2, BLACK.to_333());
            matrix.drawPixel(31, 3, BLACK.to_333());
            matrix.drawPixel(30, 2, BLACK.to_333());
            matrix.drawPixel(30, 3, BLACK.to_333());
        }
        if(time >= 21000) {
            matrix.drawPixel(29, 2, BLACK.to_333());
            matrix.drawPixel(29, 3, BLACK.to_333());
            matrix.drawPixel(28, 2, BLACK.to_333());
            matrix.drawPixel(28, 3, BLACK.to_333());
        }
        if(time >= 26000) {
            matrix.drawPixel(29, 0, BLACK.to_333());
            matrix.drawPixel(29, 1, BLACK.to_333());
            matrix.drawPixel(28, 0, BLACK.to_333());
            matrix.drawPixel(28, 1, BLACK.to_333());
        }
        /*if(time >= 31000) {
         //player.erase();
         //see what these lines do on board
         player.die();
         matrix.fillScreen(BLACK.to_333());
         matrix.setCursor(0, 0);
         print_lives(player.get_lives());
         delay(1000);
         //game_over();
         }
    }
    
    void setup() {
        //Printing starting values for player
        matrix.setTextSize(1);
        print_opening();
        delay(2000);
        matrix.fillScreen(BLACK.to_333());
        matrix.setCursor(0, 0);
        print_level(1);
        delay(2000);
        matrix.fillScreen(BLACK.to_333());
        matrix.setCursor(0, 0);
        matrix.setTextSize(1);
        print_lives(3);
        delay(2000);
        
        maze_setup();
        
        player.initialize(1,0);
        
        orange.initialize(19, 14);
        orange.draw(ORANGE);
        
        cherry.initialize(9, 14);
        cherry.draw(RED);
        
        passionfruit.initialize(1, 14);
        passionfruit.draw(FUSCHIA);
        
        //dove.initialize(17, 1);
        //dove.draw();
        
        //counter = 0;
        
        clock_setup();
        clock_time = millis();
    }
    
    void update(int potentiometer_x, int potentiometer_y) {
        time = millis();
        
        counter++;
        
        player.erase();
        
        if(counter % 500 == 0) {
            if(potentiometer_y < 312) {
                if(maze_test[player.get_x()][player.get_y() - 1] == true) {
                    player.set_y(player.get_y() - 1);
                }
            }
            if(potentiometer_y > 712) {
                if(maze_test[player.get_x()][player.get_y() + 1] == true) {
                    player.set_y(player.get_y() + 1);
                }
            }
            if(potentiometer_x < 312) {
                if(maze_test[player.get_x() - 1][player.get_y()] == true) {
                    player.set_x(player.get_x() - 1);
                }
            }
            if(potentiometer_x > 712) {
                if(maze_test[player.get_x() + 1][player.get_y()] == true) {
                    player.set_x(player.get_x() + 1);
                }
                //maze_test[3][4] = false;
                if (maze_test[3][4] == false) {
                    player.set_x(player.get_x() - 1);
                }
            }
        }
        
        player.draw();
        
        /* while (dove.get_x() == 0) {
         for (int count = 0; count < 18; count++) {
         dove.move();
         }
         }
         while (dove.get_x() == 17) {
         for (int count = 17; count > 0; count--) {
         dove.move();
         }
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
    unsigned long counter;
    Player player;
    Fruit orange;
    Fruit cherry;
    Fruit passionfruit;
    Bird dove;
    unsigned long clock_time;
    
    bool level_cleared() {
    }
};

// a global variable that represents the game Space Invaders
Game game;

void setup() {
    Serial.begin(9600);
    matrix.begin();
    game.setup();
}


void loop() {
    int potentiometer_x = analogRead(POTENTIOMETER_PIN_NUMBER);
    int potentiometer_y = analogRead(POTENTIOMETER_PIN_Y);
    
    game.update(potentiometer_x, potentiometer_y);
}

// Displays the opening message.
void print_opening() {
    matrix.print("MunchMaize");
}

// Displays the level number.
void print_level(int level) {
    matrix.print("Level");
    matrix.print(level);
}

// Displays the number of lives.
void print_lives(int lives) {
    matrix.print("Lives");
    matrix.print(lives);
}

// Displays "Game Over!" message when player dies.
void game_over() {
    matrix.fillScreen(BLACK.to_333());
    matrix.setCursor(0, 0);
    matrix.print("Time Out!");
    delay(1000); */
//}
