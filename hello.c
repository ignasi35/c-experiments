#include <stdio.h>
#include <stdbool.h>

// GCC converteix codi font en codi binary executable
// make interpreta codi font 


// f(x) = x*2  // x € Z,  E x € [−32,767, +32,767]
int f(int x) { return x * 2; } 

// x AND y
// 0 AND 0 --> 0
// 1 AND 0 --> 0
// 0 AND 1 --> 0
// 1 AND 1 --> 1
//   bool x, y;
//     .. some more code
//   return x && y;

// x OR y
// 0 OR 0 --> 0
// 1 OR 0 --> 1
// 0 OR 1 --> 1
// 1 OR 1 --> 1
//   bool x, y;
//   return x || y;

/** Retorna true si 'a' i 'b' són iguals o false en qualsevol altre cas */
bool areEqual(int a, int b){ return a == b ; }

/**
    Runs a test named 'name' with arguments:
      - 'expected': the value that should have been produced
      - 'input': the value to pass to f
*/
void testf(char name[], int input, int expected){
    // Crido 'f' usant com a paràmtre el valor de 'input'
    // de mnanera que 'actual' val el doble de input.
    int actual = f(input);
    bool testPassed = areEqual(expected, actual) ;
    
    // Un string, (ejem) equival (ejem) a un char[] que té en 
    // alguna posició el caràcter '\0'. Si no hi ha un '\0' 
    // enlloc, no podem dir que aquell char[] sigui un string 
    // vàlid.

    // Tot l'if/else que ve a continuació és equivalent a:
    //   char result[4] =  testPassed ? "YES" : "NO" 
    
    // opcio 1
    char result[4];
    if(testPassed){
        result[0] = 'Y';
        result[1] = 'E';
        result[2] = 'S';
        result[3] = '\0';
    } else {
        result[0] = 'N';
        result[1] = '0';
        result[2] = '\0';
    }
    // opcio 2
    char* r2 = testPassed ? "YES" : "NO" ;

    // opcio 3 --> no és útil perque no tinc accés 
    // a 'r' al final de l'if/else
    if(testPassed) {
        char r[4] = "YES";
    } else {
        // Puc usar el mateix nom de variable (r) perquè són 
        // dos entorns (alias curly braces) diferents.
        char r[3] = "NO";       
    }
    // r ja no existeix 

    printf("%s  \t[%s]\n", 
        name, 
        r2);
}

int main() {
    
    // Crido una funció que es diu 'testf' amb els paràmetres:
    // 1. un string que val '...'
    // 2. un enter que val 0
    // 3. un enter que val 0
    testf("0 duplicates to 0?", 0, 0);
    testf("1 duplicates to 2?", 1, 2);
    testf("-11 duplicates to -22?", -11, -22) ;
    testf("19 duplicates to 4?", 19, 4);

    int x = 040;
    int y = 0x2E;  
    //     46dec == 5*8 + 6*1
    //   101 110 == 056
    // 0010 1110 == 0x2E == 16*2 + 14*1 
    //  00001201 == 1201 base 3 == 46 base 10 
    char isSpace = x;

    printf(" \n  [%c]  [%c] !!!!", isSpace, y);

    return 0; // ignora'l 
}
