/*Program that creates than asks User to guess Password*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define MAX (1024)

int CreatePassword(char* password);                     //creating password
int CheckPassword(char* password);                      //checking if password is valid
int PrintEncriptedPassword(char* password);             //printing password like stars (Password = 123 -> ***)
int PasswordCracker(char* password);                    //cracking inputed password

int main() {

    char password[MAX] = { 0 };                         //storage for PASSWORD
    int control = 0;                                    //main control (0-Good, Else-Bad)

    control = CreatePassword(password);

    if(control != 0) {

        printf("Program nije ispravno izveden!\n");
        return -1;
    }

    else 
        printf("Dovidjenja!\n");

    return 0;
}

int CreatePassword(char* password) {

    int control = 0;                                    //control variable (0-Valid, Else-Unvalid)
    int mistakes = 0;                                   //variable for checking mistakes, 3 mistakes and program dies
    int cases = 0;                                      //checks for different cases eg. not enough caracters, less than 2 cap letters
    int static mainVar = 0;                             //variable that stops egzecution of program more than once

    printf("Unesite Vas Password:\n");
    printf("Password: ");
    scanf(" %s",password);
    puts("");

    control = CheckPassword(password);

    
    while (mistakes < 3) {
        
    if(control == 0 && mainVar < 1) {

       cases = PrintEncriptedPassword(password);

       mainVar++;

       if(cases != 0) {

           printf("Izvodjenje programa nije moguce!\n");
           return -1;
       }

       else 
        return 0;
    }

    else if(control == -1) {

        mistakes++;
        
        if (mistakes == 3) {

            printf("Previse pogresaka!\n");
            printf("Program se gasi!\n");

            return -1;

        }

        else {

            printf("Unutar Vase lozinke je premal broj Velikih slova! Trazi se minimalno 2!\n");
            printf("Molim ponovno unesite Password!\n");
            printf("Password: ");
            scanf(" %s",password);
            puts("");

            control = CheckPassword(password);
        }
            
    }

    else if(control == -2) {

        mistakes++;
        
        if (mistakes == 3) {

            printf("Previse pogresaka!\n");
            printf("Program se gasi!\n");

            return -1;
        }

        else {
           
            printf("Unutar Vase lozinke je premalo znakova! Minimalno 8 znakova!\n");
            printf("Molim ponovno unesite Password!\n");
            printf("Password: ");
            scanf(" %s",password);
            puts("");

            control = CheckPassword(password);
        }

    }

    else if(control == -3) {

        mistakes++;
        
        if (mistakes == 3) {

            printf("Previse pogresaka!\n");
            printf("Program se gasi!\n");

            return -1;
        }

        else {

            printf("Unutar Vase lozinke je previse znakova! Znakova mora biti manje od 16!\n");
            printf("Molim ponovno unesite Password!\n");
            printf("Password: ");
            scanf(" %s",password);
            puts("");

            control = CheckPassword(password);
        }
    }
         
    }

    return 0;
}

int PrintEncriptedPassword(char* password) {

    int sizeOfPassword = 0;                             //size of password, used for encripted print and for loop
    int i = 0;                                          //counter
    int control = 0;                                    //asks user if he wants his password written again
    int cnt1 = 0;                                       //var that returns in function CreatePassword

    sizeOfPassword = strlen(password);

    printf("Vas Enkriptirani Password je:\n");

    for(i = 0; i<sizeOfPassword ; i++) 
        printf("*");

    puts("");
    
    printf("Zelite li ponovan ispis Passworda?\n");
    printf("\t1-DA\n\t2-NE\n");
    scanf("%d",&control);

    if(control == 1) {

        printf("Vas Password je: %s\n",password);
           cnt1 = PasswordCracker(password);
    }

    else if (control == 2) 
          cnt1 =  PasswordCracker(password);   

    else {

        printf("Nepodrzan unos!\n");
        return -1;
    }

    return cnt1;
}

int CheckPassword(char* password) {

    int sizeOfPassword = 0;                             //again, size of Password
    int numbCaps = 0;                                   //number of cap written letters, cannot be less than 2
    int i = 0;                                          //counter

    sizeOfPassword = strlen(password);

    //printf("Password u Check: %s",password);

    // printf("%d\n",sizeOfPassword);

    if(sizeOfPassword < 7) 
        return -2;

    else if(sizeOfPassword > 16) 
        return -3;

    else {

        for(i =0; i < sizeOfPassword ; i++) {

            if(password[i] >= 'A' && password[i] <= 'Z')
                numbCaps++;
        }

        if (numbCaps < 2) 
            return -1;

        else 
            return 0;
    }

    return 0;    
}

int PasswordCracker(char* password) {

    char keyPass[MAX] = { 0 };
    static int mistakes = 0;
    int i = 0;

    for(i = 0 ; i<3 ; i++) {

        printf("Pokusaj [%d]\n",i+1);
        printf("Unesite Vasu lozinku:\n");
        scanf(" %s",keyPass);

        if(strcmp(keyPass,password) == 0) {

            printf("Lozinka je pogodjena!\n");
            return 0;
        }

        else 
            mistakes++;

        if(mistakes == 3) {

            printf("Vi niste User!\n");
            return -1;
        }

    }
    
    return 0;
}
