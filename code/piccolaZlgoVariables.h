//#include <QueueArray.h>

byte x=0;
byte y=0;

byte xprev=0;
byte yprev=0;
byte orient=0;
byte state=0;
boolean shortPath= false;
byte x_0;
byte y_0;
byte x_1;
byte y_1;
byte x_2;
byte y_2;
byte x_3;
byte y_3;
byte mazeSize = 16;
char dir;
char turning;
//QueueArray <byte> queue;
boolean  L = true;
boolean  R= true;
boolean  F= false; 
byte xdes;
byte ydes;
unsigned long timer;


byte cells[14][14] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0}};

byte flood2[14][14] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0}};

byte flood[14][14]={{12,11,10,9,8,7,6,6,7,8,9,10,11,12},
        {11,10,9,8,7,6,5,5,6,7,8,9,10,11},
        {10,9,8,7,6,5,4,4,5,6,7,8,9,10},
        {9,8,7,6,5,4,3,3,4,5,6,7,8,9},
        {8,7,6,5,4,3,2,2,3,4,5,6,7,8},
        {7,6,5,4,3,2,1,1,2,3,4,5,6,7},
        {6,5,4,3,2,1,0,0,1,2,3,4,5,6},
        {6,5,4,3,2,1,0,0,1,2,3,4,5,6},
        {7,6,5,4,3,2,1,1,2,3,4,5,6,7},
        {8,7,6,5,4,3,2,2,3,4,5,6,7,8},
        {9,8,7,6,5,4,3,3,4,5,6,7,8,9},
        {10,9,8,7,6,5,4,4,5,6,7,8,9,10},
        {11,10,9,8,7,6,5,5,6,7,8,9,10,11},
        {12,11,10,9,8,7,6,6,7,8,9,10,11,12}};

byte sliit[14][14] ={{11,11,11,11,14,10,12,5,6,5,4,10,10,12},
                    {9,9,9,8,10,4,10,3,9,9,8,10,12,11},
                    {1,3,8,10,4,7,5,3,13,9,14,4,10,3},
                    {9,8,10,10,15,10,7,1,10,7,11,9,5,3},
                    {1,4,4,4,7,5,10,7,5,4,2,2,7,9},
                    {9,13,9,1,10,3,5,10,3,9,5,4,4,9},
                    {1,4,7,9,11,9,1,6,9,1,7,9,9,9},
                    {9,9,14,7,9,9,8,7,9,1,10,7,9,9},
                    {13,8,10,10,7,8,10,10,3,8,10,10,3,9},
                    {11,11,11,14,6,11,11,5,2,4,12,5,2,7},
                    {9,9,8,6,9,1,15,3,14,15,4,15,10,6},
                    {9,1,10,3,9,9,13,1,12,9,13,8,6,9},
                    {9,8,12,1,3,1,4,15,10,3,5,10,7,9},
                    {8,10,10,7,8,7,13,13,11,13,13,5,10,7}};

char bluetoothWalls;
byte xrun=0;
byte yrun=0;
  
