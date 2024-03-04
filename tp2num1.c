/*
    nom 1 : BAHLOUL Wassila
    matricule 1 : 20183065

*/

#include <stdio.h> // Inclusion de la bibliothèque standard 
#include <math.h>  // Inclut la bibliothèque mathématique

#define EPSILON 1e-10 // Définition d'une constante pour la précision souhaitée de la méthode de Newton-Raphson
#define MAX_ITER 100  // Définition d'une constante pour le nombre maximal d'itérations

// Déclaration de la fonction f(x) la fonction dont on cherche la racine
double f(double x) {
    return pow(x, 4) + 0.8 * pow(x, 3) - 0.3 * pow(x, 2) - 1.9 * x + 0.4;
}

// Déclaration de la dérivée de la fonction f(x)
double df(double x) {
    return 4 * pow(x, 3) + 2.4 * pow(x, 2) - 0.6 * x - 1.9;
}

// Implémentation de la méthode de Newton-Raphson pour trouver la racine de la fonction f
double newtonRaphson(double x0) {
    int n; // Variable pour compter le nombre d'itérations
    double xn = x0; // Initialisation de la variable xn à la valeur de départ x0
    double xn_prev = x0; // Variable pour garder en mémoire la valeur précédente de xn

    for (n = 0; n < MAX_ITER; ++n) {
        double fxn = f(xn); // Calcul de la valeur de f(xn)
        double dfxn = df(xn); // Calcul de la valeur de la dérivée de f au point xn

        // Vérification si la dérivée est trop proche de zéro pour éviter une division par zéro
        if (fabs(dfxn) < EPSILON) {
            printf("La derivee est trop proche de zero. Division par zero. La methode echoue.\n");
            return 0;
        }

        double xn_next = xn - fxn / dfxn; // Actualisation de xn en utilisant la formule de Newton-Raphson

        // Vérification de la convergence : si xn ne change pas beaucoup on considère qu'on a convergé
        if (fabs(xn_next - xn) < EPSILON) {
            printf("La methode a converge avec succes. Racine estimee : %lf\n", xn_next);
            return xn_next; // Retourne la racine trouvée.
        }

        xn_prev = xn; // Actualisation de xn_prev à la valeur actuelle de xn avant la mise à jour
        xn = xn_next; // Actualisation de xn à la nouvelle valeur calculée
    }

    printf("La methode n'a pas converge apres %d iterations.\n", MAX_ITER);
    return 0; // Retourne 0 si la méthode n'a pas convergée après le nombre maximal d'itérations
}

int main() {
    double x0 = 0.25; // Valeur de départ pour la méthode de Newton-Raphson
    double root = newtonRaphson(x0); // Appel de la fonction de Newton-Raphson
    if (root != 0) { // Si la racine retournée est différente de 0, on l'affiche
        printf("Racine trouvee: %lf\n", root);
    }

    return 0;
}

