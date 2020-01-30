#include <stdlib.h>
#include <stdio.h>

typedef enum weekday{Pon, Wto, Sro, Czw, Pia, Sob, Nie} weekday;


typedef struct czas
{
    int hour;
    int min;
} czas;


typedef struct break_s
{
    czas start;
    czas end;
struct    break_s *next;
} przerwa;

typedef struct workday
{
    int data; //numer dnia miesiaca
    weekday dzien;
    czas start;
    czas end;
    przerwa *break_s;
    struct workday *next;
} tydzien;
//Struktyry



tydzien*create_day();

przerwa*create_breaks();

void wypisanie(tydzien* workday);

int main()
{
    tydzien* workday=create_day();
    wypisanie(workday);


    while (workday!=NULL)
    {
        while (workday->break_s!=NULL)
        {
            przerwa* tmp=workday->break_s;
            workday->break_s=workday->break_s->next;
            free(tmp);
        }
        tydzien*tmp=workday;
        workday=workday->next;
        free(tmp);
    }
    return 0;
}

tydzien* create_day()
{

    tydzien*workday=(tydzien*)malloc(sizeof(tydzien));
    tydzien*dayli=workday;
    int i=0;
    for (i; i<5; i++)
    {
        workday->data=i+1;
        workday->start.hour=9;
        workday->start.min=30;
        workday->end.hour=19;
        workday->end.min=00;
        workday->dzien=i+1;
        workday->break_s=create_breaks();
        if (i<4)
        {
        tydzien*list=(tydzien*)malloc(sizeof(tydzien));
        workday->next=list;
        workday=list;
        }
    } return dayli;
};

przerwa*create_breaks()
{
    przerwa*break_s=(przerwa*) malloc(sizeof(przerwa));
    przerwa*przerwli=break_s;
    int i=0;
    for (i; i<=2; i++)
    {
        czas start;
        czas end;
        start.hour=11+(i*3);
        start.min=50;
        end.hour=12+(i*3);
        end.min=00;
        break_s->start=start;
        break_s->end=end;
        if (i<2)
        {
            przerwa* przerwli=(przerwa*)malloc(sizeof(przerwa));
            break_s->next=przerwli;
            break_s=przerwli;
        }
    }
return przerwli;
}


void wypisanie(tydzien* workday)
{   printf("Przebieg pracy pracownika\n");
    printf("Pracownik: Jan Kowalski \n");
    printf("Stanowisko: Kierownik produkcji \n \n");

    tydzien*tmp=workday;
    while(tmp!=NULL)
    {


        printf("Data: %i ",tmp->data);
        if(tmp->dzien==1)
            printf(" Dzien tygodnia: Pon");
        if(tmp->dzien==2)
            printf(" Dzien tygodnia: Wto");
        if(tmp->dzien==3)
            printf(" Dzien tygodnia: Sro");
        if(tmp->dzien==4)
            printf(" Dzien tygodnia: Czw");
        if(tmp->dzien==5)
            printf(" Dzien tygodnia: Pia");
            printf("\n\n Godzina rozpoczecia pracy: %i:%i", tmp->start.hour, tmp->start.min);
            printf("\n\n Godzina zakonczenia pracy: %i:%i0\n", tmp->end.hour, tmp->end.min);
        przerwa*przerwli=tmp->break_s;
        int ilosc=1;

        while (przerwli!=NULL)
        {
            printf("\n przerwa %i w godzinach: ", ilosc);
            printf("%i:%i ", przerwli->start.hour, przerwli->start.min);
            printf("%i:%i", przerwli->end.hour, przerwli->end.min);
            przerwli = przerwli->next;

            ilosc++;

        }
        printf("\n \n");
tmp=tmp->next;
    }

}
