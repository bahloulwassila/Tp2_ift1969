# Tp2_ift1969
PARTIE I (20 points): 

Méthode de Newton-raphson pour estimer une racine de la fonction f(x) :
Soit  X0, une première estimation de la racine, celle-ci doit être suffisamment proche de la racine pour que la méthode converge. 

On détermine les Xn selon la formule suivante :

Xn =  Xn-1 – f(Xn-1)/f’(Xn-1)   pour n>=1

Conditions d’arrêt : 

•	Si  | Xn -  Xn-1|  < EPSILON alors Xn est le résultat de l’estimation de la racine

•	Si n > MAX_ITER  alors la méthode diverge ou n’a pas la convergence assez rapide pour fournir un résultat.

•	Si  f’(Xn-1)= 0, il y aura division par zéro.

Faites exécuter la méthode pour 
fx = x4 + 0,8x3 – 0,3x2 -1,9x +0,4 
f’x = 4x3 + 2,4x2 – 0,6x – 1,9
avec valeur de départ x0 = 0,25
nombre maximum d’itérations = 100 et EPSILON = 10-10.

Critères de correction du numéro 1
Bon fonctionnement	 10 points
Fonction fx	 4 points
Fonction f’x	 4 points
Qualité de la présentation	 2 point

 
PARTIE II (15 points) :

Le fichier tp2num2.c contient le programme, à compléter, qui déclare et remplit 2 tableaux pente et ordOrig. 
Les droites sont définies par l’équation Y = mX + b où m est la pente et b est l’ordonnée à l’origine.
Pour simplifier le traitement, les cas particuliers Y = constante, ainsi que X = constante ne sont pas considérés.

Vous devez compléter les fonctions suivantes dont la description est dans le code :
1.	int estPerpendiculaire(float m1, float m2)
2.	void intersection(float m1, float b1, float m2, float b2, float *x, float *y)
3.	void perpendiculaire( float m, float b ,float x, float y, float *m1, float *b1)

De plus, vous devez 
4.	Trouver et afficher l’équation de la droite qui est la plus rapprochée du point (5,2)
5.	Affichez les équations des droites qui sont parallèles à la première droite, c’est-à-dire : y=pente[0]X+ordOrig[0]. 
6.	Affichez les équations des droites perpendiculaires à la première droite, c’est-à-dire : y=pente[0]X+ordOrig[0]. 
7.	Modifiez la troisième droite des tableaux de façon à ce que celle-ci soit perpendiculaire à la première tout en passant par le point (3,0)
8.	Affichez les points d’intersections entre la première droite des tableaux et chacune des autres droites des tableaux qui ne sont pas parallèles à la première.


Critères de correction du numéro 2
Bon fonctionnement	 10 points
Réutilisation des fonctions	 4 points
Qualité de la présentation	 1 point



Qualité de la présentation
Voici les points qui seront évalués pour la qualité de la présentation pour les programmes et les résultats :
•	Indentation
•	Identificateurs significatifs
•	Commentaires
•	Lisibilité du programme et des résultats
•	Aération du code et des résultats (utilisation de ligne blanche)
•	Utilisation de fonctions 
•	Pas de variables globales
•	Variables déclarées en début de fonction
•	Initialisation explicite des variables
