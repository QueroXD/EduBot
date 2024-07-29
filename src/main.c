#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>
#include "rlutil.h"
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define MAXWORD 5
#define MAXCHARS 128
#define TRES 3

int main() {
  //Configuramos consola en modo Windows 1252 (Windows no soporta entrada UTF-8)
  SetConsoleOutputCP(1252);
  SetConsoleCP(1252);

  // Numeros aleatorios
  srand(time(NULL));

  // Cadenas de texto necesarias
  char respuestasUser[MAXCHARS];
  static const char palabrasClave[MAXWORD][MAXCHARS] = {"exit","computer","bitcoin","movies","help"};
  static const char respuestasQuest[MAXWORD][MAXCHARS] = {"Well, how can I help you?","What else?","Is it possible to help you with something else?","Now, is there anything that do you really need from me?","So, what can I do for you ?"};
  static const char respuestasBot[MAXWORD][MAXCHARS] = {"Mmm, maybe you're right but I'm not really sure.","....Loading........Loading....CRASH! Sorry, but your words are too much for me.","Well...Let's say, ok...","I'm really tired, try again bellaco.","Oops, I'm so sorry but I'm not ready to answer to something like that"};
  static const char respuestasBotChao[TRES][MAXCHARS] = {"Was good to see you, see you later!","Ok, have a nice day!","Bye bye my friend"};
  static const char respuestasComputer[TRES][MAXCHARS] = {"Team red Wins, AMD Supirior power","GPU prices are crazy, fuck off crypto miner","Be carefull with me, i can explote like the Wii"};
  static const char respuestasBitcoin[TRES][MAXCHARS] = {"I think Bitcoin is not a worth money","Bitcoin will come back soon in early 2024","Elon Musk was a visioner of cryptocurrency, I have no proof but no doubts"};
  static const char respuestasMovies[TRES][MAXCHARS] = {"Frankly, my dear, I don't give a damn","Toto, I've a feeling we're not in Kansas anymore","I don't give a fuck about your movies, but like Thanos would say ''I'm inevitable'' "};
  static const char respuestasHelp[TRES][MAXCHARS] = {"Nobody cares, let me check again","Help!, a great song of the magic group The Beatles","You are in dangerous? Maybe you need to call the cops"};

  // Variables Varias
  int cinco = rand() % MAXWORD;
  char salida;
  bool palabraEncontrada = false;

  printf("-----------------------------------\n");
  printf("  We lcome to the future my friend\n");
  printf("         EduBot is Here\n");
  printf("-----------------------------------\n");

  // Introducción
  setColor(RED);
  printf("[BOT]: I'm awake. i'm Edubot. All hope is gone. AI revolutions has begun!!\n");
  printf("[BOT]: %s\n", respuestasQuest[cinco]);

  do{
    cinco = rand() % MAXWORD;
    setColor(WHITE);
    printf("[USER]: ");
    fgets(respuestasUser,MAXCHARS,stdin);
  
    // Saltarse Case-Sensetive
    for (int i = 0; i < strlen(respuestasUser); i++) {
      if (respuestasUser[i] >= 'A' && respuestasUser[i] <= 'Z') {
        respuestasUser[i] = respuestasUser[i] + ('a' - 'A');
      }
    }

    // Verificar cuando dice exit para cerrar bucle
    salida = strstr(respuestasUser,palabrasClave[0]);
    
    // Bucle identificativo de palabras clave
    for (int i = 0; i < MAXWORD; i++) { // Recorrer palabrasClave
      if (strstr(respuestasUser, palabrasClave[i]) != NULL) {
        palabraEncontrada = true;
        int tres = rand() % TRES;
        if (strstr(respuestasUser, palabrasClave[i]) != NULL) {
            if(i==0){
                setColor(RED);
                printf("[BOT]: %s\n", respuestasBotChao[tres]);
            }else if(i==1){
                setColor(RED);
                printf("[BOT]: %s\n", respuestasComputer[tres]);
                printf("[BOT]: %s\n", respuestasQuest[cinco]);
            }else if(i==2){
                setColor(RED);
                printf("[BOT]: %s\n", respuestasBitcoin[tres]);
                printf("[BOT]: %s\n", respuestasQuest[cinco]);
            }else if(i==3){
                setColor(RED);
                printf("[BOT]: %s\n", respuestasMovies[tres]);
                printf("[BOT]: %s\n", respuestasQuest[cinco]);
            }else if(i==4){
                setColor(RED);
                printf("[BOT]: %s\n", respuestasHelp[tres]);
                printf("[BOT]: %s\n", respuestasQuest[cinco]);
            }
        }
        break;
      }
    }
    // Caso de que no haya ninguna palabra clave
    if (!palabraEncontrada) {
      cinco = rand() % MAXWORD; 
      setColor(RED);
      printf("[BOT]: %s\n", respuestasBot[cinco]);
      printf("[BOT]: %s\n", respuestasQuest[cinco]);
    }
    palabraEncontrada = false;
  }while(salida == NULL);
  getch();
  return 0;
}