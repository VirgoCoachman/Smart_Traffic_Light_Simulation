# Smart Traffic Light
Smart traffic light est un système de feu de signalisation intelligent. C'est un système embarqué piloté par un microcontrolleur, le STM32F401VE. 
Nous allons simuler son fonctionnement à l'aide du logiciel proteus.

## Problématique
Il résoud la problématique de congestion routière dans les centres urbains à cause des chantiers (par exemple dans la ville de Lubumbashi/RDC) et aussi de la croissance du charroi automibile. Le plus grand problème des feux de signalisations traditionnels est qu'ils sont cadancés par une temporisation uniforme et constante, et ne tiennent pas compte de la situation des artères qui affluent vers le carrefour; et permettent par conséquent que sur une voie libre, le feu soit allumé au vert pendant que sur une voie pleine de véhicules, le feu est au rouge; cette situation favorise la congestion routière avec toutes les conséquences qui en découlent. 

## Hypothèse de solution
Smart traffic light permet de résoudre ce problème en arbitrant l'allumage des feux de signalisation selon le dégré de saturation des artères affluent vers le carrefour. Ainsi les voies les plus saturéés auront la priorité sur les voies les plus libres.


## Implémentation de la solution

### Installation
1. Composants : 
	Dans notre système, nous avons utilisé les composants suivant:
	1. Un microcontrolleur STM32F401VE 
	2. 3 feux de signalisations 
	3. 8 Boutons Poussoir pour les quatres files qui affluent vers le carrefour. Nous aurons donc à l'entrée et à la sortie de chaque file un bouton poussoir.


2. Outils logiciels:
	1. STM32CubeIDE : C'est un IDE basé sur Eclipse qui facilite la configuration rapide d'un projet de système embarqué impliquant le microcontrolleur STM32
	2. Proteus 8.10 : Pour la simulation du fonctionnement de notre système

3. Installation proprement dite: 
	1. Cloner le projet en local : 
	```bash
	$ git clone https://github.com/VirgoCoachman/Smart_Traffic_Light_Simulation.git
	```
	2. Importer le projet dans l'environnement de développement STM32CubeIDE
	3. Générer l'exécutable (.hex) dans STM32CubeIDE
	4. Importer le fichier de montage **Trafic light.pdsprj** dans Proteus (pour ce projet la version utilisée est 8.10)
	5. Charger l'exécutable (.hex) généré au point 3 dans le board STM32F401VE sur le schéma dans proteus
	6. Lancer la simulation

4. Pour plus de détails voir : 
	1. Vidéo de simulation : [Google Drive](https://drive.google.com/file/d/1TxdAAeFna5Uit1mHO1axUHQ4DzYOFiNA/view?usp=sharing) (à ouvrir avec un compte gmail d'Ecole Supérieure d'Informatique Salama ***ESIS***)
	2. Compte rendu
