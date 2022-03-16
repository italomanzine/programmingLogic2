#ifndef LENGHT_HPP
#define LENGHT_HPP

#include <iostream>
#include "input.hpp"

using namespace std;
  
  //Classe que realiza as conversões de comprimento
  class Length:public Input
    {
        public:
            void mm_m();
            void m_mm();
            void cm_m();
            void m_cm();
            void cm_km();
            void km_cm();
            void m_mile();
            void mile_m();
            void km_mile();
            void mile_km();
            void feet_m();
            void m_feet();
            void inch_m();
            void m_inch();
            void yard_m();
            void m_yard();

    };
        
    void Length ::mm_m()
    {
        cout<<"\n   Milimetro= ";
        cin>>i;
        cout<<"\n   Metro= "<<i*.001;
    }

    void Length ::m_mm()
    {
        cout<<"\n   metro= ";
        cin>>i;
        cout<<"\n   milimetro= "<<i*1000;
    }

    void Length ::cm_m()
    {
        cout<<"\n   Centimetro= ";
        cin>>i;
        cout<<"\n   Metro= "<<i*.01;
    }

    void Length ::m_cm()
    {
        cout<<"\n   metro= ";
        cin>>i;
        cout<<"\n   cm= "<<i*100;
    }

    void Length::m_mile()
    {
        cout<<"\n   metro= ";
        cin>>i;
        cout<<"\n   milha= "<<i*.00062;
    }

    void Length::mile_m()
    {
        cout<<"\n   milha= ";
        cin>>i;
        cout<<"\n   metro= "<<i*1609.344;
    }
    void Length :: cm_km()
    {
        cout<<"\n   cm= ";
        cin>>i;
        cout<<"\n   km= "<<i*0.00001;

    }

    void Length :: km_cm()
    {   
        cout<<"\n   km= ";
        cin>>i;
        cout<<"\n   cm= "<<i*100000;
    }

    void Length::feet_m()
    {
        cout<<"\n   pes= ";
        cin>>i;
        cout<<"\n   metro= "<<i*.3048;
    }

    void Length::m_feet()
    {
        cout<<"\n   metro= ";
        cin>>i;
        cout<<"\n   pes= "<<i*3.28084;
    }

    void Length::yard_m()
    {
        cout<<"\n   yard= ";
        cin>>i;
        cout<<"\n   metro= " <<i*0.9144;
    }

    void Length::m_yard()
    {
        cout<<"\n   metro= ";
        cin>>i;
        cout<<"\n   yard= "<<i*1.09361;
    }

    void Length::inch_m()
    {
        cout<<"\n   polegada=";
        cin>>i;
        cout<<"\n   metro="<<i*.0254;
    }

    void Length::m_inch()
    {
        cout<<"\n   metro=";
        cin>>i;
        cout<<"\n   polegada="<<i*39.37008;
    }

    void Length ::km_mile()
    {
        cout<<"\n   kilometro=";cin>>i;
        cout<<"\n   milha="<<i*.6213712 ;
    }

    void Length ::mile_km( )
    {
        cout<<"\n   milha="; cin>>i;
        cout<<"\n   kilometro="<<i*1.60934;
    }
    

#endif