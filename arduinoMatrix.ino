
#define R0 5
#define R1 8
#define R2 3
#define R3 9
#define R4 A4
#define R5 2
#define R6 A2
#define R7 A7 // TODO
#define CA A0
#define CB A1
#define CC A5
#define CD 4
#define CE A6 // TODO
#define CF 6
#define CG 7
#define CH A3

#define ROWS 8
#define COLS 8
const int row[ROWS] { R0, R1, R2, R3, R4, R5, R6, R7 };
const int col[COLS] { CA, CB, CC, CD, CE, CF, CG, CH };
int bitmap[ROWS][COLS] {
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0
};

void setup() {
  for (int x = 0; x < ROWS; x++) {
    pinMode(row[x], OUTPUT);  
    digitalWrite(row[x], LOW);
  }
  for (int x = 0; x < COLS; x++) {
    pinMode(col[x], OUTPUT);  
    digitalWrite(col[x], HIGH);
  }
}

void clear() {
  for (int x = 0; x < ROWS; x++) {
    digitalWrite(row[x], LOW);
  }
  for (int x = 0; x < COLS; x++) {
    digitalWrite(col[x], HIGH);
  }
}
void refresh(int bm[ROWS][COLS])
{
  clear();
  for (int x = 0; x < ROWS; x++) {
    for (int y = 0; y < COLS; y++) {
      if (bm[x][y] == 1) {
        digitalWrite(row[x], HIGH);
        digitalWrite(col[y], LOW);
        //delay(10);
        digitalWrite(row[x], LOW);
        digitalWrite(col[y], HIGH);
      }
    }
  }
}

int count = 0;
int tick = 0;
// the loop function runs over and over again forever
void loop() {
  count += 1;
  if (count%100 == 0) {
    *(&bitmap[0][0] + tick) = (*(&bitmap[0][0] + tick) == 1) ? 0 : 1;
    tick += 1; 
  }
  if (tick >= ROWS*COLS) {
    tick = 0;
  }
  refresh(bitmap);
}


