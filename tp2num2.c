/*
    nom 1 : BAHLOUL Wassila
    matricule 1 : 20183065

*/

#include <math.h>
#include <stdio.h>

#define MAX_DROITE 20
#define PRECISION 0.00001 /*Definir une constante de précision*/


/* Pour afficher les coordonnées d'un point */
void affichePoint(float x, float y){
    printf("(%7.3f,%7.3f )\n",x,y);
}


/* Pour afficher l'équation de la droite */
void afficheDroite(float m, float b)
{
    printf("Y = %8.4fX + %8.4f\n", m, b);
}

/* retourne la valeur de Y d'une droite Y = mX + b ou
   X est connu */
float yDeDroite( float m, float b, float x){
    return b + m * x;
}

/* retourne la valeur de X d'une droite Y = mX + b ou
   Y est connu */
float xDeDroite( float m, float b, float y){
    return (y - b)/m;
}

float absolue(float a) {
	return a<0?-a:a;   /* si a est négatif on retourne -a sinon a */
}


int estParallele(float m1, float m2) {
	float diff;

	diff = absolue(m1 - m2);  /* La différence en valeur absolue entre les pentes */

	if(diff>=PRECISION)            /* est ce que la différence est significative */
		return 0;                  /* si oui, pas parallele */
	else return 1;                 /* si non, on cosidere parallele */
}


/* Cette fonction calcule la différence en valeur absolue entre la pente m1 */
/* et -1/(pente m2). Si la différence (en valeur absolue) est significative */
/* (plus grande que PRECISION) elles ne sont pas perpendiculaire (retourne 0)  */
/* sinon, on les considere perpendiculaires et on retourne 1*/
int estPerpendiculaire(float m1, float m2)

{
	int diff;

	if(m2 == 0) /*Vérifier que m2 est différent de 0 pour faire la division*/
		return 0;

	diff = absolue(m1-(-1/m2)); /* Calcule la différence en valeur absolue entre la pente m1 et -1/(pente m2)*/

	if(diff >= PRECISION) /*Si la différence (en valeur absolue) est significative (plus grande que PRECISION)*/
		return 0; /*Elles ne sont pas perpendiculaires(retourne 0)*/
	else
		return 1; /*Elles sont perpendiculaire (retourne 1)*/
}


/* Cette fonction calcule les valeurs x et y du point qui résout le système
   d'équation suivant :
   Y = m1 X + b1
   Y = m2 X + b2

  Le point (X,Y) est ensuite transmis par pointeurs
*/

void intersection(float m1, float b1 ,float m2, float b2, float *x, float *y) {
	if(m1 == m2) { /*Si la pente m1 et la pente m2 sont egales alors les droites sont parallèles, donc pas de point d'intersections*/
		*x = 0.0;
		*y = 0.0;
	} else { /* Dans le cas contraire un point d'intersection existe*/

		*x = (b2 -b1) / (m1 - m2); /* *x est l'abscisse de l'intersection*/
		*y = m1 * (*x) + b1; /* *y est l'ordonnée du point de l'intersection*/
	}
}


/*
Cette fonction calcule la droite qui est perpendiculaire à Y=mX+b ( pente = -1/m)
et passe par le point (x,y). La droite est transmise par pointeurs
*/
void perpendiculaire( float m, float b ,float x, float y, float *m1, float *b1)
{
    if(m == 0) {
        
        return;
    }
    
    else{
        
        *m1 = -1 / m;
        *b1 = y - (*m1 * x);
    }
}
 

/* Calcul de la distance entre 2 points */
double distancePoints(float x1, float y1, float x2, float y2) {
	float x2moinsx1= x2-x1;
	float y2moinsy1= y2-y1;
	return sqrt( x2moinsx1 * x2moinsx1 + y2moinsy1 * y2moinsy1 );
}

/* Calcul de la distance entre un point et une droite */
double distancePtDroite(float m, float b ,float x, float y) {

	float xPlusPres, yPlusPres;
	float mPerpen, bPerpen;
	
	perpendiculaire( m,b, x,y, &mPerpen, &bPerpen);

    intersection(m,b,mPerpen,bPerpen,&xPlusPres, &yPlusPres);

	return distancePoints(x,y, xPlusPres, yPlusPres);
}



int main() {
	float pente[MAX_DROITE]= {  1, 3.313253, -0.934783, 4, 1, -1, -2.07, 2.0/3};

	float ordOrig[MAX_DROITE]= {  1, -0.906627, 4.243479, -3.2, 0, 2, 9.51, -1.0/3};
	int i, nbDroite=8;
	float xPoint = 5, yPoint = 2;
	float distanceMin = INFINITY;
	int indicePlusProche = -1;

	printf("Les droites du tableau\n");

	printf("\nLes droites paralleles a la premiere droite:\n");
	for(i=0; i<nbDroite; i++) {
		if (estParallele(pente[0], pente[i])) {
			afficheDroite(pente[i],ordOrig[i]);
		}
	}

	printf("\nLes droites perpendiculaires a la premiere droite:\n");
	for (i = 1; i < nbDroite; i++) {
		if (estPerpendiculaire(pente[0], pente[i])) {
			afficheDroite(pente[i], ordOrig[i]);
		}
	}

	float m1, b1; 

	perpendiculaire(pente[0], ordOrig[0], 3.0, 0.0, &m1, &b1);


	pente[2] = m1;
	ordOrig[2] = b1;


	printf("La nouvelle equation de la troisieme droite est: ");
	afficheDroite(pente[2], ordOrig[2]);

	for (i = 0; i < nbDroite; i++) {
		float distance = distancePtDroite(pente[i], ordOrig[i], xPoint, yPoint);
		if (distance < distanceMin) {
			distanceMin = distance;
			indicePlusProche = i;
		}
	}

	printf("\nLes points d'intersections de la premiere droite avec les autres droites (qui ne sont pas paralleles):\n");
	for (i = 1; i < nbDroite; i++) {
		if (!estParallele(pente[0], pente[i])) { 
			float xIntersect, yIntersect;
			intersection(pente[0], ordOrig[0], pente[i], ordOrig[i], &xIntersect, &yIntersect);
			printf("Intersection avec la droite %d: ", i + 1);
			affichePoint(xIntersect, yIntersect);
		}
	}

	if (indicePlusProche >= 0) { 
		printf("\nLa droite la plus rapprochee du point (5,2) est :\n");
		afficheDroite(pente[indicePlusProche], ordOrig[indicePlusProche]);
	} else {
		printf("\nAucune droite n'a ete trouvee.\n");
	}

	system("pause");
	return 0;
}
