#include <stdio.h>

int Control(int altitude) {
    int thruster = 0;

//Hvis højden (altitude) er større end 100, så slår vi thruster fra (0).
//Tanken er, at hvis vi er højt nok oppe, behøver vi ikke motorhjælp.
    if (altitude > 100) {
        thruster = 0;
        //Kun hvis første if ikke var sandt, tjekker vi denne betingelse.
//Her gælder det, at hvis højden er mellem 1 og 100 (dvs. tættere på jorden), så skal thruster være tændt (1).
//Det er for at bremse farten og undgå et hårdt nedslag.
    } else if (altitude > 0) {
        thruster = 1;
        //Hvis ingen af de to første betingelser passer (dvs. altitude <= 0), så er vi allerede i jorden eller under.
//Derfor skal thruster også være slukket (0).
    } else {
        thruster = 0;
    }

    return thruster;
}

void Test(int altitude) {
    int thruster = Control(altitude);
    int behaviorCorrect = (altitude > 100 && thruster == 0) ||
                          (altitude <= 100 && altitude > 0 && thruster == 1) ||
                          (altitude <= 0 && thruster == 0);
    char *behaviorCorrectIcon = behaviorCorrect ? "✅" : "❌";
    printf("For altitude %3d, your thruster is %d |%s|\n", altitude, thruster,
           behaviorCorrectIcon);
}

int main(void) {
    Test(150);
    Test(100);
    Test(50);
    Test(0);
    Test(-1);
    return 0;
}
