/*
    nom 1 : BAHLOUL Wassila
    matricule 1 : 20183065

*/

#include <stdio.h> // Inclusion de la biblioth�que standard 
#include <math.h>  // Inclut la biblioth�que math�matique

#define EPSILON 1e-10 // D�finition d'une constante pour la pr�cision souhait�e de la m�thode de Newton-Raphson
#define MAX_ITER 100  // D�finition d'une constante pour le nombre maximal d'it�rations

// D�claration de la fonction f(x) la fonction dont on cherche la racine
double f(double x) {
    return pow(x, 4) + 0.8 * pow(x, 3) - 0.3 * pow(x, 2) - 1.9 * x + 0.4;
}

// D�claration de la d�riv�e de la fonction f(x)
double df(double x) {
    return 4 * pow(x, 3) + 2.4 * pow(x, 2) - 0.6 * x - 1.9;
}

// Impl�mentation de la m�thode de Newton-Raphson pour trouver la racine de la fonction f
double newtonRaphson(double x0) {
    int n; // Variable pour compter le nombre d'it�rations
    double xn = x0; // Initialisation de la variable xn � la valeur de d�part x0
    double xn_prev = x0; // Variable pour garder en m�moire la valeur pr�c�dente de xn

    for (n = 0; n < MAX_ITER; ++n) {
        double fxn = f(xn); // Calcul de la valeur de f(xn)
        double dfxn = df(xn); // Calcul de la valeur de la d�riv�e de f au point xn

        // V�rification si la d�riv�e est trop proche de z�ro pour �viter une division par z�ro
        if (fabs(dfxn) < EPSILON) {
            printf("La derivee est trop proche de zero. Division par zero. La methode echoue.\n");
            return 0;
        }

        double xn_next = xn - fxn / dfxn; // Actualisation de xn en utilisant la formule de Newton-Raphson

        // V�rification de la convergence : si xn ne change pas beaucoup on consid�re qu'on a converg�
        if (fabs(xn_next - xn) < EPSILON) {
            printf("La methode a converge avec succes. Racine estimee : %lf\n", xn_next);
            return xn_next; // Retourne la racine trouv�e.
        }

        xn_prev = xn; // Actualisation de xn_prev � la valeur actuelle de xn avant la mise � jour
        xn = xn_next; // Actualisation de xn � la nouvelle valeur calcul�e
    }

    printf("La methode n'a pas converge apres %d iterations.\n", MAX_ITER);
    return 0; // Retourne 0 si la m�thode n'a pas converg�e apr�s le nombre maximal d'it�rations
}

int main() {
    double x0 = 0.25; // Valeur de d�part pour la m�thode de Newton-Raphson
    double root = newtonRaphson(x0); // Appel de la fonction de Newton-Raphson
    if (root != 0) { // Si la racine retourn�e est diff�rente de 0, on l'affiche
        printf("Racine trouvee: %lf\n", root);
    }

    return 0;
}

