// A routine for detecting a win.
// (c) 2014 Erik Kessler
#include "sokoban.h"

// Birthday for advanced biometric tracking:
int BDay[] = { /* this is Duane's: */ 12, 15, 1960 };

// Check for a win (called from play, in sokoban.c).
// Return 1 iff all the BOX locations are also STORE locations.
// Duane: Note how I'm not refering directly to any part of the opaque type l!
int win(level *l)
{
  int r,c; // Row, column looking at
  int w,h; // Width and height of the level
  char cell; // Value of the cell we are looking at

  // Set width and height
  w = width(l);
  h = height(l);

  // Check for unstored boxes
  for (r = 0; r < h; r++) {
    for (c = 0; c < w; c++) {
      cell = get(l,r,c);
      
      // If there is a box not on a store return 0 (not win)
      if ((cell & BOX) && !(cell & STORE)) return 0;
    }
  }

  // Won - highlight boxes
  for (r = 0; r < h; r++) {
    for (c = 0; c < w; c++) {
      cell = get(l,r,c);
      if ((cell & BOX)) highlight(l,r,c);
    }
  }
  return 1;
}
