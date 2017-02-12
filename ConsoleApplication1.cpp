// ConsoleApplication1.cpp : Defines the entry point for the console
// application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int RNG(int max, int min) {
  srand(time(NULL));
  int ran = rand() % (max - min + 1) + min;
  return ran;
}

void firstrun()

{
  cout << '\t' << "3 en Ralla 1.0" << '\n';
  cout << "Este sera el sistema de coordenadas usado para el tablero: " << '\n';
  cout << '\t' << "  1 " << '\t' << "  2 " << '\t' << "  3 " << '\n';
  cout << " 3 "
       << "    " << '\t' << "|   |" << '\t' << "|   |" << '\t' << "|   |"
       << '\n';
  cout << " 2 "
       << "    " << '\t' << "|   |" << '\t' << "|   |" << '\t' << "|   |"
       << '\n';
  cout << " 1 "
       << "    " << '\t' << "| x |" << '\t' << "|   |" << '\t' << "|   |"
       << '\n';
  cout << "la cruz esta en el 1,1 " << '\n' << '\n' << '\n';
}

char sqr[4][4] = {{' ', ' ', ' ', ' '},
                  {' ', ' ', ' ', ' '},
                  {' ', ' ', ' ', ' '},
                  {' ', ' ', ' ', ' '}};

void board() {
  cout << "    " << '\t' << "| " << sqr[1][1] << " |" << '\t' << "| "
       << sqr[2][1] << " |" << '\t' << "| " << sqr[3][1] << " |" << '\n';
  cout << "    " << '\t' << "| " << sqr[1][2] << " |" << '\t' << "| "
       << sqr[2][2] << " |" << '\t' << "| " << sqr[3][2] << " |" << '\n';
  cout << "    " << '\t' << "| " << sqr[1][3] << " |" << '\t' << "| "
       << sqr[2][3] << " |" << '\t' << "| " << sqr[3][3] << " |" << '\n' << '\n'
       << '\n';
}

bool won() {
  if (sqr[1][1] == sqr[1][2] && sqr[1][2] == sqr[1][3] && sqr[1][3] != ' ')
    return 1;
  else if (sqr[2][1] == sqr[2][2] && sqr[2][2] == sqr[2][3] && sqr[2][3] != ' ')
    return 1;
  else if (sqr[3][1] == sqr[3][2] && sqr[3][2] == sqr[3][3] && sqr[3][3] != ' ')
    return 1;
  else if (sqr[1][1] == sqr[2][1] && sqr[2][1] == sqr[3][1] && sqr[3][1] != ' ')
    return 1;
  else if (sqr[1][2] == sqr[2][2] && sqr[2][2] == sqr[3][2] && sqr[3][2] != ' ')
    return 1;
  else if (sqr[1][3] == sqr[2][3] && sqr[2][3] == sqr[3][3] && sqr[3][3] != ' ')
    return 1;
  else if (sqr[1][1] == sqr[2][2] && sqr[2][2] == sqr[3][3] && sqr[3][3] != ' ')
    return 1;
  else if (sqr[1][3] == sqr[2][2] && sqr[2][2] == sqr[3][1] && sqr[3][1] != ' ')
    return 1;
  else
    return 0;
}

bool draw() {
  while (1) {
    int x(1);
    int y(1);
    while (x <= 3) {
      if (sqr[x][y] != ' ') {
        y++;
        if (y == 4) {
          x++;
          y = 1;
          if (x == 4) return 1;
        }
      } else
        return 0;
    }
  }
}

int main() {
  firstrun();
  int x;
  int y;
  for (int player = 1; player < 3; player++) {
    board();
    cout << "Es el turno del jugador " << player << endl;
    cout << "introduzca la coordenada x " << endl;

    cin >> x;
    cout << "introduzca la coordenada y " << endl;
    cin >> y;

    while (sqr[x][y] != ' ') {
      cout << "Introdujo un valor incorrecto" << endl;
      cout << "introduzca la coordenada x " << endl;

      cin >> x;
      cout << "introduzca la coordenada y " << endl;
      cin >> y;
    }

    if (player == 1) {
      sqr[x][y] = 'X';
    } else {
      sqr[x][y] = 'O';
      player = 0;
    }

    if (won()) {
      cout << "El jugador " << player << " gano la partida" << endl;
      memset(sqr, ' ', sizeof(sqr));
    }

    if (draw()) {
      cout << "El juego termino en empate " << endl;
      memset(sqr, ' ', sizeof(sqr));
    }
  }

  return 0;
}
