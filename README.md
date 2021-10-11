# Smart Traffic Light
Smart traffic light est un système de feu de signalisation intelligent. C'est un système embarqué piloté par un microcontrolleur, le STM32F401VE. 
Nous allons simuler son fonctionnement à l'aide du logiciel proteus.

## Problématique
Il résoud la problématique de congestion routière dans les centres urbains à cause des chantiers (par exemple dans la ville de Lubumbashi/RDC) et aussi de la croissance du charroi automibile. Le plus grand problème des feux de signalisations traditionnels est qu'ils sont cadancés par une temporisation uniforme et constante, et ne tiennent pas compte de la situation des artères qui affluent vers le carrefour; et permettent par conséquent que sur une voie libre, le feu soit allumé au vert pendant que sur une voie pleine de véhicules, le feu est au rouge; cette situation favorise la congestion routière avec toutes les conséquences qui en découlent. 

## Hypothèse de solution
Smart traffic light permet de résoudre ce problème en arbitrant l'allumage des feux de signalisation selon le dégré de saturation des artères affluent vers le carrefour. Ainsi les voies les plus saturéés auront la priorité sur les voies les plus libres.


## Implémentation de la solution

### Configuration
1. Composants : 
	Dans notre système, nous avons utilisé les composants suivant:
	1. Un microcontrolleur STM32F401VE 
	2. 3 feux de signalisations 
	3. 8 Boutons Poussoir pour les quatres files qui affluent vers le carrefour. Nous aurons donc à l'entrée et à la sortie de chaque file un bouton poussoir.

```bash
$ git 
```
2. 
3. 
