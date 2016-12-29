

void Mine_sweeper(){

SetColor(1);
printf("\n\n\n\t\t\t\tD&4          24I     TM#JHS619DT5     OPAH       FGK     THTKHI53!az&\n");
SetColor(2);
printf("\t\t\t\tF567        679O     YT0I&YS820BN     PQEJP      Q~H     M,V)?AZOT!CY\n");
SetColor(3);
printf("\t\t\t\t4V5J8      D3K)M         FJYJ         438\yW      VC.     YUT         \n");
SetColor(4);
printf("\t\t\t\t*NK 87    LK 6VZ         1@MA         @KO $YP    FAS     Q2R         \n");
SetColor(5);
printf("\t\t\t\tC/X  9S  =7  18T         Q?CT         OWE  64L   WBM     NMYTYR7     \n");
SetColor(6);
printf("\t\t\t\ttyM   ZUMT   0B1         $VM?         -!2   JIA  QCP     MAQ!89B     \n");
SetColor(7);
printf("\t\t\t\t8VY    CY    BT!         Z~LY         IJW    OJF 7OR     Q2&         \n");
SetColor(8);
printf("\t\t\t\tVYT          L+Y         AZM.         =2+     OIE8OJ     NJY         \n");
SetColor(9);
printf("\t\t\t\t$Q1          MTZ     T7KI791ZM<O      PQE      02E93     M!7NKTW/P]!Z\n");
SetColor(10);
printf("\t\t\t\t5ST          9SW     TRA.)VA!MX?      N48       TA!9     M<451L';XV&9\n\n\n");


SetColor(11);
printf("\t  GTKFDF7       KPA            FGY     THTKHI53!az&     THTKHI53!az&      GTKFF7JY       THTKHI53!az&       GTKFF7JY  \n");
SetColor(12);
printf("\tGFG8J&VAQ!9     PQE            Q~H     M,V)?AZOT!CY     M,V)?AZOT!CY    GFG8Y  YVQ!9     M,V)?AZOT!CY     GFG8Y  YQT!9\n");
SetColor(13);
printf("\tFD7     BTN     4K8            VC.     YUT              YUT             FD7      BTN     YUT              FD7      BTN\n");
SetColor(14);
printf("\t D5&            @KO            FAS     Q2R              Q2R             TYR      NTW     Q2R              TYR      NTW\n");
SetColor(15);
printf("\t  45M           RT5     VGT    64L     NMYTYR7          NMYTYR7         RTHJQ  POGT      NMYTYR7          RTHJQ   POGT\n");
SetColor(1);
printf("\t    V)Y         H!R    THJIA   QCP     MAQ!89B          MAQ!89B         PYT4HL&9IT       MAQ!89B          PYT4HL&9IT  \n");
SetColor(2);
printf("\t      UTQ       2XM   IJW OJF  7OR     Q2&              Q2&             U&3              Q2&              JU2JTYT     \n");
SetColor(3);
printf("\tTYR     NTW     7TZ  P2+   OIE 8OJ     NJY              NJY             U&3              NJY              8!A JYWT    \n");
SetColor(4);
printf("\tRTHJHYJGU9T      6$PQE      02E37      M!7NKTW/P]!Z     M!7NKTW/P]!Z    FIT              M!7NKTW/P]!Z     MT2   97QY  \n");
SetColor(5);
printf("\t  T4HL&54         FN4        A!9       M<451L';XV&9     M<451L';XV&9    MPE              M<451Ll;XV&9     OP5     MTET\n\n\n\n\n\n");


SetColor(15);

}




void Print_win(){


    SetColor(11);
    printf("\tHJ@          FDR        GTKFF7JY        GHT        /AU\n");
    SetColor(1);
    printf("\t !TO        5&L       GFG8YTHYQT!9      OIY        MTY\n");
    SetColor(36);
    printf("\t  BHY      0+M       HFD7       PTN     PT9        XQP\n");
    SetColor(72);
    printf("\t   234    1CM       97R          ZTW    MNT        [C?\n");
    SetColor(24);
    printf("\t    AWT  P8D        TY9          NTK    12P        '6A\n");
    SetColor(30);
    printf("\t     123C4S         !MT          APC    MTW        LY2\n");
    SetColor(55);
    printf("\t      sq~0          $ZM          ?TZ    PL2        &FR\n");
    SetColor(77);
    printf("\t      JHSE           HD7        BTN     MTR$      T10*\n");
    SetColor(91);
    printf("\t      WERT            GFG8MTHYQT!9       GFG8MTHYQT!9 \n");
    SetColor(111);
    printf("\t      QL3D              GTKF%7JY             GTKF%7JY   \n\n\n\n");


SetColor(7);
printf("\tKPA            FGY     TM#JHS619DT5          OPAH       FGK\n");
SetColor(11);
printf("\tPQE            Q~H     YT0I&YS820BN          PQEJP      Q~H\n");
SetColor(4);
printf("\t4K8            VC.         FJYJ              438YI      VC.\n");
SetColor(12);
printf("\t@KO            FAS         1@MA              @KO $YP    FAS\n");
SetColor(9);
printf("\tRT5     VGT    64L         QPCT              OWE  64L   WBM\n");
SetColor(5);
printf("\tH!R    THJIA   QCP         $VM?              -!2   JIA  QCP\n");
SetColor(13);
printf("\t2XM   IJW OJF  7OR         Z~LY              IJW    OJF 7OR\n");
SetColor(6);
printf("\t7TZ  P2+   OIE 8OJ         AZM.              =2+     OIE8OJ\n");
SetColor(14);
printf("\t 6$PQE      02E37      T7KI791ZM<O           PQE      02E93\n");
SetColor(8);
printf("\t  FN4        A!9       TRA.)VA!MX?           N48       TA!9");





SetColor(15);

}





#include <windows.h>         //header file for windows
//taken from the internet
void SetColor(int ForgC)
{
    WORD wColor;
    //We will need this handle to get the current background attribute
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    //We use csbi for the wAttributes word.
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        //Mask out all but the background attribute, and add in the forgournd color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}



