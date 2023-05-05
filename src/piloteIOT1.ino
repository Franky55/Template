/**
 * @file piloteIOT1.ino
 * @author CamFo Camille Fortin (camfortin2022@gmail.com)
 * @brief Pilote qui contrôle la broche d'un microcontrôleur en utilisant
 *  la librairie Arduino. (digitalWrite et pinMode)
 * 
 * @version 0.1
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
//piloteIOT1:
//Historique: 
// 2021-04-07, Yves Roy, creation

//INCLUSIONS
#include <Arduino.h>
#include "main.h"
#include <Adafruit_NeoPixel.h>
#include "piloteIOT1.h"

//Definitions privees
//pas de definitions privees

//Declarations de fonctions privees:
//pas de fonctions privees

//Definitions de variables privees:
//pas de variables privees

//Definitions de fonctions privees:
//pas de fonctions privees

//Definitions de variables publiques:
//pas de variables publiques

//Definitions de fonctions publiques:

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        48 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 1 // Popular NeoPixel ring size
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.


#define DELAYVAL 5 // Time (in milliseconds) to pause between pixels

/**
 * @brief Fonction qui met a 5V la broche \ref PILOTEIOT1_BROCHE du microcontrôleur 
 * 
 */
void piloteIOT1_metAUn(void)
{
  digitalWrite(PILOTEIOT1_BROCHE, HIGH);
}
/**
 * @brief Fonction qui met a 0V la broche \ref PILOTEIOT1_BROCHE du mirocontrôleur
 * 
 */
void piloteIOT1_metAZero(void)
{
  digitalWrite(PILOTEIOT1_BROCHE, LOW);
}
/**
 * @brief Fonciton qui met la broche \ref PILOTEIOT1_BROCHE du mirocontrôleur
 *   au niveau passé en paramètre: 1 ou 0
 * 
 * @param Niveau 
 */
void piloteIOT1_metA(int i)
{
  pixels.setPixelColor(0, pixels.Color(i, 10, 255-i));

    pixels.show();   // Send the updated pixel colors to the hardware.
}
/**
 * @brief Fonction d'initialisation de la broche \ref PILOTEIOT1_BROCHE
 *  du mirocontrôleur. Met la broche du microcontrôleur en sortie et assigne
 *  sa valeur initial selon la définition \ref PILOTEIOT1_ETAT_INITIAL_A_ZERO
 *  ou \ref PILOTEIOT1_ETAT_INITIAL_A_UN.
 * 
 */
void piloteIOT1_initialise(void)
{
  pinMode(PILOTEIOT1_BROCHE,OUTPUT);
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)

#ifdef PILOTEIOT1_ETAT_INITIAL_A_UN
	digitalWrite(PILOTEIOT1_BROCHE,HIGH);	
#endif

#ifdef PILOTEIOT1_ETAT_INITIAL_A_ZERO
	digitalWrite(PILOTEIOT1_BROCHE,LOW);
#endif
}
