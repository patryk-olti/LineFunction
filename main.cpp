#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void pierwszyPunkt(float x1, float y1, float x2, float y2, int zakres)
{
    cout<<endl<<"Rezultat programu . . ."<<endl<<endl;
    double a, b;

    if(x1-x2 != 0){
        a = (y1-y2)/(x1-x2);
        b = y1 - (x1*a);

        cout<<"Prosta przechodzaca przez punkty: ( "<<x1<<","<<y1<<" ) i ( "<<x2<<" , "<<y2<<" ) posiada parametr a = "<<a<<" ,oraz b = "<<b<<" ."<<endl;
        cout<<"Rownanie prostej: y = "<<a<<"x + "<<b<<endl;
    }
    else{
        cout<<"Prosta ma uklad sprzeczny!"<<endl;
        exit(0);
    }

    // wyznaczanie prostej prostopadlej

    if(a!=0){
        a = -(1/a);
        cout<<"Wspolczynnik kierunkowy prostej prostopadlej to: "<<a<<endl;
    }
    else{
        cout<<"Wspolczynnik kieirunkowy prostej nie istnieje!"<<endl;
        exit(0);
    }

    b = y2 - (a*x2);
    cout<<"Wzor prostej prostopadlej przechodzacej przez punkt: ( "<<x2<<" , "<<y2<<" ) : y = "<<a<<"x + "<<b<<endl;
    cout<<endl<<"Start algorytm wyszukiwania!"<<endl<<endl;

    int tmp = 0;
    bool szukam = true, next = true;
    int szukamXY = 1;

    int startX = x2;
    int startY = y2;

    if(a>0){
        while(szukam){

            if(next){
                x2 = x2 + 1;
                y2 = y2 + 1;
                next = false;
            }

            switch(szukamXY){
            case 1:{    // szukam po przekatnej
                    szukamXY = 2;
                    tmp = y2 - a*x2;
                    if(tmp == b){
                        cout<<"ZNALAZLEM! Jest to punkt: ( "<<x2<<" , "<<y2<<" )."<<endl;
                    }
                }
                break;
            case 2:{    // szukam w gore
                    szukamXY = 3;
                    tmp = y2 - a*(x2-1);
                    if(tmp == b){
                        cout<<"ZNALAZLEM! Jest to punkt: ( "<<(x2-1)<<" , "<<y2<<" )."<<endl;
                    }
                }
                break;
            case 3:{    // szukam w prawo
                    szukamXY = 1;
                    tmp = (y2-1) - a*x2;
                    if(tmp == b){
                        cout<<"ZNALAZLEM! Jest to punkt: ( "<<x2<<" , "<<(y2-1)<<" )."<<endl;                    }
                }
                break;
            }

            if(szukamXY == 1){
                next = true;    }
            else{
                next = false;   }

            if(x2 > zakres){
                szukam = false;
                cout<<"koniec szukania w gore"<<endl<<endl;
                }
        }
    }

    if(a>0){
        x2 = startX;
        y2 = startY;
        szukam = true;
        next = true;
        szukamXY = 1;

        while(szukam){

            if(next){
                x2 = x2 - 1;
                y2 = y2 - 1;
                next = false;
            }

            switch(szukamXY){
            case 1:{    // szukam po przekatnej
                    szukamXY = 2;
                    tmp = y2 - a*x2;
                    if(tmp == b){
                        cout<<"ZNALAZLEM! Jest to punkt: ( "<<x2<<" , "<<y2<<" )."<<endl;
                    }
                }
                break;
            case 2:{    // szukam w gore
                    szukamXY = 3;
                    tmp = y2 - a*(x2+1);
                    if(tmp == b){
                        cout<<"ZNALAZLEM! Jest to punkt: ( "<<(x2+1)<<" , "<<y2<<" )."<<endl;
                    }
                }
                break;
            case 3:{    // szukam w prawo
                    szukamXY = 1;
                    tmp = (y2+1) - a*x2;
                    if(tmp == b){
                        cout<<"ZNALAZLEM! Jest to punkt: ( "<<x2<<" , "<<(y2+1)<<" )."<<endl;                    }
                }
                break;
            }

            if(szukamXY == 1){
                next = true;    }
            else{
                next = false;   }

            if(x2 < -zakres){
                szukam = false;
                cout<<"koniec szukania w dol"<<endl<<endl;
                }
        }
    }

    if(a<0){
        x2 = startX;
        y2 = startY;
        szukam = true;
        next = true;
        szukamXY = 1;

        while(szukam){

            if(next){
                x2 = x2 + 1;
                y2 = y2 - 1;
                next = false;
            }

            switch(szukamXY){
            case 1:{    // szukam po przekatnej
                    szukamXY = 2;
                    tmp = y2 - a*x2;
                    if(tmp == b){
                        cout<<"ZNALAZLEM! Jest to punkt: ( "<<x2<<" , "<<y2<<" )."<<endl;
                    }
                }
                break;
            case 2:{    // szukam w dol
                    szukamXY = 3;
                    tmp = (y2) - a*(x2-1);
                    if(tmp == b){
                        cout<<"ZNALAZLEM! Jest to punkt: ( "<<(x2-1)<<" , "<<y2<<" )."<<endl;
                    }
                }
                break;
            case 3:{    // szukam w prawo
                    szukamXY = 1;
                    tmp = (y2+1) - a*x2;
                    if(tmp == b){
                        cout<<"ZNALAZLEM! Jest to punkt: ( "<<x2<<" , "<<(y2+1)<<" )."<<endl;                    }
                }
                break;
            }

            if(szukamXY == 1){
                next = true;    }
            else{
                next = false;   }

            if(x2 > zakres){
                szukam = false;
                cout<<"koniec szukania w gore"<<endl<<endl;
                }
        }
    }

    if(a<0){
        x2 = startX;
        y2 = startY;
        szukam = true;
        next = true;
        szukamXY = 1;

        while(szukam){

            if(next){
                x2 = x2 - 1;
                y2 = y2 + 1;
                next = false;
            }

            switch(szukamXY){
            case 1:{    // szukam po przekatnej
                    szukamXY = 2;
                    tmp = y2 - a*x2;
                    if(tmp == b){
                        cout<<"ZNALAZLEM! Jest to punkt: ( "<<x2<<" , "<<y2<<" )."<<endl;
                    }
                }
                break;
            case 2:{    // szukam w gore
                    szukamXY = 3;
                    tmp = y2 - a*(x2+1);
                    if(tmp == b){
                        cout<<"ZNALAZLEM! Jest to punkt: ( "<<(x2+1)<<" , "<<y2<<" )."<<endl;
                    }
                }
                break;
            case 3:{    // szukam w lewo
                    szukamXY = 1;
                    tmp = (y2-1) - a*x2;
                    if(tmp == b){
                        cout<<"ZNALAZLEM! Jest to punkt: ( "<<x2<<" , "<<(y2-1)<<" )."<<endl;                    }
                }
                break;
            }

            if(szukamXY == 1){
                next = true;    }
            else{
                next = false;   }

            if(x2 < -zakres){
                szukam = false;
                cout<<"koniec szukania w dol"<<endl<<endl;
                }
        }
    }
}

int main()
{
    float x1 = 0, y1 = 6;
    float x2 = 2, y2 = 2;
    int zakres;

    cout<<"Witaj w programie szukania punktow (ograniczenie: wspolrzedne calkowite)!"<<endl;
        cout<<"Podaj x1: ";
        cin>>x1;
        cout<<"Podaj y1: ";
        cin>>y1;
        cout<<"Podaj x2: ";
        cin>>x2;
        cout<<"podaj y2: ";
        cin>>y2;

        cout<<"Podaj zakres poszukiwan: ";
        cin>>zakres;

    pierwszyPunkt(x1,y1,x2,y2, zakres);

    return 0;
}
