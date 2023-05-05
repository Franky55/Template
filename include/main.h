/**
 * @file xmain.h
 * @author Francis Gratton 
 * 
 * @brief Le fichier xmain.h est nécessaire pour les includions global qui
 *   contien les defines essentiel au fonctionnement. Le processeur utilisé
 *  pour la gestion du véhicule est un ESP32-S3. Voir le document de projet
 *  pour plus d'information sur le fonctionnement.
 *      
 *  Le programme suivant fonctionne avec une base de temps et des machine d'état.
 * 
 *   
 * @version 0.0.1
 * @date 2023-05-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef MAIN_H
#define MAIN_H

//PROGRAMME: Batiscan
//DESCRIPTION: programme qui va permettre le bon fonctionnement d'un sous-marin

//HISTORIQUE:
/* Historique du programme gèrer par git et publier sur github au lien suivant
*
*       https://github.com/Franky55/Template
*/
  
//  *** INFORMATION PUBLIQUE ***


//DEFINITIONS REQUISES PAR LE MODULE:
//Dependances materielles:


/***  DÉFINITION POUR LES SERVOS MOTEURS  ***/

//Les pins utilisés
#define SERVO1 9



//Pin utilisé pour la communication I2C
#define I2C_SDA 7
#define I2C_SCL 8


//Utlisation de la LED Neopixel
#define NEOPIXEL  48
#define NUMPIXELS 1 


/***  DÉFINITION NÉCESSAIRE À LA BASE DE TEMPS  ***/
/**
 * @brief Période en microsecondes à laquelle le TaskServer exécute sa fonction 
 *  qui fait apelle au service Base de temps pour gêrer plusieur tache a la fois
 * 
 */
#define SERVICETASKSERVER_PERIODE_EN_US (1000L)
/**
 * @brief Fréquence en Hz de la base de temps
 * 
 */
#define SERVICEBASEDETEMPS_FREQUENCE_EN_HZ 1000
/**
 * @brief Nombre de phase dans une période de la base de temps (1 si pas utilisé)
 */
#define SERVICEBASEDETEMPS_NOMBRE_DE_PHASES_DANS_LOOP 1
/**
 * @brief Nombre de phase de la base de temps \ref xserviceBaseDeTemps.h
 * 
 */
#define SERVICEBASEDETEMPS_NOMBRE_DE_PHASES 3




/**
 * @brief Numéro de phase du processus clignotant
 */
#define PROCESSUSCLIGNOTANT_PHASE 0

/**
 * @brief Numéro de phase du processus Controle
 */
#define PROCESSUSCONTROLE_PHASE 1

/**
 * @brief Numéro de phase du processus PWM
 */
#define PROCESSUSPWM_PHASE 2



#define PROCESSUSCLIGNOTANT_TEMPS_ALLUME_EN_MS 5
#define PROCESSUSCLIGNOTANT_TEMPS_ETEINT_EN_MS 500


#endif